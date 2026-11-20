struct Vector3 {
    float x;
    float y;
    float z;
};

struct Mesh_00017F60;
struct Model_000178B0;
struct Motion_0005F060;

struct Item_00016200 {
    char unknown_00[4];
};

// The item at the start of each block (8 bytes here).
struct Item_000162A0 {
    char unknown_00[8];
};

struct Object_00016200 {
    void func_00016240(Item_00016200 *item);
    void func_000162A0(Item_000162A0 *item);
    void func_000178B0(Model_000178B0 *model, Motion_0005F060 *motion, float time);
    void func_00019570(Mesh_00017F60 *mesh, const Mesh_00017F60 *source);
};

extern Object_00016200 data_0022FCE8;

struct Object_00047470 {
    void func_000480C0(unsigned int index);
};

void __fastcall func_001BAAA0(float *vector);

extern Vector3 data_002191A8[4];
extern unsigned int data_002191D8[4];
extern Mesh_00017F60 data_00219190;

// The 0x6c-byte part at 0x30 of Object_000EA3B0 and at 0xbc of Object_000ECB50.
struct Part_000EB830 {
    void func_000EB950(Object_00047470 *model);

    char unknown_00[0x6c];
};

// A drawn block (36 bytes) of the four at 0x150.
struct Block_000E9FE0 {
    Item_000162A0 item;
    Mesh_00017F60 *mesh;
    char unknown_0c[0x18];
};

// The object func_000EA3B0 builds (0x1f4 bytes; table 0x1CEE78).
struct Object_000EA3B0 {
    char unknown_000[0x30];
    Part_000EB830 part;
    char unknown_09c[0x78];
    Object_00047470 *model;
    char unknown_118[0x10];
    Motion_0005F060 *motion_128;
    char unknown_12c[0x24];
    Block_000E9FE0 blocks[4];
    Model_000178B0 *model_1e0;
    Item_00016200 item_1e4;

    void func_000E9FE0();
};

// Hands the model at 0x1e0 (posed by the motion at 0x128) and the item at 0x1e4 to data_0022FCE8, runs func_000EB950 of
// the part at 0x30 on the model at 0x114, then for each of the four blocks at 0x150 picks the model's entry
// data_002191D8 names (func_000480C0), places the matrix at the matching point of data_002191A8 and hands the
// block's mesh (with data_00219190) and item to data_0022FCE8. Called by slot 1 (func_000EA6A0).
void Object_000EA3B0::func_000E9FE0()
{
    data_0022FCE8.func_000178B0(model_1e0, motion_128, 0.0f);
    data_0022FCE8.func_00016240(&item_1e4);
    part.func_000EB950(model);
    for (unsigned int i = 0; i < 4; i++) {
        model->func_000480C0(data_002191D8[i]);
        func_001BAAA0(&data_002191A8[i].x);
        data_0022FCE8.func_00019570(blocks[i].mesh, &data_00219190);
        data_0022FCE8.func_000162A0(&blocks[i].item);
    }
}
