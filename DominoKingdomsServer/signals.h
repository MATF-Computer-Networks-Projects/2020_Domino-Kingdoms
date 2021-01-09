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
};

#endif // SIGNALS_H
