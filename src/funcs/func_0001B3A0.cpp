struct Vector3 {
    float x;
    float y;
    float z;
};

struct Box_00017CC0 {
    Vector3 min;
    Vector3 max;
};

// A model's points, transformed into one of two buffers in turn, and the box around them.
struct Model_0001B3A0 {
    Box_00017CC0 box;
    unsigned int buffer;
    Vector3 *source;
    Vector3 *points[2];
    unsigned int count;
};

void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

struct Object_00016200 {
    void func_00017CC0(Box_00017CC0 *box, const Vector3 *points, unsigned int count);
    void func_0001B3A0(Model_0001B3A0 *model);
};

// Switches the model to its other buffer, transforms its points into it (func_001BAB20) and recomputes its box.
void Object_00016200::func_0001B3A0(Model_0001B3A0 *model)
{
    if (model) {
        model->buffer = (model->buffer - 1) & 1;
        for (unsigned int i = 0; i < model->count; i++) {
            func_001BAB20(&model->points[model->buffer][i], &model->source[i]);
        }
        func_00017CC0(&model->box, model->points[model->buffer], model->count);
    }
}
