struct Resource {
    int unknown_00;
    unsigned long value;
};

// The base of the classes whose tables are at 0x1E10E8, 0x1E1150 (created by 0x14D800) and 0x1E11B8 (created by 0x14D8E0).
struct Object_001E10E8 {
    virtual long __stdcall func_00156030(unsigned long *value, unsigned long unused);  // slot 6

    char unknown_04[4];
    Resource *resource;
};

long __stdcall Object_001E10E8::func_00156030(unsigned long *value, unsigned long unused)
{
    *value = resource->value;
    return 0;
}
