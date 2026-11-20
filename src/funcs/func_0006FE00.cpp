struct Object_00070850 {
    char unknown_000[0xa0];
    int busy[4];
    char unknown_0b0[0x460];
    int used[4];

    int func_0006FE00(int *index);
};

// The first of its four slots that is in use and not busy, through `index`; 0 when there is none.
int Object_00070850::func_0006FE00(int *index)
{
    int result = 0;
    for (unsigned int i = 0; i < 4; i++) {
        if (used[i] && !busy[i]) {
            *index = i;
            result = 1;
            break;
        }
    }
    return result;
}
