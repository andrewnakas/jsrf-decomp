void *__cdecl operator new(unsigned int size);

// A 32-byte record of the lists at +0xa4: its id first, then whether it is enabled and whether it is the current one.
struct Record_00077BF0 {
    int id;
    int unknown_04;
    int enabled;
    int current;
    char unknown_10[0x10];
};

// The 24 records list 1 starts from (0x222220).
struct Table_00077AE0 {
    Record_00077BF0 records[24];
};

extern Table_00077AE0 data_00222220;
extern unsigned int data_0021C450[];

struct Object_00039BE0 {
    int func_00039D10(unsigned int index);
};

extern Object_00039BE0 data_001EFFB0;

struct Object_00077BF0 {
    char unknown_000[0xa4];
    Record_00077BF0 *lists[2];
    char unknown_0ac[0xa0];
    int currentId;

    void func_00077AE0();
};

// Makes list 1 a new copy of the 24 records at 0x222220 and marks each whose flag (data_0021C450 by its id)
// func_00039D10 of 0x1EFFB0 reports set: enabled, or current when it is the id at +0x14c. With none enabled, clears
// the first record of list 0's +0x8.
void Object_00077BF0::func_00077AE0()
{
    int any = 0;
    lists[1] = (Record_00077BF0 *)operator new(sizeof(Table_00077AE0));
    *(Table_00077AE0 *)lists[1] = data_00222220;
    for (int i = 0; i < 24; i++) {
        if (data_001EFFB0.func_00039D10(data_0021C450[lists[1][i].id])) {
            if (lists[1][i].id != currentId) {
                lists[1][i].enabled = 1;
                any = 1;
            } else {
                lists[1][i].current = 1;
            }
        }
    }
    if (!any) {
        lists[0]->enabled = 0;
    }
}
