/* sym: ??0Object_000963E0@@QAE@PAUNode@@HI@Z = 0x000963E0 */
/* sym: ??1Object_000963E0@@UAE@XZ = 0x000964B0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
struct Buffer_000963E0;

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
    virtual int __stdcall slot54(int kind, unsigned int length, int usage, int format, void **buffer);
};

extern Device_00251D6C *data_00251D6C;

struct Vector3 {
    float x;
    float y;
    float z;
};

// A segment (0x18 bytes): two points.
struct Segment_000963E0 {
    Vector3 start;
    Vector3 end;
};

// Two words kept with each segment.
struct Pair_000963E0 {
    int first;
    int second;
};

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();

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

// A node (table 0x1CD320, destructor 0x964B0) with two 240-byte buffers from the device, two sets of up to 120
// segments with their pairs and counts, and a 2x2 grid of keys it frees from the game's object 0xe8 when it goes.
struct Object_000963E0 : Node {
    Object_000963E0(Node *owner, int id, unsigned int flags);
    virtual ~Object_000963E0();

    char unknown_44[0x30];
    Buffer_000963E0 *buffers[2];
    Segment_000963E0 segments[2][120];
    Pair_000963E0 pairs[2][120];
    unsigned int counts[2];
    int unknown_1e84;
    int unknown_1e88;
    int keys[2][2];
};

// Sets flag 0x20, asks the device for the two buffers and marks every key unused.
Object_000963E0::Object_000963E0(Node *owner, int id, unsigned int flags)
    : Node(owner, id, flags)
{
    this->flags |= 0x20;
    counts[0] = 0;
    counts[1] = 0;
    data_00251D6C->slot54(0x142, 0xf0, 0, 0, (void **)&buffers[0]);
    data_00251D6C->slot54(0x142, 0xf0, 0, 0, (void **)&buffers[1]);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            keys[i][j] = -1;
        }
    }
    unknown_1e84 = 0;
    unknown_1e88 = 0;
}
