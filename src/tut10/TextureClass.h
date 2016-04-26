#pragma once
#include <d3d11.h>
#include <stdio.h>

class TextureClass
{
private:
	struct TargaHeader
	{
		unsigned char data1[12];
		unsigned short width;
		unsigned short height;
		unsigned char bpp;
		unsigned char data2;
	};

public:
	TextureClass(void);
	TextureClass(const TextureClass &other);
	~TextureClass(void);

	bool Initialize(ID3D11Device *device, ID3D11DeviceContext *deviceContext, char *filename); // filename?
	void Shutdown(void);

	ID3D11ShaderResourceView* GetTexture(void);

private:
	bool LoadTarga(char*, int&, int&);

private:
	unsigned char				*m_targaData;
	ID3D11Texture2D				*m_texture;
	ID3D11ShaderResourceView	*m_textureView;

};
