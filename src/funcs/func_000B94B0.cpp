struct Node {
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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;
};

struct Vector3 {
    float x;
    float y;
    float z;
};

// Where func_000BAC60 places the object: position, angles, scale and a model code (bank << 10 | index).
struct Params_000BAC60 {
    Vector3 position;
    int angles[3];
    Vector3 scale;
    unsigned int model;
};

// An entry of table 5 (0xf0 bytes, copied to 0x228): ids in tables 2, 3 and 7 (-1 = none) and the 16 children.
struct Entry_000B8230 {
    unsigned int flags;
    int model;
    int shadow;
    int first;
    int second;
    int extra;
    float lift;
    float friction;
    char unknown_20[0x80];
    int children[16];
    Vector3 position;
    int sound;
};

struct Sphere_00017EC0 {
    Vector3 center;
    float radius;
};

// The one part of the sphere mesh at 0x1a8 (0x24 bytes).
struct Part_00017F60 {
    Sphere_00017EC0 sphere;
    Vector3 offset;
    char unknown_1c[8];
};

// The one part of the box mesh at 0x1e8 (0x74 bytes): the eight corners, then an offset.
struct Part_000181F0 {
    Vector3 corners[8];
    Vector3 offset;
    char unknown_6c[8];
};

struct Mesh_00017F60 {
    Part_00017F60 *parts;
    unsigned int count;
    Sphere_00017EC0 bounds;
};

struct Mesh_000181F0 {
    Part_000181F0 *parts;
    unsigned int count;
    Sphere_00017EC0 bounds;
};

// What data_0022FCE8 found touching an item: free while the first word is 0; a motion at 8 and a direction at 0x2c.
struct Touch_000B94B0 {
    int busy;
    char unknown_04[4];
    Vector3 motion;
    char unknown_14[0x18];
    Vector3 direction;
    Touch_000B94B0 *next;
};

// What func_000162A0 and func_00016320 take (0x24 bytes): flags, kind, the mesh it stands for and what touches it.
struct Item_000162A0 {
    unsigned int flags;
    int kind;
    void *mesh;
    Touch_000B94B0 *touches;
    char unknown_10[0x14];
};

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
float __fastcall func_0014C6B0(const Vector3 *vector);
float func_0014C7F0(float value);
float __fastcall func_0014C800(const Vector3 *a, const Vector3 *b);
int func_000BA800(int bank, int kind, int sound, void *position, int handle);

// The child of Node whose table is at 0x1CD998 (destructor func_000B8610).
struct Object_000B9960 : Node {
    char unknown_040[4];
    int value_44;
    int state;
    int value_4c;
    int value_50;
    int value_54;
    int value_58;
    float value_5c;
    int set;
    int sound;
    void *model;
    void *shadow;
    void *current;
    char unknown_074[0xdc];
    Shape_000EC910 shape;
    Hits_000B9D20 hits;
    Item_000162A0 item;
    Mesh_00017F60 mesh;
    Vector3 *points;
    Item_000162A0 item2;
    Mesh_000181F0 mesh2;
    Params_000BAC60 record;
    Entry_000B8230 entry;
    unsigned int flags_318;
    Vector3 direction;
    int value_328;
    int spin[3];
    int angles[3];
    Vector3 scale;
    Vector3 value_350;
    Vector3 value_35c;
    Vector3 value_368;

    void func_000B94B0();
};

// Slot 2's routine for objects without the top bit of 0x228. State 1 (with 0x4c and 0x54 set) waits for a free
// touch on its item: the offset becomes its direction scaled by 0.7 of its motion's length (x and z by -2, y by
// 1.5 through func_0014C7F0; each at most 2), the top bit of 0x318 is set, the shadow model shown unless bit 30,
// the entry's sound played at the position, state 3. State 3 (unless flag 0x400000, which clears 0x4c and 0x50)
// collides the sphere with the world: on the nearest face an offset going into it is reflected (1.5, y less the
// entry's lift) and the position pushed out; any hit applies the entry's friction to x and z and sets bit 29.
// Then the saved position follows.
void Object_000B9960::func_000B94B0()
{
    switch (state) {
    case 3:
        if (entry.flags & 0x400000) {
            value_50 = 0;
            value_4c = 0;
            return;
        }
        if (shape.first > 0 || shape.second > 0) {
            if (data_0022FCE8.func_0001B5C0(&shape, (Sphere_000EC910 *)&value_350,
                                            *(int *)&mesh.parts->sphere.radius, (int *)&hits, 0xffff, -1)) {
                Contact_000B9D20 *nearest;
                if (!func_000B9D20(&hits, &nearest)) {
                    Contact_000B9D20 *contact = nearest;
                    Face_000B94B0 face;
                    func_0014BD80(&face.plane, &contact->corners[0], &contact->corners[1], &contact->corners[2]);
                    if (func_0014C800(&face.plane.normal, &value_368) < 0.0f) {
                        Vector3 point;
                        Vector3 foot;
                        point.x = contact->point.x + value_368.x;
                        point.y = contact->point.y + value_368.y;
                        point.z = contact->point.z + value_368.z;
                        func_0014BD00(&foot, &point, &face.plane);
                        value_368.x = (foot.x - point.x) * 1.5f + point.x - contact->point.x;
                        value_368.y = (1.5f - entry.lift) * (foot.y - point.y) + point.y - contact->point.y;
                        value_368.z = (foot.z - point.z) * 1.5f + point.z - contact->point.z;
                    }
                    direction.x += contact->push.x;
                    direction.y += contact->push.y;
                    direction.z += contact->push.z;
                }
                value_368.x -= value_368.x * entry.friction;
                flags_318 |= 0x20000000;
                value_368.z -= value_368.z * entry.friction;
            }
        }
        value_35c = value_350;
        break;
    case 1:
        if (value_4c && value_54) {
            Touch_000B94B0 *touch;
            if (entry.extra == -1) {
                touch = item.touches;
            } else {
                touch = item2.touches;
            }
            for (; touch; touch = touch->next) {
                if (!touch->busy) {
                    float speed = func_0014C6B0(&touch->motion) * 0.7f;
                    value_368.x = speed * touch->direction.x * -2.0f;
                    if (value_368.x >= 2.0f) {
                        value_368.x = 2.0f;
                    }
                    value_368.y = func_0014C7F0(speed * touch->direction.y * 1.5f);
                    if (value_368.y >= 2.0f) {
                        value_368.y = 2.0f;
                    }
                    value_368.z = speed * touch->direction.z * -2.0f;
                    if (value_368.z >= 2.0f) {
                        value_368.z = 2.0f;
                    }
                    flags_318 |= 0x80000000;
                    if (!(flags_318 & 0x40000000)) {
                        current = shadow;
                    }
                    if (entry.sound != -1) {
                        sound = func_000BA800(set, 0, entry.sound, &direction, sound);
                    }
                    state = 3;
                    return;
                }
            }
        }
        break;
    }
}
