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
    int kind;
    int value;
    Box_00017CC0 box;
};

struct Object_00016200 {
    void func_00016260(Item_00016260 *item, int value);
    void func_00017D90(Box_00017CC0 *box, const Vector3 *points, unsigned int count, float radius);
};

extern Object_00016200 data_0022FCE8;

struct Node {
    Node *func_00011BD0();
};

struct Object_000A4D80 {
    char unknown_000[0x9c];
    Item_00016260 item;
    char unknown_0bc[0x134];
    Vector3 anchor;

    void func_000A59B0();
};

// A handler (entries 3, 4, 5, 9 and 13) of the member-function table at data_00215570: puts the item at 0x9c
// (kind 0x33b7) into data_0022FCE8 with a box of radius 38 around the anchor at 0x1f0.
void Object_000A4D80::func_000A59B0()
{
    ((Node *)this)->func_00011BD0();
    data_0022FCE8.func_00017D90(&item.box, &anchor, 1, 38.0f);
    item.kind = 0x33b7;
    data_0022FCE8.func_00016260(&item, -1);
}
