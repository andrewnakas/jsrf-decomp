void func_001BA9C0();
void func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
int func_0014C7D0(float first, float second);

// A record of the tables at 0x20D960, 0x20D974 and 0x20D988.
struct Motion_00085F80 {
    float speed;
    float lift;
    float fall;
    int unknown_0c;
    float unknown_10;
};

struct Object_00086060 {
    char unknown_000[0x54];
    float end[3];
    int angle;
    int heading;
    char unknown_068[0x4];
    float direction[3];
    char unknown_078[0xc];
    float speed;
    float lift;
    float spin;
    char unknown_090[0x14];
    Motion_00085F80 *motion;

    void func_000855D0();
    void func_00085640();
    void func_00085FC0();
};

// Handler 2 to 4 of the table at 0x20D9DC: moves the end point along the direction by the speed and up by the lift,
// lets the lift fall by the motion's fall, turns by the spin, faces the direction (func_0014C7D0) and draws
// (func_000855D0, func_00085640) there.
void Object_00086060::func_00085FC0()
{
    end[0] += direction[0] * speed;
    end[2] += direction[2] * speed;
    end[1] += lift;
    lift -= motion->fall;
    angle += (int)(spin * 546.0f);
    heading = func_0014C7D0(direction[0], direction[2]);
    func_001BA9C0();
    func_001BAAA0(end);
    func_000855D0();
    func_00085640();
    func_001BAA50();
}
