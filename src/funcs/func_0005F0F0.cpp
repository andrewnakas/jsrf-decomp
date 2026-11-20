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

// What func_0005E880 poses the bones with: the keys, the frames on either side of the time and how far between them,
// and (for func_0005E9B0) how the frames are posed.
struct Sample_0005F060 {
    Key_0005F060 *keys;
    int first;
    int second;
    float blend;
    int mode;
};

void func_0005E9B0(void *object, void *frames, Sample_0005F060 *sample);

// Poses an object's frames at `frame` of the motion data in mode `mode`: the frames below and above it (the one
// above wrapping to 0 past the last frame) and the fraction between them go to func_0005E9B0.
void func_0005F0F0(void *object, void *frames, void *data, float frame, int mode)
{
    Motion_0005F060 *motion = (Motion_0005F060 *)data;
    Sample_0005F060 sample;
    int first = func_0014C690((float)func_0017C61D(frame));
    int second = func_0014C690((float)func_0017C54F(frame));
    if (second >= motion->frames) {
        second = 0;
    }
    sample.keys = motion->keys;
    sample.first = first;
    sample.second = second;
    sample.blend = frame - (float)first;
    sample.mode = mode;
    func_0005E9B0(object, frames, &sample);
}
