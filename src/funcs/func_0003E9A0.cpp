struct Item_0003E9A0;

struct Object_0003E750 {
    char unknown_000[0x818];
    Item_0003E9A0 *head;
    Item_0003E9A0 **tail;

    void func_0003E9A0();
};

// Empties the list at +0x818.
void Object_0003E750::func_0003E9A0()
{
    head = 0;
    tail = &head;
}
