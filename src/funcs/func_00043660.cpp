/* sym: ?func_00011C90@Object_000448B0@@UAEXXZ = 0x00043660 */
struct Motion_0005F060;
struct Item_000162A0;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);

struct Object_00039BE0 {
    int func_00039EF0(unsigned int id);
};

extern Object_00039BE0 data_001EFFB0;

struct Object_00016200 {
    void func_000162A0(Item_000162A0 *item);
};

extern Object_00016200 data_0022FCE8;

struct Node {
    virtual ~Node();
    virtual void func_00011C90();
};

// The node class whose table is at 0x1CA748 (destructor 0x448B0): overrides slots 1 (43660), 2 (436C0) and 3 (44400).
struct Object_000448B0 : Node {
    virtual void func_00011C90();

    char unknown_04[0x74];
    float time;
    int visible;
    char unknown_80[8];
    unsigned int model;
    char unknown_8c[8];
    Motion_0005F060 *motion;
    char unknown_98[4];
    int accepted;
    char item[1];
};

// Slot 1: keeps whether data_001EFFB0's func_00039EF0 accepts the id at +0x88 (+0x9c); when it does and +0x7c is
// set, hands the item at +0xa0 to func_000162A0 of 0x22FCE8 and steps the time at +0x78 through the motion at +0x94
// at half speed.
void Object_000448B0::func_00011C90()
{
    accepted = data_001EFFB0.func_00039EF0(model);
    if (accepted && visible) {
        data_0022FCE8.func_000162A0((Item_000162A0 *)item);
        func_0005E030(motion, &time, 0.5f, 0);
    }
}
