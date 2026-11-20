// An entry of the three collider lists (+0x2c, +0x30, +0x34), linked through +0x20.
struct Collider_0001D6D0 {
    char unknown_00[0x20];
    Collider_0001D6D0 *next;
};

struct Object_00016200 {
    char unknown_00[0x2c];
    Collider_0001D6D0 *first;
    Collider_0001D6D0 *second;
    Collider_0001D6D0 *third;
    char unknown_38[0x20];
    int unknown_58;

    void func_00019C90(Collider_0001D6D0 *a, Collider_0001D6D0 *b);
    void func_0001A0A0(Collider_0001D6D0 *a, Collider_0001D6D0 *b);
    void func_0001A480(Collider_0001D6D0 *a, Collider_0001D6D0 *b);
    void func_0001A860(Collider_0001D6D0 *a, Collider_0001D6D0 *b);
    void func_0001AC20(Collider_0001D6D0 *a, Collider_0001D6D0 *b);
    void func_0001AFE0(Collider_0001D6D0 *a, Collider_0001D6D0 *b);
    void func_0001D6D0();
};

// Clears +0x58 and tests every pair of colliders: within the first list (func_00019C90), first against second
// (func_0001A0A0) and third (func_0001A480), within the second (func_0001A860), second against third (func_0001AC20)
// and within the third (func_0001AFE0).
void Object_00016200::func_0001D6D0()
{
    unknown_58 = 0;
    for (Collider_0001D6D0 *a = first; a; a = a->next) {
        for (Collider_0001D6D0 *b = a->next; b; b = b->next)
            func_00019C90(a, b);
        for (Collider_0001D6D0 *c = second; c; c = c->next)
            func_0001A0A0(a, c);
        for (Collider_0001D6D0 *d = third; d; d = d->next)
            func_0001A480(a, d);
    }
    for (Collider_0001D6D0 *e = second; e; e = e->next) {
        for (Collider_0001D6D0 *f = e->next; f; f = f->next)
            func_0001A860(e, f);
        for (Collider_0001D6D0 *g = third; g; g = g->next)
            func_0001AC20(e, g);
    }
    for (Collider_0001D6D0 *h = third; h; h = h->next) {
        for (Collider_0001D6D0 *i = h->next; i; i = i->next)
            func_0001AFE0(h, i);
    }
}
