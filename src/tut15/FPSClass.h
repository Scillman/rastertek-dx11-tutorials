#pragma once
#include <Windows.h>
#include <mmsystem.h>

class FPSClass
{
public:
	FPSClass(void);
	FPSClass(const FPSClass &other);
	~FPSClass(void);

	void Initialize(void);
	void Frame(void);
	int GetFps(void);

private:
	int					m_fps, m_count;
	unsigned long		m_startTime;
};
