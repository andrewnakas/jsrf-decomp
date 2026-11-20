int func_001186D0(int handle);
int func_00118710(int handle);

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0xc7c];
    int sounds[5];

    void func_000A1D30();
};

// Stops the five sounds at 0xc7c that are still playing (func_00118710, func_001186D0) and clears their handles.
void Object_000A1C50::func_000A1D30()
{
    if (sounds[0] >= 0) {
        if (func_00118710(sounds[0])) {
            func_001186D0(sounds[0]);
        }
        sounds[0] = -1;
    }
    if (sounds[1] >= 0) {
        if (func_00118710(sounds[1])) {
            func_001186D0(sounds[1]);
        }
        sounds[1] = -1;
    }
    if (sounds[2] >= 0) {
        if (func_00118710(sounds[2])) {
            func_001186D0(sounds[2]);
        }
        sounds[2] = -1;
    }
    if (sounds[3] >= 0) {
        if (func_00118710(sounds[3])) {
            func_001186D0(sounds[3]);
        }
        sounds[3] = -1;
    }
    if (sounds[4] >= 0) {
        if (func_00118710(sounds[4])) {
            func_001186D0(sounds[4]);
        }
        sounds[4] = -1;
    }
}
