struct Vector3 {
    float x;
    float y;
    float z;
};

struct Mark_00089C10 {
    Vector3 position;
    int unknown_0c;
    int unknown_10;
    int owner;
    Mark_00089C10 *next;
};

struct Object_0003E750 {
    char unknown_000[0x81c];
    Mark_00089C10 **markTail;

    void func_0003E6F0(Mark_00089C10 *mark);
};

// Appends a mark to the list whose tail link is at +0x81c (linked at +0x18) and clears its words at +0xc and +0x10.
void Object_0003E750::func_0003E6F0(Mark_00089C10 *mark)
{
    *markTail = mark;
    markTail = &mark->next;
    mark->unknown_0c = 0;
    mark->unknown_10 = 0;
    mark->next = 0;
}
