/* sym: ?func_000D77D0@Object_000DB8F0@@UAEXXZ = 0x000DC490 */
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

void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Object 0xe8 (the sound and effect keeper).
struct Object_000607B0 {
    void func_000606C0(int key, Vector3 *value);
    void func_00060730(int key, Vector3 *value);
    void func_00060810(int key);
    int func_000609A0(int key);
    void func_000609E0(int key, float value);
    int func_000651E0(int kind, void *data, Vector3 *direction);
};

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 {
    void func_000C1EA0(int key);
};

extern Object_00157F10 *data_00257CE8;

// The two points of the kind-0x30 effects (on the ground) and of the kind-0x31 ones (in the air).
extern Vector3 data_0021776C[2];
extern Vector3 data_00217784[2];

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    int func_000C5B10(int message, void *data);
    void func_000C5B40(int handle, void *data);
    void func_000C5B50(int *handle);
    int func_000C5B70(int handle);

    char unknown_00[0x44];
    Vector3 position;
    Angles_000C1300 angles;
    char unknown_5c[0x48];
    unsigned int flags;
};

// The class whose table is at 0x1CE780 (constructor func_000DB8F0).
struct Object_000DB8F0 {
    virtual void func_000D77D0();

    Object_000C5B50 *owner;
    int state;
    char unknown_00c[8];
    Vector3 position;
    char unknown_020[0x78];
    int mode;
    char unknown_09c[0x98];
    int key;
    char unknown_138[0xc];
    int ground[2];
    int air[2];
    int handle_154;
    int handle_158;

    void func_000DC1F0();
};

// The handlers by the mode at 0x98.
extern void (Object_000DB8F0::*data_002177BC[])();

// Slot 8: runs the handler of the mode at 0x98; in a matrix at the position turned like the owner (a half turn past its
// heading) runs func_000DC1F0 and, unless the owner has flag 1, hands the key at 0x134 to data_00257CE8. Outside state
// 2 keeps the two kind-0x30 effects (0x144) at data_0021776C pointing down, made again when gone (func_000609A0), stops
// the kind-0x31 ones (0x14c), drops the owner's item 0x158 and moves item 0x24 (0x154) to it; in state 2 the other way
// round with the kind-0x31 effects at data_00217784 facing the matrix's z axis and item 0x23.
void Object_000DB8F0::func_000D77D0()
{
    (this->*data_002177BC[mode])();
    func_001BAA00();
    func_001BAAA0(&position.x);
    func_001BB330(owner->angles.y + 0x8000);
    func_001BB2E0(owner->angles.x);
    func_001BB380(owner->angles.z);
    func_000DC1F0();
    if (key != -1 && !(owner->flags & 1)) {
        data_00257CE8->func_000C1EA0(key);
    }
    if (state != 2) {
        Object_000607B0 *effects = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (effects) {
            Vector3 down = {0.0f, -1.0f, 0.0f};
            for (unsigned int i = 0; i < 2; i++) {
                Vector3 point;
                func_001BAB20(&point, &data_0021776C[i]);
                if (ground[i] < 0 || effects->func_000609A0(ground[i])) {
                    ground[i] = effects->func_000651E0(0x30, &point, &down);
                    effects->func_000609E0(ground[i], 1.0f);
                } else {
                    effects->func_000606C0(ground[i], &point);
                }
                if (air[i] >= 0) {
                    effects->func_00060810(air[i]);
                    air[i] = -1;
                }
            }
        }
        owner->func_000C5B50(&handle_158);
        if (owner->func_000C5B70(handle_154)) {
            owner->func_000C5B40(handle_154, &owner->position);
        } else {
            handle_154 = owner->func_000C5B10(0x24, &owner->position);
        }
    } else {
        Object_000607B0 *effects = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (effects) {
            Vector3 axis = {0.0f, 0.0f, 1.0f};
            for (unsigned int i = 0; i < 2; i++) {
                Vector3 point;
                func_001BAB20(&point, &data_00217784[i]);
                func_001BAC00(&axis, &axis);
                if (air[i] >= 0) {
                    effects->func_000606C0(air[i], &point);
                    effects->func_00060730(air[i], &axis);
                } else {
                    air[i] = effects->func_000651E0(0x31, &point, &axis);
                    effects->func_000609E0(air[i], 1.0f);
                }
                if (ground[i] >= 0) {
                    effects->func_00060810(ground[i]);
                    ground[i] = -1;
                }
            }
        }
        owner->func_000C5B50(&handle_154);
        if (owner->func_000C5B70(handle_158)) {
            owner->func_000C5B40(handle_158, &owner->position);
        } else {
            handle_158 = owner->func_000C5B10(0x23, &owner->position);
        }
    }
    func_001BAA50();
}
