/* sym: ?func_00011C80@Object_000F08E0@@UAEXH@Z = 0x000F0B00 */
struct Node {
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C90_5();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C90_7();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C90_9();
    virtual void func_00011C80_4(int argument);

    unsigned int flags;
    int id;
    unsigned int mask;
    float depth;
    int sortKey;
    char unknown_18[0xc];
    Node *parent;
    Node *child;
    Node *previous;
    Node *next;
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;
};

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Motion_0005F060;

// A model from func_00025700 (5, 0x15): slot 5 poses it with a motion, slot 6 with another model; a value at 0x5c.
struct Model_000F08E0 {
    virtual void func_00();
    virtual void func_04();
    virtual void func_08();
    virtual void func_0C();
    virtual void func_10();
    virtual void func_14(Motion_0005F060 *motion, float time);
    virtual void func_18(Model_000F08E0 *other);

    char unknown_04[0x58];
    float value;
};

// Two motions.
struct Pair_000F0AC0 {
    Motion_0005F060 *first;
    Motion_0005F060 *second;
};

void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAC50(int *angles, int order);

extern float data_0021A9A4[3];

// A direct child of Node (table 0x1CEFE8, constructor func_000F08E0, destructor func_000F0A40): the position at
// 0x44, the angles at 0x50, six models at 0x5c drawn with the value at 0x60, two motions at 0x64 with their times.
struct Object_000F08E0 : Node {
    virtual ~Object_000F08E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);

    int unknown_40;
    float position[3];
    int angles[3];
    Model_000F08E0 **models;
    float value;
    Pair_000F0AC0 *motions;
    float firstTime;
    float secondTime;
    int firstKey;
    int secondKey;
};

// Overrides slot 3: from the position, message 2 keeps the depth of the origin; 3 turns by the angles and draws the
// models with the value (0 and 1 posed by the motions, 1 moved by data_0021A9A4, 2, 4 and 5 on model 1); 17 and 18
// draw model 3 on model 1.
void Object_000F08E0::func_00011C80(int argument)
{
    func_001BAAA0(position);
    switch (argument) {
    case 3:
        func_001BAC50(angles, 0);
        models[0]->value = value;
        models[0]->func_14(motions->first, firstTime);
        func_001BAAA0(data_0021A9A4);
        models[1]->value = value;
        models[1]->func_14(motions->second, secondTime);
        models[2]->value = value;
        models[2]->func_18(models[1]);
        models[4]->value = value;
        models[4]->func_18(models[1]);
        models[5]->value = value;
        models[5]->func_18(models[1]);
        break;
    case 2: {
        float origin[4];
        func_001BAB20((Vector3 *)origin, 0);
        depth = origin[2];
        break;
    }
    case 17:
    case 18:
        models[3]->func_18(models[1]);
        break;
    }
}
