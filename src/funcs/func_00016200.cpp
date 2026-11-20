struct Item_00016200 {
    int unknown_00;
    Item_00016200 *next;
};

struct Object_00016200 {
    Item_00016200 **tail;

    void func_00016200(Item_00016200 *item);
};

// Appends an item to the list whose tail link the object starts with.
void Object_00016200::func_00016200(Item_00016200 *item)
{
    *tail = item;
    item->next = 0;
    tail = &item->next;
}
