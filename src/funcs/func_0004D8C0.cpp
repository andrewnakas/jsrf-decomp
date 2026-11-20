struct Item_0004D8C0 {
    int first;
    int second;
    Item_0004D8C0 *next;
    Item_0004D8C0 **link;
};

struct Object_0004D8C0 {
    char unknown_00[8];
    Item_0004D8C0 **tail;

    void func_0004D8C0(int first, int second);
};

// Appends a new 16-byte item holding two words to the list (tail link at +0x8).
void Object_0004D8C0::func_0004D8C0(int first, int second)
{
    Item_0004D8C0 *item = new Item_0004D8C0;
    item->first = first;
    item->second = second;
    *tail = item;
    item->link = tail;
    tail = &item->next;
    item->next = 0;
}
