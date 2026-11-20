struct Owner_000CEF60 {
    char unknown_00[0xa4];
    unsigned int flags;
};

struct Object_000CE220 {
    int unknown_00;
    Owner_000CEF60 *owner;
    int state;
    char unknown_0c[0x34];
    int index;
    char unknown_44[4];
    int value_48;
    char unknown_4c[0x48];
    int value_94;

    void func_000CEF60();
};

extern int data_00216664[3][5];

// When the owner at 4 has flag 0x1000000: takes the fields at 0x94, 0x48 and the state at 8 from the three
// rows of data_00216664, by the index at 0x40.
void Object_000CE220::func_000CEF60()
{
    if (owner->flags & 0x1000000) {
        value_94 = data_00216664[2][index];
        value_48 = data_00216664[1][index];
        state = data_00216664[0][index];
    }
}
