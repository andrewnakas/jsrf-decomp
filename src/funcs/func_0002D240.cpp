/* const: 0x100000 */
void *operator new(unsigned int size);

// The object at 0x1EFFB0.
struct Object_00039BE0 {
    int func_000149D0_1();
    void func_0003A7F0(int first, int second, int third, int fourth);
    void func_0003A840(int first, int second, int third, int fourth);
};

extern Object_00039BE0 data_001EFFB0;
extern int data_001EDE50[][4][5];
extern void *data_00230DBC;
extern void *data_00230DC0;

// Object 7.
struct Object_000265A0 {
    char unknown_0000[0x188c];
    int unknown_188c;
    int unknown_1890;
    int unknown_1894;
    int unknown_1898;
    int unknown_189c;
    unsigned int unknown_18a0;
    int unknown_18a4;
    int unknown_18a8;

    int func_0002D240(int argument);
};

// Handler 25 of the table at 0x1EC068: resets +0x1894 to +0x18a4 and takes +0x18a8 from data_001EFFB0's
// func_000149D0_1; by the argument then sets +0x1890 and +0x189c and passes the values of data_001EDE50 for slot
// +0x18a8 (10 for arguments 3, 5 and 6) to data_001EFFB0's func_0003A7F0 / func_0003A840 for every row of +0x18a0
// (from row 1 for arguments 1, 2 and 4); arguments 1, 2, 4 and 7 also allocate the 1 MB block at data_00230DC0.
// Always allocates the 1 MB block at data_00230DBC and clears +0x188c.
int Object_000265A0::func_0002D240(int argument)
{
    unknown_189c = 4;
    unknown_1894 = 0;
    unknown_1898 = 0;
    unknown_18a0 = 4;
    unknown_18a4 = 0;
    unknown_18a8 = data_001EFFB0.func_000149D0_1();
    unsigned int i;
    unsigned int j;
    switch (argument) {
    case 3:
    case 5:
    case 6:
        unknown_18a8 = 10;
        unknown_1890 = 1;
        unknown_189c = 0;
        for (i = 0; i < unknown_18a0; i++) {
            for (j = 0; j < 5; j++) {
                data_001EFFB0.func_0003A7F0(i, j, data_001EDE50[unknown_18a8][i][j], 1);
                data_001EFFB0.func_0003A840(i, j, 0, 1);
            }
        }
        break;
    case 1:
    case 2:
    case 4:
        unknown_1890 = 0;
        unknown_189c = 4;
        data_00230DC0 = operator new(0x100000);
        for (i = 1; i < unknown_18a0; i++) {
            for (j = 0; j < 5; j++) {
                data_001EFFB0.func_0003A7F0(i, j, data_001EDE50[unknown_18a8][i][j], 0);
                data_001EFFB0.func_0003A840(i, j, 0, 0);
            }
        }
        break;
    case 7:
        unknown_1890 = 1;
        unknown_189c = 4;
        unknown_18a0 = 4;
        data_00230DC0 = operator new(0x100000);
        break;
    default:
        unknown_1890 = 0;
        unknown_189c = 0;
        for (i = 0; i < unknown_18a0; i++) {
            for (j = 0; j < 5; j++) {
                data_001EFFB0.func_0003A7F0(i, j, data_001EDE50[unknown_18a8][i][j], 0);
                data_001EFFB0.func_0003A840(i, j, 0, 0);
            }
        }
        break;
    }
    void *block = operator new(0x100000);
    unknown_188c = 0;
    data_00230DBC = block;
    return 1;
}
