/* sym: ??0Object_000F1820@@QAE@PAUObject_000C5B50@@@Z = 0x000F1820 */
/* sym: ??0Object_000F2AA0@@QAE@PAUObject_000C5B50@@@Z = 0x000F2710 */
struct Vector3;

void *operator new(unsigned int size);

// The owner (func_000C5B50's class): node flags at 0x4, the two state machines at 0xd4 and 0xd8, the event
// handler at 0xe8.
struct Object_000C5B50 {
    char unknown_00[4];
    unsigned int flags;
    char unknown_08[0xcc];
    struct Object_000F1820 *first;
    struct Object_000F2AA0 *second;
    char unknown_dc[0xc];
    int (*callback)(int event, Vector3 *position);
};

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

// The state machine whose table is at 0x1CF02C (0x1ac bytes).
struct Object_000F1820 : Object_000C4070 {
    Object_000F1820(Object_000C5B50 *owner);
    virtual void func_000C3D90();
    virtual void func_00011C90();
    virtual ~Object_000F1820();

    char unknown_08[0x1a4];
};

// The state machine whose table is at 0x1CF040 (0xac bytes); it keeps the first at 0x80.
struct Object_000F2AA0 : Object_000C4070 {
    Object_000F2AA0(Object_000C5B50 *owner);
    virtual void func_000C3D90();
    virtual void func_00011C90();
    virtual ~Object_000F2AA0();

    char unknown_08[0x78];
    Object_000F1820 *machine;
    char unknown_84[0x28];
};

int func_000F0CF0(int event, Vector3 *position);

// Gives the owner its two state machines (0x1CF02C at 0xd4, 0x1CF040 at 0xd8, which also points at the first)
// and its event handler func_000F0CF0, and sets its flag 4.
void func_000F1FC0(Object_000C5B50 *owner)
{
    Object_000F1820 *first = new Object_000F1820(owner);
    Object_000F2AA0 *second = new Object_000F2AA0(owner);
    owner->flags |= 4;
    first->owner = owner;
    second->owner = owner;
    second->machine = first;
    owner->first = first;
    owner->second = second;
    owner->callback = func_000F0CF0;
}
