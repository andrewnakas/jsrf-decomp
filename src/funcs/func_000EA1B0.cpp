struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Object 0xe8 (the sound and effect keeper).
struct Object_000607B0 {
    void func_000606C0(int key, Vector3 *value);
    void func_00060930(int key, int value);
    int func_000651E0(int kind, void *data, Vector3 *direction);
};

struct Object_00047470 {
    void func_000480C0(unsigned int index);
};

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    int func_000C5B10(int message, void *data);
    void func_000C5B40(int handle, void *data);
    void func_000C5B50(int *handle);
    int func_000C5B70(int handle);

    char unknown_00[0x44];
    Vector3 position;
};

// The four feet: their offsets from the joints and the joints.
extern Vector3 data_002191A8[4];
extern unsigned int data_002191D8[4];

// The class whose table is at 0x1CEE78 (constructor func_000EA3B0).
struct Object_000EA3B0 {
    char unknown_000[4];
    Object_000C5B50 *owner;
    char unknown_008[0x40];
    int marks[4];
    int dusts[4];
    char unknown_068[0x78];
    int sounds[4];
    int lifted[4];
    int sound_100;
    char unknown_104[0x10];
    Object_00047470 *model;

    void func_000EA1B0();
};

// For each of the four feet (joint data_002191D8[i] of the model, offset data_002191A8[i]): a foot less than 3 above
// the owner lands when it was lifted (event 0x3a of object 0xe8 there, its sound off, a fresh kind-0x2f mark) and its
// sound follows it; a higher one lifts (sound on, a kind-0x2e mark) and its mark follows. The kind-0x30 dust follows
// each foot. Then the sound at 0x100 goes to the point (0, 44.2, 6.38) of joint 0.
void Object_000EA3B0::func_000EA1B0()
{
    Object_000607B0 *sounds_e8 = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (!sounds_e8) {
        return;
    }
    func_001BA9C0();
    for (unsigned int i = 0; i < 4; i++) {
        model->func_000480C0(data_002191D8[i]);
        Vector3 foot;
        func_001BAB20(&foot, &data_002191A8[i]);
        if (foot.y - owner->position.y < 3.0f) {
            if (lifted[i]) {
                sounds_e8->func_000651E0(0x3a, &foot, 0);
                sounds_e8->func_00060930(sounds[i], 0);
                lifted[i] = 0;
                if (owner->func_000C5B70(marks[i])) {
                    owner->func_000C5B50(&marks[i]);
                }
                marks[i] = owner->func_000C5B10(0x2f, &foot);
            }
            sounds_e8->func_000606C0(sounds[i], &foot);
        } else {
            if (!lifted[i]) {
                sounds_e8->func_00060930(sounds[i], 1);
                lifted[i] = 1;
                if (owner->func_000C5B70(marks[i])) {
                    owner->func_000C5B50(&marks[i]);
                }
                marks[i] = owner->func_000C5B10(0x2e, &foot);
            }
            if (owner->func_000C5B70(marks[i])) {
                owner->func_000C5B40(marks[i], &foot);
            }
        }
        if (owner->func_000C5B70(dusts[i])) {
            owner->func_000C5B40(dusts[i], &foot);
        } else {
            dusts[i] = owner->func_000C5B10(0x30, &foot);
        }
    }
    Vector3 tip = {0.0f, 44.2253f, 6.3819f};
    model->func_000480C0(0);
    func_001BAB20(&tip, &tip);
    sounds_e8->func_000606C0(sound_100, &tip);
    func_001BAA50();
}
