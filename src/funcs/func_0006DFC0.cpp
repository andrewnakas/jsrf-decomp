struct Vector3 {
    float x;
    float y;
    float z;
};

struct Entry_0006DB80 {
    Vector3 position;
    char unknown_0c[4];
    int key;
    char unknown_14[0x40];
    Entry_0006DB80 *next;
};

struct Object_0006DB80 {
    int unknown_00;
    Entry_0006DB80 *buckets[0x100];

    void func_0006DFC0(int key, const Vector3 *position);
};

// Stores a copy of a vector at +0x0 of the entry registered under a key, when there is one.
void Object_0006DB80::func_0006DFC0(int key, const Vector3 *position)
{
    for (Entry_0006DB80 *entry = buckets[key & 0xff]; entry; entry = entry->next) {
        if (entry->key == key) {
            entry->position = *position;
            return;
        }
    }
}
