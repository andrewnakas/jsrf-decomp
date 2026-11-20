struct Matrix {
    unsigned long m[4][4];

    void func_00154250();
};

// The matrix the device keeps for transform state 1.
extern Matrix data_00264EF8;

// Reads a transform (Direct3D 8's GetTransform: state, matrix).
long __stdcall func_0018CD70(unsigned long state, Matrix *matrix);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots).
struct Object_001E0F00 {
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
    virtual void __stdcall slot16();
    virtual void __stdcall slot17();
    virtual void __stdcall slot18();
    virtual void __stdcall slot19();
    virtual void __stdcall slot20();
    virtual void __stdcall slot21();
    virtual void __stdcall slot22();
    virtual void __stdcall slot23();
    virtual void __stdcall slot24();
    virtual void __stdcall slot25();
    virtual long __stdcall func_001542A0(unsigned long argument1, unsigned long argument2,
                                         unsigned long argument3);  // slot 26
};

// Slot 26: copies transform argument1 into the matrix argument2 points at (state 1 from the device's own copy at
// 0x264EF8, the others from func_0018CD70) and transposes it (func_00154250) when argument3 is set.
long __stdcall Object_001E0F00::func_001542A0(unsigned long argument1, unsigned long argument2,
                                              unsigned long argument3)
{
    Matrix *matrix = (Matrix *)argument2;
    if (argument1 != 1) {
        func_0018CD70(argument1, matrix);
    } else {
        matrix->m[0][0] = data_00264EF8.m[0][0];
        matrix->m[0][1] = data_00264EF8.m[0][1];
        matrix->m[0][2] = data_00264EF8.m[0][2];
        matrix->m[0][3] = data_00264EF8.m[0][3];
        matrix->m[1][0] = data_00264EF8.m[1][0];
        matrix->m[1][1] = data_00264EF8.m[1][1];
        matrix->m[1][2] = data_00264EF8.m[1][2];
        matrix->m[1][3] = data_00264EF8.m[1][3];
        matrix->m[2][0] = data_00264EF8.m[2][0];
        matrix->m[2][1] = data_00264EF8.m[2][1];
        matrix->m[2][2] = data_00264EF8.m[2][2];
        matrix->m[2][3] = data_00264EF8.m[2][3];
        matrix->m[3][0] = data_00264EF8.m[3][0];
        matrix->m[3][1] = data_00264EF8.m[3][1];
        matrix->m[3][2] = data_00264EF8.m[3][2];
        matrix->m[3][3] = data_00264EF8.m[3][3];
    }
    if (argument3)
        matrix->func_00154250();
    return 0;
}
