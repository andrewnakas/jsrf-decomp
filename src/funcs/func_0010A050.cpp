struct Game {
    void *func_000128C0(int id);
};

// The objects with ids 0x115e to 0x1162 (table 0x1D2020; func_001084E0 reads 0x16b8 as func_00108640 does).
struct Object_00107FE0 {
    int func_001084E0(int index);
};

// The child of Node whose table has func_0010A0E0 as slot 1 (destructor func_00109B60).
struct Object_00109B60 {
    char unknown_00[0x74];
    int value;
    int current;
    int target;
    char unknown_80[0xc];
    int state;
    int unknown_90;
    int unknown_94;
    int unknown_98;
    int unknown_9c;
    int unknown_a0;
    char unknown_a4[0x10];
    int owner_id;

    void func_0010A050();
};

extern Game *data_0022FCE0;

// Reads entry 12 (func_001084E0) of the 0x115e-range object whose id is at 0xb4 into 0x74; when it changed: state 3
// with the target set and 0x94-0xa0 cleared for a value of at least 0, state 7 otherwise.
void Object_00109B60::func_0010A050()
{
    Object_00107FE0 *owner = (Object_00107FE0 *)data_0022FCE0->func_000128C0(owner_id);
    value = owner->func_001084E0(12);
    if (current != value) {
        if (value >= 0) {
            unknown_94 = 0;
            unknown_98 = 0;
            unknown_9c = 0;
            unknown_a0 = 0;
            state = 3;
            target = value;
        } else {
            state = 7;
        }
        current = value;
    }
}
