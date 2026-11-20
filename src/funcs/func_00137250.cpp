struct Object_00134880 {
    char unknown_000[0x72c];
    float speed;
    float level;
    char unknown_734;
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char pulse;
    unsigned char falling;

    void func_00137250();
};

unsigned int func_0014C690(float value);

// Member of the class whose table is at 0x1DE828 (called by its slot 1, 0x134F00): moves the level at +0x730 by
// the speed at +0x72c / 30, turning the speed around at 1 and 0; sets the colour bytes at +0x735 (100 - 100 *
// level) and +0x736, +0x737 (100 + 155 * level); and moves the pulse byte at +0x738 by 5 between 100 and 255.
void Object_00134880::func_00137250()
{
    level += speed * (1.0f / 30.0f);
    if (speed > 0.0f) {
        if (level >= 1.0f) {
            level = 1.0f;
            speed *= -1.0f;
        }
    } else if (level <= 0.0f) {
        level = 0.0f;
        speed *= -1.0f;
    }
    red = (unsigned char)((int)func_0014C690(level * -100.0f) + 100.0f);
    green = (unsigned char)((int)func_0014C690(level * 155.0f) + 100.0f);
    blue = (unsigned char)((int)func_0014C690(level * 155.0f) + 100.0f);
    if (!falling) {
        pulse += 5;
        if (pulse >= 0xff) {
            falling = 1;
        }
    } else {
        pulse -= 5;
        if (pulse <= 100) {
            falling = 0;
        }
    }
}
