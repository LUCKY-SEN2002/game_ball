#pragma once

#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>

// Texture2D能够在OpenGL中存储和配置纹理。
//它还包含实用函数，便于管理。
class Texture2D
{
public:
	//持有纹理对象的ID，用于所有纹理操作引用这个特定的纹理
	GLuint ID;
	//纹理图像尺寸
	GLuint Width, Height; //加载图像的宽度和高度(以像素为单位)
	// / /纹理格式
	GLuint Internal_Format; // 纹理对象的格式
	GLuint Image_Format; // 加载图片的格式
	// 纹理 configuration
	GLuint Wrap_S; // 绕轴模式 on S axis
	GLuint Wrap_T; // 绕轴模式 on T axis
	GLuint Filter_Min; // F如果纹理像素<屏幕像素，则为过滤模式
	GLuint Filter_Max; // F如果纹理像素<屏幕像素，则为过滤模式
	// 构造函数(设置默认纹理模式)
	Texture2D();
	// 从图像数据生成纹理
	void Generate(GLuint width, GLuint height, unsigned char* data);
	// 将纹理绑定为当前活动的GL_TEXTURE_2D纹理对象
	void Bind() const;
};

#endif