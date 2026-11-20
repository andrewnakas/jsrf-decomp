int func_00118710(int handle);
int func_001186D0(int handle);

struct Object_000A1C50 {
    char unknown_000[0xc88];
    int handle;

    void func_000A1CF0();
};

// Releases the handle at 0xc88 through func_001186D0 and marks it unset (-1) when it is set and func_00118710
// reports it live.
void Object_000A1C50::func_000A1CF0()
{
    if (handle >= 0 && func_00118710(handle)) {
        func_001186D0(handle);
        handle = -1;
    }
}
