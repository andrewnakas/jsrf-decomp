/* const: 0x200000 */
/* const: 0x100000 */
/* const: 0x80000 */
void func_000F7920(float value);
void func_000F7AF0(float value);
void func_00024620(unsigned int color, float step);
void func_000FEB00(unsigned int mask, int value, int flag);

// The arguments of the command: a kind and a count.
struct Arguments_00107340 {
    int kind;
    unsigned int count;
};

// Called by func_0004C920 (on) and func_0004C940 (off) with a command's arguments: kind 0 passes the count to
// func_000F7AF0 (on) or func_000F7920 (off); kind 1 fades (func_00024620) to black or clear at 1/60 a frame; kinds 2
// to 10 switch the masks 0x4000000, 0x2000000, 0x1000000, 0x800000, 0x400000, 0x200000, 0x100000, 0x80000 and 2
// (func_000FEB00).
void func_00107340(void *arguments, int on)
{
    Arguments_00107340 *command = (Arguments_00107340 *)arguments;
    switch (command->kind) {
    case 0:
        if (on) {
            func_000F7AF0((float)command->count);
        } else {
            func_000F7920((float)command->count);
        }
        break;
    case 1:
        if (on) {
            func_00024620(0xff000000, 0.016666668f);
        } else {
            func_00024620(0, 0.016666668f);
        }
        break;
    case 2:
        func_000FEB00(0x4000000, 0, on);
        break;
    case 3:
        func_000FEB00(0x2000000, 0, on);
        break;
    case 4:
        func_000FEB00(0x1000000, 0, on);
        break;
    case 5:
        func_000FEB00(0x800000, 0, on);
        break;
    case 6:
        func_000FEB00(0x400000, 0, on);
        break;
    case 7:
        func_000FEB00(0x200000, 0, on);
        break;
    case 8:
        func_000FEB00(0x100000, 0, on);
        break;
    case 9:
        func_000FEB00(0x80000, 0, on);
        break;
    case 10:
        func_000FEB00(2, 0, on);
        break;
    }
}
