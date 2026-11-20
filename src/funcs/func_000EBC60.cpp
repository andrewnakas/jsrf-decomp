struct Target_000EBC60 {
    char unknown_00[0x74];
    float sizes[5];
    int values[5];
};

// The 0x6c-byte part at 0x30 of Object_000EA3B0 and at 0xbc of Object_000ECB50.
struct Part_000EB830 {
    char unknown_00[0x4c];
    float sizes[4];
    int values[4];

    void func_000EBC60(Target_000EBC60 *target);
};

extern int data_0021A0DC[4];

// Copies the part's four sizes (doubled) and four values into `target`'s two arrays at +0x74 and +0x88, at the
// slots data_0021A0DC names.
void Part_000EB830::func_000EBC60(Target_000EBC60 *target)
{
    target->sizes[data_0021A0DC[0]] = sizes[0] * 2.0f;
    target->values[data_0021A0DC[0]] = values[0];
    target->sizes[data_0021A0DC[1]] = sizes[1] * 2.0f;
    target->values[data_0021A0DC[1]] = values[1];
    target->sizes[data_0021A0DC[2]] = sizes[2] * 2.0f;
    target->values[data_0021A0DC[2]] = values[2];
    target->sizes[data_0021A0DC[3]] = sizes[3] * 2.0f;
    target->values[data_0021A0DC[3]] = values[3];
}
