/* sym: ??1Object_000A4D80@@UAE@XZ = 0x000A2820 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000A4D80@@UAEXXZ = 0x000A5070 */
/* sym: ?func_00011C90_1@Object_000A4D80@@UAEXXZ = 0x000A28B0 */
/* sym: ?func_00011C80@Object_000A4D80@@UAEXH@Z = 0x000A2960 */
/* sym: ?func_00011C80_4@Object_000A4D80@@UAEXH@Z = 0x000B3DE0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

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

// A camera node (table 0x1C43D8 repeats Node's slots 1 to 15; mask 7): eye, target, field of view and roll.
struct Object_00012170 : Node {
    Object_00012170(Node *owner, int id, unsigned int flags);

    Vector3 eye;
    char unknown_50[0xc];
    Vector3 target;
    char unknown_68[0xc];
    unsigned int fov;
    int unknown_78;
    int roll;
    int unknown_80;
    int left;
    int top;
    int width;
    int height;
    int unknown_94;
};

// The surface at +0x178: slot 3 opens a handle, slot 5 closes it, slot 16 presents it.
struct Surface_000A2960 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual int __stdcall slot3(int flags, void *settings, int argument);
    virtual void __stdcall slot4();
    virtual void __stdcall slot5(int handle);
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
    virtual void __stdcall slot16(int handle);
};

// The quad drawer at +0x180.
struct Drawer_000A2960 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8(float scale, float alpha);
    virtual void __stdcall slot9(void *vertices, int argument);
};

// The class whose table is at 0x1CD518 (constructor 0xA4D80, destructor 0xA2820): overrides slots 1 (A5070),
// 2 (A28B0), 3 (A2960), 15 (B3DE0).
struct Object_000A4D80 : Object_00012170 {
    virtual ~Object_000A4D80();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_098[0xd4];
    int texture_16c;
    int texture_170;
    int texture_174;
    Surface_000A2960 *surface;
    int unknown_17c;
    Drawer_000A2960 *drawer;
    int handle;
    char settings[0x24];
    unsigned int phase;
    unsigned int alpha;
    float offset;
    char unknown_1b8[0x24];
    unsigned int color;
};

// Closes the surface's handle and releases the surface and the drawer.
Object_000A4D80::~Object_000A4D80()
{
    surface->slot5(handle);
    surface->slot2();
    drawer->slot7();
    drawer->slot2();
    unknown_17c = 0;
}
