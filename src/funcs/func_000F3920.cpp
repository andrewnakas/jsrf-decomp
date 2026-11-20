/* sym: ?func_00011C90@Object_000F37B0@@UAEXXZ = 0x000F3920 */
struct Vector3 {
    float x;
    float y;
    float z;
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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};


struct Sphere_00017EC0 {
    Vector3 center;
    float radius;
};

struct Part_00017F60 {
    Sphere_00017EC0 sphere;
    Vector3 motion;
    char unknown_1c[8];
};

struct Mesh_00017F60 {
    Part_00017F60 *parts;
    unsigned int count;
    Sphere_00017EC0 bounds;
};

struct Item_000162A0 {
    int unknown_00[2];
    Mesh_00017F60 *mesh;
    char unknown_0c[8];
    int unknown_14;
};

struct Object_00016200 {
    void func_000162A0(Item_000162A0 *item);
};

extern Object_00016200 data_0022FCE8;

struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float step, int hold);

// One of the queued meshes from 0x764 (0x24 bytes each).
struct Entry_000F3920 {
    Item_000162A0 item;
    char unknown_18[0xc];
};

// The child of Node whose table is at 0x1CF058 (constructor func_000F37B0).
struct Object_000F37B0 : Node {
    virtual ~Object_000F37B0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    int unknown_040;
    Vector3 points[150];
    unsigned int count;
    unsigned int flags_750;
    float fade;
    char unknown_758[4];
    Motion_0005F060 *motion;
    float time;
    Entry_000F3920 entries[75];
};

// Slot 1: once shown (bit 1 of 0x750) it gets bit 2 and then fades (0x754) by 1/120 until it unlinks itself
// (func_00011BE0, func_00011C20). While the fade is above 0.5 every second point from 0x44 places one queued mesh
// (its first part and bounds; func_000162A0 of data_0022FCE8). Then its motion at 0x75c steps by 0.5 and bit 1 is set.
void Object_000F37B0::func_00011C90()
{
    if (flags_750 & 2) {
        fade -= 1.0f / 120.0f;
        if (fade < 0.0f) {
            fade = 0.0f;
            func_00011BE0(this);
            func_00011C20(child);
        }
    } else if (flags_750 & 1) {
        flags_750 |= 2;
    }
    if (fade > 0.5f) {
        int j = 0;
        for (unsigned int i = 0; i < count; i += 2) {
            entries[j].item.mesh->parts->sphere.center = points[i];
            entries[j].item.mesh->bounds.center = points[i];
            data_0022FCE8.func_000162A0(&entries[j].item);
            j++;
        }
    }
    func_0005E030(motion, &time, 0.5f, 0);
    flags_750 |= 1;
}
