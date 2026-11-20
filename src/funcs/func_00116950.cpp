struct Object_00116A10 {
    void func_00116240(int channel, int value);
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;
extern const int data_001D7768[];

// Calls func_00116240 of object 5 for the channel the table at 0x1D7768 gives for an index, with 0.
void func_00116950(int index)
{
    Object_00116A10 *object = (Object_00116A10 *)data_0022FCE0->func_000128C0(5);
    if (object) {
        object->func_00116240(data_001D7768[index], 0);
    }
}
