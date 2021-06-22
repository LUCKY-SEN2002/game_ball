#pragma once
#ifndef GAMELEVEL_H
#define GAMELEVEL_H
#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "game_object.h"
#include "sprite_renderer.h"
#include "resource_manager.h"


/// GameLevel holds all Tiles as part of a Breakout level and 
/// hosts functionality to Load/render levels from the harddisk.
class GameLevel
{
public:
	// 等级状态
	std::vector<GameObject> Bricks;
	// 构造函数
	GameLevel() { }
	// 加载等级
	void      Load(const GLchar *file, GLuint levelWidth, GLuint levelHeight);
	// 绘制level
	void      Draw(SpriteRenderer &renderer);
	// 检查关卡是否完成(所有非实心砖块都被摧毁)
	GLboolean IsCompleted();
private:
	// 从砖块数据初始化级别
	void      init(std::vector<std::vector<GLuint>> tileData, GLuint levelWidth, GLuint levelHeight);
};

#endif