struct Motion_0005F060 {
    short unknown_00;
    short frames;
};

struct Model_000178B0 {
    Motion_0005F060 *motion;
};

void func_0005F060(Motion_0005F060 *motion, float first, float second);

struct Object_00016200 {
    void func_000178B0(Model_000178B0 *model, float first, float second);
};

// Passes the model's motion and the two values on to func_0005F060.
void Object_00016200::func_000178B0(Model_000178B0 *model, float first, float second)
{
    func_0005F060(model->motion, first, second);
}
