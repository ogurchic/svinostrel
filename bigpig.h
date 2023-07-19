//pig.h
#include "pig.h"
#include "renderer.h"
#include <cmath> 
#include <math.h>


class BigPig : public Pig {
public:

    double bigX, bigY;

    BigPig(int startX, int startY, int hitX, int hitY, int health) : Pig(startX, startY, hitX, hitY, health) {
        bigX = x;
        bigY = y;
    }

    void draw() {
        drawString(bigX, bigY,     "     /\"\\......... / \"\\", frontBuffer, FOREGROUND_GREEN);
        drawString(bigX, bigY + 1, "     \\..:-\"\"\" - :….\\./ ", frontBuffer, FOREGROUND_GREEN);
        drawString(bigX, bigY + 2, "      ;'….//`\\..../", frontBuffer, FOREGROUND_GREEN);
        drawString(bigX, bigY + 3, "      /__.....|..\"('.",  frontBuffer, FOREGROUND_GREEN);
        drawString(bigX, bigY + 4, "     |.O./O)\\..../\\..`)", frontBuffer, FOREGROUND_GREEN);
        drawString(bigX, bigY + 5, "   _/-.....`......`\"`.. | `-.", frontBuffer, FOREGROUND_GREEN);
        drawString(bigX, bigY + 6, " .-=;.`................../.`-.", frontBuffer, FOREGROUND_GREEN);
        drawString(bigX, bigY + 7, "/o.o.\\...,_,...................'.", frontBuffer, FOREGROUND_GREEN);
        drawString(bigX, bigY + 8, "L._._;_.-'......................`'-.", frontBuffer, FOREGROUND_GREEN);
        drawString(bigX, bigY + 9, "  `'-.`.............'.............`'-.", frontBuffer, FOREGROUND_GREEN);
        drawString(bigX, bigY + 10, "      `..........'...................`-.", frontBuffer, FOREGROUND_GREEN);
        drawString(bigX, bigY + 11, "        '-._..-'........................'", frontBuffer, FOREGROUND_GREEN);
        drawString(bigX, bigY + 12, "           \\...........................`/", frontBuffer, FOREGROUND_GREEN);
        drawString(bigX, bigY + 13, "           /.............................\\", frontBuffer, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
        drawString(bigX, bigY + 14, "           \\-----------------------------/", frontBuffer, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
        drawString(bigX, bigY + 15, "             ############################", frontBuffer, FOREGROUND_RED | FOREGROUND_INTENSITY);
    }

    void moving() {
        bigX -= 1;
    }

    void health_down() {
        health_lvl--;
    }

};