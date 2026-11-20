// The 15-bit pseudo-random generator (data_00251F28, data_00257C80).
struct Object_00066980 {
    Object_00066980();

    unsigned int value;
};

// A 16-byte record kept by Object_00015D50.
struct Record_00015D10 {
    int unknown_00;
    int unknown_04;
    int unknown_08;
    int unknown_0c;
};

// The class whose table at 0x1C454C holds only its scalar deleting destructor 0x15D50 (constructor 0x15420; 0x118
// bytes, made by 0x1FD50 and others).
struct Object_00015D50 {
    virtual ~Object_00015D50();

    int unknown_04;
    float unknown_08;
    float unknown_0c;
    float unknown_10;
    int unknown_14;
    int unknown_18;
    int unknown_1c;
    int unknown_20;
    char unknown_24[4];
    int unknown_28;
    int unknown_2c;
    int unknown_30;
    char unknown_34[4];
    void *owner;
    char unknown_3c[4];
    Object_00066980 random;
    char unknown_44[0x40];
    void *buffer;
    unsigned int count;
    Record_00015D10 records[8];
    char unknown_10c[0xc];

    void func_00015D10(const Record_00015D10 *record);
};

// Called by 0x1FFF0, the player (0x9E910) and others: appends a copy of the record while fewer than eight are kept.
void Object_00015D50::func_00015D10(const Record_00015D10 *record)
{
    if (count < 8) {
        records[count] = *record;
        count++;
    }
}
