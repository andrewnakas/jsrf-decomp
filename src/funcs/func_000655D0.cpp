struct Vector3 {
    float x;
    float y;
    float z;
};

struct Model_000655D0 {
    char unknown_000[0x10c];
    Vector3 center;
};

// The table of 0x28-byte entries at 0x1FA1F0: a model first.
struct Entry_001FA1F0 {
    Model_000655D0 *model;
    char unknown_04[0x24];
};

extern Entry_001FA1F0 data_001FA1F0[];
extern Vector3 data_00251DC8;

void func_001BA9C0();
void func_001BA8A0();
void func_001BAA50();
void __fastcall func_001BAC50(int *angles, int order);
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);

struct Object_000607B0 {
    int func_000653D0(int index, int first, int second, Vector3 *center);
    int func_000655D0(int index, int first, int second, int third);
};

// Unless entry `first` of the table at 0x1FA1F0 has no model (-1), turns its model's center (+0x10c) by the angles
// at `third` into 0x251DC8 and passes it to func_000653D0.
int Object_000607B0::func_000655D0(int index, int first, int second, int third)
{
    if (!data_001FA1F0[first].model) {
        return -1;
    }
    func_001BA9C0();
    func_001BA8A0();
    func_001BAC50((int *)third, 0);
    func_001BAC00(&data_00251DC8, &data_001FA1F0[first].model->center);
    func_001BAA50();
    return func_000653D0(index, first, second, &data_00251DC8);
}
