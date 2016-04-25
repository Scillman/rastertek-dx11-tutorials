#include "InputClass.h"

InputClass::InputClass(void)
{
	// Initialize
}

InputClass::InputClass(const InputClass &other)
{
	// Copy
}

InputClass::~InputClass(void)
{
	// Destruct
}

void InputClass::Initialize(void)
{
	int					i;

	// Initialize all the keys to being released and not pressed.
	for (i = 0; i < NUM_KEYS; i++)
	{
		m_keys[i] = false;
	}
}

void InputClass::KeyDown(unsigned int input)
{
	// If a key is pressed then save that state in the key array.
	m_keys[input] = true;
}

void InputClass::KeyUp(unsigned int input)
{
	// If a key is released then clear that state in the key array.
	m_keys[input] = false;
}

bool InputClass::IsKeyDown(unsigned int key)
{
	// Return what state the key is in (pressed/not pressed).
	return m_keys[key];
}
