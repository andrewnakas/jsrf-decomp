struct Object_000A1C50 {
    int func_000836A0();
    void func_000992D0(int first, int second, int third, float value);
    void func_00099F10();
    int func_0009A140();
};

// func_000992D0(1, 1, 1, 0.0) when func_000836A0 reports true, func_00099F10 otherwise; returns 1.
int Object_000A1C50::func_0009A140()
{
    if (func_000836A0()) {
        func_000992D0(1, 1, 1, 0.0f);
        return 1;
    }
    func_00099F10();
    return 1;
}
