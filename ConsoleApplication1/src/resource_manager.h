#pragma once

#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <map>
#include <string>

#include <GL/glew.h>

#include "texture.h"
#include "shader.h"


//一个静态的单例ResourceManager类
//函数加载纹理和着色器。每个加载纹理
//和/或shader也被存储为将来引用的字符串
//处理。所有的功能和资源都是静态的，没有
//定义公共构造函数。
class ResourceManager
{
public:
	// 资源存储
	static std::map<std::string, Shader>    Shaders;
	static std::map<std::string, Texture2D> Textures;
	//加载(并生成)一个着色程序从文件加载顶点，片段(和几何)着色器的源代码。如果gShaderFile不是nullptr，它也会加载一个几何着色器
	static Shader   LoadShader(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile, std::string name);
	// 取回存储的悲伤器
	static Shader   GetShader(std::string name);
	//从文件中加载(并生成)纹理
	static Texture2D LoadTexture(const GLchar *file, GLboolean alpha, std::string name);
	//检索存储的纹理
	static Texture2D GetTexture(std::string name);
	// 正确地取消分配所有加载的资源
	static void      Clear();
private:
	// 私有构造函数，即我们不需要任何实际的资源管理器对象。它的成员和函数应该是公开可用的(静态的)。
	ResourceManager() { }
	// 从文件中加载并生成一个着色器
	static Shader    loadShaderFromFile(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile = nullptr);
	//从文件中加载单个纹理
	static Texture2D loadTextureFromFile(const GLchar *file, GLboolean alpha);
};

#endif