// What the four globals hold: slot 2 releases it.
struct Unknown_001307C0 {
    virtual unsigned long __stdcall slot0();
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

struct Object_0006E130 {
    void func_0006E7B0(int id);
};

struct Object_00120420 {
    char unknown_0000[0x8a4];
    int ids[4];
    char unknown_08b4[0x29c];
    void *buffers[3];

    void func_001307C0();
};

extern int data_0025C314;
extern int data_0025C318;
extern int data_0025C31C;
extern int data_0025C320;
extern Object_0006E130 data_00252790;

// Releases the four objects at data_0025C314-data_0025C320 (slot 2) and clears them, then for the first three ids
// at 0x8a4 releases the id (func_0006E7B0 of data_00252790) and frees its buffer at 0xb50.
void Object_00120420::func_001307C0()
{
    if (data_0025C314) {
        ((Unknown_001307C0 *)data_0025C314)->slot2();
        data_0025C314 = 0;
    }
    if (data_0025C318) {
        ((Unknown_001307C0 *)data_0025C318)->slot2();
        data_0025C318 = 0;
    }
    if (data_0025C31C) {
        ((Unknown_001307C0 *)data_0025C31C)->slot2();
        data_0025C31C = 0;
    }
    if (data_0025C320) {
        ((Unknown_001307C0 *)data_0025C320)->slot2();
        data_0025C320 = 0;
    }
    if (ids[0] != -1) {
        data_00252790.func_0006E7B0(ids[0]);
    }
    if (buffers[0]) {
        operator delete(buffers[0]);
        buffers[0] = 0;
    }
    if (ids[1] != -1) {
        data_00252790.func_0006E7B0(ids[1]);
    }
    if (buffers[1]) {
        operator delete(buffers[1]);
        buffers[1] = 0;
    }
    if (ids[2] != -1) {
        data_00252790.func_0006E7B0(ids[2]);
    }
    if (buffers[2]) {
        operator delete(buffers[2]);
        buffers[2] = 0;
    }
}
