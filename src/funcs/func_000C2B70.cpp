// One of the four entries at 0x48 of data_00257CEC: an angle at 4.
struct Entry_000C36F0 {
    int unknown_00;
    int angle;
    int unknown_08;
};

// The motion ids at 0xc8 of data_00257CEC: a left and a right one for each turn (from 4 on).
struct Motions_000C2B70 {
    int ids[18];
};

// The object at data_00257CEC: an entry each for four points at 0x48 and the motion ids at 0xc8.
struct Object_000C3BE0 {
    char unknown_00[0x48];
    Entry_000C36F0 entries[4];
    char unknown_78[0x50];
    Motions_000C2B70 *motions;
};

extern Object_000C3BE0 *data_00257CEC;

struct Data_000C2700;

// The base whose table is at 0x1CDCF8 (constructor func_000C2420, destructor func_000C2470); slot 9 is the
// destructor.
struct Object_000C2420 {
    Object_000C2420(Data_000C2700 *data);
    virtual void func_000C2630();
    virtual void func_000C2700();
    virtual void func_000C3800();
    virtual void func_000C30C0();
    virtual void func_000C3100();
    virtual void func_000C3140();
    virtual void func_000C31B0();
    virtual void func_000C3350();
    virtual void func_000C33C0();
    virtual ~Object_000C2420();
    virtual void func_000C2480();
    virtual void func_000C36F0();
    virtual void func_000C2FE0();
    virtual void func_000C2500();
    virtual void func_000C2560();
    virtual void func_000C25D0();
    virtual int func_000C2AA0();

    char unknown_04[0x1c];
    int target;
    char unknown_24[0x1c];
    int heading;
    char unknown_44[0x18];
    float side;
    unsigned int area;
    unsigned int kind;
    int point;
    char unknown_6c[0x10];
    int motion;

    void func_000C2B70(int angle);
};

// Turns to face away from the angle (plus 0x8000), a quarter turn to the right while the side at 0x5c is positive
// and to the left otherwise, and picks the motion of that side: areas 0x2c..0x2f and 0x28..0x2b have their own,
// otherwise by the kind (0, 1, 4, 3, 2). Kind 3 faces the point's entry instead, turned by 0x1555.
void Object_000C2420::func_000C2B70(int angle)
{
    int facing = angle + 0x8000;
    if (side > 0.0f) {
        target = facing + 0x4000;
        if (area == 0x2c || area == 0x2d || area == 0x2e || area == 0x2f) {
            motion = data_00257CEC->motions->ids[17];
        } else if (area == 0x28 || area == 0x29 || area == 0x2a || area == 0x2b) {
            motion = data_00257CEC->motions->ids[15];
        } else if (kind == 0) {
            motion = data_00257CEC->motions->ids[5];
        } else if (kind == 1) {
            motion = data_00257CEC->motions->ids[7];
        } else if (kind == 4) {
            motion = data_00257CEC->motions->ids[9];
        } else if (kind == 3) {
            facing = data_00257CEC->entries[point].angle + 0x8000;
            target = data_00257CEC->entries[point].angle - 0x1555;
            motion = data_00257CEC->motions->ids[10];
        } else if (kind == 2) {
            motion = data_00257CEC->motions->ids[13];
        }
    } else {
        target = facing - 0x4000;
        if (area == 0x2c || area == 0x2d || area == 0x2e || area == 0x2f) {
            motion = data_00257CEC->motions->ids[16];
        } else if (area == 0x28 || area == 0x29 || area == 0x2a || area == 0x2b) {
            motion = data_00257CEC->motions->ids[14];
        } else if (kind == 0) {
            motion = data_00257CEC->motions->ids[4];
        } else if (kind == 1) {
            motion = data_00257CEC->motions->ids[6];
        } else if (kind == 4) {
            motion = data_00257CEC->motions->ids[8];
        } else if (kind == 3) {
            facing = data_00257CEC->entries[point].angle + 0x8000;
            target = data_00257CEC->entries[point].angle + 0x1555;
            motion = data_00257CEC->motions->ids[10];
        } else if (kind == 2) {
            motion = data_00257CEC->motions->ids[12];
        }
    }
    heading = facing;
}
