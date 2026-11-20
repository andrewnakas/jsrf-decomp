struct Object_00016200 {
    void func_000197E0(int *field, int base);
};

// Relocates a stored offset: adds the base to the word the first argument points to, unless the word is zero.
// The one caller (0x37a63, on the object at 0x22FCE8) passes a loaded block as both arguments.
void Object_00016200::func_000197E0(int *field, int base)
{
    if (*field) {
        *field += base;
    }
}
