// Node child with the table at 0x1C4500 (trails): up to eight trails at +0x70, their count at +0xb0.
struct Object_00014280 {
    char unknown_00[0xb0];
    unsigned int count;
    char unknown_b4[8];
    int enabled;

    void func_000147A0(int index);
    void func_00014840(int enabled);
};

// Called by the player (0x80BD0, 0x81860) and 0x84200 on game objects: stores the flag at +0xbc; when it is 0, ends
// every trail (func_000147A0), last first.
void Object_00014280::func_00014840(int enabled)
{
    this->enabled = enabled;
    if (!enabled) {
        for (int i = count - 1; i >= 0; i--) {
            func_000147A0(i);
        }
    }
}
