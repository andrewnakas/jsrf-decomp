/* sym: ??0Object_00069F00@@QAE@XZ = 0x00069A30 */
/* sym: ??1Object_00069F00@@UAE@XZ = 0x00069F00 */
/* sym: ??0Object_00047470@@QAE@XZ = 0x00048100 */
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

// The class whose table is at 0x1CC12C (constructor 0x69A30, destructor 0x69F00), built on Object_00047470.
struct Object_00069F00 : Object_00047470 {
    Object_00069F00();
    virtual ~Object_00069F00();

    float unknown_74;
    unsigned int unknown_78;
    float unknown_7c;
    int unknown_80;
};

// Sets flag 0x1000, +0x74 to 150, +0x78 to 0x80000000, +0x7c to 0.5 and +0x80 to 1.
Object_00069F00::Object_00069F00()
{
    flags |= 0x1000;
    unknown_78 = 0x80000000;
    unknown_74 = 150.0f;
    unknown_7c = 0.5f;
    unknown_80 = 1;
}
