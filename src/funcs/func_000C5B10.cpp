// The owner at 0x4 of the Object_000CC600 family.
struct Object_000C5B50 {
    char unknown_00[0xe8];
    int (*callback)(int, void *);

    int func_000C5B10(int message, void *data);
};

// Calls the callback at 0xe8 with the message and the data and returns its result; -1 without a callback.
int Object_000C5B50::func_000C5B10(int message, void *data)
{
    if (callback) {
        return callback(message, data);
    }
    return -1;
}
