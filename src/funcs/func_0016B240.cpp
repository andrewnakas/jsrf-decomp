void __cdecl operator delete(void *memory) throw();

struct Guid;
struct Sound;

// The objects in the voice's list at +0x10 (slot 7 of the voice gives them out; slot 2 lets go of one).
struct Buffer;

// The allocator of a vector, and the empty tag the library passes by value to its helpers.
struct Allocator {
};

struct Tag {
};

// A std::vector of pointers.
struct BufferList {
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
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual long __stdcall func_0016B240(void *buffer);

    void *outer;
    long references;
    Sound *sound;
    BufferList buffers;
    GroupList groups;
};

// Slot 11: clears the place of the object in the first of the lists at +0x20 that holds it; without an object, empties
// the lists at +0x20 altogether. Always S_OK.
long __stdcall Object_001E3B00::func_0016B240(void *buffer)
{
    if (buffer) {
        for (BufferList *list = groups.first; list != groups.last; ++list) {
            for (Buffer **entry = list->first; entry != list->last; ++entry) {
                if (*entry == buffer) {
                    *entry = 0;
                    return 0;
                }
            }
        }
    } else {
        groups.tidy();
    }
    return 0;
}
