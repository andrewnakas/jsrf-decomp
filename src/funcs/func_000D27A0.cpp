struct Object_00016200 {
    void func_00019760(void *pointer);
    void func_0001B400(int key);
};

extern Object_00016200 data_0022FCE8;

struct Object_0003E750 {
    void func_0003F280(int index);
};

extern Object_0003E750 data_002314B0;

struct Object_0006DB80 {
    void func_0006DF30(int key);
};

extern Object_0006DB80 data_00251F78;

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    void func_00060810(int key);
};

// The owner at 0x4.
struct Object_000C5B50 {
    void func_000C5B50(int *handle);
};

void func_0005DAA0(void *pointer);

// The base with a pure slot 0 (table 0x1CE304, destructor func_000E7EB0).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600() {}
};

// The class whose table is at 0x1CE450 (constructor func_000D27F0).
struct Object_000D27F0 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000D27F0();

    void func_000D27A0();

    Object_000C5B50 *owner;
    char unknown_008[0xedc];
    int sounds[4];
    char unknown_ef4[0x1c];
    void *blocks[3];
    char unknown_f1c[0x70];
    void *mesh_f8c;
    char unknown_f90[0x20];
    void *mesh_fb0;
    char unknown_fb4[0x30];
    int key_fe4;
    int effect_fe8;
    char unknown_fec[8];
    int key_ff4;
    char unknown_ff8[4];
    int handle_ffc;
};

// Stops each of the four sounds at 0xee4 that is set (not negative) through object 0xe8 (func_00060810) and marks it
// -1.
void Object_000D27F0::func_000D27A0()
{
    Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (object) {
        for (int i = 0; i < 4; i++) {
            if (sounds[i] >= 0) {
                object->func_00060810(sounds[i]);
                sounds[i] = -1;
            }
        }
    }
}
