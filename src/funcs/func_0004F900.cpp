/* sym: ??0Object_0007AF70@@QAE@PAUNode@@HIH@Z = 0x0007AE10 */
struct Node;

int func_000256C0(unsigned int index, int argument);

struct Object_0007AF70 {
    Object_0007AF70(Node *owner, int id, unsigned int flags, int argument);

    char unknown_00[0x60];
};

struct Object_0004EF90 {
    char unknown_00[0x44];
    int next;
    int unknown_48;

    void func_0004F900();
};

// A state handler (table 0x1FA008, slot 19): once handler 0x14 answers, sets +0x48, creates node 2 under this one
// (Object_0007AF70) and goes to state 20.
void Object_0004EF90::func_0004F900()
{
    if (func_000256C0(0x14, 0)) {
        unknown_48 = 1;
        new Object_0007AF70((Node *)this, 2, 0, 0);
        next = 20;
    }
}
