struct Object_000A1C50 {
    int func_00091380(int *first, int *second);
    void func_0009B490();
};

// Calls func_00091380 and drops everything it reports.
void Object_000A1C50::func_0009B490()
{
    int first;
    int second;
    func_00091380(&first, &second);
}
