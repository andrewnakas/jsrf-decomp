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

// One of the sixty trail points at 0x50 (28 bytes).
struct Point_000DAE30 {
    Vector3 position;
    Vector3 direction;
    int handle;
};

// The class whose table is at 0x1CE6F8 (destructor func_000DAD60).
struct Object_000DB0F0 {
    char unknown_000[0x50];
    Point_000DAE30 points[60];
    unsigned int current;
    char unknown_6e4[4];
    int active;

    void func_000DAE30();
};

// On every other call (the flag at 0x6e8 flips each time): kind 0x46 of object 0xe8 (func_000651E0) at the current
// point's position and direction, keeping its handle, then the point is copied into the next of the sixty slots
// (wrapping to 0), which becomes current. Called by slot 1 (func_000DB330).
void Object_000DB0F0::func_000DAE30()
{
    if (active) {
        Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (object) {
            points[current].handle =
                object->func_000651E0(0x46, &points[current].position, &points[current].direction);
        }
        unsigned int next = current + 1;
        if (next >= 60) {
            next = 0;
        }
        points[next] = points[current];
        current = next;
    }
    active = active == 0;
}
