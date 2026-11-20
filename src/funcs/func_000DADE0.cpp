struct Vector3 {
    float x;
    float y;
    float z;
};

// One of the object's 60 places (28 bytes each, from 0x50).
struct Place_000DADE0 {
    Vector3 position;
    Vector3 direction;
    int unknown_18;
};

struct Object_000DADE0 {
    char unknown_000[0x50];
    Place_000DADE0 places[60];
    int current;

    void func_000DADE0(Vector3 *position, Vector3 *direction);
};

// Copies a position and a direction into the current place (its index at 0x6e0).
void Object_000DADE0::func_000DADE0(Vector3 *position, Vector3 *direction)
{
    places[current].position = *position;
    places[current].direction = *direction;
}
