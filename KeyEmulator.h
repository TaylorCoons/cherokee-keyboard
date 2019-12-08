#ifndef KeyEmulator_h
#define KeyEmulator_h

#include <iostream>
#include <stdlib.h>
#include <regex>
#include <string> 
class KeyEmulator {

    /* Variables */
    private:
    // System type
    enum SYSTEM {
        WIN,
        POSIX,
        OTHER
    };
    SYSTEM sys;
    // Enabled / Disabled
    bool enable;
    
    /* Functions */

    private:
    // Detect current system
    SYSTEM DetectSystem();
     
    public:
    // CTOR
    KeyEmulator();
    // Enable
    void Enable(bool enable);
    // DTOR
    ~KeyEmulator();
};

#endif
