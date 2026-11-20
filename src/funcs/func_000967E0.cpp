/* sym: ??0Object_000967E0@@QAE@PAUNode@@HIPAUObject_000963E0@@H@Z = 0x000967E0 */
/* sym: ??1Object_000967E0@@UAE@XZ = 0x00096920 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
struct Vector3 {
    float x;
    float y;
    float z;
};

// A segment (0x18 bytes): two points.
struct Segment_000967E0 {
    Vector3 start;
    Vector3 end;
};

// Two words kept with each segment.
struct Pair_000967E0 {
    int first;
    int second;
};

struct Resource_000967E0;

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

// The node with two sets of up to 120 segments (table 0x1CD320, constructor func_000963E0): the segments at 0x7c, their
// pairs at 0x16fc and the counts at 0x1e7c.
struct Object_000963E0 : Node {
    Object_000963E0(Node *owner, int id, unsigned int flags);
    virtual ~Object_000963E0();

    char unknown_44[0x30];
    Resource_000967E0 *buffers[2];
    Segment_000967E0 segments[2][120];
    Pair_000967E0 pairs[2][120];
    unsigned int counts[2];
};

// One of two direct children of Node with the same slots 2, 3, 5 and 6 (tables 0x1CD360 and 0x1CD3E0); this one
// has the table at 0x1CD360 (destructor func_00096920): one set of segments copied from an Object_000963E0.
struct Object_000967E0 : Node {
    Object_000967E0(Node *owner, int id, unsigned int flags, Object_000963E0 *source, int index);
    virtual ~Object_000967E0();

    Segment_000967E0 segments[120];
    Pair_000967E0 pairs[120];
    unsigned int count;
    int unknown_f48;
    int unknown_f4c;
    Resource_000967E0 *resource;
};

// Sets flag 0x20, copies set `index` of the source (its count, segments and pairs), then sets 0x168 at 0xf48 and asks
// the device for the buffer at 0xf50.
Object_000967E0::Object_000967E0(Node *owner, int id, unsigned int flags, Object_000963E0 *source, int index)
    : Node(owner, id, flags)
{
    this->flags |= 0x20;
    count = source->counts[index];
    for (unsigned int i = 0; i < count; i++) {
        segments[i].start = source->segments[index][i].start;
        segments[i].end = source->segments[index][i].end;
        pairs[i].first = source->pairs[index][i].first;
        pairs[i].second = source->pairs[index][i].second;
    }
    unknown_f48 = 0x168;
    data_00251D6C->slot54(0x142, 0xf0, 0, 0, (void **)&resource);
}
