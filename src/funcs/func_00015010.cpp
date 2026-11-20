struct Vector3 {
    float x;
    float y;
    float z;
};

struct Entry_00015090 {
    int unknown_00;
    Vector3 position;
    int unknown_10;
    int unknown_14;
};

struct Object_00015130 {
    void func_00015010(Entry_00015090 *entry, const Vector3 *position, int first, int second);
};

// Fills in an entry: a copy of the vector at +0x4 and the two words at +0x10 and +0x14.
void Object_00015130::func_00015010(Entry_00015090 *entry, const Vector3 *position, int first, int second)
{
    entry->position = *position;
    entry->unknown_10 = first;
    entry->unknown_14 = second;
}
