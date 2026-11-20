// One controller's state (0x40 bytes); +0 holds the buttons pressed this frame.
struct Entry_00251DE8 {
    unsigned char flags;
    char unknown_01[0x3f];
};

struct Object_00070850 {
    void func_00070960(int index);
};

struct Slot_00135640 {
    int state;
    char unknown_04[0x34];
};

struct Cursor_00135640 {
    int unknown_00;
    unsigned int left;
    unsigned int right;
    int unknown_0c;
};

struct Object_00135710 {
    char unknown_000[0x54c];
    Slot_00135640 slots[4];
    char unknown_62c[0xc4];
    Cursor_00135640 cursors[4];

    void func_00135640(int player);
};

extern Entry_00251DE8 data_00251DE8[];
extern int data_0022C6E4[];

// Reads the buttons of the player's controller: 1 or 4 confirms (state 6, sound 0); 0x8000 or a pending right
// count above 25 moves right (state 2, the count reset to 20, sound 3); 0x4000 or a pending left count above 25
// moves left (state 4, likewise).
void Object_00135710::func_00135640(int player)
{
    unsigned int pressed = *(unsigned int *)&data_00251DE8[data_0022C6E4[player]];
    if (!(pressed & 5)) {
        if (!(pressed & 0x8000) && cursors[player].right <= 0x19) {
            if ((pressed & 0x4000) || cursors[player].left > 0x19) {
                if (cursors[player].left > 0x19) {
                    cursors[player].left = 0x14;
                }
                slots[player].state = 4;
                ((Object_00070850 *)this)->func_00070960(3);
            }
        } else {
            if (cursors[player].right > 0x19) {
                cursors[player].right = 0x14;
            }
            slots[player].state = 2;
            ((Object_00070850 *)this)->func_00070960(3);
        }
    } else {
        slots[player].state = 6;
        ((Object_00070850 *)this)->func_00070960(0);
    }
}
