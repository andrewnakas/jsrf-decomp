extern "C" void *memset(void *to, int value, unsigned int size);

// The settings block at +0x33c (0x30 bytes).
struct Settings_000676A0 {
    int unknown_00;
    int unknown_04;
    int unknown_08;
    int unknown_0c;
    int unknown_10;
    int unknown_14;
    int unknown_18;
    int unknown_1c;
    int unknown_20;
    int unknown_24;
    int unknown_28;
    int unknown_2c;
};

// The class whose table is at 0x1CB0F8 (constructor 0x67B60, destructor 0x67980).
struct Object_00067980 {
    char unknown_000[0x33c];
    Settings_000676A0 *settings;

    void func_000676A0();
};

// Resets the settings block at +0x33c: cleared, then 9 at +4, -1 at +0xc, 1 at +0x10, 3 at +0x14, 2 at +0x20 and
// +0x24, 1 at +0x2c.
void Object_00067980::func_000676A0()
{
    memset(settings, 0, sizeof(Settings_000676A0));
    settings->unknown_00 = 0;
    settings->unknown_04 = 9;
    settings->unknown_0c = -1;
    settings->unknown_10 = 1;
    settings->unknown_14 = 3;
    settings->unknown_1c = 0;
    settings->unknown_20 = 2;
    settings->unknown_24 = 2;
    settings->unknown_2c = 1;
}
