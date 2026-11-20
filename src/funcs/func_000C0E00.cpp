/* sym: ??0Object_000C1270@@QAE@XZ = 0x000C0E00 */
/* sym: ??0Object_00066980@@QAE@XZ = 0x00066920 */
struct Vector3 {
    float x;
    float y;
    float z;
};

// The 15-bit pseudo-random generator (constructor func_00066920 clears it, func_00066980 seeds it).
struct Object_00066980 {
    Object_00066980();

    int value;

    void func_00066980(int newValue);
};

struct Link_000C6150;

// A queued sound (0x18 bytes): the sound, the key (0 for a plain sound), the position and its distance.
struct Sound_000C1270 {
    int sound;
    unsigned int key;
    Vector3 position;
    float distance;
};

void *func_00025700(unsigned int index, int first, int second, int third);

// The object in data_00257CE4 (destructor func_000C0EB0): the lists per area at 0x4, a generator at 0x78, the
// points at 0x7c, 0x88 and 0x94, two resources at 0xcc and 0xd0 and the queued sounds at 0xd8.
struct Object_000C1270 {
    Object_000C1270();

    int unknown_00;
    Link_000C6150 *lists[29];
    Object_00066980 *clock;
    Vector3 point;
    Vector3 point_88;
    Vector3 point_94;
    char unknown_a0[0x2c];
    void *resource_cc;
    void *resource_d0;
    int value_d4;
    Sound_000C1270 sounds[64];
    unsigned int count;
};

// Marks 0 as -1, clears the lists, makes the generator (seed 0x19f), takes resources 0xb/0/1/6 and 0xb/0/4/4
// (func_00025700) and starts with no sound queued.
Object_000C1270::Object_000C1270()
{
    unknown_00 = -1;
    for (int i = 0; i < 29; i++) {
        lists[i] = 0;
    }
    clock = new Object_00066980;
    clock->func_00066980(0x19f);
    resource_cc = func_00025700(0xb, 0, 1, 6);
    resource_d0 = func_00025700(0xb, 0, 4, 4);
    value_d4 = 0;
    count = 0;
}
