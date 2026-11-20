// The player's parameters at 0xc90: the boost cap at 0x84.
struct Params_000A1C50 {
    char unknown_00[0x84];
    float cap;
};

// The player (object 0x2c).
struct Object_000A1C50 {
    char unknown_000[0xc90];
    Params_000A1C50 *params;
    char unknown_c94[0x40];
    float boost;

    float func_0007F820();
    void func_0009A030();
};

// While the value at 0xcd4 is below the cap at 0x84 of the parameters at 0xc90 and func_0007F820 gives more than 0.2,
// adds the cap to it, at most the cap.
void Object_000A1C50::func_0009A030()
{
    float value = func_0007F820();
    if (boost < params->cap && value > 0.2f) {
        boost += params->cap;
        if (boost > params->cap) {
            boost = params->cap;
        }
    }
}
