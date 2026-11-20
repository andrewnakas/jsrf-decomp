struct Vector3 {
    float x;
    float y;
    float z;
};

// What func_00018260 tests a segment against: two counted parts (+4 and +0x14).
struct Model_00018260 {
    void *unknown_00;
    unsigned int count;
    char unknown_08[0xc];
    unsigned int otherCount;
    char unknown_18[0x14];
};

// What func_00018260 reports (16 bytes, cleared first).
struct Hit_00018260 {
    float unknown_00[4];
};

struct Object_00016200 {
    int func_00018260(Model_00018260 *model, Vector3 *from, Vector3 *to, Hit_00018260 *hit, int mask, int flags);
};

extern Object_00016200 data_0022FCE8;

struct Segment_00044E80 {
    Vector3 from;
    Vector3 to;
    Model_00018260 model;
};

struct Object_00044AE0 {
    char unknown_000[0x144];
    Segment_00044E80 segments[29];
    char unknown_8f8[0x3c];
    int count;

    int func_00044E80();
};

// 1 when func_00018260 of 0x22FCE8 (mask 0xffff) reports a hit for any of the `count` segments whose model has parts.
int Object_00044AE0::func_00044E80()
{
    Hit_00018260 hit;
    for (int i = 0; i < count; i++) {
        if (segments[i].model.count > 0 || segments[i].model.otherCount > 0) {
            if (data_0022FCE8.func_00018260(&segments[i].model, &segments[i].from, &segments[i].to, &hit, 0xffff, -1))
                return 1;
        }
    }
    return 0;
}
