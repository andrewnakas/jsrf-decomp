struct Game {
    void *func_000128C0(int id);
};

struct Object_00066980 {
    float func_00066950();
};

// A track that has a second version (8 bytes): the version func_00117350 plays when +0x108 of the player is set.
struct Pair_00117350 {
    int track;
    int other;
};

// A group of tracks to pick from at random (0x2c bytes).
struct Group_00117350 {
    unsigned int count;
    int tracks[10];
};

// Object 5, the sound player.
struct Object_00116A10 {
    char unknown_000[0x78];
    int current;
    int states[4];
    float volumes[4];
    int track;
    char unknown_0a0[4];
    int value_a4;
    char unknown_0a8[0x14];
    int value_bc;
    char unknown_0c0[0x30];
    int ramps[4];
    int value_100;
    int forced;
    int other;
    int changed;

    void func_00116170(int next);
    void func_00116290(int channel, char value);
    void func_00116AB0(int channel, int track);
};

extern Game *data_0022FCE0;
extern Object_00066980 data_00251F28;
extern const Pair_00117350 data_001D37B0[];
extern const Group_00117350 data_001D37F0[];

void func_00116F50(int track, int fade_in, int fade_out);
void func_001166E0(int track);
void func_00117060(int track, int mode);

// Plays `track` on the sound player (object 5): tracks 10-19 go to func_00117060; from 100 the track comes from
// data_001D37B0 (the other version when +0x108 is set and it exists), 80-99 pick one of data_001D37F0's group at
// random; nothing happens when it is already playing unless +0x104 forces it. With a track playing and `mode`
// above 1 it fades over (func_001166E0, func_00116F50); otherwise it starts on the current channel at full volume.
void func_00117350(int track, int mode)
{
    Object_00116A10 *player = (Object_00116A10 *)data_0022FCE0->func_000128C0(5);
    if (!player) {
        return;
    }
    if (track >= 10 && track <= 19) {
        func_00117060(track, mode);
        return;
    }
    if (track < 100) {
        player->forced = 0;
    }
    if (!player->forced && track == player->track) {
        return;
    }
    player->func_00116170(track);
    if (track >= 100) {
        int index = track - 100;
        if (player->other) {
            track = data_001D37B0[index].other;
        } else {
            track = data_001D37B0[index].track;
        }
        if (track < 0) {
            track = data_001D37B0[index].track;
        }
        if (!player->forced && track == player->track) {
            return;
        }
        player->changed = 1;
        player->forced = 0;
    } else if (track >= 80) {
        int group = track - 80;
        unsigned int count = data_001D37F0[group].count;
        int pick = (int)(data_00251F28.func_00066950() * count);
        if (pick >= (int)count) {
            pick = count;
        }
        track = data_001D37F0[group].tracks[pick];
    }
    player->value_bc = 1;
    if (player->track != -1 && (unsigned int)mode > 1) {
        func_001166E0(1);
        func_00116F50(track, 0, 1);
        player->value_a4 = 1;
        return;
    }
    player->track = track;
    player->states[player->current] = 1;
    player->volumes[player->current] = 1.0f;
    player->ramps[player->current] = 0;
    player->func_00116290(player->current, 1);
    player->func_00116AB0(player->current, track);
}
