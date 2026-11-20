// The object at 0x251F5C: a table of 0x5e floats.
struct Object_000694A0 {
    float *values;

    float func_000694A0(unsigned int index);
};

// Value `index` of the table, or 0 past its end.
float Object_000694A0::func_000694A0(unsigned int index)
{
    if (index < 0x5e) {
        return values[index];
    }
    return 0.0f;
}
