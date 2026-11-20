struct Game {
    int func_000127E0(int index);
};

extern Game *data_0022FCE0;

void func_00024620(unsigned int colour, float speed);
void func_0004E9B0(int first, int second, int third);

struct Object_0004ABA0 {
    char unknown_000[0x4c];
    int unknown_4c;
    int unknown_50;
    char unknown_054[8];
    int state;

    void func_00053C00();
};

// State handler 0x67 of the table at 0x1F9888: starts func_00024620 with 0xFF000000 at 1/60, func_0004E9B0 with
// the word at +0x4c and the game's flag 6, then state 0x68.
void Object_0004ABA0::func_00053C00()
{
    func_00024620(0xff000000, 0.016666668f);
    func_0004E9B0(unknown_4c, data_0022FCE0->func_000127E0(6), 1);
    state = 0x68;
}
