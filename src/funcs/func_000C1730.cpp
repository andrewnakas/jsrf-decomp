struct Game {
    char unknown_0000[0x87f0];
    int value_87f0;

    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_0006DB80 {
    void func_0006DF30(int key);
};

extern Object_0006DB80 data_00251F78;

void func_00106FF0(unsigned int id, int key, int which);

// The object in data_00257CE8 (its callers load `ecx` from there; this function does not read it).
struct Object_00157F10 {
    void func_000C1730(int *handle);
};

// Releases a set handle: func_00106FF0 with 0x87f0 of data_0022FCE0, the handle and 3, then func_0006DF30 of
// data_00251F78; the handle becomes -1.
void Object_00157F10::func_000C1730(int *handle)
{
    if (*handle != -1) {
        func_00106FF0(data_0022FCE0->value_87f0, *handle, 3);
        data_00251F78.func_0006DF30(*handle);
        *handle = -1;
    }
}
