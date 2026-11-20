/* sym: ?func_00011C90@Object_000F08E0@@UAEXXZ = 0x000F0AC0 */
struct Motion_0005F060;

int func_0005E030(Motion_0005F060 *motion, float *time, float step, int hold);

struct Node {
    virtual ~Node();
    virtual void func_00011C90();
};

// Two motions.
struct Pair_000F0AC0 {
    Motion_0005F060 *first;
    Motion_0005F060 *second;
};

// A direct child of Node (table 0x1CEFE8, constructor func_000F08E0, destructor func_000F0A40).
struct Object_000F08E0 : Node {
    virtual void func_00011C90();

    char unknown_04[0x60];
    Pair_000F0AC0 *motions;
    float firstTime;
    float secondTime;
};

// Overrides slot 1: steps the times at 0x68 and 0x6c of both motions at 0x64 by 0.5 (func_0005E030).
void Object_000F08E0::func_00011C90()
{
    func_0005E030(motions->first, &firstTime, 0.5f, 0);
    func_0005E030(motions->second, &secondTime, 0.5f, 0);
}
