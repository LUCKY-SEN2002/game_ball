#pragma once
#ifndef PARTICLE_GENERATOR_H
#define PARTICLE_GENERATOR_H
#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "shader.h"
#include "texture.h"
#include "game_object.h"


// 表示单个粒子及其状态
struct Particle {
	glm::vec2 Position, Velocity;
	glm::vec4 Color;
	GLfloat Life;

	Particle() : Position(0.0f), Velocity(0.0f), Color(1.0f), Life(0.0f) { }
};


//粒子生成器作为一个容器渲染大量的
//通过重复生成和更新粒子和杀死粒子
//在给定的时间之后。
class ParticleGenerator
{
public:
	//构造函数
	ParticleGenerator(Shader shader, Texture2D texture, GLuint amount);
	// 更新粒子
	void Update(GLfloat dt, GameObject &object, GLuint newParticles, glm::vec2 offset = glm::vec2(0.0f, 0.0f));
	// 绘制粒子
	void Draw();
private:
	// 状态
	std::vector<Particle> particles;
	GLuint amount;
	// 着色器状态
	Shader shader;
	Texture2D texture;
	GLuint VAO;
	// 初始化缓冲区和顶点属性
	void init();
	// 返回当前未使用的第一个粒子索引，例如Life &lt;= 0.0f，如果当前没有粒子处于非活动状态则返回0
	GLuint firstUnusedParticle();
	// 重生的粒子
	void respawnParticle(Particle &particle, GameObject &object, glm::vec2 offset = glm::vec2(0.0f, 0.0f));
};

#endif