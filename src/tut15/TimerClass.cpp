#include "TimerClass.h"

TimerClass::TimerClass(void)
{
	// Initialize
}

TimerClass::TimerClass(const TimerClass &other)
{
	// Copy
}

TimerClass::~TimerClass(void)
{
	// Destruct
}

bool TimerClass::Initialize(void)
{
	// Check to see if this system supports high performance timers.
	QueryPerformanceFrequency((LARGE_INTEGER*)&m_frequency);
	if (m_frequency == 0)
	{
		return false;
	}

	// Find out how many times the frequency counter ticks every millisecond.
	m_ticksPerMs = (float)(m_frequency / 1000);

	QueryPerformanceCounter((LARGE_INTEGER*)&m_startTime);

	return true;
}

void TimerClass::Frame(void)
{
	INT64				currentTime;
	float				timeDifference;
	
	QueryPerformanceCounter((LARGE_INTEGER*)& currentTime);

	timeDifference = (float)(currentTime - m_startTime);

	m_frameTime = timeDifference / m_ticksPerMs;

	m_startTime = currentTime;
}

float TimerClass::GetTime(void)
{
	return m_frameTime;
}
