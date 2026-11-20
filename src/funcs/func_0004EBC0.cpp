struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The four controller ports (64 bytes each): flags (1: connected) and a word at +0x34.
struct Entry_00251DE8 {
    unsigned char flags;
    char unknown_01[0x33];
    int unknown_34;
    char unknown_38[8];
};

extern Entry_00251DE8 data_00251DE8[];
extern int data_00251F20;

struct Other_0004AFC0 {
    char unknown_000[0x8ac];
    int port;
    char unknown_8b0[4];
    int mode;
};

// Finds the first of objects 0xc to 0xf in mode 0 whose port (+0x8ac) is connected with its word at +0x34 set; keeps
// the port in *port (port 4: the one at 0x251F20) and returns 1, otherwise 0. Called from 0x5BAD0.
int func_0004EBC0(int *port)
{
    for (unsigned int i = 0; i < 4; i++) {
        Other_0004AFC0 *other = (Other_0004AFC0 *)data_0022FCE0->func_000128C0(i + 0xc);
        if (other && other->port != -1 && other->mode == 0 && (data_00251DE8[other->port].flags & 1) &&
            data_00251DE8[other->port].unknown_34) {
            *port = other->port;
            if (*port == 4)
                *port = data_00251F20;
            return 1;
        }
    }
    return 0;
}
