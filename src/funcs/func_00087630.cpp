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
    Item_00016260 shape2;
    char unknown_248[0x990];
    int hasSecond;
    char unknown_bdc[0x14];
    Vector3 secondPosition;
    char unknown_bfc[0xa8];
    Vector3 position;

    void func_00087630();
};

// Puts a box of the player's radius around its position into the shape at +0x1c0 and queues it (kind 0x73f7) on
// the fourth list of 0x22FCE8; the same for its second position (+0xbf0) and shape (+0x204) when +0xbd8 is set.
void Object_000A1C50::func_00087630()
{
    data_0022FCE8.func_00017D90(&shape.box, &position, 1, radius);
    shape.unknown_00 = 0x73f7;
    data_0022FCE8.func_00016260(&shape, -1);
    if (hasSecond) {
        data_0022FCE8.func_00017D90(&shape2.box, &secondPosition, 1, radius);
        shape2.unknown_00 = 0x73f7;
        data_0022FCE8.func_00016260(&shape2, -1);
    }
}
