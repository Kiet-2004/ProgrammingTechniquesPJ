#include "asciiArt.h"

void deleteArt(int m, int n, char **&display){
    for (int i = 0; i < 5 * (m + 2); i++)
        delete[] display[i];
    delete[] display;
}

void generateArt(int m, int n, char **&display){
    display = new char*[5 * (m + 2)];
    for (int i = 0; i < 5 * (m + 2); i++)
        display[i] = new char[7 * (n + 2)];

    for (int i = 0; i < 5 * (m + 2); i++){
        for (int j = 0; j < 7 * (n + 2); j++){
            display[i][j] = '.';
        }
    }
}

void drawLine(int line[][2])
{
    for (int k = 0; k < 3; k++)
    {
        if(line[k+1][0] == 0 && line[k+1][1] == 0)
            break;
        int x1 = line[k][0], x2 = line[k+1][0], y1 = line[k][1], y2 = line[k+1][1];
        if (x1 == x2)
        {
            if (y1 > y2)
                swap (y1, y2);
            for (int i = y1 * 7 + 3; i <= y2 * 7 + 3; i++)
                {
                    cursor(i, x1 * 5 + 3);
                    cout << '@';
                }
        }
        else
        {
            if (x1 > x2)
                swap (x1, x2);
            for (int i = x1 * 5 + 3; i <= x2 * 5 + 3; i++)
                {
                    cursor(y1 * 7 + 3, i);
                    cout << '@';
                }
        }
    }
}
