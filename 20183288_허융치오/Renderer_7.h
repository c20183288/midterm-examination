#pragma once

struct GLFWwindow;
class Object;
class IUpdater;
class Controls;

class Renderer : public ICleanUp, public Controls
{
private:
	GLFWwindow* window;

	std::vector<IRenderer*> _renderingObjArr;

public:
	static Renderer* instance()
	{
		static Renderer instance;

		return &instance;
	}
public:
	void render(RenderableObject* src_obj);
	void init();
	void addObject(IRenderer* render_obj);
	void update(IUpdater* src_obj);
	virtual void shutDown() override;

};
