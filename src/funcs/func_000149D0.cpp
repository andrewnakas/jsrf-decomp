struct List_000149B0;

struct Object_000149B0 {
    char unknown_00[0x4];
    List_000149B0 *head;

    List_000149B0 *func_000149D0();
};

// Returns the first entry of the list.
List_000149B0 *Object_000149B0::func_000149D0()
{
    return head;
}
