/* sym: ?func_00011C90@Object_00070BD0@@UAEXXZ = 0x00070BE0 */
struct Node {
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
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

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Interface_00070C90 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8();
    virtual void __stdcall slot9();
    virtual void __stdcall slot10();
    virtual void __stdcall slot11();
    virtual void __stdcall slot12(int first, int second);
    virtual void __stdcall slot13(int value);
    virtual void __stdcall slot14(int first, void *data);
};

struct Motion_00070BE0 {
    short unknown_00;
    short frames;
};

struct Model_00070C90 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(Motion_00070BE0 *motion, float time);

    Interface_00070C90 *unknown_04;
    char unknown_08[0x1c];
    unsigned int flags;
};


struct Game {
    void *func_000128C0(int id);
};

struct Object_00137910 {
    int func_00137920();
};

extern Game *data_0022FCE0;

// The class whose table is at 0x1CCA38: overrides slots 1 (70BE0), 3 (70C90), 4 (AECC0), 6 (B3DE0), 7 (AECC0), 9 (B3DE0), 10 (AECC0), 12 (B3DE0), 13 (AECC0), 15 (B3DE0).
struct Object_00070BD0 : Node {
    virtual ~Object_00070BD0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C80_4(int argument);

    unsigned int unknown_44;
    int unknown_48;
    Vector3 unknown_4c;
    int unknown_58;
    int unknown_5c;
    Vector3 position;
    int angles[3];
    Vector3 scale;
    float unknown_84;
    int unknown_88;
    int unknown_8c;
    int unknown_90;
    int unknown_94;
    Model_00070C90 *model;
    Motion_00070BE0 *motion;
    float time;
    int unknown_a4;
    int phase;
    int unknown_ac;
    int unknown_b0[6];
    int hasB0;
};

// Slot 1: ends the node unless object 0x1DEB is in state 2, then steps the motion's time and wraps it at the last
// frame.
void Object_00070BD0::func_00011C90()
{
    if (((Object_00137910 *)data_0022FCE0->func_000128C0(0x1deb))->func_00137920() != 2 && this) {
        func_00011BE0(this);
        func_00011C20(child);
    }
    switch (phase) {
    case 0:
        time = 0.0f;
        phase = 1;
    case 1:
        if (motion) {
            time += 1.0f;
            if (time > motion->frames - 1.0f) {
                time = 0.0f;
            }
        }
        break;
    }
}
