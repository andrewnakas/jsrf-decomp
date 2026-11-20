/* sym: ??0Object_001E0F00@@QAE@XZ = 0x0014CDB0 */
struct Desc;
struct Rect6;
struct Source;

struct Rect {
    long left;
    long top;
    long right;
    long bottom;
};

struct LargeInteger {
    unsigned long low;
    long high;
};

// The device's statistics (0x20 bytes at +4, a non-polymorphic base: data_002650EC points at it).
struct Stats {
    unsigned long unknown_00[2];
    unsigned int primitives;
    unsigned int draws;
    unsigned long unknown_10[3];
    float frequency;
};

extern "C" void *memset(void *destination, int value, unsigned int size);

int __stdcall func_00145571(LargeInteger *frequency);
int __stdcall func_00182B81(Rect *rect, long left, long top, long right, long bottom);

struct Entry_50;
struct Object_001E0F00;
extern unsigned char data_00264F50[];
extern void **data_00264F68;
extern int data_00264F70;
extern Entry_50 *data_00264D4C;
extern unsigned int data_00264D50;
extern unsigned long data_00265000[0x35];
extern unsigned long data_002650D4;
extern Object_001E0F00 *data_002650D8;
extern unsigned long data_002650DC;

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), 0xE4 bytes, created by 0x14CFB0.
struct Object_001E0F00 : Stats {
    virtual long __stdcall func_0014CF20(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_0014CF00();  // slot 1
    virtual unsigned long __stdcall func_0014CF80();  // slot 2
    virtual long __stdcall func_00155A60(unsigned long argument1);  // slot 3
    virtual void __stdcall func_00155540(void *handle);  // slot 4
    virtual long __stdcall func_00155560(unsigned long argument1, unsigned long argument2, unsigned long argument3);  // slot 5
    virtual long __stdcall func_00155380(unsigned long argument1);  // slot 6
    virtual long __stdcall func_00154D70(int kind, Source *source);  // slot 7
    virtual void *__stdcall func_00154DC0(int kind);  // slot 8
    virtual long __stdcall func_00155150(unsigned long argument1, unsigned long argument2);  // slot 9
    virtual long __stdcall func_00155050(unsigned long argument1, unsigned long argument2);  // slot 10
    virtual int __stdcall func_00154CF0(Rect6 *out);  // slot 11
    virtual void __stdcall func_00154BB0(unsigned long mode);  // slot 12
    virtual int __stdcall func_001548E0(int index);  // slot 13
    virtual long __stdcall func_0014F720(unsigned long argument1, unsigned long argument2);  // slot 14
    virtual void __stdcall func_0014F6D0(unsigned int index);  // slot 15
    virtual long __stdcall func_00150A70(unsigned long argument1, unsigned long argument2, unsigned long argument3);  // slot 16
    virtual long __stdcall func_00150C00(int index);  // slot 17
    virtual long __stdcall func_00150C70(int index);  // slot 18
    virtual long __stdcall func_0014FA40(unsigned long argument1, unsigned long argument2);  // slot 19
    virtual long __stdcall func_0014FB20(unsigned long argument1);  // slot 20
    virtual long __stdcall func_0014FBB0(unsigned long color);  // slot 21
    virtual void __stdcall func_0014FDB0(unsigned long color);  // slot 22
    virtual long __stdcall func_00154560(unsigned long argument1, unsigned long argument2, unsigned long argument3, unsigned long argument4);  // slot 23
    virtual void __stdcall func_0014D020(unsigned long value);  // slot 24
    virtual long __stdcall func_0014D030(unsigned long flags);  // slot 25
    virtual long __stdcall func_001542A0(unsigned long argument1, unsigned long argument2, unsigned long argument3);  // slot 26
    virtual long __stdcall func_00154420(int state, const void *matrix);  // slot 27
    virtual long __stdcall func_00154520(int state, const void *matrix);  // slot 28
    virtual long __stdcall func_00154540(int state, const void *matrix);  // slot 29
    virtual long __stdcall func_00153E30(Desc *desc);  // slot 30
    virtual long __stdcall func_00153FE0(long first, float second, float third);  // slot 31
    virtual long __stdcall func_001540A0(Desc *desc);  // slot 32
    virtual long __stdcall func_001540D0(float value);  // slot 33
    virtual float __stdcall func_001540F0(float value);  // slot 34
    virtual float __stdcall func_00154110(float value);  // slot 35
    virtual long __stdcall func_00154130(unsigned long argument1, unsigned long argument2);  // slot 36
    virtual long __stdcall func_00154180(unsigned long argument1, unsigned long argument2, unsigned long argument3);  // slot 37
    virtual long __stdcall func_00153DB0(unsigned long argument1);  // slot 38
    virtual long __stdcall func_00153C50(unsigned long argument1);  // slot 39
    virtual long __stdcall func_00153DF0(unsigned long argument1);  // slot 40
    virtual long __stdcall func_00153CA0(unsigned long argument1);  // slot 41
    virtual long __stdcall func_0014D340(unsigned long argument1);  // slot 42
    virtual long __stdcall func_0014D0F0(unsigned long *value);  // slot 43
    virtual unsigned long __stdcall func_0014D080_3();  // slot 44
    virtual unsigned long __stdcall func_0014D080_4();  // slot 45
    virtual long __stdcall func_0014D090();  // slot 46
    virtual long __stdcall func_0014D1E0(unsigned long value, unsigned long extra);  // slot 47
    virtual long __stdcall func_0014D200(const void *vertices, unsigned int count);  // slot 48
    virtual long __stdcall func_0014D230(const void *vertices, unsigned int count);  // slot 49
    virtual long __stdcall func_0014D270(const void *vertices, unsigned int vertexCount, const void *indices, unsigned int count);  // slot 50
    virtual long __stdcall func_0014D2B0(const void *vertices, unsigned int count);  // slot 51
    virtual long __stdcall func_0014D2E0(const void *vertices, unsigned int count);  // slot 52
    virtual long __stdcall func_0014D310(const void *vertices, unsigned int count);  // slot 53
    virtual long __stdcall func_0014D800(unsigned long argument1, unsigned long argument2, unsigned long argument3, unsigned long argument4, void **object);  // slot 54
    virtual long __stdcall func_0014E430(unsigned long argument1, unsigned long argument2, unsigned long argument3, unsigned long argument4);  // slot 55
    virtual long __stdcall func_001539B0(unsigned long argument1, unsigned long argument2, void **object);  // slot 56
    virtual long __stdcall func_001536E0(unsigned long argument1, void **object);  // slot 57
    virtual long __stdcall func_00152BC0(unsigned long argument1, unsigned long argument2, unsigned long argument3, unsigned long kind, void **object);  // slot 58
    virtual long __stdcall func_00167CB0_2(void *argument1, unsigned long argument2);  // slot 59
    virtual long __stdcall func_00152270(void **object);  // slot 60
    virtual long __stdcall func_00151CA0(unsigned long argument1, unsigned long argument2, unsigned long argument3, void **object);  // slot 61
    virtual long __stdcall func_001504D0(unsigned long argument1, unsigned long argument2);  // slot 62
    virtual int __stdcall func_001507C0(int index, unsigned long *value);  // slot 63
    virtual long __stdcall func_001503F0(int mode);  // slot 64
    virtual long __stdcall func_001507E0(int smooth);  // slot 65
    virtual long __stdcall func_00150440(int mode);  // slot 66
    virtual long __stdcall func_00150810(unsigned long value);  // slot 67
    virtual long __stdcall func_00150830(unsigned long value);  // slot 68
    virtual long __stdcall func_00150480(unsigned long value);  // slot 69
    virtual int __stdcall func_00150490(unsigned long value);  // slot 70
    virtual long __stdcall func_00150850(unsigned long value);  // slot 71
    virtual long __stdcall func_00150870(unsigned long value);  // slot 72
    virtual long __stdcall func_00150890(unsigned long value);  // slot 73
    virtual long __stdcall func_001508B0(unsigned long first, unsigned long second);  // slot 74
    virtual long __stdcall func_0014FE50(unsigned long value);  // slot 75
    virtual long __stdcall func_00150910(unsigned long value);  // slot 76
    virtual long __stdcall func_00150930(unsigned long value);  // slot 77
    virtual long __stdcall func_00150950(unsigned long value);  // slot 78
    virtual long __stdcall func_001504A0(unsigned long value);  // slot 79
    virtual long __stdcall func_00150970(unsigned long first, unsigned long second, float third);  // slot 80
    virtual long __stdcall func_0014FDE0(unsigned long value, int index);  // slot 81
    virtual long __stdcall func_0014FEF0(unsigned long argument1, unsigned long argument2);  // slot 82
    virtual long __stdcall func_0014FE30(unsigned long first, unsigned long second);  // slot 83
    virtual long __stdcall func_00150130(unsigned long stage, unsigned long value);  // slot 84
    virtual long __stdcall func_00150170(unsigned long stage, unsigned long value);  // slot 85
    virtual long __stdcall func_001501F0(unsigned long stage, unsigned long mode);  // slot 86
    virtual long __stdcall func_00150240(unsigned long stage, int enable);  // slot 87
    virtual long __stdcall func_00150280(unsigned long stage, int enable);  // slot 88
    virtual long __stdcall func_00150FB0(unsigned long value);  // slot 89
    virtual long __stdcall func_001504B0(unsigned long value);  // slot 90
    virtual long __stdcall func_001504B0_4(unsigned long value);  // slot 91
    virtual long __stdcall func_001504C0(unsigned long value);  // slot 92
    virtual long __stdcall func_0014FE60(unsigned long argument1, unsigned long argument2);  // slot 93
    virtual long __stdcall func_00151120(unsigned long value);  // slot 94
    virtual long __stdcall func_001511B0(unsigned long first, unsigned long second, unsigned long third);  // slot 95
    virtual long __stdcall func_00151160(unsigned long color);  // slot 96
    virtual long __stdcall func_00151180(unsigned long value);  // slot 97
    virtual long __stdcall func_00151330(unsigned long argument1);  // slot 98
    virtual long __stdcall func_00151200();  // slot 99
    virtual long __stdcall func_001512E0();  // slot 100
    virtual long __stdcall func_001511A0();  // slot 101
    virtual long __stdcall func_00151670();  // slot 102
    virtual long __stdcall func_00151520();  // slot 103
    virtual long __stdcall func_001515D0(unsigned long mode);  // slot 104
    virtual long __stdcall func_00150FA0(unsigned long value);  // slot 105
    virtual long __stdcall func_00150FE0(float value);  // slot 106
    virtual long __stdcall func_001510D0();  // slot 107
    virtual long __stdcall func_00150FD0();  // slot 108
    virtual long __stdcall func_00150FD0_1();  // slot 109
    virtual long __stdcall func_00150CA0(unsigned long argument1, unsigned long argument2, unsigned long argument3);  // slot 110
    virtual long __stdcall func_00150D90(unsigned long argument1, unsigned long argument2, unsigned long argument3);  // slot 111
    virtual long __stdcall func_001502F0(unsigned long stage, int type, unsigned long value);  // slot 112
    virtual long __stdcall func_001508F0(unsigned long value);  // slot 113
    virtual long __stdcall func_001502C0(unsigned long stage, unsigned long value);  // slot 114
    virtual long __stdcall func_0014FDA0(unsigned long value);  // slot 115
    virtual long __stdcall func_0014E600(unsigned long argument1);  // slot 116
    virtual long __stdcall func_0014D9D0(int mode);  // slot 117
    virtual long __stdcall func_0014D8E0(unsigned long argument1, void **object);  // slot 118
    virtual long __stdcall func_0014D110(unsigned long argument1, unsigned long argument2);  // slot 119
    virtual void __stdcall func_0014D0D0();  // slot 120

    Object_001E0F00();

    long value_24[5];
    long value_38;
    long value_3C;
    float value_40;
    float value_44;
    unsigned long value_48;
    unsigned long value_4C[5];
    float value_60;
    unsigned long value_64;
    unsigned long value_68;
    long value_6C;
    Rect rect;
    unsigned long value_80;
    unsigned long value_84;
    unsigned long value_88[8];
    unsigned long value_A8[14];
    unsigned long references;
};

// The constructor: clears the Direct3D globals and the statistics, keeps the performance counter's frequency.
Object_001E0F00::Object_001E0F00()
{
    data_002650D8 = 0;
    data_002650DC = 0;
    data_002650D4 = 0;
    data_00264F68 = 0;
    data_00264F70 = 0;
    memset(data_00264F50, 0, 0x16);
    memset(data_00265000, 0, sizeof(data_00265000));
    data_00264D4C = 0;
    data_00264D50 = 0;
    memset(static_cast<Stats *>(this), 0, sizeof(Stats));
    LargeInteger counter;
    func_00145571(&counter);
    frequency = (float)counter.low;
    value_24[0] = 0;
    value_24[1] = 0;
    value_24[2] = 0;
    value_24[3] = 0;
    value_24[4] = 0;
    value_38 = -1;
    value_3C = -1;
    value_40 = 0.5f;
    value_44 = 500.0f;
    value_48 = 0x4000;
    value_4C[0] = 0;
    value_4C[1] = 0;
    value_4C[2] = 0;
    value_4C[3] = 0;
    value_4C[4] = 0;
    value_60 = 1.0f;
    value_64 = 0;
    value_68 = 0;
    value_6C = -1;
    func_00182B81(&rect, 0, 0, 0, 0);
    value_80 = 0;
    value_84 = 1;
    value_88[0] = 0;
    value_88[1] = 0;
    value_88[2] = 0;
    value_88[3] = 0;
    value_88[4] = 0;
    value_88[5] = 0;
    value_88[6] = 0;
    value_88[7] = 0;
    memset(value_A8, 0, sizeof(value_A8));
    references = 0;
}
