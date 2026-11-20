struct Node;

// What func_000B9E70 reads the kind of the child to create from (at 0x28).
struct Info_000B9E70 {
    char unknown_00[0x28];
    int kind;
};

// Object 0xeb (constructor func_000BB1A0, destructor func_000BAC20).
struct Object_000BAC20 {
    char unknown_00[0xa0];
    int count;

    void func_000BAC30(Info_000B9E70 *info, int value, int unused1, int unused2);
};

int func_000B9E70(Node *owner, Info_000B9E70 *info, int value, int first, int second);

// Counts at 0xa0 and has func_000B9E70 create the child the info describes under itself (with the value and -1, -1;
// its id is not kept).
// The last two arguments are not read.
void Object_000BAC20::func_000BAC30(Info_000B9E70 *info, int value, int, int)
{
    count++;
    func_000B9E70((Node *)this, info, value, -1, -1);
}
