double func_0017C61D(double value);
double func_0017C54F(double value);
unsigned int func_0014C690(float value);

struct Key_0005F060;

// A motion: its frame count at +0x2 and its keys at +0x4.
struct Motion_0005F060 {
    short unknown_00;
    short frames;
    Key_0005F060 *keys;
};

// What func_0005E880 poses the bones with: the keys, the frames on either side of the time and how far between them.
struct Sample_0005F060 {
    Key_0005F060 *keys;
    int first;
    int second;
    float blend;
    int unknown_10;
};

struct Bone_0005E880;

void func_0005DAB0(Bone_0005E880 *bone, Key_0005F060 **keys, int frame, Key_0005F060 **others,
                   Sample_0005F060 *sample);

// Poses the bones at `target` from two motions (both passed as words): frame `frame` of the first and, at `time` (a
// float's bits), the second: the frames below and above the time (each wrapping to 0 past the last frame) and the
// fraction between them; the two key cursors walk the bones in func_0005DAB0. Gives 1.
int func_0005E7B0(void *target, int first, int frame, int second, int time)
{
    Key_0005F060 *keys = ((Motion_0005F060 *)first)->keys;
    Motion_0005F060 *motion = (Motion_0005F060 *)second;
    Key_0005F060 *others = motion->keys;
    Sample_0005F060 sample;
    Sample_0005F060 *s = &sample;
    s->first = func_0014C690((float)func_0017C61D(*(float *)&time));
    s->second = func_0014C690((float)func_0017C54F(*(float *)&time));
    int frames = motion->frames;
    if (s->first >= frames) {
        s->first = 0;
    }
    if (s->second >= frames) {
        s->second = 0;
    }
    float blend = *(float *)&time - (float)(int)func_0014C690((float)func_0017C61D(*(float *)&time));
    s->blend = blend;
    func_0005DAB0((Bone_0005E880 *)target, &keys, frame, &others, &sample);
    return 1;
}
