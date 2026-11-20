// Prints a debug message (in the XAPI library).
void __stdcall func_001473E1(const char *text);

// The message printed for files of another kind (0x1CC62C).
extern const char data_001CC62C[];

// A key of a camera motion track (0x10 bytes): a value at +0xc.
struct Key_0006EB20 {
    char unknown_00[0xc];
    float value;
};

// The body of a camera motion: four pointers stored as offsets from the file's start, and the counts of the first
// two tracks.
struct Body_0006EB20 {
    Key_0006EB20 *first;
    Key_0006EB20 *second;
    void *third;
    void *fourth;
    unsigned int firstCount;
    unsigned int secondCount;
};

// A camera motion file: its body (an offset from the start) and its kind at +0x8.
struct Motion_0006EB20 {
    Body_0006EB20 *body;
    int unknown_04;
    short kind;
};

// Turns the offsets of a camera motion file of kind 0x1c1 into pointers and negates the values of the keys of its
// first two tracks; any other kind only prints a message. Its callers push the file and load no object, and it pops
// its argument: it is __stdcall.
void __stdcall func_0006EB20(Motion_0006EB20 *motion)
{
    if (motion->kind == 0x1c1) {
        Body_0006EB20 *body = (Body_0006EB20 *)((char *)motion->body + (int)motion);
        motion->body = body;
        body->first = (Key_0006EB20 *)((char *)body->first + (int)motion);
        body->second = (Key_0006EB20 *)((char *)body->second + (int)motion);
        body->third = (char *)body->third + (int)motion;
        body->fourth = (char *)body->fourth + (int)motion;
        Key_0006EB20 *key = body->first;
        for (unsigned int i = 0; i < body->firstCount; i++, key++) {
            key->value *= -1.0f;
        }
        key = body->second;
        for (unsigned int j = 0; j < body->secondCount; j++, key++) {
            key->value *= -1.0f;
        }
    } else {
        func_001473E1(data_001CC62C);
    }
}
