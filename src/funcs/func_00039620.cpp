int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);

struct Object_0006E130 {
    void func_0006E7B0(int id);
};

extern Object_0006E130 data_00252790;

// Something object 7 keeps a list of: deleted through its virtual destructor.
struct Item_00039620 {
    virtual ~Item_00039620();
};

struct Object_000265A0 {
    char unknown_0000[0x174c];
    Item_00039620 **items;
    unsigned int itemCount;
    char *buffer1754;
    char unknown_1758[4];
    int *textures;
    unsigned int textureCount;
    char *buffer1764;
    char unknown_1768[4];
    void *block176c;
    int unknown_1770;
    char unknown_1774[0x24];
    void *block1798;

    void func_00039620(int argument);
};

// Handler 20 of the table at 0x1EC288: clears +0x1770 and frees what it loaded: the buffers at +0x1764 and +0x1754,
// the items at +0x174c (each through its destructor) and their list, the textures at +0x175c (func_0006E7B0 of
// 0x252790) and their list, and the blocks at +0x1798 and +0x176c (func_00145A5D).
void Object_000265A0::func_00039620(int)
{
    unknown_1770 = 0;
    if (buffer1764) {
        delete buffer1764;
        buffer1764 = 0;
    }
    if (buffer1754) {
        delete buffer1754;
        buffer1754 = 0;
    }
    if (items) {
        for (unsigned int i = 0; i < itemCount; i++) {
            delete items[i];
        }
        delete items;
        items = 0;
    }
    if (textures) {
        for (unsigned int j = 0; j < textureCount; j++) {
            data_00252790.func_0006E7B0(textures[j]);
        }
        delete textures;
        textures = 0;
    }
    if (block1798) {
        func_00145A5D(block1798, 0, 0x8000);
        block1798 = 0;
    }
    if (block176c) {
        func_00145A5D(block176c, 0, 0x8000);
        block176c = 0;
    }
}
