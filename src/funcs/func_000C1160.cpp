struct Vector3 {
    float x;
    float y;
    float z;
};

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
    int func_000C1160(int kind, int value, Vector3 *position);
};

extern Object_000C1270 *data_00257CE4;

int func_00118890(int first, int second);
int func_00118710(int handle);
int func_00119540(int group, int index, void *position);
float __fastcall func_0014C530(const Vector3 *a, const Vector3 *b);

// Plays sound (kind, value) at the position, or queues it. The sound (func_00118890) gets an entry
// (func_000C0FE0; -1 when the queue is full). While it is already playing (func_00118710), a nearer position
// (distance to the point at 0x7c of data_00257CE4, func_0014C530) replaces the entry's, keyed by kind << 16 | value;
// otherwise it starts (func_00119540, whose handle is returned) and the entry takes key 0, the position and the
// distance. Returns the handle.
int Object_000C1270::func_000C1160(int kind, int value, Vector3 *position)
{
    int handle = func_00118890(kind, value);
    int index = func_000C0FE0(handle);
    if (index != -1) {
        float distance = func_0014C530(position, &data_00257CE4->point);
        if (func_00118710(handle)) {
            if (sounds[index].distance > distance) {
                sounds[index].key = (kind << 16) | value;
                sounds[index].position = *position;
                sounds[index].distance = distance;
            }
        } else {
            handle = func_00119540(kind, value, position);
            sounds[index].key = 0;
            sounds[index].position = *position;
            sounds[index].distance = distance;
        }
        return handle;
    }
    return -1;
}
