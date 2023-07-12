#pragma once

namespace ariel{
    class Stats{

        public:
            //stats
            double WinRate, drawRate, numberOfGamesPlayed;
            int cardsWon, draws, turns, beatAce, GamesEndedinDraw, gamesWon, gamesDrawn;
            //constructor
            Stats();

    };
}