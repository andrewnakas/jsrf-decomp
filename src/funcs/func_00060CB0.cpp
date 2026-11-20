/* sym: ??0Object_00062390@@QAE@PAUNode@@HIPAUDesc_00060A40@@1H@Z = 0x00060CB0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_00062390@@UAE@XZ = 0x00062390 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
extern "C" void *memset(void *destination, int value, unsigned int size);

struct Vector3 {
    float x;
    float y;
    float z;
};

void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);

// A description an entry is built from (0x66c bytes).
struct Desc_00060A40 {
    char unknown_000[0x100];
    Vector3 position;
    Vector3 direction;
    char unknown_118[0xf8];
    int rate;
    char unknown_214[8];
    int spawns;
    char unknown_220[0x2c];
    int count;
    char unknown_250[0xc];
    int life;
    char unknown_260[4];
    int mode;
    char unknown_268[0x404];
};

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();

    char unknown_04[0x40];
};

// An entry (table 0x1CB040, destructor 0x62390; 0x1558 bytes).
struct Object_00062390 : Node {
    Object_00062390(Node *owner, int id, unsigned int flags, Desc_00060A40 *desc, Desc_00060A40 *second, int size);
    virtual ~Object_00062390();

    void func_0005F6B0();
    void func_0005F970(Desc_00060A40 desc);

    void SetFrom(Desc_00060A40 desc)
    {
        from = desc;
        func_0014C410(&from.direction, &from.direction);
        blending = 1;
    }

    void SetTo(Desc_00060A40 desc)
    {
        to = desc;
        func_0014C410(&to.direction, &to.direction);
        blending = 1;
    }

    char unknown_044[0xe0];
    int blending;
    char unknown_128[0x34];
    int unknown_15c;
    char unknown_160[0x1c];
    Desc_00060A40 desc;
    Desc_00060A40 from;
    Desc_00060A40 to;
    char unknown_14c0[0x58];
    int unknown_1518;
    char unknown_151c[0x38];
    int size;
};

// Clears the entry, sizes its particle count to what the description (and the second one, when given) can have
// alive at once ((life + 1) * spawns * rate / 60 + 1, at most the description's count), keeps the mode (1 becomes 2
// in both), allocates (func_0005F6B0) and takes the description (func_0005F970). With a second description the
// entry blends: the first and the second are copied to +0x7e8 / +0xe54 with their directions normalised.
Object_00062390::Object_00062390(Node *owner, int id, unsigned int flags, Desc_00060A40 *desc, Desc_00060A40 *second,
                                 int size)
    : Node(owner, id, flags)
{
    memset(unknown_044, 0, 0x1514);
    int count = desc->count;
    this->desc.count = count;
    int alive = (desc->life + 1) * desc->spawns * desc->rate / 60 + 1;
    if (second) {
        int other = (second->life + 1) * (second->spawns + 1) * second->rate / 60 + 1;
        if (alive <= other) {
            alive = other;
        }
    }
    if (count > alive) {
        this->desc.count = alive;
    }
    this->desc.mode = desc->mode;
    this->size = size;
    if (this->desc.mode == 1) {
        desc->mode = 2;
        this->desc.mode = 2;
    }
    func_0005F6B0();
    func_0005F970(*desc);
    if (second) {
        SetFrom(*desc);
        SetTo(*second);
    }
    unknown_1518 = 1;
    unknown_15c = -1;
}
