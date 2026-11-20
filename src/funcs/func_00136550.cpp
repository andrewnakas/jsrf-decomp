struct Object_00136270 {
    char unknown_00[0x44];
    unsigned long port;
    unsigned long slot;
    bool mounted;

    void func_00136550();
};

unsigned long __stdcall func_001BE8ED(unsigned long first, unsigned long second);

// When the flag at +0x4c is set, passes the two words at +0x44 and +0x48 to the library function func_001BE8ED
// and clears all three.
void Object_00136270::func_00136550()
{
    if (mounted) {
        func_001BE8ED(port, slot);
        port = 0;
        slot = 0;
        mounted = false;
    }
}
