struct Node {
    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
    virtual ~Node();

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

// One of the effect's particles: how long it lives (+0x2c, below 0 for ever), how long it has, and a buffer at +0x78.
struct Particle_000612D0 {
    char unknown_00[0x2c];
    int life;
    int age;
    char unknown_34[0x44];
    void *buffer;
};

// The kinds of effect (0x28 bytes each): flag 4 makes an effect go once it has spawned all its particles and none is
// left.
struct Record_001FA200 {
    int unknown_00;
    unsigned char flags;
    char unknown_05[0x23];
};

extern Record_001FA200 data_001FA200[];

void operator delete(void *pointer);

// The class whose table is at 0x1CB040.
struct Object_00062390 : Node {
    char unknown_044[8];
    int alive;
    char unknown_050[4];
    int frames;
    char unknown_058[0x370];
    int count;
    char unknown_3cc[0x1100];
    int limit;
    int spawned;
    Particle_000612D0 **particles;
    char unknown_14d8[0x48];
    int unknown_1520;
    int kind;
    char unknown_1528[4];
    int ageing;

    void func_000612D0();
};

// With +0x152c set, ages each particle and frees those that have lived their life (with their buffers), one fewer
// alive at +0x4c. Counts a spawn at +0x14d0 while below the limit at +0x14cc (always without one). An effect of a kind
// with flag 4 whose particles are all gone after the last spawn (and +0x1520 clear) takes itself and its children out
// (func_00011BE0, func_00011C20); otherwise it counts a frame at +0x54.
void Object_00062390::func_000612D0()
{
    if (ageing) {
        for (int i = 0; i < count; i++) {
            Particle_000612D0 *particle = particles[i];
            if (particle) {
                particle->age++;
                if (particle->life >= 0 && particle->age >= particle->life) {
                    if (particle->buffer) {
                        operator delete(particle->buffer);
                    }
                    operator delete(particle);
                    particles[i] = 0;
                    alive--;
                    if ((data_001FA200[kind].flags & 4) && alive <= 0 && limit >= 0 && spawned >= limit) {
                        func_00011BE0(this);
                        func_00011C20(child);
                        return;
                    }
                }
            }
        }
    }
    if (limit < 0) {
        spawned++;
    } else if (spawned < limit) {
        spawned++;
    }
    if ((data_001FA200[kind].flags & 4) && !unknown_1520 && alive <= 0 && limit >= 0 && spawned >= limit) {
        func_00011BE0(this);
        func_00011C20(child);
        return;
    }
    frames++;
}
