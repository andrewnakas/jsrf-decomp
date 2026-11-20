struct Vector3 {
    float x;
    float y;
    float z;
};

struct Matrix_001BA950 {
    float m[4][4];
};

void __fastcall func_001BA8F0(Matrix_001BA950 *matrix);
void func_001BA9C0();
void __fastcall func_001BAA50();

// A shader of the context's table at +0x500: slot 3 begins (negative on failure), slot 5 sets constants, slot 4 ends.
struct Shader_00069E10 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual long __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5(int index, const void *values, int count);
};

struct Context_00251D7C {
    char unknown_000[0x500];
    Shader_00069E10 *shaders[1];
};

extern Context_00251D7C *data_00251D7C;
extern int data_00251D40;
extern float data_0020C628[4];

struct Surface_00069E10 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8();
    virtual void __stdcall slot9();
    virtual void __stdcall slot10();
    virtual void __stdcall slot11();
    virtual void __stdcall slot12();
    virtual void __stdcall slot13();
    virtual void __stdcall slot14();
    virtual void __stdcall slot15();
    virtual void __stdcall slot16(int value);
};

struct Object_00047470 {
    virtual ~Object_00047470();

    Surface_00069E10 *surface;
    char unknown_08[4];
    int *data;
    char unknown_10[8];
    int shader;
    unsigned int count;
    Matrix_001BA950 *matrices;
};

// The class whose table is at 0x1CC12C (constructor 0x69A30, destructor 0x69F00), built on Object_00047470.
struct Object_00069F00 : Object_00047470 {
    virtual ~Object_00069F00();

    char unknown_24[0x50];
    float unknown_74;
    char unknown_78[4];
    float unknown_7c;

    void func_00069E10(int unused, Matrix_001BA950 *matrices);
};

// Draws through the context's shader +0x18: constants 0 (data_0020C628), 1 (+0x74, 0, +0x7c) and two words 6 and 7,
// then one matrix per frame from register 0xb on (func_001BA8F0 of each of `matrices`), presents +0xc's first word
// through slot 16 of the surface and counts the draw in data_00251D40.
void Object_00069F00::func_00069E10(int, Matrix_001BA950 *matrices)
{
    Shader_00069E10 *shader = data_00251D7C->shaders[this->shader];
    if (shader->slot3() >= 0) {
        Vector3 values;
        values.x = unknown_74;
        values.y = 0.0f;
        values.z = unknown_7c;
        shader->slot5(0, data_0020C628, 1);
        shader->slot5(1, &values, 1);
        shader->slot5(6, 0, 0x30);
        shader->slot5(7, 0, 3);
        func_001BA9C0();
        for (unsigned int i = 0; i < count; i++) {
            func_001BA8F0(&matrices[i]);
            shader->slot5(i * 4 + 0xb, 0, 2);
        }
        func_001BAA50();
        surface->slot16(*data);
        data_00251D40++;
        shader->slot4();
    }
}
