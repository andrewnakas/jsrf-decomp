struct Object_00074F00 {
    void func_00074F00(int value);
};

struct Object_00070850 {
    char unknown_000[0x4e4];
    int ids[4];

    void func_00070530(int first, int second, int value);
    int func_00071680(int first, int second);
};

struct Node {
    Node *func_00011BD0();
};

struct Game {
    void *func_000128C0(int id);
};

struct Object_001197F0 {
    char unknown_00[0x44];
    int mode;
    int first;
    int second;
    int value;
    int active;
    int target;
    int value_5c;
    int value_60;

    void func_00119950(int newValue, int newTarget)
    {
        value_60 = newValue;
        active = 1;
        Object_00070850 *owner = (Object_00070850 *)((Node *)this)->func_00011BD0();
        if (newTarget == -1) {
            value_5c = 0;
            value = 0;
            owner->func_00070530(first, second, 0);
        } else {
            if (second == -1) {
                second = owner->func_00071680(first, first);
            }
            target = newTarget;
        }
        mode = 4;
    }

    void func_00119CE0();
};

extern Game *data_0022FCE0;
int func_00119540(int group, int index, void *position);

// Gives up what func_00119C20 took: with a value set at +0x50, frees the owner's entry (func_00070530 in mode 0);
// with no target, notes 9 in the owner (func_00074F00); otherwise resets the partner holding the target (retail
// inlined func_00119950 with target -1: same source file) and forgets the target. Plays entry 2 of group 8.
void Object_001197F0::func_00119CE0()
{
    Object_00070850 *owner = (Object_00070850 *)((Node *)this)->func_00011BD0();
    if (value) {
        value = 0;
        owner->func_00070530(first, second, 0);
        func_00119540(8, 2, 0);
    } else if (target == -1) {
        ((Object_00074F00 *)owner)->func_00074F00(9);
        func_00119540(8, 2, 0);
    } else {
        Object_001197F0 *partner = (Object_001197F0 *)data_0022FCE0->func_000128C0(owner->ids[target]);
        partner->func_00119950(value_60, -1);
        target = -1;
        active = 0;
        func_00119540(8, 2, 0);
    }
}
