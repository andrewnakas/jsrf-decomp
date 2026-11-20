/* sym: ??0Object_00070BD0@@QAE@PAUNode@@HIHHHHPBUVector3@@PBH1PBUBlock_00070BD0@@MI@Z = 0x000709A0 */
/* sym: ??1Object_00070BD0@@UAE@XZ = 0x00070BD0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_00070BD0@@UAEXXZ = 0x00070BE0 */
/* sym: ?func_00011C80@Object_00070BD0@@UAEXH@Z = 0x00070C90 */
/* sym: ?func_00011C90_2@Object_00070BD0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_1@Object_00070BD0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90_4@Object_00070BD0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_2@Object_00070BD0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90_6@Object_00070BD0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_3@Object_00070BD0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90_8@Object_00070BD0@@UAEXXZ = 0x000AECC0 */
/* sym: ?func_00011C80_4@Object_00070BD0@@UAEXH@Z = 0x000B3DE0 */
struct Node {
    Node(Node *owner, int id, unsigned int flags);
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
    char unknown_34[0x10];
};

/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Interface_00070C90 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8();
    virtual void __stdcall slot9();
    virtual void __stdcall slot10();
    virtual void __stdcall slot11();
    virtual void __stdcall slot12(int first, int second);
    virtual void __stdcall slot13(int value);
    virtual void __stdcall slot14(int first, void *data);
};

struct Motion_00070BE0 {
    short unknown_00;
    short frames;
};

struct Model_00070C90 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(Motion_00070BE0 *motion, float time);

    Interface_00070C90 *unknown_04;
    char unknown_08[0x1c];
    unsigned int flags;
};


struct Block_00070BD0 {
    int unknown_00[6];
};

void *func_00025700(unsigned int index, int first, int second, int third);

extern Vector3 data_00220A58;

// The class whose table is at 0x1CCA38: overrides slots 1 (70BE0), 3 (70C90), 4 (AECC0), 6 (B3DE0), 7 (AECC0), 9 (B3DE0), 10 (AECC0), 12 (B3DE0), 13 (AECC0), 15 (B3DE0).
struct Object_00070BD0 : Node {
    virtual ~Object_00070BD0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C80_4(int argument);

    Object_00070BD0(Node *owner, int id, unsigned int flags, int type, int bank, int model, int motion,
                    const Vector3 *position, const int *angles, const Vector3 *scale, const Block_00070BD0 *block,
                    float unknown_84, unsigned int unknown_44);

    unsigned int unknown_44;
    int unknown_48;
    Vector3 unknown_4c;
    int unknown_58;
    int unknown_5c;
    Vector3 position;
    int angles[3];
    Vector3 scale;
    float unknown_84;
    int unknown_88;
    int unknown_8c;
    int unknown_90;
    int unknown_94;
    Model_00070C90 *model;
    Motion_00070BE0 *motion;
    float time;
    int unknown_a4;
    int phase;
    int unknown_ac;
    Block_00070BD0 unknown_b0;
    int hasB0;
};

Object_00070BD0::Object_00070BD0(Node *owner, int id, unsigned int flags, int type, int bank, int model, int motion,
                                 const Vector3 *position, const int *angles, const Vector3 *scale,
                                 const Block_00070BD0 *block, float unknown_84, unsigned int unknown_44)
    : Node(owner, id, flags)
{
    this->unknown_44 = unknown_44;
    unknown_88 = type;
    unknown_8c = bank;
    unknown_90 = model;
    unknown_94 = motion;
    if (position) {
        this->position.x = position->x;
        this->position.y = position->y;
        this->position.z = position->z;
    } else {
        this->position.x = 0.0f;
        this->position.y = 0.0f;
        this->position.z = 0.0f;
    }
    if (angles) {
        this->angles[0] = angles[0];
        this->angles[1] = angles[1];
        this->angles[2] = angles[2];
    } else {
        this->angles[0] = 0;
        this->angles[1] = 0;
        this->angles[2] = 0;
    }
    if (scale) {
        this->scale.x = scale->x;
        this->scale.y = scale->y;
        this->scale.z = scale->z;
    } else {
        this->scale.x = 1.0f;
        this->scale.y = 1.0f;
        this->scale.z = 1.0f;
    }
    if (block) {
        hasB0 = 1;
        unknown_b0 = *block;
    } else {
        hasB0 = 0;
    }
    this->unknown_84 = unknown_84;
    this->model = 0;
    this->motion = 0;
    unknown_a4 = 0;
    time = 0.0f;
    unknown_48 = 0;
    unknown_4c.x = data_00220A58.x;
    unknown_4c.y = data_00220A58.y;
    unknown_4c.z = data_00220A58.z;
    phase = 0;
    unknown_ac = 0;
    switch (type) {
    case 1:
        this->model = (Model_00070C90 *)func_00025700(0xd, bank, 0, model);
        if (motion != -1) {
            this->motion = (Motion_00070BE0 *)func_00025700(0xd, unknown_8c, 0, motion);
        }
        break;
    case 2:
        this->model = (Model_00070C90 *)func_00025700(0xf, bank, 0, model);
        if (motion != -1) {
            this->motion = (Motion_00070BE0 *)func_00025700(0xf, unknown_8c, 0, motion);
        }
        break;
    case 3:
        this->model = (Model_00070C90 *)func_00025700(0x12, bank, 2, model);
        break;
    default:
        this->model = (Model_00070C90 *)func_00025700(0xa, 0, 1, model);
        if (motion != -1) {
            this->motion = (Motion_00070BE0 *)func_00025700(0xa, 0, 2, motion);
        }
        break;
    }
    if (this->unknown_44 & 0x80000000) {
        this->model->flags &= ~1;
        this->model->flags |= 1;
    }
}
