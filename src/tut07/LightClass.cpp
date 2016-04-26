#include "LightClass.h"

LightClass::LightClass(void)
{
	// Initialize
}

LightClass::LightClass(const LightClass &other)
{
	// Copy
}

LightClass::~LightClass(void)
{
	// Destruct
}

void LightClass::SetDiffuseColor(float red, float green, float blue, float alpha)
{
	m_diffuseColor = XMFLOAT4(red, green, blue, alpha);
}

void LightClass::SetDirection(float x, float y, float z)
{
	m_direction = XMFLOAT3(x, y, z);
}

XMFLOAT4 LightClass::GetDiffuseColor(void)
{
	return m_diffuseColor;
}

XMFLOAT3 LightClass::GetDirection(void)
{
	return m_direction;
}
