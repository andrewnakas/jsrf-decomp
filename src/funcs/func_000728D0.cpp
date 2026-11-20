struct Game {
    void func_00012750();
};

extern Game *data_0022FCE0;

struct Object_000728D0 {
    virtual ~Object_000728D0();
    virtual void func_000728D0();

};

// Slot 1 of the table at 0x1CCB28.
void Object_000728D0::func_000728D0()
{
    data_0022FCE0->func_00012750();
}
