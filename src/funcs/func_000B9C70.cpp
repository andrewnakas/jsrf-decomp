// 1 at 400 and below, falling by 0.01 per unit above it, never below 0.
float func_000B9C70(float value)
{
    float result = 1.0f - (value - 400.0f) * 0.01f;
    if (result > 1.0f) {
        return 1.0f;
    }
    if (result < 0.0f) {
        return 0.0f;
    }
    return result;
}
