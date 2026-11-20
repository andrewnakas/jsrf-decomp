// The objects whose state handlers fill the table at 0x2165F4 to 0x216660 (func_000CE1A0, func_000CE220,
// func_000CEF60, this one, ...).
struct Object_000CE220 {
    char unknown_00[8];
    int state;
    int unknown_0c;
    int count;

    int func_000CE2D0();
    void func_000CF010();
};

void Object_000CE220::func_000CF010()
{
    count++;
    if (count > 120) {
        state = 1;
    }
    func_000CE2D0();
}
