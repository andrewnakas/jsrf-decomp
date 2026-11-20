extern "C" void *memset(void *destination, int value, unsigned int size);

struct Entry_00230DD0 {
    int unknown_00;
    int unknown_04;
    int unknown_08;
    int busy;
};

struct Entry_00230F60 {
    void *pointer;
    int unknown_4;
};

extern Entry_00230F60 data_00230F60[];
extern Entry_00230DD0 data_00230DD0[];

// Object 7.
struct Object_000265A0 {
    char unknown_0000[0x16b4];
    int unknown_16b4;
    char unknown_16b8[8];
    int unknown_16c0[25];

    void func_00025640(const char *path);
    void func_00036760();
};

// Clears +0x16b4 and the 25 words at +0x16c0, runs func_00025640 for the effect, sound and sound-effect folders, and
// clears the 25-entry tables at 0x230F60 and 0x230DD0.
void Object_000265A0::func_00036760()
{
    unknown_16b4 = 0;
    for (int i = 0; i < 25; i++)
        unknown_16c0[i] = 0;
    func_00025640("D:\\Media\\Effect\\");
    func_00025640("D:\\Media\\Sounds\\");
    func_00025640("D:\\Media\\Sounds\\SE\\");
    memset(data_00230F60, 0, 25 * sizeof(Entry_00230F60));
    memset(data_00230DD0, 0, 25 * sizeof(Entry_00230DD0));
}
