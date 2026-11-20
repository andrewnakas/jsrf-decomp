/* sym: ?func_00011C90_1@Object_000C7910@@UAEXXZ = 0x000C7330 */
struct Node {
    virtual ~Node();
    virtual void func_00011C90_1();

    char unknown_04[0x40];
};

// The second base (table 0x1CE1B8), two slots.
struct Object_000C60C0 {
    virtual void func_000C6090();
    virtual void func_000C60C0();
};

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Object_00047470 {
    void func_00047970(void *motion, int frame);
    void func_000480C0(unsigned int flags);
};

struct Object_000C1440 {
};

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 : Object_000C1440 {
    int func_000C1D40(int *effect, int *second, int *third);
};

extern Object_00157F10 *data_00257CE8;

// The effects object at 0xb0: its key at 0x9c and flags at 0xa4.
struct Object_000C5B50 {
    char unknown_00[0x9c];
    int key;
    char unknown_a0[4];
    unsigned int flags;

    int func_000C5B10(int kind, void *data);
};

struct Object_0006DB80 {
    void func_0006DFC0(int sound, const Vector3 *position);
};

extern Object_0006DB80 data_00251F78;

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// Player 0x2c: a word per slot at 0xfec.
struct Player_000C7330 {
    char unknown_0000[0xfec];
    int slots[1];
};

void func_000FEC30(int key, const Vector3 *position);
void func_001BA9C0();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAA50();

// The class whose tables are at 0x1CE1C8 (Node) and 0x1CE1C0 (Object_000C60C0 at +0x44).
struct Object_000C7910 : Node, Object_000C60C0 {
    virtual void func_00011C90_1();

    Vector3 position;
    char unknown_054[0x3c];
    unsigned int flags;
    char unknown_094[4];
    int sound;
    int fresh;
    char unknown_0a0[0x10];
    Object_000C5B50 *effects;
    char unknown_0b4[8];
    int mode;
    char unknown_0c0[0x7c];
    int slot;
    char unknown_140[0x44];
    Object_00047470 *model;
    char unknown_188[0x14];
    void *motion;
    char unknown_1a0[0x1c];
    int state;
    char unknown_1c0[0x1f8];
    int effect;
    int value_3bc;
    int value_3c0;

    void func_000C9860();
    void func_000CA920();
};

// Slot 2 (the move), unless flag 0x2000 is set: func_000CA920 (func_000C9860 in mode 0x17); while the effects at 0xb0
// have flag 0x4000, follows the effect at 0x3b8 (func_000C1D40): when it is over sets flag 0x2000 (clearing 0x1208000),
// mode 0x1a, state 0x18, frees the player slot at 0x13c, starts effect 0x11 at the position and marks 0x9c; otherwise
// func_000FEC30 of the effects' key and the position. With a sound at 0x98, plays it at the model's origin (posed with
// the motion at 0x19c, part 9).
void Object_000C7910::func_00011C90_1()
{
    if (flags & 0x2000) {
        return;
    }
    if (mode != 0x17) {
        func_000CA920();
    } else {
        func_000C9860();
    }
    if (effects->flags & 0x4000) {
        if (data_00257CE8->func_000C1D40(&effect, &value_3c0, &value_3bc)) {
            flags = (flags & ~0x1208000) | 0x2000;
            mode = 0x1a;
            state = 0x18;
            if (slot >= 0) {
                Player_000C7330 *player = (Player_000C7330 *)data_0022FCE0->func_000128C0(0x2c);
                if (player) {
                    player->slots[slot] = 0;
                }
                slot = -1;
            }
            effects->func_000C5B10(0x11, &position);
            fresh = 1;
        } else {
            func_000FEC30(effects->key, &position);
        }
    }
    if (sound != -1) {
        Vector3 origin = {0.0f};
        func_001BA9C0();
        func_001BAAA0(&position.x);
        model->func_00047970(motion, 0);
        model->func_000480C0(9);
        func_001BAB20(&origin, &origin);
        func_001BAA50();
        data_00251F78.func_0006DFC0(sound, &origin);
    }
}
