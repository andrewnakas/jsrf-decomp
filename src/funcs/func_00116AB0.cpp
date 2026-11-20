struct Entry_001160D0 {
    int id;
    const char *name;
};

// Object 5, the sound player.
struct Object_00116A10 {
    char unknown_000[0x68];
    void *handles[4];

    int func_001160D0(int kind, int id);
    const char *func_001164F0(int index);
    void func_00116AB0(int channel, int track);
};

extern const Entry_001160D0 data_001D3878[];
extern const Entry_001160D0 data_001D3A38[];
extern const Entry_001160D0 data_001D4DB0[];

void func_0013A6B0(void *handle);
void func_0013AA60(void *handle, char value);
void func_0013AEB0(void *handle, const char *name);

// Starts `track` on `channel`: channels 0 and 1 play the named entry of the first table (func_001160D0) on their
// own handle, channel 3 that of the table at data_001D4DB0 on handle 3, all with 1 passed to func_0013AA60;
// channels 2 and 5 (handle 2) and 4 (handle 1) play the path func_001164F0 builds for the track's index in
// data_001D3A38 (func_001160D0's kind 2, inlined), with 0.
void Object_00116A10::func_00116AB0(int channel, int track)
{
    switch (channel) {
    case 0:
    case 1: {
        int index = func_001160D0(channel, track);
        if (index >= 0) {
            func_0013AA60(handles[channel], 1);
            func_0013A6B0(handles[channel]);
            func_0013AEB0(handles[channel], data_001D3878[index].name);
        }
        break;
    }
    case 2:
    case 5: {
        int index = 0;
        if (track != 1) {
            do {
                if (data_001D3A38[index++].id == -1) {
                    index = -1;
                    break;
                }
            } while (data_001D3A38[index].id != track);
        }
        if (index >= 0) {
            func_0013AA60(handles[2], 0);
            func_0013A6B0(handles[2]);
            func_0013AEB0(handles[2], func_001164F0(index));
        }
        break;
    }
    case 3: {
        int index = func_001160D0(3, track);
        if (index >= 0) {
            func_0013AA60(handles[3], 1);
            func_0013A6B0(handles[3]);
            func_0013AEB0(handles[3], data_001D4DB0[index].name);
        }
        break;
    }
    case 4: {
        int index = 0;
        if (track != 1) {
            do {
                if (data_001D3A38[index++].id == -1) {
                    index = -1;
                    break;
                }
            } while (data_001D3A38[index].id != track);
        }
        if (index >= 0) {
            func_0013AA60(handles[1], 0);
            func_0013A6B0(handles[1]);
            func_0013AEB0(handles[1], func_001164F0(index));
        }
        break;
    }
    }
}
