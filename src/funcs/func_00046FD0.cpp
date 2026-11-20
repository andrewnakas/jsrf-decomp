// The device type the XPP library's func_001BD5FF counts (memory units); it lies in a code section.
extern char data_001BC7E0[];

// "JSRFDATA.SAV"
extern char data_001F9668[];

unsigned long __stdcall func_001BD5FF(void *type);
int __stdcall func_0014646E(const char *path, unsigned __int64 *available, unsigned __int64 *total,
                            unsigned __int64 *free);

struct Object_00039BE0 {
    int func_0003A910();
};

extern Object_00039BE0 data_001EFFB0;

// A 64-bit byte count as GetDiskFreeSpaceEx reports it.
union Size_00046FD0 {
    unsigned __int64 quad;
    struct {
        unsigned long low;
        unsigned long high;
    };
};

// One storage slot as func_00047080 fills it in (0x50 bytes).
struct Slot_00047080 {
    int present;
    int formatted;
    int space;
    int saved;
    short unknown_10;
    char unknown_12[0x3e];
};

struct Object_00047110 {
    int func_00046C40(char drive, const char *name);
    int func_00046FD0(int index, Slot_00047080 *slot);
};

// Clears the slot; for slot 8 (the hard disk, drive U) marks it present and formatted, notes whether the free space
// holds the save (func_0003A910 * 3 + 0x8060 bytes) and whether "JSRFDATA.SAV" is there (func_00046C40). Returns 0.
int Object_00047110::func_00046FD0(int index, Slot_00047080 *slot)
{
    slot->present = 0;
    slot->formatted = 0;
    slot->space = 0;
    slot->saved = 0;
    slot->unknown_10 = 0;
    if (index == 8) {
        func_001BD5FF(data_001BC7E0);
        slot->present = 1;
        slot->formatted = 1;
        char path[] = "X:\\";
        unsigned int needed = data_001EFFB0.func_0003A910() * 3 + 0x8060;
        Size_00046FD0 available;
        Size_00046FD0 total;
        Size_00046FD0 free;
        path[0] = 'U';
        if (func_0014646E(path, &available.quad, &total.quad, &free.quad) &&
            (available.high > 0 || available.low >= needed)) {
            slot->space = 1;
        }
        slot->saved = func_00046C40('U', data_001F9668);
    }
    return 0;
}
