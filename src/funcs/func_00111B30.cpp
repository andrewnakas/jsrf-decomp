struct Vector3 {
    float x;
    float y;
    float z;
};

struct Model_00111B30 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);
};

struct State_00111B30 {
    int value;
};

struct Object_001118F0 {
    char unknown_000[0xb0];
    Model_00111B30 *model;
    char unknown_0b4[0x74];
    float scale;
    char unknown_12c[0x58];
    State_00111B30 *state;

    void func_00111B30();
};

int func_0003BF40(Vector3 *position);
void func_001BA9C0();
void func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void func_001BB230(float x, float y, float z);

// Member of the 0x1D27C8 class: when the state at +0x184 is 4 or 12 and func_0003BF40 gives a position, draws
// the model at +0xb0 (its slot 5) there, the position scaled by 0.01 and the model by the float at +0x128.
void Object_001118F0::func_00111B30()
{
    if (state->value == 4 || state->value == 12) {
        Vector3 position;
        if (func_0003BF40(&position)) {
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
