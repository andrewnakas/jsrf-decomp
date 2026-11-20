struct Model_00133370 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);

    void func_00047F40(int value);
};

// The scene at +0x7c: its models from +0x10 are the three entries of a menu.
struct Scene_0007D900 {
    char unknown_00[0x10];
    Model_00133370 *models[3];
};

struct Object_0007C250 {
    char unknown_00[0x54];
    int selected;
    char unknown_58[0x24];
    Scene_0007D900 *scene;

    void func_0007D900();
};

// Entry 1 of the table at 0x20D408: colours the scene's three entry models (0xFFFFA000 for the selected one at +0x54,
// 0xFF646464 for the others) and runs slot 5 (0, 0) of each.
void Object_0007C250::func_0007D900()
{
    for (int i = 0; i < 3; i++) {
        if (i != selected) {
            scene->models[i]->func_00047F40(0xff646464);
        } else {
            scene->models[i]->func_00047F40(0xffffa000);
        }
    }
    scene->models[0]->slot5(0, 0);
    scene->models[1]->slot5(0, 0);
    scene->models[2]->slot5(0, 0);
}
