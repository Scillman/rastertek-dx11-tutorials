#pragma once
#include <Windows.h>

#define FULLSCREEN			false
#define VSYNC_ENABLED		true
#define SCREEN_DEPTH		1000.0f
#define SCREEN_NEAR			0.1f

class GraphicsClass
{
public:
	GraphicsClass(void);
	GraphicsClass(const GraphicsClass &other);
	~GraphicsClass(void);

	bool Initialize(int screenWidth, int screenHeight, HWND hWnd);
	void Shutdown(void);
	bool Frame(void);

private:
	bool Render(void);
};
