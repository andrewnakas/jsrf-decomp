struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_00117510 {
    void func_00117560(int kind, Vector3 *position, float x, float y);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Passes its arguments to func_00117560 of object 0xea (a kind, a position, two floats), the floats scaled by
// 10.
void func_00117770(int kind, Vector3 *position, float x, float y)
{
    Object_00117510 *object = (Object_00117510 *)data_0022FCE0->func_000128C0(0xea);
    if (object) {
        object->func_00117560(kind, position, x * 10.0f, y * 10.0f);
    }
}
