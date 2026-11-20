struct Item_0006C6D0;

struct Object_0006C6D0 {
    char unknown_00[0xc];
    Item_0006C6D0 *head;
    Item_0006C6D0 **tail;

    void func_0006C6D0();
};

// Empties the list at +0xc.
void Object_0006C6D0::func_0006C6D0()
{
    head = 0;
    tail = &head;
}
