#pragma once
#include <DirectXMath.h>

using namespace DirectX;

#define RATIO_DEG_RAD	0.0174532925f

class CameraClass
{
public:
	CameraClass(void);
	CameraClass(const CameraClass &other);
	~CameraClass(void);

	void SetPosition(float x, float y, float z);
	void SetRotation(float x, float y, float z);

	XMFLOAT3 GetPosition(void);
	XMFLOAT3 GetRotation(void);

	void Render(void);
	void GetViewMatrix(XMMATRIX &viewMatrix);

private:
	XMFLOAT3			m_position;
	XMFLOAT3			m_rotation;
	XMMATRIX			m_viewMatrix;
};
