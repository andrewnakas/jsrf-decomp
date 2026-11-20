/* sym: ??1Object_0006A1B0@@UAE@XZ = 0x0006B270 */
void __cdecl operator delete(void *memory) throw();
int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);

struct Object_0006E130 {
    void func_0006E7B0(int id);
};

extern Object_0006E130 data_00252790;

struct Record_0006A1F0;
struct Slot_0006A1B0;
struct Parts_0006A1B0;

// What the slot table at +0x82c holds: deleted through its table.
struct Thing_0006B270 {
    virtual ~Thing_0006B270();
};

// The class whose table is at 0x1CC154 (destructor 0x6B270, deleting destructor 0x6C340).
struct Object_0006A1B0 {
    virtual ~Object_0006A1B0();
    void func_0006A1F0(int part);

    char unknown_004[0x10];
    Record_0006A1F0 *records;
    Slot_0006A1B0 *slots;
    void *pool;
    char unknown_020[0x80c];
    Thing_0006B270 *things[10][5];
    void *buffers[10][5];  // walked as things[50 + n]
    char unknown_9bc[0x190];
    void *pool2;
    int textures[40];
    unsigned int textureCount;
    int first[10];
    int second[10];
    char unknown_c44[4];
    Parts_0006A1B0 *parts;
};

// Frees the two pools (+0x1c, +0xb4c), deletes the 10x5 buffers and things, hands every texture id (+0xb50, the
// count at +0xbf0, then the two lists of ten at +0xbf4 and +0xc1c) back to object 0x252790, releases the 31 parts
// (func_0006A1F0) and deletes the records and the slots.
Object_0006A1B0::~Object_0006A1B0()
{
    if (pool) {
        func_00145A5D(pool, 0, 0x8000);
    }
    // One walk over both tables: each buffer is 50 slots after its thing.
    Thing_0006B270 **thing = things[0];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            if (thing[50]) {
                operator delete(thing[50]);
            }
            delete *thing;
            thing++;
        }
    }
    if (pool2) {
        func_00145A5D(pool2, 0, 0x8000);
    }
    for (unsigned int k = 0; k < textureCount; k++) {
        data_00252790.func_0006E7B0(textures[k]);
    }
    for (int m = 0; m < 10; m++) {
        if (first[m]) {
            data_00252790.func_0006E7B0(first[m]);
        }
        if (second[m]) {
            data_00252790.func_0006E7B0(second[m]);
        }
    }
    for (unsigned int part = 0; part < 0x1f; part++) {
        func_0006A1F0(part);
    }
    if (records) {
        operator delete(records);
    }
    if (slots) {
        operator delete(slots);
    }
}
