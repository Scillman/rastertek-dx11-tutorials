#pragma once
#include <Windows.h>
#include "BitmapClass.h"
#include "CameraClass.h"
#include "ColorShaderClass.h"
#include "D3DClass.h"
#include "LightClass.h"
#include "LightShaderClass.h"
#include "ModelClass.h"
#include "TextClass.h"
#include "TextureShaderClass.h"

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
	bool Render(float rotation);

private:
	D3DClass			*m_Direct3D;
	CameraClass			*m_Camera;
	ModelClass			*m_Model;
	ColorShaderClass	*m_ColorShader;
	TextureShaderClass	*m_TextureShader;
	LightShaderClass	*m_LightShader;
	LightClass			*m_Light;
	BitmapClass			*m_Bitmap;
	TextClass			*m_Text;
};
