struct Object_000C5B10 {
    char unknown_00[0xe8];
    int (*callback)(int, int);

    int func_000C5B10(int first, int second);
};

// Calls the callback at 0xe8 with both arguments and returns its result; -1 without a callback.
int Object_000C5B10::func_000C5B10(int first, int second)
{
    if (callback) {
        return callback(first, second);
    }
    return -1;
}
