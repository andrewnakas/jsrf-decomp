int func_0004A7F0(int first, int second);

// The player.
struct Object_000A1C50 {
    char unknown_000[0xd0];
    int angle_d0;
    char unknown_0d4[0x60];
    int unknown_134;
    char unknown_138[0xb88];
    int angle_cc0;

    int func_0007FB10();
};

// Whether the distance between the angles at +0xcc0 and +0xd0 (func_0004A7F0) is under 0x2aaa (60 degrees) while
// +0x134 is set.
int Object_000A1C50::func_0007FB10()
{
    if ((func_0004A7F0(angle_cc0, angle_d0) < 0 ? -func_0004A7F0(angle_cc0, angle_d0)
                                                : func_0004A7F0(angle_cc0, angle_d0)) < 0x2aaa &&
        unknown_134) {
        return 1;
    }
    return 0;
}
