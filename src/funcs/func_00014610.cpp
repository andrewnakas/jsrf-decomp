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
};

// Called by 0x147A0. Frees the fading trail `index` and its points and closes the gap.
void Object_00014280::func_00014610(int index)
{
    Trail_00014370 **slot = &fading[index];
    operator delete((*slot)->points);
    operator delete(*slot);
    for (unsigned int i = index; i < fadingCount - 1; i++) {
        fading[i] = fading[i + 1];
    }
    fadingCount--;
}
