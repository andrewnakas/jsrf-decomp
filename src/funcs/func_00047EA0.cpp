// A frame (0x6c bytes): a word tested first, its first child at +0x60 and its next sibling at +0x64.
struct Frame_000479D0 {
    int unknown_00;
    char unknown_04[0x5c];
    Frame_000479D0 *child;
    Frame_000479D0 *next;
    char unknown_68[0x4];
};

struct Object_00047470 {
    void func_00047EA0(Frame_000479D0 *frame, int *count, int *used);
};

// Counts the frames of a tree (a frame, its siblings and, recursively, their children) and those whose first word is
// set. The first frame must exist.
void Object_00047470::func_00047EA0(Frame_000479D0 *frame, int *count, int *used)
{
    do {
        (*count)++;
        if (frame->unknown_00) {
            (*used)++;
        }
        if (frame->child) {
            func_00047EA0(frame->child, count, used);
        }
        frame = frame->next;
    } while (frame);
}
