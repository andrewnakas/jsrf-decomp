/* sym: ??1Game@@UAE@XZ = 0x00012390 */
struct Node {
    virtual ~Node();
};

struct Context_00251D7C {
    virtual ~Context_00251D7C();
};

extern Context_00251D7C *data_00251D7C;

struct Object_0006E130 {
    void func_0006E7B0(int id);
};

extern Object_0006E130 data_00252790;

// The game (constructor 0x12210, table 0x1C4458): the root node at +0x87dc and two ids at +0x8838 / +0x883c.
struct Game {
    virtual ~Game();

    char unknown_0004[0x87d8];
    Node *root;
    char unknown_87e0[0x58];
    int unknown_8838;
    int unknown_883c;
};

// Releases the two ids (func_0006E7B0 of 0x252790), deletes the root node and the object at 0x251D7C.
Game::~Game()
{
    data_00252790.func_0006E7B0(unknown_8838);
    data_00252790.func_0006E7B0(unknown_883c);
    delete root;
    delete data_00251D7C;
}
