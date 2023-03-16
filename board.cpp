#include "board.h"

void deleteMem(int m, int n, int **&a){
    for (int i = 0; i < m + 2; i++)
        delete[] a[i];
    delete[] a;
}

void generateBoard(int &m, int &n, int **&a){
    cout << "Please input the board size (Less than 100 tiles)" << endl;
    while (true){
        cout << "Number of rows: ";
        cin >> m;
        cout << "Number of columns: ";
        cin >> n;
        if ((m * n) % 2 != 0 || m > 15 || m < 0 || n > 15 || n < 0 || m * n > 100){
            cout << "Invalid size of board, please input again!" << endl;
        }
        else{
            break;
        }
    }

    a = new int*[m + 2];
    for (int i = 0; i < m + 2; i++)
        a[i] = new int[n + 2];
    
    for (int i = 0; i < m + 2; i++)
        for (int j = 0; j < n + 2; j++)
            a[i][j] = 0;

    int count = 0;
    char gen = 'A';
    srand(time(0));
    int maxNum;
    if (m * n <= 20)
        maxNum = 2;
    else
        maxNum = 4;

    while(true){
        if ((int) (gen - 'A' + 1) * maxNum < m * n){
            for (int i = 1; (i <= maxNum) && (count <= m * n); ){
                int x = rand() % m + 1;
                int y = rand() % n + 1;
                if (a[x][y] == 0){
                    i++;
                    a[x][y] = (int) gen;
                    count ++;
                }
            }
            gen++;
        }
        else {
            for (int i = 1; i <= m; i++)
                for (int j = 1; j <= n; j++)
                    if (a[i][j] == 0){
                        a[i][j] = (int) gen;
                        count++;
                    }
        }
        if (count >= m * n){
            break;
        }
    }
    
}

void showBoard(int m, int n, int **a){
    for (int i = 0; i < m + 2; i++){
        for (int j = 0; j < n + 2; j++){
            if (i == 0 || j == 0 || i == m + 1 || j == n + 1)
                cout << "# ";
            else if (a[i][j] != 0)
                cout << (char) a[i][j] << " ";
            else   
                cout << ". ";
        }
        cout << endl;
    }
}

void resetBoard(int m, int n, int **a){
    int cnt[26];
    for (int i = 0; i < 26; i++)
        cnt[i] = 0;
    
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if(a[i][j] != 0){
                cnt[a[i][j] - (int) 'A'] ++;
                a[i][j] = -1;
            }
        }
    }

    srand(time(0));
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if (a[i][j] == -1)
                while (true){
                    char gen = (char) (rand() % 25 + (int)'A'); 
                    if (cnt[(int) (gen - 'A')] > 0){
                        a[i][j] = (int) gen;
                        cnt[(int) (gen - 'A')]--;
                        break;
                    }
                }
        }
    }
}