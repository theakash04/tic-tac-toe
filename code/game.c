#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h> 

//Global variable
char board[3][3];
char const P = 'X';
char const B = 'O';

void resetgame();
void printgame();
int checkfreespace();
void playermove();
void botmove();
char checkwinner();
void pwinner(char winner);

int main()
{
    char winner = ' ';
    char r = ' ';

    do{

        winner = ' ';
        r = ' ';
        resetgame();

        while (winner == ' ' && checkfreespace() != 0)
        {
            printgame();

            playermove();
            winner = checkwinner();
            if(winner != ' ' || checkwinner() == 0)
            {
                break;
            }

            botmove();
            winner = checkwinner();
            if(winner != ' ' || checkwinner() == 0)
            {
                break;
            }
        }


        printgame();
        pwinner(winner);

        printf("Do you want to play again!: \n");
        scanf(" %c",&r);
        r = toupper(r);
    }while(r == 'Y');
    
    printf("\nThank you for Playing - DEX");
    return 0;
}


//Game Functions
void resetgame()
{
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        board[i][j] = ' ';
    }
}

void printgame()
{
    printf(" %c | %c | %c ",board[0][0],board[0][1],board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ",board[1][0],board[1][1],board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ",board[2][0],board[2][1],board[2][2]);
    printf("\n");
}

int checkfreespace()
{
    int fspace = 9;
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if(board[i][j] != ' ')
            {
                fspace--;
            }
        }
    }
    return fspace;
}

void playermove()
{
    int x;
    int y;
    

    do
    {
        printf("Enter Row  #(1,2,3): ");
        scanf("%d",&x);
        x--;

        printf("Enter columns  #(1,2,3): ");
        scanf(" %d",&y);
        y--;

        if(board[x][y] != ' ')
        {
            printf("Invalid move!!");
        }
        else
        {
            board[x][y] = P; 
            break;
        }
    } while (board[x][y] != ' ');
}

void botmove()
{
    srand(time(0));
    int x;
    int y;

    if(checkfreespace() > 0)
    {
        do{
        x = rand()%3;
        y = rand()%3;
        }while(board[x][y] != ' ');

        board[x][y] = B;
    }
    else
    {
        pwinner(' ');
    }
}

char checkwinner()
{
    //check rows
    for(int i = 0; i<3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }

    //check columns
    for(int i = 0; i<3; i++)
    {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }

    //check diagnose
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }

    if(board[0][2] == board[1][1] &&  board[0][2] == board[2][0])
    {
        return board[0][2];
    }

    return ' ';
}

void pwinner(char winner)
{
    if(winner == P)
    {
        printf("You win!!\n");
    }
    else if(winner == B)
    {
        printf("You Lose :(\n");
    }
    else
    {
        printf("It's a Draw ^_^\n");
    }
}