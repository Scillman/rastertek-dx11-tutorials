#include "GraphicsClass.h"

GraphicsClass::GraphicsClass(void)
{
	m_Direct3D = 0;
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
	bool				result;
	
	// Create the Direct3D object.
	m_Direct3D = new D3DClass;
	if (!m_Direct3D)
	{
		return false;
	}

	// Initialize the Direct3D object.
	result = m_Direct3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hWnd, FULLSCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if (!result)
	{
		MessageBox(hWnd, L"Could not initialize Direct3D", L"Error", MB_OK);
		return false;
	}
	
	return true;
}

void GraphicsClass::Shutdown(void)
{
	// Release the Direct3D object.
	if (m_Direct3D)
	{
		m_Direct3D->Shutdown();
		delete m_Direct3D;
		m_Direct3D = 0;
	}
}

bool GraphicsClass::Frame(void)
{
	bool				result;
	
	// Render the graphics scene.
	result = Render();
	if (!result)
	{
		return false;
	}

	return true;
}

bool GraphicsClass::Render(void)
{
	// Clear the buffers to begin the scene.
	m_Direct3D->BeginScene(0.5f, 0.5f, 0.5f, 1.0f);
	
	// Present the rendered scene to the screen.
	m_Direct3D->EndScene();

	return true;
}
