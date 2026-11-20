/* sym: ?func_00011C80@Object_0004EF90@@UAEXH@Z = 0x0004F9A0 */
struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C90_5();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C90_7();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C90_9();
    virtual void func_00011C80_4(int argument);

    unsigned int flags;
    int id;
    unsigned int mask;
    float depth;
    int sortKey;
    char unknown_18[0xc];
    Node *parent;
    Node *child;
    Node *previous;
    Node *next;
    char unknown_34[0x10];
};

// The debug text printer: slot 3 sets a color, slot 8 draws text at a position.
struct Interface_00251D68 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3(int index, unsigned int color);
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __cdecl slot8(int x, int y, char *text);
};

extern Interface_00251D68 *data_00251D68;
extern char *data_0020CF40[];

int func_00145CCB(char *buffer, const char *format, ...);

// The class whose table is at 0x1CAAF8: overrides slots 1 (4EF90), 3 (4F9A0), 4 (AECC0), 7 (AECC0), 10 (AECC0).
struct Object_0004EF90 : Node {
    virtual ~Object_0004EF90();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C90_6();

    unsigned int state;
    void *unknown_48;
    int unknown_4c;
    int unknown_50;
    unsigned int unknown_54;
    int unknown_58[2];
    unsigned int unknown_60[4];
    int unknown_70[4];
    int unknown_80[4];
    void *buffers[4];
};

// Slot 3: the debug page of the key settings, one line per player (state 0xb: key data, state 0x11: key numbers).
void Object_0004EF90::func_00011C80(int argument)
{
    char text[0x400];
    switch (state) {
    case 0xb: {
        unsigned int i;
        unsigned int y;
        for (i = 0, y = 0x78; y < 0xc8; i++, y += 0x14) {
            data_00251D68->slot3(0x14, 0xffffffff);
            func_00145CCB(text, "Player %d", i);
            data_00251D68->slot8(0xa0, y, text);
            if (unknown_54 == i) {
                data_00251D68->slot3(0x14, 0xffffff00);
            } else {
                data_00251D68->slot3(0x14, 0xffffffff);
            }
            if (unknown_60[i] > 0) {
                if (unknown_70[i]) {
                    func_00145CCB(text, "Key Data(%s) %d", data_0020CF40[unknown_60[i]], unknown_70[i]);
                } else {
                    func_00145CCB(text, "Get Key Data(%s)", data_0020CF40[unknown_60[i]]);
                }
            } else {
                func_00145CCB(text, "Nothing");
            }
            data_00251D68->slot8(0x190, y, text);
        }
        data_00251D68->slot3(0x14, 0xffffffff);
        break;
    }
    case 0x11: {
        unsigned int i;
        unsigned int y;
        for (i = 0, y = 0x78; y < 0xc8; i++, y += 0x14) {
            data_00251D68->slot3(0x14, 0xffffffff);
            func_00145CCB(text, "Player %d", i);
            data_00251D68->slot8(0xa0, y, text);
            if (unknown_54 == i) {
                data_00251D68->slot3(0x14, 0xffffff00);
            } else {
                data_00251D68->slot3(0x14, 0xffffffff);
            }
            if (unknown_80[i]) {
                if (unknown_70[i]) {
                    func_00145CCB(text, "Key%02d", unknown_70[i]);
                } else {
                    func_00145CCB(text, "Cancel");
                }
            } else {
                func_00145CCB(text, "Disable");
            }
            data_00251D68->slot8(0x190, y, text);
        }
        data_00251D68->slot3(0x14, 0xffffffff);
        break;
    }
    }
}
