int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);

struct Object_0006E130 {
    void func_0006E7B0(int texture);
};

extern Object_0006E130 data_00252790;

// Something a set owns (deleted through its virtual destructor).
struct Part_000352D0 {
    virtual ~Part_000352D0();
};

// A device object a set holds (slot 2 releases it).
struct Device_000352D0 {
    virtual unsigned long __stdcall QueryInterface();
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};

// A loaded set: its textures, blocks and parts, its file and a device object.
struct Set_000352D0 {
    int *textures;
    unsigned int textureCount;
    void *block_08;
    char unknown_0c[4];
    Part_000352D0 **parts;
    unsigned int partCount;
    void *block_18;
    char unknown_1c[4];
    void *buffer;
    Device_000352D0 *device;
};

struct Object_000265A0 {
    char unknown_0000[0x15fc];
    Set_000352D0 *other;
    Set_000352D0 *current;
    char unknown_1604[8];
    void *buffer;

    void func_000352D0(int key);
};

// Handler 10 of the table at 0x1EC288: releases the set at +0x1600 (its blocks, parts and textures with their
// pointers cleared, its file freed with func_00145A5D, its device object released), deletes it and frees the buffer at
// +0x160c; then releases and deletes the set at +0x15fc the same way. The key is not used.
void Object_000265A0::func_000352D0(int)
{
    if (current) {
        if (current->block_18) {
            delete current->block_18;
            current->block_18 = 0;
        }
        if (current->parts) {
            for (unsigned int i = 0; i < current->partCount; i++) {
                if (current->parts[i])
                    delete current->parts[i];
            }
            delete current->parts;
            current->parts = 0;
        }
        if (current->block_08) {
            delete current->block_08;
            current->block_08 = 0;
        }
        if (current->textures) {
            for (unsigned int i = 0; i < current->textureCount; i++)
                data_00252790.func_0006E7B0(current->textures[i]);
            delete current->textures;
            current->textures = 0;
        }
        if (current->buffer)
            func_00145A5D(current->buffer, 0, 0x8000);
        if (current->device)
            current->device->Release();
        delete current;
        current = 0;
        if (buffer) {
            func_00145A5D(buffer, 0, 0x8000);
            buffer = 0;
        }
    }
    if (other) {
        if (other->block_18) {
            delete other->block_18;
            other->block_18 = 0;
        }
        if (other->parts) {
            for (unsigned int i = 0; i < other->partCount; i++) {
                if (other->parts[i])
                    delete other->parts[i];
            }
            delete other->parts;
            other->parts = 0;
        }
        if (other->block_08) {
            delete other->block_08;
            other->block_08 = 0;
        }
        if (other->textures) {
            for (unsigned int i = 0; i < other->textureCount; i++)
                data_00252790.func_0006E7B0(other->textures[i]);
            delete other->textures;
            other->textures = 0;
        }
        if (other->buffer)
            func_00145A5D(other->buffer, 0, 0x8000);
        if (other->device)
            other->device->Release();
        delete other;
        other = 0;
    }
}
