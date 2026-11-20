struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// What func_0004EA50 fills in (0x118 bytes).
struct Info_0004D460 {
    unsigned int values[5];
    char unknown_14[0x104];
};

void func_0004EA50(Info_0004D460 *info);
int func_0003BFB0();
int func_0003BEC0(int key);

struct Object_0003E750 {
    int func_0003E830(int key, int);
};

extern Object_0003E750 data_002314B0;

// The object a player slot points at: the id of another object at +0x8d4.
struct Holder_000500F0 {
    char unknown_000[0x8d4];
    int target;
};

// The object that one names: its port at +0xfbc.
struct Player_000732D0 {
    char unknown_000[0xfbc];
    int port;
};

struct Object_00073AD0 {
    int func_000732D0(int mode, int port);
};

// Whether `port` is the one port that still has something in the given mode: mode 4 needs func_0003BFB0 and counts
// with func_0003BEC0, mode 5 needs the info's first value not above its second and counts with data_002314B0's
// func_0003E830; the four players (objects 0xc to 0xf and the objects they name) give the ports and counts.
int Object_00073AD0::func_000732D0(int mode, int port)
{
    switch (mode) {
    case 4:
        if (!func_0003BFB0()) {
            return 0;
        }
        break;
    case 5: {
        Info_0004D460 info;
        func_0004EA50(&info);
        if (info.values[0] > info.values[1]) {
            return 0;
        }
        break;
    }
    }
    int counts[4];
    int ports[4];
    int found = 0;
    for (int i = 0; i < 4; i++) {
        Holder_000500F0 *holder = (Holder_000500F0 *)data_0022FCE0->func_000128C0(i + 0xc);
        if (holder) {
            Player_000732D0 *player = (Player_000732D0 *)data_0022FCE0->func_000128C0(holder->target);
            if (player) {
                ports[i] = player->port;
                switch (mode) {
                case 4:
                    counts[i] = func_0003BEC0(i);
                    break;
                case 5:
                    counts[i] = data_002314B0.func_0003E830(i, 0);
                    break;
                }
                if (counts[i] > 0) {
                    found++;
                }
            } else {
                ports[i] = -1;
                counts[i] = 0;
            }
        }
    }
    if (found != 1) {
        return 0;
    }
    for (int j = 0; j < 4; j++) {
        if (ports[j] >= 0 && counts[j] > 0 && port == ports[j]) {
            return 1;
        }
    }
    return 0;
}
