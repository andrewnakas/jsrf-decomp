struct Object_00116A10 {
    char unknown_00[0x68];
    void *handles[4];

    void func_00116240(int channel, int value);
};

void func_0013AA80(void *handle, int value);

// Passes a value to the ADX function func_0013AA80 for the handle of a channel (see func_00116200).
void Object_00116A10::func_00116240(int channel, int value)
{
    switch (channel) {
    case 4:
        func_0013AA80(handles[1], value);
        break;
    case 5:
        func_0013AA80(handles[2], value);
        break;
    default:
        func_0013AA80(handles[channel], value);
        break;
    }
}
