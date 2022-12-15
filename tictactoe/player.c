#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef char input;
int gamestate = 0;

char board[9];

char player1Move(char in)
{
    switch (in)
    {
    case '1':
        board[0] = 'X';
        break;
    case '2':
        board[1] = 'X';
        break;
    case '3':
        board[2] = 'X';
        break;
    case '4':
        board[3] = 'X';
        break;
    case '5':
        board[4] = 'X';
        break;
    case '6':
        board[5] = 'X';
        break;
    case '7':
        board[6] = 'X';
        break;
    case '8':
        board[7] = 'X';
        break;
    case '9':
        board[8] = 'X';
        break;
    }

    return '1';
}

char player2Move(char in)
{
    switch (in)
    {
    case '1':
        board[0] = 'O';
        break;
    case '2':
        board[1] = 'O';
        break;
    case '3':
        board[2] = 'O';
        break;
    case '4':
        board[3] = 'O';
        break;
    case '5':
        board[4] = 'O';
        break;
    case '6':
        board[5] = 'O';
        break;
    case '7':
        board[6] = 'O';
        break;
    case '8':
        board[7] = 'O';
        break;
    case '9':
        board[8] = 'O';
        break;
    }

    return '1';
}

char moveCPU()
{
    int valid = 0;
    int move;
    char pass;

    do
    {
        move = rand() % 9;
        pass = move + '0';
        if (move == 1 && (board[0] != 'X' && board[0] != 'O'))
        {
            valid = 1;
            player2Move(pass);
        }
        else if (move == 2 && (board[1] != 'X' && board[1] != 'O'))
        {
            valid = 1;
            player2Move(pass);
        }
        else if (move == 3 && (board[2] != 'X' && board[2] != 'O'))
        {
            valid = 1;
            player2Move(pass);
        }
        else if (move == 4 && (board[3] != 'X' && board[3] != 'O'))
        {
            valid = 1;
            player2Move(pass);
        }
        else if (move == 5 && (board[4] != 'X' && board[4] != 'O'))
        {
            valid = 1;
            player2Move(pass);
        }
        else if (move == 6 && (board[5] != 'X' && board[5] != 'O'))
        {
            valid = 1;
            player2Move(pass);
        }
        else if (move == 7 && (board[6] != 'X' && board[6] != 'O'))
        {
            valid = 1;
            player2Move(pass);
        }
        else if (move == 8 && (board[7] != 'X' && board[7] != 'O'))
        {
            valid = 1;
            player2Move(pass);
        }
        else if (move == 9 && (board[8] != 'X' && board[8] != 'O'))
        {
            valid = 1;
            player2Move(pass);
        }

    } while (valid == 0);

    return pass;
}

void checkWin()
{
    if (board[0] == 'X' && board[1] == 'X' && board[2] == 'X')
    {
        gamestate = 1;
    }
    else if (board[3] == 'X' && board[4] == 'X' && board[5] == 'X')
    {
        gamestate = 1;
    }
    else if (board[6] == 'X' && board[7] == 'X' && board[8] == 'X')
    {
        gamestate = 1;
    }
    else if (board[0] == 'X' && board[3] == 'X' && board[6] == 'X')
    {
        gamestate = 1;
    }
    else if (board[1] == 'X' && board[4] == 'X' && board[7] == 'X')
    {
        gamestate = 1;
    }
    else if (board[2] == 'X' && board[5] == 'X' && board[8] == 'X')
    {
        gamestate = 1;
    }
    else if (board[3] == 'X' && board[4] == 'X' && board[5] == 'X')
    {
        gamestate = 1;
    }
    else if (board[0] == 'X' && board[3] == 'X' && board[8] == 'X')
    {
        gamestate = 1;
    }
    else if (board[2] == 'X' && board[3] == 'X' && board[6] == 'X')
    {
        gamestate = 1;
    }

    // check if player 2 wins
    if (board[0] == 'O' && board[1] == 'O' && board[2] == 'O')
    {
        gamestate = 2;
    }
    else if (board[3] == 'O' && board[4] == 'O' && board[5] == 'O')
    {
        gamestate = 2;
    }
    else if (board[6] == 'O' && board[7] == 'O' && board[8] == 'O')
    {
        gamestate = 2;
    }
    else if (board[0] == 'O' && board[3] == 'O' && board[6] == 'O')
    {
        gamestate = 2;
    }
    else if (board[1] == 'O' && board[4] == 'O' && board[7] == 'O')
    {
        gamestate = 2;
    }
    else if (board[2] == 'O' && board[5] == 'O' && board[8] == 'O')
    {
        gamestate = 2;
    }
    else if (board[3] == 'O' && board[4] == 'O' && board[5] == 'O')
    {
        gamestate = 2;
    }
    else if (board[0] == 'O' && board[3] == 'O' && board[8] == 'O')
    {
        gamestate = 2;
    }
    else if (board[2] == 'O' && board[3] == 'O' && board[6] == 'O')
    {
        gamestate = 2;
    }

    if (board[0] != '1' && board[1] != '2' && board[2] != '3' && board[3] != '4' && board[4] != '5' && board[5] != '6' && board[6] != '7' && board[7] != '8' && board[8] != '9')
    {
        gamestate = 3;
    }
}

int main(input in)
{
    char cpu;
    time_t t;
    srand((unsigned)time(&t));
    char divider[] = "+-----+\n";
    FILE *myFile;
    myFile = fopen("board.txt", "r");
    int i;
    for (i = 0; i < 16; i++)
    {
        fscanf(myFile, "%1f", &board[i]);
    }

    player1Move(in);

    while (gamestate == 0)
    {
        printf("Board State:\n");
        printf(divider);
        printf("|%c|%c|%c|\n", board[0], board[1], board[2]);
        printf(divider);
        printf("|%c|%c|%c|\n", board[3], board[4], board[5]);
        printf(divider);
        printf("|%c|%c|%c|\n", board[6], board[7], board[8]);
        printf(divider);
        printf("\n");
    }

    checkWin();
    if (gamestate == 1)
    {
        printf("Player One Wins!\n");
        gamestate = 5;
    }
    else if (gamestate == 2)
    {
        printf("Player Two Wins!\n");
        gamestate = 5;
    }
    else if (gamestate == 3)
    {
        printf("Tie\n");
        gamestate = 5;
    }

    if (gamestate == 0)
    {
        printf("Where would player two like to put an O:\n");
        in = getchar();
        getchar();
        player2Move(in);
    }

    if (gamestate == 0)
    {
        checkWin();
    }

    if (gamestate == 1)
    {
        printf("Player One Wins!\n");
        gamestate = 5;
    }
    else if (gamestate == 2)
    {
        printf("Player Two Wins!\n");
        gamestate = 5;
    }
    else if (gamestate == 3)
    {
        printf("Tie\n");
        gamestate = 5;
    }

    return 0;
}