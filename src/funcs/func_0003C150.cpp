/* const: 0x4b104 */
/* const: 0x4b0f8 */
/* const: 0x4b130 */
/* const: 0x2583c */
/* const: 0x25850 */
/* const: 0x12c28 */
/* const: 0x4b0e8 */
/* const: 0x4b0ec */
/* sym: ??0Object_0003C2B0@@QAE@PAUNode@@HI@Z = 0x0003C150 */
/* sym: ??1Object_0003C2B0@@UAE@XZ = 0x0003C2B0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
void *func_00025700(unsigned int index, int first, int second, int third);

struct Object_0006E130 {
    int func_0006E130(int id);
};

extern Object_0006E130 data_00252790;

// A Direct3D resource: slot 2 releases it.
struct Resource_0003C2B0 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual unsigned long __stdcall Release();
};

struct Interface_00251D74 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4();
    virtual long __stdcall slot5();
    virtual long __stdcall slot6();
    virtual long __stdcall slot7();
    virtual long __stdcall slot8();
    virtual long __stdcall slot9(int first, int second, Resource_0003C2B0 **result);
};

extern Interface_00251D74 *data_00251D74;

// The two groups of 0x28 bytes at 0x1F8B20: how many entries and the first one's index.
struct Group_0003C150 {
    int count;
    int first;
    char unknown_08[0x20];
};

extern Group_0003C150 data_001F8B20[2];

// One of the four 0x12c28-byte records at +0x48.
struct Record_0003C150 {
    int unknown_00[5];
    int ids[5];
    char unknown_28[0x12c00];
};

struct Pair_0003C150 {
    float first;
    float second;
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

// The node class whose table is at 0x1CA440 (destructor 0x3C2B0).
struct Object_0003C2B0 : Node {
    Object_0003C2B0(Node *owner, int id, unsigned int flags);
    virtual ~Object_0003C2B0();

    Resource_0003C2B0 *resource;
    Record_0003C150 records[2][2];
    int unknown_4b0e8;
    int unknown_4b0ec;
    float unknown_4b0f0[2];
    int unknown_4b0f8[2];
    Pair_0003C150 unknown_4b100[2];
    Pair_0003C150 unknown_4b110[2];
    int unknown_4b120[2];
    int unknown_4b128[2];
    int unknown_4b130;
};

// Sets up the two sets of values at +0x4b0f0, makes the resource at +0x44 (0x140 bytes; none when that fails) and
// fills both record pairs with the ids of the entries of the two groups at 0x1F8B20 (kind 0x11).
Object_0003C2B0::Object_0003C2B0(Node *owner, int id, unsigned int flags)
    : Node(owner, id, flags)
{
    for (int k = 0; k < 2; k++) {
        unknown_4b0f0[k] = 1.5f;
        unknown_4b0f8[k] = -1;
        unknown_4b100[k].first = 1.0f;
        unknown_4b100[k].second = 1.0f;
        unknown_4b110[k].first = 0.0f;
        unknown_4b120[k] = 0;
        unknown_4b110[k].second = 0.0f;
        unknown_4b128[k] = 0xff;
    }
    unknown_4b130 = 0;
    if (data_00251D74->slot9(0x140, 0, &resource) < 0) {
        resource = 0;
    }
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < data_001F8B20[j].count; i++) {
            records[0][j].unknown_00[i] = 0;
            records[0][j].ids[i] =
                data_00252790.func_0006E130((int)func_00025700(0x11, data_001F8B20[j].first + i, 0, 0));
            records[1][j].unknown_00[i] = 0;
            records[1][j].ids[i] =
                data_00252790.func_0006E130((int)func_00025700(0x11, data_001F8B20[j].first + i, 0, 0));
        }
    }
    unknown_4b0e8 = 0;
    unknown_4b0ec = 0;
}
