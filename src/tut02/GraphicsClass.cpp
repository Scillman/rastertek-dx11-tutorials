#include "GraphicsClass.h"

GraphicsClass::GraphicsClass(void)
{
	// Initialize
}

GraphicsClass::GraphicsClass(const GraphicsClass &other)
{
	// Copy
}

GraphicsClass::~GraphicsClass(void)
{
	// Destruct
}

bool GraphicsClass::Initialize(int screenWidth, int screenHeight, HWND hWnd)
{
	return true;
}

void GraphicsClass::Shutdown(void)
{
	// Release resources
}

bool GraphicsClass::Frame(void)
{
	return true;
}

bool GraphicsClass::Render(void)
{
	return true;
}
