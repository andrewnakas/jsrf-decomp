/* sym: ??0Object_000416C0@@QAE@XZ = 0x000416C0 */
/* sym: ??0Object_00047470@@QAE@XZ = 0x00048100 */
/* sym: ??1Object_00047470@@UAE@XZ = 0x00048180 */
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

// The class whose table is at 0x1CA5CC.
struct Object_000416C0 : Object_00047470 {
    Object_000416C0();

    int unknown_74;
    int unknown_78;
    int unknown_7c;
    int unknown_80;
    int unknown_84;
    int unknown_88;
};

// Sets flag 0x400, clears +0x74 to +0x88 and sets the mode at +0x10 to 5.
Object_000416C0::Object_000416C0()
{
    flags |= 0x400;
    unknown_84 = unknown_7c = unknown_80 = unknown_74 = unknown_78 = unknown_88 = 0;
    mode = 5;
}
