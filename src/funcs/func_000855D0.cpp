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

struct Object_00086060 {
    char unknown_000[0x48];
    Vector3 start;
    Vector3 end;
    char unknown_060[0xa8];
    Item_00016260 shape;

    void func_000855D0();
};

// Puts a box 3.5 wider than its two ends into the shape at +0x108 and queues it on the fourth list of 0x22FCE8.
void Object_00086060::func_000855D0()
{
    Vector3 points[2];
    points[0] = start;
    points[1] = end;
    data_0022FCE8.func_00017D90(&shape.box, points, 2, 3.5f);
    data_0022FCE8.func_00016260(&shape, -1);
}
