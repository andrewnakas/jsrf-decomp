struct Object_0007FA70 {
    void func_0007FA70();
};

// A landing pose: two words each.
struct Pose_00215D1C {
    int first;
    int second;
};

extern Pose_00215D1C data_00215D1C[];
extern unsigned int data_00215D44;
extern int data_0020E5E4[];

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0xa0c];
    int value_a0c;
    char unknown_a10[0x58];
    Pose_00215D1C *pose;
    int value_a6c;
    char unknown_a70[0x34];
    int ground;
    char unknown_aa8[0x3a8];
    int value_e50;
    char unknown_e54[4];
    int phase;
    char unknown_e5c[0x1f8];
    unsigned int value_1054;
    int value_1058;
    char unknown_105c[0x5c];
    int value_10b8;
    char unknown_10bc[4];
    int value_10c0;
    char unknown_10c4[0xc];
    int value_10d0;

    unsigned int func_0007F9B0(unsigned int range);
    void func_0009AA70(int motion);
    void func_000A1CF0();
    void func_0009B190(int index);
};

// Phase 3 (unless 9), func_0009AA70 with entry index of data_0020E5E4, func_0007FA70, func_000A1CF0; clears 0xa0c,
// 2 at 0xe50, a random pose of data_00215D1C (count data_00215D44, func_0007F9B0) at 0xa68; on ground 0 counts 0x1058
// up when 0x1054 was running and restarts it at 30; clears 0x10b8, 0x10c0 and 0x10d0.
void Object_000A1C50::func_0009B190(int index)
{
    if (phase != 9) {
        phase = 3;
    }
    func_0009AA70(data_0020E5E4[index]);
    ((Object_0007FA70 *)this)->func_0007FA70();
    func_000A1CF0();
    value_a0c = 0;
    value_e50 = 2;
    pose = &data_00215D1C[func_0007F9B0(data_00215D44 << 8) >> 8];
    value_a6c = 0;
    if (ground == 0) {
        if (value_1054 > 0) {
            value_1058++;
        }
        value_1054 = 30;
    }
    value_10b8 = 0;
    value_10c0 = 0;
    value_10d0 = 0;
}
