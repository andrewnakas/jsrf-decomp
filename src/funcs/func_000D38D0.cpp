struct Vector3 {
    float x;
    float y;
    float z;
};

void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);
void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    int func_000C5B10(int message, void *data);
    void func_000C5B40(int id, void *position);
    void func_000C5B50(int *handle);
    int func_000C5B70(int handle);

    char unknown_00[0xa4];
    unsigned int flags;
};

// The class (constructor func_000D27F0) whose slot 0 runs the member-function table at 0x2169e0.
struct Object_000D27F0 {
    char unknown_000[0x4];
    Object_000C5B50 *owner;
    char unknown_008[0x88];
    Vector3 path[300];
    Vector3 direction;
    char unknown_eac[0xc];
    unsigned int count;
    unsigned int next;
    char unknown_ec0[0x13c];
    int mark;

    void func_000D27A0();
    void func_000D38D0(int back);
};

// Steps the path at 0x90 back by `back` points while more than that are left past the next one (0xebc): the
// direction at 0xea0 from the new last point to the one after it (func_0014C4C0, func_0014C410), and the owner's
// mark at 0xffc moved there (func_000C5B40) or made (message 0x26); at least one point stays. Otherwise one point is
// left, the owner loses the flag 0x8000000, the sounds stop (func_000D27A0) and the mark is released.
void Object_000D27F0::func_000D38D0(int back)
{
    if (count > next + back) {
        count -= back;
        func_0014C4C0(&direction, &path[count + 1], &path[count]);
        func_0014C410(&direction, &direction);
        if (owner->func_000C5B70(mark)) {
            owner->func_000C5B40(mark, &path[count]);
        } else {
            mark = owner->func_000C5B10(0x26, &path[count]);
        }
        if (count < 1) {
            count = 1;
        }
        return;
    }
    count = 1;
    owner->flags &= ~0x8000000;
    func_000D27A0();
    owner->func_000C5B50(&mark);
}
