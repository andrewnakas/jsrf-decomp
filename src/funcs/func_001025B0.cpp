struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The objects with ids 0x115e to 0x1162 (table 0x1D2020): the id of their target at 0x16b8.
struct Object_00107FE0 {
    char unknown_0000[0x16b8];
    int target;
};

// What the target's 0x24 points at: a position at 0xca4.
struct Body_001025B0 {
    char unknown_000[0xca4];
    Vector3 position;
};

// The target: its body at 0x24 and two points at 0x1e4 and 0x1f0.
struct Target_001025B0 {
    char unknown_000[0x24];
    Body_001025B0 *body;
    char unknown_028[0x1bc];
    Vector3 from;
    Vector3 to;
};

int func_0014C7D0(float x, float z);
float __fastcall func_0014C6B0(const Vector3 *vector);

// A direct child of Node (table 0x1D1DD0, destructor func_00102480).
struct Object_00102480 {
    char unknown_00[0x54];
    int owner;
    int mode;
    char unknown_5c[4];
    Vector3 position;
    char unknown_6c[0xc];
    int pitch;
    int angle;

    void func_001025B0();
};

// Called by slot 1: with the owner (id at 0x54) and its target (id at its 0x16b8) and the target's body, the angle at
// 0x7c is the heading (func_0014C7D0) from the body's position to the one at 0x60 less the target's heading (from
// 0x1e4 to 0x1f0); in mode 1 also the pitch at 0x78 (the height against the flat distance, func_0014C6B0).
void Object_00102480::func_001025B0()
{
    Object_00107FE0 *object = (Object_00107FE0 *)data_0022FCE0->func_000128C0(owner);
    if (object) {
        Target_001025B0 *target = (Target_001025B0 *)data_0022FCE0->func_000128C0(object->target);
        if (target && target->body) {
            Vector3 delta;
            delta.x = position.x - target->body->position.x;
            delta.y = position.y - target->body->position.y;
            delta.z = position.z - target->body->position.z;
            angle = func_0014C7D0(delta.x, delta.z);
            angle -= func_0014C7D0(target->to.x - target->from.x, target->to.z - target->from.z);
            if (mode == 1) {
                Vector3 flat;
                flat.x = delta.x;
                flat.y = 0.0f;
                flat.z = delta.z;
                float length = func_0014C6B0(&flat);
                pitch = func_0014C7D0(-delta.y, length);
            }
        }
    }
}
