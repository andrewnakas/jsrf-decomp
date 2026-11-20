struct Object_00116A10 {
    char unknown_00[0x68];
    void *handles[4];

    void func_00116290(int channel, char value);
};

void func_0013AA70(void *handle, char value);

// Passes a byte to the ADX function func_0013AA70 for the handle of a channel (see func_00116200).
void Object_00116A10::func_00116290(int channel, char value)
{
    switch (channel) {
    case 4:
        func_0013AA70(handles[1], value);
        break;
    case 5:
        func_0013AA70(handles[2], value);
        break;
    default:
        func_0013AA70(handles[channel], value);
        break;
    }
}
