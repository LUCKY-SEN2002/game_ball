#pragma once
#ifndef POWER_UP_H
#define POWER_UP_H
#include <string>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "game_object.h"


// PowerUp块的大小
const glm::vec2 SIZE(60, 20);
// PowerUp砖块产生时的速度
const glm::vec2 VELOCITY(0.0f, 150.0f);

// PowerUp继承的状态和呈现函数
// GameObject，但也包含额外的信息来声明它
//活动持续时间和是否被激活。
// PowerUp的类型存储为字符串。

class PowerUp : public GameObject
{
public:
	// PowerUp 状态
	std::string Type;
	GLfloat     Duration;
	GLboolean   Activated;
	// Constructor
	PowerUp(std::string type, glm::vec3 color, GLfloat duration, glm::vec2 position, Texture2D texture)
		: GameObject(position, SIZE, texture, color, VELOCITY), Type(type), Duration(duration), Activated() { }
};

#endif