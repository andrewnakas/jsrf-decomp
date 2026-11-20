struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Object 0xe8.
struct Object_000607B0 {
    void func_000606C0(int key, Vector3 *point);
    void func_00060930(int id, int value);
    int func_000651E0(int kind, void *data, Vector3 *direction);
};

struct Object_00047470 {
    virtual ~Object_00047470();

    void func_000480C0(unsigned int index);
};

struct Object_000C5B50 {
    int func_000C5B10(int message, void *data);
    void func_000C5B40(int id, void *position);
    void func_000C5B50(int *handle);
    int func_000C5B70(int handle);
};

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

// One of the four lights: its point (0x10 bytes).
struct Light_000EC990 {
    Vector3 point;
    int unknown_0c;
};

struct Object_000ECB50 {
    char unknown_000[0xb0];
    Object_000C5B50 *owner;
    char unknown_0b4[0x20];
    int effects[4];
    int glows[4];
    char unknown_0f4[0x4c];
    Object_00047470 *model;
    char unknown_144[0x20];
    int keys[4];
    Light_000EC990 lights[4];
    int states[4];
    int key;

    void func_000EC990();
};

// With object 0xe8: for each of the four lights, by its state (0x1b4): 1 starts block 0x3a at its point, switches its
// key (0x164) off and restarts effect 0x2f (0xd4) there before 0 places the key at the point; 3 switches the key on
// and restarts effect 0x2e before 2 moves that effect to the point. Effect 0x30 (0xe4) is kept at every point. Then
// key 0x1c4 goes to the point (0, 44.2253, 6.3819) through model 0 of the model at 0x140.
void Object_000ECB50::func_000EC990()
{
    Object_000607B0 *lamps = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (lamps) {
        func_001BA9C0();
        for (int i = 0; i < 4; i++) {
            switch (states[i]) {
            case 1:
                lamps->func_000651E0(0x3a, &lights[i].point, 0);
                lamps->func_00060930(keys[i], 0);
                if (owner->func_000C5B70(effects[i])) {
                    owner->func_000C5B50(&effects[i]);
                }
                effects[i] = owner->func_000C5B10(0x2f, &lights[i].point);
            case 0:
                lamps->func_000606C0(keys[i], &lights[i].point);
                break;
            case 3:
                lamps->func_00060930(keys[i], 1);
                if (owner->func_000C5B70(effects[i])) {
                    owner->func_000C5B50(&effects[i]);
                }
                effects[i] = owner->func_000C5B10(0x2e, &lights[i].point);
            case 2:
                if (owner->func_000C5B70(effects[i])) {
                    owner->func_000C5B40(effects[i], &lights[i].point);
                }
                break;
            }
            if (owner->func_000C5B70(glows[i])) {
                owner->func_000C5B40(glows[i], &lights[i].point);
            } else {
                glows[i] = owner->func_000C5B10(0x30, &lights[i].point);
            }
        }
        Vector3 point;
        point.x = 0.0f;
        point.y = 44.2253f;
        point.z = 6.3819f;
        model->func_000480C0(0);
        func_001BAB20(&point, &point);
        lamps->func_000606C0(key, &point);
        func_001BAA50();
    }
}
