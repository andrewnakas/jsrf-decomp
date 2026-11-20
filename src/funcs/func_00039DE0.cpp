struct Object_00039BE0 {
    void func_00039BE0(int value);
    void func_00039DE0(int type, int index, int flag);
};

void Object_00039BE0::func_00039DE0(int type, int index, int flag)
{
    func_00039BE0(((((flag & 1) << 16) | (index & 0xffff)) << 3) | (type & 7));
}
