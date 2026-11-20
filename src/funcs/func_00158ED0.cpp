// The base of the classes whose tables are at 0x1E1598, 0x1E15C0 and 0x1E15E8 (created by 0x158F00).
struct Object_001E1598 {
    virtual void __stdcall func_00158ED0(float value);  // slot 8

    char unknown_04[8];
    float value;
};

void __stdcall Object_001E1598::func_00158ED0(float value)
{
    this->value = value;
}
