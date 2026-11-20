struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The object the player keeps by id at 0xc98: a sound id at 0x23c.
struct Owner_0009C350 {
    char unknown_000[0x23c];
    unsigned int sound;
};

void func_00106E50(unsigned int id, unsigned int kind, int first, int second, int third);

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x1b8];
    int value_1b8;
    char unknown_1bc[0xa90];
    int value_c4c;
    int value_c50;
    char unknown_c54[0x44];
    int ownerId;
    char unknown_c9c[0x3b0];
    int value_104c;
    unsigned int value_1050;

    void func_0009C350();
};

// With a value at 0x1050, sends it to the sound of the object kept by id at 0xc98 (func_00106E50, kind 1); then
// clears 0xc4c, 0xc50, 0x104c, 0x1050 and 0x1b8.
void Object_000A1C50::func_0009C350()
{
    if (value_1050 > 0) {
        Owner_0009C350 *owner = (Owner_0009C350 *)data_0022FCE0->func_000128C0(ownerId);
        if (owner) {
            func_00106E50(owner->sound, 1, value_1050, 0, 0);
        }
    }
    value_c4c = 0;
    value_c50 = 0;
    value_104c = 0;
    value_1050 = 0;
    value_1b8 = 0;
}
