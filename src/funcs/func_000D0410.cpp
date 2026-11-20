struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The object func_000128C0(0x2c) of data_0022FCE0 gives: drawing is off while 0xe20 is set.
struct Screen_000D0410 {
    char unknown_000[0xe20];
    int paused;
};

// The object in data_00257CE4.
struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 position;
};

extern Object_000C1270 *data_00257CE4;

float __fastcall func_0014C580(const Vector3 *a, const Vector3 *b);

// A mesh copy: the point its part is drawn at (first word) and its own position at 0x8.
struct Mesh_000D0410 {
    Vector3 *origin;
    int unknown_04;
    Vector3 position;
};

// The item a piece draws (0x24 bytes; its mesh at 0x8).
struct Item_000162A0 {
    char unknown_00[8];
    Mesh_000D0410 *mesh;
    char unknown_0c[0x18];
};

struct Object_00016200 {
    void func_000162A0(Item_000162A0 *item);
};

extern Object_00016200 data_0022FCE8;

// The counter at 0x1c3c: the number of points at 0x68, the fade at 0x6c, the head at 0x74.
struct Counter_000D0410 {
    char unknown_00[0x68];
    unsigned int count;
    float fade;
    char unknown_70[4];
    Vector3 head;
};

// One of the eight pieces at 0x48 of Object_000D01A0: a trail of up to 600 points from 0x4.
struct Object_000CFB70 {
    int unknown_0000;
    Vector3 points[600];
    char unknown_1c24[0x18];
    Counter_000D0410 *counter;
    Item_000162A0 items[10];

    void func_000CFFE0();
    void func_000D0140();
    void func_000D0410();
};

// Puts the counter's head at the first point; below 600 points runs func_000D0140 and func_000CFFE0. Unless the
// screen object (func_000128C0(0x2c)) is missing or paused or the fade is at most 0.5, draws up to ten of the points
// that lie within 400 of the point at 0x7c of data_00257CE4, each with the next item from 0x1c40 (its mesh and the
// mesh's origin moved there).
void Object_000CFB70::func_000D0410()
{
    points[0] = counter->head;
    if (counter->count < 600) {
        func_000D0140();
        func_000CFFE0();
    }
    Screen_000D0410 *screen = (Screen_000D0410 *)data_0022FCE0->func_000128C0(0x2c);
    unsigned int drawn = 0;
    if (screen && !screen->paused && counter->fade > 0.5f) {
        for (unsigned int i = 0; i < counter->count; i++) {
            if (func_0014C580(&data_00257CE4->position, &points[i]) < 400.0f) {
                Mesh_000D0410 *mesh = items[drawn].mesh;
                mesh->position = points[i];
                *mesh->origin = points[i];
                data_0022FCE8.func_000162A0(&items[drawn]);
                if (++drawn >= 10) {
                    break;
                }
            }
        }
    }
}
