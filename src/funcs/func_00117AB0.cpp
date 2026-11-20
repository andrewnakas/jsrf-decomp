struct Vector3 {
    float x;
    float y;
    float z;
};

struct Marker_00117B20 {
    int id;
    Vector3 position;
};

struct Sound_00117AB0 {
    int group;
    int index;
};

struct Object_00117A30 {
    virtual ~Object_00117A30();
    virtual void func_00117AB0();

    char unknown_04[0x44];
    int played;
    unsigned int count;
    Marker_00117B20 markers[32];
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;
extern Sound_00117AB0 data_002227A8[];
int func_00119540(int group, int index, void *position);

// Slot 1 of the table at 0x1D77B8: once object 0x4c exists, plays the sound of each marker at its position
// (func_00119540 with the group and entry data_002227A8 gives for the marker's id), once.
void Object_00117A30::func_00117AB0()
{
    if (data_0022FCE0->func_000128C0(0x4c) && !played) {
        for (unsigned int i = 0; i < count; i++) {
            Sound_00117AB0 *sound = &data_002227A8[markers[i].id];
            func_00119540(sound->group, sound->index, &markers[i].position);
        }
        played = 1;
    }
}
