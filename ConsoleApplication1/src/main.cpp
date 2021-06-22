#pragma once

#define STB_IMAGE_IMPLEMENTATION
#define GLEW_STATIC


#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "game.h"
#include "resource_manager.h"


// GLFW函数声明
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

// 屏幕宽度
const GLuint SCREEN_WIDTH = 800;
// 屏幕长度
const GLuint SCREEN_HEIGHT = 600;

Game Breakout(SCREEN_WIDTH, SCREEN_HEIGHT);

int main(int argc, char *argv[])
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Breakout", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	glewInit();
	glGetError();//调用一次捕获glewInit() bug，所有其他错误现在都来自我们的应用程序。

	glfwSetKeyCallback(window, key_callback);

	// OpenGL c配置
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// 初始化
	Breakout.Init();

	// DeltaTime变量
	GLfloat deltaTime = 0.0f;
	GLfloat lastFrame = 0.0f;

	// 在菜单状态下开始游戏
	Breakout.State = GAME_ACTIVE;

	while (!glfwWindowShouldClose(window))
	{
		// 计算时间
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		glfwPollEvents();

		// deltaTime = 0.001 f;
		//管理用户输
		Breakout.ProcessInput(deltaTime);

		//更新游戏状态e
		Breakout.Update(deltaTime);

		// 着色器
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		Breakout.Render();

		glfwSwapBuffers(window);
	}

	//使用资源管理器删除加载的所有资源
	ResourceManager::Clear();

	glfwTerminate();
	return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	// 当用户按下escape键时，我们将WindowShouldClose属性设置为true，关闭应用程序
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
			Breakout.Keys[key] = GL_TRUE;
		else if (action == GLFW_RELEASE)
		{
			Breakout.Keys[key] = GL_FALSE;
			Breakout.KeysProcessed[key] = GL_FALSE;
		}
	}
}