struct Vector3 {
    float x;
    float y;
    float z;
};

struct Sphere_00017EC0 {
    Vector3 center;
    float radius;
};

struct Mesh_00017FD0;

struct Item_000162A0 {
    int unknown_00[0xf];
};

struct Object_00016200 {
    void func_000162E0(Item_000162A0 *item);
    void func_000195F0(Mesh_00017FD0 *mesh, const Mesh_00017FD0 *source);
};

extern Object_00016200 data_0022FCE8;

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

struct Object_000A1C50 {
    char unknown_000[0x270];
    Mesh_00017FD0 *mesh;
    Item_000162A0 shape;
    Mesh_00017FD0 *source;
    char unknown_2b4[0x9f0];
    Vector3 position;
    char unknown_cb0[0x18];
    int angle_cc8;
    int angle_ccc;
    int angle_cd0;

    void func_00089A60();
};

// Moves the player's capsule mesh to its place and angles (from the one at +0x2b0) and queues its shape on the sixth
// list of 0x22FCE8.
void Object_000A1C50::func_00089A60()
{
    func_001BA9C0();
    func_001BAAA0(&position.x);
    func_001BB2E0(angle_cc8);
    func_001BB380(angle_cd0);
    func_001BB330(angle_ccc + 0x8000);
    data_0022FCE8.func_000195F0(mesh, source);
    data_0022FCE8.func_000162E0(&shape);
    func_001BAA50();
}
