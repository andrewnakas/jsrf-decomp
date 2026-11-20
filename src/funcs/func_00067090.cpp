// A key of a range curve: a time and a value, both words.
struct Key_00067090 {
    unsigned short time;
    unsigned short value;
};

// What a slot's value points at: the curves of the high and the low word.
struct Range_00067090 {
    int unknown_00;
    Key_00067090 *high;
    Key_00067090 *low;
};

struct Object_00067030 {
    Range_00067090 *values[4];
    float times[4];

    unsigned int func_00067090(int slot);
};

// Packs the two curves of a slot's range at the slot's time into the high and the low word (0 for a missing curve):
// each between the last key before the time and the next one, by how far the time is between them.
unsigned int Object_00067030::func_00067090(int slot)
{
    Range_00067090 *range = values[slot];
    int high = 0;
    int low = 0;
    Key_00067090 *key = range->high;
    if (key) {
        while (key[1].time < times[slot]) {
            key++;
        }
        float blend = (times[slot] - key->time) / (key[1].time - key->time);
        high = (int)((1.0f - blend) * key->value + key[1].value * blend);
    }
    key = range->low;
    if (key) {
        while (key[1].time < times[slot]) {
            key++;
        }
        float blend = (times[slot] - key->time) / (key[1].time - key->time);
        low = (int)((1.0f - blend) * key->value + key[1].value * blend);
    }
    return (unsigned short)high << 16 | (unsigned short)low;
}
