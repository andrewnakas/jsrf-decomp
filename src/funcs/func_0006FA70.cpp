struct Resource_0006FA70 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual unsigned long __stdcall Release();
};

struct Object_00071040 {
    char unknown_000[0x4b4];
    Resource_0006FA70 *resources[5];
    int loaded;

    void func_0006FA70();
};

// When +0x4c8 is set, releases the five resources at +0x4b4 (slot 2), clears them and the flag.
void Object_00071040::func_0006FA70()
{
    if (loaded) {
        for (unsigned int i = 0; i < 5; i++) {
            if (resources[i]) {
                resources[i]->Release();
                resources[i] = 0;
            }
        }
        loaded = 0;
    }
}
