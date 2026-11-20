/* sym: ??1Object_000C1270@@QAE@XZ = 0x000C0EB0 */
// The object in data_00257CE4: 29 buffers at 4 and one at 0x78.
struct Object_000C1270 {
    ~Object_000C1270();

    int unknown_00;
    char *buffers[29];
    char *buffer;
};

// Frees the 29 buffers at 4 (clearing each) and the one at 0x78. func_000C0AC0 runs it before freeing the
// object in data_00257CE4.
Object_000C1270::~Object_000C1270()
{
    for (int i = 0; i < 29; i++) {
        if (buffers[i]) {
            delete[] buffers[i];
            buffers[i] = 0;
        }
    }
    delete[] buffer;
}
