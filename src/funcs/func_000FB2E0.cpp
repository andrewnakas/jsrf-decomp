extern int data_0021FD58[];

// Looks an index up in an eight-entry table; 11 for anything outside it.
int func_000FB2E0(unsigned int index)
{
    if (index < 8) {
        return data_0021FD58[index];
    }
    return 11;
}
