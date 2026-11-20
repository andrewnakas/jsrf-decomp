int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);

struct Object_0006E130 {
    void func_0006E7B0(int texture);
};

extern Object_0006E130 data_00252790;

// Something a set owns (deleted through its virtual destructor).
struct Part_00035DC0 {
    virtual ~Part_00035DC0();
};

// A loaded set (0x38 bytes) of the list at +0x1680: its textures, blocks and parts, its file and its place in the list.
struct Set_00035DC0 {
    int key;
    int *textures;
    unsigned int textureCount;
    void *block_0c;
    char unknown_10[4];
    Part_00035DC0 **parts;
    unsigned int partCount;
    void *block_1c;
    char unknown_20[4];
    void *block_24;
    char unknown_28[4];
    void *buffer;
    Set_00035DC0 **link;
    Set_00035DC0 *next;
};

struct Object_000265A0 {
    char unknown_0000[0x1680];
    Set_00035DC0 *sets;
    Set_00035DC0 **tail;
    Set_00035DC0 *current;
    char unknown_168c[0xc];
    void *buffer;

    void func_00035DC0(int key);
};

// Handler 15 of the table at 0x1EC288: releases the set at +0x1688 (its blocks, parts, textures and file, each
// pointer cleared) and frees the buffer at +0x1698; then takes the set with `key` out of the list at +0x1680 (tail
// link at +0x1684), releases it the same way and deletes it.
void Object_000265A0::func_00035DC0(int key)
{
    if (current) {
        if (current->block_24) {
            delete current->block_24;
            current->block_24 = 0;
        }
        if (current->block_1c) {
            delete current->block_1c;
            current->block_1c = 0;
        }
        if (current->parts) {
            for (unsigned int i = 0; i < current->partCount; i++) {
                if (current->parts[i])
                    delete current->parts[i];
            }
            delete current->parts;
            current->parts = 0;
        }
        if (current->block_0c) {
            delete current->block_0c;
            current->block_0c = 0;
        }
        if (current->textures) {
            for (unsigned int i = 0; i < current->textureCount; i++)
                data_00252790.func_0006E7B0(current->textures[i]);
            delete current->textures;
            current->textures = 0;
        }
        if (current->buffer) {
            func_00145A5D(current->buffer, 0, 0x8000);
            current->buffer = 0;
        }
        delete current;
        current = 0;
        if (buffer) {
            func_00145A5D(buffer, 0, 0x8000);
            buffer = 0;
        }
    }
    for (Set_00035DC0 *set = sets; set; set = set->next) {
        if (set->key == key) {
            if (set->block_24) {
                delete set->block_24;
                set->block_24 = 0;
            }
            if (set->block_1c) {
                delete set->block_1c;
                set->block_1c = 0;
            }
            if (set->parts) {
                for (unsigned int i = 0; i < set->partCount; i++) {
                    if (set->parts[i])
                        delete set->parts[i];
                }
                delete set->parts;
                set->parts = 0;
            }
            if (set->block_0c) {
                delete set->block_0c;
                set->block_0c = 0;
            }
            if (set->textures) {
                for (unsigned int i = 0; i < set->textureCount; i++)
                    data_00252790.func_0006E7B0(set->textures[i]);
                delete set->textures;
                set->textures = 0;
            }
            if (set->buffer) {
                func_00145A5D(set->buffer, 0, 0x8000);
                set->buffer = 0;
            }
            *set->link = set->next;
            if (set->next)
                set->next->link = set->link;
            else
                tail = set->link;
            delete set;
            return;
        }
    }
}
