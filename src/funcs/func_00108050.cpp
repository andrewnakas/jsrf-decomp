struct Game {
    void *func_000128C0(int id);
};

struct Object_000FC4D0 {
    void func_000FC4D0(unsigned int mask, int set);
};

// The objects with ids 0x115e to 0x1162 (table 0x1D2020; func_00106C10 calls this on them).
struct Object_00107FE0 {
    char unknown_00[0x44];
    int ids[1]; // the count is not known here

    void func_00108050(int index, unsigned int mask, int set);
};

extern Game *data_0022FCE0;

// Sets or clears the mask (func_000FC4D0) in the object whose id is entry `index` of the list at 0x44, when it
// exists.
void Object_00107FE0::func_00108050(int index, unsigned int mask, int set)
{
    Object_000FC4D0 *target = (Object_000FC4D0 *)data_0022FCE0->func_000128C0(ids[index]);
    if (target) {
        target->func_000FC4D0(mask, set);
    }
}
