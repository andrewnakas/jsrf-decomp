/* const: 0x10000 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Entry_00015090;

struct Object_00015130 {
    void func_00015010(Entry_00015090 *entry, const Vector3 *position, int kind, int flag);
};

extern Object_00015130 data_001EB994;

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x420];
    Entry_00015090 *entry;
    char unknown_424[0x740];
    int count_b64;
    char unknown_b68[0xfc];
    float limit;
    char unknown_c68[0x3c];
    Vector3 position;
    char unknown_cb0[0x24];
    float scale;
    char unknown_cd8[0x498];
    int timer;

    int func_0007F880();
    void func_0009B190(int pose);
    int func_0009C690(int kind);
    void func_000A2680();
    int func_000A2700();
};

// Entry of the player's handler table at 0x215364: while the timer at 0x1170 runs, the scale at 0xcd4 grows (above
// 18) or shrinks, and the timer stops once it is under the limit at 0xc64. Otherwise, with bit 16 of func_0007F880
// lands with pose 1; else with the count at 0xb64 used up lands with pose 6, or takes one (func_0009C690(1),
// func_000A2680) and sends kind 2 at the position with the scale to data_001EB994 (func_00015010). Always 1.
int Object_000A1C50::func_000A2700()
{
    if (timer > 0) {
        if (timer > 18) {
            scale += 0.011022927f;
        } else {
            scale -= 0.025720164f;
        }
        if (scale < limit) {
            timer = 0;
        }
        return 1;
    }
    if (func_0007F880() & 0x10000) {
        func_0009B190(1);
        return 1;
    }
    if (count_b64 <= 0) {
        func_0009B190(6);
    } else {
        func_0009C690(1);
        func_000A2680();
        count_b64--;
    }
    data_001EB994.func_00015010(entry, &position, 2, *(int *)&scale);
    return 1;
}
