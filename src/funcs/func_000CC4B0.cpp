// The owner at 0x4 (Object_000C5B50): speed at 0x5c, flags at 0xa4, the object it follows at 0xe0.
struct Object_000C5B50 {
    char unknown_00[0x5c];
    float speed;
    char unknown_60[0x44];
    unsigned int flags;
    char unknown_a8[0x38];
    Object_000C5B50 *leader;
};

struct Limits_000CC020 {
    char unknown_00[0xc];
    float margin;
    float step;
};

// The base with a pure slot 0 (table 0x1CE304, destructor func_000E7EB0).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600();
};

// The class whose table is at 0x1CE320 (constructor func_000CC620, destructor func_000CC680).
struct Object_000CCE00 : Object_000CC600 {
    void func_000CC4B0(float value);

    Object_000C5B50 *owner;
    char unknown_08[0x28];
    Limits_000CC020 *limits;
};

// Raises the owner's speed at 0x5c by the step at 0x10 of the object at 0x30 while it is below value, up to
// value. An owner following another (0xe0) takes the leader's speed under flag 0x40, and otherwise steps again,
// capped at value plus the margin at 0xc.
void Object_000CCE00::func_000CC4B0(float value)
{
    if (owner->speed < value) {
        owner->speed = limits->step + owner->speed;
        if (owner->speed > value)
            owner->speed = value;
    }
    if (owner->leader != 0) {
        if (owner->flags & 0x40) {
            owner->speed = owner->leader->speed;
        } else {
            owner->speed = limits->step + owner->speed;
            if (owner->speed > value + limits->margin)
                owner->speed = value + limits->margin;
        }
    }
}
