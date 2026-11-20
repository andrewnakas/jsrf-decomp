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
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);

struct Object_000607B0 {
    int func_000651E0(int kind, void *data, Vector3 *direction);
};

void func_000F43D0(const Vector3 *position, Vector3 *direction);

extern unsigned int data_0021B1A4[];
extern Vector3 data_0021B198;
extern Vector3 data_0021B18C;

struct Object_000F2AA0 {
    int unknown_00;
    Object_000C5B50 *owner;
    char unknown_08[0x78];
    Object_000F1820 *body;

    void func_000F2500(int index);
};

// Fires from part `index` of the body: on skeleton matrix data_0021B1A4[index] (posed by the body's motion) the
// point data_0021B198 and the direction (0, 0, -1) turned with it go to func_000F43D0; from the point data_0021B18C
// object 0xe8 gets kind 0x53 with that direction (func_000651E0) and the owner message 0x3e with the point.
void Object_000F2AA0::func_000F2500(int index)
{
    Vector3 direction;
    Vector3 point;
    direction.x = 0.0f;
    direction.y = 0.0f;
    direction.z = -1.0f;
    func_001BAA00();
    body->skeleton->func_00047970(body->motion, 0);
    body->skeleton->func_000480C0(data_0021B1A4[index]);
    func_001BAB20(&point, &data_0021B198);
    func_001BAC00(&direction, &direction);
    func_000F43D0(&point, &direction);
    func_001BAB20(&point, &data_0021B18C);
    Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (object) {
        object->func_000651E0(0x53, &point, &direction);
    }
    func_001BAA50();
    owner->func_000C5B10(0x3e, &point);
}
