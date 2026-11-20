struct Vector3 {
    float x;
    float y;
    float z;
};

struct Mark_00117560 {
    Vector3 position;
    float x;
    float y;
    int value;
};

struct Kind_002226E8 {
    int value;
    char unknown_04[8];
};

struct Object_00117510 {
    char unknown_000[0x48];
    Mark_00117560 marks[30];
    char unknown_318[0xf0];
    unsigned int count;

    void func_00117560(int kind, Vector3 *position, float x, float y);
};

extern Kind_002226E8 data_002226E8[];

// Adds a mark while fewer than 30 are set: the first word of the kind's entry in data_002226E8, a copy of the
// position and the two floats.
void Object_00117510::func_00117560(int kind, Vector3 *position, float x, float y)
{
    if (count < 30) {
        marks[count].value = data_002226E8[kind].value;
        marks[count].position = *position;
        marks[count].x = x;
        marks[count].y = y;
        count++;
    }
}
