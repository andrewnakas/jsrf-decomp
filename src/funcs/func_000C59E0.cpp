struct Vector3 {
    float x;
    float y;
    float z;
};

// The table of boxes at data_00257CE0.
struct Object_000BFF60 {
    int func_000BFF80(Vector3 *position);
};

extern Object_000BFF60 *data_00257CE0;

// The owner at 0x4 of the Object_000CC600 family.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0x14];
    int area;
    char unknown_68[0x54];
    int *areaOut;

    int func_000C59E0();
};

// Looks up the box of data_00257CE0 that holds the position at 0x44 (func_000BFF80, -1 for none), stores its
// index at 0x64 and through the pointer at 0xbc; true when there is one.
int Object_000C5B50::func_000C59E0()
{
    int index = data_00257CE0->func_000BFF80(&position);
    *areaOut = index;
    area = index;
    return index >= 0;
}
