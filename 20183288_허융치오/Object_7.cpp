#include "Object_7.h"

#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h"

Object::Object()
{
	translate = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
}

void Object::SetPosition(glm::vec3 src_position)
{
	translate = glm::translate(glm::mat4(1.0f), src_position);
}

void Object::shutDown()
{

}

void RenderableObject::shutDown()
{
	//cleanup VBO and shader
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);
	glDeleteBuffers(1, &normalbuffer);
	glDeleteProgram(programID);
	glDeleteTextures(1, &Texture);
	glDeleteVertexArrays(1, &VertexArrayID);
}

void NonRenderableObject::shutDown()
{

}

void NonRenderableObject::update()
{

}