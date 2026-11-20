// A sprite from func_00025700: flags at 0x24.
struct Sprite_000FC500 {
    char unknown_00[0x24];
    unsigned int flags;
};

// The class whose constructor func_000FBFD0 runs entry `mode` (at 0x58) of the member-function table at 0x21FDA8
// on itself.
struct Object_000FBFD0 {
    char unknown_00[0x54];
    int value_54;
    char unknown_58[8];
    Sprite_000FC500 *sprite_60;
    char unknown_64[0x18];
    void *sprite_7c;
    int unknown_80;
    void *sprite_84;
    void *sprite_88;

    void func_000FC500();
};

void *func_00025700(unsigned int index, int first, int second, int third);

// Entry 0 of that table: the first sprite by the value at 0x54 (0x24, 0x25 and 0x7a for 8, 9 and 0x27; value + 0x54
// for 0x28 to 0x2b, with bit 0 of its flags set; else value + 0x1c and sprite 0x36 at 0x7c), then sprites 7 and 8 of
// set 0xa at 0x84 and 0x88.
void Object_000FBFD0::func_000FC500()
{
    switch (value_54) {
    case 8:
        sprite_60 = (Sprite_000FC500 *)func_00025700(0xa, 0, 1, 0x24);
        break;
    case 9:
        sprite_60 = (Sprite_000FC500 *)func_00025700(0xa, 0, 1, 0x25);
        break;
    case 0x27:
        sprite_60 = (Sprite_000FC500 *)func_00025700(0xa, 0, 1, 0x7a);
        break;
    case 0x28:
    case 0x29:
    case 0x2a:
    case 0x2b:
        sprite_60 = (Sprite_000FC500 *)func_00025700(0xa, 0, 1, value_54 + 0x54);
        if (sprite_60) {
            sprite_60->flags &= ~1;
            sprite_60->flags |= 1;
        }
        break;
    default:
        sprite_60 = (Sprite_000FC500 *)func_00025700(0xa, 0, 1, value_54 + 0x1c);
        sprite_7c = func_00025700(0xa, 0, 1, 0x36);
        break;
    }
    sprite_84 = func_00025700(0xa, 0, 2, 7);
    sprite_88 = func_00025700(0xa, 0, 2, 8);
}
