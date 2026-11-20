struct Matrix {
    unsigned long m[4][4];
};

// A matrix filled in as floats and passed on as words.
union Projection {
    float value[4][4];
    Matrix matrix;
};

// The projection the device sets for transform 1, and the device's copy of transform 1.
extern Projection data_0022E6B8;
extern Matrix data_00264EF8;

// The viewport's width and height (0x264ED0 is the device's viewport).
extern unsigned long data_00264ED8;
extern unsigned long data_00264EDC;

// Sets a transform (Direct3D 8's SetTransform: state, matrix).
long __stdcall func_0018CC60(unsigned long state, const Matrix *matrix);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    long func_00153EC0();

    char unknown_00[0x40];
    float value_40;
    char unknown_44[8];
    float value_4C;
    float value_50;
    float value_54;
    float value_58;
    float value_5C;
    float value_60;
};

// Fills in the projection at 0x22E6B8 from the viewport's aspect, the values at +0x40, +0x4C, +0x54, +0x58 and
// +0x60, keeps a copy at 0x264EF8 and sets it as transform 1.
long Object_001E0F00::func_00153EC0()
{
    float depth = value_58 * value_54;
    data_0022E6B8.value[1][1] = (float)data_00264ED8 / ((float)data_00264EDC * value_60);
    data_0022E6B8.value[2][2] = depth;
    data_0022E6B8.value[2][3] = value_54;
    data_0022E6B8.value[3][2] = value_4C - depth * value_40;
    data_00264EF8.m[0][0] = data_0022E6B8.matrix.m[0][0];
    data_00264EF8.m[0][1] = data_0022E6B8.matrix.m[0][1];
    data_00264EF8.m[0][2] = data_0022E6B8.matrix.m[0][2];
    data_00264EF8.m[0][3] = data_0022E6B8.matrix.m[0][3];
    data_00264EF8.m[1][0] = data_0022E6B8.matrix.m[1][0];
    data_00264EF8.m[1][1] = data_0022E6B8.matrix.m[1][1];
    data_00264EF8.m[1][2] = data_0022E6B8.matrix.m[1][2];
    data_00264EF8.m[1][3] = data_0022E6B8.matrix.m[1][3];
    data_00264EF8.m[2][0] = data_0022E6B8.matrix.m[2][0];
    data_00264EF8.m[2][1] = data_0022E6B8.matrix.m[2][1];
    data_00264EF8.m[2][2] = data_0022E6B8.matrix.m[2][2];
    data_00264EF8.m[2][3] = data_0022E6B8.matrix.m[2][3];
    data_00264EF8.m[3][0] = data_0022E6B8.matrix.m[3][0];
    data_00264EF8.m[3][1] = data_0022E6B8.matrix.m[3][1];
    data_00264EF8.m[3][2] = data_0022E6B8.matrix.m[3][2];
    data_00264EF8.m[3][3] = data_0022E6B8.matrix.m[3][3];
    func_0018CC60(1, &data_0022E6B8.matrix);
    return 0;
}
