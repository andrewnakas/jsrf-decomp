struct Object_00070530 {
    void func_00070530(int first, int second, int value);
};

struct Object_00070850 {
    char unknown_000[0xe4];
    int value_e4;
    char unknown_0e8[0x3fc];
    int ids[4];

    int func_0006FE00(int *index);
    int func_00070870(int index);
    int func_00070890(int index);
};

struct Node {
    Node *func_00011BD0();
};

struct Game {
    void *func_000128C0(int id);
};

struct Object_00119C00 {
    char unknown_00[0x48];
    int first;
    int second;
    int value;
    char unknown_54[8];
    int value_5c;
    int value_60;

    void func_00119950(int value, int target);
    void func_00119C20();
};

extern Game *data_0022FCE0;
int func_00119540(int group, int index, void *position);

// Unless a value is set at +0x50: when the owner's entry is free (func_00070890), takes it (func_00070530 in
// mode 1), hands the value at +0x60 on to the object of a free owner slot (func_0006FE00, func_00119950) when the
// owner expects it, and plays the entry's sound (group 0x38); when it is not free, plays entry 5 of group 8.
void Object_00119C00::func_00119C20()
{
    int index;
    if (!value) {
        Object_00070850 *owner = (Object_00070850 *)((Node *)this)->func_00011BD0();
        if (!owner->func_00070890(second)) {
            value = 1;
            ((Object_00070530 *)owner)->func_00070530(first, second, 1);
            if (value_60 == owner->value_e4 && owner->func_0006FE00(&index)) {
                Object_00119C00 *partner = (Object_00119C00 *)data_0022FCE0->func_000128C0(owner->ids[index]);
                partner->func_00119950(value_60, first);
                value_5c = 1;
            }
            func_00119540(0x38, owner->func_00070870(second), 0);
        } else {
            func_00119540(8, 5, 0);
        }
    }
}
