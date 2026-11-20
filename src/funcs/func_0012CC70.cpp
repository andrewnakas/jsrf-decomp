struct Object_00120420 {
    void func_0012CC70();
};

extern void *data_0025B110;
extern void *data_0025B114;

// Frees the two buffers func_0012CC40 allocates. Never reads this.
void Object_00120420::func_0012CC70()
{
    if (data_0025B110) {
        operator delete(data_0025B110);
        data_0025B110 = 0;
    }
    if (data_0025B114) {
        operator delete(data_0025B114);
        data_0025B114 = 0;
    }
}
