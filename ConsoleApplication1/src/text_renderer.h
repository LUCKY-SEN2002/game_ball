#pragma once

#ifndef TEXT_RENDERER_H
#define TEXT_RENDERER_H

#include <map>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "texture.h"
#include "shader.h"


/// Holds all state information relevant to a character as loaded using FreeType
struct Character {
	GLuint TextureID;   //符号纹理的ID
	glm::ivec2 Size;    // 字形大小
	glm::ivec2 Bearing; // 从基线到字形左上角的偏移量
	GLuint Advance;     // 向前移动到下一个字形的水平偏移量
};


//控件加载的字体显示文本的渲染器类
// FreeType的图书馆。加载单一字体，并将其处理为字符列表
//后续渲染。
class TextRenderer
{
public:
	//保存预先编译的字符列表
	std::map<GLchar, Character> Characters;
	//用于文本渲染的着色器
	Shader TextShader;
	//构造函数
	TextRenderer(GLuint width, GLuint height);
	//预先编译给定字体的字符列表
	void Load(std::string font, GLuint fontSize);
	//使用预编译的字符列表呈现文本字符串
	void RenderText(std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color = glm::vec3(1.0f));
private:
	// 着色器状态
	GLuint VAO, VBO;
};

#endif 