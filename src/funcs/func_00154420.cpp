/* cflags: /Oy- */
struct Matrix {
    unsigned long m[4][4];
};

// The matrix the device keeps for transform state 1, and the identity matrix.
extern Matrix data_00264EF8;
extern Matrix data_0022E700;

// Sets a transform (Direct3D 8's SetTransform: state, matrix).
long __stdcall func_0018CC60(unsigned long state, const Matrix *matrix);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_00154420(int state, const void *matrix);  // slot 27

    char unknown_04[0x60];
    const Matrix **view;
};

// Slot 27: sets transform state to the matrix (to the identity without one, to the matrix +0x64 points at for
// -1); keeps a copy of transform 1's at 0x264EF8.
long __stdcall Object_001E0F00::func_00154420(int state, const void *matrix)
{
    if (matrix == (const void *)-1) {
        func_0018CC60(state, *view);
        return 0;
    }
    if (matrix) {
        const Matrix *source = (const Matrix *)matrix;
        if (state != 1) {
            func_0018CC60(state, source);
        } else {
            data_00264EF8.m[0][0] = source->m[0][0];
            data_00264EF8.m[0][1] = source->m[0][1];
            data_00264EF8.m[0][2] = source->m[0][2];
            data_00264EF8.m[0][3] = source->m[0][3];
            data_00264EF8.m[1][0] = source->m[1][0];
            data_00264EF8.m[1][1] = source->m[1][1];
            data_00264EF8.m[1][2] = source->m[1][2];
            data_00264EF8.m[1][3] = source->m[1][3];
            data_00264EF8.m[2][0] = source->m[2][0];
            data_00264EF8.m[2][1] = source->m[2][1];
            data_00264EF8.m[2][2] = source->m[2][2];
            data_00264EF8.m[2][3] = source->m[2][3];
            data_00264EF8.m[3][0] = source->m[3][0];
            data_00264EF8.m[3][1] = source->m[3][1];
            data_00264EF8.m[3][2] = source->m[3][2];
            data_00264EF8.m[3][3] = source->m[3][3];
            func_0018CC60(1, source);
        }
    } else {
        func_0018CC60(state, &data_0022E700);
    }
    return 0;
}
