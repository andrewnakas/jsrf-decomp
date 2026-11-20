struct Unknown;

// The objects in the list at +0x10 of the MEvent class (table 0x1E4130): other events of the same class.
struct Listener;

// A std::vector of pointers.
struct ListenerList {
    void func_0017A330(Listener *const &value);

    char allocator;
    Listener **first;
    Listener **last;
    Listener **end;
};

// The MEvent class (table 0x1E4130).
struct Object_001E4130 {
    void func_0017A3A0(ListenerList *handles);

    void *vtable;
    Unknown *outer;
    long references;
    void *event;
    ListenerList listeners;
};

// Appends the event's handle at +0xc to `handles` (through the vector's append 0x17A330), then those of the events
// in its list, and theirs, depth first. Slot 5 (0x17A3E0) collects the handles this way into a local vector and waits
// on them.
void Object_001E4130::func_0017A3A0(ListenerList *handles)
{
    handles->func_0017A330(reinterpret_cast<Listener *const &>(event));
    for (Listener **entry = listeners.first; entry != listeners.last; ++entry) {
        if (*entry)
            ((Object_001E4130 *)*entry)->func_0017A3A0(handles);
    }
}
