int func_0001E460(void *owner, void *data);

struct Stage_00056540 {
    char unknown_00[0x14];
    int unknown_14;
};

struct Part_0004B5B0 {
    char unknown_00[0xfc];
    char *entries;
};

struct Object_0004ABA0 {
    char unknown_000[0x5c];
    int state;
    char unknown_060[0xf58];
    Stage_00056540 *stage;
    char unknown_fbc[8];
    int unknown_fc4;
    char unknown_fc8[0x78];
    Part_0004B5B0 *part;

    void func_0004B5B0();
};

// State handler 0x38 of the table at 0x1F9888: creates an object for the stage's 64-byte entry (func_0001E460),
// keeps its id at +0xfc4 and goes to state 0x39.
void Object_0004ABA0::func_0004B5B0()
{
    unknown_fc4 = func_0001E460(this, part->entries + stage->unknown_14 * 0x40);
    state = 0x39;
}
