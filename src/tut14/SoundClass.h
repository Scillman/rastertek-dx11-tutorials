#pragma once
#include <Windows.h>
#include <mmsystem.h>
#include <dsound.h>
#include <stdio.h>

class SoundClass
{
private:
	struct WaveHeaderType
	{
		char			chunkId[4];
		unsigned long	chunkSize;
		char			format[4];
		char			subChunkId[4];
		unsigned long	subChunkSize;
		unsigned short	audioFormat;
		unsigned short	numChannels;
		unsigned long	sampleRate;
		unsigned long	bytesPerSecond;
		unsigned short	blockAlign;
		unsigned short	bitsPerSample;
		char			dataChunkId[4];
		unsigned long	dataSize;
	};

public:
	SoundClass(void);
	SoundClass(const SoundClass &other);
	~SoundClass(void);

	bool Initialize(HWND hWnd);
	void Shutdown(void);

private:
	bool InitializeDirectSound(HWND hWnd);
	void ShutdownDirectSound(void);

	bool LoadWaveFile(char *filename, IDirectSoundBuffer8 **secondaryBuffer);
	void ShutdownWaveFile(IDirectSoundBuffer8 **secondaryBuffer);

	bool PlayWaveFile(void);

private:
	IDirectSound8		*m_DirectSound;
	IDirectSoundBuffer	*m_primaryBuffer;
	IDirectSoundBuffer8	*m_secondaryBuffer1;
};
