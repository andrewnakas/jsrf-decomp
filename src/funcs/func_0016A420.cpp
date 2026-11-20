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
    virtual long __stdcall slot18(void *argument);
};

// A std::vector of pointers.
struct BufferList {
    // The vector's iterator: a class around the pointer.
    struct iterator {
        Buffer **pointer;

        iterator(Buffer **pointer) : pointer(pointer)
        {
        }
        Buffer *&operator*() const
        {
            return *pointer;
        }
        iterator operator++(int)
        {
            iterator old = *this;
            ++pointer;
            return old;
        }
        iterator &operator++()
        {
            ++pointer;
            return *this;
        }
        iterator operator+(int count) const
        {
            return iterator(pointer + count);
        }
        bool operator!=(const iterator &other) const
        {
            return pointer != other.pointer;
        }
    };

    char allocator;
    Buffer **first;
    Buffer **last;
    Buffer **end;

    iterator begin()
    {
        return iterator(first);
    }
    iterator finish()
    {
        return iterator(last);
    }
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
    virtual long __stdcall slot7(unsigned int index, Buffer **buffer);
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
    virtual long __stdcall func_0016A420(unsigned int index, void *argument);

    void *outer;
    long references;
    Sound *sound;
    BufferList buffers;
};

// Slot 23: passes the argument on to slot 18 of entry `index` of the list at +0x10 (taken with slot 7), or of every
// entry after the first for index -1. 0x800401F0 (not initialised) without the DirectSound object at +0xc.
long __stdcall Object_001E3B00::func_0016A420(unsigned int index, void *argument)
{
    long result;
    if (sound) {
        if (index == 0xFFFFFFFF) {
            for (BufferList::iterator entry = buffers.begin() + 1; entry != buffers.finish(); ) {
                Buffer *buffer = *entry++;
                if (buffer)
                    buffer->slot18(argument);
            }
            result = 0;
        } else {
            Buffer *buffer;
            result = slot7(index, &buffer);
            if (result >= 0) {
                result = buffer->slot18(argument);
                if (buffer)
                    buffer->slot2();
            }
        }
    } else {
        result = 0x800401F0;
    }
    return result;
}
