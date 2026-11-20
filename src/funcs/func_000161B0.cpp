struct Item_00016200;
struct Item_000162A0;

// The object at 0x22FCE8: seven lists, each a head and the link the next item goes into.
struct Object_00016200 {
    Item_00016200 **tails[4];
    Item_00016200 *heads[4];
    Item_000162A0 **otherTails[3];
    Item_000162A0 *otherHeads[3];
    char unknown_38[0x28];
    int unknown_60;
    int unknown_64;
    int unknown_68;
    int unknown_6c;

    void func_000161B0();
};

// Empties the seven lists and clears the words at +0x60 to +0x6c (called from 0x123E0).
void Object_00016200::func_000161B0()
{
    heads[0] = 0;
    heads[1] = 0;
    heads[2] = 0;
    heads[3] = 0;
    tails[0] = &heads[0];
    tails[1] = &heads[1];
    tails[2] = &heads[2];
    tails[3] = &heads[3];
    otherHeads[0] = 0;
    otherHeads[1] = 0;
    otherHeads[2] = 0;
    otherTails[0] = &otherHeads[0];
    otherTails[1] = &otherHeads[1];
    otherTails[2] = &otherHeads[2];
    unknown_60 = 0;
    unknown_64 = 0;
    unknown_68 = 0;
    unknown_6c = 0;
}
