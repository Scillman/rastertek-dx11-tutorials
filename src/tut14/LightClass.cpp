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

void LightClass::SetAmbientColor(float red, float green, float blue, float alpha)
{
	m_ambientColor = XMFLOAT4(red, green, blue, alpha);
}

void LightClass::SetDiffuseColor(float red, float green, float blue, float alpha)
{
	m_diffuseColor = XMFLOAT4(red, green, blue, alpha);
}

void LightClass::SetDirection(float x, float y, float z)
{
	m_direction = XMFLOAT3(x, y, z);
}

void LightClass::SetSpecularColor(float red, float green, float blue, float alpha)
{
	m_specularColor = XMFLOAT4(red, green, blue, alpha);
}

void LightClass::SetSpecularPower(float power)
{
	m_specularPower = power;
}

XMFLOAT4 LightClass::GetAmbientColor(void)
{
	return m_ambientColor;
}

XMFLOAT4 LightClass::GetDiffuseColor(void)
{
	return m_diffuseColor;
}

XMFLOAT3 LightClass::GetDirection(void)
{
	return m_direction;
}

XMFLOAT4 LightClass::GetSpecularColor(void)
{
	return m_specularColor;
}

float LightClass::GetSpecularPower(void)
{
	return m_specularPower;
}
