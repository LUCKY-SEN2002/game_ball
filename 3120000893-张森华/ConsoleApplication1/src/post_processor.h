#pragma once
#ifndef POST_PROCESSOR_H
#define POST_PROCESSOR_H

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "texture.h"
#include "sprite_renderer.h"
#include "shader.h"

//游戏。它在一个纹理四边形上渲染游戏
//通过启用混淆，混乱或
//布尔。
//在渲染游戏之前需要调用BeginRender()
//和EndRender()后渲染类工作的游戏。

class PostProcessor
{
public:
	// 状态
	Shader PostProcessingShader;
	Texture2D Texture;
	GLuint Width, Height;
	// 选项
	GLboolean Confuse, Chaos, Shake;
	// 构造函数
	PostProcessor(Shader shader, GLuint width, GLuint height);
	//在呈现游戏之前准备后处理器的framebuffer操作
	void BeginRender();
	// 应该在渲染游戏后调用，所以它将所有渲染数据存储到一个纹理对象
	void EndRender();
	// 渲染PostProcessor纹理方块(作为一个包含屏幕的大精灵)
	void Render(GLfloat time);
private:
	// 着色器状态
	GLuint MSFBO, FBO; // FBO是规则的，用于分割MS色缓冲纹理
	GLuint RBO; // RBO用于多采样彩色缓冲
	GLuint VAO;
	// 初始化quad渲染后处理纹理
	void initRenderData();
};

#endif