#include "KeyEmulator.h"

LRESULT __stdcall HookCallbackKeyboard(int nCode, WPARAM wParam, LPARAM lParam) {
  if (nCode >= 0) {
    KBDLLHOOKSTRUCT kbdStruct;
    kbdStruct = *((KBDLLHOOKSTRUCT*)lParam);
    if(wParam == WM_KEYDOWN) {
      int chChar = KeyEmulator::Translate(kbdStruct.vkCode);
      if (chChar) {
        PostMessageW(HWND_BROADCAST, WM_CHAR, 0x13A1, 1L);
        return -1;
      }
    }
  }
  return CallNextHookEx(NULL, nCode, wParam, lParam);
}

KeyEmulator::KeyEmulator() {
  enable = true;
  kbHook = SetWindowsHookEx(WH_KEYBOARD_LL, HookCallbackKeyboard, NULL, 0);
  if (!kbHook) {
    std::cout << "Failed to link keyboard" << std::endl;
  }
  LoadKeyMap("cherokee-map-std.txt");
}

void KeyEmulator::LoadKeyMap(std::string filePath) {
  std::ifstream keyFile(filePath);
  if (!keyFile.is_open()) {
    std::cout << "Failed to load keymap" << std::endl;
    std::cout << "Error with file: " << filePath << std::endl;
  }
  std::string buff;
  unsigned int lineNum = 0;
  while (getline(keyFile, buff)) {
    if (buff.size() < 8) {
      lineNum++;
      continue;
    }
    if (buff.at(1) != '.') {
      lineNum++;
      continue;
    }
    char ch = buff.at(0);
    unsigned int offset = 2;
    unsigned int charIndex = 0;
    unsigned int currChar = 0;
    std::string unicodeChar = "";
    std::vector<unsigned long int> hexChars;
    for (int i = offset; i < buff.size(); i++) {
      if (buff.at(i) == ',') {
        continue;
      }
      bool success = true;
      char c = buff.at(i);
      unicodeChar += c;
      currChar++;
      if (currChar == 6) {
        hexChars.push_back(std::strtoul(unicodeChar.c_str(), 0, 16));
        unicodeChar = "";
        currChar = 0;
        charIndex++;
        if (i + 1 >= buff.size() || buff.at(i + 1) != ',') {
          break;
        }
      }
    }
    std::cout << ch << ": ";
    for (int j = 0; j < hexChars.size(); j++) {
      std::cout << hexChars.at(j) << ", ";
    }
    std::cout << std::endl;
    keyMap[ch] = hexChars;
    lineNum++;
  }
}

void KeyEmulator::Enable(bool enable) {
  this->enable = enable;
}

int KeyEmulator::Translate(int vkCode) {
  int c = (int)MapVirtualKey(vkCode, 2);

}

KeyEmulator::~KeyEmulator() {
  UnhookWindowsHookEx(kbHook);
}
