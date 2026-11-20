struct Object_0006E130 {
    char unknown_00[0xfe8];
    unsigned int unknown_fe8;

    void func_0006E110(unsigned int value);
};

// Stores a value below 10 at +0xfe8 of the object at 0x252790.
void Object_0006E130::func_0006E110(unsigned int value)
{
    if (value < 10) {
        unknown_fe8 = value;
    }
}
