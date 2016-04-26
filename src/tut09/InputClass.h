#pragma once

#define NUM_KEYS	256

class InputClass
{
public:
	InputClass(void);
	InputClass(const InputClass &other);
	~InputClass(void);

	void Initialize(void);

	void KeyDown(unsigned int);
	void KeyUp(unsigned int);

	bool IsKeyDown(unsigned int);

private:
	bool m_keys[NUM_KEYS];
};
