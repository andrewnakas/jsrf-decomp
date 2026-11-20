/* sym: ??0Object_00106390@@QAE@PAUNode@@HIHHI@Z = 0x001067A0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_00106390@@UAE@XZ = 0x00106390 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_00106390@@UAEXXZ = 0x001063A0 */
/* sym: ?func_00011C80@Object_00106390@@UAEXH@Z = 0x001068E0 */
/* sym: ?func_00011C90_2@Object_00106390@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_4@Object_00106390@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_6@Object_00106390@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C90_8@Object_00106390@@UAEXXZ = 0x000AECC0 */
struct Vector3 {
    float x;
    float y;
    float z;
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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;
};

struct Material_001067A0 {
    char unknown_00[0x30];
    unsigned int stage;
};

struct Model_001067A0 {
    char unknown_00[0xc];
    Material_001067A0 *material;
};

// What func_00025700 gives for (0xa, 0, 1, 0x3a).
struct Sprite_001067A0 {
    char unknown_00[0xc];
    Model_001067A0 *model;
    char unknown_10[0x14];
    unsigned int flags;
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
    virtual void __stdcall slot92();
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
    virtual void __stdcall slot110(unsigned int stage, int kind, unsigned int value);
};

extern Device_00251D6C *data_00251D6C;

void *func_00025700(unsigned int index, int first, int second, int third);

// A direct child of Node (table 0x1D1FD8).
struct Object_00106390 : Node {
    Object_00106390(Node *owner, int id, unsigned int flags, int ownerId, int first, unsigned int mask);
    virtual ~Object_00106390();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C90_6();
    virtual void func_00011C90_8();

    char unknown_40[4];
    unsigned int mask;
    int unknown_48;
    char unknown_4c[4];
    Sprite_001067A0 *sprite;
    void *shadow;
    int unknown_58;
    float scale;
    unsigned int color;
    int unknown_64;
    float step;
    Vector3 *target;
    Vector3 position;
    char unknown_7c[8];
    float value_84;
    char unknown_88[4];
    float value_8c;
    float value_90;
    float value_94;
    int ownerId;
};

// Keeps the owner's id, the mask and the point `first` gives (and, without bit 31 in the mask, the pointer itself),
// loads its two sprites (func_00025700) and gives the first's texture stage the colour 0xffffd600 (slot 110 of
// data_00251D6C).
Object_00106390::Object_00106390(Node *owner, int id, unsigned int flags, int ownerId, int first, unsigned int mask)
    : Node(owner, id, flags)
{
    Vector3 *point = (Vector3 *)first;
    this->mask = mask;
    unknown_58 = 0;
    scale = 1.0f;
    this->ownerId = ownerId;
    if ((mask & 0x80000000) == 0) {
        target = point;
    }
    position.x = point->x;
    position.y = point->y;
    position.z = point->z;
    unknown_48 = 0;
    color = 0xffffd600;
    unknown_64 = 0;
    value_8c = -32.0f;
    value_90 = 24.0f;
    value_94 = 1220.0f;
    value_84 = 10.0f;
    sprite = (Sprite_001067A0 *)func_00025700(0xa, 0, 1, 0x3a);
    if (sprite) {
        sprite->flags &= ~1;
        sprite->flags |= 1;
    }
    shadow = func_00025700(0xa, 0, 2, 5);
    step = 0.06666667f;
    data_00251D6C->slot110(sprite->model->material->stage, 1, 0xffffd600);
}
