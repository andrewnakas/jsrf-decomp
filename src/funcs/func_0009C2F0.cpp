struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

void func_00106E50(unsigned int id, unsigned int kind, int first, int second, int third);

// The object whose id the player keeps at 0xc98.
struct Partner_0009C210 {
    char unknown_000[0x23c];
    unsigned int id;
};

// The object at 0x5c of the player.
struct Object_0009C2F0 {
    char unknown_000[0x1f8];
    int value_1f8;
};

struct Object_000A1C50 {
    char unknown_000[0x5c];
    Object_0009C2F0 *value_5c;
    char unknown_060[0xc38];
    int partnerId;

    void func_0009C2F0();
};

// Passes the id at 0x23c of the object at 0xc98, when it exists, to func_00106E50 with kind 0 and 1, 3, 0 when the
// value at 0x1f8 of the object at 0x5c is set, 0, 3, 0 otherwise.
void Object_000A1C50::func_0009C2F0()
{
    Partner_0009C210 *partner = (Partner_0009C210 *)data_0022FCE0->func_000128C0(partnerId);
    if (partner) {
        if (value_5c->value_1f8) {
            func_00106E50(partner->id, 0, 1, 3, 0);
        } else {
            func_00106E50(partner->id, 0, 0, 3, 0);
        }
    }
}
