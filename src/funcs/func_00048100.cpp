/* sym: ??0Object_00047470@@QAE@XZ = 0x00048100 */
struct Frame_000479D0;
struct Surface_000476F0;

// The base of the tables at 0x1CA490, 0x1CA5A8, 0x1CA5CC and 0x1CAA8C.
struct Object_00047470 {
    Object_00047470();
    virtual ~Object_00047470()
    {
        func_00047550();
    }
    virtual void func_00048190(void *first, void *second, Frame_000479D0 *frame);
    virtual void func_00047470();
    virtual void func_00048390();
    virtual void func_00047540();
    virtual void func_00047690(int value, int argument);
    virtual void func_00047820(int value);
    virtual int func_00047550();
    virtual void func_00047600(Frame_000479D0 *frame);

    void func_000476F0(int argument);
    void func_00047710(int first, int second, int third);

    Surface_000476F0 *surface;
    Frame_000479D0 *frames;
    void *unknown_0c;
    int mode;
    int unknown_14;
    int unknown_18;
    int unknown_1c;
    int unknown_20;
    unsigned int flags;
    float unknown_28;
    int unknown_2c;
    int unknown_30;
    float unknown_34;
    float unknown_38;
    int unknown_3c;
    int unknown_40;
    int unknown_44;
    float colour[4];
    float unknown_58;
    int unknown_5c;
    int unknown_60;
    void (Object_00047470::*draw)(int argument);
    void (Object_00047470::*drawAt)(int first, int second, int third);
    void **unknown_6c;
    unsigned int unknown_70;
};

// Clears the object; flags 9, 0.08 at +0x28 and +0x38, 1.0 at +0x34, 1 at +0x40, the colour at +0x48 to 0.5 and -1.0
// at +0x58; the two draw handlers start as func_000476F0 and func_00047710.
Object_00047470::Object_00047470()
{
    mode = 0;
    unknown_18 = 0;
    surface = 0;
    frames = 0;
    unknown_0c = 0;
    unknown_20 = 0;
    flags = 9;
    unknown_28 = 0.08f;
    unknown_2c = 0;
    unknown_30 = 0;
    unknown_34 = 1.0f;
    unknown_38 = 0.08f;
    unknown_3c = 0;
    colour[0] = colour[1] = colour[2] = colour[3] = 0.5f;
    unknown_44 = 0;
    unknown_40 = 1;
    unknown_58 = -1.0f;
    unknown_5c = 0;
    unknown_60 = 0;
    draw = &Object_00047470::func_000476F0;
    drawAt = &Object_00047470::func_00047710;
    unknown_6c = 0;
    unknown_70 = 0;
}
