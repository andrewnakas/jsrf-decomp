/* sym: ?func_000D7880@Object_000EDC30@@UAEXXZ = 0x000EFFF0 */
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
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);
void func_000FEC30(int value, const Vector3 *position);

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    int func_000651E0(int kind, void *data, Vector3 *direction);
};

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 {
    int func_000C1D40(int *effect, int *second, int *third);
};

extern Object_00157F10 *data_00257CE8;

struct Object_0006DB80 {
    void func_0006DFC0(int key, const Vector3 *position);
};

extern Object_0006DB80 data_00251F78;

// The four points the kind-0x2b effects start from.
extern Vector3 data_0021A8D0[4];

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    int func_000C5B10(int message, void *data);
    void func_000C5AD0(int amount);

    char unknown_00[0x44];
    Vector3 position;
    Angles_000C1300 angles;
    char unknown_5c[0x40];
    int value_9c;
    char unknown_a0[4];
    unsigned int flags;
};

struct Source_000EDC30 {
    char unknown_00[0x28];
    int value_28;
};

// The class whose table is at 0x1CEFAC (constructor func_000EDC30).
struct Object_000EDC30 {
    virtual void func_000D7880();

    Object_000C5B50 *owner;
    int state;
    char unknown_00c[0x5c];
    int value_68;
    char unknown_06c[0x70];
    int mode;
    char unknown_0e0[0x10];
    int value_f0;
    char unknown_0f4[4];
    Source_000EDC30 *source;
    char unknown_0fc[0x258];
    int effects_354[3];
    int value_360[3];
    int value_36c[3];
    int sound;
    Vector3 point;
    char unknown_388[0xc];
    int value_394;
    int value_398;
    char unknown_39c[8];
    int effects_3a4[4];

    void func_000EF0E0();
};

// Slot 9: runs func_000EF0E0. Unless the owner has flag 0x2000, with flag 0x4000: without 0x2000000, when both
// effects 0x354 and 0x358 are done (func_000C1D40), sets the owner's flags 0x2001000, state and mode 3, starts four
// kind-0x2b effects of object 0xe8 at data_0021A8D0 in the owner's frame (0x3a4) and sends the owner message 0x29;
// with 0x2000000, when effect 0x35c is done, takes 0x28 of the source at 0x394, sets the owner's flag 0x2000 and
// func_000C5AD0(1), state 8, mode 3, 1 at 0x68 and message 0x11 at 0x37c. Then func_000FEC30 with the owner's 0x9c,
// and the sound at 0x378 goes 10 above the owner (or the point at 0x37c with 0x2000000).
void Object_000EDC30::func_000D7880()
{
    func_000EF0E0();
    unsigned int flags = owner->flags;
    if (flags & 0x2000) {
        return;
    }
    if (flags & 0x4000) {
        if (!(flags & 0x2000000)) {
            unsigned int done = 0;
            if (data_00257CE8->func_000C1D40(&effects_354[0], &value_36c[0], &value_360[0])) {
                done = 1;
            }
            if (data_00257CE8->func_000C1D40(&effects_354[1], &value_36c[1], &value_360[1])) {
                done++;
            }
            if (done >= 2) {
                owner->flags |= 0x2001000;
                state = 3;
                mode = 3;
                value_f0 = 0x7fffffff;
                Object_000607B0 *effects = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
                if (effects) {
                    func_001BA9C0();
                    func_001BAAA0(&owner->position.x);
                    func_001BB330(owner->angles.y + 0x8000);
                    func_001BB2E0(owner->angles.x);
                    func_001BB380(owner->angles.z);
                    for (unsigned int i = 0; i < 4; i++) {
                        float start[4];
                        func_001BAB20((Vector3 *)start, &data_0021A8D0[i]);
                        effects_3a4[i] = effects->func_000651E0(0x2b, start, 0);
                    }
                    func_001BAA50();
                }
                owner->func_000C5B10(0x29, &owner->position);
            }
        } else if (data_00257CE8->func_000C1D40(&effects_354[2], &value_36c[2], &value_360[2])) {
            value_394 = source->value_28;
            value_398 = 0;
            owner->flags |= 0x2000;
            owner->func_000C5AD0(1);
            state = 8;
            mode = 3;
            value_f0 = 0x7fffffff;
            value_68 = 1;
            owner->func_000C5B10(0x11, &point);
        }
    }
    func_000FEC30(owner->value_9c, &owner->position);
    if (sound != -1) {
        Vector3 at;
        if (!(owner->flags & 0x2000000)) {
            at = owner->position;
        } else {
            at = point;
        }
        at.y += 10.0f;
        data_00251F78.func_0006DFC0(sound, &at);
    }
}
