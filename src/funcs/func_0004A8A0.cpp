float func_0014C7F0(float value);

// Moves `from` toward `to` by `step`; `to` itself once it is closer than that (func_0014C7F0 of the difference).
float func_0004A8A0(float from, float to, float step)
{
    float difference = to - from;
    if (func_0014C7F0(difference) < step)
        return to;
    if (difference >= 0.0f)
        return from + step;
    return from - step;
}
