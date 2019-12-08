g++ main.cpp KeyEmulator.h KeyEmulator.cpp -o cherokee-keyboard.exe -I"C:\SFML-2.5.1\include" -L"C:\SFML-2.5.1\lib" -lsfml-window -lsfml-system -lsfml-graphics
cp cherokee-keyboard.exe exe/
cd exe/
./cherokee-keyboard.exe
