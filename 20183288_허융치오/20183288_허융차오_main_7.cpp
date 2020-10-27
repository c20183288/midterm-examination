#define _CRT_SECURE_NO_WARNINGS

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "lib-vc2017/glew32.lib")
#pragma comment(lib, "lib-vc2017/glfw3.lib")

#include "Object_7.h"
#include "FileManager_7.h"
#include "Renderer_7.h"
#include "Sphere.h"
#include "ICleanUp.h"
#include "SampleNonRenderObj.h"
#include "controls.h"

int main()
{
	FileManager* file_mgr = FileManager::instance();

	Renderer* renderer = Renderer::instance();
	renderer->init();

	RenderableObject* cube = new RenderableObject();
	renderer->addObject(cube);

	file_mgr->loadObj(
		cube,
		"cube.obj",
		"uvtemplate.DDS",
		"20183288_vs.shader",
		"20183288_fs.shader"
	);

	Sphere* sphere = new Sphere();
	renderer->addObject(sphere);

	SampleNonRenderObj* non_render_obj = new SampleNonRenderObj();
	//NonRenderableObject* non_render_obj = new NonRenderableObject();

	while (true)
	{
		renderer->update(non_render_obj);

		renderer->render(sphere);
	}

	renderer->shutDown();

	delete non_render_obj;
	delete sphere;
	delete cube;

	return 0;
}