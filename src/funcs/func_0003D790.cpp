/* sym: ??0Object_0003D790@@QAE@XZ = 0x0003D790 */
/* sym: ??0Object_00047470@@QAE@XZ = 0x00048100 */
/* sym: ??1Object_00047470@@UAE@XZ = 0x00048180 */
// The 15-bit pseudo-random generator (data_00251F28).
struct Object_00066980 {
    float func_00066950();
};

extern Object_00066980 data_00251F28;

// The base of the tables at 0x1CA490, 0x1CA5A8, 0x1CA5CC and 0x1CAA8C (constructor 0x48100).
struct Object_00047470 {
    Object_00047470();
    virtual ~Object_00047470();

    char unknown_04[0xc];
    int mode;
    char unknown_14[0x10];
    unsigned int flags;
    char unknown_28[0x4c];
};

// The class whose table is at 0x1CA490.
struct Object_0003D790 : Object_00047470 {
    Object_0003D790();

    float unknown_74;
    float unknown_78;
    float unknown_7c;
    float unknown_80;
    float unknown_84;
    float unknown_88;
    float unknown_8c;
    char unknown_90[4];
    float unknown_94;
    float unknown_98;
    int unknown_9c;
};

// Sets flag 0x200 and its values (+0x74 0.94, +0x78 0.6, +0x7c 20, +0x80 1, +0x84 and +0x88 0, +0x8c -1, +0x94 1),
// a random +0x98 (func_00066950) and clears +0x9c.
Object_0003D790::Object_0003D790()
{
    flags |= 0x200;
    unknown_74 = 0.94f;
    unknown_78 = 0.6f;
    unknown_7c = 20.0f;
    unknown_80 = 1.0f;
    unknown_88 = 0.0f;
    unknown_84 = 0.0f;
    unknown_8c = -1.0f;
    unknown_94 = 1.0f;
    unknown_98 = data_00251F28.func_00066950();
    unknown_9c = 0;
}
