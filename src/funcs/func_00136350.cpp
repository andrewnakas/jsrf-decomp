// A texture of the table at data_0025ECA8: slot 4 locks it, slot 5 unlocks it.
struct Texture_00136350 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4(unsigned short **pixels, int first, int second);
    virtual void __stdcall slot5();
};

// The size of each of the five kinds of picture.
struct Size_0022C8AC {
    unsigned int width;
    unsigned int height;
};

struct Object_00136270 {
    int func_00136270(int index, int value);
    int func_00136350(int row, int index, int value);
};

extern unsigned int data_0022C898[5];
extern Size_0022C8AC data_0022C8AC[5];
extern unsigned short data_0025C328[];
extern unsigned char data_0025E328;
extern void *data_0025ECA8[4][5];

// When func_00136270 gives 1 for the index and value, copies the picture at data_0025C328 into the texture of the
// row for the current kind (data_0025E328), row by row with that kind's pitch; whether it did.
int Object_00136270::func_00136350(int row, int index, int value)
{
    if (func_00136270(index, value) == 1) {
        unsigned int kind = data_0025E328;
        unsigned short *pixels;
        ((Texture_00136350 *)data_0025ECA8[row][kind])->slot4(&pixels, 0, 0);
        unsigned short *out = pixels;
        unsigned int k = 0;
        for (unsigned int y = 0; y < data_0022C8AC[kind].height; y++) {
            for (unsigned int x = 0; x < data_0022C8AC[kind].width; x++) {
                out[data_0022C898[kind] * y + x] = data_0025C328[k++];
            }
        }
        ((Texture_00136350 *)data_0025ECA8[row][kind])->slot5();
        return 1;
    }
    return 0;
}
