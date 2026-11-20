/* const: 0x80000 */
struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The objects with ids 0x115e to 0x1162 (table 0x1D2020); flags at 0x1700.
struct Object_00107FE0 {
    char unknown_0000[0x1700];
    unsigned int flags;

    void func_00108050(int index, unsigned int mask, int set);
    void func_00108080(int kind, int flag, int first, int second);
};

void func_00106BD0(unsigned int id, unsigned int flags, int value);

// For an id from 0x115e to 0x1162: on, func_00108080(0, index, value, on) for an index below 0x17 (when the object
// exists), else func_00106BD0 with 0x80000; then flag 0x20000000 at 0x1700 is set and passed on (func_00108050). Off,
// func_00108080(0, index, value, 0), flag 0x20000000 cleared and passed on, 0x10000000 set; then func_00106BD0 with
// 0x80000 off.
void func_00106C10(unsigned int id, unsigned int index, int value, int on)
{
    if (id >= 0x115e && id <= 0x1162) {
        Object_00107FE0 *object = (Object_00107FE0 *)data_0022FCE0->func_000128C0(id);
        if (on) {
            if (index < 0x17) {
                if (!object) {
                    return;
                }
                object->func_00108080(0, index, value, on);
            } else {
                func_00106BD0(id, 0x80000, on);
            }
            if (object) {
                object->flags |= 0x20000000;
                object->func_00108050(8, 0x20000000, 1);
            }
        } else {
            if (object) {
                object->func_00108080(0, index, value, 0);
                object->flags &= ~0x20000000;
                object->func_00108050(8, 0x20000000, 0);
                object->func_00108050(8, 0x10000000, 1);
            }
            func_00106BD0(id, 0x80000, 0);
        }
    }
}
