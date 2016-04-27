#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "CPUClass.h"
#include "FPSClass.h"
#include "GraphicsClass.h"
#include "InputClass.h"
#include "SoundClass.h"
#include "TimerClass.h"

class SystemClass
{
public:
	SystemClass(void);
	SystemClass(const SystemClass &other);
	~SystemClass(void);

	bool Initialize(void);
	void Shutdown(void);
	void Run(void);

	LRESULT CALLBACK MessageHandler(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam);

private:
	bool Frame(void);
	void InitializeWindows(int &screenWidth, int &screenHeight);
	void ShutdownWindows(void);

private:
	LPCWSTR				m_applicationName;
	HINSTANCE			m_hInstance;
	HWND				m_hWnd;

	InputClass			*m_Input;
	GraphicsClass		*m_Graphics;
	SoundClass			*m_Sound;

	FPSClass			*m_fps;
	CPUClass			*m_cpu;
	TimerClass			*m_timer;
};

static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam);
static SystemClass *ApplicationHandle = NULL;
