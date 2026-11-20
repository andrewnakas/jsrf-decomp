struct Object_00022990 {
    char unknown_00[0xbc];
    float *depths;
    int *order;
    int sortCount;

    void func_00022840(int first, int low, int high);
};

// Quicksorts the depths at +0xbc from `low` to `high` (with the indices at +0xc0 alongside) round the middle of the
// two ends' depths: nearest first when `first` is 0, farthest first otherwise.
void Object_00022990::func_00022840(int first, int low, int high)
{
    for (;;) {
        float pivot = (depths[low] + depths[high]) * 0.5f;
        int i = low;
        int j = high;
        if (i < j) {
            do {
                if (!first) {
                    while (depths[i] < pivot)
                        i++;
                    while (depths[j] > pivot)
                        j--;
                } else {
                    while (depths[i] > pivot)
                        i++;
                    while (depths[j] < pivot)
                        j--;
                }
                if (i >= j)
                    break;
                float depth = depths[i];
                int index = order[i];
                depths[i] = depths[j];
                order[i] = order[j];
                depths[j] = depth;
                order[j] = index;
                i++;
                j--;
                if (i == j)
                    j++;
            } while (i < j);
        }
        if (low < i - 1)
            func_00022840(first, low, i - 1);
        if (high <= j + 1)
            return;
        low = j + 1;
    }
}
