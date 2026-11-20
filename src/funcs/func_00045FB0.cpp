/* sym: ?func_00011C80_1@Object_00044AE0@@UAEXH@Z = 0x00045FB0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Node {
    Node *func_00011BD0();
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
    virtual void __stdcall slot36(float *screen, Vector3 *point);
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
    virtual void __stdcall slot71(int value);
    virtual void __stdcall slot72();
    virtual void __stdcall slot73(int value);
    virtual void __stdcall slot74(int source, int destination);
    virtual void __stdcall slot75();
    virtual void __stdcall slot76(int value);
    virtual void __stdcall slot77();
    virtual void __stdcall slot78();
    virtual void __stdcall slot79();
    virtual void __stdcall slot80();
    virtual void __stdcall slot81(int first, int second);
};

extern Device_00251D6C *data_00251D6C;
extern int data_001FA1CC;
extern int data_001FA1D0;
extern int data_00251D58;

struct Matrix_001BA950 {
    float m[4][4];
};

void func_001BA9C0();
void func_001BAA00();
void func_001BAA50();
void __fastcall func_001BA8F0(Matrix_001BA950 *matrix);
void __fastcall func_001BA950(Matrix_001BA950 *matrix);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAF70(Vector3 *eye, Vector3 *target, int roll);

// The camera this node hangs under: its view at +0xd8.
struct Owner_00045FB0 : Node {
    char unknown_044[0x94];
    Vector3 eye;
    Vector3 target;
    int roll;
};

// The node class whose table is at 0x1CA788 (constructor 0x44940, destructor 0x44AE0).
struct Object_00044AE0 : Node {
    virtual ~Object_00044AE0();
    virtual void func_00011C80_1(int message);
    void func_00045220();
    void func_00045450();
    void func_00045910();
    void func_00045B70();

    int unknown_44;
    int shown;
    int mode;
    char unknown_050[0x24];
    int unknown_74;
    char unknown_078[0xc];
    Vector3 position;
    char unknown_090[0xc];
    Vector3 view;
    float screen[2];
    float x;
    float y;
    char unknown_0b8[0x18];
    char kind;
    char unknown_0d1[0x27];
    Matrix_001BA950 matrix;
};

// Slot 6: as slot 3 (0x45DC0) with the owner's view at +0xd8; it sets the device's states 73 and 71 only in mode 0
// and draws by kind only when shown.
void Object_00044AE0::func_00011C80_1(int message)
{
    Owner_00045FB0 *owner = (Owner_00045FB0 *)func_00011BD0();
    if (message == 2 || message == 7 || message == 12) {
        depth = 9.0f;
        return;
    }
    if (!mode) {
        func_001BAA00();
        func_001BAF70(&owner->eye, &owner->target, owner->roll);
        func_001BA950(&matrix);
        func_001BAA50();
        if (!shown)
            return;
        func_001BA9C0();
        func_001BA8F0(&matrix);
        func_001BAB20(&view, &position);
        func_001BAA50();
        data_00251D6C->slot36(screen, &view);
        x = screen[0] - 320.0f;
        y = screen[1] - 240.0f;
        if (data_001FA1D0 != 1) {
            data_001FA1D0 = 1;
            data_00251D6C->slot73(1);
        }
        if (data_001FA1CC) {
            data_001FA1CC = 0;
            data_00251D6C->slot71(0);
        }
    }
    if (data_00251D58 != -1) {
        data_00251D58 = -1;
        data_00251D6C->slot81(1, -1);
    }
    data_00251D6C->slot76(0);
    data_00251D6C->slot74(0x302, 1);
    func_001BA9C0();
    if (shown) {
        switch (kind) {
        case 0:
            func_00045220();
            break;
        case 1:
            func_00045450();
            break;
        case 2:
            func_00045910();
            break;
        }
    }
    if (unknown_74 && shown != 2)
        func_00045B70();
    func_001BAA50();
    data_00251D6C->slot74(0x302, 0x303);
    data_00251D6C->slot76(1);
}
