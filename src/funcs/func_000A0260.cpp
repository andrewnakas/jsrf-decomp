struct Entry_0020E920 {
    int first;
    int second;
    int unknown_08[4];
};

// The player object: func_0009DC60 calls this with its own `this`, as it calls func_000A0240.
struct Object_000A1C50 {
    int func_000A0260(int index);
};

extern Entry_0020E920 data_0020E920[];

int Object_000A1C50::func_000A0260(int index)
{
    return data_0020E920[index].second;
}
