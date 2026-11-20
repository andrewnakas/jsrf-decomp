/* sym: ??1Object_000E5FF0@@UAE@XZ = 0x000E6100 */
/* sym: ?func_000CD1E0@Object_000E5FF0@@UAEXXZ = 0x000E6180 */
/* sym: ?func_00011C90@Object_000E5FF0@@UAEXXZ = 0x000E6900 */
/* sym: ?func_00011C80@Object_000E5FF0@@UAEXH@Z = 0x000E5450 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_00016200 {
    void func_00019760(void *pointer);
};

extern Object_00016200 data_0022FCE8;

struct Object_0003E750 {
    void func_0003F280(int index);
};

extern Object_0003E750 data_002314B0;

struct Object_0006DB80 {
    void func_0006DF30(int key);
};

extern Object_0006DB80 data_00251F78;

// The object at data_00257CE8 (func_00157F10 is the engine's); it also answers func_000C1D40.
struct Object_00157F10 {
    int func_000C1D40(int *effect, int *second, int *third);
};

extern Object_00157F10 *data_00257CE8;

// The object a behaviour serves (the owner type of the Object_000CC600 family).
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0x4c];
    int value_9c;
    char unknown_a0[4];
    unsigned int flags;
};

void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);
float __fastcall func_0014C6B0(const Vector3 *vector);
void func_000FEC30(int value, const Vector3 *position);

// The base with a pure slot 0 (table 0x1CE304, destructor func_000E7EB0).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600() {}
};

// The class whose table is at 0x1CED80 (handlers at 0x218DD0, run by the state at 0x30).
struct Object_000E5FF0 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual ~Object_000E5FF0();

    void func_000E6720();

    Object_000C5B50 *owner;
    char unknown_08[0xc];
    Vector3 target;
    char unknown_20[0x2c];
    int key;
    float distance;
    char unknown_54[0x18];
    void *mesh;
    char unknown_70[0x108];
    int effect;
    int value_17c;
    int value_180;
};

// Releases the key at 0x4c (data_00251F78), the effect at 0x178 (data_002314B0) and the mesh at 0x6c
// (data_0022FCE8).
Object_000E5FF0::~Object_000E5FF0()
{
    if (key != -1) {
        data_00251F78.func_0006DF30(key);
    }
    if (effect != -1) {
        data_002314B0.func_0003F280(effect);
    }
    if (mesh) {
        data_0022FCE8.func_00019760(mesh);
    }
}
