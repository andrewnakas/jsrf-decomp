float func_0014C890(float from, float to, float t);

// A point of a curve: a time and a value.
struct Point_0001EAA0 {
    float time;
    float value;
    float unknown_08;
};

// The block at +0xdc: curves of 100 points at +0x38.
struct State_0001EAA0 {
    char unknown_00[0x38];
    Point_0001EAA0 **curves;
};

// Node child with the table at 0x1C4BA8.
struct Object_00022990 {
    char unknown_00[0xdc];
    State_0001EAA0 *state;

    float func_0001EAA0(int index, float time);
};

// Called by func_0001EFC0: the value of curve `index` of the block at the time (0 and 1 map to themselves),
// interpolated (func_0014C890) between the two points around it.
float Object_00022990::func_0001EAA0(int index, float time)
{
    if (time == 0.0f || time == 1.0f)
        return time;
    Point_0001EAA0 *previous;
    Point_0001EAA0 *next;
    for (unsigned int i = 1; i < 100; i++) {
        previous = &state->curves[index][i - 1];
        next = &state->curves[index][i];
        if (next->time > time)
            break;
    }
    return func_0014C890(previous->value, next->value, (time - previous->time) / (next->time - previous->time));
}
