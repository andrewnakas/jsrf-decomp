struct Pose_0005F060;

// A motion: its frame count at +0x2 and its keys at +0x4.
struct Motion_0005F060 {
    short unknown_00;
    short frames;
};

// A collision model: what it poses first.
struct Model_000178B0 {
    Pose_0005F060 *pose;
};

void func_0005F060(Pose_0005F060 *pose, Motion_0005F060 *motion, float time);

struct Object_00016200 {
    void func_000178B0(Model_000178B0 *model, Motion_0005F060 *motion, float time);
};

// Poses the model's bones at `time` of the motion (func_0005F060).
void Object_00016200::func_000178B0(Model_000178B0 *model, Motion_0005F060 *motion, float time)
{
    func_0005F060(model->pose, motion, time);
}
