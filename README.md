# Domino Kingdoms

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/57442a879e9b425990f5fda60ba25df2)](https://app.codacy.com/gh/MATF-Computer-Networks-Projects/2020_Domino-Kingdoms?utm_source=github.com&utm_medium=referral&utm_content=MATF-Computer-Networks-Projects/2020_Domino-Kingdoms&utm_campaign=Badge_Grade)

## Board game that you'll like.
### Description
In  _*Domino Kingdoms*_, you are a lord seeking new lands in which to expand your kingdom. You must explore all the lands, including wheat fields, lakes, and mountains, in order to spot the best plots, while competing with other lords to acquire them first.

The game uses tiles with two sections, similar to Dominoes. Each turn, each player will select a new domino to connect to their existing kingdom, making sure at least one of its sides connects to a matching terrain type already in play. The order of who picks first depends on which tile was previously chosen, with better tiles forcing players to pick later in the next round. The game ends when each player has completed a 5x5 grid (or failed to do so), and points are counted based on number of connecting tiles and valuable crown symbols.

taken from https://boardgamegeek.com/boardgame/204583/kingdomino

### Authors
-  [Nikola Jovanović](nikolajovanov998@gmail.com)
-  [Jovan Stamenković](stamenkovicjovan15@gmail.com)
-  [Marija Radović](radovicmarija14@gmail.com)

### Technologies
- ![#f03c15](https://via.placeholder.com/15/f03c15/000000?text=+) Language: C++ 
- ![#c5f015](https://via.placeholder.com/15/c5f015/000000?text=+) Work frame: Qt creator

### How to run the app?

- open terminal
- `git clone https://github.com/MATF-Computer-Networks-Projects/2020_Domino-Kingdoms.git`
- `cd 2020_Domino-Kingdoms`
- `cd DominoKingdomsServer`
- `mkdir build`
- `cd build`
- `qmake ../DominoKingdomsServer.pro`
- `make`
- `cd ../DominoKingdoms`
- `mkdir build`
- `cd build`
- `qmake ../DominoKingdoms.pro`
- `make`
- `./DominoKingdoms`

### Note:
- executable file that is on this repository is for Ubuntu OS.
