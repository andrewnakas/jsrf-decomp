struct Game {
    void *func_000128C0(int id);
};

struct Object_00043700 {
    int func_00043700();
};

struct Rect_001284F0 {
    int left;
    int top;
    int right;
    int bottom;
};

// The device at data_00251D6C: slot 30 sets the clipping rectangle (none with 0).
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
    virtual void __stdcall slot24();
    virtual void __stdcall slot25();
    virtual void __stdcall slot26();
    virtual void __stdcall slot27();
    virtual void __stdcall slot28();
    virtual void __stdcall slot29();
    virtual void __stdcall slot30(const Rect_001284F0 *rect);
};

struct Object_00120420 {
    char unknown_000[0x1c8];
    int mode;
    char unknown_1cc[0x9fc];
    float scroll;
};

// The class whose table is at 0x1DA350 (destructor 0x127E60).
struct Object_00127E60 {
    char unknown_00[0x44];
    int value_44;

    void func_001284F0(int index);
};

extern Game *data_0022FCE0;
extern Object_00043700 data_001FC724;
extern Device_00251D6C *data_00251D6C;
extern unsigned char data_00227840[];
extern int *data_00227FE0[];

float func_0003D750(float scale, int text);
void func_0003D610(float x, float y, float scale, unsigned int color, float width, float height, int text);

// Scrolls text `index` (0x11 when +0x44 is 2) of the language's table in data_00227FE0 through the band from
// (80, 38) to (560, 68) when data_00227840 allows it and object 0x1de2 is not in mode 4: the scroll at +0xbc8 of
// that object grows by 1 and wraps after the text's width; the text is drawn at 78 - scroll, and once more after
// it while it ends inside the band.
void Object_00127E60::func_001284F0(int index)
{
    Object_00120420 *game = (Object_00120420 *)data_0022FCE0->func_000128C0(0x1de2);
    if (value_44 == 2) {
        index = 0x11;
    }
    if (!data_00227840[index]) {
        return;
    }
    if (game->mode == 4) {
        return;
    }
    Rect_001284F0 rect;
    rect.left = 80;
    rect.top = 38;
    rect.right = 560;
    rect.bottom = 68;
    data_00251D6C->slot30(&rect);
    float width = func_0003D750(1.0f, data_00227FE0[data_001FC724.func_00043700()][index]);
    int span = rect.right - rect.left;
    game->scroll += 1.0f;
    if (width < game->scroll) {
        game->scroll = 0.0f;
    }
    func_0003D610(78.0f - game->scroll, 42.0f, 1.0f, 0xffffffff, 1.0f, 1.0f,
                  data_00227FE0[data_001FC724.func_00043700()][index]);
    if (width - game->scroll < span) {
        func_0003D610(78.0f - game->scroll + width, 42.0f, 1.0f, 0xffffffff, 1.0f, 1.0f,
                      data_00227FE0[data_001FC724.func_00043700()][index]);
    }
    data_00251D6C->slot30(0);
}
