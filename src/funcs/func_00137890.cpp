struct Pair_00137890 {
    int first;
    int second;
};

struct Game {
    void func_000127C0(int index, int value);
    int func_000127E0(int index);
};

extern Game *data_0022FCE0;
extern Pair_00137890 data_0022CB18[];

// Copies the pair of entry (game value 0x1b7) - 1 of the table at data_0022CB18 (entry 0 when out of range)
// into game values 2 and 3, and again into 5 and 6.
void func_00137890()
{
    unsigned int index = data_0022FCE0->func_000127E0(0x1b7) - 1;
    if (index >= 0x6f) {
        index = 0;
    }
    data_0022FCE0->func_000127C0(2, data_0022CB18[index].first);
    data_0022FCE0->func_000127C0(3, data_0022CB18[index].second);
    data_0022FCE0->func_000127C0(5, data_0022CB18[index].first);
    data_0022FCE0->func_000127C0(6, data_0022CB18[index].second);
}
