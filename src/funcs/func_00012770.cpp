void func_001165D0(int value);
void func_00118800();
void *__stdcall func_001455A3(const char *name, unsigned long access, unsigned long share, void *security,
                              unsigned long creation, unsigned long flags, void *pattern);
int __stdcall func_00145585(void *handle);

struct Game {
    char unknown_00[0x24];
    int stopped;

    void func_00012770();
};

// The fatal stop: marks the game stopped, runs func_001165D0(0) and func_00118800, and creates the empty file
// Z:\Media\Cache\JSRF_FATAL.ERR (CreateFile, CloseHandle).
void Game::func_00012770()
{
    stopped = 1;
    func_001165D0(0);
    func_00118800();
    void *file = func_001455A3("Z:\\Media\\Cache\\JSRF_FATAL.ERR", 0x40000000, 0, 0, 2, 0x20000000, 0);
    if (file != (void *)-1) {
        func_00145585(file);
    }
}
