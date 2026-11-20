struct Vector3 {
    float x;
    float y;
    float z;
};

struct Node;

Node *func_000C70A0(Node *owner, Vector3 *position, int kind);
void func_000C4B70(int kind);
void func_001BA9C0();
void func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    int func_000651E0(int kind, void *data, Vector3 *direction);
};

// The object a behaviour serves (the owner type of the Object_000CC600 family).
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    int angle_x;
    int angle_y;
    int angle_z;
    char unknown_5c[0x14];
    float level;

    int func_000C5B10(int message, void *data);
};

// The behaviour func_000D6350 builds; this is entry 8 of its handler table at 0x21718C (the pointer at 0x74).
struct Object_000D6350 {
    void *vtable;
    Object_000C5B50 *desc;
    int state;
    char unknown_0c[4];
    int count;

    void func_000D6B90();
};

// Below level 30: func_000C70A0 kind 1 at the served object's position, object 0xE8 (if any) gets func_000651E0 kind
// 0x38 there, the count restarts, state 9, func_000C4B70(1) runs inside a matrix placed and turned like the object, and
// the object gets message 0x22 with its position.
void Object_000D6350::func_000D6B90()
{
    if (desc->level < 30.0f) {
        func_000C70A0(0, &desc->position, 1);
        Object_000607B0 *node = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (node) {
            node->func_000651E0(0x38, &desc->position, 0);
        }
        count = 0;
        state = 9;
        func_001BA9C0();
        func_001BAAA0(&desc->position.x);
        func_001BB330(desc->angle_y + 0x8000);
        func_001BB2E0(desc->angle_x);
        func_001BB380(desc->angle_z);
        func_000C4B70(1);
        func_001BAA50();
        desc->func_000C5B10(0x22, &desc->position);
    }
}
