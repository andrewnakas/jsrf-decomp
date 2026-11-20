/* sym: ?func_00011C90@Object_00117510@@UAEXXZ = 0x001178B0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

struct Mark_00117560 {
    Vector3 position;
    float inner;
    float outer;
    int track;
};

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();
    virtual void func_00011C90();

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

// The class whose table is at 0x1D7778 (constructor 0x1174D0): overrides slot 1 of Node.
struct Object_00117510 : Node {
    virtual void func_00011C90();

    char unknown_44[4];
    Mark_00117560 marks[30];
    float distances[30];
    unsigned int order[30];
    unsigned int count;
    int track;

    int func_00117820();
};

extern Game *data_0022FCE0;

void func_00116930(float volume);
void func_001168F0();
void func_001171F0(int sound);

// Slot 1: while object 0x4c exists and there are marks, and none of the objects 0x11e6-0x1207 exists, plays the
// track of the nearest mark (func_00117820 sorts them) at a volume falling from 0.8 at its inner distance to 0 at
// its outer one (func_00116930, func_001171F0), keeping the track at +0x40c; out of range, or when one of those
// objects exists, stops the music (func_001168F0) and sets +0x40c to -1.
void Object_00117510::func_00011C90()
{
    if (data_0022FCE0->func_000128C0(0x4c) && count) {
        unsigned int id;
        for (id = 0x11e6; id <= 0x11f6; id++) {
            if (data_0022FCE0->func_000128C0(id)) {
                goto stop;
            }
        }
        for (id = 0x11f7; id <= 0x1207; id++) {
            if (data_0022FCE0->func_000128C0(id)) {
                goto stop;
            }
        }
        if (!func_00117820()) {
            return;
        }
        {
            float distance = distances[0];
            Mark_00117560 *mark = &marks[order[0]];
            float volume;
            if (distance <= mark->inner) {
                volume = 1.0f;
            } else if (distance >= mark->outer) {
                volume = 0.0f;
            } else {
                float t = 1.0f - (mark->outer - distance) / (mark->outer - mark->inner);
                volume = 1.0f - t * t;
            }
            volume *= 0.8f;
            func_00116930(volume);
            if (volume > 0.0f) {
                func_001171F0(mark->track);
                track = mark->track;
                return;
            }
        }
    stop:
        func_001168F0();
        track = -1;
    }
}
