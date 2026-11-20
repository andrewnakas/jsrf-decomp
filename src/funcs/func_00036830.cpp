// One of the 25 entries at 0x230DD0 (func_00036820 reads `busy`).
struct Entry_00230DD0 {
    int unknown_00;
    int unknown_04;
    int unknown_08;
    int busy;
};

struct Entry_00230F60 {
    void *pointer;
    int unknown_4;
};

extern int *data_001EEAF0[];
extern Entry_00230F60 data_00230F60[];
extern Entry_00230DD0 data_00230DD0[];

struct Object_000265A0 {
    void *func_00036830(int index, int kind, int which);
};

// Handler 14 of the table at 0x1EC200: for kind 0 the pointer of the 0x230F60 entry that the list at 0x1EEAF0 gives for
// `index` and `which`, for kind 1 word `which` of entry `index` at 0x230DD0, otherwise 0.
void *Object_000265A0::func_00036830(int index, int kind, int which)
{
    switch (kind) {
    case 0:
        return data_00230F60[data_001EEAF0[index][which]].pointer;
    case 1:
        return ((void **)&data_00230DD0[index])[which];
    }
    return 0;
}
