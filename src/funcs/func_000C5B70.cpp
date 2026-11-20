int func_00118710(int handle);

// The owner at 0x4 of the Object_000CC600 family.
struct Object_000C5B50 {
    int func_000C5B70(int handle);
};

// Asks func_00118710 about a handle; 0 for a negative (unset) handle. func_000D7950 calls this with an
// object in ecx, which is not used.
int Object_000C5B50::func_000C5B70(int handle)
{
    if (handle >= 0) {
        return func_00118710(handle);
    }
    return 0;
}
