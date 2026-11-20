void func_001BA9C0();
void func_001BAA50();
void __fastcall func_001BAAA0(float *vector);

struct Object_00086060 {
    char unknown_00[0x54];
    float position[3];

    void func_000855D0();
    void func_00085640();
    void func_00086060();
};

// Handler (at 0x20D9F4 to 0x20DA00, four entries of one table): runs func_000855D0 and func_00085640 under a matrix moved to the
// position at +0x54.
void Object_00086060::func_00086060()
{
    func_001BA9C0();
    func_001BAAA0(position);
    func_000855D0();
    func_00085640();
    func_001BAA50();
}
