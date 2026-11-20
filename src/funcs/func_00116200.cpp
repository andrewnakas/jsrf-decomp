struct Object_00116A10 {
    char unknown_00[0x68];
    void *handles[4];

    void func_00116200(int channel);
};

void func_0013A6B0(void *handle);

// Passes the ADX handle of a channel to func_0013A6B0: channels 0 to 3 are the handles at +0x68, channel 4 is
// handle 1 and channel 5 handle 2.
void Object_00116A10::func_00116200(int channel)
{
    switch (channel) {
    case 4:
        func_0013A6B0(handles[1]);
        break;
    case 5:
        func_0013A6B0(handles[2]);
        break;
    default:
        func_0013A6B0(handles[channel]);
        break;
    }
}
