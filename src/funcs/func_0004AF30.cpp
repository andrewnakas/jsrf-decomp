struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000A63C0 {
    void func_000A6360(Vector3 *position);
    void func_000A6390(int value);
    void func_000A63C0();
};

struct Stage_00056540 {
    char unknown_00[0x14];
    int unknown_14;
    int unknown_18;
};

// A 0x2c-byte record: its kind first, a position at +0x20.
struct Record_0004AF30 {
    unsigned int kind;
    char unknown_04[0x1c];
    Vector3 position;
};

struct Info_0004AF30 {
    char unknown_00[0x3c];
    Record_0004AF30 *records;
};

struct Object_0004ABA0 {
    char unknown_0000[0x5c];
    int state;
    char unknown_0060[0x38];
    Vector3 positions[0x142];
    char unknown_0fb0[8];
    Stage_00056540 *stage;
    char unknown_0fbc[0x84];
    Info_0004AF30 *info;

    void func_0004AF30();
};

// State handler 24 of the table at 0x1F9888: when object +0xc after the stage's +0x14 exists and the stage names a
// record (+0x18) of kind 1 or 2, the record's position goes to the stage's slot of the positions at +0x98 and to the
// object (func_000A6360, then func_000A6390(1)); the object is then told func_000A63C0. Moves on to state 0x19.
void Object_0004ABA0::func_0004AF30()
{
    Object_000A63C0 *object = (Object_000A63C0 *)data_0022FCE0->func_000128C0(stage->unknown_14 + 0xc);
    if (object) {
        int slot = stage->unknown_14;
        int index = stage->unknown_18;
        if (index >= 0) {
            Record_0004AF30 *record = &info->records[index];
            if (record->kind > 0 && record->kind <= 2) {
                positions[slot] = record->position;
                object->func_000A6360(&positions[slot]);
                object->func_000A6390(1);
            }
        }
        object->func_000A63C0();
    }
    state = 0x19;
}
