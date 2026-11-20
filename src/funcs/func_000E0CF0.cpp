struct Vector3 {
    float x;
    float y;
    float z;
};

// Three angles (x, y, z).
struct Angles_000C1300 {
    int x;
    int y;
    int z;
};

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAC50(int *angles, int order);
void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);
float __fastcall func_0014C460(Vector3 *a, const Vector3 *b);
void __fastcall func_0014C500(Vector3 *vector, const Vector3 *other);
void func_000C5670(void *parent, Vector3 *position, Vector3 *direction, int kind);

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    void func_000606C0(int key, Vector3 *value);
    int func_000651E0(int kind, void *data, Vector3 *direction);
};

// The object in data_00257CE4: its position at 0x7c and a target point at 0xa0.
struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 position;
    char unknown_88[0x18];
    Vector3 target;
};

extern Object_000C1270 *data_00257CE4;

// The kinds of the two effects at 0x120 and the two ends of the shot (from joint 3 of the holder's model).
extern int data_00217E30[2];
extern Vector3 data_00217DE4;
extern Vector3 data_00217DF0;

struct Object_00047470 {
    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
};

struct Holder_000E0440 {
    Object_00047470 *model;
};

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    int func_000C5B10(int message, void *data);
    void func_000C5B40(int handle, void *data);
    int func_000C5B70(int handle);

    char unknown_00[0x44];
    Vector3 position;
    Angles_000C1300 angles;
    char unknown_5c[0x48];
    unsigned int flags;
};

// The ranges at 0x8c: the count to start with, a reach at 0x8 and the count between shots at 0x10.
struct Ranges_000E0440 {
    int count;
    char unknown_04[4];
    float reach;
    char unknown_0c[4];
    int interval;
};

struct Object_000E0440 {
    char unknown_000[4];
    Object_000C5B50 *owner;
    char unknown_008[0x84];
    Ranges_000E0440 *ranges;
    int shots;
    char unknown_094[0xc];
    int value_0a0;
    char unknown_0a4[0x10];
    int count;
    Holder_000E0440 *holder;
    char unknown_0bc[4];
    void *data_c0;
    char unknown_0c4[0x1c];
    float value_0e0;
    char unknown_0e4[0x3c];
    int effects[2];
    char unknown_128[8];
    int handle_130;
    int handle_134;

    void func_000E0CF0();
};

// Entry 11 of the handler table at 0x217DFC: poses the holder's model at the owner (data at 0xc0, joint 3) for the
// two ends of the shot (data_00217DE4, data_00217DF0); keeps the two effects at 0x120 there (kinds data_00217E30,
// object 0xe8). Unless the owner has flag 0x4000000: within the reach of the ranges at 0x8c of the target at
// data_00257CE4+0xa0 (flat), counts down 0xb4 and then shoots (owner flag 0x2000000, func_000C5670 kind 1), back to
// state 3 after the last shot (0x90); out of reach, or with that flag, state 3 at 0xa0 and the flag cleared. Then
// moves the owner's items 4 (at it) and 5 (at data_00257CE4's position).
void Object_000E0440::func_000E0CF0()
{
    func_001BA9C0();
    func_001BAAA0(&owner->position.x);
    func_001BAC50(&owner->angles.x, 0);
    holder->model->func_00047970(data_c0, 0);
    holder->model->func_000480C0(3);
    Vector3 start;
    Vector3 end;
    func_001BAB20(&start, &data_00217DE4);
    func_001BAB20(&end, &data_00217DF0);
    func_0014C500(&end, &start);
    func_001BAA50();
    Object_000607B0 *sounds = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (sounds) {
        for (unsigned int i = 0; i < 2; i++) {
            if (effects[i] >= 0) {
                sounds->func_000606C0(effects[i], &start);
            } else {
                effects[i] = sounds->func_000651E0(data_00217E30[i], &start, 0);
            }
        }
    }
    if (!(owner->flags & 0x4000000)) {
        Vector3 offset;
        func_0014C4C0(&offset, &data_00257CE4->target, &owner->position);
        offset.y = 0.0f;
        if (ranges->reach > func_0014C460(&offset, &offset)) {
            if (--count <= 0) {
                owner->flags |= 0x2000000;
                count = ranges->interval;
                value_0e0 = 0.0f;
                func_000C5670(0, &start, &end, 1);
                if (--shots == 0) {
                    value_0a0 = 3;
                    owner->flags &= ~0x2000000;
                    count = ranges->count;
                }
            }
        } else {
            value_0a0 = 3;
            owner->flags &= ~0x2000000;
            count = ranges->count;
        }
    } else {
        value_0a0 = 3;
        owner->flags &= ~0x2000000;
        count = 0x7fffffff;
    }
    if (owner->func_000C5B70(handle_130)) {
        owner->func_000C5B40(handle_130, &owner->position);
    } else {
        handle_130 = owner->func_000C5B10(4, &owner->position);
    }
    if (owner->func_000C5B70(handle_134)) {
        owner->func_000C5B40(handle_134, &data_00257CE4->position);
    } else {
        handle_134 = owner->func_000C5B10(5, &data_00257CE4->position);
    }
}
