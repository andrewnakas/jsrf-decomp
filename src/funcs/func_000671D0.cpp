// The object at 0x251F2C: four slots, each a pointer to a frame count and the time spent in it.
struct Object_00067030 {
    unsigned int *values[4];
    float times[4];

    void func_000671D0(int slot);
};

// Steps a slot's time by one; once it reaches the last frame of its count, clears the slot and its time (called from
// 0x67220).
void Object_00067030::func_000671D0(int slot)
{
    times[slot] += 1.0f;
    if (times[slot] >= *values[slot] - 1.0f) {
        values[slot] = 0;
        times[slot] = 0.0f;
    }
}
