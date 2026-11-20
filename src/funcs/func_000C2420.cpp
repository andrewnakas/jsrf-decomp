/* sym: ??0Object_000C2420@@QAE@PAUData_000C2700@@@Z = 0x000C2420 */
extern "C" void *memset(void *destination, int value, unsigned int size);

struct Data_000C2700 {
    unsigned char type;
    char unknown_01[2];
    char kind;
};

// Seventeen words; the constructor sets only the first.
struct Block_000C2420 {
    int kind;
    int unknown_04[16];
};

struct Pair_000C3100 {
    short first;
    short second;
};

// The base whose table is at 0x1CDCF8 (constructor func_000C2420, destructor func_000C2470); slot 9 is the
// destructor.
struct Object_000C2420 {
    Object_000C2420(Data_000C2700 *data);
    virtual void func_000C2630();
    virtual void func_000C2700();
    virtual void func_000C3800();
    virtual void func_000C30C0();
    virtual void func_000C3100();
    virtual void func_000C3140();
    virtual void func_000C31B0();
    virtual void func_000C3350();
    virtual void func_000C33C0();
    virtual ~Object_000C2420();
    virtual void func_000C2480();
    virtual void func_000C36F0();
    virtual void func_000C2FE0();
    virtual void func_000C2500();
    virtual void func_000C2560();
    virtual void func_000C25D0();
    virtual int func_000C2AA0();

    char unknown_04[0x24];
    int value_28;
    char unknown_2c[4];
    unsigned int flags;
    unsigned int state;
    char unknown_38[0x10];
    int value_48;
    char unknown_4c[0x14];
    int type;
    char unknown_64[0xc];
    int value_70;
    char unknown_74[4];
    Data_000C2700 *data;
    Pair_000C3100 *pair;
    float value;
    Block_000C2420 block;
    int value_c8;
};

Object_000C2420::Object_000C2420(Data_000C2700 *data)
{
    this->data = data;
    state = 0;
    type = data->type;
    value_70 = 0;
    value_48 = 0;
    value_c8 = 0;
    flags = 2;
    memset(&block, 0, sizeof(block));
    block.kind = 0xc37;
}
