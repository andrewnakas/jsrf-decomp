/* sym: ?func_00011C80_3@Object_000C7910@@UAEXH@Z = 0x000C7720 */
struct Node {
    virtual ~Node();
    virtual void func_00011C80_3(int argument);

    char unknown_04[0xc];
    float depth;
    char unknown_14[0x30];
};

// The second base (table 0x1CE1B8), two slots.
struct Object_000C60C0 {
    virtual void func_000C6090();
    virtual void func_000C60C0();
};

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Sphere_0005BCE0 {
    Vector3 center;
    float radius;
};

struct Motion_0005F060;

// The model's frame data: a point at 0x54.
struct Frame_000C7720 {
    char unknown_00[0x54];
    Vector3 point;
};

// A model: slot 5 draws it; flags at 0x24, the fade at 0x58, the colour at 0x5c and two words at 0x74 and 0x7c.
struct Object_00047470 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void draw(void *motion, float time);

    char unknown_04[8];
    Frame_000C7720 *frame;
    char unknown_10[0x14];
    unsigned int flags;
    char unknown_28[0x30];
    float fade;
    int colour;
    char unknown_60[0x14];
    int value_74;
    char unknown_78[4];
    int value_7c;
};

struct Object_000C1440 {
};

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 : Object_000C1440 {
    int func_000C1340(Object_00047470 *model, Sphere_0005BCE0 *sphere, float close, float middle, float distant);
};

extern Object_00157F10 *data_00257CE8;

// The camera object at data_00257CE4: its turn at 0xc8.
struct Object_000C1270 {
    char unknown_00[0xc8];
    int angle;
};

extern Object_000C1270 *data_00257CE4;

struct Device_00251D6C {
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
    virtual void __stdcall slot12();
    virtual void __stdcall slot13();
    virtual void __stdcall slot14();
    virtual void __stdcall slot15();
    virtual void __stdcall slot16();
    virtual void __stdcall slot17();
    virtual void __stdcall slot18();
    virtual void __stdcall slot19();
    virtual void __stdcall slot20();
    virtual void __stdcall slot21();
    virtual void __stdcall slot22();
    virtual void __stdcall slot23();
    virtual void __stdcall slot24();
    virtual void __stdcall slot25();
    virtual void __stdcall slot26();
    virtual void __stdcall slot27();
    virtual void __stdcall slot28();
    virtual void __stdcall slot29();
    virtual void __stdcall slot30();
    virtual void __stdcall slot31();
    virtual void __stdcall slot32();
    virtual void __stdcall slot33();
    virtual void __stdcall slot34();
    virtual void __stdcall slot35();
    virtual void __stdcall slot36();
    virtual void __stdcall slot37();
    virtual void __stdcall slot38();
    virtual void __stdcall slot39();
    virtual void __stdcall slot40();
    virtual void __stdcall slot41();
    virtual void __stdcall slot42();
    virtual void __stdcall slot43();
    virtual void __stdcall slot44();
    virtual void __stdcall slot45();
    virtual void __stdcall slot46();
    virtual void __stdcall slot47();
    virtual void __stdcall slot48();
    virtual void __stdcall slot49();
    virtual void __stdcall slot50();
    virtual void __stdcall slot51();
    virtual void __stdcall slot52();
    virtual void __stdcall slot53();
    virtual void __stdcall slot54();
    virtual void __stdcall slot55();
    virtual void __stdcall slot56();
    virtual void __stdcall slot57();
    virtual void __stdcall slot58();
    virtual void __stdcall slot59();
    virtual void __stdcall slot60();
    virtual void __stdcall slot61();
    virtual void __stdcall slot62();
    virtual void __stdcall slot63();
    virtual void __stdcall slot64();
    virtual void __stdcall slot65();
    virtual void __stdcall slot66();
    virtual void __stdcall slot67();
    virtual void __stdcall slot68();
    virtual void __stdcall slot69();
    virtual void __stdcall slot70();
    virtual void __stdcall slot71();
    virtual void __stdcall slot72();
    virtual void __stdcall slot73();
    virtual void __stdcall slot74(int source, int destination);
};

extern Device_00251D6C *data_00251D6C;

// The three distances a model is drawn at.
struct Distances_000C7720 {
    char unknown_00[0x30];
    float close;
    float middle;
    float distant;
};

struct Owner_000C7720 {
    char unknown_00[0x30];
    Distances_000C7720 *distances;
};

struct Motions_000C7720 {
    char unknown_00[0x3c];
    Motion_0005F060 *motion;
};

int func_0005E030(Motion_0005F060 *motion, float *time, float step, int loop);
void func_001BA9C0();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAA50();

// The class whose tables are at 0x1CE1C8 (Node) and 0x1CE1C0 (Object_000C60C0 at +0x44).
struct Object_000C7910 : Node, Object_000C60C0 {
    virtual void func_00011C80_3(int argument);

    Vector3 position;
    int angles[3];
    char unknown_060[0x18];
    Sphere_0005BCE0 bounds;
    int colour;
    char unknown_08c[4];
    unsigned int flags;
    char unknown_094[0x28];
    int mode;
    char unknown_0c0[0xb0];
    int level;
    char unknown_174[4];
    float fade;
    char unknown_17c[8];
    Object_00047470 *model;
    Object_00047470 *shadow;
    Motions_000C7720 *motions;
    char unknown_190[0x18];
    float time;
    char unknown_1ac[0x208];
    Owner_000C7720 *owner;
    char unknown_3b8[4];
    int value_3bc;
    int value_3c0;
};

// Slot 12 (the pass), on the matrix moved to the position: pass 7 puts the model frame's point at 0x54 into the bounds
// at 0x78 and keeps its z as the node's depth; pass 8 turns by the angles (y + 0x8000; x and z with flag 0x2000000 or
// in mode 0x17), picks the level of detail (func_000C1340 against the owner's three distances, kept at 0x170; level 0
// is not drawn; levels 1 and 2 set model flag 0x10), scales the fade by 0x178, steps the motion at 0x18c by 0.5
// (func_0005E030) and draws it; at levels 1 and 2, outside flag 0x2000000 and mode 0x17, the shadow at 0x188 is drawn
// turned by the camera with blend 0x306 / 0 (back to 0x302 / 0x303 after).
void Object_000C7910::func_00011C80_3(int argument)
{
    func_001BAAA0(&position.x);
    switch (argument) {
    case 8: {
        func_001BA9C0();
        func_001BB330(angles[1] + 0x8000);
        if ((flags & 0x2000000) || mode == 0x17) {
            func_001BB2E0(angles[0]);
            func_001BB380(angles[2]);
        }
        level = data_00257CE8->func_000C1340(model, &bounds, owner->distances->close, owner->distances->middle,
                                             owner->distances->distant);
        if (level == 0) {
            func_001BAA50();
            return;
        }
        if (level == 1) {
            model->flags &= ~0x10;
            model->flags |= 0x10;
        } else if (level == 2) {
            model->flags &= ~0x10;
            model->flags |= 0x10;
        } else {
            model->flags &= ~0x10;
        }
        model->fade = fade * model->fade;
        model->colour = colour;
        func_0005E030(motions->motion, &time, 0.5f, 0);
        Object_00047470 *drawn = model;
        if (!(flags & 0x1000)) {
            drawn->value_74 = value_3bc;
            drawn->value_7c = value_3c0;
        }
        drawn->draw(motions->motion, time);
        func_001BAA50();
        if (shadow && (level == 1 || level == 2) && !(flags & 0x2000000) && mode != 0x17) {
            func_001BB330(data_00257CE4->angle);
            data_00251D6C->slot74(0x306, 0);
            shadow->draw(0, 0);
            data_00251D6C->slot74(0x302, 0x303);
        }
        break;
    }
    case 7:
        func_001BAB20(&bounds.center, &model->frame->point);
        depth = bounds.center.z;
        break;
    }
}
