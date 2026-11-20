struct Time_0003AE00 {
    int unknown_00;
    unsigned int seconds;
};

struct Object_00039BE0 {
    void func_0003AB60(void *buffer);
    void func_0003AE00(Time_0003AE00 *out);
};

extern Object_00039BE0 data_001EFFB0;

// A save slot record (0x10 bytes, from +0x18 of the list at +0x678): used flag at +0x4, time at +0x8.
struct Record_000678D0 {
    int unknown_00;
    int used;
    Time_0003AE00 time;
};

struct List_000678D0 {
    char unknown_00[0x18];
    Record_000678D0 records[1];
};

// The node 0x12af (table 0x1CB0F8, constructor 0x67B60, destructor 0x67980).
struct Object_00067980 {
    char unknown_000[0x678];
    List_000678D0 *list;
    void *buffers[1];

    int func_000678D0(int index);
};

// Writes the save into the slot's buffer (func_0003AB60), marks its record used and stamps it with the time
// (func_0003AE00). Returns 1.
int Object_00067980::func_000678D0(int index)
{
    List_000678D0 *saves = list;
    data_001EFFB0.func_0003AB60(buffers[index]);
    Time_0003AE00 time;
    saves->records[index].used = 1;
    data_001EFFB0.func_0003AE00(&time);
    saves->records[index].time.unknown_00 = time.unknown_00;
    saves->records[index].time.seconds = time.seconds;
    return 1;
}
