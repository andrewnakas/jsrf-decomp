// A registration: a handler index and its argument, released through func_00025740.
struct Item_0004D8C0 {
    int first;
    int second;
    Item_0004D8C0 *next;
    Item_0004D8C0 **link;
};

void func_00025740(unsigned int index, int argument);

struct Object_0004D8C0 {
    int unknown_00;
    Item_0004D8C0 *items;
    Item_0004D8C0 **tail;

    void func_0004D900(int first, int second);
    void func_0004DAA0();
    void func_0004DAE0(const int *keep, unsigned int count);
};

// Releases and deletes every registration and empties the list.
void Object_0004D8C0::func_0004DAA0()
{
    Item_0004D8C0 *item = items;
    while (item) {
        Item_0004D8C0 *next = item->next;
        func_00025740(item->first, item->second);
        delete item;
        item = next;
    }
    tail = &items;
    items = 0;
}
