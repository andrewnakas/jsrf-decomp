struct Object_00062390 {
    char unknown_0000[0x7c];
    float *depths;
    int *order;

    void func_00060470(int descending, int low, int high);
};

// Quicksorts the depths at +0x7c between `low` and `high` (both included), nearest first or, when `descending`,
// farthest first, around the mean of the two ends, carrying the indices at +0x80 along.
void Object_00062390::func_00060470(int descending, int low, int high)
{
    float pivot = (depths[low] + depths[high]) * 0.5f;
    int i = low;
    int j = high;
    while (i < j) {
        if (!descending) {
            while (depths[i] < pivot) {
                i++;
            }
            while (depths[j] > pivot) {
                j--;
            }
        } else {
            while (depths[i] > pivot) {
                i++;
            }
            while (depths[j] < pivot) {
                j--;
            }
        }
        if (i >= j) {
            break;
        }
        float depth = depths[i];
        int index = order[i];
        depths[i] = depths[j];
        order[i] = order[j];
        depths[j] = depth;
        order[j] = index;
        i++;
        j--;
        if (i == j) {
            j++;
        }
    }
    if (low < i - 1) {
        func_00060470(descending, low, i - 1);
    }
    if (high > j + 1) {
        func_00060470(descending, j + 1, high);
    }
}
