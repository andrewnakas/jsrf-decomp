void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
int func_0014C7D0(float first, float second);

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000A1C50;

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
    char unknown_090[0x8];
    int target;
    unsigned int flags;
    char unknown_0a0[0x4];
    Motion_00085F80 *motion;

    void func_000855D0();
    void func_00085640();
    void func_00085A60(Object_000A1C50 *player);
    void func_00085EA0();
};

// Handler 1 of the table at 0x20D9DC: with flag 4, follows the object whose id is at +0x98 (func_00085A60) or, once it
// is gone, clears the flag and takes the lift from the speed; without the flag moves as func_00085FC0 does; then
// turns, faces the direction and draws.
void Object_00086060::func_00085EA0()
{
    if (flags & 4) {
        Object_000A1C50 *player = (Object_000A1C50 *)data_0022FCE0->func_000128C0(target);
        if (player) {
            func_00085A60(player);
        } else {
            flags &= ~4;
            lift = speed * direction[1];
        }
    }
    if (!(flags & 4)) {
        end[0] += direction[0] * speed;
        end[2] += direction[2] * speed;
        end[1] += lift;
        lift -= motion->fall;
    }
    angle += (int)(spin * 546.0f);
    heading = func_0014C7D0(direction[0], direction[2]);
    func_001BA9C0();
    func_001BAAA0(end);
    func_000855D0();
    func_00085640();
    func_001BAA50();
}
