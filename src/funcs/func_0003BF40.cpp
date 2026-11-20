struct Vector3 {
    float x;
    float y;
    float z;
};

struct Entry_0003BF40 {
    Vector3 position;
    char unknown_0c[0x50];
};

struct Object_0003BF40 {
    char unknown_00[0x44];
    unsigned int index;
    unsigned int count;
    int unknown_4c;
    Entry_0003BF40 *entries;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The position of the current entry of object 0x19B5, through `position`; 0 when there is none.
int func_0003BF40(Vector3 *position)
{
    Object_0003BF40 *object = (Object_0003BF40 *)data_0022FCE0->func_000128C0(0x19b5);
    if (object && object->index < object->count && position) {
        *position = object->entries[object->index].position;
        return 1;
    }
    return 0;
}
