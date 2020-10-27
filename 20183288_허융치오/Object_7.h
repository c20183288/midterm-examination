#ifndef  __OBJECT_5_H__
#define __OBJECT_5_H__

#include <vector>

#include "glm/glm.hpp"
#include "include/GL/glew.h"
#include "glm/gtc/matrix_transform.hpp"

#include "IUpdater.h"
#include "ICleanUp.h"

class Object : public ICleanUp
{
public:
	Object();
	virtual ~Object(){}

	virtual void shutDown() override;

	glm::mat4 GetTranslate() const { return translate; }
	void SetPosition(glm::vec3 src_position);

private:
	glm::mat4 translate;
};

class IRenderer
{
public:
	virtual glm::mat4 GetTranslate() = 0;

public:
	GLuint VertexArrayID;
	GLuint programID;
	GLuint MatrixID;
	GLuint ViewMatrixID;
	GLuint ModelMatrixID;
	GLuint Texture;
	GLuint TextureID;

	std::vector<glm::vec3>vertices;
	std::vector<glm::vec2>uvs;
	std::vector<glm::vec3>normals;

	GLuint vertexbuffer;
	GLuint uvbuffer;
	GLuint normalbuffer;
	GLuint LightID;
};

class RenderableObject : public Object, public IRenderer
{
public:
	virtual void shutDown() override;

	virtual glm::mat4 GetTranslate() override
	{
		return Object::GetTranslate();
	}
};

class NonRenderableObject : public Object, public IUpdater
{
public:
	virtual void shutDown() override {}
public:
	virtual void update() override {}
};

#endif // ! __OBJECT_5_H__