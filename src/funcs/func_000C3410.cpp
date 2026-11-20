struct Data_000C2700;

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

struct Object_000C1440 {
    int func_000C1450(int current, int target, int step);
};

// The object at data_00257CE8 (func_00157F10 is the engine's); it also answers func_000C1450.
struct Object_00157F10 : Object_000C1440 {
    void func_000C1F20(Angles_000C1300 *angles, Vector3 *direction, int step);
};

extern Object_00157F10 *data_00257CE8;

struct Object_000C1670 {
    int func_000C1670(int flags);
};

// What func_00018260 casts a ray through: two counts, at +0x4 and +0x14.
struct Model_00018260 {
    void *unknown_00;
    unsigned int count;
    char unknown_08[0xc];
    unsigned int unknown_14;
    char unknown_18[0xc];
};

// What func_000194B0 of data_0022FCE8 hands func_000C3410: a face's flags at 0x24 and point at 0x2c, an edge's
// flags at 0x48 and point at 0x50.
struct Hit_000C2840 {
    char unknown_00[0x24];
    int flags;
    char unknown_28[4];
    Vector3 point;
    char unknown_38[0x10];
    int edgeFlags;
    char unknown_4c[4];
    Vector3 edgePoint;
};

struct Hits_000C4C60;
struct Contact_000C4A90;

struct Hit_00018260 {
    Hit_000C2840 *faces;
    unsigned int faceCount;
    Hit_000C2840 *edges;
    unsigned int edgeCount;
};

struct Object_00016200 {
    int func_00018260(Model_00018260 *model, Vector3 *from, Vector3 *to, Hit_00018260 *hit, int mask, int flags);
    int func_000194B0(Hits_000C4C60 *hits, Contact_000C4A90 **nearest);
};

extern Object_00016200 data_0022FCE8;

// The base whose table is at 0x1CDCF8 (constructor func_000C2420, destructor func_000C2470); slot 9 is the
// destructor.
struct Object_000C2420 {
    Object_000C2420(Data_000C2700 *data);
    virtual void func_000C2630();

    Vector3 last;
    Vector3 position;
    Angles_000C1300 angles;
    float speed;
    float lift;
    unsigned int flags;
    char unknown_34[0x70];
    Model_00018260 ray;

    void func_000C2840(Hit_000C2840 *hit);
    void func_000C2900(Hit_000C2840 *hit);
    void func_000C3410();
};

// The fall, while moving (0x28 or the lift at 0x2c) with bit 0 of 0x30: a ray from 3 above where it was to 1 below
// the position (func_00018260 of data_0022FCE8, mask 0xffff). A face or edge that is not a wall (func_000C1670)
// takes the position (and the height), turns the angles along the way moved (func_000C1F20, 0x38e) and sets the
// lift to the climb; a wall bounces off it (func_000C2840 / func_000C2900) unless the first hit is no wall.
// Without ground the lift falls by 1/36 down to -10/36. The angles' x is cleared and the position kept as the last.
void Object_000C2420::func_000C3410()
{
    if ((speed == 0.0f && lift == 0.0f) || !(flags & 1)) {
        return;
    }
    int hit = 0;
    Vector3 from;
    Vector3 to;
    if (ray.count > 0 || ray.unknown_14 > 0) {
        from = last;
        from.y += 3.0f;
        to = position;
        to.y -= 1.0f;
        Hit_00018260 hits;
        if (data_0022FCE8.func_00018260(&ray, &from, &to, &hits, 0xffff, -1)) {
            Hit_000C2840 *nearest;
            int onEdge = data_0022FCE8.func_000194B0((Hits_000C4C60 *)&hits, (Contact_000C4A90 **)&nearest);
            if (!onEdge) {
                Hit_000C2840 *contact = nearest;
                if (((Object_000C1670 *)data_00257CE8)->func_000C1670(contact->flags)) {
                    func_000C2840(contact);
                    Hit_000C2840 *face = hits.faces;
                    for (unsigned int i = 0; i < hits.faceCount; i++) {
                        if (!((Object_000C1670 *)data_00257CE8)->func_000C1670(face->flags)) {
                            position.y = face->point.y;
                            hit = 1;
                            break;
                        }
                    }
                } else {
                    position.x = contact->point.x;
                    position.y = contact->point.y;
                    position.z = contact->point.z;
                    hit = 1;
                }
            } else {
                Hit_000C2840 *contact = nearest;
                if (((Object_000C1670 *)data_00257CE8)->func_000C1670(contact->edgeFlags)) {
                    func_000C2900(contact);
                    Hit_000C2840 *edge = hits.edges;
                    for (unsigned int i = 0; i < hits.edgeCount; i++) {
                        if (!((Object_000C1670 *)data_00257CE8)->func_000C1670(edge->edgeFlags)) {
                            position.y = edge->edgePoint.y;
                            hit = 1;
                            break;
                        }
                    }
                } else {
                    position.x = contact->edgePoint.x;
                    position.y = contact->edgePoint.y;
                    position.z = contact->edgePoint.z;
                    hit = 1;
                }
            }
        }
    }
    if (hit) {
        Vector3 way;
        way.x = position.x - last.x;
        way.y = 0;
        way.z = position.z - last.z;
        data_00257CE8->func_000C1F20(&angles, &way, 0x38e);
        lift = position.y - last.y;
    } else {
        if (lift > 0.0f) {
            lift = 0;
        }
        lift -= 0.027777778f;
        if (lift < -0.27777779f) {
            lift = -0.27777779f;
        }
    }
    angles.x = 0;
    last = position;
}
