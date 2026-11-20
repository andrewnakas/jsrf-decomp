/* sym: ?func_00011C90@Object_000E6E80@@UAEXXZ = 0x000E7470 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_000C1270 {
    int func_000C1160(int kind, int count, Vector3 *position);
    void func_000C1270(int handle, void *position);
};

extern Object_000C1270 *data_00257CE4;

extern Vector3 data_00218E40;

int func_00118710(int handle);
void func_001BAA00();
void func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C90_5();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C90_7();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C90_9();
    virtual void func_00011C80_4(int argument);

    unsigned int flags;
    int id;
    unsigned int mask;
    float depth;
    int sortKey;
    char unknown_18[0xc];
    Node *parent;
    Node *child;
    Node *previous;
    Node *next;
    char unknown_34[0x10];
};

// The child of Node whose table is at 0x1CEDA0; its handlers (table at 0x218E4C) run by the state at 0x9c.
struct Object_000E6E80 : Node {
    virtual ~Object_000E6E80();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    void func_000E6DF0();

    char unknown_044[0x24];
    Vector3 previous;
    char unknown_074[0x1c];
    int angles[3];
    int state;
    unsigned int flags_a0;
    char unknown_0a4[4];
    Vector3 trail[95];
    unsigned int index;
    char unknown_520[0x8c];
    int handle;
};

// The handlers slot 1 runs by the state at 0x9c.
extern void (Object_000E6E80::*data_00218E4C[])();

// Slot 1: runs the handler of the state; unless flag 1 at 0xa0 is set, inside a matrix at the point at 0x68 turned
// by the angles at 0x90: func_000E6DF0, the effect of the handle at 0x5ac moved there while it lasts
// (func_00118710, func_000C1270) or a new kind-0x2a one, and the next of the 95 trail points at 0xa8 set from
// data_00218E40.
void Object_000E6E80::func_00011C90()
{
    (this->*data_00218E4C[state])();
    if (!(flags_a0 & 1)) {
        func_001BAA00();
        func_001BAAA0(&previous.x);
        func_001BB330(angles[1] + 0x8000);
        func_001BB2E0(angles[0]);
        func_001BB380(angles[2]);
        func_000E6DF0();
        if (func_00118710(handle)) {
            data_00257CE4->func_000C1270(handle, &previous);
        } else {
            data_00257CE4->func_000C1160(0x2a, 3, &previous);
        }
        func_001BAB20(&trail[index], &data_00218E40);
        if (++index >= 95) {
            index = 0;
        }
        func_001BAA50();
    }
}
