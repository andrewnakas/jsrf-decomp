/* sym: ??0Object_0001E4D0@@QAE@PAX@Z = 0x0001E4D0 */
extern "C" void *memset(void *destination, int value, unsigned int size);

// The 15-bit pseudo-random generator (data_00251F28).
struct Object_00066980 {
    float func_00066950();
};

extern Object_00066980 data_00251F28;

// A 0xa8-byte record made by func_00022E50.
struct Object_0001E4D0 {
    int unknown_00;
    int unknown_04;
    void *data;
    char unknown_0c[0x58];
    float unknown_64;
    char unknown_68[0x18];
    int unknown_80;
    int unknown_84;
    char unknown_88[8];
    int unknown_90[3];
    int unknown_9c;
    int unknown_a0;
    int unknown_a4;

    Object_0001E4D0(void *data);
};

// Clears the record, keeps `data` at +0x8, sets +0x4, +0x84, +0x9c and +0xa0 to -1 and +0x80 to 8, and +0x64 to a
// random value (func_00066950) times 15.
Object_0001E4D0::Object_0001E4D0(void *data)
{
    memset(this, 0, sizeof(Object_0001E4D0));
    this->data = data;
    unknown_04 = -1;
    for (int i = 0; i < 3; i++)
        unknown_90[i] = 0;
    unknown_9c = -1;
    unknown_a0 = -1;
    unknown_84 = -1;
    unknown_80 = 8;
    unknown_64 = data_00251F28.func_00066950() * 15.0f;
}
