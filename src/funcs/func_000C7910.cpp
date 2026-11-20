struct Vector3 {
    float x;
    float y;
    float z;
};

extern "C" void *memset(void *destination, int value, unsigned int size);

struct Object_00046670 {
    float func_000466C0(Vector3 *position, int index);
};

extern Object_00046670 data_001F93C8;

struct Node {
    virtual ~Node();

    char unknown_04[0x40];
};

struct Object_000C60C0 {
    virtual void func_000C6090();
    virtual void func_000C60C0();
};

struct Tuning_000C7910 {
    char unknown_00[0x28];
    int value_28;
};

struct Body_000C7910 {
    char unknown_00[0x30];
    Tuning_000C7910 *tuning;
};

// The child of Node whose table is at 0x1CE1C8 (destructor func_000C7240).
struct Object_000C7910 : Node, Object_000C60C0 {
    virtual void func_000C7910();

    Vector3 last;
    int value_54;
    char unknown_058[4];
    int value_5c;
    float speed;
    float lift;
    char unknown_068[0x20];
    float ground;
    char unknown_08c[0x10];
    int value_9c;
    int value_a0;
    Vector3 start;
    char unknown_0b0[0xc];
    int value_bc;
    char unknown_0c0[4];
    Vector3 heading;
    Vector3 position;
    Vector3 point_dc;
    char unknown_0e8[4];
    int value_ec;
    int value_f0;
    int value_f4;
    int value_f8;
    char unknown_0fc[0x30];
    Vector3 slide;
    char unknown_138[4];
    int slot_13c;
    char unknown_140[0xc];
    int value_14c;
    int value_150;
    int value_154;
    char unknown_158[0x14];
    float height;
    char unknown_170[4];
    int value_174;
    float scale_178;
    float scale_17c;
    int value_180;
    char unknown_184[0x10];
    int value_194;
    int value_198;
    char unknown_19c[0xc];
    int value_1a8;
    int value_1ac;
    int value_1b0;
    char unknown_1b4[8];
    int state;
    int last_state;
    int count;
    char unknown_1c8[4];
    int value_1cc;
    char unknown_1d0[0x4c];
    int value_21c;
    char unknown_220[0xc];
    int value_22c;
    char unknown_230[0x184];
    Body_000C7910 *body;

    void func_000C9D70();
};

// Restarts the object (func_000C9D70 first): the last position, the position and the point at 0xdc all go back to the
// start at 0xa4 (0x16c keeps its height); speeds, timers, motion blends and flags words are cleared, the state and the
// last state become 6, 0x14c takes the body's tuning value at 0x28, 0x13c becomes -1, the heading and the slide are
// zeroed, the scales at 0x178/0x17c become 1 and the ground height under the start is taken (func_000466C0).
void Object_000C7910::func_000C7910()
{
    func_000C9D70();
    point_dc = start;
    position = start;
    last = start;
    height = last.y;
    value_22c = 0;
    value_21c = 0;
    count = 0;
    value_194 = 0;
    value_198 = 0;
    value_1a8 = 0;
    value_1b0 = 0;
    value_1ac = 0;
    value_1cc = 0;
    value_5c = 0;
    value_54 = 0;
    value_bc = 1;
    last_state = 6;
    state = 6;
    value_14c = body->tuning->value_28;
    value_150 = 0;
    lift = 0.0f;
    speed = 0.0f;
    value_f8 = 0;
    value_f4 = 0;
    value_f0 = 0;
    value_a0 = 0;
    value_ec = 0;
    value_154 = 0;
    value_180 = 0;
    slot_13c = -1;
    memset(&slide, 0, sizeof(slide));
    memset(&heading, 0, sizeof(heading));
    value_9c = 0;
    value_174 = 0;
    scale_178 = 1.0f;
    scale_17c = 1.0f;
    ground = data_001F93C8.func_000466C0(&last, -1);
}
