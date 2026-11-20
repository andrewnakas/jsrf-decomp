// An animation: its frame count at +0x2.
struct Animation_0007DFA0 {
    short unknown_00;
    short count;
};

// The models the scene at +0x7c keeps (+0x8, +0xc): slot 5 draws one frame of an animation.
struct Model_0007DFA0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(Animation_0007DFA0 *animation, float frame);
};

struct Scene_0007DFA0 {
    char unknown_00[0x8];
    Model_0007DFA0 *first;
    Model_0007DFA0 *second;
};

struct Object_0007C250 {
    char unknown_00[0x7c];
    Scene_0007DFA0 *scene;
    Animation_0007DFA0 **animation;

    void func_0007D900();
    void func_0007DFD0();
};

// Entry 4 of the draw table at 0x20D3E0: draws the scene's second model at the last frame of the animation at +0x80
// and runs func_0007D900.
void Object_0007C250::func_0007DFD0()
{
    scene->second->slot5(*animation, (float)(*animation)->count - 1.0f);
    func_0007D900();
}
