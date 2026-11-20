/* sym: ??0Object_001E3C08@@QAE@PAUUnknown@@@Z = 0x001722F0 */
/* sym: ??1Object_001E3C08@@UAE@XZ = 0x001721D0 */
extern "C" long __cdecl _InterlockedIncrement(long volatile *addend);
extern "C" long __cdecl _InterlockedDecrement(long volatile *addend);
void __cdecl operator delete(void *memory) throw();

struct Guid;
struct Caps;
struct Format;

// The controlling object of an aggregate.
struct Unknown {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

// The DirectSound object at +0xc and its release (0x19E4DC).
struct Sound;
unsigned long __stdcall func_0019E4DC(Sound *sound);

// A list whose nodes are 0x10 bytes: the next and previous links and an 8-byte value. Its erase (0x16E2C0) is the
// same function as that of the lists with 0xc-byte and 0x20-byte nodes.
struct Object_0016E310 {
    struct Node {
        Node *next;
        Node *previous;
        int value[2];
    };

    // The list's iterator: a class around the node pointer.
    struct iterator {
        Node *node;

        iterator(Node *node) : node(node)
        {
        }
    };

    Object_0016E310()
    {
        head = func_0016E310();
        size = 0;
    }
    ~Object_0016E310()
    {
        func_0016E2C0(iterator(head == 0 ? 0 : head->next), iterator(head));
        operator delete(head);
        head = 0;
        size = 0;
    }

    Node *func_0016E310();
    iterator func_0016E2C0(iterator first, iterator last) throw();

    char allocator;
    Node *head;
    unsigned int size;
};

// The entries of the std::vector at +0x3bc (0x254 bytes each).
struct Item {
    char unknown[0x254];
};

// A std::vector of them.
struct ItemList {
    ItemList()
    {
        first = 0;
        last = 0;
        end = 0;
    }
    ~ItemList()
    {
        tidy();
    }
    // Frees the block and leaves the vector empty.
    void tidy()
    {
        if (first)
            operator delete(first);
        first = 0;
        last = 0;
        end = 0;
    }

    char allocator;
    Item *first;
    Item *last;
    Item *end;
};

// A vector of three floats.
struct Vector3 {
    float x;
    float y;
    float z;
};

// The buffer's 3D parameters (0x4c bytes; the layout of DirectSound's DS3DBUFFER and three factors).
struct Buffer3D {
    unsigned long size;
    Vector3 position;
    Vector3 velocity;
    unsigned long insideConeAngle;
    unsigned long outsideConeAngle;
    Vector3 coneOrientation;
    long coneOutsideVolume;
    float minDistance;
    float maxDistance;
    unsigned long mode;
    float distanceFactor;
    float rolloffFactor;
    float dopplerFactor;
};

// The buffer's reverb send (0x24 bytes; the layout of the I3DL2 buffer properties).
struct BufferReverb {
    long direct;
    long directHF;
    long room;
    long roomHF;
    float roomRolloffFactor;
    long obstruction;
    float obstructionLFRatio;
    long occlusion;
    float occlusionLFRatio;
};

// The state at +0x3e4 (0x354 bytes); +0x10 points at the 0x100 bytes after it.
struct State {
    char unknown_00[0xc];
    unsigned long unknown_0c;
    unsigned char *data;
    char unknown_14[0x340];
};

// The number of live sound objects (MGameSound8 and the buffers).
extern long data_00265198;

// The class whose table is at 0x1E3C08 (0x848 bytes, 30 slots; the destructor is the last). MGameSound8's 0x1695A0
// creates it for flag 0x10, otherwise 0x1E3B90's class; the two share QueryInterface and Release, and slots 5, 16 and
// 18 are the library's E_NOTIMPL stub 0x1504B0 (the linker folded the identical functions).
struct Object_001E3C08 {
    Object_001E3C08(Unknown *outer);
    virtual long __stdcall func_00170170(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00177FE0();
    virtual unsigned long __stdcall func_0016FCE0();
    virtual long __stdcall func_00172640(void *argument);
    virtual long __stdcall func_0016FDF0(Caps *caps);
    virtual long __stdcall func_001504B0(unsigned long value);
    virtual long __stdcall func_00170200(void *argument);
    virtual long __stdcall func_001710E0(void *argument);
    virtual long __stdcall func_00171B50();
    virtual long __stdcall func_0016FD90(unsigned long *value);
    virtual long __stdcall func_00171E00(unsigned long flags);
    virtual long __stdcall func_00170C50(void *argument);
    virtual long __stdcall func_0016FEE0(void *argument1, void *argument2);
    virtual long __stdcall func_00170920(unsigned long value1, unsigned long value2);
    virtual long __stdcall func_00171030();
    virtual long __stdcall func_00172070();
    virtual long __stdcall func_001504B0_1(unsigned long value);
    virtual long __stdcall func_0016FEB0(int *value);
    virtual long __stdcall func_001504B0_2(unsigned long value);
    virtual long __stdcall func_0016FFE0(int value);
    virtual long __stdcall func_00170970(void *argument1, void *argument2);
    virtual long __stdcall func_001726F0(void *argument);
    virtual long __stdcall func_00172540(void *argument1, void *argument2);
    virtual long __stdcall func_00171EC0(void *argument);
    virtual long __stdcall func_00170070(int *value);
    virtual long __stdcall func_00170D10(unsigned int index);
    virtual long __stdcall func_00170090(void *argument);
    virtual long __stdcall func_001700B0(void *argument);
    virtual long __stdcall func_001700D0(void *argument1, void *argument2);
    virtual ~Object_001E3C08();

    Unknown *outer;
    long references;
    Sound *sound;
    void *ready;
    unsigned long unknown_14;
    unsigned long unknown_18[6];
    unsigned long unknown_30[0x12];
    Buffer3D buffer3D;
    BufferReverb bufferReverb;
    long unknown_e8;
    unsigned long unknown_ec;
    unsigned long unknown_f0;
    unsigned long unknown_f4;
    unsigned long unknown_f8;
    unsigned long unknown_fc;
    unsigned long unknown_100;
    unsigned long unknown_104;
    long first;
    unsigned long second;
    unsigned long unknown_110;
    unsigned long unknown_114;
    unsigned long unknown_118;
    unsigned long unknown_11c;
    unsigned long unknown_120;
    unsigned long unknown_124;
    unsigned long unknown_128;
    unsigned long unknown_12c;
    unsigned long unknown_130;
    char unknown_134[0x23c];
    unsigned long unknown_370;
    unsigned long unknown_374;
    unsigned long unknown_378;
    unsigned long unknown_37c;
    unsigned long unknown_380;
    unsigned long unknown_384;
    unsigned long unknown_388[0xc];
    unsigned long unknown_3b8;
    ItemList items;
    unsigned int selected;
    Object_0016E310 list;
    unsigned long unknown_3dc;
    unsigned long unknown_3e0;
    State state;
    unsigned char data[0x100];
    unsigned long unknown_838;
    unsigned long unknown_83c;
    unsigned long unknown_840;
    unsigned long unknown_844;
};

extern "C" void *__cdecl memset(void *destination, int value, unsigned int size);

// Constructor: one reference, no DirectSound objects, volumes -10000, the list and the item vector empty; holds a
// reference to the controlling object, if any, clears the blocks, sets the 3D parameters to their defaults and counts
// the object in.
Object_001E3C08::Object_001E3C08(Unknown *outer)
    : outer(outer), references(1), sound(0), ready(0), unknown_14(0), unknown_e8(-10000), unknown_ec(0),
      unknown_f0(0), unknown_f4(0), unknown_f8(0), unknown_fc(0), unknown_100(0), unknown_104(0), first(-10000),
      second(0), unknown_110(0x53), unknown_114(0), unknown_118(0), unknown_11c(0), unknown_120(0), unknown_124(0),
      unknown_128(0), unknown_12c(0), unknown_130(0), unknown_370(0), unknown_374(0), unknown_37c(0),
      unknown_380(0), selected(0), unknown_3dc(0), unknown_3e0(0), unknown_838(0), unknown_844(0)
{
    if (this->outer)
        this->outer->slot1();
    memset(unknown_30, 0, sizeof(unknown_30));
    memset(unknown_18, 0, sizeof(unknown_18));

    memset(&buffer3D, 0, sizeof(buffer3D));
    buffer3D.size = sizeof(buffer3D);
    buffer3D.position.x = 0.0f;
    buffer3D.position.y = 0.0f;
    buffer3D.position.z = 0.0f;
    buffer3D.velocity.x = 0.0f;
    buffer3D.velocity.y = 0.0f;
    buffer3D.velocity.z = 0.0f;
    buffer3D.insideConeAngle = 360;
    buffer3D.outsideConeAngle = 360;
    buffer3D.coneOrientation.x = 0.0f;
    buffer3D.coneOrientation.y = 0.0f;
    buffer3D.coneOrientation.z = 1.0f;
    buffer3D.minDistance = 1.0f;
    buffer3D.maxDistance = 1000000000.0f;
    buffer3D.coneOutsideVolume = 0;
    buffer3D.mode = 0;

    memset(&bufferReverb, 0, sizeof(bufferReverb));
    bufferReverb.direct = 0;
    bufferReverb.directHF = 0;
    bufferReverb.room = 0;
    bufferReverb.roomHF = 0;
    bufferReverb.roomRolloffFactor = 0.0f;
    bufferReverb.obstruction = 0;
    bufferReverb.obstructionLFRatio = 0.0f;
    bufferReverb.occlusion = 0;
    bufferReverb.occlusionLFRatio = 0.25f;

    memset(&state, 0, sizeof(state));
    state.unknown_0c = 0;
    state.data = data;
    memset(unknown_388, 0, sizeof(unknown_388));
    _InterlockedIncrement(&data_00265198);
}
