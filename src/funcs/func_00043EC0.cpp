/* sym: ?func_00011C80@Object_000432E0@@UAEXH@Z = 0x00043EC0 */
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
    virtual void __stdcall slot30();
    virtual void __stdcall slot31();
    virtual void __stdcall slot32();
    virtual void __stdcall slot33();
    virtual void __stdcall slot34();
    virtual void __stdcall slot35();
    virtual void __stdcall slot36();
    virtual void __stdcall slot37();
    virtual void __stdcall slot38();
    virtual void __stdcall slot39();
    virtual void __stdcall slot40();
    virtual void __stdcall slot41();
    virtual void __stdcall slot42();
    virtual void __stdcall slot43();
    virtual void __stdcall slot44();
    virtual void __stdcall slot45();
    virtual void __stdcall slot46();
    virtual void __stdcall slot47();
    virtual void __stdcall slot48();
    virtual void __stdcall slot49();
    virtual void __stdcall slot50();
    virtual void __stdcall slot51();
    virtual void __stdcall slot52();
    virtual void __stdcall slot53();
    virtual void __stdcall slot54();
    virtual void __stdcall slot55();
    virtual void __stdcall slot56();
    virtual void __stdcall slot57();
    virtual void __stdcall slot58();
    virtual void __stdcall slot59();
    virtual void __stdcall slot60();
    virtual void __stdcall slot61();
    virtual void __stdcall slot62();
    virtual void __stdcall slot63();
    virtual void __stdcall slot64();
    virtual void __stdcall slot65();
    virtual void __stdcall slot66();
    virtual void __stdcall slot67();
    virtual void __stdcall slot68();
    virtual void __stdcall slot69();
    virtual void __stdcall slot70();
    virtual void __stdcall slot71();
    virtual void __stdcall slot72();
    virtual void __stdcall slot73();
    virtual void __stdcall slot74();
    virtual void __stdcall slot75();
    virtual void __stdcall slot76();
    virtual void __stdcall slot77();
    virtual void __stdcall slot78();
    virtual void __stdcall slot79();
    virtual void __stdcall slot80();
    virtual void __stdcall slot81();
    virtual void __stdcall slot82();
    virtual void __stdcall slot83();
    virtual void __stdcall slot84();
    virtual void __stdcall slot85();
    virtual void __stdcall slot86();
    virtual void __stdcall slot87();
    virtual void __stdcall slot88();
    virtual void __stdcall slot89();
    virtual void __stdcall slot90();
    virtual void __stdcall slot91();
    virtual void __stdcall slot92(int enable);
    virtual void __stdcall slot93();
    virtual void __stdcall slot94();
    virtual void __stdcall slot95();
    virtual void __stdcall slot96();
    virtual void __stdcall slot97();
    virtual void __stdcall slot98();
    virtual void __stdcall slot99();
    virtual void __stdcall slot100();
    virtual void __stdcall slot101();
    virtual void __stdcall slot102();
    virtual void __stdcall slot103();
    virtual void __stdcall slot104();
    virtual void __stdcall slot105();
    virtual void __stdcall slot106();
    virtual void __stdcall slot107();
    virtual void __stdcall slot108();
    virtual void __stdcall slot109();
    virtual void __stdcall slot110();
    virtual void __stdcall slot111();
    virtual void __stdcall slot112();
    virtual void __stdcall slot113(int enable);
};

extern Device_00251D6C *data_00251D6C;

struct Motion_0005F060;

struct Object_0006A960 {
    int func_0006AC10(int area);
};

extern Object_0006A960 data_0020C6C0;

void func_001BA9C0();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAA50();
void func_001BB230(float x, float y, float z);

struct Model_00044400 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(Motion_0005F060 *motion, float time);

    char unknown_04[0x54];
    float alpha;
    float unknown_5c;
};

extern void *data_00231CD0[18];
extern void *data_00231D18[9];

// One entry (0x54 bytes, as in 0x43C00).
struct Entry_00043370 {
    float position[3];
    unsigned int kind;
    int area;
    unsigned int timer;
    int active;
    int hit;
    float time;
    float time_24;
    float alpha;
    float unknown_2c;
    char unknown_30[0x24];
};

// The node class whose table is at 0x1CA678 (constructor 0x43C00, destructor 0x432E0).
struct Object_000432E0 : Node {
    virtual ~Object_000432E0();
    virtual void func_00011C80(int message);
    int func_000435B0(float *alpha);

    Entry_00043370 *entries;
    unsigned int count;
};

// Slot 3: draws the active entries whose area is drawn (func_0006AC10 of 0x20C6C0), each at its place scaled by its
// alpha. Message 0 (with the device's slot 92 on and slot 113 off) draws the model of its kind (models 0, 1, 3, 3, 2,
// 12 with motions 0, 0, 2, 2, 1, 5) when func_000435B0 says so and marks the entry hit; message 1 draws model 13
// with motion 6 for a hit entry of kind 5.
void Object_000432E0::func_00011C80(int message)
{
    switch (message) {
    case 0:
        data_00251D6C->slot92(1);
        data_00251D6C->slot113(0);
        for (unsigned int i = 0; i < count; i++) {
            if (entries[i].active && data_0020C6C0.func_0006AC10(entries[i].area)) {
                func_001BA9C0();
                func_001BAAA0(entries[i].position);
                func_001BB230(entries[i].alpha, entries[i].alpha, entries[i].alpha);
                switch (entries[i].kind) {
                case 0:
                    if (func_000435B0(&((Model_00044400 *)data_00231CD0[0])->alpha)) {
                        ((Model_00044400 *)data_00231CD0[0])->unknown_5c = entries[i].unknown_2c;
                        ((Model_00044400 *)data_00231CD0[0])->slot5((Motion_0005F060 *)data_00231D18[0], entries[i].time);
                        entries[i].hit = 1;
                    }
                    break;
                case 1:
                    if (func_000435B0(&((Model_00044400 *)data_00231CD0[1])->alpha)) {
                        ((Model_00044400 *)data_00231CD0[1])->unknown_5c = entries[i].unknown_2c;
                        ((Model_00044400 *)data_00231CD0[1])->slot5((Motion_0005F060 *)data_00231D18[0], entries[i].time);
                        entries[i].hit = 1;
                    }
                    break;
                case 2:
                    if (func_000435B0(&((Model_00044400 *)data_00231CD0[3])->alpha)) {
                        ((Model_00044400 *)data_00231CD0[3])->unknown_5c = entries[i].unknown_2c;
                        ((Model_00044400 *)data_00231CD0[3])->slot5((Motion_0005F060 *)data_00231D18[2], entries[i].time);
                        entries[i].hit = 1;
                    }
                    break;
                case 3:
                    if (func_000435B0(&((Model_00044400 *)data_00231CD0[3])->alpha)) {
                        ((Model_00044400 *)data_00231CD0[3])->unknown_5c = entries[i].unknown_2c;
                        ((Model_00044400 *)data_00231CD0[3])->slot5((Motion_0005F060 *)data_00231D18[2], entries[i].time);
                        entries[i].hit = 1;
                    }
                    break;
                case 4:
                    if (func_000435B0(&((Model_00044400 *)data_00231CD0[2])->alpha)) {
                        ((Model_00044400 *)data_00231CD0[2])->unknown_5c = entries[i].unknown_2c;
                        ((Model_00044400 *)data_00231CD0[2])->slot5((Motion_0005F060 *)data_00231D18[1], entries[i].time);
                        entries[i].hit = 1;
                    }
                    break;
                case 5:
                    if (func_000435B0(&((Model_00044400 *)data_00231CD0[0])->alpha)) {
                        ((Model_00044400 *)data_00231CD0[12])->unknown_5c = entries[i].unknown_2c;
                        ((Model_00044400 *)data_00231CD0[12])->slot5((Motion_0005F060 *)data_00231D18[5], entries[i].time);
                        entries[i].hit = 1;
                    }
                    break;
                }
                func_001BAA50();
            }
        }
        data_00251D6C->slot92(0);
        data_00251D6C->slot113(1);
        break;
    case 1:
        data_00251D6C->slot92(1);
        for (unsigned int i = 0; i < count; i++) {
            if (entries[i].active && data_0020C6C0.func_0006AC10(entries[i].area)) {
                func_001BA9C0();
                func_001BAAA0(entries[i].position);
                func_001BB230(entries[i].alpha, entries[i].alpha, entries[i].alpha);
                if (entries[i].kind == 5 && entries[i].hit) {
                    ((Model_00044400 *)data_00231CD0[13])->unknown_5c = entries[i].unknown_2c;
                    ((Model_00044400 *)data_00231CD0[13])->slot5((Motion_0005F060 *)data_00231D18[6], entries[i].time_24);
                }
                func_001BAA50();
            }
        }
        data_00251D6C->slot92(0);
        break;
    }
}
