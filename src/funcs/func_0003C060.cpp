/* sym: ?func_00011C80@Object_0003BB10@@UAEXH@Z = 0x0003C060 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Motion_0005F060;

void func_001BA9C0();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAA50();
void func_001BB230(float x, float y, float z);

// The Direct3D device.
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
};

extern Device_00251D6C *data_00251D6C;

// The model at +0x54: slot 5 draws it in a pose of a motion; its alpha at +0x58.
struct Model_0003C060 {
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

// One entry (0x5c bytes): its position, state, time and scales.
struct Entry_0003BC80 {
    Vector3 position;
    char unknown_0c[0xc];
    unsigned int state;
    float time;
    int drawn;
    unsigned int countdown;
    float scaleX;
    float scaleY;
    float scaleZ;
    float unknown_34;
    char unknown_38[0x24];
};

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

// The node class whose table is at 0x1CA3E8 (constructor 0x3B940, destructor 0x3BB10): overrides slot 3.
struct Object_0003BB10 : Node {
    virtual void func_00011C80(int argument);
    int func_0003BCD0(float *alpha);

    int unknown_44;
    unsigned int count;
    char unknown_4c[4];
    Entry_0003BC80 *entries;
    Model_0003C060 *model;
    Motion_0005F060 *motion;
};

// Slot 3: message 0 draws, with slot 92 of the device on, every entry in state 1 or 2 that func_0003BCD0 lets through:
// the model at its position scaled by its x and y scales, its alpha times the z scale, +0x5c from the entry, in the
// pose of the motion at +0x58 at the entry's time; the entry is then marked drawn.
void Object_0003BB10::func_00011C80(int argument)
{
    if (!argument) {
        data_00251D6C->slot92(1);
        for (unsigned int i = 0; i < count; i++) {
            if (entries[i].state > 0 && entries[i].state <= 2) {
                func_001BA9C0();
                func_001BAAA0(&entries[i].position.x);
                func_001BB230(entries[i].scaleX, entries[i].scaleY, 1.0f);
                if (func_0003BCD0(&model->alpha)) {
                    model->alpha = entries[i].scaleZ * model->alpha;
                    model->unknown_5c = entries[i].unknown_34;
                    model->slot5(motion, entries[i].time);
                    entries[i].drawn = 1;
                }
                func_001BAA50();
            }
        }
        data_00251D6C->slot92(0);
    }
}
