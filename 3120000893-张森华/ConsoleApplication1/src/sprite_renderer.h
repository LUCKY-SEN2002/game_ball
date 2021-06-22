#pragma once
#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "texture.h"
#include "shader.h"


class SpriteRenderer
{
public:
	// 构造函数 (inits shaders/shapes)
	SpriteRenderer(Shader &shader);
	// 析构函数
	~SpriteRenderer();
	//用给定的精灵渲染一个定义的纹理
	void DrawSprite(Texture2D &texture, glm::vec2 position, glm::vec2 size = glm::vec2(10, 10), GLfloat rotate = 0.0f, glm::vec3 color = glm::vec3(1.0f));
private:
	// 着色器状态
	Shader shader;
	GLuint quadVAO;
	//初始化和配置方块的缓冲区和顶点属性
	void initRenderData();
};

#endif