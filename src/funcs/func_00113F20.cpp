struct Vector3 {
    float x;
    float y;
    float z;
};

struct Model_00113F20 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);
};

struct Menu_00113F20 {
    char unknown_000[0x1c4];
    int *kind;
};

struct Object_00014A80 {
    int func_00014A10(Vector3 *position);
};

struct Game {
    void *func_000128C0(int id);
};

struct Object_00113C40 {
    char unknown_000[0xa4];
    float scale;
    char unknown_0a8[0x18];
    Model_00113F20 *model;

    void func_00113F20();
};

extern Game *data_0022FCE0;
extern Object_00014A80 data_001EB938;

void func_001BA9C0();
void __fastcall func_001BAA50();
void func_001BB230(float x, float y, float z);
void __fastcall func_001BAAA0(float *vector);

// Member of the class whose table is at 0x1D2B28: when menu object 0x1167's kind is 7 and data_001EB938 reports a
// position (func_00014A10), draws the model at +0xC0 (its slot 5) there, the position scaled by 0.01 and the model
// by the float at +0xA4.
void Object_00113C40::func_00113F20()
{
    Menu_00113F20 *menu = (Menu_00113F20 *)data_0022FCE0->func_000128C0(0x1167);
    if (*menu->kind == 7) {
        Vector3 position;
        if (data_001EB938.func_00014A10(&position)) {
            func_001BA9C0();
            position.x *= 0.01f;
            position.y *= 0.01f;
            position.z *= 0.01f;
            func_001BAAA0(&position.x);
            func_001BB230(scale, scale, scale);
            if (model) {
                model->slot5(0, 0);
            }
            func_001BAA50();
        }
    }
}
