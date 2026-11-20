struct Entry_0020E920 {
    int first;
    int second;
    int unknown_08[4];
};

struct Object_000A0260 {
    int func_000A0260(int index);
};

extern Entry_0020E920 data_0020E920[];

int Object_000A0260::func_000A0260(int index)
{
    return data_0020E920[index].second;
}
