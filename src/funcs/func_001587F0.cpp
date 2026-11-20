// The base of the classes whose tables are at 0x1E14D8, 0x1E1508, 0x1E1538 and 0x1E1568 (created by 0x158A80).
struct Object_001E14D8 {
    virtual void __stdcall func_001587F0(float value, unsigned long unused);  // slot 8

    char unknown_04[0x108];
    float value;
};

void __stdcall Object_001E14D8::func_001587F0(float value, unsigned long unused)
{
    this->value = value;
}
