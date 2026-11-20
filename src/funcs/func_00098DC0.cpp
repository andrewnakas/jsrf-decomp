struct Object_000A1C50 {
    char unknown_000[0xcd4];
    float speed;
    char unknown_cd8[4];
    float value_cdc;

    void func_00098100(int mode);
    int func_00098DC0();
};

// Sets the field at 0xcd4 to the magnitude of the one at 0xcdc, then func_00098100(0); returns 1.
int Object_000A1C50::func_00098DC0()
{
    speed = (value_cdc < 0.0f) ? -value_cdc : value_cdc;
    func_00098100(0);
    return 1;
}
