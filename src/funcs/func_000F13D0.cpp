struct Vector3 {
    float x;
    float y;
    float z;
};

struct Sphere_00017EC0 {
    Vector3 center;
    float radius;
};

struct Part_00017F60;

struct Mesh_00017F60 {
    Part_00017F60 *parts;
    unsigned int count;
    Sphere_00017EC0 bounds;
};

struct Item_000162A0 {
    int unknown_00[2];
    Mesh_00017F60 *mesh;
    char unknown_0c[8];
    int unknown_14;
};

struct Item_00016200;
struct Model_000178B0;
struct Motion_0005F060;

struct Object_00016200 {
    void func_00016240(Item_00016200 *item);
    void func_000162A0(Item_000162A0 *item);
    void func_000178B0(Model_000178B0 *model, Motion_0005F060 *motion, float time);
    void func_00019570(Mesh_00017F60 *mesh, const Mesh_00017F60 *source);
};

extern Object_00016200 data_0022FCE8;

// The skeleton at 0x78.
struct Object_00047470 {
    void func_000480C0(unsigned int index);
};

void func_001BA9C0();
void __fastcall func_001BAA50();

extern unsigned int data_0021B010[2];
extern unsigned int data_0021B018[2];
extern Mesh_00017F60 data_0021AF90;
extern Mesh_00017F60 data_0021AFA8;

// A queued mesh (0x24 bytes).
struct Part_000F1820 {
    Item_000162A0 item;
    char unknown_18[0xc];
};

// The model item at 0x164: its model comes first.
struct Body_000F1820 {
    Model_000178B0 *model;
};

// The class whose table is at 0x1CF02C (constructor func_000F1820; slot 0 func_000F1C30 calls this).
struct Object_000F1820 {
    char unknown_000[0x78];
    Object_00047470 *skeleton;
    char unknown_07c[0x2c];
    Motion_0005F060 *motion;
    char unknown_0ac[0x28];
    Part_000F1820 first[2];
    Part_000F1820 second[2];
    Body_000F1820 body;

    void func_000F13D0();
};

// Between func_001BA9C0 and func_001BAA50, for both sides: loads skeleton matrix 8 / 0x15 (data_0021B010) and queues
// the mesh of the first part at 0xd4 as data_0021AF90, then matrix 0xd / 0x1a (data_0021B018) and the second part at
// 0x11c as data_0021AFA8 (func_00019570, func_000162A0 of data_0022FCE8). Then poses the model at 0x164 with the motion
// at 0xa8 (func_000178B0) and queues it (func_00016240).
void Object_000F1820::func_000F13D0()
{
    func_001BA9C0();
    for (unsigned int i = 0; i < 2; i++) {
        skeleton->func_000480C0(data_0021B010[i]);
        data_0022FCE8.func_00019570(first[i].item.mesh, &data_0021AF90);
        data_0022FCE8.func_000162A0(&first[i].item);
        skeleton->func_000480C0(data_0021B018[i]);
        data_0022FCE8.func_00019570(second[i].item.mesh, &data_0021AFA8);
        data_0022FCE8.func_000162A0(&second[i].item);
    }
    func_001BAA50();
    data_0022FCE8.func_000178B0(body.model, motion, 0.0f);
    data_0022FCE8.func_00016240((Item_00016200 *)&body);
}
