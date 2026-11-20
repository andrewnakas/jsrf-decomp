/* sym: ?func_00011C90@Object_00014280@@UAEXXZ = 0x00014870 */
struct Vector3 {
    float x;
    float y;
    float z;
};

// One trail: a ring of points from `start` to `end`, `last` the newest one added.
struct Trail_00014370 {
    int frame;
    unsigned int start;
    unsigned int end;
    unsigned int last;
    Vector3 *points;
};

struct Node {
    virtual ~Node();
    virtual void func_00011C90();

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

// The trail drawer (table 0x1C4500, constructor 0x141E0, destructor 0x14280): up to eight live trails at +0x70 (count
// at +0xb0) and eight fading ones at +0x90 (count at +0xb4), each a ring of +0x54 points.
struct Object_00014280 : Node {
    virtual void func_00011C90();
    void func_00014610(int index);
    void func_000147A0(int index);

    char unknown_44[0x10];
    unsigned int length;
    char unknown_58[0x18];
    Trail_00014370 *trails[8];
    Trail_00014370 *others[8];
    unsigned int trailCount;
    unsigned int otherCount;
};

// Slot 1: moves every live trail one point on (repeating the newest point, dropping the oldest when the ring is full)
// and hands a trail that got no new point this frame to func_000147A0; every fading trail drops its oldest point and
// is freed (func_00014610) when it has none left.
void Object_00014280::func_00011C90()
{
    for (unsigned int i = 0; i < trailCount; i++) {
        Trail_00014370 *trail = trails[i];
        unsigned int previous = trail->end;
        if (++trail->end >= length) {
            trail->end = 0;
        }
        if (trail->end == trail->start) {
            if (++trail->start >= length) {
                trail->start = 0;
            }
        }
        trail->points[trail->end] = trail->points[previous];
        if (trail->last != trail->end && trail->last != previous) {
            func_000147A0(i);
        }
    }
    for (unsigned int j = 0; j < otherCount;) {
        Trail_00014370 *trail = others[j];
        if (++trail->start >= length) {
            trail->start = 0;
        }
        if (trail->start == trail->end) {
            func_00014610(j);
        } else {
            j++;
        }
    }
}
