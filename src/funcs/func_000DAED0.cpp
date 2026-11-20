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
    int func_000609A0(int handle);
};

void __fastcall func_0014C730(Vector3 *target, Vector3 *direction, float scale);

// One of the sixty trail points at 0x50 (28 bytes).
struct Point_000DAE30 {
    Vector3 position;
    Vector3 direction;
    int handle;
};

// The class whose table is at 0x1CE6F8 (destructor func_000DAD60).
struct Object_000DB0F0 {
    char unknown_000[0x48];
    unsigned int flags;
    char unknown_04c[4];
    Point_000DAE30 points[60];
    unsigned int current;
    unsigned int oldest;

    void func_000DAED0();
};

// Walks the trail points from the oldest (0x6e4) to the current one (0x6e0): a point whose effect object 0xe8 still
// runs (func_000609A0 gives 0) moves twice its direction (func_0014C730); the others are dropped by moving the oldest
// past them. Sets the flag 1 at 0x48 once the current point's effect has ended too.
void Object_000DB0F0::func_000DAED0()
{
    for (unsigned int i = oldest; i != current;) {
        Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (object && !object->func_000609A0(points[i].handle)) {
            func_0014C730(&points[i].position, &points[i].direction, 2.0f);
            if (++i >= 60) {
                i = 0;
            }
        } else {
            if (++i >= 60) {
                i = 0;
            }
            oldest = i;
        }
    }
    Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (!object || object->func_000609A0(points[current].handle)) {
        flags |= 1;
    }
}
