// The camera node (table 0x1CD518): a target colour at 0x1c8 (red, green, blue, alpha from 0 to 1), the step it
// fades by at 0x1d8 and a flag at 0x1e0 (only the fields this method uses).
struct Object_000A4D80 {
    char unknown_000[0x1c8];
    float target[4];
    float step;
    char unknown_1dc[4];
    int done;

    void func_000A4C30(unsigned int color, float step);
};

// Sets the target colour from a packed one (top byte first, each over 255), the step, and clears 0x1e0.
void Object_000A4D80::func_000A4C30(unsigned int color, float step)
{
    done = 0;
    target[0] = (color >> 24) * 0.003921569f;
    target[1] = (color >> 16 & 0xff) * 0.003921569f;
    target[2] = (color >> 8 & 0xff) * 0.003921569f;
    target[3] = (color & 0xff) * 0.003921569f;
    this->step = step;
}
