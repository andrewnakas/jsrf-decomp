struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The owner at 0x4.
struct Object_000C5B50 {
    int func_000C5B10(int message, void *data);
    void func_000C5B40(int id, void *position);
    int func_000C5B70(int handle);
};

// The skeleton of the body.
struct Object_00047470 {
    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
};

// The body at 0x80 (an Object_000F1820): its skeleton at 0x78 and the motion at 0xa8.
struct Object_000F1820 {
    char unknown_00[0x78];
    Object_00047470 *skeleton;
    char unknown_7c[0x2c];
    void *motion;
};

void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

struct Object_000F37B0 {
    void func_000F3D60(const Vector3 *point);
};

int func_000F3DA0(const Vector3 *position);

extern unsigned int data_0021B17C[];
extern Vector3 data_0021B170;

struct Object_000F2AA0 {
    int unknown_00;
    Object_000C5B50 *owner;
    char unknown_08[0x68];
    int ids[4];
    Object_000F1820 *body;
    char unknown_84[0x10];
    int handles[4];

    void func_000F2420(int index, int create);
};

// Part `index` of the body: the point data_0021B170 on skeleton matrix data_0021B17C[index] (posed by the body's
// motion). Creates an Object_000F37B0 there (func_000F3DA0; its id at 0x70) or moves the existing one
// (func_000F3D60), then moves the owner's handle at 0x94 there (func_000C5B40), or gets one with message 0x3b
// (func_000C5B10) when the owner no longer knows it.
void Object_000F2AA0::func_000F2420(int index, int create)
{
    Vector3 point;
    func_001BAA00();
    body->skeleton->func_00047970(body->motion, 0);
    body->skeleton->func_000480C0(data_0021B17C[index]);
    func_001BAB20(&point, &data_0021B170);
    func_001BAA50();
    if (!create) {
        Object_000F37B0 *object = (Object_000F37B0 *)data_0022FCE0->func_000128C0(ids[index]);
        if (object) {
            object->func_000F3D60(&point);
        }
    } else {
        ids[index] = func_000F3DA0(&point);
    }
    if (owner->func_000C5B70(handles[index])) {
        owner->func_000C5B40(handles[index], &point);
    } else {
        handles[index] = owner->func_000C5B10(0x3b, &point);
    }
}
