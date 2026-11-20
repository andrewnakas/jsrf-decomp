struct Matrix {
    unsigned long m[4][4];

    void func_00154250();
};

// The Direct3D device wrapper (table 0x1E0F00).
struct Object_001E0F00 {
    virtual void __stdcall slot0();

    void func_00154360(Matrix *out);

    char unknown_04[0x60];
    Matrix **stack;
};

// Copies the matrix the pointer at +0x64 leads to into out and transposes it (func_00154250).
void Object_001E0F00::func_00154360(Matrix *out)
{
    out->m[0][0] = (*stack)->m[0][0];
    out->m[0][1] = (*stack)->m[0][1];
    out->m[0][2] = (*stack)->m[0][2];
    out->m[0][3] = (*stack)->m[0][3];
    out->m[1][0] = (*stack)->m[1][0];
    out->m[1][1] = (*stack)->m[1][1];
    out->m[1][2] = (*stack)->m[1][2];
    out->m[1][3] = (*stack)->m[1][3];
    out->m[2][0] = (*stack)->m[2][0];
    out->m[2][1] = (*stack)->m[2][1];
    out->m[2][2] = (*stack)->m[2][2];
    out->m[2][3] = (*stack)->m[2][3];
    out->m[3][0] = (*stack)->m[3][0];
    out->m[3][1] = (*stack)->m[3][1];
    out->m[3][2] = (*stack)->m[3][2];
    out->m[3][3] = (*stack)->m[3][3];
    out->func_00154250();
}
