struct Unknown {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

int __stdcall func_0014A85B(void *handle);

// The list of objects at data_00265120 (data_00265124 entries).
extern void **data_00265120;
extern unsigned int data_00265124;

// Releases every object left in the list until it goes away, then frees the list (func_0014A85B). The argument
// is not used.
void __stdcall func_00159E20(void *link)
{
    if (data_00265124) {
        for (unsigned int i = 0; i < data_00265124; i++) {
            if (data_00265120[i]) {
                while (static_cast<Unknown *>(data_00265120[i])->slot2())
                    ;
                data_00265120[i] = 0;
            }
        }
        if (data_00265120) {
            func_0014A85B(data_00265120);
            data_00265120 = 0;
            data_00265124 = 0;
        }
    }
}
