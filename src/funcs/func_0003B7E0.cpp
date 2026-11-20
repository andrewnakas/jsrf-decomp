extern "C" void *memset(void *destination, int value, unsigned int size);

extern int data_001EFC88[];

// The slot of a stage id (area in the high half, stage in the low half, one decimal digit each).
inline int stage_0003A2F0(unsigned int id)
{
    return data_001EFC88[(id >> 16) % 10 * 10 + (id & 0xffff) % 10];
}

// A record of a stage's table (8 bytes): its score and three letters.
struct Record_0003A690 {
    unsigned int score;
    unsigned char letters[3];
};

// A record handed in (0x28 bytes): a score, three letters, the date and time.
struct Record_00073440 {
    unsigned int score;
    int letters[3];
    int unknown_10[6];
};

// The object at 0x1EFFB0: per stage slot, four kinds of five records at +0x2a9c and their flags at +0x6a58.
struct Object_00039BE0 {
    char unknown_0000[0x2a9c];
    Record_0003A690 records[0x140];
    char unknown_349c[0x35bc];
    int flags[0x140];

    void func_0003B7E0(unsigned int stage, int kind, Record_00073440 *record);
};

// Clears every record's flag, then puts `record` into the five records of kind `kind` (0 to 3) of the stage where
// it ranks (kind 1 keeps the highest scores first, the others the lowest), moving the ones after it down, and flags
// it as new.
void Object_00039BE0::func_0003B7E0(unsigned int stage, int kind, Record_00073440 *record)
{
    int slot = stage_0003A2F0(stage);
    for (int n = 0; n < 0x140; n++)
        flags[n] = 0;
    int list = slot * 4 + kind;
    Record_0003A690 *entries = &records[list * 5];
    unsigned int i;
    switch (kind) {
    case 0:
    case 2:
    case 3:
        for (i = 0; i < 5; i++) {
            if (entries[i].score > record->score) {
                for (unsigned int n = 4; n > i; n--)
                    entries[n] = entries[n - 1];
                memset(&entries[i], 0, sizeof(Record_0003A690));
                entries[i].score = record->score;
                entries[i].letters[0] = record->letters[0];
                entries[i].letters[1] = record->letters[1];
                entries[i].letters[2] = record->letters[2];
                flags[list * 5 + i] = 1;
                return;
            }
        }
        break;
    case 1:
        for (i = 0; i < 5; i++) {
            if (entries[i].score < record->score) {
                for (unsigned int n = 4; n > i; n--)
                    entries[n] = entries[n - 1];
                memset(&entries[i], 0, sizeof(Record_0003A690));
                entries[i].score = record->score;
                entries[i].letters[0] = record->letters[0];
                entries[i].letters[1] = record->letters[1];
                entries[i].letters[2] = record->letters[2];
                flags[list * 5 + i] = 1;
                return;
            }
        }
        break;
    }
}
