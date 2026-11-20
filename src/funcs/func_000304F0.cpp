int func_00145CCB(char *buffer, const char *format, ...);
void func_0004DB30(void *data);

// A loaded mission file: its number, data and links in the list at +0x198.
struct Load_000304F0 {
    unsigned int mission;
    void *data;
    Load_000304F0 **link;
    Load_000304F0 *next;
};

struct Object_000265A0 {
    char unknown_0000[0x198];
    Load_000304F0 *head;
    Load_000304F0 **tail;
    Load_000304F0 *load;
    int step;
    unsigned int mission;

    int func_00025400();
    int func_00025DD0(const char *path, void **data);
    int func_000304F0();
};

// Entry 0 of the table at 0x1EC0F0: step 0 starts loading mssnABCD.bin (A B from the high half of the mission number
// at +0x1a8, C D from the low half) into the load at +0x1a0; step 1 waits for func_00025400 and hands the data to
// func_0004DB30; step 2 appends the load to the list at +0x198 under the mission number. Returns 1 once done.
int Object_000265A0::func_000304F0()
{
    char path[260];
    switch (step) {
    case 0:
        func_00145CCB(path, "D:\\Media\\Mission\\mssn%1d%1d%1d%1d.bin", (mission >> 16) / 10 % 10,
                      (mission >> 16) % 10, (mission & 0xffff) / 10 % 10, (mission & 0xffff) % 10);
        if (!func_00025DD0(path, &load->data)) {
            break;
        }
        step = 1;
    case 1:
        if (!func_00025400()) {
            break;
        }
        func_0004DB30(load->data);
        step = 2;
    case 2:
        load->link = tail;
        *tail = load;
        tail = &load->next;
        load->mission = mission;
        load = 0;
        step = 3;
    case 3:
        return 1;
    }
    return 0;
}
