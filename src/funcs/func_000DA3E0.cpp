struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    int func_000651E0(int kind, void *data, Vector3 *direction);
};

// The object at data_00257CE4.
struct Object_000C1270 {
    void func_000C1270(int handle, void *position);
    int func_000C1160(int kind, int count, Vector3 *position);
};

extern Object_000C1270 *data_00257CE4;

int func_00118710(int handle);

// What func_00018260 tests a segment against: two counted parts (+4 and +0x14).
struct Model_00018260 {
    void *unknown_00;
    unsigned int count;
    char unknown_08[0xc];
    unsigned int unknown_14;
};

// What func_00018260 reports: two lists.
struct Hit_00018260 {
    void *faces;
    unsigned int faceCount;
    void *edges;
    unsigned int edgeCount;
};

// A contact func_000194B0 picks: a face keeps a point and a normal at +0x2c / +0x48, an edge at +0x50 / +0x6c.
struct Contact_000C4A90 {
    union {
        struct {
            char unknown_00[0x2c];
            Vector3 point;
            char unknown_38[0x10];
            Vector3 normal;
        } face;
        struct {
            char unknown_00[0x50];
            Vector3 point;
            char unknown_5c[0x10];
            Vector3 normal;
        } edge;
    };
};

struct Hits_000C4C60;

struct Object_00016200 {
    int func_00018260(Model_00018260 *model, Vector3 *from, Vector3 *to, Hit_00018260 *hit, int mask, int flags);
    int func_000194B0(Hits_000C4C60 *hits, Contact_000C4A90 **nearest);
};

extern Object_00016200 data_0022FCE8;

// One of the sixty slots at 0x64 (16 bytes).
struct Slot_000DA5B0 {
    Vector3 position;
    unsigned int state;
};

// The child of Node whose table is at 0x1CE658 (constructor func_000DA1E0).
struct Object_000DA3E0 {
    char unknown_000[0x44];
    int full;
    char unknown_048[8];
    Vector3 direction;
    unsigned int end;
    unsigned int start;
    Slot_000DA5B0 slots[60];
    char unknown_424[0x20];
    Model_00018260 model;
    char unknown_45c[0x24c];
    Vector3 from;
    Vector3 to;
    int handle;

    void func_000DA3E0();
};

// Sweeps the model at 0x444 from 0x6a8 to 0x6b4 against mask 0xffff (func_00018260). On a hit, the nearest contact's
// point and normal (edge or face, func_000194B0) go to the end slot and to object 0xe8's kind-0x48 event; otherwise
// the end point with an upward normal. The kind-0x2e effect at 0x6c0 follows that point (made again if func_00118710
// says it is gone). The end index then advances round the sixty slots, retiring the start slot (state 2) when it
// catches up.
void Object_000DA3E0::func_000DA3E0()
{
    Vector3 *at;
    Hit_00018260 hit;
    if ((model.count > 0 || model.unknown_14 > 0)
        && data_0022FCE8.func_00018260(&model, &from, &to, &hit, 0xffff, -1)) {
        Contact_000C4A90 *nearest;
        Vector3 point;
        Vector3 normal;
        if (!data_0022FCE8.func_000194B0((Hits_000C4C60 *)&hit, &nearest)) {
            point = nearest->face.point;
            normal = nearest->face.normal;
        } else {
            point = nearest->edge.point;
            normal = nearest->edge.normal;
        }
        slots[end].position = point;
        Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (object) {
            object->func_000651E0(0x48, &point, &normal);
        }
        at = &point;
    } else {
        Vector3 up = {0.0f, 1.0f, 0.0f};
        slots[end].position = to;
        Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (object) {
            object->func_000651E0(0x48, &to, &up);
        }
        at = &to;
    }
    if (func_00118710(handle)) {
        data_00257CE4->func_000C1270(handle, at);
    } else {
        handle = data_00257CE4->func_000C1160(0x2e, 0xe, at);
    }
    if (++end >= 60) {
        end = 0;
    }
    if (end == start) {
        slots[start].state = 2;
        if (++start >= 60) {
            start = 0;
        }
    }
}
