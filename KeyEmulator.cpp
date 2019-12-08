#include "KeyEmulator.h"

// Check for which system
#if defined(__WIN32) || defined(__WIN64)
#define WIN_SYS
#elif defined(__linux__) || defined(__linux) || defined(linux)
#define LINUX_SYS
#endif

KeyEmulator::KeyEmulator() {
    enable = true;
}

void KeyEmulator::Enable(bool enable) {
    this->enable = enable;
}

#ifdef WIN_SYS
void KeyEmulator::Run() {

}
#endif

#ifdef LINUX_SYS
void KeyEmulator::Run() {

}
#endif


KeyEmulator::~KeyEmulator() {
}
