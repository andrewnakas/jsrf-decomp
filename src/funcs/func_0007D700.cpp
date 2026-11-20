struct Part_0007D700 {
    char unknown_00[0x58];
    int unknown_58;
};

struct Holder_0007D8E0 {
    void *first;
    void *second;
    Part_0007D700 *part;
};

struct Object_0007C250 {
    char unknown_00[0x44];
    int step;
    int state;
    unsigned int timer;
    char unknown_50[0xc];
    int unknown_5c;
    float unknown_60;
    char unknown_64[0x18];
    Holder_0007D8E0 *holder;

    void func_0007D700();
};

// Step 4 (table at 0x20D3B8): after 60 frames, goes to step 1 and resets the timer and the part's word at +0x58.
void Object_0007C250::func_0007D700()
{
    if (timer++ >= 60) {
        step = 1;
        timer = 0;
        unknown_5c = 0;
        unknown_60 = 0.016666668f;
        holder->part->unknown_58 = 0;
    }
}
