void *func_00025700(unsigned int index, int first, int second, int third);

// A sprite from func_00025700: flags at 0x24.
struct Sprite_000FC630 {
    char unknown_00[0x24];
    unsigned int flags;
};

// The class whose constructor func_000FBFD0 runs entry `mode` (at 0x58) of the member-function table at 0x21FDA8
// on itself (table 0x1D1B68).
struct Object_000FBFD0 {
    char unknown_000[0x54];
    int kind;
    char unknown_058[8];
    Sprite_000FC630 *sprite_60;
    Sprite_000FC630 *sprite_64;
    Sprite_000FC630 *sprite_68;
    Sprite_000FC630 *sprite_6c;
    char unknown_070[0xc];
    Sprite_000FC630 *sprite_7c;
    char unknown_080[4];
    Sprite_000FC630 *sprite_84;
    Sprite_000FC630 *sprite_88;

    void func_000FC630();
};

// Entry 2 of data_0021FDA8: loads the sprites of set 0xa for the kind at 0x54 (func_00025700 (0xa, 0, 1, n)): kinds
// 0-8 and 10-12 take 0x1c and 0x29 past the kind and 0x36; 13 takes 0x20, 0x2d, 0x37 and 0x36; 14 takes 0x28, 0x35,
// 0x37 and 0x36; 0x2c takes 0x38 with bit 0 of its flags cleared. Then sprites 0x10, 7 and 8 of (0xa, 0, 2).
void Object_000FBFD0::func_000FC630()
{
    switch (kind) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 10:
    case 11:
    case 12:
        sprite_60 = (Sprite_000FC630 *)func_00025700(0xa, 0, 1, kind + 0x1c);
        sprite_64 = (Sprite_000FC630 *)func_00025700(0xa, 0, 1, kind + 0x29);
        sprite_7c = (Sprite_000FC630 *)func_00025700(0xa, 0, 1, 0x36);
        break;
    case 13:
        sprite_60 = (Sprite_000FC630 *)func_00025700(0xa, 0, 1, 0x20);
        sprite_64 = (Sprite_000FC630 *)func_00025700(0xa, 0, 1, 0x2d);
        sprite_68 = (Sprite_000FC630 *)func_00025700(0xa, 0, 1, 0x37);
        sprite_7c = (Sprite_000FC630 *)func_00025700(0xa, 0, 1, 0x36);
        break;
    case 14:
        sprite_60 = (Sprite_000FC630 *)func_00025700(0xa, 0, 1, 0x28);
        sprite_64 = (Sprite_000FC630 *)func_00025700(0xa, 0, 1, 0x35);
        sprite_68 = (Sprite_000FC630 *)func_00025700(0xa, 0, 1, 0x37);
        sprite_7c = (Sprite_000FC630 *)func_00025700(0xa, 0, 1, 0x36);
        break;
    case 0x2c:
        sprite_60 = (Sprite_000FC630 *)func_00025700(0xa, 0, 1, 0x38);
        if (sprite_60) {
            sprite_60->flags &= ~1;
        }
        break;
    }
    sprite_6c = (Sprite_000FC630 *)func_00025700(0xa, 0, 2, 0x10);
    sprite_84 = (Sprite_000FC630 *)func_00025700(0xa, 0, 2, 7);
    sprite_88 = (Sprite_000FC630 *)func_00025700(0xa, 0, 2, 8);
}
