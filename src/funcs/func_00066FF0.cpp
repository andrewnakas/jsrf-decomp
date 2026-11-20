struct Data_00066CB0;

struct Item_00066CB0 {
    Data_00066CB0 *data;
    int value;
    int active;
    Item_00066CB0 **link;
    Item_00066CB0 *next;
};

struct Object_00065730 {
    int unknown_00;
    Item_00066CB0 *head;

    int func_00066FF0();
};

// Returns the value (+4) of the first item of the list at +4 whose word at +8 is set, or -1 (the list at 0x1FB8E8).
int Object_00065730::func_00066FF0()
{
    for (Item_00066CB0 *item = head; item; item = item->next) {
        if (item->active) {
            return item->value;
        }
    }
    return -1;
}
