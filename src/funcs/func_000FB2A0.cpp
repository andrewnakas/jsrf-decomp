struct Entry_0021FBDC {
    int first;
    int second;
    int third;
    int fourth;
};

extern Entry_0021FBDC data_0021FBDC[];

// The second field of entry index of the 24-entry table data_0021FBDC; 24 for an index past the end.
int func_000FB2A0(unsigned int index)
{
    if (index < 24) {
        return data_0021FBDC[index].second;
    }
    return 24;
}
