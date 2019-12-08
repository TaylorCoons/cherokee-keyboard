#include "KeyEmulator.h"

KeyEmulator::KeyEmulator() {
    sys = DetectSystem();
    enable = true;
}

KeyEmulator::SYSTEM KeyEmulator::DetectSystem() {
    char* path = getenv("PATH");
    std::smatch m;
    std::string s(path);
    std::regex e("/usr/bin");
    std::regex_search(s, m, e);
    if (!m.empty()) {
        std::cout << "linux" << std::endl;
    } else {
        std::cout << "unknown" << std::endl;
    }
    std::cout << path << std::endl;
}

void KeyEmulator::Enable(bool enable) {
    this->enable = enable;
}

KeyEmulator::~KeyEmulator() {
}
