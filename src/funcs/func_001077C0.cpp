// The objects with ids 0x115e to 0x1162 (table 0x1D2020, constructor func_001074B0): their ids at 0x44.
struct Object_00107FE0 {
    char unknown_00[0x44];
    int ids[24];

    void func_001077C0(int index);
};

// Clears id `index` (-1).
void Object_00107FE0::func_001077C0(int index)
{
    ids[index] = -1;
}
