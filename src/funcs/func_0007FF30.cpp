struct Vector3 {
    float x;
    float y;
    float z;
};

struct Motion_0007FF30 {
    char unknown_00[0x44];
    int frame;
};

struct Object_000A1C50 {
    char unknown_0000[0x404];
    Vector3 savedPosition;
    int savedAngles[3];
    int savedFrame;
    char unknown_0420[0x884];
    Vector3 position;
    char unknown_0cb0[0xc];
    int angles[3];
    char unknown_0cc8[0x354];
    Motion_0007FF30 *motion;

    void func_0007FF30();
};

// Keeps the player's position, its angles at +0xcbc and its motion's frame (+0x404 to +0x41c).
void Object_000A1C50::func_0007FF30()
{
    savedPosition = position;
    savedAngles[0] = angles[0];
    savedAngles[1] = angles[1];
    savedAngles[2] = angles[2];
    savedFrame = motion->frame;
}
