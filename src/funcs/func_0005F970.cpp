struct Vector3 {
    float x;
    float y;
    float z;
};

void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);

// The 15-bit pseudo-random generator (data_00251F28).
struct Object_00066980 {
    float func_00066950();
};

extern Object_00066980 data_00251F28;

// A description an entry is built from (0x66c bytes).
struct Desc_00060A40 {
    char unknown_000[0x100];
    Vector3 position;
    Vector3 direction;
    char unknown_118[0xfc];
    int interval;
    char unknown_218[0x34];
    int count;
    char unknown_250[0x20];
    float color[4];
    char unknown_280[0x34];
    Vector3 scale;
    char unknown_2c0[0x1c];
    int life;
    char unknown_2e0[0x32c];
    int intervalSpread;
    char unknown_610[4];
    unsigned int lifeSpread;
    char unknown_618[0x54];
};

struct Node {
    virtual ~Node();

    char unknown_04[0x40];
};

// An entry (table 0x1CB040, constructor 0x60CB0, destructor 0x62390; 0x1558 bytes).
struct Object_00062390 : Node {
    char unknown_044[0xc];
    int life;
    char unknown_054[0xc];
    Vector3 position;
    char unknown_06c[0x110];
    Desc_00060A40 desc;
    char unknown_7e8[0xce4];
    int interval;
    char unknown_14d0[0x20];
    float color[4];
    char unknown_1500[0xc];
    Vector3 scale;
    char unknown_1518[0x40];

    void func_0005F970(Desc_00060A40 desc);
};

// Takes a new description (keeping the buffer count), normalises its direction and copies its position; the
// interval (+0x14cc) is the description's plus a random share of its spread around it (at least 1), the life (+0x50)
// likewise (at least 0); then copies the colour (+0x14f0) and the scale (+0x150c).
void Object_00062390::func_0005F970(Desc_00060A40 desc)
{
    int count = this->desc.count;
    this->desc = desc;
    this->desc.count = count;
    func_0014C410(&this->desc.direction, &this->desc.direction);
    position = this->desc.position;
    if (this->desc.interval != -1 && this->desc.intervalSpread) {
        interval = (int)(data_00251F28.func_00066950() * (unsigned int)this->desc.intervalSpread + this->desc.interval -
                         ((unsigned int)this->desc.intervalSpread >> 1));
        if (interval < 1) {
            interval = 1;
        }
    } else {
        interval = this->desc.interval;
    }
    if (this->desc.lifeSpread) {
        const unsigned int &range = this->desc.lifeSpread;
        float spread = (float)range;
        life = (int)(data_00251F28.func_00066950() * spread + this->desc.life - spread * 0.5f);
        if (life < 0) {
            life = 0;
        }
    } else {
        life = this->desc.life;
    }
    for (int i = 0; i < 4; i++) {
        color[i] = this->desc.color[i];
    }
    scale.x = this->desc.scale.x;
    scale.y = this->desc.scale.y;
    scale.z = this->desc.scale.z;
}
