struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);

    unsigned int flags;
    int id;
    unsigned int mask;
    float depth;
    int sortKey;
    char unknown_18[0xc];
    Node *parent;
    Node *child;
    Node *previous;
    Node *next;
    char unknown_34[0x10];
};

// Object 5's class, whose table is at 0x1D76C8: the ADX handles of its four channels at 0x68 (0 and 1 take turns
// as the music channel, the one at 0x78 current).
struct Object_00116A10 : Node {
    virtual ~Object_00116A10();
    virtual void func_00011C90();

    void func_00116290(int channel, char value);
    void func_00116C30();

    char unknown_44[0x24];
    void *handles[4];
    int current;
    char unknown_7c[0x20];
    int track;
    char unknown_a0[4];
    int crossing;
    char unknown_a8[0x14];
    int music;
    int voice;
    int sound;
    int effect;
    int extra;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

unsigned int func_0013A9A0(void *handle, int which);
void func_0013AA70(void *handle, char value);
int func_0013BF30(void *handle);
void func_001166E0(int track);

// Watches the channels: once the faded-out channel (during a cross-fade, flag at 0xa4) or the starting music channel
// (state 1 at 0xbc) has 0x2000 or more of func_0013A9A0, moves on (state 2; ends the cross-fade with func_001166E0,
// or passes 0 to object 5's current channel); the same for channels 2 and 3 (states at 0xc0 and 0xc8, passing 0 to
// object 5's handle), channel 1 (state at 0xcc, passing 0 to its own handle) and channel 1 again (state at 0xc4).
// A state goes back to 0 when func_0013BF30 gives 0 or 5 for its handle (the music one also clears 0x9c).
void Object_00116A10::func_00116C30()
{
    if (crossing) {
        if (func_0013A9A0(handles[current ^ 1], 0) >= 0x2000) {
            crossing = 0;
            music = 2;
            func_001166E0(0);
        }
    } else if (music == 1) {
        if (func_0013A9A0(handles[current], 0) >= 0x2000) {
            music = 2;
            Object_00116A10 *other = (Object_00116A10 *)data_0022FCE0->func_000128C0(5);
            if (other) {
                other->func_00116290(other->current, 0);
            }
        }
    }
    int state = func_0013BF30(handles[current]);
    if (state == 0 || state == 5) {
        music = 0;
        track = -1;
    }
    if (voice == 1) {
        if (func_0013A9A0(handles[2], 0) >= 0x2000) {
            voice = 2;
            Object_00116A10 *other = (Object_00116A10 *)data_0022FCE0->func_000128C0(5);
            if (other) {
                func_0013AA70(other->handles[2], 0);
            }
        }
    }
    state = func_0013BF30(handles[2]);
    if (state == 0 || state == 5) {
        voice = 0;
    }
    if (effect == 1) {
        if (func_0013A9A0(handles[3], 0) >= 0x2000) {
            effect = 2;
            Object_00116A10 *other = (Object_00116A10 *)data_0022FCE0->func_000128C0(5);
            if (other) {
                func_0013AA70(other->handles[3], 0);
            }
        }
    }
    state = func_0013BF30(handles[3]);
    if (state == 0 || state == 5) {
        effect = 0;
    }
    int *slot = &extra;
    if (*slot == 1) {
        if (func_0013A9A0(handles[1], 0) >= 0x2000) {
            *slot = 2;
            func_0013AA70(handles[1], 0);
        }
    }
    state = func_0013BF30(handles[1]);
    if (state == 0 || state == 5) {
        extra = 0;
    }
    if (sound == 1) {
        if (func_0013A9A0(handles[1], 0) >= 0x2000) {
            sound = 2;
        }
    }
    state = func_0013BF30(handles[1]);
    if (state == 0 || state == 5) {
        sound = 0;
    }
}
