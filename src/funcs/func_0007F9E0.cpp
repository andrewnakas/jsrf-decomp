int func_0004A7F0(int first, int second);

// One entry of the player's parameter table (0x98 bytes).
struct Limit_0007F9E0 {
    int value;
    char unknown_04[0x94];
};

struct Table_0007F9E0 {
    char unknown_000[0x100];
    Limit_0007F9E0 limits[1];
};

struct Object_000A1C50 {
    char unknown_000[0x88];
    float speed_88;
    char unknown_08c[0x44];
    int angle_d0;
    char unknown_0d4[0x9c0];
    int unknown_a94;
    char unknown_a98[0x1f8];
    Table_0007F9E0 *table;
    char unknown_c94[0x2c];
    int angle_cc0;
    char unknown_cc4[0x4a4];
    int index;

    int func_0007F9E0();
};

// Whether, with +0xa94 clear and the speed at +0x88 above 0, the distance between the angles at +0xcc0 and +0xd0
// (func_0004A7F0) exceeds the limit of the player's entry (+0x1168) in its table.
int Object_000A1C50::func_0007F9E0()
{
    if (!unknown_a94 && speed_88 > 0.0f) {
        if ((func_0004A7F0(angle_cc0, angle_d0) < 0 ? -func_0004A7F0(angle_cc0, angle_d0)
                                                    : func_0004A7F0(angle_cc0, angle_d0)) > table->limits[index].value) {
            return 1;
        }
    }
    return 0;
}
