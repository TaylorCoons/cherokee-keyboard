#ifndef KeyEmulator_h
#define KeyEmulator_h

#include <iostream>
#include <stdlib.h>
#include <string>
#include <Windows.h>
#include <fstream>
#include <map>
#include <vector>

class KeyEmulator {
  /* Variables */
  private:
  // Enabled / Disabled
  bool enable;
  HHOOK kbHook;
  std::map<char, std::vector<unsigned long int>> keyMap;

  /* Functions */
  private:
  // Loads key map used for translation
  void LoadKeyMap(std::string filePath);

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
