// The player's settings (object at 0x2a0): the speed factors.
struct Object_00094780 {
    char unknown_000[0x10c];
    float base_10c;
    float scale_110;
    float base_114;
    float scale_118;
};

// One 0x98-byte entry of the player's table at 0xc90.
struct Entry_00098800 {
    char unknown_00[0xc];
    float heldLimit;
    char unknown_10[4];
    float step;
    float limit;
    char unknown_1c[0x7c];
};

// The player's table at 0xc90: its entries from 0xa0.
struct Table_00098800 {
    char unknown_00[0xa0];
    Entry_00098800 entries[1];
};

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x2a0];
    Object_00094780 *object_2a0;
    char unknown_2a4[0x910];
    float value_bb4;
    float value_bb8;
    char unknown_bbc[0xd4];
    Table_00098800 *table;
    char unknown_c94[0x40];
    float value_cd4;
    char unknown_cd8[0x188];
    unsigned int value_e60;
    char unknown_e64[0x304];
    int entry;

    float func_0007F820();
    void func_00098800();
};

// Eases the speed at 0xbb4 toward the input (func_0007F820) scaled by the settings at 0x2a0 (0x110/0x114 while 0xe60
// counts, else 0x118/0x10c), by the entry's step over its limit; drops it below the step when that limit is 0; the
// speed at 0xcd4 is it plus 0xbb8, held within the limit when 0xe60 is clear.
void Object_000A1C50::func_00098800()
{
    float input = func_0007F820();
    float target;
    float limit;
    if (value_e60 > 0) {
        target = input * object_2a0->scale_110 + object_2a0->base_114;
        limit = table->entries[entry].heldLimit;
    } else {
        target = input * object_2a0->scale_118 + object_2a0->base_10c;
        limit = table->entries[entry].limit;
    }
    value_bb4 += (target - value_bb4) / table->entries[entry].limit * table->entries[entry].step;
    if (limit == 0.0f) {
        if ((value_bb4 < 0.0f ? -value_bb4 : value_bb4) < table->entries[entry].step) {
            value_bb4 = 0.0f;
        }
    }
    value_cd4 = value_bb8 + value_bb4;
    if (!value_e60) {
        if (value_cd4 > limit) {
            value_cd4 = limit;
        }
        if (value_cd4 < -limit) {
            value_cd4 = -limit;
        }
    }
}
