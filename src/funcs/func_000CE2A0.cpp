struct Owner_000CE2A0 {
    char unknown_00[0xa4];
    unsigned int flags;
};

struct Object_000CE220 {
    int unknown_00;
    Owner_000CE2A0 *owner;
    char unknown_08[8];
    int count;

    void func_000CE2A0();
};

// While the owner at 4 lacks flag 0x2000, counts up at 0x10; past 60 the owner gets the flags 0x2020.
void Object_000CE220::func_000CE2A0()
{
    Owner_000CE2A0 *owner = this->owner;
    if (!(owner->flags & 0x2000)) {
        if (++count > 60) {
            owner->flags |= 0x2020;
        }
    }
}
