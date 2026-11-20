struct Vector3 {
    float x;
    float y;
    float z;
};

void __fastcall func_0014C340(Vector3 *out, const Vector3 *in);

struct Box_00017CC0 {
    Vector3 min;
    Vector3 max;
};

// The part of the collision item func_0001B5C0 tests: two counts, at +0x4 and +0x14.
struct Shape_000EC910 {
    int unknown_00;
    unsigned int first;
    char unknown_08[0xc];
    unsigned int second;
    char unknown_18[0xc];
};

struct Item_00016260 {
    int kind;
    int value;
    Box_00017CC0 box;
    Shape_000EC910 shape;
};

struct Sphere_000EC910;

// A contact func_0001B5C0 finds (0x58 bytes): its distance at 0x38 and point at 0x3c.
struct Contact_000EB440 {
    char unknown_00[0x38];
    float distance;
    Vector3 point;
    char unknown_48[0x10];
};

struct Hits_000EB440 {
    Contact_000EB440 *contacts;
    unsigned int count;
    char unknown_08[8];
};

struct Object_00016200 {
    int func_0001B5C0(Shape_000EC910 *shape, Sphere_000EC910 *sphere, int radius, int *hit, int mask, int limit);
};

extern Object_00016200 data_0022FCE8;

struct Object_000C1270 {
    int func_000C1160(int kind, int count, Vector3 *position);
};

extern Object_000C1270 *data_00257CE4;

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
    char unknown_34[0x10];
};

// The child of Node whose table is at 0x1CEED8.
struct Object_000EB440 : Node {
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    void func_000EB440();

    Vector3 start;
    Vector3 position;
    char unknown_05c[0x1c];
    int state;
    char unknown_07c[0xc];
    Item_00016260 shape;
    Vector3 point;
    float radius;
};

// While the shape at 0x88 holds anything, tests the sphere of the radius at 0xd8 around the point at 0xcc against
// it (func_0001B5C0); on a hit moves the position at 0x50 onto the nearest contact within 1000 (state 1 at 0x78)
// and calls func_000C1160(0x2c, 5) of data_00257CE4 there. Then the start at 0x44 follows the position.
void Object_000EB440::func_000EB440()
{
    if (shape.shape.first > 0 || shape.shape.second > 0) {
        Hits_000EB440 hits;
        if (data_0022FCE8.func_0001B5C0(&shape.shape, (Sphere_000EC910 *)&point, *(int *)&radius, (int *)&hits,
                                        0xffff, -1)) {
            float best = 1000.0f;
            Contact_000EB440 *nearest = 0;
            int which = 0;
            for (unsigned int i = 0; i < hits.count; i++) {
                if (hits.contacts[i].distance < best) {
                    nearest = &hits.contacts[i];
                    best = hits.contacts[i].distance;
                    which = 1;
                }
            }
            if (which == 1) {
                func_0014C340(&position, &nearest->point);
                state = 1;
            } else if (which == 2) {
                func_0014C340(&position, (Vector3 *)((char *)nearest + 0x60));
                state = 1;
            }
            data_00257CE4->func_000C1160(0x2c, 5, &position);
        }
    }
    start = position;
}
