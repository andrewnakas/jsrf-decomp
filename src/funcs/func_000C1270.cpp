struct Vector3 {
    float x;
    float y;
    float z;
};

float __fastcall func_0014C530(const Vector3 *a, const Vector3 *b);

// A queued sound (0x18 bytes): the sound, the key (0 for a plain sound), the position and its distance.
struct Sound_000C1270 {
    int sound;
    unsigned int key;
    Vector3 position;
    float distance;
};

// The object in data_00257CE4: its point at 0x7c, the queued sounds at 0xd8.
struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 point;
    char unknown_88[0x50];
    Sound_000C1270 sounds[64];
    unsigned int count;

    int func_000C0FE0(int sound);
    void func_000C1270(int handle, void *position);
};

extern Object_000C1270 *data_00257CE4;

// Queues the sound (func_000C0FE0 finds its entry) at the position when that is nearer to the point at 0x7c of
// data_00257CE4 (func_0014C530) than the entry's.
void Object_000C1270::func_000C1270(int handle, void *position)
{
    int index = func_000C0FE0(handle);
    if (index != -1) {
        Vector3 *point = (Vector3 *)position;
        float distance = func_0014C530(point, &data_00257CE4->point);
        if (distance < sounds[index].distance) {
            sounds[index].key = 0;
            sounds[index].position = *point;
            sounds[index].distance = distance;
        }
    }
}
