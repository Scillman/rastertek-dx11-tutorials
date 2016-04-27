#pragma once
#include <d3d11.h>
#include <DirectXMath.h>
#include "TextureClass.h"

using namespace DirectX;

class BitmapClass
{
private:
	struct VertexType
	{
		XMFLOAT3 position;
		XMFLOAT2 texture;
	};

public:
	BitmapClass(void);
	BitmapClass(const BitmapClass &other);
	~BitmapClass(void);

	bool Initialize(ID3D11Device *device, ID3D11DeviceContext *deviceContext, int screenWidth, int screenHeight, char *textureFilename, int bitmapWidth, int bitmapHeight);
	void Shutdown(void);
	bool Render(ID3D11DeviceContext *deviceContext, int positionX, int positionY);

	int GetIndexCount(void);
	ID3D11ShaderResourceView* GetTexture(void);

private:
	bool InitializeBuffers(ID3D11Device *device);
	void ShutdownBuffers(void);
	bool UpdateBuffers(ID3D11DeviceContext *deviceContext, int positionX, int positionY);
	void RenderBuffers(ID3D11DeviceContext *deviceContext);

	bool LoadTexture(ID3D11Device *device, ID3D11DeviceContext *deviceContext, char *filename);
	void ReleaseTexture(void);

private:
	ID3D11Buffer		*m_vertexBuffer;
	ID3D11Buffer		*m_indexBuffer;
	int					m_vertexCount, m_indexCount;
	TextureClass		*m_Texture;
	int					m_screenWidth, m_screenHeight;
	int					m_bitmapWidth, m_bitmapHeight;
	int					m_previousPosX, m_previousPosY;
};
