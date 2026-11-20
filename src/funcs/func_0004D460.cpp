struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_0003E750 {
    int func_0003E760();
    int func_0003E7A0(int second);
};

extern Object_0003E750 data_002314B0;

// Object 0x12b1.
struct Object_000C0670 {
    void func_000C0670(int *firstOut, int *secondOut);
};

// What object 9 fills in (func_0004D460; 0x118 bytes): five values, two lists of 32 and a pointer into the object.
struct Info_0004D460 {
    int values[5];
    int first[32];
    int second[32];
    void *data;
};

// What object 9 keeps at +0x1040: two lists of 32 bytes at +0x19c and +0x1bc.
struct Record_0004D460 {
    char unknown_000[0x19c];
    unsigned char first[32];
    unsigned char second[32];
};

// Object 9.
struct Object_0004D460 {
    char unknown_0000[0x1040];
    Record_0004D460 *record;
    char unknown_1044[0x10];
    char data[4];

    void func_0004D460(Info_0004D460 *info);
};

// Fills in `info` (when given): values 0 and 1 from data_002314B0 (func_0003E760, func_0003E7A0(0)), values 4 and 2
// from object 0x12b1 (func_000C0670, value 3 cleared) when it exists, the two byte lists of the record at +0x1040 and
// a pointer to +0x1054.
void Object_0004D460::func_0004D460(Info_0004D460 *info)
{
    if (info) {
        info->values[0] = data_002314B0.func_0003E760();
        info->values[1] = data_002314B0.func_0003E7A0(0);
        Object_000C0670 *object = (Object_000C0670 *)data_0022FCE0->func_000128C0(0x12b1);
        if (object) {
            object->func_000C0670(&info->values[4], &info->values[2]);
            info->values[3] = 0;
        }
        for (unsigned int i = 0; i < 4; i++) {
            for (unsigned int j = 0; j < 8; j++) {
                info->first[i * 8 + j] = record->first[i * 8 + j];
                info->second[i * 8 + j] = record->second[i * 8 + j];
            }
        }
        info->data = data;
    }
}
