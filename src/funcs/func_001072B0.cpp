/* const: 0x80000 */
struct Game {
    void *func_000128C0(int id);
};

// The arguments of the command: the player's index (object 0xc + index) and a kind.
struct Arguments_001072B0 {
    int player;
    int kind;
};

// The player object (it keeps the id of its 0x115e-range object at 0x8d8).
struct Player_001072B0 {
    char unknown_000[0x8d8];
    int partner_id;
};

// The partner (it keeps the id of the 0x115e-range object at 0x23c).
struct Partner_001072B0 {
    char unknown_000[0x23c];
    unsigned int id;
};

extern Game *data_0022FCE0;

void func_00106BD0(unsigned int id, unsigned int mask, int set);

// For kind 0: sets (on) or clears mask 0x80000 through func_00106BD0 for the 0x115e-range object of the player's
// partner, when both exist.
void func_001072B0(void *arguments, int on)
{
    Arguments_001072B0 *args = (Arguments_001072B0 *)arguments;
    Player_001072B0 *player = (Player_001072B0 *)data_0022FCE0->func_000128C0(args->player + 0xc);
    if (player) {
        Partner_001072B0 *partner = (Partner_001072B0 *)data_0022FCE0->func_000128C0(player->partner_id);
        if (partner && args->kind == 0) {
            if (on) {
                func_00106BD0(partner->id, 0x80000, 1);
            } else {
                func_00106BD0(partner->id, 0x80000, 0);
            }
        }
    }
}
