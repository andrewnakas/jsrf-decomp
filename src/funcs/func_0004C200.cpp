/* sym: ??0Object_00074C60@@QAE@PAUNode@@HIPAUObject_0006A720@@@Z = 0x00074BD0 */
struct Node;

void operator delete(void *memory);

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The object 0x12b1.
struct Object_000C0A90 {
    void func_000C04D0();
};

struct Object_00039BE0 {
    void func_0003AEA0(int kind);
};

extern Object_00039BE0 data_001EFFB0;

struct Object_0006A720;

// The class whose table is at 0x1CCC98 (constructor 0x74BD0; 0x58 bytes).
struct Object_00074C60 {
    Object_00074C60(Node *owner, int id, unsigned int flags, Object_0006A720 *source);

    char unknown_00[0x58];
};

// Object 9.
struct Object_0004ABA0 {
    char unknown_0000[0x64];
    void *unknown_64;
    char unknown_0068[0xfe8];
    Object_0006A720 *unknown_1050;

    void func_0004C200();
};

// Called by func_00051780: runs func_000C04D0 of object 0x12b1 when it exists, creates an Object_00074C60 under this
// object (no id, flags 0) for +0x1050, runs func_0003AEA0 (0) of 0x1EFFB0 and frees the block at +0x64.
void Object_0004ABA0::func_0004C200()
{
    Object_000C0A90 *object = (Object_000C0A90 *)data_0022FCE0->func_000128C0(0x12b1);
    if (object)
        object->func_000C04D0();
    new Object_00074C60((Node *)this, -1, 0, unknown_1050);
    data_001EFFB0.func_0003AEA0(0);
    if (unknown_64) {
        operator delete(unknown_64);
        unknown_64 = 0;
    }
}
