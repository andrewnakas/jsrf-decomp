struct Vector3 {
    float x;
    float y;
    float z;
};

struct Matrix_001BA950 {
    float m[4][4];
};

struct Node {
    virtual ~Node();

    char unknown_04[0x40];
};

// A player (object 4 and on): its position at +0xca4.
struct Object_000A1C50 {
    char unknown_0000[0xca4];
    Vector3 position;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The 0x28-byte records at 0x20C778: two points.
struct Record_0006D370 {
    Vector3 first;
    Vector3 second;
    char unknown_18[0x10];
};

extern Record_0006D370 data_0020C778[];

int func_0014C7A0(float cosine);
void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);
void __fastcall func_001BA8F0(Matrix_001BA950 *matrix);
void __fastcall func_001BA950(Matrix_001BA950 *matrix);
void func_001BA9C0();
void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB410(Vector3 *out);

struct Object_0006CEE0 : Node {
    char unknown_044[0x5c];
    Vector3 start;
    Vector3 end;
    char unknown_0b8[4];
    int unknown_0bc;
    int record;
    char unknown_0c4[0x14];
    Matrix_001BA950 here;
    Matrix_001BA950 there;

    void func_0006D370(int argument);
};

// Takes the point of the matrix it is given (func_001BB410) and the position of object 0x2c, turns both to face from
// the point to the position in the flat (func_0014C7A0 of the way's -z, the sign by its x) into the matrices at +0xd8
// (at the position) and +0x118 (at the point), copies the two points of record +0xc0 of the table at 0x20C778 into
// +0xac and +0xa0 and clears +0xbc.
void Object_0006CEE0::func_0006D370(int argument)
{
    Vector3 way;
    Vector3 at;
    Vector3 point;
    Object_000A1C50 *player = (Object_000A1C50 *)data_0022FCE0->func_000128C0(0x2c);
    func_001BA9C0();
    func_001BA8F0((Matrix_001BA950 *)argument);
    func_001BB410(&point);
    func_001BAA50();
    at = player->position;
    way.x = at.x - point.x;
    way.y = 0.0f;
    way.z = at.z - point.z;
    func_0014C410(&way, &way);
    int angle = func_0014C7A0(-way.z);
    if (-way.x < 0.0f) {
        angle = -angle;
    }
    func_001BAA00();
    func_001BAAA0(&at.x);
    func_001BB330(angle);
    func_001BA950(&here);
    func_001BAA50();
    func_001BAA00();
    func_001BAAA0(&point.x);
    func_001BB330(angle);
    func_001BA950(&there);
    func_001BAA50();
    end = data_0020C778[record].second;
    start = data_0020C778[record].first;
    unknown_0bc = 0;
}
