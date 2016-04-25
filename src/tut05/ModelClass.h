#pragma once
#include <d3d11.h>
#include <DirectXMath.h>
#include "TextureClass.h"

using namespace DirectX;

class ModelClass
{
private:
	struct VertexType
	{
		XMFLOAT3 position;
		XMFLOAT2 texture;
	};

public:
	ModelClass(void);
	ModelClass(const ModelClass &other);
	~ModelClass(void);

	bool Initialize(ID3D11Device *device, ID3D11DeviceContext *deviceContext, char *filename);
	void Shutdown(void);
	void Render(ID3D11DeviceContext *deviceContext);

	int GetIndexCount(void);
	ID3D11ShaderResourceView* GetTexture(void);

private:
	bool InitializeBuffers(ID3D11Device *device);
	void ShutdownBuffers(void);
	void RenderBuffers(ID3D11DeviceContext *deviceContext);

	bool LoadTexture(ID3D11Device *device, ID3D11DeviceContext *deviceContext, char *filename);
	void ReleaseTexture(void);

private:
	TextureClass		*m_Texture;
	ID3D11Buffer		*m_vertexBuffer;
	ID3D11Buffer		*m_indexBuffer;
	int					m_vertexCount, m_indexCount;
};
