struct Game {
    void func_000127C0(int index, int value);
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

int func_00024650();
void func_00024620(unsigned int color, float step);
int func_0006F190();
void func_0006F600(int port);

// The four controller ports (64 bytes each): flags (1: connected) and a word at +0x34.
struct Entry_00251DE8 {
    unsigned char flags;
    char unknown_01[0x33];
    int unknown_34;
    char unknown_38[8];
};

extern Entry_00251DE8 data_00251DE8[];
extern int data_00251F20;

struct Node {
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);

    char unknown_00[0x28];
    Node *child;
};

struct Object_000780F0 : Node {
    char unknown_02c[0x6c];
    int unknown_098;
    int unknown_09c;
    char unknown_0a0[0x88];
    int state;
    unsigned int flags;
    char unknown_130[0x328];
    int mode;

    void func_00078210(int first, int second);
    void func_000789F0();
    void func_00079740();
};

// The menu's steps (+0x128): 0 and 1 lead to 3; in 3, mode 2 (+0x458) waits for object 0x12af to go and then goes
// back to mode 0 (func_00078210), other modes run the menu (func_00079740) while the chosen port (0x251F20) has its
// word at +0x34, else hand the port to func_0006F600 and go to 5; 5 goes back to 3 once func_0006F190 says so; 6, once
// +0x9c is set, either sets the game's value 0x19b and goes to 7 or (with +0x98) goes back to mode 0 and step 3; 7
// fades out (func_00024620) once func_00024650 says so and takes the node out.
void Object_000780F0::func_000789F0()
{
    switch (state) {
    case 0:
        state = 1;
    case 1:
        state = 3;
    case 3:
        switch (mode) {
        case 2:
            if (!data_0022FCE0->func_000128C0(0x12af)) {
                mode = 0;
                func_00078210(0, 1);
            }
            break;
        default: {
            int port = data_00251F20;
            if (!data_00251DE8[port].unknown_34) {
                func_0006F600(port);
                state = 5;
                return;
            }
            func_00079740();
            return;
        }
        }
        break;
    case 5:
        if (func_0006F190()) {
            state = 3;
        }
        break;
    case 6:
        if (unknown_09c) {
            if (!unknown_098) {
                data_0022FCE0->func_000127C0(0x19b, 1);
                state = 7;
            } else {
                mode = 0;
                state = 3;
            }
        }
        break;
    case 7:
        if (func_00024650()) {
            func_00024620(0, 0.083333336f);
            flags |= 0x40000000;
            func_00011BE0(this);
            func_00011C20(child);
        }
        break;
    }
}
