struct Record_00070530 {
    unsigned int value;
    char unknown_04[0x1c];
    int unknown_20;
    int unknown_24;
};

struct Transform_000704E0 {
    float scale;
    float unknown_04;
    float unknown_08;
    float unknown_0c;
    float unknown_10;
    float rate;
};

struct Object_00070850 {
    char unknown_00[0xa0];
    int values[0x12];
    Record_00070530 records[1];

    void func_000704E0(int index, Transform_000704E0 *transform);
};

// Fills `transform` for record `index`: 1, 0, 0, 0, 1 and the record's first word (unsigned) times 0.0234375.
void Object_00070850::func_000704E0(int index, Transform_000704E0 *transform)
{
    transform->scale = 1.0f;
    transform->unknown_04 = 0.0f;
    transform->unknown_08 = 0.0f;
    transform->unknown_0c = 0.0f;
    transform->unknown_10 = 1.0f;
    transform->rate = records[index].value * 0.0234375f;
}
