int func_001186D0(int handle);
int func_00118710(int handle);
int func_00118BD0(int first, int second);

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0xc88];
    int sound;
    char unknown_c8c[0x18];
    char position[0xc];

    void func_000A1CA0();
};

// While the sound at 0xc88 plays (func_00118710) it follows the position at 0xca4 (func_00118BD0, whose settled
// second parameter is an int); once it stops it is released (func_001186D0) and unset.
void Object_000A1C50::func_000A1CA0()
{
    if (sound >= 0) {
        if (func_00118710(sound)) {
            func_00118BD0(sound, (int)position);
        } else {
            func_001186D0(sound);
            sound = -1;
        }
    }
}
