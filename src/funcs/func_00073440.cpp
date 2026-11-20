// The clock in the XAPI library: fills in the date and time (words: year, month, day of week, day, hour, minute,
// second, millisecond).
struct Time_00147BEC {
    unsigned short year;
    unsigned short month;
    unsigned short dayOfWeek;
    unsigned short day;
    unsigned short hour;
    unsigned short minute;
    unsigned short second;
    unsigned short milliseconds;
};

void __stdcall func_00147BEC(Time_00147BEC *time);

struct Game {
    int func_000127E0(int index);
};

extern Game *data_0022FCE0;

// A record kept by func_0003B7E0 (0x28 bytes): a score, the game's value 0xd, two words and the date and time.
struct Record_00073440 {
    int score;
    int value;
    int first;
    int second;
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int seconds;
};

struct Object_00039BE0 {
    void func_0003B7E0(unsigned int stage, int kind, Record_00073440 *record);
};

extern Object_00039BE0 data_001EFFB0;

// The node class whose table is at 0x1CCB68 (constructor 0x73500, made by 0x109300; destructor 0x73AD0).
struct Object_00073AD0 {
    char unknown_00[0x5c];
    int unknown_5c;
    char unknown_60[0x14];
    int unknown_74;
    int unknown_78;
    char unknown_7c[8];
    unsigned int stage;
    char unknown_88[4];
    int kind;
    char unknown_90[0x24];
    int unknown_b4;

    void func_00073440();
};

// Hands a record for kinds 9 to 12 to func_0003B7E0 of 0x1EFFB0 with the stage at +0x84: the score (+0xb4 for kind
// 10, else +0x5c), the game's value 0xd, the words at +0x74 and +0x78 and the date and time now (func_00147BEC).
void Object_00073AD0::func_00073440()
{
    Time_00147BEC now;
    func_00147BEC(&now);
    Record_00073440 record;
    record.value = data_0022FCE0->func_000127E0(0xd);
    switch (kind) {
    case 9:
    case 11:
    case 12:
        record.score = unknown_5c;
        break;
    case 10:
        record.score = unknown_b4;
        break;
    }
    record.first = unknown_74;
    record.second = unknown_78;
    record.year = now.year;
    record.month = now.month;
    record.day = now.day;
    record.hour = now.hour;
    record.minute = now.minute;
    record.seconds = now.second;
    data_001EFFB0.func_0003B7E0(stage, kind - 9, &record);
}
