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
}

void KeyEmulator::Enable(bool enable) {
  this->enable = enable;
}

int KeyEmulator::Translate(int vkCode) {
  int c = (int)MapVirtualKey(vkCode, 2);
  switch (c) {
    case
  }
}

KeyEmulator::~KeyEmulator() {
  UnhookWindowsHookEx(kbHook);
}
