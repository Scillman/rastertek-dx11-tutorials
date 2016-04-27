#pragma once
#include <Windows.h>

class TimerClass
{
public:
	TimerClass(void);
	TimerClass(const TimerClass &other);
	~TimerClass(void);

	bool Initialize(void);
	void Frame(void);

	float GetTime(void);

private:
	INT64				m_frequency;
	float				m_ticksPerMs;
	INT64				m_startTime;
	float				m_frameTime;
};
