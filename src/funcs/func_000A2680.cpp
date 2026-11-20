// The object at 0x2a0 of the player.
struct Data_00092300 {
    char unknown_00[0x80];
    float limit;
};

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0x2a0];
    Data_00092300 *data_2a0;
    char unknown_2a4[0xa30];
    float speed;

    void func_000A2680();
};

// Keeps the speed at 0xcd4 within the limit at 0x80 of 0x2a0, both ways.
void Object_000A1C50::func_000A2680()
{
    if (speed > data_2a0->limit) {
        speed = data_2a0->limit;
    }
    if (-data_2a0->limit > speed) {
        speed = -data_2a0->limit;
    }
}
