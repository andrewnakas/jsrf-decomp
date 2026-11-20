struct Object_00133350 {
    char unknown_0000[0x2eba];
    char bytes_2eba[7];

    void func_00133350();
};

// Clears the seven bytes at +0x2eba.
void Object_00133350::func_00133350()
{
    for (int i = 0; i < 7; i++) {
        bytes_2eba[i] = 0;
    }
}
