struct Motion_0005F060 {
    short unknown_00;
    short frames;
};

int func_0005E030(Motion_0005F060 *motion, float *time, float step, int hold);

extern float data_0020C638[5];

struct Object_0006A720 {
    char unknown_000[0x9bc];
    Motion_0005F060 *motions[10][5];
    float times[10][5];
    char unknown_b4c[0xf8];
    int current;

    void func_0006A770();
};

// Steps the time of each of the five motions of the current set (func_0005E030) by its rate from 0x20C638.
void Object_0006A720::func_0006A770()
{
    for (unsigned int i = 0; i < 5; i++) {
        if (motions[current][i]) {
            func_0005E030(motions[current][i], &times[current][i], data_0020C638[i], 0);
        }
    }
}
