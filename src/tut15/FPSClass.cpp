#include "FPSClass.h"

FPSClass::FPSClass(void)
{
	// Initialize
}

FPSClass::FPSClass(const FPSClass &other)
{
	// Copy
}

FPSClass::~FPSClass(void)
{
	// Destruct
}

void FPSClass::Initialize(void)
{
	m_fps = 0;
	m_count = 0;
	m_startTime = timeGetTime();
}

void FPSClass::Frame(void)
{
	m_count++;

	if (timeGetTime() >= (m_startTime + 1000))
	{
		m_fps = m_count;
		m_count = 0;

		m_startTime = timeGetTime();
	}
}

int FPSClass::GetFps(void)
{
	return m_fps;
}
