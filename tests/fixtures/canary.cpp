// The toolchain canary. `xbx gate toolcheck` compiles this file with the
// project's flags and compares the object with tests/fixtures/canary.sha256,
// so a judge with another compiler, other flags or a different result from the
// emulation layer is caught before it judges anything. It is not game code.
// It exercises what units rely on: a switch table, floating-point and string
// constants, a class with virtual functions (a vtable and a deleting
// destructor), and a local object with a destructor (exception-handling
// tables and an unwind funclet).

struct Shape {
    virtual float area() const;
    virtual ~Shape();
    float scale;
};

struct Guard {
    Guard();
    ~Guard();
    int held;
};

extern int canary_table(int);
extern void canary_use(const char *, float);

float Shape::area() const
{
    return scale * 2.5f;
}

Shape::~Shape()
{
    canary_use("shape", scale);
}

int canary_switch(int v)
{
    switch (v) {
    case 0:
        return 11;
    case 1:
        return 22;
    case 2:
        return canary_table(v);
    case 3:
        return 44;
    case 4:
        return 55;
    case 5:
        return 66;
    default:
        return -1;
    }
}

int canary_guard(int v)
{
    Guard g;
    canary_use("guard", 1.5f);
    return canary_table(v) + g.held;
}
