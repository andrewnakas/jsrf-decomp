/* sym: ??0Object_000CCE00@@QAE@XZ = 0x000CC620 */
/* sym: ??1Object_000CCE00@@UAE@XZ = 0x000CC680 */
/* sym: ?func_000CD1E0@Object_000CCE00@@UAEXXZ = 0x000CC6E0 */
/* sym: ?func_00011C90@Object_000CCE00@@UAEXXZ = 0x000CD050 */
extern "C" void *memset(void *destination, int value, unsigned int size);

struct Owner_000CBF90;
struct Limits_000CC020;

struct Vector_000CC620 {
    int x;
    int y;
    int z;
};

// Seventeen words; the constructor sets only the first.
struct Block_000CC620 {
    int kind;
    int unknown_04[16];
};

// The base with a pure slot 0 (table 0x1CE304).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600() {}
};

// The class whose table is at 0x1CE320.
struct Object_000CCE00 : Object_000CC600 {
    Object_000CCE00();
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual ~Object_000CCE00();
    virtual void func_000CBCD0();
    virtual void func_000CBD90();
    virtual void func_000CBE60();
    virtual void func_000CBF20();
    virtual void func_000CC910();
    virtual void func_000CD060();
    virtual void func_000CD140();
    virtual void func_000CD1A0();
    virtual void func_000CBF90();
    virtual void func_000CBFC0();
    virtual void func_000CCA40();
    virtual void func_000CC020();

    Owner_000CBF90 *owner;
    int state;
    int unknown_0c;
    int count;
    char unknown_14[0xc];
    Vector_000CC620 unknown_20;
    char unknown_2c[4];
    Limits_000CC020 *limits;
    char unknown_34[0x38];
    int handle;
    Block_000CC620 first;
    Block_000CC620 second;
    char unknown_f8[0xc];
    float unknown_104;
};

Object_000CCE00::Object_000CCE00()
{
    state = 0;
    handle = -1;
    memset(&unknown_20, 0, sizeof(unknown_20));
    memset(&first, 0, sizeof(first));
    first.kind = 0x41b;
    memset(&second, 0, sizeof(second));
    second.kind = 0x824;
    unknown_104 = 7.0f;
}
