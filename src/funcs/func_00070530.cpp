struct Record_00070530 {
    char unknown_00[0x20];
    int unknown_20;
    int unknown_24;
};

struct Object_00070530 {
    char unknown_00[0xa0];
    int values[0x12];
    Record_00070530 records[1];

    void func_00070530(int index, int record, int value);
};

// Stores a value in record +0x20 of one of the 0x28-byte records at +0xe8 and in the table at +0xa0.
void Object_00070530::func_00070530(int index, int record, int value)
{
    records[record].unknown_20 = value;
    values[index] = value;
}
