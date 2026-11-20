struct Vector3 {
    float x;
    float y;
    float z;
};

struct Motion_0005F060;

struct Item_000162A0 {
    char unknown_00[8];
};

struct Part_00017F60 {
    Vector3 center;
    float radius;
    Vector3 motion;
    char unknown_1c[8];
};

struct Mesh_00017F60 {
    Part_00017F60 *parts;
};

struct Object_00016200 {
    void func_00019570(Mesh_00017F60 *mesh, const Mesh_00017F60 *source);
    void func_000162A0(Item_000162A0 *item);
};

struct Object_000C1270 {
    int func_000C1160(int kind, int value, Vector3 *position);
    void func_000C1270(int handle, void *position);
};

struct Node {
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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;
};

// The child of Node whose table is at 0x1CF098 (constructor func_000F3E60, destructor func_000F3F70): its slot 1
// runs entry `state` of the member-function table at 0x21b2dc on itself.
struct Object_000F44E0 : Node {
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    int unknown_040;
    unsigned int state;
    Vector3 position;
    char unknown_054[0xc];
    int angle;
    float x;
    int unknown_068;
    float z;
    int count;
    char unknown_074[0x24];
    Motion_0005F060 *motion;
    float time;
    char unknown_0a0[0x44];
    Item_000162A0 item;
    Mesh_00017F60 *mesh;
    char unknown_0f0[0x18];
    int handle;

    void func_000F40E0();
};

extern Object_000C1270 *data_00257CE4;
extern Object_00016200 data_0022FCE8;
extern const Mesh_00017F60 data_0021B2C4;

int func_0005E030(Motion_0005F060 *motion, float *time, float step, int flag);
int func_0014C7D0(float x, float z);
void func_000C70A0(Node *owner, Vector3 *position, int kind);
int func_001186D0(int handle);
void func_001BA9C0();
void __fastcall func_001BAAA0(float *position);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BAA50();

// Entry 3 of the member-function table at 0x21b2dc: func_000C70A0 at the centre of the mesh's second part (kind 1),
// state 4 and 0 at 0x70, releases the handle (func_001186D0), then func_000C1160(0x30, 9) at that centre.
void Object_000F44E0::func_000F40E0()
{
    func_000C70A0(0, &mesh->parts[1].center, 1);
    state = 4;
    count = 0;
    func_001186D0(handle);
    data_00257CE4->func_000C1160(0x30, 9, &mesh->parts[1].center);
}
