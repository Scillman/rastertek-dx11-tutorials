#pragma once
#include <d3d11.h>
#include <DirectXMath.h>

using namespace DirectX;

class D3DClass
{
public:
	D3DClass(void);
	D3DClass(const D3DClass &other);
	~D3DClass(void);

	bool Initialize(int screenWidth, int screenHeight, bool vSync, HWND hWnd, bool fullscreen, float screenDepth, float screenNear);
	void Shutdown(void);

	void BeginScene(float red, float green, float blue, float alpha);
	void EndScene(void);

	ID3D11Device* GetDevice(void);
	ID3D11DeviceContext* GetDeviceContext(void);

	void GetProjectionMatrix(XMMATRIX &projectionMatrix);
	void GetWorldMatrix(XMMATRIX &worldMatrix);
	void GetOrthoMatrix(XMMATRIX &orthoMatrix);

	void GetVideoCardInfo(char *cardName, int &memory);

	void TurnZBufferOn(void);
	void TurnZBufferOff(void);

private:
	bool						m_vsync_enabled;
	int							m_videoCardMemory;
	char						m_videoCardDescription[128];
	IDXGISwapChain				*m_swapChain;
	ID3D11Device				*m_device;
	ID3D11DeviceContext			*m_deviceContext;
	ID3D11RenderTargetView		*m_renderTargetView;
	ID3D11Texture2D				*m_depthStencilBuffer;
	ID3D11DepthStencilState		*m_depthStencilStateEnabled;
	ID3D11DepthStencilState		*m_depthStencilStateDisabled;
	ID3D11DepthStencilView		*m_depthStencilView;
	ID3D11RasterizerState		*m_rasterState;
	XMMATRIX					m_projectionMatrix;
	XMMATRIX					m_worldMatrix;
	XMMATRIX					m_orthoMatrix;
};
