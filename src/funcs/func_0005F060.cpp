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

void func_0005E880(Bone_0005E880 *bone, Sample_0005F060 *sample);

// What a collision model poses: its bones at +0x28.
struct Pose_0005F060 {
    char unknown_00[0x28];
    Bone_0005E880 *bones;
};

// Poses the bones at `time` of the motion: the frames below and above it (the one above wrapping to 0 past the
// last frame) and the fraction between them go to func_0005E880.
void func_0005F060(Pose_0005F060 *pose, Motion_0005F060 *motion, float time)
{
    Sample_0005F060 sample;
    int first = func_0014C690((float)func_0017C61D(time));
    int second = func_0014C690((float)func_0017C54F(time));
    if (second >= motion->frames) {
        second = 0;
    }
    sample.keys = motion->keys;
    sample.first = first;
    sample.second = second;
    sample.blend = time - (float)first;
    func_0005E880(pose->bones, &sample);
}
