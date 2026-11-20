struct Object_000CE2D0 {
    char unknown_00[8];
    int state;
    int unknown_0c;
    int count;

    void func_000CE2D0();
    void func_000CF010();
};

void Object_000CE2D0::func_000CF010()
{
    count++;
    if (count > 120) {
        state = 1;
    }
    func_000CE2D0();
}
