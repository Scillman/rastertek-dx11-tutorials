#include "CameraClass.h"

CameraClass::CameraClass(void)
{
	m_position = { 0.0f, 0.0f, 0.0f };
	m_rotation = { 0.0f, 0.0f, 0.0f };
}

CameraClass::CameraClass(const CameraClass &other)
{
	// Copy
}

CameraClass::~CameraClass(void)
{
	// Destruct
}

void CameraClass::SetPosition(float x, float y, float z)
{
	m_position = XMFLOAT3(x, y, z);
}

void CameraClass::SetRotation(float x, float y, float z)
{
	m_rotation = XMFLOAT3(x, y, z);
}

XMFLOAT3 CameraClass::GetPosition(void)
{
	return m_position;
}

XMFLOAT3 CameraClass::GetRotation(void)
{
	return m_rotation;
}

void CameraClass::Render(void)
{
	XMFLOAT3			up, lookAt;
	XMVECTOR			upVector, positionVector, lookAtVector;
	float				yaw, pitch, roll;
	XMMATRIX			rotationMatrix;
	
	// Setup the vector that points upwards.
	up.x = 0.0f;
	up.y = 1.0f;
	up.z = 0.0f;

	// Load it into a XMVECTOR structure.
	upVector = XMLoadFloat3(&up);

	// Load it into a XMVECTOR structure.
	positionVector = XMLoadFloat3(&m_position);

	// Setup where the camera is looking by default.
	lookAt.x = 0.0f;
	lookAt.y = 0.0f;
	lookAt.z = 1.0f;

	// Load it into a XMVECTOR structure.
	lookAtVector = XMLoadFloat3(&lookAt);

	// Set the yaw (Y axis), pitch (X axis), and roll (Z axis) rotations in radians.
	pitch = m_rotation.x * RATIO_DEG_RAD;
	yaw = m_rotation.y * RATIO_DEG_RAD;
	roll = m_rotation.z * RATIO_DEG_RAD;

	// Create the rotation matrix from the yaw, pitch, and roll values.
	rotationMatrix = XMMatrixRotationRollPitchYaw(pitch, yaw, roll);

	// Transform the lookAt and up vector by the rotation matrix so the view is correctly rotated at the origin.
	lookAtVector = XMVector3TransformCoord(lookAtVector, rotationMatrix);
	upVector = XMVector3TransformCoord(upVector, rotationMatrix);

	// Translate the rotated camera position to the location of the viewer.
	lookAtVector = XMVectorAdd(positionVector, lookAtVector);

	// Finally create the view matrix from the three updated vectors.
	m_viewMatrix = XMMatrixLookAtLH(positionVector, lookAtVector, upVector);
}

void CameraClass::GetViewMatrix(XMMATRIX &viewMatrix)
{
	viewMatrix = m_viewMatrix;
}
