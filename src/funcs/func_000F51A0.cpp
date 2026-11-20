struct Vector3 {
    float x;
    float y;
    float z;

    Vector3() {}
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
    void set(float a, float b, float c) { x = a; y = b; z = c; }
};

struct Mesh_00017F60;

extern "C" void *memset(void *destination, int value, unsigned int size);

struct Object_00016200 {
    Mesh_00017F60 *func_00019680(const Mesh_00017F60 *mesh);
};

extern Object_00016200 data_0022FCE8;

struct Object_0003E750 {
    int func_0003EE90(void *effect, int first, int second, int third, float scale, int fourth, int id, int fifth);
    void func_0003F410(int index, int value);
};

extern Object_0003E750 data_002314B0;

struct Object_00046670 {
    float func_000466C0(Vector3 *position, int hint);
};

extern Object_00046670 data_001F93C8;

extern Mesh_00017F60 data_0021B850;
extern char data_0021B6D0[];

// The node that made this one; its flags at 0xa4.
struct Owner_000F51A0 {
    char unknown_00[0xa4];
    unsigned int flags;
};

struct Node {
    virtual ~Node();

    unsigned int flags;
    int id;
    unsigned int mask;
    float depth;
    int sortKey;
    char unknown_18[0xc];
    Node *parent;
    Node *child;
    Node *previous;
    Node *next;
    char unknown_34[0x10];
};

struct Object_000F55E0 : Node {
    virtual void func_000F51A0();

    char unknown_044[4];
    Vector3 position;
    int value_54;
    int heading;
    int value_5c;
    int value_60;
    int value_64;
    char unknown_068[0x20];
    float floor;
    char unknown_08c[0x10];
    int value_9c;
    int value_a0;
    char unknown_0a4[0xc];
    Owner_000F51A0 *owner;
    char unknown_0b4[8];
    int value_bc;
    Vector3 vector_c0;
    Vector3 target;
    int value_d8;
    char unknown_0dc[0xc];
    Vector3 velocity;
    char unknown_0f4[0x18];
    int value_10c;
    float scale[2];
    char unknown_118[8];
    Vector3 home;
    int homeHeading;
    char unknown_130[0x10];
    int value_140;
    int value_144;
    char unknown_148[0xc];
    int value_154;
    int value_158;
    int value_15c;
    char unknown_160[8];
    int value_168;
    int value_16c;
    int value_170;
    char unknown_174[4];
    int value_178;
    Mesh_00017F60 *mesh;
    Mesh_00017F60 *source;
    char unknown_184[0x44];
    int value_1c8;
    int value_1cc;
    Mesh_00017F60 *mesh_1d0;
    char unknown_1d4[0x18];
    int effect;
};

// Slot 16: plays effect 0x21B6D0 when the owner has flag 0x4000, puts the node back at its home position and heading,
// clears its motion, copies mesh 0x21B850 and finds the floor under it.
void Object_000F55E0::func_000F51A0()
{
    if (owner->flags & 0x4000) {
        effect = data_002314B0.func_0003EE90(data_0021B6D0, -1, -1, 1, 0.5f, 1, id, -1);
        data_002314B0.func_0003F410(effect, 0);
    }
    target = home;
    position = home;
    heading = homeHeading;
    value_5c = 0;
    value_54 = 0;
    value_bc = 1;
    value_16c = 0;
    value_168 = 0;
    value_170 = 0;
    value_140 = 0;
    value_144 = 0;
    value_154 = 0;
    value_15c = 0;
    value_158 = 0;
    value_178 = 0;
    value_64 = 0;
    value_60 = 0;
    value_a0 = 0;
    value_d8 = 0;
    memset(&velocity, 0, sizeof(velocity));
    memset(&vector_c0, 0, sizeof(vector_c0));
    value_9c = 0;
    value_10c = 0;
    scale[0] = 1.0f;
    scale[1] = 1.0f;
    mesh = data_0022FCE8.func_00019680(&data_0021B850);
    source = &data_0021B850;
    mesh_1d0 = mesh;
    value_1c8 = 2;
    value_1cc = 1;
    floor = data_001F93C8.func_000466C0(&position, -1);
}
