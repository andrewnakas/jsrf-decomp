struct Pair {
    unsigned long first;
    unsigned long second;
};

long __stdcall func_0018E750(void *object, Pair *pair, unsigned long third, unsigned long fourth);

// The base of the classes whose tables are at 0x1E1290 (destructor 0x152690), 0x1E1298, 0x1E12B8 and 0x1E12D8
// (created by 0x152BC0); all four share this QueryInterface.
struct Object_001E1290 {
    virtual long __stdcall func_00152360(const void *iid, void **object);  // slot 0

    void *object;
};

// The class whose table is at 0x1E1298 (created by 0x152BC0).
struct Object_001E1298 : Object_001E1290 {
    virtual long __stdcall func_00152740(unsigned long *second, unsigned long *first, unsigned long unused);  // slot 4
};

// Asks func_0018E750 for the pair of values of the object at +4 and gives back the ones asked for.
long __stdcall Object_001E1298::func_00152740(unsigned long *second, unsigned long *first, unsigned long unused)
{
    Pair pair;

    func_0018E750(object, &pair, 0, 0);
    if (second)
        *second = pair.second;
    if (first)
        *first = pair.first;
    return 0;
}
