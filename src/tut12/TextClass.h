#pragma once
#include "FontClass.h"
#include "FontShaderClass.h"

using namespace DirectX;

class TextClass
{
private:
	struct SentenceType
	{
		ID3D11Buffer *vertexBuffer, *indexBuffer;
		int vertexCount, indexCount, maxLength;
		float red, green, blue;
	};

	struct VertexType
	{
		XMFLOAT3 position;
		XMFLOAT2 texture;
	};

public:
	TextClass(void);
	TextClass(const TextClass &other);
	~TextClass(void);

	bool Initialize(ID3D11Device *device, ID3D11DeviceContext *deviceContext, HWND hWnd,
		int screenWidth, int screenHeight, XMMATRIX baseViewMatrix);
	void Shutdown(void);
	bool Render(ID3D11DeviceContext *deviceContext, XMMATRIX worldMatrix, XMMATRIX orthoMatrix);

private:
	bool InitializeSentence(SentenceType **sentence, int maxLength, ID3D11Device *device);
	bool UpdateSentence(SentenceType *sentence, char *text, int positionX, int positionY,
		float red, float green, float blue, ID3D11DeviceContext *deviceContext);
	void ReleaseSentence(SentenceType **sentence);
	bool RenderSentence(ID3D11DeviceContext *deviceContext, SentenceType *sentence,
		XMMATRIX worldMatrix, XMMATRIX orthoMatrix);

private:
	FontClass			*m_Font;
	FontShaderClass		*m_FontShader;
	int					m_screenWidth, m_screenHeight;
	XMMATRIX			m_baseViewMatrix;
	SentenceType		*m_sentence1;
	SentenceType		*m_sentence2;
};
