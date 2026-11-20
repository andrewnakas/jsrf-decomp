struct Pair_000C3100 {
    short first;
    short second;
};

struct Object_000C3100 {
    char unknown_00[0x7c];
    Pair_000C3100 *pair;
    float value;

    void func_000C3100();
};

void Object_000C3100::func_000C3100()
{
    if ((float)pair->second - 1.0f > value) {
        value += 0.5f;
    }
}
