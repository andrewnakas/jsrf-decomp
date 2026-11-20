struct Object_00011CA0 {
    char unknown_00[0x44];
    int unknown_44[3];
    int unknown_50[3];
    int unknown_5c[3];
    int unknown_68[3];
    int unknown_74;
    int unknown_78;
    int unknown_7c;
    int unknown_80;

    void func_00011CA0();
};

void Object_00011CA0::func_00011CA0()
{
    unknown_50[0] = unknown_44[0];
    unknown_50[1] = unknown_44[1];
    unknown_50[2] = unknown_44[2];
    unknown_68[0] = unknown_5c[0];
    unknown_68[1] = unknown_5c[1];
    unknown_68[2] = unknown_5c[2];
    unknown_74 = unknown_78;
    unknown_7c = unknown_80;
}
