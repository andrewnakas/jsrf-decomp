struct Vector3 {
    float x;
    float y;
    float z;
};

// A record of the list at 0x14c.
struct Record_000FF090 {
    int value;
    Vector3 position;
};

// Object 0x1163 (constructor func_000FF230, destructor func_000FEC60).
struct Object_000FEDB0 {
    char unknown_000[0x14c];
    Record_000FF090 records[0xc0];
    unsigned int count;

    void func_000FF090(int value, const Vector3 *position);
};

// Adds a record (the value and the position) to the list at 0x14c while it holds fewer than 191.
void Object_000FEDB0::func_000FF090(int value, const Vector3 *position)
{
    if (count < 0xbf) {
        records[count].value = value;
        records[count].position.x = position->x;
        records[count].position.y = position->y;
        records[count].position.z = position->z;
        count++;
    }
}
