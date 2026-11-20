// Object 0x1de2.
struct Scene_00124B20 {
    char unknown_0000[0xb44];
    int stage;
    char unknown_0b48[0x26ad];
    unsigned char flag_31f5;
    unsigned char flag_31f6;
    char unknown_31f7[0x10];
    unsigned char items[0x1c];
    unsigned char flag_3223;
    unsigned char flag_3224;
    char unknown_3225[0x38];
    unsigned char flag_325d;
    char unknown_325e[0x1];
    unsigned char flag_325f;
    unsigned char flag_3260;
    char unknown_3261[0x2];
    unsigned char flag_3263;
    unsigned char flag_3264;
    char unknown_3265[0xf];
    unsigned char flag_3274;
    unsigned char flag_3275;
    unsigned char flag_3276;

};

struct Object_00039BE0 {
    int func_0003A2B0(int group, int item);
};

struct Game {
    void *func_000128C0(int id);
};

struct Object_00120420 {
    void func_00124910();
    void func_00124B20();
};

extern Game *data_0022FCE0;
extern Object_00039BE0 data_001EFFB0;

// Sets the unlock flags of object 0x1de2: in stage 5 a fixed set (with func_00124910's marks), otherwise three
// flags and each of the 28 items that data_001EFFB0 reports as 1 for the stage (func_0003A2B0).
void Object_00120420::func_00124B20()
{
    Scene_00124B20 *scene = (Scene_00124B20 *)data_0022FCE0->func_000128C0(0x1de2);
    if (scene->stage == 5) {
        scene->flag_325f = 1;
        scene->flag_3274 = 1;
        scene->flag_3275 = 1;
        func_00124910();
        scene->flag_3260 = 1;
        scene->flag_31f5 = 1;
        scene->flag_325d = 1;
        scene->flag_31f6 = 1;
        scene->flag_3263 = 1;
        scene->flag_3264 = 1;
    } else {
        scene->flag_3223 = 1;
        scene->flag_3276 = 1;
        scene->flag_3224 = 1;
        for (int i = 0; i < 0x1c; i++) {
            if (data_001EFFB0.func_0003A2B0(scene->stage, i) == 1) {
                scene->items[i] = 1;
            }
        }
    }
}
