struct Pair_000C3100 {
    short first;
    short second;
};

struct Object_000C2420 {
    void func_000C2EF0(Pair_000C3100 *pair, float *time);
};

// Advances the time by 0.5 and wraps it to 0 once it reaches the pair's second value. func_000C21B0 calls this
// with its own `this` (unused), the pair at 0x7c and the time at 0x80.
void Object_000C2420::func_000C2EF0(Pair_000C3100 *pair, float *time)
{
    *time += 0.5f;
    if (*time >= pair->second) {
        *time = 0.0f;
    }
}
