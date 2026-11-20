// An entry of the 0x14-byte table the global points at; the child keeps the value at +0xc of its entry.
struct Line_000FA780 {
    char unknown_00[0xc];
    unsigned int count;
    int unknown_10;
};

// The child of Object_000FDDC0 whose table is at 0x1D1B20 (func_000FDFB0 creates it as entry 6
// of object 0x1165).
struct Object_000FB530 {
    char unknown_00[0x94];
    int state;
    char unknown_98[0x38];
    int index;
    unsigned int count;
    int first;
    int second;

    void func_000FB550(int index, int first, int second);
};

extern Line_000FA780 *data_0025889C;

void func_00117140(int sound);
void func_001166B0(int value);
int func_001186A0(int index, unsigned int value);

// Keeps the index and both values, the count of the index's entry of the table at 0x0025889C, state 6 at 0x94;
// then func_001186A0(0xb, 1), func_00117140(0x39) and func_001166B0(0).
void Object_000FB530::func_000FB550(int index, int first, int second)
{
    this->index = index;
    this->first = first;
    this->second = second;
    count = data_0025889C[index].count;
    state = 6;
    func_001186A0(0xb, 1);
    func_00117140(0x39);
    func_001166B0(0);
}
