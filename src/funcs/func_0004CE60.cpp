struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Other_0004AFC0 {
    char unknown_000[0x8b4];
    int mode;
    char unknown_8b8[0x1c];
    int unknown_8d4;
};

struct Object_000A1C50 {
    char unknown_000[0xf14];
    int unknown_f14;
};

struct Object_0004ABA0 {
    void func_0004CE60();
};

// Called from func_00056990 (it ignores `this`): for objects 0xc to 0xf whose mode (+0x8b4) is not 0xb, 1 into
// +0xf14 of the player whose id each keeps at +0x8d4.
void Object_0004ABA0::func_0004CE60()
{
    for (unsigned int i = 0; i < 4; i++) {
        Other_0004AFC0 *other = (Other_0004AFC0 *)data_0022FCE0->func_000128C0(i + 0xc);
        if (other) {
            Object_000A1C50 *player = (Object_000A1C50 *)data_0022FCE0->func_000128C0(other->unknown_8d4);
            if (player && other->mode != 0xb)
                player->unknown_f14 = 1;
        }
    }
}
