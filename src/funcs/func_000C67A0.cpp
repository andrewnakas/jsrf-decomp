struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *matrix);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

struct Item_00016260 {
    char unknown_00[8];
};

struct Box_00017CC0 {
    char unknown_00[0x3c];
};

struct Object_00016200 {
    void func_00016260(Item_00016260 *item, int argument);
    void func_00017D90(Box_00017CC0 *box, const Vector3 *center, unsigned int kind, float radius);
};

extern Object_00016200 data_0022FCE8;

// The class whose table is at 0x1CE030 (constructor func_000C6690).
struct Object_000C6690 {
    char unknown_00[0x54];
    Vector3 position;
    char unknown_60[0x1c];
    Item_00016260 item;
    Box_00017CC0 box;
    Vector3 center;
    float radius;

    void func_000C67A0();
};

// Under the transform at 0x54 (func_001BA9C0 .. func_001BAA50): the centre at 0xc0 is the point radius (0xcc) up
// (func_001BAB20); the box at 0x84 is a sphere of that radius there (func_00017D90, kind 1), and the item at 0x7c
// goes into data_0022FCE8's list (func_00016260).
void Object_000C6690::func_000C67A0()
{
    Vector3 up;
    func_001BA9C0();
    func_001BAAA0(&position.x);
    up.x = 0.0f;
    up.y = radius;
    up.z = 0.0f;
    func_001BAB20(&center, &up);
    data_0022FCE8.func_00017D90(&box, &center, 1, radius);
    data_0022FCE8.func_00016260(&item, -1);
    func_001BAA50();
}
