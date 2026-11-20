/* const: 0x40000 */
struct Vector3;

// The owner at 0x4. The objects of this family call func_000C5B50 (and func_000C59A0, func_000C5B10, ...) with
// this taken from 0x4, so the owner is that function's class.
struct Object_000C5B50 {
    char unknown_00[0x5c];
    float value_5c;
    char unknown_60[0x44];
    unsigned int flags;

};

// The rates at 0x30: up and down.
struct Rates_000CD310 {
    float up;
    float down;
};

// The base with a pure slot 0 (table 0x1CE304).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600() {}
};

// The class whose table is at 0x1CE364; slots 8 and 9 are pure.
struct Object_000CD1E0 : Object_000CC600 {
    Object_000CD1E0();
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_000CD210();
    virtual void func_000CD800();
    virtual void func_000CD850();
    virtual void func_000D77D0() = 0;
    virtual void func_000D7880() = 0;
    virtual float func_000CD440();
    virtual float func_000CD4F0();
    virtual int func_000CD390(Vector3 *position, float value, Vector3 *direction);

    Object_000C5B50 *owner;
    int state;
    int unknown_0c;
    int unknown_10;
    char unknown_14[0x1c];
    Rates_000CD310 *rates;

    void func_000CD310(float rate);
};

// Moves the owner's value at 0x5c towards the rate by the up or down step at 0x30 without passing it; flag 0x40000
// of the owner is set while it rises and cleared while it falls.
void Object_000CD1E0::func_000CD310(float rate)
{
    if (owner->value_5c < rate) {
        owner->value_5c += rates->up;
        if (owner->value_5c > rate) {
            owner->value_5c = rate;
        }
        owner->flags |= 0x40000;
    } else {
        owner->value_5c -= rates->down;
        if (owner->value_5c < rate) {
            owner->value_5c = rate;
        }
        owner->flags &= ~0x40000;
    }
}
