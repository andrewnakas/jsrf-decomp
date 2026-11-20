struct Animation_00114FE0 {
    short unknown_0;
    short frames;
};

struct Object_00114FD0 {
    virtual ~Object_00114FD0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(int argument);
    virtual void slot4();
    virtual void slot5();
    virtual void slot6(int argument);
    virtual void func_00114FE0();

    char unknown_04[0xc4];
    Animation_00114FE0 *animation;
    float frame;
};

// Slot 7 of the table at 0x1D2B68: advances the frame by one and wraps it to 0 at the last frame.
void Object_00114FD0::func_00114FE0()
{
    frame += 1.0f;
    if (frame >= animation->frames - 1.0f) {
        frame = 0;
    }
}
