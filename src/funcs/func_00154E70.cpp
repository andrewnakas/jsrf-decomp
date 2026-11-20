struct Unknown {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

int __stdcall func_0014A85B(void *handle);

// The device's list of resources (data_002650E8 entries at data_002650E4).
extern void **data_002650E4;
extern unsigned int data_002650E8;

// The Direct3D device wrapper (table 0x1E0F00).
struct Object_001E0F00 {
    void func_00154E70();
};

// Releases every resource left in the list until it goes away, then frees the list (func_0014A85B).
void Object_001E0F00::func_00154E70()
{
    if (data_002650E8) {
        for (unsigned int i = 0; i < data_002650E8; i++) {
            if (data_002650E4[i]) {
                while (static_cast<Unknown *>(data_002650E4[i])->slot2())
                    ;
                data_002650E4[i] = 0;
            }
        }
        if (data_002650E4) {
            func_0014A85B(data_002650E4);
            data_002650E4 = 0;
            data_002650E8 = 0;
        }
    }
}
