/* sym: ?func_00011C80@Object_001044F0@@UAEXH@Z = 0x001045D0 */
struct Object_00043700 {
    int func_00043700();
};

extern Object_00043700 data_001FC724;

float func_0003D750(float scale, int text);
void func_0003D5D0(float x, float y, float scale, unsigned int color, float first, float second, int text);
unsigned int func_0014C690(float value);

// The texts by language: the plain ones, the kind-3 ones and 0x17 per kind.
extern int *data_0021CFCC[];
extern int *data_0021D5A4[];
extern int *data_0021D554[];

// The places the labels are drawn at.
struct Place_00220B18 {
    float x;
    float y;
};

extern Place_00220B18 data_00220B18[];

// The object above the label: shown with bit 28 of 0x16ac.
struct Holder_001045D0 {
    char unknown_0000[0x16ac];
    unsigned int flags;
};

struct Node {
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
    Holder_001045D0 *parent;
    Node *child;
    Node *previous;
    Node *next;
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;
};

// A label node (table 0x1D1ED8, constructor func_00104490).
struct Object_001044F0 : Node {
    virtual void func_00011C80(int argument);

    int unknown_040;
    int text;
    int unknown_048;
    int kind;
    int unknown_050;
    int place;
    int unknown_058;
    int unknown_05c;
    float alpha;
    float slide;
};

// Slot 3 (the pass): while the parent has bit 28 of 0x16ac set and the alpha at 0x60 is not 0, draws the text (0x44)
// of its kind (0x4c: 3, below 0, or 0x17 texts per kind) in the current language (func_00043700 of data_001FC724) at
// its place (0x54, data_00220B18), right-aligned by the slide at 0x64 (func_0003D750 for the width), scale 1.1, white
// at the alpha; the text scale is 1, or 0.8 when func_00043700 gives 0. The argument is not read.
void Object_001044F0::func_00011C80(int)
{
    if (!parent) {
        return;
    }
    if (!(parent->flags & 0x10000000)) {
        return;
    }
    if (alpha == 0.0f) {
        return;
    }
    float scale = 1.0f;
    if (!data_001FC724.func_00043700()) {
        scale = 0.8f;
    }
    if (kind == 3) {
        float width = func_0003D750(scale, data_0021D5A4[data_001FC724.func_00043700()][text]);
        func_0003D5D0(data_00220B18[place].x - (1.0f - slide) * width, data_00220B18[place].y, 1.1f,
                      func_0014C690(alpha * 255.0f) << 24 | 0xffffff, scale, scale,
                      data_0021D5A4[data_001FC724.func_00043700()][text]);
    } else if (kind < 0) {
        float width = func_0003D750(scale, data_0021CFCC[data_001FC724.func_00043700()][text]);
        func_0003D5D0(data_00220B18[place].x - (1.0f - slide) * width, data_00220B18[place].y, 1.1f,
                      func_0014C690(alpha * 255.0f) << 24 | 0xffffff, scale, scale,
                      data_0021CFCC[data_001FC724.func_00043700()][text]);
    } else {
        float width = func_0003D750(scale, data_0021D554[data_001FC724.func_00043700()][kind * 0x17 + text]);
        func_0003D5D0(data_00220B18[place].x - (1.0f - slide) * width, data_00220B18[place].y, 1.1f,
                      func_0014C690(alpha * 255.0f) << 24 | 0xffffff, scale, scale,
                      data_0021D554[data_001FC724.func_00043700()][kind * 0x17 + text]);
    }
}
