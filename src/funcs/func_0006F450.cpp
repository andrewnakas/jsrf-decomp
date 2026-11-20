/* sym: ??0Object_0006EC00@@QAE@PAUNode@@HIHHHH@Z = 0x0006F200 */
/* const: 0x10003 */
struct Node;

struct Game {
    void *func_000128C0(int index);
};

extern Game *data_0022FCE0;

// Object 0x12b0 (0xd0 bytes; table 0x1CC660, destructor 0x6EC00): shows a text (`sound` is its address).
struct Object_0006EC00 {
    Object_0006EC00(Node *owner, int id, unsigned int flags, int sound, int first, int flags2, int value);

    void func_0006F100(const char *text, int first, int flags, int value);

    char unknown_00[0xd0];
};

// Creates object 0x12b0 under object 0 with the four values, or passes them to it (func_0006F100) when it exists.
void func_0006F450(int sound, int first, int flags, int value)
{
    if (data_0022FCE0->func_000128C0(0x12b0) == 0) {
        new Object_0006EC00((Node *)data_0022FCE0->func_000128C0(0), 0x12b0, 0x10003, sound, first, flags, value);
    } else {
        Object_0006EC00 *object = (Object_0006EC00 *)data_0022FCE0->func_000128C0(0x12b0);
        if (object) {
            object->func_0006F100((const char *)sound, first, flags, value);
        }
    }
}
