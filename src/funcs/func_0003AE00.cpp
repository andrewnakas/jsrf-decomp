struct Time_0003AE00 {
    int unknown_00;
    unsigned int seconds;
};

struct Object_00039BE0 {
    int unknown_00;
    int unknown_04;
    char unknown_08[8];
    unsigned int frames;

    void func_0003AE00(Time_0003AE00 *out);
};

// Copies the word at +0x4 out, with the frame count at +0x10 turned into seconds (60 frames each).
void Object_00039BE0::func_0003AE00(Time_0003AE00 *out)
{
    if (out) {
        out->unknown_00 = unknown_04;
        out->seconds = frames / 60;
    }
}
