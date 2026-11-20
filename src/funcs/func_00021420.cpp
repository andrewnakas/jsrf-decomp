void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *matrix);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB380(int angle);
void func_001BB230(float x, float y, float z);

struct Info_00021420 {
    int unknown_00;
    int slot;
    int unknown_08;
};

// An entry of the table at +0xe0: its info (+0x8), position (+0x1c), a slot (+0x38) and four angles.
struct Entry_00021420 {
    char unknown_00[8];
    Info_00021420 *info;
    char unknown_0c[0x10];
    float position[3];
    char unknown_28[0x10];
    int slot;
    int angle_3c;
    int angle_40;
    int angle_44;
    int angle_48;
};

struct State_00021420 {
    char unknown_00[0x2c];
    int *turned;
    char unknown_30[0x58];
    int *modes;
};

// Node child with the table at 0x1C4BA8 (destructor 0x22990).
struct Object_00022990 {
    char unknown_00[0xdc];
    State_00021420 *state;
    Entry_00021420 **entries;

    void func_00021320(unsigned int index, int pass);
    void func_00021420(unsigned int index, int pass);
};

// Called by func_000232A0 for each entry of the list at +0xc0: unless the entry's info has a word at +0x8 and its
// slot's mode (+0x88 of the block at +0xdc) is 2, draws it (func_00021320) at its position (+0x1c, func_001BAAA0),
// turned by +0x48 + +0x3c (func_001BB330), by +0x44 when the slot at +0x38 is set in the list at +0x2c
// (func_001BB2E0) and by +0x40 (func_001BB380), at scale 1.
void Object_00022990::func_00021420(unsigned int index, int pass)
{
    Entry_00021420 *entry = entries[index];
    if (entry->info->unknown_08 && state->modes[entry->info->slot] == 2)
        return;
    func_001BA9C0();
    func_001BAAA0(entry->position);
    func_001BB330(entry->angle_48 + entry->angle_3c);
    if (state->turned[entry->slot])
        func_001BB2E0(entry->angle_44);
    func_001BB380(entry->angle_40);
    func_001BB230(1.0f, 1.0f, 1.0f);
    func_00021320(index, pass);
    func_001BAA50();
}
