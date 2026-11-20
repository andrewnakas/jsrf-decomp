void __cdecl operator delete(void *memory) throw();

struct Guid;
struct Sound;

// The objects in the voice's list at +0x10 (slot 7 of the voice gives them out; slot 2 lets go of one).
struct Buffer {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

// The allocator of a vector, and the empty tag the library passes by value to its helpers.
struct Allocator {
};

struct Tag {
};

// A std::vector of pointers.
struct BufferList {
    // Frees the block and leaves the vector empty.
    void tidy()
    {
        if (first)
            operator delete(first);
        first = 0;
        last = 0;
        end = 0;
    }

    Allocator allocator;
    Buffer **first;
    Buffer **last;
    Buffer **end;
};

// Destroys the lists from `first` up to `last`.
void func_0016AC50(BufferList *first, BufferList *last, Allocator &, Tag);

// A std::vector of those lists.
struct GroupList {
    // Destroys the lists, frees the block and leaves the vector empty.
    void tidy()
    {
        if (first) {
            func_0016AC50(first, last, allocator, Tag());
            operator delete(first);
        }
        first = 0;
        last = 0;
        end = 0;
    }

    Allocator allocator;
    BufferList *first;
    BufferList *last;
    BufferList *end;
};

// The class whose table is at 0x1E3B00: the voices MGameSound8 makes (0x30 bytes).
struct Object_001E3B00 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual long __stdcall func_0016A5C0(void *buffer);
    virtual void slot9();
    virtual void slot10();
    virtual long __stdcall func_0016B240(void *buffer);

    void *outer;
    long references;
    Sound *sound;
    BufferList buffers;
    GroupList groups;
};

// Slot 8: lets go of the object: takes it out of the lists at +0x20 (slot 11), then releases it and clears its place
// in the list at +0x10 (0x800710D8 if it is not there). Without an object, releases every object of that list and
// frees it (slot 11 empties the lists at +0x20). 0x800401F0 (not initialised) without the DirectSound object.
long __stdcall Object_001E3B00::func_0016A5C0(void *buffer)
{
    long result;
    if (sound) {
        func_0016B240(buffer);
        if (buffer) {
            result = 0x800710D8;
            for (Buffer **entry = buffers.first; entry != buffers.last; ++entry) {
                if (*entry == buffer) {
                    if (*entry) {
                        (*entry)->slot2();
                        *entry = 0;
                    }
                    result = 0;
                    break;
                }
            }
        } else {
            for (Buffer **entry = buffers.first; entry != buffers.last; ++entry) {
                if (*entry) {
                    (*entry)->slot2();
                    *entry = 0;
                }
            }
            buffers.tidy();
            result = 0;
        }
    } else {
        result = 0x800401F0;
    }
    return result;
}
