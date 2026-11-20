struct Counter_000D0140 {
    char unknown_00[0x68];
    unsigned int frames;
};

// One of the eight objects at +0x48 of the class whose table is at 0x1CE3B8 (slot 1, 0xD05C0, runs
// func_000D0410 on each); func_000D0410 calls this.
struct Object_000CFB70 {
    char unknown_0000[0x1c30];
    int x;
    int angle;
    char unknown_1c38[4];
    Counter_000D0140 *counter;

    void func_000D0140();
};

float __fastcall func_0014C640(int angle);

// Once the counter at +0x1c3c passes 30 frames, swings the x at +0x1c30 around 364 by 182 * sin of the angle at
// +0x1c34 (func_0014C640) and advances the angle by 0x111.
void Object_000CFB70::func_000D0140()
{
    if (counter->frames > 30.0) {
        x = 0x16c - (int)(func_0014C640(angle) * -182.0f);
        angle += 0x111;
    }
}
