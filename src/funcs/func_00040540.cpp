/* sym: ??0Object_00040540@@QAE@XZ = 0x00040540 */
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

// The class whose table is at 0x1CA5A8.
struct Object_00040540 : Object_00047470 {
    Object_00040540();

    int first[5];
    int second[5];
    int unknown_9c;
};

// Sets flag 0x800 and the mode at +0x10 to 5 and clears the five words at +0x74, the five at +0x88 and +0x9c.
Object_00040540::Object_00040540()
{
    flags |= 0x800;
    mode = 5;
    for (int i = 0; i < 5; i++) {
        first[i] = 0;
        second[i] = 0;
    }
    unknown_9c = 0;
}
