void __cdecl operator delete(void *memory) throw();

struct Guid;
struct Sound;

// The objects in the voice's list at +0x10 (slot 7 of the voice gives them out; slot 2 lets go of one).
struct Buffer {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual long __stdcall slot7(void *argument);
};

// The allocator of a vector, and the empty tag the library passes by value to its helpers.
struct Allocator {
};

struct Tag {
};

// A std::vector of pointers.
struct BufferList {
    unsigned int size() const
    {
        return first == 0 ? 0 : last - first;
    }
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
    virtual long __stdcall func_00169E90(void *index, void *object);

    void *outer;
    long references;
    Sound *sound;
    BufferList buffers;
    GroupList groups;
};

// Slot 7: gives out the object at `index` of the list at +0x10 with a reference added; 0x800710D8 (and a null object)
// when there is none there. 0x800401F0 (not initialised) without the DirectSound object.
long __stdcall Object_001E3B00::func_00169E90(void *index, void *object)
{
    if (sound) {
        Buffer **result = (Buffer **)object;
        if (result) {
            unsigned int i = (unsigned int)index;
            if (i < buffers.size() && buffers.first[i]) {
                Buffer *buffer = buffers.first[i];
                buffer->slot1();
                *result = buffer;
                return 0;
            }
            *result = 0;
        }
        return 0x800710D8;
    }
    return 0x800401F0;
}
