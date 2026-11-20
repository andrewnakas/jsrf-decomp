/* sym: ??1Object_000CFB70@@UAE@XZ = 0x000CFC70 */
struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    void func_00060810(int key);
};

struct Object_00016200 {
    void func_00019760(void *pointer);
};

extern Object_00016200 data_0022FCE8;

// A resource with a COM-style table: slot 2 releases it.
struct Interface_000CFB70 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
};

// One of the ten entries at 0x1c40 (0x24 bytes each).
struct Entry_000CFB70 {
    char unknown_00[8];
    void *item;
    char unknown_0c[0x18];
};

// A part of func_000D01A0's object (table 0x1CE3F8, constructor func_000CFB70): slot 0 is the destructor.
struct Object_000CFB70 {
    virtual ~Object_000CFB70();

    char unknown_0004[0x1c34];
    int key;
    char unknown_1c3c[4];
    Entry_000CFB70 entries[10];
    Interface_000CFB70 *resource;
};

// Hands its key at 0x1c38, when set, to object 0xe8 (func_00060810), releases the resource at 0x1da8 and hands the
// ten entries' items (0x1c48) that are there to func_00019760 of data_0022FCE8.
Object_000CFB70::~Object_000CFB70()
{
    if (key >= 0) {
        Object_000607B0 *target = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
        if (target) {
            target->func_00060810(key);
        }
    }
    if (resource) {
        resource->slot2();
    }
    for (int i = 0; i < 10; i++) {
        if (entries[i].item) {
            data_0022FCE8.func_00019760(entries[i].item);
        }
    }
}
