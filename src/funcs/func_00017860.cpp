struct Mesh_00017860 {
    int unknown_00;
    int count;
    int unknown_08;
    int extra;
};

struct Frame_00017860 {
    char unknown_00[0x24];
    Mesh_00017860 *mesh;
    Frame_00017860 *child;
    Frame_00017860 *next;
};

struct Object_00016200 {
    int func_00017860(Frame_00017860 *frame);
};

// Bytes needed to copy a frame tree: 0x30 per frame, plus 0x34 and 12 bytes for each of three per counted item and
// one per extra item of its mesh, over the frame, its children and the frames after it.
int Object_00016200::func_00017860(Frame_00017860 *frame)
{
    int size = 0;
    for (; frame; frame = frame->next) {
        size += 0x30;
        if (frame->mesh)
            size += 0x34 + (frame->mesh->count * 3 + frame->mesh->extra) * 12;
        size += func_00017860(frame->child);
    }
    return size;
}
