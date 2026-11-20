/* sym: ??0Object_000F7990@@QAE@PAUNode@@HIHMH@Z = 0x000F7990 */
struct Node;

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Object 0x1164: a direct child of Node (table 0x1CF338) that holds a resource at 0x48; the layout at 0x10c.
struct Object_000F7990 {
    Object_000F7990(Node *owner, int id, unsigned int flags, int mode, float value, int argument);
    virtual ~Object_000F7990();

    char unknown_004[0x108];
    int mode;
    char unknown_110[0x10];
    float value_120;
    char unknown_124[0xc];
};

// Creates object 0x1164 under object 0x1163 when it does not exist (flags 0x100, layout 0, value 1.5), then gives it
// layout 1 and the value at 0x120.
void func_000F7AF0(float value)
{
    if (!data_0022FCE0->func_000128C0(0x1164)) {
        new Object_000F7990((Node *)data_0022FCE0->func_000128C0(0x1163), 0x1164, 0x100, 0, 1.5f, 0);
    }
    Object_000F7990 *object = (Object_000F7990 *)data_0022FCE0->func_000128C0(0x1164);
    if (object) {
        object->mode = 1;
    }
    object = (Object_000F7990 *)data_0022FCE0->func_000128C0(0x1164);
    if (object) {
        object->value_120 = value;
    }
}
