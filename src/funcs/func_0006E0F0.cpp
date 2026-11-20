struct Object_0006E0F0 {
    char unknown_00[0xfe4];
    unsigned int unknown_fe4;

    void func_0006E0F0(unsigned int value);
};

// Stores a value below 10 at +0xfe4.
void Object_0006E0F0::func_0006E0F0(unsigned int value)
{
    if (value < 10) {
        unknown_fe4 = value;
    }
}
