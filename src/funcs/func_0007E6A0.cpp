/* sym: ??0Object_0007E2F0@@QAE@PAUNode@@HI@Z = 0x0007E6A0 */
/* sym: ??1Object_0007E2F0@@UAE@XZ = 0x0007E2F0 */
/* sym: ??0Object_00012170@@QAE@PAUNode@@HI@Z = 0x00012170 */
/* sym: ??1Object_00012170@@UAE@XZ = 0x000121D0 */
struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();

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

// A node with no virtual functions of its own (table 0x1C43D8 repeats Node's slots 1 to 15) and mask 7.
struct Object_00012170 : Node {
    Object_00012170(Node *owner, int id, unsigned int flags);
    virtual ~Object_00012170();

    char unknown_44[0x50];
    int unknown_94;
};

// A Direct3D resource: slot 2 releases it.
struct Resource_0007E2F0 {
    virtual void __stdcall slot0();
};

struct Interface_00251D74 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4();
    virtual long __stdcall slot5();
    virtual long __stdcall slot6();
    virtual long __stdcall slot7();
    virtual long __stdcall slot8();
    virtual long __stdcall slot9(int first, int second, Resource_0007E2F0 **result);
};

extern Interface_00251D74 *data_00251D74;

struct Device_00251D6C {
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
    virtual void __stdcall slot12();
    virtual void __stdcall slot13();
    virtual void __stdcall slot14();
    virtual void __stdcall slot15();
    virtual void __stdcall slot16();
    virtual void __stdcall slot17();
    virtual void __stdcall slot18();
    virtual void __stdcall slot19();
    virtual void __stdcall slot20();
    virtual void __stdcall slot21();
    virtual void __stdcall slot22();
    virtual void __stdcall slot23();
    virtual void __stdcall slot24(int value);
};

extern Device_00251D6C *data_00251D6C;
extern int data_0020D498[];

// Object 0x1FC724: the value at +0 (func_00043700) and the word at +4 (the getter folded with 0x149D0).
struct Object_00043700 {
    int func_00043700();
    int func_000149D0_2();
};

extern Object_00043700 data_001FC724;

void *func_00025700(unsigned int index, int first, int second, int third);
void func_00024600(int colour);
void func_00024620(unsigned int mode, float rate);
void func_0007E260(Node *owner);

// The node class whose table is at 0x1CCFB8 (constructor 0x7E6A0, destructor 0x7E2F0; 0xbc bytes).
struct Object_0007E2F0 : Object_00012170 {
    Object_0007E2F0(Node *owner, int id, unsigned int flags);
    virtual ~Object_0007E2F0();

    unsigned int unknown_98;
    int unknown_9c;
    int unknown_a0;
    int unknown_a4;
    void *unknown_a8;
    void *unknown_ac;
    int unknown_b0;
    int unknown_b4;
    Resource_0007E2F0 *resource;
};

// Clears +0x98 to +0xa4, keeps object 0x1FC724's two values (+0xb0, +0xb4) and two func_00025700 handles of kind
// 0x16 (+0xa8, +0xac), creates the resource at +0xb8 (slot 9 of 0x251D74), sets the colour 0xff000000 and the rate
// 1/120, hands the device (slot 24) the entry of 0x20D498 for +0x98 / 3 and runs func_0007E260.
Object_0007E2F0::Object_0007E2F0(Node *owner, int id, unsigned int flags) : Object_00012170(owner, id, flags)
{
    unknown_98 = 0;
    unknown_9c = 0;
    unknown_a0 = 0;
    unknown_a4 = 0;
    unknown_b0 = data_001FC724.func_00043700();
    unknown_b4 = data_001FC724.func_000149D0_2();
    unknown_a8 = func_00025700(0x16, 0, 0, 0);
    unknown_ac = func_00025700(0x16, 1, 0, 0);
    data_00251D74->slot9(1, 0, &resource);
    func_00024600(0xff000000);
    func_00024620(0, 0.0083333338f);
    data_00251D6C->slot24(data_0020D498[unknown_98 / 3]);
    func_0007E260(0);
}
