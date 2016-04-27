#include "FontClass.h"

FontClass::FontClass(void)
{
	m_Font = 0;
	m_Texture = 0;
}

FontClass::FontClass(const FontClass &other)
{
	// Copy
}

FontClass::~FontClass(void)
{
	// Destruct
}

bool FontClass::Initialize(ID3D11Device *device, ID3D11DeviceContext *deviceContext, char *fontFilename, char *textureFilename)
{
	bool				result;
	
	// Load in the text file containing the font data.
	result = LoadFontData(fontFilename);
	if (!result)
	{
		return false;
	}

	// Load the texture that has the font characters on it.
	result = LoadTexture(device, deviceContext, textureFilename);
	if (!result)
	{
		return false;
	}

	return true;
}

void FontClass::Shutdown(void)
{
	// Release the font texture.
	ReleaseTexture();

	// Release the font data.
	ReleaseFontData();
}

bool FontClass::LoadFontData(char *filename)
{
	ifstream			fIn;
	int					i;
	char				temp;

	// Create the font spacing buffer.
	m_Font = new FontType[NUM_CHARS_PER_FONT];
	if (!m_Font)
	{
		return false;
	}

	// Read in the font size and spacing between chars.
	fIn.open(filename);
	if (fIn.fail())
	{
		return false;
	}

	// Read in the 95 used ascii characters for text.
	for (i = 0; i < NUM_CHARS_PER_FONT; i++)
	{
		fIn.get(temp);
		while (temp != ' ')
		{
			fIn.get(temp);
		}
		fIn.get(temp);
		while (temp != ' ')
		{
			fIn.get(temp);
		}

		fIn >> m_Font[i].left;
		fIn >> m_Font[i].right;
		fIn >> m_Font[i].size;
	}

	// Close the file.
	fIn.close();

	return true;
}

void FontClass::ReleaseFontData(void)
{
	// Release the font data array.
	if (m_Font)
	{
		delete[] m_Font;
		m_Font = 0;
	}
}

bool FontClass::LoadTexture(ID3D11Device *device, ID3D11DeviceContext *deviceContext, char *filename)
{
	bool				result;
	
	// Create the texture object.
	m_Texture = new TextureClass;
	if (!m_Texture)
	{
		return false;
	}

	// Initialize the texture object.
	result = m_Texture->Initialize(device, deviceContext, filename);
	if (!result)
	{
		return false;
	}

	return true;
}

void FontClass::ReleaseTexture(void)
{
	// Release the texture object.
	if (m_Texture)
	{
		m_Texture->Shutdown();
		delete m_Texture;
		m_Texture = 0;
	}
}

ID3D11ShaderResourceView* FontClass::GetTexture(void)
{
	return m_Texture->GetTexture();
}

void FontClass::BuildVertexArray(void *vertices, char *sentence, float drawX, float drawY)
{
	VertexType			*vertexPtr;
	int					numLetters, index, i, letter;

	// Coerce the input vertices into a VertexType structure.
	vertexPtr = (VertexType*)vertices;

	// Get the number of letters in the sentence.
	numLetters = (int)strlen(sentence);

	// Initialize the index to the vertex array.
	index = 0;

	// Draw each letter onto a quad.
	for (i = 0; i < numLetters; i++)
	{
		letter = ((int)sentence[i]) - 32;

		// If the letter is a space then just move over three pixels.
		if (letter == 0)
		{
			drawX = drawX + 3.0f;
		}
		else
		{
			// First triangle in quad.
			vertexPtr[index].position = XMFLOAT3(drawX, drawY, 0.0f);  // Top left.
			vertexPtr[index].texture = XMFLOAT2(m_Font[letter].left, 0.0f);
			index++;

			vertexPtr[index].position = XMFLOAT3((drawX + m_Font[letter].size), (drawY - 16), 0.0f);  // Bottom right.
			vertexPtr[index].texture = XMFLOAT2(m_Font[letter].right, 1.0f);
			index++;

			vertexPtr[index].position = XMFLOAT3(drawX, (drawY - 16), 0.0f);  // Bottom left.
			vertexPtr[index].texture = XMFLOAT2(m_Font[letter].left, 1.0f);
			index++;

			// Second triangle in quad.
			vertexPtr[index].position = XMFLOAT3(drawX, drawY, 0.0f);  // Top left.
			vertexPtr[index].texture = XMFLOAT2(m_Font[letter].left, 0.0f);
			index++;

			vertexPtr[index].position = XMFLOAT3(drawX + m_Font[letter].size, drawY, 0.0f);  // Top right.
			vertexPtr[index].texture = XMFLOAT2(m_Font[letter].right, 0.0f);
			index++;

			vertexPtr[index].position = XMFLOAT3((drawX + m_Font[letter].size), (drawY - 16), 0.0f);  // Bottom right.
			vertexPtr[index].texture = XMFLOAT2(m_Font[letter].right, 1.0f);
			index++;

			// Update the x location for drawing by the size of the letter and one pixel.
			drawX = drawX + m_Font[letter].size + 1.0f;
		}
	}
}
