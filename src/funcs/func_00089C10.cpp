struct Vector3 {
    float x;
    float y;
    float z;
};

struct Mark_00089C10 {
    Vector3 position;
    char unknown_0c[8];
    int owner;
};

struct Object_0003E750 {
    void func_0003E6F0(Mark_00089C10 *mark);
};

extern Object_0003E750 data_002314B0;

struct Object_000A1C50 {
    char unknown_000[8];
    int unknown_008;
    char unknown_00c[0x2a8];
    Mark_00089C10 mark;
    char unknown_2cc[0x9d8];
    Vector3 position;

    void func_00089C10();
};

// Fills in the mark at +0x2b4 with the position at +0xca4 and the word at +0x8, and hands it to func_0003E6F0 of
// the table object at 0x2314B0.
void Object_000A1C50::func_00089C10()
{
    mark.position.x = position.x;
    mark.position.y = position.y;
    mark.position.z = position.z;
    mark.owner = unknown_008;
    data_002314B0.func_0003E6F0(&mark);
}
