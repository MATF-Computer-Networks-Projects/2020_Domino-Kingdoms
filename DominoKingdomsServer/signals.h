#ifndef SIGNALS_H
#define SIGNALS_H

class Signals{
public:
    const static int send_name = 0;
    const static int request_player1 = 1;
    const static int request_player2 = 2;
    const static int request_player3 = 3;
    const static int send_update = 4;
    const static int sending_table = 5;
    const static int player_not_found = 6;
    const static int send_reserve = 7;
    const static int request_cards = 8;
    const static int game_ended = 9;
    const static int sending_cards = 10;
    const static int change_next_task = 11;
    const static int sending_id = 12;
    const static int send_reserve_back = 13;
    const static int request_color = 14;
    const static int send_color = 15;
    const static int request_delete = 16;
    const static int send_delete = 17;
};

#endif // SIGNALS_H
