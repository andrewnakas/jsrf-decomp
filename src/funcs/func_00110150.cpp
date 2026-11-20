// One of the five channels at +0xA0 (0x44 bytes each).
struct Channel_00110150 {
    int handle;
    int state;
    char unknown_08[0x20];
    int values[2];
    int ids[2];
    char unknown_38[0xc];
};

// The node with the five channels (table 0x1D2580, constructor func_0010FD30).
struct Object_0010FD30 {
    char unknown_000[0x54];
    int count;
    char unknown_058[0x48];
    Channel_00110150 channels[5];
    char unknown_1f4[0x1c];
    unsigned int state;

    void func_00110150();
};

void func_001087D0(int handle, unsigned int count, int *values, int value);

// Unless already in state 3 or later, clears both values of every channel (func_001087D0), forgets their ids and
// puts every channel and the object in state 3.
void Object_0010FD30::func_00110150()
{
    if (state < 3) {
        for (int i = 0; i < count; i++) {
            func_001087D0(channels[i].handle, 2, channels[i].values, 0);
            for (int j = 0; j < 2; j++) {
                channels[i].ids[j] = -1;
            }
            channels[i].state = 3;
        }
        state = 3;
    }
}
