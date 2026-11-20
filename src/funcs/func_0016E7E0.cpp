/* sym: ??1Object_001E3B90@@UAE@XZ = 0x0016E7E0 */
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

// The DirectSound object at +0xc and its release (0x19E4DC); the stream at +0x298 of the description and its release
// (0x19E50D, through the interface 0x1c bytes into the object).
struct Sound;
struct Stream;
struct SoundBuffer;
unsigned long __stdcall func_0019E4DC(Sound *sound);
unsigned long __stdcall func_0019E50D(Stream *stream);

// The system library's process heap and heap free.
void *__stdcall func_0014A838();
int __stdcall func_0014A821(void *heap, unsigned long flags, void *memory);

// A list whose nodes are 0xc bytes: the next and previous links and a 4-byte value.
struct Object_00174220 {
    struct Node {
        Node *next;
        Node *previous;
        void *value;
    };

    // The list's iterator: a class around the node pointer.
    struct iterator {
        Node *node;

        iterator(Node *node) : node(node)
        {
        }
    };

    Object_00174220()
    {
        head = func_00174220();
        size = 0;
    }
    ~Object_00174220()
    {
        func_0016E2C0(iterator(head == 0 ? 0 : head->next), iterator(head));
        operator delete(head);
        head = 0;
        size = 0;
    }

    Node *func_00174220();
    iterator func_0016E2C0(iterator first, iterator last) throw();

    char allocator;
    Node *head;
    unsigned int size;
};

// A list whose nodes are 0x10 bytes: the next and previous links and an 8-byte value. Its erase (0x16E2C0) is the
// same function as that of the list with 0xc-byte nodes.
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

// The objects the std::vector at +0x4d4 points at.
struct Voice;

// The std::vector of pointers at +0x4d4.
struct VoiceList {
    VoiceList()
    {
        first = 0;
        last = 0;
        end = 0;
    }
    ~VoiceList()
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
    Voice **first;
    Voice **last;
    Voice **end;
};

// The entries of the std::vector at +0x4e4 (0x254 bytes each).
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

// The listener's 3D parameters (0x40 bytes; the layout of DirectSound's DS3DLISTENER).
struct Listener3D {
    unsigned long size;
    Vector3 position;
    Vector3 velocity;
    Vector3 front;
    Vector3 top;
    float distanceFactor;
    float rolloffFactor;
    float dopplerFactor;
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

// The listener's reverb (0x30 bytes; the layout of the I3DL2 listener properties).
struct Reverb {
    long room;
    long roomHF;
    float roomRolloffFactor;
    float decayTime;
    float decayHFRatio;
    long reflections;
    float reflectionsDelay;
    long reverb;
    float reverbDelay;
    float diffusion;
    float density;
    float hfReference;
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

// The description at +0x28c (0x23c bytes): +4 is the flags; with flag 0x2000 the object holds the stream at +0xc and
// with flag 0x8000 the object at +0x10.
struct Description {
    unsigned long unknown_00;
    unsigned long flags;
    unsigned long unknown_08;
    Stream *stream;
    Unknown *object;
    char unknown_14[0x228];
};

// The state at +0x50c (0x354 bytes); +0x10 points at the 0x100 bytes after it.
struct State {
    char unknown_00[0xc];
    unsigned long unknown_0c;
    unsigned char *data;
    char unknown_14[0x340];
};

// The number of live sound objects (MGameSound8 and the buffers).
extern long data_00265198;

// The class whose table is at 0x1E3B90 (0x970 bytes, 30 slots; the destructor is the last). MGameSound8's 0x1695A0
// creates it, or 0x1E3C08's class with flag 0x10; the two share QueryInterface and Release.
struct Object_001E3B90 {
    Object_001E3B90(Unknown *outer);
    virtual long __stdcall func_00170170(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00177FE0();
    virtual unsigned long __stdcall func_0016FCE0();
    virtual long __stdcall func_0016FAD0(void *argument);
    virtual long __stdcall func_0016B810(Caps *caps);
    virtual long __stdcall func_0016F390(void *argument);
    virtual long __stdcall func_0016BAE0(void *argument);
    virtual long __stdcall func_0016D300(void *argument);
    virtual long __stdcall func_0016CFF0();
    virtual long __stdcall func_0016B7B0(unsigned long *value);
    virtual long __stdcall func_0016F4B0(void *argument);
    virtual long __stdcall func_0016E3C0(void *argument);
    virtual long __stdcall func_0016C310(void *argument1, void *argument2);
    virtual long __stdcall func_0016C580(unsigned long value1, unsigned long value2);
    virtual long __stdcall func_0016F8F0();
    virtual long __stdcall func_0016E5E0();
    virtual long __stdcall func_0016B8D0(const Format *format);
    virtual long __stdcall func_0016B960(int *value);
    virtual long __stdcall func_001504B0(unsigned long value);
    virtual long __stdcall func_0016E040(void *argument);
    virtual long __stdcall func_0016C440(unsigned __int64 *position, unsigned long flags);
    virtual long __stdcall func_0016FBF0(void *argument);
    virtual long __stdcall func_0016F760(void *argument1, void *argument2);
    virtual long __stdcall func_0016E130(void *argument);
    virtual long __stdcall func_0016B990(int *value);
    virtual long __stdcall func_0016C5D0(unsigned int index);
    virtual long __stdcall func_0016B9B0(void *argument);
    virtual long __stdcall func_0016B9D0(void *argument);
    virtual long __stdcall func_0016B9F0(unsigned __int64 *value, unsigned long flags);
    virtual ~Object_001E3B90();

    Unknown *outer;
    long references;
    Sound *sound;
    SoundBuffer *buffer;
    unsigned long unknown_14;
    unsigned long unknown_18;
    unsigned long unknown_1c[6];
    unsigned long unknown_34[0x12];
    unsigned long unknown_7c[0x38];
    Listener3D listener;
    Buffer3D buffer3D;
    Reverb reverb;
    BufferReverb bufferReverb;
    unsigned long unknown_23c;
    unsigned long unknown_240;
    unsigned long unknown_244;
    void *block;
    unsigned long unknown_24c;
    unsigned long unknown_250;
    unsigned long unknown_254;
    unsigned long unknown_258;
    long unknown_25c;
    unsigned long unknown_260;
    unsigned long unknown_264;
    unsigned long unknown_268;
    unsigned long unknown_26c;
    unsigned long unknown_270;
    unsigned long unknown_274;
    unsigned long unknown_278;
    unsigned long unknown_27c;
    unsigned long unknown_280;
    unsigned long unknown_284;
    unsigned long unknown_288;
    Description description;
    Object_00174220 list1;
    VoiceList voices;
    ItemList items;
    unsigned long unknown_4f4;
    Object_0016E310 list2;
    unsigned long unknown_504;
    unsigned long unknown_508;
    State state;
    unsigned char data[0x100];
    unsigned long unknown_960;
    unsigned long unknown_964;
    unsigned long unknown_968;
    unsigned long unknown_96c;
};

// Destructor: stops the buffer (slot 15), lets go of the stream and the object the description holds, of the
// DirectSound object and of the heap block, empties the item list, lets go of the controlling object and counts the
// object out; the members free the rest.
Object_001E3B90::~Object_001E3B90()
{
    func_0016E5E0();
    if ((description.flags & 0x2000) && description.stream) {
        func_0019E50D(description.stream);
        description.stream = 0;
    }
    if ((description.flags & 0x8000) && description.object) {
        description.object->slot2();
        description.object = 0;
    }
    if (sound) {
        func_0019E4DC(sound);
        sound = 0;
    }
    if (block) {
        func_0014A821(func_0014A838(), 0, block);
        block = 0;
    }
    items.tidy();
    if (outer) {
        outer->slot2();
        outer = 0;
    }
    _InterlockedDecrement(&data_00265198);
}
