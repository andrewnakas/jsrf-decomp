struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The objects with ids 0x115e to 0x1162 (table 0x1D2020): the id of their screen at 0x16b8.
struct Object_00107FE0 {
    char unknown_0000[0x16b8];
    int screenId;
};

// The player: its position at 0xd04 and a direction at 0xde8.
struct Player_001011E0 {
    char unknown_000[0xd04];
    float position[3];
    char unknown_d10[0xd8];
    Vector3 direction;
};

// The screen: its player at 0x24.
struct Screen_001011E0 {
    char unknown_00[0x24];
    Player_001011E0 *player;
};

void func_001BA9C0();
void func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_0014CD50(Vector3 *out, const Vector3 *in);
void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);
float __fastcall func_0014C620(int angle);
float __fastcall func_0014C640(int angle);

// The Node child whose table is at 0x1D1D48 (constructor func_00100F40, which runs the handlers of
// data_0021FF98 by the phase at 0x44).
struct Object_00101180 {
    char unknown_000[0x48];
    int mode;
    char unknown_04c[0x34];
    float angle;
    char unknown_084[0x10];
    Vector3 position;
    char unknown_0a0[0x18];
    Vector3 start;
    Vector3 previous;
    Vector3 direction;
    char unknown_0dc[0x58];
    int ownerId;

    void func_001011E0();
};

// Entry 1 of data_0021FF98: with the player of its owner's screen (else mode 6 at 0x48), takes the player's position
// (0x94, copied to 0xb8 and 0xc4) and the negated direction (NaN parts as 0), turned by the angle at 0x80 in degrees
// (x and z plus its sine and a half, y half its cosine) and normalised (func_0014C410).
void Object_00101180::func_001011E0()
{
    Vector3 origin;
    origin.x = 0.0f;
    origin.y = 0.0f;
    origin.z = 0.0f;
    Object_00107FE0 *owner = (Object_00107FE0 *)data_0022FCE0->func_000128C0(ownerId);
    Player_001011E0 *player = ((Screen_001011E0 *)data_0022FCE0->func_000128C0(owner->screenId))->player;
    if (player) {
        func_001BA9C0();
        func_001BAAA0(player->position);
        func_001BAB20(&position, &origin);
        start = position;
        previous = position;
        func_001BAA50();
        direction = player->direction;
        if (*(unsigned int *)&direction.x == 0xffc00000) {
            direction.x = 0.0f;
        }
        if (*(unsigned int *)&direction.y == 0xffc00000) {
            direction.y = 0.0f;
        }
        if (*(unsigned int *)&direction.z == 0xffc00000) {
            direction.z = 0.0f;
        }
        func_0014CD50(&direction, &direction);
        float s = func_0014C620((int)(angle * 182.04445f)) + 0.5f;
        direction.x += s;
        direction.y = func_0014C640((int)(angle * 182.04445f)) * 0.5f;
        s = func_0014C620((int)(angle * 182.04445f)) + 0.5f;
        direction.z += s;
        func_0014C410(&direction, &direction);
    } else {
        mode = 6;
    }
}
