extern "C" void *__cdecl memset(void *destination, int value, unsigned int size);
extern "C" void *__cdecl memcpy(void *destination, const void *source, unsigned int size);

// VirtualAlloc (address, size, allocation type, protection), CreateFile (name, access, share, security, creation,
// flags, template) and ReadFile (file, buffer, size, done, overlapped).
void *__stdcall func_00145A2F(void *address, unsigned long size, unsigned long type, unsigned long protect);
void *__stdcall func_001455A3(const char *name, unsigned long access, unsigned long share, void *security,
                              unsigned long creation, unsigned long flags, void *pattern);
int __stdcall func_00145F8B(void *file, void *buffer, unsigned long size, unsigned long *done, void *overlapped);
// Reads up to a size from a file and returns the count read; closes a file.
unsigned long func_00024340(void *file, void *buffer, unsigned long size);
void func_00024370(void *handle);

// A class whose table is at 0x1E141C (12 slots; Release 0x1579A0).
struct Object_001E141C {
    virtual long __stdcall func_001577C0(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_001576F0();  // slot 1
    virtual unsigned long __stdcall func_001579A0();  // slot 2
    virtual long __stdcall func_00157800(unsigned long first, unsigned long second, unsigned long third);  // slot 3
    virtual void __stdcall func_00157960();  // slot 4

    char unknown_04[0x1024];
    void *memory;
    unsigned long count;
};

// Committed, cleared memory.
static inline void *Allocate(unsigned long size)
{
    void *memory = func_00145A2F(0, size, 0x3000, 4);
    if (memory)
        memset(memory, 0, size);
    return memory;
}

// Slot 3: takes second entries of 0x48 bytes (keeping the memory when the count is the same, else freeing it
// through slot 4 and making new) and fills them from first: a copy of memory (third 1), the file of that name
// (2) or the open file (4). E_OUTOFMEMORY; E_FAIL when a file is short or missing and E_INVALIDARG for another
// kind, both after freeing the memory.
long __stdcall Object_001E141C::func_00157800(unsigned long first, unsigned long second, unsigned long third)
{
    unsigned long size = second * 0x48;
    void *data;
    if (count == second) {
        data = memory;
    } else {
        func_00157960();
        data = Allocate(size);
    }
    if (data) {
        memory = data;
        count = second;
        switch (third) {
        case 1:
            memcpy(data, (const void *)first, size);
            break;
        case 2: {
            void *file = func_001455A3((const char *)first, 0x80000000, 0, 0, 3, 0x80, 0);
            if (file != (void *)-1) {
                if (func_00024340(file, data, size) == size) {
                    func_00024370(file);
                    return 0;
                }
                func_00024370(file);
            }
            func_00157960();
            return 0x80004005;
        }
        case 4: {
            unsigned long done = 0;
            func_00145F8B((void *)first, data, size, &done, 0);
            if (done != size) {
                func_00157960();
                return 0x80004005;
            }
            break;
        }
        default:
            func_00157960();
            return 0x80070057;
        }
        return 0;
    }
    return 0x8007000e;
}
