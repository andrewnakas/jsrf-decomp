// The player.
struct Object_000A1C50 {
    char unknown_000[0xfa0];
    int unknown_fa0;

    void func_0007FC60(int amount);
};

// Takes `amount` off the player's word at +0xfa0, stopping at 0.
void Object_000A1C50::func_0007FC60(int amount)
{
    unknown_fa0 -= amount;
    if (unknown_fa0 < 0) {
        unknown_fa0 = 0;
    }
}
