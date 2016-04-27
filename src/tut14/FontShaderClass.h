#pragma once
#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>
#include <fstream>

using namespace DirectX;
using namespace std;

class FontShaderClass
{
private:
	struct ConstantBufferType
	{
		XMMATRIX world;
		XMMATRIX view;
		XMMATRIX projection;
	};

	struct PixelBufferType
	{
		XMFLOAT4 pixelColor;
	};

public:
	FontShaderClass(void);
	FontShaderClass(const FontShaderClass &other);
	~FontShaderClass(void);

	bool Initialize(ID3D11Device *device, HWND hWnd);
	void Shutdown(void);
	bool Render(ID3D11DeviceContext* deviceContext, int indexCount,
		XMMATRIX worldMatrix, XMMATRIX viewMatrix, XMMATRIX projectionMatrix,
		ID3D11ShaderResourceView* texture, XMFLOAT4 pixelColor);

private:
	bool InitializeShader(ID3D11Device *device, HWND hWnd, LPCWSTR filename);
	void ShutdownShader(void);
	void OutputShaderErrorMessage(ID3D10Blob *errorMessage, HWND hWnd, LPCWSTR filename);

	bool SetShaderParameters(ID3D11DeviceContext *deviceContext,
		XMMATRIX worldMatrix, XMMATRIX viewMatrix, XMMATRIX projectionMatrix,
		ID3D11ShaderResourceView *texture, XMFLOAT4 pixelColor);
	void RenderShader(ID3D11DeviceContext *deviceContext, int indexCount);

private:
	ID3D11VertexShader	*m_vertexShader;
	ID3D11PixelShader	*m_pixelShader;
	ID3D11InputLayout	*m_layout;
	ID3D11Buffer		*m_constantBuffer;
	ID3D11SamplerState	*m_sampleState;
	ID3D11Buffer		*m_pixelBuffer;
};
