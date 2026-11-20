struct Object_0003E750 {
    int func_0003EE90(void *effect, int first, int second, int third, float scale, int kind, int owner, int fourth);
};

extern Object_0003E750 data_002314B0;
extern char data_00219448[];
extern char data_002195A8[];
extern char data_00219708[];
extern char data_00219868[];

// The 0x6c-byte part at 0x30 of Object_000EA3B0 and at 0xbc of Object_000ECB50.
struct Part_000EB830 {
    int kind;
    char unknown_04[0x38];
    int effects[4];

    void func_000EBAA0(int owner);
};

// Starts the effects data_00219448, data_002195A8 and data_00219708 (scale 0.3) for `owner` into the first three
// slots at 0x3c (func_0003EE90 of data_002314B0); the fourth gets data_00219868 at scale 2 for kind 0, else -1.
void Part_000EB830::func_000EBAA0(int owner)
{
    effects[0] = data_002314B0.func_0003EE90(data_00219448, -1, -1, 1, 0.3f, 2, owner, -1);
    effects[1] = data_002314B0.func_0003EE90(data_002195A8, -1, -1, 1, 0.3f, 2, owner, -1);
    effects[2] = data_002314B0.func_0003EE90(data_00219708, -1, -1, 1, 0.3f, 2, owner, -1);
    if (kind == 0) {
        effects[3] = data_002314B0.func_0003EE90(data_00219868, -1, -1, 1, 2.0f, 2, owner, -1);
    } else {
        effects[3] = -1;
    }
}
