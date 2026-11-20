struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_00086060 {
    char unknown_000[0x48];
    Vector3 start;
    Vector3 end;
    char unknown_060[0x34];
    unsigned int delay;

    void func_00085CE0();
};

// Entry 0 of the table at 0x20D9C8: copies the end point to the start and waits 10.
void Object_00086060::func_00085CE0()
{
    delay = 10;
    start = end;
}
