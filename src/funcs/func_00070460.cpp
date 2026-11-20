struct Record_00070530 {
    unsigned int value;
    char unknown_04[0x1c];
    int unknown_20;
    int unknown_24;
};

struct Transform_000704E0 {
    float scale;
    float unknown_04;
    float unknown_08;
    float unknown_0c;
    float unknown_10;
    float rate;
};

struct Object_00070850 {
    char unknown_00[0xa0];
    int values[0x12];
    Record_00070530 records[1];

    void func_00070460(int index, Transform_000704E0 *transform);
};

// Fills `transform` for record `index` from a cell of an 11-wide grid: 1, 0, the column (the record's first word modulo
// 11) times 0.087890625, 0, 1 and the row (the word over 11) times 0.087890625.
void Object_00070850::func_00070460(int index, Transform_000704E0 *transform)
{
    transform->scale = 1.0f;
    transform->unknown_04 = 0.0f;
    transform->unknown_08 = records[index].value % 11 * 0.087890625f;
    transform->unknown_0c = 0.0f;
    transform->unknown_10 = 1.0f;
    transform->rate = records[index].value / 11 * 0.087890625f;
}
