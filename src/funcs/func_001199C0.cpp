/* sym: ?func_00011C80@Object_001197F0@@UAEXH@Z = 0x001199C0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BA9C0();
void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void func_001BB960(float value);

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
    virtual void __stdcall slot33(float value);
};

extern Device_00251D6C *data_00251D6C;

struct Transform_000704E0 {
    float scale;
    float unknown_04;
    float unknown_08;
    float unknown_0c;
    float unknown_10;
    float rate;
};

// A player record of the owner (0x28 bytes): whether it is in at 0x8.
struct Player_001199C0 {
    char unknown_00[8];
    int present;
    char unknown_0c[0x1c];
};

struct Object_00070850 {
    char unknown_00[0xe8];
    Player_001199C0 players[4];

    void func_00070460(int index, Transform_000704E0 *transform);
    int func_00070850(int index);
};

struct Interface_001199C0 {
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
    virtual void __stdcall slot12(int first, int second);
    virtual void __stdcall slot13(int value);
    virtual void __stdcall slot14(int first, void *data);
};

// A model with a colour (func_00047F40); its slot 5 poses it.
struct Model_00133370 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);

    Interface_001199C0 *unknown_04;

    void func_00047F40(int value);
};

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);

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

    Node *func_00011BD0();
};

// The class whose table is at 0x1D7B60: a controller's badge, built by func_001196A0 with the looked-up parts at
// 0x6c (models, place tables and a level table of group 0x12).
struct Object_001197F0 : Node {
    virtual ~Object_001197F0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);

    int value_44;
    int port;
    int player;
    int dim;
    int mode;
    char unknown_58[0x14];
    Model_00133370 *badge;
    Model_00133370 *ring;
    Model_00133370 *dot;
    Model_00133370 *mark;
    Vector3 *badgePlaces;
    Vector3 *ringPlaces;
    Vector3 *dotPlaces;
    float *levels;
    Vector3 position;
};

// Slot 3: on passes 0, 3, 5 and 8 draws at the point at 0x8c (device slot 33 at -26, then 0): in a mode (0x54) and
// with the player at 0x4c in, the ring at its port's place with the owner's func_00070460 transform and the mark
// (when dimmed, 0x50); in a mode, the badge at the player's place (grey when dimmed); then the seven dots at the
// port's places, each scaled down by the player's level row (func_00070850) when in a mode with the player in.
// Pass 7 sets the depth to 0.9.
void Object_001197F0::func_00011C80(int argument)
{
    Object_00070850 *owner = (Object_00070850 *)func_00011BD0();
    switch (argument) {
    case 0:
    case 3:
    case 5:
    case 8:
        data_00251D6C->slot33(-26.0f);
        func_001BAA00();
        func_001BAAA0(&position.x);
        if (mode && owner->players[player].present) {
            func_001BA9C0();
            func_001BAAA0(&ringPlaces[port].x);
            Transform_000704E0 transform;
            owner->func_00070460(player, &transform);
            if (ring) {
                ring->unknown_04->slot12(0, 7);
                ring->unknown_04->slot14(0, &transform);
                ring->slot5(0, 0);
                ring->unknown_04->slot13(0);
            }
            if (mark && dim) {
                mark->slot5(0, 0);
            }
            func_001BAA50();
        }
        if (mode) {
            func_001BA9C0();
            func_001BAAA0(&badgePlaces[player].x);
            if (badge) {
                if (dim) {
                    badge->func_00047F40(0xffa0a0a0);
                }
                badge->slot5(0, 0);
                if (dim) {
                    badge->func_00047F40(-1);
                }
            }
            func_001BAA50();
        }
        if (dot) {
            for (unsigned int i = 0; i < 7; i++) {
                func_001BA9C0();
                func_001BAAA0(&dotPlaces[port * 7 + i].x);
                if (mode && owner->players[player].present) {
                    func_001BB960(1.0f - levels[owner->func_00070850(player) * 7 + i]);
                }
                dot->slot5(0, 0);
                func_001BAA50();
            }
        }
        func_001BAA50();
        data_00251D6C->slot33(0.0f);
        break;
    case 7:
        depth = 0.9f;
        break;
    }
}
