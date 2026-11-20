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

struct Object_000A1C50 {
    char unknown_000[0x1bc];
    float radius;
    Item_00016260 shape;
    char unknown_204[0xaa0];
    Vector3 position;

    void func_000871C0();
    void func_000873F0();
};

// Puts a box of the player's radius around its position into the shape at +0x1c0 and queues it (kind 0x73f7) on
// the fourth list of 0x22FCE8.
void Object_000A1C50::func_000873F0()
{
    data_0022FCE8.func_00017D90(&shape.box, &position, 1, radius);
    shape.unknown_00 = 0x73f7;
    data_0022FCE8.func_00016260(&shape, -1);
}
