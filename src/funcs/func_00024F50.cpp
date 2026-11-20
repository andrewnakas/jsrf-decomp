/* sym: ??0Object_00024CF0@@QAE@PAUNode@@HI@Z = 0x00024C90 */
struct Node;

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

int func_00025770(const char *path);

// The class whose table is at 0x1C4D58 (destructor 0x24CF0; 0x180 bytes).
struct Object_00024CF0 {
    Object_00024CF0(Node *owner, int id, unsigned int flags);

    char unknown_000[0x180];
};

// Unless the cache is complete (Z:\Media\Cache\JSRF_CACHE_COMPLETE.CMP exists) or object 0x1DF1 already exists,
// creates it (the class at 0x1C4D58) under an owner.
void func_00024F50(void *owner)
{
    if (!func_00025770("Z:\\Media\\Cache\\JSRF_CACHE_COMPLETE.CMP") && !data_0022FCE0->func_000128C0(0x1df1)) {
        new Object_00024CF0((Node *)owner, 0x1df1, 0);
    }
}
