int func_001186D0(int handle);

struct Object_000C5B50 {
    void func_000C5B50(int *handle);
};

// Releases a handle through func_001186D0 and marks it unset (-1). func_000CC680 calls this with an object in
// ecx, which is not used.
void Object_000C5B50::func_000C5B50(int *handle)
{
    if (*handle >= 0) {
        func_001186D0(*handle);
        *handle = -1;
    }
}
