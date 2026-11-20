/* sym: ??0Object_00134880@@QAE@PAUNode@@HI@Z = 0x001346F0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_00134880@@UAE@XZ = 0x00134880 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_00134880@@UAEXXZ = 0x00134F00 */
/* sym: ?func_00011C80@Object_00134880@@UAEXH@Z = 0x00134B30 */
/* sym: ??0Object_00135130@@QAE@PAUNode@@HI@Z = 0x00135290 */
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

// The child the constructor adds (constructor func_00135290).
struct Object_00135130 {
    Object_00135130(Node *owner, int id, unsigned int flags);

    char unknown_00[0xb0];
};

// The class whose table is at 0x1DE828: overrides slots 1 and 3 of Node.
struct Object_00134880 : Node {
    Object_00134880(Node *owner, int id, unsigned int flags);
    virtual ~Object_00134880();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);

    int value_44;
    int value_48;
    unsigned char value_4c;
    char unknown_04d[0x17];
    int value_64;
    char unknown_068[0xb4];
    unsigned char first[0x118];
    char unknown_234[0x4f8];
    float speed;
    float level;
    unsigned char unknown_734;
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char pulse;
    unsigned char falling;
};

extern Object_00046670 data_001F93C8;
extern Device_00251D6C *data_00251D6C;
extern int data_00251D44;

// Sets flag 0x200, adds an Object_00135130 (id 0x1de6, flags 1), points the light straight along z in white
// (func_00046920, func_00046740) and turns it off (func_00046940), sets render state 0 to 2 and the blend factors
// 0x302/0x303 on the device, the colour bytes at +0x734 to 100, the speed at +0x72c to 1, and clears the rest.
Object_00134880::Object_00134880(Node *owner, int id, unsigned int flags) : Node(owner, id, flags)
{
    this->flags |= 0x200;
    value_64 = 0;
    new Object_00135130(this, 0x1de6, 1);
    Light_00046920 light;
    data_001F93C8.func_00046920(&light);
    light.value_50 = 0;
    light.color_48 = 0xffffff;
    light.color_40 = 0xffffff;
    light.direction.x = 0.0f;
    light.direction.y = 0.0f;
    light.direction.z = 1.0f;
    light.color_04 = 0xffffff;
    light.color_08 = 0;
    data_001F93C8.func_00046740(&light);
    data_001F93C8.func_00046940(0);
    if (data_00251D44 != 2) {
        data_00251D44 = 2;
        data_00251D6C->slot82(0, 2);
    }
    data_00251D6C->slot74(0x302, 0x303);
    unknown_734 = 100;
    red = 100;
    green = 100;
    blue = 100;
    pulse = 100;
    value_44 = 0;
    value_48 = 0;
    value_4c = 0;
    level = 0.0f;
    falling = 0;
    speed = 1.0f;
    for (int i = 0; i < 0x118; i++) {
        first[i] = 0;
    }
}
