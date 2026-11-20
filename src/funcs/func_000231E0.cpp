struct Vector3 {
    float x;
    float y;
    float z;
};

void __fastcall func_001BAB20(Vector3 *to, const Vector3 *from);

// An entry of the table at +0xe0: its position at +0x1c.
struct Entry_000231E0 {
    char unknown_00[0x1c];
    Vector3 position;
};

// The block +0xdc points at: the entry count at +0x18.
struct State_000231E0 {
    char unknown_00[0x18];
    int count;
};

// Node child with the table at 0x1C4BA8 (destructor 0x22990).
struct Object_00022990 {
    char unknown_00[0xbc];
    float *depths;
    int *order;
    int sortCount;
    char unknown_c8[0x14];
    State_000231E0 *state;
    Entry_000231E0 **entries;

    void func_00022840(int first, int low, int high);
    void func_000231E0();
};

// Called by func_000232A0: lists the entries after the first two with the depth of their position under the current
// matrix (func_001BAB20) in +0xbc and their index in +0xc0 (count at +0xc4), then sorts them (func_00022840) when
// there are two or more.
void Object_00022990::func_000231E0()
{
    State_000231E0 *block = state;
    sortCount = 0;
    for (int i = 0; i < block->count - 2; i++) {
        Entry_000231E0 *entry = entries[i + 2];
        Vector3 position = entry->position;
        func_001BAB20(&position, &position);
        depths[sortCount] = position.z;
        order[sortCount] = i + 2;
        sortCount++;
    }
    if (sortCount > 1)
        func_00022840(1, 0, sortCount - 1);
}
