struct Object_0007C250 {
    char unknown_00[0x48];
    int state;

    void func_0007C050();
};

void func_00024F50(void *parent);

// State handler (table at 0x20D2B8): passes the object to func_00024F50 (which creates object 0x1df1 unless the
// cache is complete or the object exists) and goes to state 6.
void Object_0007C250::func_0007C050()
{
    func_00024F50(this);
    state = 6;
}
