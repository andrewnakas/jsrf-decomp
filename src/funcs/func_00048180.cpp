/* sym: ??1Object_00047470@@UAE@XZ = 0x00048180 */
struct Frame_000479D0;
struct Surface_000476F0;

// The base of the tables at 0x1CA490, 0x1CA5A8, 0x1CA5CC and 0x1CAA8C.
struct Object_00047470 {
    virtual ~Object_00047470();
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

// Releases what the object holds (slot 7, func_00047550).
Object_00047470::~Object_00047470()
{
    func_00047550();
}
