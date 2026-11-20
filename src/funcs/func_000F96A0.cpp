/* sym: ??0Object_000F96A0@@QAE@PAUNode@@HIHHIPBDHHHH@Z = 0x000F96A0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_000F96A0@@UAE@XZ = 0x000F80C0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000F96A0@@UAEXXZ = 0x000F8B10 */
/* sym: ?func_00011C80@Object_000F96A0@@UAEXH@Z = 0x000F8130 */
/* sym: ?func_00011C90_2@Object_000F96A0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_1@Object_000F96A0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90_6@Object_000F96A0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_3@Object_000F96A0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000F96A0@@UAEXH@Z = 0x000B3DE0 */
extern "C" void *memcpy(void *destination, const void *source, unsigned int size);

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C90_5();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C90_7();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C90_9();
    virtual void func_00011C80_4(int argument);

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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

int func_000FE690(const char *text);

// A direct child of Node (table 0x1D07B0, destructor func_000F80C0) that shows a "$r"-ended text.
struct Object_000F96A0 : Node {
    Object_000F96A0(Node *owner, int id, unsigned int flags, int x, int y, unsigned int color, const char *text,
                    int first, int second, int third, int last);
    virtual ~Object_000F96A0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    void func_000F9090();

    char unknown_040[4];
    int unknown_044;
    int last;
    char *text;
    int unknown_050;
    char unknown_054[0x100];
    int unknown_154;
    char unknown_158[4];
    int unknown_15c;
    char unknown_160[4];
    int unknown_164;
    int unknown_168;
    int unknown_16c;
    int unknown_170;
    int unknown_174;
    int first;
    unsigned int color;
    char unknown_180[0xc];
    int third;
    int x;
    int y;
    char unknown_198[4];
    int alpha;
    int second;
};

// Keeps a copy of the text (up to its "$r" end, func_000FE690), its place, colour (24 bits) and the four numbers,
// with alpha 0xff, and lays the text out (func_000F9090). Without a text it marks itself and its children as dead.
Object_000F96A0::Object_000F96A0(Node *owner, int id, unsigned int flags, int x, int y, unsigned int color,
                                 const char *text, int first, int second, int third, int last)
    : Node(owner, id, flags)
{
    this->last = last;
    unsigned int length = func_000FE690(text);
    if (length <= 0 || text == 0) {
        func_00011BE0(this);
        func_00011C20(child);
    }
    this->x = x;
    this->y = y;
    this->color = color & 0xffffff;
    this->text = 0;
    this->text = (char *)operator new(length);
    memcpy(this->text, text, length);
    this->third = third;
    this->first = first;
    unknown_050 = 0;
    this->second = second;
    unknown_044 = 0;
    unknown_154 = 0;
    unknown_15c = 0;
    unknown_168 = 0;
    unknown_170 = 0;
    unknown_174 = 0;
    unknown_16c = 0;
    unknown_164 = 0;
    alpha = 0xff;
    func_000F9090();
}
