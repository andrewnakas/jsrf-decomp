struct Object_000BFF60 {
    void *data;
    char unknown_04[0x18];
};

struct Object_000C05A0 {
    void func_000C05A0(void *data);
};

// The object func_000C04D0 allocates (0x1c bytes) and func_000BFF60 constructs.
extern Object_000BFF60 *data_00257CE0;

// Sets the data pointer of the object in data_00257CE0 when there is one. The callers (func_000585E0) pass
// an object in ecx, which is not used.
void Object_000C05A0::func_000C05A0(void *data)
{
    if (data_00257CE0) {
        data_00257CE0->data = data;
    }
}
