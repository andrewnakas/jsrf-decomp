/* sym: ?func_00011C90_1@Object_000B7440@@UAEXXZ = 0x000B7FE0 */
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

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};
extern Game *data_0022FCE0;

struct Shape_000EC910 {
    int unknown_00;
    unsigned int first;
    char unknown_08[0xc];
    unsigned int second;
    char unknown_18[0xc];
};

struct Sphere_000EC910;

// A face func_0001B5C0 found: its corners, the point on it and how far to push out of it.
struct Contact_000B9D20 {
    Vector3 corners[3];
    unsigned int flags;
    char unknown_28[4];
    Vector3 point;
    float distance;
    Vector3 push;
    char unknown_48[0x10];
};

struct Other_000B9D20;

struct Hits_000B9D20 {
    Contact_000B9D20 *contacts;
    unsigned int count;
    Other_000B9D20 *others;
    unsigned int otherCount;
};

struct Object_00016200 {
    int func_0001B5C0(Shape_000EC910 *shape, Sphere_000EC910 *sphere, int radius, int *hit, int mask, int limit);
};

extern Object_00016200 data_0022FCE8;

struct Plane_0007F030 {
    Vector3 point;
    float distance;
    Vector3 normal;
};

// The local plane: Plane_0007F030 and a spare word.
struct Face_000B94B0 {
    Plane_0007F030 plane;
    float spare;
};

int func_000B9D20(Hits_000B9D20 *hits, Contact_000B9D20 **nearest);
void func_0014BD80(Plane_0007F030 *plane, const Vector3 *a, const Vector3 *b, const Vector3 *c);
float __fastcall func_0014BD00(Vector3 *out, const Vector3 *point, const Plane_0007F030 *plane);
float __fastcall func_0014C800(const Vector3 *a, const Vector3 *b);

struct Object_0006A960 {
    int func_0006AAA0(Vector3 *position, int index);
    float func_0006AC40(Vector3 *position, int index);
};
extern Object_0006A960 data_0020C6C0;

// The object the id at 0x200 names.
struct Owner_000B7FE0 {
    char unknown_000[0x318];
    unsigned int flags;
};

struct Buffer_000B7170 {
    char unknown_00[0xc];
    int value;
};

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD950).
struct Object_000B7440 : Node {
    virtual ~Object_000B7440();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    int unknown_040;
    unsigned int unknown_044;
    int unknown_048;
    int state;
    char unknown_050[0x28];
    unsigned int flags_78;
    char unknown_07c[0xc];
    float lift;
    float friction;
    char unknown_090[0x2c];
    unsigned int count;
    char unknown_0c0[4];
    int index;
    float height;
    char unknown_0cc[0x20];
    Vector3 position;
    char unknown_0f8[0x1c];
    Vector3 point;
    Vector3 last;
    Vector3 velocity;
    char unknown_138[0x7c];
    Shape_000EC910 shape;
    Hits_000B9D20 hits;
    Buffer_000B7170 *buffer;
    char unknown_1ec[0x14];
    int owner;

    void func_000B76A0();
};

// Slot 2. State 3 (unless flag 0x20000000 of 0x78): while the shape at 0x1b4 has contacts, moves out of the nearest
// face (func_000B9D20): a velocity heading into the face is reflected off its plane (twice the way to the foot, y
// scaled by 2 - 0x88), the face's push added to the position, x and z damped by 0x8c; then keeps the point at 0x114
// at 0x120. State 1: once the owner (id at 0x200) sets bit 31 of 0x318, sets bit 31 of 0x44 and goes to state 3 (no
// count at 0xbc) or 2, func_000B76A0, and refreshes the ground index and height (func_0006AAA0/func_0006AC40).
void Object_000B7440::func_00011C90_1()
{
    Owner_000B7FE0 *other = (Owner_000B7FE0 *)data_0022FCE0->func_000128C0(owner);
    switch (state) {
    case 3:
        if (flags_78 & 0x20000000) {
            return;
        }
        if (shape.first > 0 || shape.second > 0) {
            if (data_0022FCE8.func_0001B5C0(&shape, (Sphere_000EC910 *)&point, buffer->value, (int *)&hits, 0xffff,
                                            -1)) {
                Contact_000B9D20 *nearest;
                if (!func_000B9D20(&hits, &nearest)) {
                    Contact_000B9D20 *contact = nearest;
                    Face_000B94B0 face;
                    func_0014BD80(&face.plane, &contact->corners[0], &contact->corners[1], &contact->corners[2]);
                    if (func_0014C800(&face.plane.normal, &velocity) < 0.0f) {
                        Vector3 point;
                        Vector3 foot;
                        point.x = contact->point.x + velocity.x;
                        point.y = contact->point.y + velocity.y;
                        point.z = velocity.z + contact->point.z;
                        func_0014BD00(&foot, &point, &face.plane);
                        velocity.x = (foot.x - point.x) * 2.0f + point.x - contact->point.x;
                        velocity.y = (2.0f - lift) * (foot.y - point.y) + point.y - contact->point.y;
                        velocity.z = (foot.z - point.z) * 2.0f + point.z - contact->point.z;
                    }
                    position.x += contact->push.x;
                    position.y += contact->push.y;
                    position.z += contact->push.z;
                }
                velocity.x -= friction * velocity.x;
                velocity.z -= velocity.z * friction;
            }
        }
        last = point;
        break;
    case 1:
        if (other->flags & 0x80000000) {
            unknown_044 |= 0x80000000;
            if (count <= 0) {
                state = 3;
                func_000B76A0();
            } else {
                state = 2;
                func_000B76A0();
            }
            index = data_0020C6C0.func_0006AAA0(&position, index);
            height = data_0020C6C0.func_0006AC40(&position, index);
        }
        break;
    }
}
