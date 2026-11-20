struct Vector3 {
    float x;
    float y;
    float z;
};

struct Model_00111A90 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);
};

struct Object_00014A80 {
    int func_00014A10(Vector3 *position);
};

struct State_00111A90 {
    int value;
};

struct Object_001118F0 {
    char unknown_000[0xb4];
    Model_00111A90 *model;
    char unknown_0b8[0x70];
    float scale;
    char unknown_12c[0x58];
    State_00111A90 *state;

    void func_00111A90();
};

extern Object_00014A80 data_001EB938;
void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void func_001BB230(float x, float y, float z);

// Member of the 0x1D27C8 class: when the state at +0x184 is 7 and data_001EB938 gives a position
// (func_00014A10), draws the model at +0xb4 (its slot 5) there, the position scaled by 0.01 and the model by the
// float at +0x128.
void Object_001118F0::func_00111A90()
{
    if (state->value == 7) {
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
