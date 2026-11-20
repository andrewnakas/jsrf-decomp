int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);

struct Object_000265A0 {
    char unknown_0000[0x1834];
    void *buffer_1834;
    void *buffer_1838;
    void *buffer_183c;
    void *buffer_1840;
    void *buffer_1844;
    void *buffer_1848;
    int ready;
    int unknown_1850;
    void *buffer_1854;
    void *buffer_1858;
    void *buffer_185c;
    void *buffer_1860;
    void *buffer_1864;
    int unknown_1868;
    void *buffer_186c;
    void *buffer_1870;

    void func_0002F420(int key);
};

// Handler 19 of the table at 0x1EC288: clears +0x184c and frees each loaded buffer from +0x1834 to +0x1870
// (func_00145A5D with 0x8000), clearing its pointer. The key is not used.
void Object_000265A0::func_0002F420(int)
{
    ready = 0;
    if (buffer_1834) {
        func_00145A5D(buffer_1834, 0, 0x8000);
        buffer_1834 = 0;
    }
    if (buffer_1854) {
        func_00145A5D(buffer_1854, 0, 0x8000);
        buffer_1854 = 0;
    }
    if (buffer_1838) {
        func_00145A5D(buffer_1838, 0, 0x8000);
        buffer_1838 = 0;
    }
    if (buffer_1858) {
        func_00145A5D(buffer_1858, 0, 0x8000);
        buffer_1858 = 0;
    }
    if (buffer_183c) {
        func_00145A5D(buffer_183c, 0, 0x8000);
        buffer_183c = 0;
    }
    if (buffer_185c) {
        func_00145A5D(buffer_185c, 0, 0x8000);
        buffer_185c = 0;
    }
    if (buffer_1840) {
        func_00145A5D(buffer_1840, 0, 0x8000);
        buffer_1840 = 0;
    }
    if (buffer_1844) {
        func_00145A5D(buffer_1844, 0, 0x8000);
        buffer_1844 = 0;
    }
    if (buffer_1860) {
        func_00145A5D(buffer_1860, 0, 0x8000);
        buffer_1860 = 0;
    }
    if (buffer_1848) {
        func_00145A5D(buffer_1848, 0, 0x8000);
        buffer_1848 = 0;
    }
    if (buffer_1864) {
        func_00145A5D(buffer_1864, 0, 0x8000);
        buffer_1864 = 0;
    }
    if (buffer_186c) {
        func_00145A5D(buffer_186c, 0, 0x8000);
        buffer_186c = 0;
    }
    if (buffer_1870) {
        func_00145A5D(buffer_1870, 0, 0x8000);
        buffer_1870 = 0;
    }
}
