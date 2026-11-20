/* sym: ?func_000C3D90@Object_000F2AA0@@UAEXXZ = 0x000F2C10 */
/* sym: ??1Object_000F2AA0@@UAE@XZ = 0x000F2770 */
struct Game {
    void *func_000128C0(int id);
};

struct Object_000607B0 {
    void func_00060810(int key);
};

extern Game *data_0022FCE0;

struct Object_000C5B50 {
    void func_000C5B50(int *handle);
};

struct Object_000F1820;

// The base of the small state machines (tables 0x1CDDB8, 0x1CDDCC, 0x1CF02C and 0x1CF040): slots 0 and 1 are
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

// Drops the twelve keys at 0x38 with object 0xe8 (func_00060810) when it exists, then has the owner release the
// handles at 0x84, 0x94, 0xa4 and 0xa8 (func_000C5B50).
Object_000F2AA0::~Object_000F2AA0()
{
    Object_000607B0 *target = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (target) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                target->func_00060810(ids[i][j]);
            }
            owner->func_000C5B50(&handles_84[i]);
            owner->func_000C5B50(&handles_94[i]);
        }
    }
    owner->func_000C5B50(&handle_a4);
    owner->func_000C5B50(&handle_a8);
}
