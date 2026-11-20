struct Interface {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

extern Interface *data_0026514C;

void func_0015AFF0()
{
    if (data_0026514C) {
        while (data_0026514C->slot2() != 0)
            ;
        data_0026514C = 0;
    }
}
