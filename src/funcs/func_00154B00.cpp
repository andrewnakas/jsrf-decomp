extern void **data_00264F68;
unsigned long __stdcall func_00192790(void *resource);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), constructor 0x14CDB0, 0xE4 bytes.
struct Object_001E0F00 {
    virtual long __stdcall func_0014CF20(const void *iid, void **object);  // slot 0
    int func_00154B00(unsigned int index);
};

// Whether func_00192790 gives 4 for entry index of the table at data_00264F68.
int Object_001E0F00::func_00154B00(unsigned int index)
{
    void *resource = data_00264F68[index];
    return func_00192790(resource) == 4;
}
