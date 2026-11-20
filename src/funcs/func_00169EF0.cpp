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
    Buffer **begin()
    {
        return first;
    }
    Buffer **end_()
    {
        return last;
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
    unsigned int size() const
    {
        return first == 0 ? 0 : last - first;
    }

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
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual long __stdcall func_00169EF0(void *group, void *argument);

    void *outer;
    long references;
    Sound *sound;
    BufferList buffers;
    GroupList groups;
};

// Slot 26: passes `argument` to slot 7 of every object of list `group` of the lists at +0x20; E_FAIL without that list.
long __stdcall Object_001E3B00::func_00169EF0(void *group, void *argument)
{
    unsigned int i = (unsigned int)group;
    if (i < groups.size()) {
        BufferList *const &lists = groups.first;
        for (Buffer **entry = lists[i].first; entry != lists[i].last; ++entry)
            (*entry)->slot7(argument);
        return 0;
    }
    return 0x80004005;
}
