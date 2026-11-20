struct Game {
    void *func_000128C0(int id);
};

// The arguments of the command: the player's index (object 0xc + index) and a kind.
struct Arguments_00107260 {
    int player;
    unsigned int kind;
};

// The player object (it keeps the id of its partner at 0x8d8).
struct Player_00107260 {
    char unknown_000[0x8d8];
    int partner_id;
};

// The partner (it keeps the id of its 0x115e-range object at 0x23c).
struct Partner_00107260 {
    char unknown_000[0x23c];
    unsigned int id;
};

extern Game *data_0022FCE0;

void func_00106D40(unsigned int id, int kind, int first, int second, int third);

// For kinds 0 to 2: func_00106D40 (0, the kind, 0, -1) on the 0x115e-range object of the player's partner, when both
// exist.
void func_00107260(void *arguments)
{
    Arguments_00107260 *args = (Arguments_00107260 *)arguments;
    Player_00107260 *player = (Player_00107260 *)data_0022FCE0->func_000128C0(args->player + 0xc);
    if (player) {
        Partner_00107260 *partner = (Partner_00107260 *)data_0022FCE0->func_000128C0(player->partner_id);
        if (partner && args->kind <= 2) {
            func_00106D40(partner->id, 0, args->kind, 0, -1);
        }
    }
}
