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

struct Item_00065730 {
    Triangle_0014BE70 first;
    Triangle_0014BE70 second;
    Item_00065730 **link;
    Item_00065730 *next;
    int unknown_68[2];
};

struct Object_00065730 {
    char unknown_00[8];
    Item_00065730 **tail;

    Item_00065730 *func_000656D0(const Quad_0001DE00 *quad);
};

// Appends a new item to the list whose tail link is at +0x8 with the quad's two triangles (func_0014BE70), and
// returns it.
Item_00065730 *Object_00065730::func_000656D0(const Quad_0001DE00 *quad)
{
    Item_00065730 *item = new Item_00065730;
    func_0014BE70(&item->first, &quad->corners[0], &quad->corners[3], &quad->corners[2]);
    func_0014BE70(&item->second, &quad->corners[0], &quad->corners[2], &quad->corners[1]);
    item->next = 0;
    *tail = item;
    item->link = tail;
    tail = &item->next;
    return item;
}
