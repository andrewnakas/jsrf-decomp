extern "C" char *strcpy(char *destination, const char *source);
extern "C" char *strcat(char *destination, const char *source);

extern char *data_001EE730[];
extern char data_002313A8[];

// The name at `index` of the table at 0x1EE730 with ".bin" (`binary` set) or ".dat" added, in the buffer at
// 0x2313A8.
char *func_00036BB0(int index, int binary)
{
    strcpy(data_002313A8, data_001EE730[index]);
    if (!binary)
        strcat(data_002313A8, ".dat");
    else
        strcat(data_002313A8, ".bin");
    return data_002313A8;
}
