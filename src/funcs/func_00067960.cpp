struct Part_00067960 {
    char unknown_00[0x1c];
    int unknown_1c;
};

struct Object_00067960 {
    char unknown_000[0x678];
    Part_00067960 *part;

    int *func_00067960();
};

int *Object_00067960::func_00067960()
{
    if (part) {
        return &part->unknown_1c;
    }
    return 0;
}
