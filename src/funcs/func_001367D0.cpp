struct Object_0006E130 {
    void func_0006E7B0(int id);
};

struct Object_00134880 {
    void func_001367D0();
};

extern Object_0006E130 data_00252790;
extern int data_0025EB98[4][5];
extern void *data_0025ECA8[4][5];

// Frees the 4 x 5 ids at data_0025EB98 through func_0006E7B0 of data_00252790 and deletes the 4 x 5 buffers at
// data_0025ECA8. Never reads this.
void Object_00134880::func_001367D0()
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (data_0025EB98[i][j] != -1) {
                data_00252790.func_0006E7B0(data_0025EB98[i][j]);
            }
            if (data_0025ECA8[i][j]) {
                operator delete(data_0025ECA8[i][j]);
                data_0025ECA8[i][j] = 0;
            }
        }
    }
}
