struct Matrix_00107F40 {
    float m[4][4];
};

// An entry of the list at 0x1a4 (64 of 0x54 bytes).
struct Entry_00107F40 {
    int id;
    int kind;
    Matrix_00107F40 matrix;
    float value;
    int extra;
    int unknown_50;
};

// The objects with ids 0x115e to 0x1162 (table 0x1D2020).
struct Object_00107FE0 {
    char unknown_0000[0x1a4];
    Entry_00107F40 entries[64];
    unsigned int count;

    void func_00107F40(int kind, const Matrix_00107F40 *matrix, int id, float value, int extra);
};

// Appends an entry (kind, matrix, id, value, extra) to the list at 0x1a4 while it holds fewer than 64.
void Object_00107FE0::func_00107F40(int kind, const Matrix_00107F40 *matrix, int id, float value, int extra)
{
    if (count < 64) {
        entries[count].kind = kind;
        entries[count].matrix = *matrix;
        entries[count].id = id;
        entries[count].value = value;
        entries[count].extra = extra;
        count++;
    }
}
