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

// Removes every registration of handler 2 whose argument is not among the ones to keep.
void Object_0004D8C0::func_0004DAE0(const int *keep, unsigned int count)
{
    Item_0004D8C0 *item = items;
    while (item) {
        Item_0004D8C0 *next = item->next;
        if (item->first == 2) {
            unsigned int i;
            for (i = 0; i < count; i++) {
                if (item->second == keep[i]) {
                    break;
                }
            }
            if (i >= count) {
                func_0004D900(2, item->second);
            }
        }
        item = next;
    }
}
