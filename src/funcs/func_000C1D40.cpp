// An effect of data_002314B0: its kind in the low bits of 0xa4, the time left at 0xc8 out of the time at 0xcc.
struct Entry_0003E720 {
    char unknown_00[0xa4];
    unsigned int flags;
    char unknown_a8[0x20];
    float left;
    float length;
};

struct Object_0003E750 {
    Entry_0003E720 *func_0003E720(int key);
    void func_0003F280(int index);
};

extern Object_0003E750 data_002314B0;

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 {
    int func_000C1D40(int *effect, int *second, int *third);
};

// Follows the effect: while it runs, stores how far it has gone (1 - left / length, a float) at third and, while
// that is above 0, a quarter of its kind (flags & 7, a float) at second; returns 0 while time is left. Once the time is out
// (or the effect is gone) the effect is released (func_0003F280) and set to -1, and the answer is 1.
int Object_00157F10::func_000C1D40(int *effect, int *second, int *third)
{
    if (*effect != -1) {
        Entry_0003E720 *entry = data_002314B0.func_0003E720(*effect);
        if (entry) {
            float done = 1.0f - entry->left / entry->length;
            *(float *)third = done;
            if (done > 0.0f) {
                *(float *)second = (float)(entry->flags & 7) * 0.25f;
            }
            if (entry->left > 0.0f) {
                return 0;
            }
            data_002314B0.func_0003F280(*effect);
            *effect = -1;
        }
    }
    return 1;
}
