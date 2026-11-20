/* sym: ??0Object_000FDDC0@@QAE@PAUNode@@HIHHHPBDHH@Z = 0x000FD870 */
struct Node;

struct Game {
    int func_000128E0(int first, int last);
};

// The child of Node whose table is at 0x1D1BA8 (destructor func_000FD9B0): it keeps a copy of the text up to its
// first "$r" (func_000FE690).
struct Object_000FDDC0 {
    Object_000FDDC0(Node *owner, int id, unsigned int flags, int kind, int value, int first, const char *text,
                    int second, int third);

    char unknown_00[0x90];
};

// An entry of the list at 0xdc: what func_000FE370 passes to the child it creates.
struct Entry_000FDF30 {
    int value;
    int first;
    char *text;
    int second;
    int third;
    int unknown_14;
};

// Object 0x1165 (constructor func_000FE740, destructor func_000FDF30).
struct Object_000FDF30 {
    char unknown_000[0xa4];
    int ids[7];
    int pending[7];
    Entry_000FDF30 entries[7];

    void func_000FE370(int index);
};

extern Game *data_0022FCE0;

// Creates the child for entry `index` when it is pending: a new id from func_000128E0(0x1208, 0x1288) into the list
// at 0xa4 and an Object_000FDDC0 under itself with the entry's values; then frees the entry's text. With nothing
// pending it only clears the id.
void Object_000FDF30::func_000FE370(int index)
{
    if (pending[index] == -1) {
        ids[index] = -1;
        return;
    }
    ids[index] = data_0022FCE0->func_000128E0(0x1208, 0x1288);
    new Object_000FDDC0((Node *)this, ids[index], 0x100, index, entries[index].value, entries[index].first,
                        entries[index].text, entries[index].second, entries[index].third);
    pending[index] = -1;
    if (entries[index].text) {
        operator delete(entries[index].text);
        entries[index].text = 0;
    }
}
