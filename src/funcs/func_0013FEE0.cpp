struct Context_0013FEE0 {
    char unknown_00[0xc];
    int value;
    char unknown_10[0xc];
    int (*callback)(void *argument, int code);
    void *argument;
};

int func_0013FEE0(Context_0013FEE0 *context, int mode)
{
    if (mode == 1) {
        return context->value;
    }
    if (mode != 0 && context->callback) {
        context->callback(context->argument, -3);
    }
    return 0;
}
