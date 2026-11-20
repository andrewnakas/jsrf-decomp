struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

void func_00106D90(unsigned int id, int kind);

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0xc98];
    int partnerId;
};

// The object whose id the player keeps at 0xc98.
struct Partner_0009C210 {
    char unknown_000[0x23c];
    unsigned int id;
};

// Passes the id at 0x23c of the player's partner (0xc98), when it exists, to func_00106D90 with kind 1.
void func_000C1E60()
{
    Object_000A1C50 *player = (Object_000A1C50 *)data_0022FCE0->func_000128C0(0x2c);
    Partner_0009C210 *partner = (Partner_0009C210 *)data_0022FCE0->func_000128C0(player->partnerId);
    if (partner) {
        func_00106D90(partner->id, 1);
    }
}
