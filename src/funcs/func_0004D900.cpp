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

// Releases the registration of a handler and argument (func_00025740), unlinks it and deletes it.
void Object_0004D8C0::func_0004D900(int first, int second)
{
    for (Item_0004D8C0 *item = items; item; item = item->next) {
        if (item->first == first && item->second == second) {
            func_00025740(item->first, item->second);
            *item->link = item->next;
            if (item->next) {
                item->next->link = item->link;
            } else {
                tail = item->link;
            }
            delete item;
            return;
        }
    }
}
