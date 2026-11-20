// The object 0x1ddc (table 0x1C4C88): a second colour as four channels from 0 to 1 at +0xbc, a scale at +0xcc and a
// flag at +0xd4.
struct Object_000239D0 {
    char unknown_00[0xbc];
    float red;
    float green;
    float blue;
    float alpha;
    float scale;
    char unknown_d0[4];
    int unknown_d4;

    void func_00023B90(int value, float scale);
};

// Called by func_00021F30 and ~Object_00022990: clears the flag at +0xd4 and splits the colour (bytes from the top)
// into the four channels at +0xbc, each divided by 255; keeps the scale at +0xcc.
void Object_000239D0::func_00023B90(int value, float scale)
{
    unknown_d4 = 0;
    red = (float)((unsigned int)value >> 24) * (1.0f / 255.0f);
    green = (float)(((unsigned int)value >> 16) & 0xff) * (1.0f / 255.0f);
    blue = (float)(((unsigned int)value >> 8) & 0xff) * (1.0f / 255.0f);
    alpha = (float)((unsigned int)value & 0xff) * (1.0f / 255.0f);
    this->scale = scale;
}
