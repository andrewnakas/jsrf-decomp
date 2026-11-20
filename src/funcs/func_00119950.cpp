struct Object_00070850 {
    void func_00070530(int first, int second, int value);
    int func_00071680(int first, int second);
};

struct Node {
    Node *func_00011BD0();
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

    void func_00119950(int value, int target);
};

// Starts mode 4: notes a value, and for target -1 resets the entry in the owner (func_00070530), otherwise makes
// sure the entry has a slot (func_00071680) and notes the target.
void Object_001197F0::func_00119950(int newValue, int newTarget)
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
