struct Data_000C2700;

struct Vector3 {
    float x;
    float y;
    float z;
};

// Two corners.
struct Box_00017CC0 {
    Vector3 low;
    Vector3 high;
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
};

extern Object_00016200 data_0022FCE8;

float func_0014C850(float a, float b);
float func_0014C870(float a, float b);

// The base whose table is at 0x1CDCF8 (constructor func_000C2420, destructor func_000C2470); slot 9 is the
// destructor.
struct Object_000C2420 {
    Object_000C2420(Data_000C2700 *data);
    virtual void func_000C2630();
    virtual void func_000C2700();
    virtual void func_000C3800();
    virtual void func_000C30C0();
    virtual void func_000C3100();
    virtual void func_000C3140();
    virtual void func_000C31B0();
    virtual void func_000C3350();
    virtual void func_000C33C0();
    virtual ~Object_000C2420();
    virtual void func_000C2480();
    virtual void func_000C36F0();
    virtual void func_000C2FE0();
    virtual void func_000C2500();
    virtual void func_000C2560();
    virtual void func_000C25D0();
    virtual int func_000C2AA0();

    Vector3 position;
    Vector3 last;
    char unknown_1c[0xc];
    float speed;
    float rise;
    unsigned int flags;
    char unknown_34[0x50];
    Item_00016260 item;

    void func_000C2730();
};

// While moving (speed at 0x28 or rise at 0x2c) with flag 1, spans the item's box at 0x8c between the position raised
// by 3 and the last position at 0x10 lowered by 1 (func_0014C870 low, func_0014C850 high, per axis) and queues the
// item at 0x84 on data_0022FCE8 (func_00016260, -1); otherwise clears the item's words at 0xa8 and 0xb8.
void Object_000C2420::func_000C2730()
{
    if ((speed == 0.0f && rise == 0.0f) || !(flags & 1)) {
        item.unknown_20[5] = 0;
        item.unknown_20[1] = 0;
        return;
    }
    Vector3 top = position;
    top.y += 3.0f;
    Vector3 bottom = last;
    bottom.y -= 1.0f;
    item.box.low.x = func_0014C870(top.x, bottom.x);
    item.box.low.y = func_0014C870(top.y, bottom.y);
    item.box.low.z = func_0014C870(top.z, bottom.z);
    item.box.high.x = func_0014C850(top.x, bottom.x);
    item.box.high.y = func_0014C850(top.y, bottom.y);
    item.box.high.z = func_0014C850(top.z, bottom.z);
    data_0022FCE8.func_00016260(&item, -1);
}
