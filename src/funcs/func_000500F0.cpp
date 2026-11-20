struct Game {
    int func_000127E0(int index);
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_00080010 {
    int func_00080010();
};

// The object the slot points at: the id of another object at +0x8d4.
struct Holder_000500F0 {
    char unknown_000[0x8d4];
    int target;
};

// Object 0x12ac (destructor 0x4FBC0): ids at +0x88c (with their count) and the slots they stand for at +0x894.
struct Object_0004FC40 {
    char unknown_000[0x88c];
    int *ids;
    unsigned int count;
    int *slots;

    // The index of the game's value 0x1ac among the ids at +0x88c, or 0 when it is not there.
    unsigned int func_0004FC40()
    {
        int id = data_0022FCE0->func_000127E0(0x1ac);
        for (unsigned int i = 0; i < count; i++) {
            if (ids[i] == id) {
                return i;
            }
        }
        return 0;
    }

    int func_000500F0();
};

// Takes the slot of the current id (func_0004FC40); when it is not negative, object 0xc plus the slot names an object
// whose +0x8d4 names another, and the answer is func_00080010 of that one. 0 when any of them is missing.
int Object_0004FC40::func_000500F0()
{
    int slot = slots[func_0004FC40()];
    if (slot >= 0) {
        Holder_000500F0 *holder = (Holder_000500F0 *)data_0022FCE0->func_000128C0(slot + 0xc);
        if (holder) {
            Object_00080010 *object = (Object_00080010 *)data_0022FCE0->func_000128C0(holder->target);
            if (object) {
                return object->func_00080010();
            }
        }
    }
    return 0;
}
