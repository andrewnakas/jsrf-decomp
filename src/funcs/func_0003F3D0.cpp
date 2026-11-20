struct Vector3 {
    float x;
    float y;
    float z;
};

struct Entry_0003E720 {
    char unknown_00[0x9c];
    int key;
    int unknown_a0;
    char unknown_a4[0x30];
    Vector3 unknown_d4;
    char unknown_e0[0x24];
    Entry_0003E720 *next;
};

struct Object_0003E750 {
    void *vtable;
    int unknown_04;
    Entry_0003E720 *buckets[0x100];

    void func_0003EA80(Entry_0003E720 *entry);
    void func_0003F3D0(int key);
    int func_0003F450(int key);
    void func_0003F490(int key, const Vector3 *value);
};

// Runs func_0003EA80 on the entry registered under a key, when there is one.
void Object_0003E750::func_0003F3D0(int key)
{
    for (Entry_0003E720 *entry = buckets[key & 0xff]; entry; entry = entry->next) {
        if (entry->key == key) {
            func_0003EA80(entry);
            return;
        }
    }
}
