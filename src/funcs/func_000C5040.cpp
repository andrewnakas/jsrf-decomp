/* sym: ?func_00011C90_1@Object_000C4CF0@@UAEXXZ = 0x000C5040 */
struct Vector3 {
    float x;
    float y;
    float z;
};
// Three angles (x, y, z).
struct Angles_000C1300 {
    int x;
    int y;
    int z;
};
struct Box_00017CC0 {
    Vector3 min;
    Vector3 max;
};

// The part of the collision item func_00018260 tests: two counts, at +0x4 and +0x14.
struct Model_00018260 {
    void *unknown_00;
    unsigned int count;
    char unknown_08[0xc];
    unsigned int otherCount;
    char unknown_18[8];
};

// The collision item of data_0022FCE8 (func_00016260): a mask, a box and a shape.
struct Item_00016260 {
    int mask;
    int value;
    Box_00017CC0 box;
    Model_00018260 shape;
    Item_00016260 *next;
};

struct Hit_00018260;

// A contact of the first list (0x58 bytes): where the moving point stops at 0x2c and the normal at 0x48.
struct Contact_000C4A90 {
    char unknown_00[0x2c];
    Vector3 stop;
    char unknown_38[0x10];
    Vector3 normal;
    char unknown_54[4];
};

// A contact of the second list (0x84 bytes): the same at 0x50 and 0x6c.
struct Contact_000CA1C0 {
    char unknown_00[0x50];
    Vector3 stop;
    char unknown_5c[0x10];
    Vector3 normal;
    char unknown_78[0xc];
};

// What func_00018260 hands func_000194B0: two lists of contacts with their counts.
struct Hits_000C4C60 {
    Contact_000C4A90 *contacts;
    unsigned int count;
    Contact_000C4A90 *others;
    unsigned int otherCount;
};

struct Object_00016200 {
    int func_00018260(Model_00018260 *model, Vector3 *from, Vector3 *to, Hit_00018260 *hit, int mask, int flags);
    int func_000194B0(Hits_000C4C60 *hits, Contact_000C4A90 **nearest);
};

extern Object_00016200 data_0022FCE8;

struct Object_00047470;
struct Mesh_00017FD0;

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

    char unknown_04[0x3c];
};

// The child of Node whose table is at 0x1CDE60 (constructor func_000C4CF0, destructor func_000C4E50): it
// overrides slots 1, 2, 3, 12 and 15 and adds three empty slots, 16 to 18. A shot: it starts at a point (0x44 and
// 0x50) going along a direction (0x5c, angles at 0x74) for a life (0x8c, frames), with a model (0x90), a collision item
// (0x94) and a drawing item (0xd8) on a mesh of its own (0xfc).
struct Object_000C4CF0 : Node {
    virtual ~Object_000C4CF0();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);
    virtual void func_00011C90_10();
    virtual void func_00011C90_11();
    virtual void func_00011C90_12();

    char unknown_040[4];
    Vector3 origin;
    Vector3 position;
    Vector3 direction;
    Vector3 unknown_068;
    Angles_000C1300 angles;
    int roll;
    int value_084;
    int value_088;
    int life;
    Object_00047470 *model;
    Item_00016260 item;
    int drawFlags;
    int drawCount;
    Mesh_00017FD0 *drawMesh;
    int drawValue;
};

// Slot 2: with 0xe4 set, it is done (1 at 0x84); otherwise, when the collision item's shape has contacts to test and
// the way from the start point at 0x44 to the position at 0x50 hits it (func_00018260 of data_0022FCE8, mask
// 0xffff), the position moves to the nearest contact's stop (func_000194B0) with its normal at 0x68, and it is done.
// Then the start point takes the position and slot 17 runs.
void Object_000C4CF0::func_00011C90_1()
{
    if (drawValue) {
        value_084 = 1;
    } else if (item.shape.count > 0 || item.shape.otherCount > 0) {
        Vector3 from = origin;
        Vector3 to = position;
        Hits_000C4C60 hits;
        if (data_0022FCE8.func_00018260(&item.shape, &from, &to, (Hit_00018260 *)&hits, 0xffff, -1)) {
            Contact_000C4A90 *nearest;
            if (!data_0022FCE8.func_000194B0(&hits, &nearest)) {
                position = nearest->stop;
                unknown_068 = nearest->normal;
            } else {
                position = ((Contact_000CA1C0 *)nearest)->stop;
                unknown_068 = ((Contact_000CA1C0 *)nearest)->normal;
            }
            value_084 = 1;
        }
    }
    origin = position;
    func_00011C90_11();
}
