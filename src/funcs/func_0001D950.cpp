extern "C" void *memset(void *destination, int value, unsigned int size);

struct Frame_00017860;

// A copied frame tree: a 0x70-byte header, the copy follows it. Kept in a bucket list (by the low byte of its id)
// and in one list of all copies; each list keeps the address of the previous link.
struct Copy_0001D950 {
    char *buffer;
    int id;
    int value;
    char unknown_0c[0x50];
    int unknown_5c;
    Copy_0001D950 **previous;
    Copy_0001D950 *next;
    Copy_0001D950 **allPrevious;
    Copy_0001D950 *allNext;
};

struct Object_00016200 {
    char unknown_000[0x80];
    int nextId;
    Copy_0001D950 *heads[0x100];
    Copy_0001D950 **tails[0x100];
    Copy_0001D950 *allHead;
    Copy_0001D950 **allTail;

    void func_00017670(char **cursor, Frame_00017860 *frame);
    int func_00017860(Frame_00017860 *frame);
    void func_0001D7B0(void *buffer);
    int func_0001D950(void *frame, int value);
};

// Copies a frame tree into a new zeroed block (func_00017860 sizes it, func_00017670 fills it), gives it the next id
// and the value, appends it to its bucket and to the list of all copies, runs func_0001D7B0 on the copy twice and
// returns the block.
int Object_00016200::func_0001D950(void *frame, int value)
{
    unsigned int size = func_00017860((Frame_00017860 *)frame) + 0x70;
    Copy_0001D950 *copy = (Copy_0001D950 *)operator new(size);
    memset(copy, 0, size);
    copy->buffer = (char *)(copy + 1);
    copy->id = nextId;
    copy->value = value;
    copy->unknown_5c = 0;
    nextId++;
    unsigned int bucket = copy->id & 0xff;
    *tails[bucket] = copy;
    copy->previous = tails[bucket];
    tails[bucket] = &copy->next;
    *allTail = copy;
    copy->allPrevious = allTail;
    allTail = &copy->allNext;
    char *cursor = copy->buffer;
    func_00017670(&cursor, (Frame_00017860 *)frame);
    func_0001D7B0(copy->buffer);
    func_0001D7B0(copy->buffer);
    return (int)copy;
}
