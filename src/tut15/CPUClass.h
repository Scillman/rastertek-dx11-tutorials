#pragma once
#include <pdh.h>

class CPUClass
{
public:
	CPUClass(void);
	CPUClass(const CPUClass &other);
	~CPUClass(void);

	void Initialize(void);
	void Shutdown(void);
	void Frame(void);
	int GetCpuPercentage(void);

private:
	bool				m_canReadCpu;
	HQUERY				m_queryHandle;
	HCOUNTER			m_counterHandle;
	unsigned long		m_lastSampleTime;
	long				m_cpuUsage;
};
