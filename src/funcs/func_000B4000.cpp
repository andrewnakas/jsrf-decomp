void *__stdcall func_0006EBB0(unsigned int size);
long __stdcall func_0015F1F0(void *data, unsigned long size, unsigned long count, void **object);

// A source point (0x10 bytes): x, y and z from 0x4.
struct Source_000B4000 {
    int unknown_00;
    float x;
    float y;
    float z;
};

// A copied point (0x10 bytes).
struct Point_000B4000 {
    float x;
    float y;
    float z;
    int unknown_0c;
};

// A point count.
struct Header_000B4000 {
    unsigned int count;
};

// The class whose table is at 0x1CD8C8 (constructor func_000B4330, which calls this; func_000BAD80 finds it by id).
struct Object_000B40F0 {
    char unknown_000[0xb4];
    Source_000B4000 *sources[2];
    int unknown_0bc;
    void *objects[2];
    Point_000B4000 *points[2];
    char unknown_0d0[0x6c];
    Header_000B4000 *headers[2];

    void func_000B4000();
};

// For both point sets with a count (0x13c): copies the source points at 0xb4 into a new block (func_0006EBB0) kept at
// 0xc8 and makes an object of them (func_0015F1F0, 0x10 bytes each) at 0xc0.
void Object_000B40F0::func_000B4000()
{
    for (int i = 0; i < 2; i++) {
        if (headers[i]) {
            Point_000B4000 *point = (Point_000B4000 *)func_0006EBB0(headers[i]->count << 4);
            points[i] = point;
            Source_000B4000 *source = sources[i];
            for (unsigned int j = 0; j < headers[i]->count; j++) {
                point[j].x = source[j].x;
                point[j].y = source[j].y;
                point[j].z = source[j].z;
            }
            func_0015F1F0(point, 0x10, headers[i]->count, &objects[i]);
        }
    }
}
