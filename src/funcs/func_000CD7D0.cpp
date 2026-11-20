/* sym: ??0Object_000CD1E0@@QAE@XZ = 0x000CD7D0 */
/* sym: ?func_00011C90@Object_000CD1E0@@UAEXXZ = 0x000CD200 */
extern "C" void *memset(void *destination, int value, unsigned int size);

struct Vector_000CD7D0 {
    int x;
    int y;
    int z;
};

// The base with a pure slot 0 (table 0x1CE304).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600() {}
};

// The class whose table is at 0x1CE364; slots 8 and 9 are pure.
struct Object_000CD1E0 : Object_000CC600 {
    Object_000CD1E0();
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_000CD210();
    virtual void func_000CD800();
    virtual void func_000CD850();
    virtual void func_000D77D0() = 0;
    virtual void func_000D7880() = 0;
    virtual void func_000CD440();
    virtual float func_000CD4F0();
    virtual void func_000CD390();

    int unknown_04;
    int state;
    int unknown_0c;
    int unknown_10;
    char unknown_14[0xc];
    Vector_000CD7D0 unknown_20;
    char unknown_2c[0xc];
    int unknown_38;
    int unknown_3c;
    int unknown_40;
    int unknown_44;
    int unknown_48;
    char unknown_4c[0x1c];
    int unknown_68;
};

Object_000CD1E0::Object_000CD1E0()
{
    unknown_38 = 0;
    unknown_3c = 0;
    unknown_10 = 0;
    unknown_44 = 0;
    unknown_48 = 0;
    state = 0;
    unknown_68 = 0;
    memset(&unknown_20, 0, sizeof(unknown_20));
}
