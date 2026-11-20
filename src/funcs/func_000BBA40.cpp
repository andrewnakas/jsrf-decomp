/* sym: ?func_00011C80@Object_000BB710@@UAEXH@Z = 0x000BBA40 */
struct Node {
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);

    unsigned int flags;
    int id;
    unsigned int mask;
    float depth;
    char unknown_14[0x2c];
};

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Matrix_001BA950 {
    float m[4][4];
};

struct Model_00101A70 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void draw(int first, int second);
};

// One of the lights of an entry (0xb8 bytes): its position at 0x94.
struct Light_0003E720 {
    char unknown_00[0x94];
    Vector3 position;
    char unknown_a0[0x18];
};

struct Entry_0003E720 {
    char unknown_00[0x94];
    Light_0003E720 *lights;
    unsigned int count;
    char unknown_9c[4];
    int shown;
    unsigned int kinds;
};

struct Object_0003E750 {
    Entry_0003E720 *func_0003E720(int key);
};

extern Object_0003E750 data_002314B0;

struct Camera_000BBA40 {
    char unknown_00[0x44];
    Vector3 position;
};

struct Game {
    char unknown_0000[0x87ec];
    Camera_000BBA40 *camera;
};

extern Game *data_0022FCE0;

struct Object_0006A960 {
    int func_0006AC10(int key);
};

extern Object_0006A960 data_0020C6C0;

unsigned int func_000B9B50(Model_00101A70 *model, float *time);
float __fastcall func_0014C530(const Vector3 *a, const Vector3 *b);
void func_001BA9C0();
void __fastcall func_001BA8F0(Matrix_001BA950 *matrix);
void __fastcall func_001BA950(Matrix_001BA950 *matrix);
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAC50(int *angles, int order);
void __fastcall func_001BB270(float *scale);
void __fastcall func_001BAA50();

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CDA60; constructor
// func_000BB4C0).
struct Object_000BB710 : Node {
    virtual void func_00011C80(int argument);

    char unknown_040[0x50];
    int key;
    char unknown_094[8];
    Model_00101A70 *model;
    int value_a0;
    int value_a4;
    int glow;
    Model_00101A70 *halo;
    int value_b0;
    int value_b4;
    int light;
    Vector3 center;
    float fade;
    Vector3 position;
    int angles[3];
    Vector3 scale;
    char unknown_0f0[0x28];
    Matrix_001BA950 matrix;
    unsigned int state;
    float distance;
};

// Slot 3 (the pass), when the key at 0x90 is known to data_0020C6C0. Pass 2 poses the model into the matrix at
// 0x118 (view state from func_000B9B50 at 0x158) and keeps the view depth as the node's depth. Pass 3 draws the
// model and, with 0xa8 set and the light entry 0xb8 of data_002314B0 shown, the halo at 0xac: it fades in (by 1/30)
// within 200 of the camera and out beyond; while it shows it is drawn at each light of kind 7 (three bits per light
// at 0xa4 of the entry), moved from the centre at 0xbc toward the light by the fade; else once at the centre.
void Object_000BB710::func_00011C80(int argument)
{
    if (key == -1) {
        return;
    }
    if (!data_0020C6C0.func_0006AC10(key)) {
        return;
    }
    switch (argument) {
    case 3: {
        func_001BA9C0();
        func_001BA8F0(&matrix);
        if (model) {
            model->draw(value_a0, value_a4);
        }
        func_001BAA50();
        if (!glow) {
            break;
        }
        Entry_0003E720 *entry = data_002314B0.func_0003E720(light);
        if (!entry->shown) {
            break;
        }
        func_001BA9C0();
        if (func_0014C530(&data_0022FCE0->camera->position, &center) < 200.0f) {
            fade += 1.0f / 30.0f;
            if (fade > 1.0f) {
                fade = 1.0f;
            }
        } else {
            fade -= 1.0f / 30.0f;
            if (fade < 0.0f) {
                fade = 0;
            }
        }
        if (fade > 0.0f) {
            for (unsigned int i = 0; i < entry->count; i++) {
                if (((entry->kinds >> (i * 3)) & 7) == 7) {
                    Vector3 at;
                    at.x = (entry->lights[i].position.x - center.x) * fade + center.x;
                    at.y = (entry->lights[i].position.y - center.y) * fade + center.y;
                    at.z = (entry->lights[i].position.z - center.z) * fade + center.z;
                    func_001BA9C0();
                    func_001BAAA0(&at.x);
                    halo->draw(value_b0, value_b4);
                    func_001BAA50();
                }
            }
        } else {
            func_001BA9C0();
            func_001BAAA0(&center.x);
            halo->draw(value_b0, value_b4);
            func_001BAA50();
        }
        func_001BAA50();
        break;
    }
    case 2:
        func_001BA9C0();
        func_001BAAA0(&position.x);
        func_001BAC50(angles, 0);
        func_001BB270(&scale.x);
        func_001BA950(&matrix);
        state = func_000B9B50(model, &distance);
        func_001BAA50();
        depth = distance;
        break;
    }
}
