/* sym: ?func_00011C90@Object_000EA3B0@@UAEXXZ = 0x000E96E0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    void func_00060810(int key);
};

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    void func_000C5AD0(int amount);
    void func_000C5B50(int *handle);

    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0x4c];
    int value_9c;
    char unknown_a0[4];
    unsigned int flags;
};

void func_000FEC30(int value, const Vector3 *position);

// The 0x6c-byte part at 0x30 of Object_000EA3B0 and at 0xbc of Object_000ECB50.
struct Part_000EB830 {
    char unknown_00[0x18];
    int marks[4];
    int marks_28[4];
    char unknown_38[0x34];

    int func_000EBBF0(unsigned int *flags);
};

// The base with a pure slot 0 (table 0x1CE304, destructor func_000E7EB0).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600() {}
};

// The object func_000EA3B0 builds (0x1f4 bytes; table 0x1CEE78).
struct Object_000EA3B0 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000EA3B0();

    Object_000C5B50 *owner;
    int state;
    char unknown_00c[4];
    int timer;
    Vector3 position;
    char unknown_020[0x10];
    Part_000EB830 part;
    char unknown_09c[0x44];
    int sounds[4];
    char unknown_0f0[0x10];
    int sound_100;
    char unknown_104[0xec];
    int value_1f0;
};

// Slot 1: unless the owner has the flag 0x2000000, puts it at the position at 0x14; once the part's four effects are
// on (func_000EBBF0), gives it that flag and func_000C5AD0(1), state 8 with 1 at 0x1f0 and the timer cleared, stops
// the four sounds at 0xe0 (cleared) and the one at 0x100 through object 0xe8, and hands the owner back the part's
// eight marks; else passes the owner's position to func_000FEC30.
void Object_000EA3B0::func_00011C90()
{
    if (!(owner->flags & 0x2000000)) {
        owner->position = position;
        unsigned int count = part.func_000EBBF0(&owner->flags);
        if (count >= 4) {
            owner->flags |= 0x2000000;
            owner->func_000C5AD0(1);
            state = 8;
            value_1f0 = 1;
            timer = 0;
            Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
            if (object) {
                if (sounds[0]) {
                    for (int i = 0; i < 4; i++) {
                        object->func_00060810(sounds[i]);
                        sounds[i] = 0;
                    }
                }
                if (sound_100) {
                    object->func_00060810(sound_100);
                }
            }
            for (int j = 0; j < 4; j++) {
                owner->func_000C5B50(&part.marks[j]);
                owner->func_000C5B50(&part.marks_28[j]);
            }
            return;
        }
        func_000FEC30(owner->value_9c, &owner->position);
    }
}
