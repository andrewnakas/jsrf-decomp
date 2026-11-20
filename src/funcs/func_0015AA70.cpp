struct Interface_00265110;

extern Interface_00265110 *data_00265110;
extern float *data_00265128;
// Room for a 16-byte aligned vector; data_00265128 points at it.
extern char data_0026512C[0x20];
long func_0015AE80(Interface_00265110 *object);

// Points data_00265128 at the 16-byte aligned vector in the buffer at 0x26512C, sets it to (1, -1, 1) and calls
// func_0015AE80 with the object at 0x265110, whose result it returns. The argument is not used.
long __stdcall func_0015AA70(void *object)
{
    data_00265128 = (float *)((unsigned long)(data_0026512C + 15) & ~15);
    data_00265128[0] = 1.0f;
    data_00265128[1] = -1.0f;
    data_00265128[2] = 1.0f;
    return func_0015AE80(data_00265110);
}
