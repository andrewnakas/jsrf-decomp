struct Vector3 {
    float x;
    float y;
    float z;
};

struct Matrix_001BA950 {
    float m[4][4];
};

struct Light_00046920 {
    int unknown_00;
    unsigned int color_04;
    unsigned int color_08;
    int unknown_0c;
    Vector3 direction;
    char unknown_1c[0x24];
    unsigned int color_40;
    int unknown_44;
    unsigned int color_48;
    int unknown_4c;
    int value_50;
    char unknown_54[0x1c];
};

struct Object_0006A960 {
    void func_0006BBA0(Vector3 *position, Light_00046920 *light);
};

extern Object_0006A960 data_0020C6C0;

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BA8F0(Matrix_001BA950 *matrix);
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);

struct Node {
    virtual ~Node();

    Node *func_00011BD0();

    char unknown_04[0x40];
};

// What the parent keeps at +0x44: its position.
struct Parent_00046340 : Node {
    Vector3 position;
};

// The class whose table is at 0x1CA788 (Node child, destructor 0x44AE0).
struct Object_00044AE0 : Node {
    char unknown_044[0xc];
    Vector3 position;
    char unknown_05c[0x24];
    int fixed;
    Vector3 farPoint;
    Vector3 nearPoint;
    char unknown_09c[0x28];
    float depth;
    char unknown_0c8[0x30];
    Matrix_001BA950 matrix;

    void func_00044C40(Vector3 *vector);
    void func_00046340();
};

// Follows the parent's position (+0x44 into +0x50); with object 0xe7 present, points along the light that
// 0x20C6C0 places there (unless +0x80 fixes the points at +0x84 and +0x90, which it then aims at), and keeps the
// direction's depth in the matrix at +0xf8 at +0xc4.
void Object_00044AE0::func_00046340()
{
    Vector3 direction;
    Vector3 view;
    Light_00046920 light;
    Parent_00046340 *parent = (Parent_00046340 *)func_00011BD0();
    if (parent) {
        position.x = parent->position.x;
        position.y = parent->position.y;
        position.z = parent->position.z;
    }
    if (!data_0022FCE0->func_000128C0(0xe7))
        return;
    if (!fixed) {
        data_0020C6C0.func_0006BBA0(&position, &light);
        direction.x = -light.direction.x;
        direction.y = -light.direction.y;
        direction.z = -light.direction.z;
        func_00044C40(&direction);
        farPoint.x = direction.x * 1000.0f + position.x;
        farPoint.y = direction.y * 530.0f + position.y;
        farPoint.z = direction.z * 1000.0f + position.z;
        nearPoint.x = direction.x * 10.0f + position.x;
        nearPoint.y = direction.y * 5.2999997f + position.y;
        nearPoint.z = direction.z * 10.0f + position.z;
    } else {
        direction.x = farPoint.x - position.x;
        direction.y = farPoint.y - position.y;
        direction.z = farPoint.z - position.z;
        func_00044C40(&direction);
    }
    func_001BA9C0();
    func_001BA8F0(&matrix);
    func_001BAC00(&view, &direction);
    func_001BAA50();
    func_00044C40(&view);
    depth = (view.x + view.y) * 0.0f + view.z;
}
