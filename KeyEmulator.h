#ifndef KeyEmulator_h
#define KeyEmulator_h

#include <iostream>
#include <stdlib.h>
#include <string>
#include <Windows.h>

class KeyEmulator {
  /* Variables */
  private:
  // Enabled / Disabled
  bool enable;
  HHOOK kbHook;
  /* Functions */
  public:
  // CTOR
  KeyEmulator();
  // Enable
  void Enable(bool enable);
  // Translate vk key to cherokee character
  static int Translate(int vkCode);
  // DTOR
  ~KeyEmulator();
};

extern KeyEmulator keyEm;

#endif
