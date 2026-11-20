struct Vector3 {
    float x;
    float y;
    float z;
};

struct Box_00017CC0 {
    Vector3 min;
    Vector3 max;
};

struct Mesh_00017F60;

// The item at 0x544 (8 bytes here).
struct Item_00016260 {
    char unknown_00[8];
};

// The item at 0x588 (8 bytes here).
struct Item_000162A0 {
    char unknown_00[8];
};

struct Object_00016200 {
    void func_00016260(Item_00016260 *item, int value);
    void func_000162A0(Item_000162A0 *item);
    void func_00017CC0(Box_00017CC0 *box, const Vector3 *points, unsigned int count);
    void func_00019570(Mesh_00017F60 *mesh, const Mesh_00017F60 *source);
};

extern Object_00016200 data_0022FCE8;
extern Mesh_00017F60 data_00218E28;

// The child of Node whose table is at 0x1CEDA0; called by its slot func_000E7470.
struct Object_000E6E80 {
    char unknown_000[0x5c];
    Vector3 start;
    Vector3 previous;
    char unknown_074[0x4b8];
    int value_52c;
    char unknown_530[0x14];
    Item_00016260 item_544;
    Box_00017CC0 box;
    char unknown_564[0x24];
    Item_000162A0 item_588;
    Mesh_00017F60 *mesh;

    void func_000E6DF0();
};

// Fits the box at 0x54c around the two points at 0x5c and 0x68 (func_00017CC0), then hands the item at 0x544 with
// the value at 0x52c, the mesh at 0x590 with data_00218E28 and the item at 0x588 to data_0022FCE8.
void Object_000E6E80::func_000E6DF0()
{
    Vector3 points[2];
    points[0] = start;
    points[1] = previous;
    data_0022FCE8.func_00017CC0(&box, points, 2);
    data_0022FCE8.func_00016260(&item_544, value_52c);
    data_0022FCE8.func_00019570(mesh, &data_00218E28);
    data_0022FCE8.func_000162A0(&item_588);
}
