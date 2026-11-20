struct Object_00116A10 {
    char unknown_00[0xd0];
    float steps[4];
    float targets[4];
    int active[4];
    int value_100;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Starts a fade of a channel of object 5: the word at +0x100, the target, a step of 1 / frames and the flag of
// the channel.
void func_001169B0(int channel, int value, float target, unsigned int frames)
{
    Object_00116A10 *object = (Object_00116A10 *)data_0022FCE0->func_000128C0(5);
    object->value_100 = value;
    object->targets[channel] = target;
    object->steps[channel] = 1.0f / frames;
    object->active[channel] = 1;
}
