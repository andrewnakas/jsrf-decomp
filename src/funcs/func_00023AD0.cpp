// The object 0x1ddc (table 0x1C4C88): a colour as four channels from 0 to 1 at +0xac, the colour itself at +0xd0 and
// a flag at +0xd4.
struct Object_000239D0 {
    char unknown_00[0xac];
    float red;
    float green;
    float blue;
    float alpha;
    char unknown_bc[0x14];
    int colour;
    int unknown_d4;

    void func_00023AD0(int value);
};

// Called by func_00021F30 and ~Object_00022990: sets the flag at +0xd4 and splits the colour (bytes from the top)
// into the four channels at +0xac, each divided by 255; keeps the colour at +0xd0.
void Object_000239D0::func_00023AD0(int value)
{
    unknown_d4 = 1;
    red = (float)((unsigned int)value >> 24) * (1.0f / 255.0f);
    green = (float)(((unsigned int)value >> 16) & 0xff) * (1.0f / 255.0f);
    blue = (float)(((unsigned int)value >> 8) & 0xff) * (1.0f / 255.0f);
    alpha = (float)((unsigned int)value & 0xff) * (1.0f / 255.0f);
    colour = value;
}
