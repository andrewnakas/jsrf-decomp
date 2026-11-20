// What a group draws from: a word at +0x8 used as a kind.
struct Buffer_00047230 {
    int unknown_00;
    unsigned int size;
    int kind;
};

struct Group_00047230 {
    Buffer_00047230 *buffer;
};

struct Out_00047230 {
    int handle;
    int unknown_04;
};

// What +0x4 points at: slot 3 makes a handle for a buffer.
struct Maker_00047410 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual int __stdcall slot3(int kind, Buffer_00047230 *buffer, int unknown);
};

extern int data_0020C39C[];

struct Object_00048180 {
    int unknown_00;
    Maker_00047410 *maker;
    char unknown_08[0x10];
    int unknown_18;
    char unknown_1c[8];
    unsigned int flags;

    void func_00047230(Group_00047230 *group, Out_00047230 *out);
    void func_00047410(int unused, Group_00047230 *group, Out_00047230 *out, int unknown);
};

// Has slot 3 of +0x4 make a handle for the group's buffer into `out` (kind: entry +0x18 of the table at 0x20C39C with
// flag 2, 0x112 with flag 0x40, else the buffer's own), clears the word after it and copies the group's parts into
// `out` (func_00047230). The first argument is not used.
void Object_00048180::func_00047410(int unused, Group_00047230 *group, Out_00047230 *out, int unknown)
{
    Buffer_00047230 *buffer = group->buffer;
    int handle;
    if (flags & 2)
        handle = maker->slot3(data_0020C39C[unknown_18], buffer, unknown);
    else if (flags & 0x40)
        handle = maker->slot3(0x112, buffer, unknown);
    else
        handle = maker->slot3(buffer->kind, buffer, unknown);
    out->handle = handle;
    out->unknown_04 = 0;
    func_00047230(group, out);
}
