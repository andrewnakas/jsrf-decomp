struct Game {
    void func_00012A20(int shift);
    void func_000131A0();
};

// Four passes of func_00012A20, one for each byte of the key.
void Game::func_000131A0()
{
    func_00012A20(0);
    func_00012A20(8);
    func_00012A20(16);
    func_00012A20(24);
}
