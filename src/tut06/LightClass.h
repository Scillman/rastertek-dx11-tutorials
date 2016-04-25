#pragma once
#include <DirectXMath.h>

using namespace DirectX;

class LightClass
{
public:
	LightClass(void);
	LightClass(const LightClass &other);
	~LightClass(void);

	void SetDiffuseColor(float red, float green, float blue, float alpha);
	void SetDirection(float x, float y, float z);

	XMFLOAT4 GetDiffuseColor(void);
	XMFLOAT3 GetDirection(void);

private:
	XMFLOAT4			m_diffuseColor;
	XMFLOAT3			m_direction;
};
