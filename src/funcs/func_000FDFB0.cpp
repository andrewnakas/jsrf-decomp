/* sym: ??0Object_000FAB60@@QAE@PAUNode@@HIHHHH@Z = 0x000FAB60 */
/* sym: ??0Object_000FB530@@QAE@PAUNode@@HIHHHH@Z = 0x000FB870 */
struct Node;

struct Game {
    void *func_000128C0(int id);
    int func_000128E0(int first, int last);
};

struct Object_00043700 {
    int func_00043700();
};

// An entry of the 0x14-byte tables at 0x21FBC4 (one per language): the count at +0xc.
struct Line_000FA780 {
    char unknown_00[0xc];
    unsigned int count;
    int unknown_10;
};

// The child of Object_000FDDC0 whose table is at 0x1D08E0.
struct Object_000FAB60 {
    Object_000FAB60(Node *owner, int id, unsigned int flags, int kind, int index, int first, int second);
    unsigned int func_000FA7D0();
    void func_000FA780(int index, int first, int second);

    char unknown_00[0x100];
};

// The child of Object_000FDDC0 whose table is at 0x1D1B20.
struct Object_000FB530 {
    Object_000FB530(Node *owner, int id, unsigned int flags, int kind, int index, int first, int second);
    unsigned int func_000FB5B0();
    void func_000FB550(int index, int first, int second);

    char unknown_00[0xe4];
};

// Object 0x1165 (constructor func_000FE740, destructor func_000FDF30).
struct Object_000FDF30 {
    char unknown_000[0xbc];
    int id_bc;

    void func_000FDFB0(int index, int first, int second, int type);
};

extern Game *data_0022FCE0;
extern Object_00043700 data_001FC724;
extern Line_000FA780 *data_0021FBC4[];

void func_00116810();

// Entry 6 (id at 0xbc): with no child yet, creates one (an Object_000FAB60 for type 1, else an Object_000FB530,
// kind 6) with the index and values; otherwise, while the child's count is below that of the index's entry in the
// table for the language (0x21FBC4), passes them on to it (func_000FA780, or func_00116810 then func_000FB550).
void Object_000FDF30::func_000FDFB0(int index, int first, int second, int type)
{
    if (id_bc == -1) {
        id_bc = data_0022FCE0->func_000128E0(0x1208, 0x1288);
        if (type == 1) {
            new Object_000FAB60((Node *)this, id_bc, 0x100, 6, index, first, second);
        } else {
            new Object_000FB530((Node *)this, id_bc, 0x100, 6, index, first, second);
        }
        return;
    }
    Line_000FA780 *lines = data_0021FBC4[data_001FC724.func_00043700()];
    if (type == 1) {
        Object_000FAB60 *child = (Object_000FAB60 *)data_0022FCE0->func_000128C0(id_bc);
        if (lines[index].count > child->func_000FA7D0()) {
            child->func_000FA780(index, first, second);
        }
    } else {
        Object_000FB530 *child = (Object_000FB530 *)data_0022FCE0->func_000128C0(id_bc);
        if (lines[index].count > child->func_000FB5B0()) {
            func_00116810();
            child->func_000FB550(index, first, second);
        }
    }
}
