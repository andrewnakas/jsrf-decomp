struct Object_00070530 {
    void func_00070530(int first, int second, int value);
};

struct Node {
    Node *func_00011BD0();
};

struct Object_00119C00 {
    char unknown_00[0x44];
    int mode;
    int first;
    int second;
    int value;

    void func_00119BD0(int value);
};

// Stores a value at +0x50 and in the object func_00011BD0 returns, then sets the mode to 2 for a nonzero value
// and 1 for zero.
void Object_00119C00::func_00119BD0(int newValue)
{
    Object_00070530 *owner = (Object_00070530 *)((Node *)this)->func_00011BD0();
    value = newValue;
    owner->func_00070530(first, second, newValue);
    mode = (newValue != 0) + 1;
}
