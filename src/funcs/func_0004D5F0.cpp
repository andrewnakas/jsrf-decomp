struct Game {
    int func_000127E0(int index);
};

extern Game *data_0022FCE0;

struct Object_00039BE0 {
    int func_00039D10(unsigned int index);
};

extern Object_00039BE0 data_001EFFB0;

// The 32 entries of the ring that object 0xd's value is looked up in.
extern unsigned int data_001F9808[32];

struct Object_0004ABA0 {
    unsigned int func_0004D5F0(unsigned int *list);
};

// Finds object 0xd's value in the ring at 0x1F9808 and lists, without repeats, the next five entries after it and
// then the four before it that func_00039D10 of 0x1EFFB0 accepts. Returns how many it listed.
unsigned int Object_0004ABA0::func_0004D5F0(unsigned int *list)
{
    unsigned int count = 0;
    unsigned int current = data_0022FCE0->func_000127E0(0xd);
    unsigned int start;
    for (start = 0; start < 32; start++) {
        if (data_001F9808[start] == current)
            break;
    }
    unsigned int index = start - 1;
    unsigned int n;
    unsigned int j;
    for (n = 0; n < 5; n++) {
        do {
            index = (index + 1) & 0x1f;
        } while (!data_001EFFB0.func_00039D10(data_001F9808[index]));
        for (j = 0; j < count; j++) {
            if (list[j] == data_001F9808[index])
                break;
        }
        if (j == count)
            list[count++] = data_001F9808[index];
    }
    index = start;
    for (n = 0; n < 4; n++) {
        do {
            index = (index - 1) & 0x1f;
        } while (!data_001EFFB0.func_00039D10(data_001F9808[index]));
        for (j = 0; j < count; j++) {
            if (list[j] == data_001F9808[index])
                break;
        }
        if (j == count)
            list[count++] = data_001F9808[index];
    }
    return count;
}
