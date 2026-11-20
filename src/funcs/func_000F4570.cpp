struct Vector3 {
    float x;
    float y;
    float z;
};

// A place on a path (func_000C1820): the path, the point reached, the segment, the distance along it, the
// direction of travel.
struct Path_000C1820 {
    void *path;
    Vector3 point;
    int segment;
    float distance;
    int reverse;
    int unknown_1c;
};

// A hit of the list func_00018920 fills in: a place on a path, its distance last.
struct Hit_000F4390 : Path_000C1820 {
};

struct Hits_000F4390 {
    Hit_000F4390 *items;
    unsigned int count;
    char unknown_08[8];
};

struct Object_00016200 {
    int func_00018920(void *shape, const Vector3 *from, const Vector3 *to, float radius, Hits_000F4390 *hits,
                      int first, int second, int mask, int last);
};

extern Object_00016200 data_0022FCE8;

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

// The child of Node whose table is at 0x1CF098 (destructor func_000F3F70): its slot 1 (func_000F4480) runs entry
// `state` of the member-function table at 0x21b2dc on itself.
struct Object_000F44E0 : Node {
    char unknown_040[4];
    int state;
    Vector3 start;
    Vector3 position;
    int angle;
    Vector3 velocity;
    char unknown_070[4];
    Path_000C1820 path;
    char unknown_094[0x2c];
    char shape[0xc];
    unsigned int value_cc;

    Hit_000F4390 *func_000F4390(Hits_000F4390 *hits);
    int func_000F4570();
};

// While the count at 0xcc is set: the nearest hit (func_000F4390) of the shape at 0xc0 between the start at 0x48
// raised by 10 and the position at 0x54 lowered by 10 (func_00018920 of data_00257CE8, radius 0.8, mask 0x3f)
// becomes the place on the path at 0x74 and both points, and the result is 1; otherwise the start becomes the
// position and the result is 0.
int Object_000F44E0::func_000F4570()
{
    if (value_cc > 0) {
        Hits_000F4390 hits;
        Vector3 points[2];
        points[0] = start;
        points[0].y += 10.0f;
        points[1] = position;
        points[1].y -= 10.0f;
        if (data_0022FCE8.func_00018920(shape, &points[0], &points[1], 0.8f, &hits, 0, 0, 0x3f, -1) &&
            hits.count > 0) {
            Hit_000F4390 *hit = func_000F4390(&hits);
            path = *hit;
            start = hit->point;
            position = hit->point;
            return 1;
        }
    }
    start = position;
    return 0;
}
