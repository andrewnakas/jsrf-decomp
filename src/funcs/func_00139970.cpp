/* sym: ??0Object_001379E0@@QAE@PAUNode@@HI@Z = 0x00139970 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_001379E0@@UAE@XZ = 0x001379E0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_001379E0@@UAEXXZ = 0x0013A340 */
/* sym: ?func_00011C80@Object_001379E0@@UAEXH@Z = 0x0013A240 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Light_00046920 {
    int unknown_00;
    unsigned int color_04;
    unsigned int color_08;
    int unknown_0c;
    Vector3 direction;
    char unknown_1c[0x24];
    unsigned int color_40;
    int unknown_44;
    unsigned int color_48;
    int unknown_4c;
    int value_50;
    char unknown_54[0x1c];
};

struct Object_00046670 {
    void func_00046740(Light_00046920 *light);
    void func_00046920(Light_00046920 *light);
    void func_00046940(int enable);
};

// The device at data_00251D6C: slot 74 sets the blend factors, slot 82 a render state.
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
    virtual void __stdcall slot74(int source, int destination);
    virtual void __stdcall slot75();
    virtual void __stdcall slot76();
    virtual void __stdcall slot77();
    virtual void __stdcall slot78();
    virtual void __stdcall slot79();
    virtual void __stdcall slot80();
    virtual void __stdcall slot81();
    virtual void __stdcall slot82(int stage, int value);
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

// The menu class whose table is at 0x1DEA60.
struct Object_001379E0 : Node {
    Object_001379E0(Node *owner, int id, unsigned int flags);
    virtual ~Object_001379E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);

    int value_44;
    char unknown_048[4];
    int values_4c[5];
    char unknown_060[0x24c];
    int value_2ac;
    int value_2b0;
    float value_2b4;
    int value_2b8;
    unsigned char alpha;
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    void *animation;
    void *model;
    int value_2c8;
    char unknown_2cc[0xe8];
    int value_3b4;
    int values_3b8[4];
    int value_3c8;
    int value_3cc;

    void func_00138100();
};

extern Object_00046670 data_001F93C8;
extern Device_00251D6C *data_00251D6C;
extern int data_00251D44;

void *func_00025700(unsigned int index, int first, int second, int third);

// Sets flag 0x200, points the light straight along z in white (func_00046920, func_00046740) and turns it off
// (func_00046940), sets render state 0 to 2 and the blend factors 0x302/0x303, the colour at +0x2BC to 100, lays out
// the cells (func_00138100), clears the rest and loads resources 0x12/1/3 (+0x2C0) and 0x12/1/2/0xd (+0x2C4).
Object_001379E0::Object_001379E0(Node *owner, int id, unsigned int flags) : Node(owner, id, flags)
{
    this->flags |= 0x200;
    value_2b0 = 0;
    value_44 = 0;
    Light_00046920 light;
    data_001F93C8.func_00046920(&light);
    light.color_48 = 0xffffff;
    light.color_40 = 0xffffff;
    light.direction.x = 0.0f;
    light.direction.y = 0.0f;
    light.direction.z = 1.0f;
    light.value_50 = 0;
    light.color_04 = 0xffffff;
    light.color_08 = 0;
    data_001F93C8.func_00046740(&light);
    data_001F93C8.func_00046940(0);
    if (data_00251D44 != 2) {
        data_00251D44 = 2;
        data_00251D6C->slot82(0, 2);
    }
    data_00251D6C->slot74(0x302, 0x303);
    value_2b4 = 1.0f;
    value_2b8 = 0;
    blue = 100;
    green = 100;
    red = 100;
    alpha = 100;
    for (unsigned int i = 0; i < 5; i++) {
        values_4c[i] = 0;
    }
    func_00138100();
    value_2ac = 0;
    value_3b4 = 0;
    for (unsigned int j = 0; j < 4; j++) {
        values_3b8[j] = 0;
    }
    value_3c8 = -1;
    value_3cc = -1;
    animation = func_00025700(0x12, 1, 3, 0);
    model = func_00025700(0x12, 1, 2, 0xd);
    value_2c8 = 0;
}
