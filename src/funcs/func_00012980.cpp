struct Device_00251D6C {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8();
    virtual void __stdcall slot9();
    virtual void __stdcall slot10();
    virtual void __stdcall slot11();
    virtual void __stdcall slot12();
    virtual void __stdcall slot13();
    virtual void __stdcall slot14();
    virtual void __stdcall slot15();
    virtual void __stdcall slot16();
    virtual void __stdcall slot17();
    virtual void __stdcall slot18();
    virtual void __stdcall slot19();
    virtual void __stdcall slot20();
    virtual void __stdcall slot21();
    virtual void __stdcall slot22();
    virtual void __stdcall slot23();
    virtual void __stdcall slot24(int value);
    virtual void __stdcall slot25(int value);
    virtual void __stdcall slot26();
    virtual void __stdcall slot27();
    virtual void __stdcall slot28();
    virtual void __stdcall slot29();
    virtual void __stdcall slot30(void *pointer);
};

extern Device_00251D6C *data_00251D6C;

struct Game {
    char unknown_00[0x34];
    int unknown_34;

    void func_00012980();
};

// Hands the word at +0x34 to slot 24 of the device at 0x251D6C, then slot 30 with 0 and slot 25 with -1.
void Game::func_00012980()
{
    data_00251D6C->slot24(unknown_34);
    data_00251D6C->slot30(0);
    data_00251D6C->slot25(-1);
}
