#pragma once
#include <DirectXMath.h>

using namespace DirectX;

class LightClass
{
public:
	LightClass(void);
	LightClass(const LightClass &other);
	~LightClass(void);

	void SetAmbientColor(float red, float green, float blue, float alpha);
	void SetDiffuseColor(float red, float green, float blue, float alpha);
	void SetDirection(float x, float y, float z);
	void SetSpecularColor(float red, float green, float blue, float alpha);
	void SetSpecularPower(float power);

	XMFLOAT4 GetAmbientColor(void);
	XMFLOAT4 GetDiffuseColor(void);
	XMFLOAT3 GetDirection(void);
	XMFLOAT4 GetSpecularColor(void);
	float GetSpecularPower(void);

private:
	XMFLOAT4			m_ambientColor;
	XMFLOAT4			m_diffuseColor;
	XMFLOAT3			m_direction;
	XMFLOAT4			m_specularColor;
	float				m_specularPower;
};
