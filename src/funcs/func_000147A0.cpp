void __cdecl operator delete(void *memory) throw();

struct Vector3 {
    float x;
    float y;
    float z;
};

// A ring of points from `start` to `end`.
struct Trail_00014370 {
    int unknown_00;
    int start;
    int end;
    int last;
    Vector3 *points;
};

// Node child with the table at 0x1C4500 (trails): up to eight live trails at +0x70 (count at +0xb0) and eight that
// are fading out at +0x90 (count at +0xb4).
struct Object_00014280 {
    char unknown_00[0x70];
    Trail_00014370 *trails[8];
    Trail_00014370 *fading[8];
    unsigned int count;
    unsigned int fadingCount;

    void func_00014610(int index);
    void func_000147A0(int index);
};

// Called by 0x14840 and 0x14870. Ends the live trail `index`: an empty one is freed, any other moves to the fading
// list (dropping the oldest there when it is full) with its end set to +0xc; then closes the gap.
void Object_00014280::func_000147A0(int index)
{
    Trail_00014370 **slot = &trails[index];
    Trail_00014370 *trail = *slot;
    if (trail->last != trail->start) {
        if (fadingCount >= 8) {
            func_00014610(0);
        }
        trail->end = trail->last;
        fading[fadingCount] = trail;
        fadingCount++;
    } else {
        operator delete(trail->points);
        operator delete(trail);
    }
    for (unsigned int i = index; i < count - 1; i++) {
        trails[i] = trails[i + 1];
    }
    count--;
}
