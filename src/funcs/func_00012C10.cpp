/* sym: ??0Object_00012AE0@@QAE@PAUNode@@HI@Z = 0x00012AE0 */
struct Node;

// The root node class (constructor 0x12AE0, destructor 0x12BE0; 0x44 bytes).
struct Object_00012AE0 {
    Object_00012AE0(Node *owner, int id, unsigned int flags);

    char unknown_00[0x44];
};

// The game (constructor 0x12210).
struct Game {
    virtual ~Game();

    char unknown_0004[0xc];
    int unknown_0010;
    char unknown_0014[0x87c8];
    Object_00012AE0 *root;

    void func_00012C10();
};

// Called right after the game is made (0x6F9E0): creates the root node (no owner, no id, flags 0) at +0x87dc while
// the word at +0x10 is not negative, else leaves it 0.
void Game::func_00012C10()
{
    root = 0;
    if (unknown_0010 >= 0)
        root = new Object_00012AE0(0, -1, 0);
}
