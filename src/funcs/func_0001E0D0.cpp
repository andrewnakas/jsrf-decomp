struct Vector3 {
    float x;
    float y;
    float z;
};

struct Segment_0014B910 {
    char unknown_00[0x38];
    int unknown_38;
};

void func_0014B910(Segment_0014B910 *segment, const Vector3 *start, const Vector3 *end);

struct Item_0001DEF0 {
    char unknown_00[0x30];
    Item_0001DEF0 **link;
    Item_0001DEF0 *next;
    int unknown_38;
    char unknown_3c[0x24];
};

struct Object_0001DEF0 {
    char unknown_00[0x10];
    Item_0001DEF0 **tail;

    Item_0001DEF0 *func_0001E0D0();
};

// Appends a new 0x60-byte item to the list whose tail link is at +0x10, its segment set up at the origin
// (func_0014B910), and returns it.
Item_0001DEF0 *Object_0001DEF0::func_0001E0D0()
{
    Item_0001DEF0 *item = new Item_0001DEF0;
    Vector3 origin;
    origin.x = 0.0f;
    origin.y = 0.0f;
    origin.z = 0.0f;
    func_0014B910((Segment_0014B910 *)item, &origin, &origin);
    item->unknown_38 = 0;
    item->next = 0;
    *tail = item;
    item->link = tail;
    tail = &item->next;
    return item;
}
