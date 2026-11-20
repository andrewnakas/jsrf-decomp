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

struct Info_0004EA70 {
    char unknown_00[0x1c];
    int unknown_1c;
};

struct Object_0004EA70 {
    char unknown_0000[0x1040];
    Info_0004EA70 *info;
};

struct Other_0004AFC0 {
    char unknown_000[0x8ac];
    int port;
    char unknown_8b0[4];
    int mode;
};

// As func_0004EBC0 for objects 0xc to 0xf in mode 0 or 7 (or 0xb while +0x1c of object 9's block at +0x1040 is set),
// once object 9 exists, whose port's word at +0x34 is clear. Called from 0x52950 and 0x5BAD0.
int func_0004EC30(int *port)
{
    for (unsigned int i = 0; i < 4; i++) {
        Other_0004AFC0 *other = (Other_0004AFC0 *)data_0022FCE0->func_000128C0(i + 0xc);
        if (other && other->port != -1) {
            Object_0004EA70 *object = (Object_0004EA70 *)data_0022FCE0->func_000128C0(9);
            if (object && (other->mode == 0 || other->mode == 7 || (other->mode == 0xb && object->info->unknown_1c)) &&
                !data_00251DE8[other->port].unknown_34) {
                *port = other->port;
                if (*port == 4)
                    *port = data_00251F20;
                return 1;
            }
        }
    }
    return 0;
}
