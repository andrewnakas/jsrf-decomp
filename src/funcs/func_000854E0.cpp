/* sym: ?func_00011C80@Object_00086060@@UAEXH@Z = 0x000854E0 */
void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BB2E0(int handle);
void __fastcall func_001BB330(int handle);
void func_000146E0(int id);

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

struct Vector3 {
    float x;
    float y;
    float z;
};

void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

struct Object_00047470 {
    virtual ~Object_00047470();
    virtual void slot1();
    virtual void func_00047470();
    virtual void slot3();
    virtual void func_00047540();
    virtual void func_00047690(int first, int second);

    void func_00047970(void *data, int argument);
};

struct Holder_000854E0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6(Object_00047470 *object);
};

// The class whose table is at 0x1CD0C0: overrides slots 1 (85480), 2 (854B0), 3 (854E0).
struct Object_00086060 : Node {
    virtual ~Object_00086060();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);

    int state;
    float unknown_48[3];
    char unknown_054[0xc];
    int unknown_60;
    int unknown_64;
    char unknown_068[0x34];
    unsigned int flags;
    int unknown_a0;
    char unknown_0a4[0x5c];
    Object_00047470 *unknown_100;
    Holder_000854E0 *unknown_104;
};

// Slot 3: with flag 1, under the position at +0x48 (func_001BAAA0): pass 7 stores the depth of the moved origin,
// pass 8 draws +0x100 (slot 5) turned by the angles at +0x64 / +0x60 and object +0xa0 (func_000146E0), passes 15 and 16
// set +0x100 up (func_00047970) and hand it to slot 6 of +0x104.
void Object_00086060::func_00011C80(int argument)
{
    if (flags & 1) {
        func_001BAAA0(unknown_48);
        switch (argument) {
        case 7: {
            Vector3 origin;
            func_001BAB20(&origin, 0);
            depth = origin.z;
            break;
        }
        case 8:
            func_001BA9C0();
            func_001BB330(unknown_64);
            func_001BB2E0(unknown_60);
            unknown_100->func_00047690(0, 0);
            func_000146E0(unknown_a0);
            func_001BAA50();
            break;
        case 15:
        case 16:
            func_001BB330(unknown_64);
            func_001BB2E0(unknown_60);
            unknown_100->func_00047970(0, 0);
            unknown_104->slot6(unknown_100);
            break;
        }
    }
}
