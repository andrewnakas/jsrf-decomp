struct Vector3 {
    float x;
    float y;
    float z;
};

struct Marker_00117B20 {
    int id;
    Vector3 position;
};

struct Object_00117A30 {
    char unknown_00[0x48];
    int value_48;
    unsigned int count;
    Marker_00117B20 markers[32];
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Adds a marker (an id and a position) to the up to 32 of object 0xe9.
void func_00117B20(int id, Vector3 *position)
{
    Object_00117A30 *object = (Object_00117A30 *)data_0022FCE0->func_000128C0(0xe9);
    if (object && object->count < 32) {
        object->value_48 = 0;
        object->markers[object->count].id = id;
        object->markers[object->count].position = *position;
        object->count++;
    }
}
