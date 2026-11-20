int __stdcall func_00145560(void *counter);

struct Object_00016200 {
    void func_000161B0();
    void func_0001D920();
};

extern Object_00016200 data_0022FCE8;

struct Object_0003E750 {
    void func_0003E9A0();
    void func_0003E9C0();
};

extern Object_0003E750 data_002314B0;

struct Object_000149B0;

extern Object_000149B0 data_0020C750;

// The lists at 0x20C750.
struct Object_0006C6D0 {
    void func_0006C6D0();
    void func_0006C6E0();
};

struct Object_0006DB80 {
    void func_0006DBB0();
    void func_0006DBE0();
};

extern Object_0006DB80 data_00251F78;

struct Object_0001DEF0 {
    void func_0006F8C0();
    void func_0001DF30();
    void func_00024AE0();
};

extern Object_0001DEF0 data_0020CC58;
extern Object_0001DEF0 data_001EBABC;
extern Object_0001DEF0 data_001EC050;

struct Object_00065730 {
    void func_00065800();
    void func_00066D80();
};

extern Object_00065730 data_001FB804;
extern Object_00065730 data_001FB8E8;

struct Object_00039A10 {
    void func_00066AD0();
    void func_00066110();
    void func_0001DD60();
    void func_00039A80();
};

extern Object_00039A10 data_001FB8CC;
extern Object_00039A10 data_001FB820;
extern Object_00039A10 data_001EBAA8;
extern Object_00039A10 data_001EFC74;

struct Object_00015130 {
    void func_00015130();
};

extern Object_00015130 data_001EB994;

struct Object_0006E910 {
    void func_0006E910(__int64 *out, __int64 start, __int64 end);
};

extern Object_0006E910 data_0020CC48;

// A node of the game's tree; each of these walks the tree from it.
struct Node {
    void func_00011070();
    void func_000112A0();
    void func_000114D0();
    void func_00011700();
    void func_00011930();
    void func_00011D00();
    void func_00011DA0();
    void func_00011E40();
    void func_00011EE0();
    void func_00011F80();
};

// The game (constructor 0x12210, table 0x1C4458): four mode flags at +0x40, the frame time at +0x87b8 and the root
// node at +0x87dc.
struct Game {
    char unknown_0000[0x40];
    int unknown_40;
    int unknown_44;
    int unknown_48;
    int unknown_4c;
    char unknown_50[0x28];
    int unknown_78;
    char unknown_7c[0x873c];
    __int64 time;
    char unknown_87c0[0x1c];
    Node *root;

    void func_000123E0();
};

// One frame of the game: counts its time (func_00145560 before and after, data_0020CC48 into +0x87b8) around the
// update and draw passes. Each of the four flags at +0x40 picks its own update and draw walks of the tree; with none
// set the subsystems are updated in turn and the tree's plain walks run.
void Game::func_000123E0()
{
    __int64 end;
    __int64 start;
    func_00145560(&start);
    data_0022FCE8.func_000161B0();
    data_002314B0.func_0003E9A0();
    ((Object_0006C6D0 *)&data_0020C750)->func_0006C6D0();
    data_00251F78.func_0006DBB0();
    unknown_78 = 0;
    if (unknown_40) {
        root->func_000114D0();
    } else if (unknown_44) {
        root->func_000112A0();
    } else if (unknown_48) {
        root->func_00011700();
    } else if (unknown_4c) {
        root->func_00011930();
    } else {
        data_0020CC58.func_0006F8C0();
        data_001EBABC.func_0001DF30();
        data_001FB804.func_00065800();
        data_001FB8CC.func_00066AD0();
        data_001EC050.func_00024AE0();
        data_001FB820.func_00066110();
        data_001EB994.func_00015130();
        root->func_00011070();
    }
    data_0022FCE8.func_0001D920();
    data_002314B0.func_0003E9C0();
    ((Object_0006C6D0 *)&data_0020C750)->func_0006C6E0();
    data_00251F78.func_0006DBE0();
    data_001EBAA8.func_0001DD60();
    data_001FB8E8.func_00066D80();
    data_001EFC74.func_00039A80();
    if (unknown_40)
        root->func_00011E40();
    else if (unknown_44)
        root->func_00011DA0();
    else if (unknown_48)
        root->func_00011EE0();
    else if (unknown_4c)
        root->func_00011F80();
    else
        root->func_00011D00();
    func_00145560(&end);
    data_0020CC48.func_0006E910(&time, start, end);
}
