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

// What +0x4 points at: slot 3 makes a handle for a buffer, slot 4 one for a colour.
struct Maker_00047410 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual int __stdcall slot3(int kind, Buffer_00047230 *buffer, int unknown);
    virtual int __stdcall slot4(unsigned int colour, int value, Buffer_00047230 *buffer, int unknown);
};

extern int data_0020C39C[];

struct Object_00048180 {
    int unknown_00;
    Maker_00047410 *maker;
    char unknown_08[0x10];
    int unknown_18;
    char unknown_1c[8];
    unsigned int flags;
    float red;
    float green;
    float blue;
    float alpha;
    int unknown_38;

    void func_00047230(Group_00047230 *group, Out_00047230 *out);
    void func_00047480(int unused, Group_00047230 *group, Out_00047230 *out, int unknown);
};

// As func_00047410 (with flag 0x10 instead): has slot 3 of +0x4 make a handle for the group's buffer into `out` and
// copies the group's parts into `out` (func_00047230); then slot 4 makes the second handle from the colour at +0x28
// (red, green, blue, alpha from 0 to 1, packed as A8R8G8B8) and +0x38.
void Object_00048180::func_00047480(int unused, Group_00047230 *group, Out_00047230 *out, int unknown)
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
    func_00047230(group, out);
    unsigned int colour = (int)(alpha * 255.0f);
    colour = colour << 8 | (int)(red * 255.0f);
    colour = colour << 8 | (int)(green * 255.0f);
    colour = colour << 8 | (int)(blue * 255.0f);
    out->unknown_04 = maker->slot4(colour, unknown_38, buffer, unknown);
}
