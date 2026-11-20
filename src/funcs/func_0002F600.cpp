// The block at +0x1588: six tables of pointers.
struct Tables_0002F600 {
    int unknown_000;
    void *first[0x20];
    void *second[0x13];
    void *third[2];
    void *fourth[1];
    void *fifth[9];
    void *sixth[1];
};

struct Object_000265A0 {
    char unknown_0000[0x1588];
    Tables_0002F600 *tables;

    void *func_0002F600(int unused, int kind, int index);
};

// Handler 11 of the table at 0x1EC200: pointer `index` of one of the six tables of the block at +0x1588 by kind (for
// kind 0, the values 0x103 and 0x102 for indices 0x100 and 0x101); 0 otherwise or without the block.
void *Object_000265A0::func_0002F600(int, int kind, int index)
{
    Tables_0002F600 *tables = this->tables;
    if (tables) {
        switch (kind) {
        case 0:
            switch (index) {
            case 0x100:
                return (void *)0x103;
            case 0x101:
                return (void *)0x102;
            }
            return tables->first[index];
        case 1:
            return tables->second[index];
        case 2:
            return tables->third[index];
        case 3:
            return tables->fourth[index];
        case 4:
            return tables->fifth[index];
        case 5:
            return tables->sixth[index];
        }
    }
    return 0;
}
