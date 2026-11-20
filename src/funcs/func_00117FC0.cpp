struct Vector3 {
    float x;
    float y;
    float z;
};

// Object 0x4c, the camera: its position at +0x44 and its target at +0x5c.
struct Camera_00117FC0 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0xc];
    Vector3 target;
};

// A 0x40-byte block whose first word is its size.
struct Listener_00117FC0 {
    unsigned int size;
    Vector3 position;
    char unknown_10[0xc];
    Vector3 front;
    char unknown_28[0x4];
    float value_2c;
    char unknown_30[0x10];
};

struct Game {
    void *func_000128C0(int id);
};

// Object 4, the sound system.
struct Object_00118CB0 {
    char unknown_0000[0x3ebc];
    Vector3 position;
    Listener_00117FC0 listener;

    void func_00117FC0();
};

extern Game *data_0022FCE0;

extern "C" void *memset(void *destination, int value, unsigned int size);
void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);
float __fastcall func_0014C460(Vector3 *out, const Vector3 *in);

// Fills the listener block at +0x3EC8 from the camera (object 0x4c): its position, and as front the normalised
// direction from target to position (func_0014C4C0, func_0014C460) when that has a length (else 0, 0, 1); then
// copies the position to +0x3EBC.
void Object_00118CB0::func_00117FC0()
{
    Camera_00117FC0 *camera = (Camera_00117FC0 *)data_0022FCE0->func_000128C0(0x4c);
    memset(&listener, 0, sizeof(listener));
    listener.size = 0x40;
    if (camera) {
        listener.position.x = camera->position.x;
        listener.position.y = camera->position.y;
        listener.position.z = camera->position.z;
        Vector3 front;
        func_0014C4C0(&front, &camera->target, &camera->position);
        if (func_0014C460(&front, &front) > 0.0f) {
            listener.front = front;
            goto done;
        }
    }
    listener.front.z = 1.0f;
done:
    position.x = listener.position.x;
    position.y = listener.position.y;
    position.z = listener.position.z;
    listener.value_2c = 1.0f;
}
