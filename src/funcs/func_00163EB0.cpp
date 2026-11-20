// The system library's string compare (0 when equal).
int __stdcall func_0014807D(const char *left, const char *right);

struct Guid {
    unsigned long data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
};

// The objects in the vector at +0x118 (the devices found).
struct Item {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();

    char unknown_04[0x38];
    Guid id;
    char unknown_4c[0x108];
    char name[0x120];
    unsigned char type;
};

// The std::vector of pointers at +0x118.
struct ItemVector {
    char allocator;
    Item **first;
    Item **last;
    Item **end;
};

// The class whose table is at 0x1E19E0 (0x144 bytes).
struct Object_001E19E0 {
    virtual long __stdcall func_00163DB0(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00177FE0();
    virtual unsigned long __stdcall func_00163B90();
    virtual long __stdcall func_00165130(void *argument1, void *argument2);
    virtual long __stdcall func_001652E0(void *argument);
    virtual long __stdcall func_00164080(void *argument1, void *argument2, void *argument3);

    long __stdcall func_00163EB0(const char *name, unsigned char index, Item **found);
    long __stdcall func_00163F30(const Guid *id, unsigned char index, Item **found);
    long __stdcall func_00163FD0(unsigned long type, unsigned char index, Item **found);

    void *outer;
    long references;
    unsigned long unknown_0c;
    unsigned long block[0x41];
    unsigned long unknown_114;
    ItemVector items;
};

// Finds the device at `index` among those named `name` and gives it out with a reference added (a null object and
// 0x800710D8 when there is none).
long __stdcall Object_001E19E0::func_00163EB0(const char *name, unsigned char index, Item **found)
{
    long result = 0x800710D8;
    unsigned int number = 0;
    *found = 0;
    for (Item **entry = items.first; entry != items.last; entry++) {
        Item *item = *entry;
        if (item && func_0014807D(name, item->name) == 0) {
            if (number == index) {
                item->slot1();
                *found = item;
                result = 0;
                break;
            }
            number++;
        }
    }
    return result;
}
