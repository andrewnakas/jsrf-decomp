// A frame (0x6c bytes): a word tested first, its first child at +0x60 and its next sibling at +0x64.
struct Frame_000479D0 {
    int unknown_00;
    char unknown_04[0x5c];
    Frame_000479D0 *child;
    Frame_000479D0 *next;
    char unknown_68[0x4];
};

struct Object_00047470 {
    void func_00047E60(Frame_000479D0 *frame);
};

// Goes down the first children to the first frame with a sibling and drops the last frame of that sibling chain.
void Object_00047470::func_00047E60(Frame_000479D0 *frame)
{
    for (; frame; frame = frame->child) {
        if (frame->next) {
            for (; frame; frame = frame->next) {
                if (!frame->next->next) {
                    frame->next = 0;
                    return;
                }
            }
            return;
        }
    }
}
