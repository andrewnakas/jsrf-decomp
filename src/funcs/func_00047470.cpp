struct Frame_000479D0;

struct Object_00047470 {
    virtual ~Object_00047470();
    virtual void func_00048190(void *first, void *second, Frame_000479D0 *frame);
    virtual void func_00047470(void *first, void *second, Frame_000479D0 *frame);

    char unknown_04[0x20];
    unsigned int flags;
};

// Slot 2 of the table at 0x1CA490: sets flag 0x10 and runs slot 1 with the same arguments (a tail jump).
void Object_00047470::func_00047470(void *first, void *second, Frame_000479D0 *frame)
{
    flags |= 0x10;
    func_00048190(first, second, frame);
}
