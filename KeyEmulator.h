#ifndef KeyEmulator_h
#define KeyEmulator_h

#include <iostream>
#include <stdlib.h>
#include <regex>
#include <string> 
class KeyEmulator {

    /* Variables */
    private:
    // Enabled / Disabled
    bool enable;
    
    /* Functions */  
    public:
    // CTOR
    KeyEmulator();
    // Enable
    void Enable(bool enable);
    // Run emulator
    void Run();
    // DTOR
    ~KeyEmulator();
};

#endif
