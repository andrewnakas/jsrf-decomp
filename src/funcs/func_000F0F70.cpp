/* sym: ?func_00011C80@Object_000F1820@@UAEXH@Z = 0x000F0F70 */
struct Motion_0005F060;

// The owner: its flags at 0xa4.
struct Object_000C5B50 {
    char unknown_00[0x44];
    float position[3];
    char unknown_50[0x54];
    unsigned int flags;
};

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 {
    void func_000C1690(int key);
    void func_000C1730(int *handle);
    void func_000C1770(int key);
};

extern Object_00157F10 *data_00257CE8;

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);

extern unsigned int data_0021AFC0[4];

// The models at 0x78, 0x7c and 0x80: slot 5 poses them; four weights at 0x74 and four keys at 0x88.
struct Object_00047470 {
    virtual void func_00();
    virtual void func_04();
    virtual void func_08();
    virtual void func_0C();
    virtual void func_10();
    virtual void func_14(Motion_0005F060 *motion, float time);

    void func_000480C0(unsigned int index);

    char unknown_04[0x70];
    float weights[4];
    char unknown_84[4];
    int keys[4];
};

// The base of the owner's behaviours (table 0x1CE304): slot 0 is pure, slots 2 and 3 take an argument, slot 4 is
// the destructor.
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
};

// The state machine whose table is at 0x1CF02C (constructor func_000F1820), made by func_000F1FC0.
struct Object_000F1820 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C80(int argument);

    Object_000C5B50 *owner;
    char unknown_008[0x28];
    int done;
    char unknown_034[0x44];
    Object_00047470 *part;
    Object_00047470 *first;
    Object_00047470 *second;
    Motion_0005F060 **motions;
    char unknown_088[0x20];
    Motion_0005F060 *motion;
    Motion_0005F060 *secondMotion;
    char unknown_0b0[0xbc];
    int sounds[4];
    float values[4];
    int seconds[4];
    int key;
};

// Slot 2: on message 0, gives the model at 0x7c (or 0x80 once the owner has flag 0x2000) twice the four values at
// 0x17c and the four keys at 0x18c and draws the part at 0x78 and that model with the motions at 0xa8 and 0xac (or
// motions 20 and 21 with the model at 0x80). Without the flag, at the owner's position, a done machine (0x30) first
// releases its key at 0x19c (func_000C1730, then -1); the key goes to func_000C1690 and each of the four sounds at
// 0x16c to func_000C1770 on the model's matrices data_0021AFC0.
void Object_000F1820::func_00011C80(int argument)
{
    if (argument) {
        return;
    }
    if (!(owner->flags & 0x2000)) {
        first->weights[0] = values[0] * 2.0f;
        first->keys[0] = seconds[0];
        first->weights[1] = values[1] * 2.0f;
        first->keys[1] = seconds[1];
        first->weights[2] = values[2] * 2.0f;
        first->keys[2] = seconds[2];
        first->weights[3] = values[3] * 2.0f;
        first->keys[3] = seconds[3];
        part->func_14(motion, 0.0f);
        first->func_14(secondMotion, 0.0f);
        func_001BA9C0();
        func_001BAAA0(owner->position);
        if (done) {
            data_00257CE8->func_000C1730(&key);
            done = 0;
            key = -1;
        }
        data_00257CE8->func_000C1690(key);
        for (unsigned int i = 0; i < 4; i++) {
            first->func_000480C0(data_0021AFC0[i]);
            data_00257CE8->func_000C1770(sounds[i]);
        }
        func_001BAA50();
    } else {
        second->weights[0] = values[0] * 2.0f;
        second->keys[0] = seconds[0];
        second->weights[1] = values[1] * 2.0f;
        second->keys[1] = seconds[1];
        second->weights[2] = values[2] * 2.0f;
        second->keys[2] = seconds[2];
        second->weights[3] = values[3] * 2.0f;
        second->keys[3] = seconds[3];
        part->func_14(motions[20], 0.0f);
        second->func_14(motions[21], 0.0f);
    }
}
