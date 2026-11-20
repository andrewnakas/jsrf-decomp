struct Vector3 {
    float x;
    float y;
    float z;
};

struct Box_00017CC0 {
    Vector3 min;
    Vector3 max;
};

struct Item_00016260 {
    int unknown_00;
    int value;
    Box_00017CC0 box;
    int unknown_20[8];
    Item_00016260 *next;
};

struct Object_00016200 {
    void func_00016260(Item_00016260 *item, int value);
    void func_00017D90(Box_00017CC0 *box, const Vector3 *points, unsigned int count, float radius);
};

extern Object_00016200 data_0022FCE8;

// The child of Node whose table is at 0x1CEED8.
struct Object_000EB440 {
    char unknown_00[0x50];
    Vector3 position;
    char unknown_5c[0x2c];
    Item_00016260 shape;
    Vector3 point;
    float radius;

    void func_000EB3C0();
};

void func_001BA9C0();
void func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

// Takes the point `radius` (+0xd8) above the position at +0x50 into +0xcc, puts a box of that radius around it
// into the shape at +0x88 and queues it on the fourth list of 0x22FCE8.
void Object_000EB440::func_000EB3C0()
{
    func_001BA9C0();
    func_001BAAA0(&position.x);
    Vector3 offset;
    offset.x = 0.0f;
    offset.y = radius;
    offset.z = 0.0f;
    func_001BAB20(&point, &offset);
    data_0022FCE8.func_00017D90(&shape.box, &point, 1, radius);
    data_0022FCE8.func_00016260(&shape, -1);
    func_001BAA50();
}
