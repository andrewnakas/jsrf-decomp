int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);
void func_000FE5B0(int key);

struct Object_0006E130 {
    void func_0006E7B0(int texture);
};

extern Object_0006E130 data_00252790;

// Something a set owns (deleted through its virtual destructor).
struct Part_00034070 {
    virtual ~Part_00034070();
};

// A loaded set (0x30 bytes): two textures, three blocks and three parts, and its place in the list at +0x1658.
struct Set_00034070 {
    int key;
    int flag;
    int textures[2];
    void *blocks[3];
    Part_00034070 *parts[3];
    Set_00034070 **link;
    Set_00034070 *next;
};

struct Object_000265A0 {
    char unknown_0000[0x1658];
    Set_00034070 *sets;
    Set_00034070 **tail;
    Set_00034070 *current;
    char unknown_1664[0xc];
    void *buffer;

    void func_00034070(int key);
};

// Handler 13 of the table at 0x1EC288: passes `key` to func_000FE5B0; deletes the set at +0x1660 (its parts, blocks
// and textures) and frees the buffer at +0x1670; then takes the set with `key` out of the list at +0x1658 (tail link
// at +0x165c) and deletes it the same way, unless its flag (+4) is set.
void Object_000265A0::func_00034070(int key)
{
    func_000FE5B0(key);
    if (current) {
        unsigned int i;
        for (i = 0; i < 3; i++) {
            if (current->parts[i])
                delete current->parts[i];
        }
        for (i = 0; i < 3; i++) {
            if (current->blocks[i])
                delete current->blocks[i];
        }
        for (i = 0; i < 2; i++)
            data_00252790.func_0006E7B0(current->textures[i]);
        delete current;
        current = 0;
        if (buffer) {
            func_00145A5D(buffer, 0, 0x8000);
            buffer = 0;
        }
    }
    for (Set_00034070 *set = sets; set; set = set->next) {
        if (set->key == key) {
            if (!set->flag) {
                unsigned int j;
                for (j = 0; j < 3; j++) {
                    if (set->parts[j])
                        delete set->parts[j];
                }
                for (j = 0; j < 3; j++) {
                    if (set->blocks[j])
                        delete set->blocks[j];
                }
                for (j = 0; j < 2; j++)
                    data_00252790.func_0006E7B0(set->textures[j]);
                *set->link = set->next;
                if (set->next)
                    set->next->link = set->link;
                else
                    tail = set->link;
                delete set;
            }
            return;
        }
    }
}
