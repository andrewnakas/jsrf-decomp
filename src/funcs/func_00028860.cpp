int func_00118BA0(unsigned int id);
void func_00036F10(int id);
int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);

struct Object_0006E130 {
    void func_0006E7B0(int texture);
};

extern Object_0006E130 data_00252790;

// An object a slot owns: deleted through its virtual destructor.
struct Part_00031360 {
    virtual ~Part_00031360();
};

// A loaded slot (0x30 bytes, from +0x278).
struct Slot_00031360 {
    Part_00031360 **parts;
    unsigned int partCount;
    void *data;
    int unknown_0c;
    int *textures;
    unsigned int textureCount;
    void *first;
    int unknown_1c;
    void *second;
    char unknown_24[0x4];
    void *block;
    int loaded;
};

// Per slot: the ids handed to func_00036F10 and func_00118BA0 when it is released.
extern int data_001EC430[];
extern int data_001EC3D0[];

// Object 7.
struct Object_000265A0 {
    char unknown_000[0x278];
    Slot_00031360 slots[1];

    void func_00028860(int index);
};

// Entry 5 of the table at 0x1EC288: releases slot `index` (from +0x278): clears its loaded flag, frees its buffers
// (+0x20, +0x18, +0x8), deletes its parts and their list, releases its textures through data_00252790 and frees their
// list, returns the block at +0x28 (func_00145A5D), then runs func_00036F10 and func_00118BA0 with the slot's ids.
void Object_000265A0::func_00028860(int index)
{
    Slot_00031360 *slot = &slots[index];
    slot->loaded = 0;
    if (slot->second) {
        operator delete(slot->second);
        slot->second = 0;
    }
    if (slot->first) {
        operator delete(slot->first);
        slot->first = 0;
    }
    if (slot->data) {
        operator delete(slot->data);
        slot->data = 0;
    }
    if (slot->parts) {
        for (unsigned int k = 0; k < slot->partCount; k++)
            delete slot->parts[k];
        operator delete(slot->parts);
        slot->parts = 0;
    }
    if (slot->textures) {
        for (unsigned int t = 0; t < slot->textureCount; t++)
            data_00252790.func_0006E7B0(slot->textures[t]);
        operator delete(slot->textures);
        slot->textures = 0;
    }
    if (slot->block) {
        func_00145A5D(slot->block, 0, 0x8000);
        slot->block = 0;
    }
    func_00036F10(data_001EC430[index]);
    func_00118BA0(data_001EC3D0[index]);
}
