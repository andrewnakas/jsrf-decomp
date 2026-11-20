extern int data_00215180[];

// Half of an entry of the table at 0x64 (0x18 bytes): a start and an end.
struct Range_000A0580 {
    char unknown_00[8];
    float start;
    char unknown_0c[8];
    float end;
};

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x64];
    Range_000A0580 (*ranges)[2];
    char unknown_068[0x984];
    float value_9ec;
    float value_9f0;
    char unknown_9f4[0x478];
    int value_e6c;
    int value_e70;

    void func_000A0580();
};

// The range of the current motion (0xe6c, looked up in data_00215180): its start (second half when 0xe70 is set)
// at 0x9ec and its length at 0x9f0; 2 and 4 when the motion is not listed.
void Object_000A1C50::func_000A0580()
{
    for (unsigned int i = 0; i < 32; i++) {
        if (data_00215180[i] == value_e6c) {
            if (value_e70) {
                value_9ec = ranges[i][1].start;
                float length = ranges[i][1].end - ranges[i][1].start;
                if (length < 0.0f) {
                    length = -length;
                }
                value_9f0 = length;
            } else {
                value_9ec = ranges[i][0].start;
                float length = ranges[i][0].end - ranges[i][0].start;
                if (length < 0.0f) {
                    length = -length;
                }
                value_9f0 = length;
            }
            return;
        }
    }
    value_9ec = 2.0f;
    value_9f0 = 4.0f;
}
