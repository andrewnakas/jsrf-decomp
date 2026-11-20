/* sym: ??0Object_000F2AA0@@QAE@PAUObject_000C5B50@@@Z = 0x000F2710 */
/* sym: ?func_000C3D90@Object_000F2AA0@@UAEXXZ = 0x000F2C10 */
/* sym: ??1Object_000F2AA0@@UAE@XZ = 0x000F2770 */
extern "C" void *memset(void *destination, int value, unsigned int size);

struct Object_000C5B50;

struct Object_000F1820;

// The base of the small state machines (tables 0x1CDDB8, 0x1CDDCC and 0x1CF040): slots 0 and 1 are
// pure, slots 2 and 3 take an argument and do nothing, slot 4 is the destructor.
struct Object_000C4070 {
    virtual void func_000C3D90() = 0;
    virtual void func_00011C90() = 0;
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000C4070() {}

    Object_000C5B50 *owner;
};

// The state machine whose table is at 0x1CF040 (made by func_000F1FC0 with the one at 0x1CF02C, which it keeps at
// 0x80; destructor func_000F2770): the handles at 0x70 to 0xa8 belong to the owner (func_000C5B50).
struct Object_000F2AA0 : Object_000C4070 {
    Object_000F2AA0(Object_000C5B50 *owner);
    virtual void func_000C3D90();
    virtual void func_00011C90();
    virtual ~Object_000F2AA0();

    int state;
    char unknown_0c[0xc];
    int unknown_18[4];
    char unknown_28[0x10];
    int ids[4][3];
    int first;
    int second;
    int handles_70[4];
    Object_000F1820 *machine;
    int handles_84[4];
    int handles_94[4];
    int handle_a4;
    int handle_a8;
};

Object_000F2AA0::Object_000F2AA0(Object_000C5B50 *owner)
{
    state = 0;
    memset(unknown_18, 0, sizeof(unknown_18));
    for (int i = 0; i < 4; i++) {
        handles_70[i] = -1;
        handles_84[i] = -1;
        handles_94[i] = -1;
    }
    handle_a4 = -1;
    handle_a8 = -1;
    first = 0;
    second = 2;
}
