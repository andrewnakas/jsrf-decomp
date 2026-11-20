struct Vector3 {
    float x;
    float y;
    float z;
};

// What func_0014BE70 builds from three corners (0x30 bytes).
struct Triangle_0014BE70 {
    int unknown_00[0xc];
};

void func_0014BE70(Triangle_0014BE70 *triangle, const Vector3 *first, const Vector3 *second, const Vector3 *third);

// A quad: four corners.
struct Quad_0001DE00 {
    Vector3 corners[4];
    Vector3 unknown_30;
    Vector3 unknown_3c;
    char unknown_48[8];
    Vector3 unknown_50;
};

struct Item_0006F7B0 {
    Triangle_0014BE70 first;
    Triangle_0014BE70 second;
    Vector3 position;
    Item_0006F7B0 **link;
    Item_0006F7B0 *next;
};

struct Object_0001DEF0 {
    char unknown_00[8];
    Item_0006F7B0 **tail;

    Item_0006F7B0 *func_0006F7B0(const Quad_0001DE00 *quad, const Vector3 *position);
};

// Appends a new item to the list whose tail link is at +0x8: the quad's two triangles (func_0014BE70) and a
// position. Returns it.
Item_0006F7B0 *Object_0001DEF0::func_0006F7B0(const Quad_0001DE00 *quad, const Vector3 *position)
{
    Item_0006F7B0 *item = new Item_0006F7B0;
    func_0014BE70(&item->first, &quad->corners[0], &quad->corners[3], &quad->corners[2]);
    func_0014BE70(&item->second, &quad->corners[0], &quad->corners[2], &quad->corners[1]);
    item->position.x = position->x;
    item->position.y = position->y;
    item->position.z = position->z;
    item->next = 0;
    *tail = item;
    item->link = tail;
    tail = &item->next;
    return item;
}
