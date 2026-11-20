struct Object_000265A0;

extern int data_001EC3D0[];
extern void (Object_000265A0::*data_001EC370[])();

struct Object_000265A0 {
    char unknown_000[0x6f8];
    int index;
    int unknown_6fc;

    int func_00027D40(int index);
};

// Handler 5 of the table at 0x1EC068: keeps an index, sets +0x6fc to 2 when the table at 0x1EC3D0 has -1 for it (else
// 0) and runs the index's handler from the table at 0x1EC370.
int Object_000265A0::func_00027D40(int index)
{
    this->index = index;
    unknown_6fc = data_001EC3D0[index] == -1 ? 2 : 0;
    (this->*data_001EC370[index])();
    return 1;
}
