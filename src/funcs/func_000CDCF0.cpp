/* sym: ?func_00011C80@Object_000CE9D0@@UAEXH@Z = 0x000CDCF0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

// A model: slot 5 draws it; its colour word at 0x5c and two more at 0x74 and 0x7c.
struct Object_00047470 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void draw(int first, int second);

    char unknown_04[0x58];
    int colour;
    char unknown_60[0x14];
    int value_74;
    char unknown_78[4];
    int value_7c;

    void func_000480C0(unsigned int flags);
};

// What draws a model: slot 6 takes it; its colour word at 0x5c.
struct Renderer_000CDCF0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void draw(Object_00047470 *model);

    char unknown_04[0x58];
    int colour;
};

// The models of a behaviour: three bodies, then the renderers at 0xc and 0x20-0x2c.
struct Models_000CDCF0 {
    Object_00047470 *bodies[3];
    Renderer_000CDCF0 *renderer;
    char unknown_10[0x10];
    Renderer_000CDCF0 *outer[2];
    Renderer_000CDCF0 *inner[2];
};

struct Object_000C1440 {
};

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 : Object_000C1440 {
    void func_000C1690(int key);
    void func_000C1730(int *handle);
    void func_000C1770(int key);
};

extern Object_00157F10 *data_00257CE8;

// The object a behaviour serves: its position at 0x44 and its turn at 0x54.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    int unknown_50;
    int angle;
};

struct Object_00015D50 {
    virtual ~Object_00015D50();

    void func_00015F90();
};

void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BB330(int angle);
void func_001BB2B0(float scale);
void func_001BA9C0();
void __fastcall func_001BAA50();

// The base with a pure slot 0 (table 0x1CE304).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual ~Object_000CC600() {}
};

// The behaviour func_000CE9D0 builds (0x140 bytes, table 0x1CE3A0); 0x4 holds the object it serves.
struct Object_000CE9D0 : Object_000CC600 {
    virtual void func_00011C80(int argument);

    Object_000C5B50 *owner;
    int state;
    char unknown_0c[0x20];
    int colour;
    char unknown_30[0x14];
    unsigned int kind;
    char unknown_48[0x10];
    Models_000CDCF0 *models;
    Renderer_000CDCF0 *shadow;
    Object_00015D50 *first;
    Object_00015D50 *second;
    char unknown_68[0x10];
    int frame;
    char unknown_7c[0x94];
    int effect;
    int value_114;
    int value_118;
    int sound;
    int fresh;
};

// Slot 2 (the pass), on a matrix moved to the owner's position, turned by its angle plus 0x8000 and scaled by 2: pass 0
// starts the sound at 0x11c (func_000C1730 the first time), draws the body for the kind at 0x44 (the third one with
// 0x114 and 0x118 at 0x74 and 0x7c) at frame 0x78 in the colour at 0x2c, then the shadow and two renderers (0x20/0x24,
// or 0x28/0x2c in state 6) with it; from kind 2 on it also runs func_000480C0(8) and effect 0x110 (func_000C1770).
// Then pops the matrix, runs func_00015F90 of 0x60 and 0x64 and pushes a new one. Passes 0x11 and 0x12 only hand the
// body to the renderer at 0xc.
void Object_000CE9D0::func_00011C80(int argument)
{
    func_001BAAA0(&owner->position.x);
    func_001BB330(owner->angle + 0x8000);
    func_001BB2B0(2.0f);
    if (argument != 0) {
        if ((unsigned int)argument > 0x10 && (unsigned int)argument <= 0x12) {
            Object_00047470 *body;
            if (kind == 0) {
                body = models->bodies[0];
            } else if (kind == 1) {
                body = models->bodies[1];
            } else {
                body = models->bodies[2];
            }
            models->renderer->draw(body);
        }
        return;
    }
    if (fresh) {
        data_00257CE8->func_000C1730(&sound);
        fresh = 0;
    }
    data_00257CE8->func_000C1690(sound);
    Object_00047470 *body;
    if (kind == 0) {
        body = models->bodies[0];
    } else if (kind == 1) {
        body = models->bodies[1];
    } else {
        body = models->bodies[2];
        body->value_74 = value_114;
        body->value_7c = value_118;
    }
    body->colour = colour;
    body->draw(frame, 0);
    shadow->colour = colour;
    shadow->draw(body);
    if (state != 6) {
        models->outer[0]->colour = colour;
        models->outer[1]->colour = colour;
        models->outer[0]->draw(body);
        models->outer[1]->draw(body);
    } else {
        models->inner[0]->colour = colour;
        models->inner[1]->colour = colour;
        models->inner[0]->draw(body);
        models->inner[1]->draw(body);
    }
    if (kind >= 2) {
        body->func_000480C0(8);
        data_00257CE8->func_000C1770(effect);
    }
    func_001BAA50();
    first->func_00015F90();
    second->func_00015F90();
    func_001BA9C0();
}
