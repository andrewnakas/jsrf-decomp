/* const: 0x80000 */
/* sym: ??0Object_0006EC00@@QAE@PAUNode@@HIHHHH@Z = 0x0006F200 */
/* sym: ??0Object_00012170@@QAE@PAUNode@@HI@Z = 0x00012170 */
/* sym: ??1Object_00012170@@UAE@XZ = 0x000121D0 */
/* sym: ??1Object_0006EC00@@UAE@XZ = 0x0006EC00 */
extern "C" unsigned int strlen(const char *);
extern "C" void *memcpy(void *, const void *, unsigned int);

void *func_00025700(unsigned int index, int first, int second, int third);
void func_00024620(unsigned int color, float step);

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

struct Object_00012170 : Node {
    Object_00012170(Node *owner, int id, unsigned int flags);
    virtual ~Object_00012170();

    char unknown_44[0x50];
    int unknown_94;
};

// Object 0x12b0 (0xd0 bytes; table 0x1CC660, destructor 0x6EC00): shows a text (`sound` is its address).
struct Object_0006EC00 : Object_00012170 {
    Object_0006EC00(Node *owner, int id, unsigned int flags, int sound, int first, int flags2, int value);
    virtual ~Object_0006EC00();

    int flags2;
    int value;
    char *text;
    void *sounds[4];
    int unknown_b4;
    int first;
    float position[3];
    int unknown_c8;
    int unknown_cc;
};

// Keeps a copy of the text and the three values, places the text at (-32, 24, 1220) and, unless flag 0x80000 is set,
// takes four sounds (func_00025700: 0xfa, 0x69, 0x6a and 0x11); fades in from 0xaa000000 at 1/60 (func_00024620)
// when there is no first sound.
Object_0006EC00::Object_0006EC00(Node *owner, int id, unsigned int flags, int sound, int first, int flags2,
                                 int value)
    : Object_00012170(owner, id, flags)
{
    sortKey = 0xf;
    text = 0;
    unsigned int size = strlen((const char *)sound) + 1;
    text = (char *)operator new(size);
    memcpy(text, (const char *)sound, size);
    sounds[0] = 0;
    sounds[1] = 0;
    sounds[2] = 0;
    sounds[3] = 0;
    this->first = first;
    this->flags2 = flags2;
    this->value = value;
    position[0] = -32.0f;
    position[1] = 24.0f;
    position[2] = 1220.0f;
    unknown_c8 = 0;
    unknown_cc = 0;
    if (!(flags2 & 0x80000)) {
        sounds[0] = func_00025700(0xa, 0, 1, 0xfa);
        sounds[1] = func_00025700(0xa, 0, 1, 0x69);
        sounds[2] = func_00025700(0xa, 0, 1, 0x6a);
        sounds[3] = func_00025700(0xa, 0, 2, 0x11);
        unknown_b4 = 0;
    }
    if (!sounds[0]) {
        func_00024620(0xaa000000, 0.016666668f);
    }
}
