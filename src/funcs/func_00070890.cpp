struct Record_00070530 {
    char unknown_00[8];
    int unknown_08;
    char unknown_0c[0x14];
    int unknown_20;
    int unknown_24;
};

struct Object_00070850 {
    char unknown_00[0xe8];
    Record_00070530 records[1];

    int func_00070890(int index);
};

// Says whether a record (0x28 bytes from +0xe8) is free: its word at +0x8 is clear or its word at +0x20 is set.
int Object_00070850::func_00070890(int index)
{
    if (records[index].unknown_08 == 0 || records[index].unknown_20 != 0) {
        return 1;
    }
    return 0;
}
