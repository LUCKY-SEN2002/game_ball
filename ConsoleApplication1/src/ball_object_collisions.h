#pragma once
#ifndef BALLOBJECT_H
#define BALLOBJECT_H

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "texture.h"
#include "sprite_renderer.h"
#include "game_object.h"

// BallObject持有Ball对象继承的状态
//游戏对象的相关状态数据。包含一些额外的
//功能特定于Breakout的球对象
//对于单独的GameObject来说太具体了。
class BallObject : public GameObject
{
public:
	// 球的状态
	GLfloat   Radius;
	GLboolean Stuck;
	//构造函数(s)

	GLboolean Sticky, PassThrough;

	BallObject();
	BallObject(glm::vec2 pos, GLfloat radius, glm::vec2 velocity, Texture2D sprite);
	// 移动球，将其限制在窗口范围内(除了下边缘);返回新职位
	glm::vec2 Move(GLfloat dt, GLuint window_width);
	//以给定的位置和速度将球重置为初始状态
	void      Reset(glm::vec2 position, glm::vec2 velocity);
};

#endif