int func_0014C7D0(float x, float y);
float func_0014C7F0(float value);

// func_0014C7D0 of x and func_0014C7F0(y), mirrored about 0x8000 (or -0x8000 when negative) for a negative y.
int func_0004A7A0(float x, float y)
{
    int angle = func_0014C7D0(x, func_0014C7F0(y));
    if (y < 0.0f) {
        if (angle < 0)
            return -0x8000 - angle;
        return 0x8000 - angle;
    }
    return angle;
}
