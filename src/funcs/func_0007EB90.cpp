struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The camera node (table 0x1CD518): fades its colour towards a target.
struct Object_000A4D80 {
    void func_000A4C30(unsigned int color, float step);
};

// The player.
struct Object_000A1C50 {
    char unknown_000[0xc98];
    int camera;

    void func_0007EB90(unsigned int color, float step);
};

// Hands the colour and step to func_000A4C30 of the camera node whose id is at +0xc98, when it is there.
void Object_000A1C50::func_0007EB90(unsigned int color, float step)
{
    Object_000A4D80 *object = (Object_000A4D80 *)data_0022FCE0->func_000128C0(camera);
    if (object) {
        object->func_000A4C30(color, step);
    }
}
