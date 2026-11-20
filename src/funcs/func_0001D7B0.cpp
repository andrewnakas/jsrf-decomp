struct Vector3 {
    float x;
    float y;
    float z;
};

struct Model_0001B3A0;

// A frame of a model tree: its place, angles and scale, a model, its first child and its next sibling.
struct Frame_0001D7B0 {
    Vector3 position;
    int angles[3];
    Vector3 scale;
    Model_0001B3A0 *model;
    Frame_0001D7B0 *child;
    Frame_0001D7B0 *sibling;
};

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAC50(int *angles, int zero);
void __fastcall func_001BB270(float *scale);

struct Object_00016200 {
    void func_0001B3A0(Model_0001B3A0 *model);
    void func_0001D7B0(void *frames);
};

// Draws a tree of frames: each one between func_001BA9C0 and func_001BAA50, moved, turned and scaled, its model
// (func_0001B3A0) and then its children.
void Object_00016200::func_0001D7B0(void *frames)
{
    for (Frame_0001D7B0 *frame = (Frame_0001D7B0 *)frames; frame; frame = frame->sibling) {
        func_001BA9C0();
        func_001BAAA0(&frame->position.x);
        func_001BAC50(frame->angles, 0);
        func_001BB270(&frame->scale.x);
        func_0001B3A0(frame->model);
        func_0001D7B0(frame->child);
        func_001BAA50();
    }
}
