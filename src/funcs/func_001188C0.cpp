/* sym: ??1Object_00117E10@@QAE@XZ = 0x00117E10 */
struct Interface_002589F4 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4();
    virtual long __stdcall slot5();
    virtual long __stdcall slot6(unsigned int index);
};

struct Buffer_001188C0 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
};

// A sound bank (destructor 0x117E10).
struct Object_00117E10 {
    unsigned int index;
    int unknown_04;
    int users;
    char unknown_0c[0x2c];

    ~Object_00117E10();
};

struct Object_00118CB0 {
    char unknown_0000[0x50];
    Buffer_001188C0 *buffers[0xfb2];
    unsigned int count;
    Object_00117E10 *banks[1];

    int func_001188C0(unsigned int index, int flag);
};

extern Interface_002589F4 *data_002589F4;
extern "C" void *memcpy(void *destination, const void *source, unsigned int size);

// Releases the bank loaded for `index` (0 when there is none): drops one user unless `flag` is set and returns 1
// while users remain; otherwise releases its buffer at +0x50 (0 when there is none), passes the index to slot 6 of
// data_002589F4, deletes the bank and closes the gap in the list at +0x3f1c (clearing the last entry only when
// it moved).
int Object_00118CB0::func_001188C0(unsigned int index, int flag)
{
    if (count <= 0) {
        return 0;
    }
    int found = -1;
    for (unsigned int i = 0; i < count; i++) {
        if (banks[i]->index == index) {
            found = i;
            break;
        }
    }
    if (found >= 0) {
        if (!flag) {
            banks[found]->users--;
            if (banks[found]->users > 0) {
                return 1;
            }
        }
        if (buffers[index] == 0) {
            return 0;
        }
        buffers[index]->slot2();
        buffers[index] = 0;
        data_002589F4->slot6(index);
        delete banks[found];
        banks[found] = 0;
        if (found < (int)count - 1) {
            memcpy(&banks[found], &banks[found + 1], (count - found - 1) * sizeof(Object_00117E10 *));
            banks[count - 1] = 0;
        }
        count--;
        return 1;
    }
    return 0;
}
