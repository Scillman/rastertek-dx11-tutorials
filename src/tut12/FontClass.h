#include <d3d11.h>
#include <DirectXMath.h>
#include <fstream>
#include "TextureClass.h"

using namespace DirectX;
using namespace std;

#define NUM_CHARS_PER_FONT		95

class FontClass
{
private:
	struct FontType
	{
		float left, right;
		int size;
	};

	struct VertexType
	{
		XMFLOAT3 position;
		XMFLOAT2 texture;
	};

public:
	FontClass(void);
	FontClass(const FontClass &other);
	~FontClass(void);

	bool Initialize(ID3D11Device *device, ID3D11DeviceContext *deviceContext, char *fontFilename, char *textureFilename);
	void Shutdown(void);

	ID3D11ShaderResourceView* GetTexture();

	void BuildVertexArray(void*, char*, float, float);

private:
	bool LoadFontData(char*);
	void ReleaseFontData();
	bool LoadTexture(ID3D11Device *device, ID3D11DeviceContext *deviceContext, char *filename);
	void ReleaseTexture(void);

private:
	FontType			*m_Font;
	TextureClass		*m_Texture;
};
