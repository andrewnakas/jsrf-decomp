// What a frame keeps at +0x24: two pointers (+0x0, +0x8), stored as offsets in a loaded file.
struct Mesh_00017860 {
    char *first;
    int unknown_04;
    char *second;
};

// A frame of a loaded tree: its mesh (+0x24), first child (+0x28) and next sibling (+0x2c).
struct Frame_00017860 {
    char unknown_00[0x24];
    Mesh_00017860 *mesh;
    Frame_00017860 *child;
    Frame_00017860 *next;
};

struct Object_00016200 {
    void func_00019770(Frame_00017860 *frame, int base);
};

// Turns the offsets of a loaded frame tree into pointers by adding the base: each frame's mesh and its two pointers,
// the children (recursively) and the siblings. Null offsets stay null.
void Object_00016200::func_00019770(Frame_00017860 *frame, int base)
{
    while (frame) {
        if (frame->mesh) {
            frame->mesh = (Mesh_00017860 *)((char *)frame->mesh + base);
            if (frame->mesh->first)
                frame->mesh->first += base;
            if (frame->mesh->second)
                frame->mesh->second += base;
        }
        if (frame->child) {
            frame->child = (Frame_00017860 *)((char *)frame->child + base);
            func_00019770(frame->child, base);
        }
        if (!frame->next)
            break;
        frame = frame->next = (Frame_00017860 *)((char *)frame->next + base);
    }
}
