/********************************************************
 ** Program Filename: main.cpp
 ** Author: Karim
 ** Project Start Date: 17.04.2017
 ** Description: Tic tac toe (Singleplayer & Multiplayer)
 ********************************************************/



#include <bits/stdc++.h>
#include <conio.h>
//#include <windows.h>
//#include <MMSystem.h>


#define fl(n) for(int i = 0; i < n; i++)


#define ll long long
#define nl endl
#define init -9999
#define u unsigned

using namespace std;

bool movesleft();

int Check_Win();
int win_5x5();
int Easy_AI();
int Med_AI();
int Hard_AI();
int evaluate();
int minimax(int, bool);
int findBestMove();

void Prompt(int);
void Single_Mode();
void Multi_Mode();
void Multi_5x5();
void Draw_Board();
void Draw_5x5();
void Logo();
void Reset_Board();
void Reset_5x5();
void refresh(int);



//3x3
char board[] = {'z',
                    '1','2','3',
                    '4','5','6',
                    '7','8','9'
               };
char reset[] = {'z',
                    '1','2','3',
                    '4','5','6',
                    '7','8','9'
               };


//5x5
string board_5x5[] = {"z",
                      "1","2","3","4","5",
                      "6","7","8","9","10",
                      "11","12","13","14","15",
                      "16","17","18","19","20",
                      "21","22","23","24","25",
                   };
string reset_5x5[] = {"z",
                      "1","2","3","4","5",
                      "6","7","8","9","10",
                      "11","12","13","14","15",
                      "16","17","18","19","20",
                      "21","22","23","24","25",
                   };

static int S1 = 0, S2 = 0;
static int again = 0;
int diff;
//static int coming_from_single = 0;
//static int coming_from_multi_3x3 = 0;
string Player1;
string Player2;
string label;

/*********************************************************************
 ** Function: Draw_Board
 ** Description: Draws the tic tac toe board using the array board[]
 ** Parameters: None.
 ** Pre-Conditions: None.
 ** Post-Conditions: Board is drawn with the array specified.
 *********************************************************************/
void Draw_Board()
{

       system("CLS");
        cout << " ________________" << nl;
        cout << "|    |     |     " << "|  " << nl;
		cout << "| " << board[1] << "  |  " << board[2] << "  |  " << board[3] << "  |  "<< nl;
		cout << "|____|_____|_____" << "|  " << nl;
		cout << "|    |     |     " << "|  " << nl;
		cout << "| " << board[4] << "  |  " << board[5] << "  |  " << board[6] << "  |  " << "                                          " << Player1 << "'s Score: " << S1 <<nl;
		cout << "|____|_____|_____" << "|  " << "                                          " << Player2 << "'s Score: " << S2 <<nl;
		cout << "|    |     |     " << "|  " << nl;
		cout << "| " << board[7] << "  |  " << board[8] << "  |  " << board[9] << "  |  " << nl;
		//cout << "|    |     |     " << "|  " << nl; //design testing
		cout << "|____|_____|_____|" << nl;
}
/****************************************************************************
 ** Function: Draw_5x5
 ** Description: Draws the tic tac toe 5x5 board using the array board_5x5[]
 ** Parameters: None.
 ** Pre-Conditions: None.
 ** Post-Conditions: Board is drawn with the array specified.
 ****************************************************************************/
void Draw_5x5()
{
    /*
         _____________________________
        |     |     |     |     |     |
        |     |     |     |     |     |
        |_____|_____|_____|_____|_____|
        |     |     |     |     |     |
        |     |     |     |     |     |
        |_____|_____|_____|_____|_____|
        |     |     |     |     |     |
        |     |     |     |     |     |
        |_____|_____|_____|_____|_____|
        |     |     |     |     |     |
        |     |     |     |     |     |
        |_____|_____|_____|_____|_____|
        |     |     |     |     |     |
        |     |     |     |     |     |
        |_____|_____|_____|_____|_____|

        */
system("CLS");
cout << "             _____________________________" << nl;
cout << "            |     |     |     |     |     |" << nl;
cout << "            | " << board_5x5[1] << "   |" << " " << board_5x5[2] << "   |" << " " << board_5x5[3] << "   |" << " " << board_5x5[4] << "   |" << " " << board_5x5[5] << "   |" << nl;
cout << "            |_____|_____|_____|_____|_____|" << nl;
cout << "            |     |     |     |     |     |" << nl;
cout << "            | " << board_5x5[6] << "   |" << " " << board_5x5[7] << "   |" << " " << board_5x5[8] << "   |" << " " << board_5x5[9] << "   |" << " " << board_5x5[10] << "  |" << nl;
cout << "            |_____|_____|_____|_____|_____|" << nl;
cout << "            |     |     |     |     |     |" << nl;
cout << "            | " << board_5x5[11] << "  |" << " " << board_5x5[12] << "  |" << " " << board_5x5[13] << "  |" << " " << board_5x5[14] << "  |" << " " << board_5x5[15] << "  |" << nl;
cout << "            |_____|_____|_____|_____|_____|                              "  << Player1 << "'s Score: "  << nl;
cout << "            |     |     |     |     |     |                              "  << Player2 << "'s Score: "  << nl;
cout << "            | " << board_5x5[16] << "  |" << " " << board_5x5[17] << "  |" << " " << board_5x5[18] << "  |" << " " << board_5x5[19] << "  |" << " " << board_5x5[20] << "  |" << nl;
cout << "            |_____|_____|_____|_____|_____|" << nl;
cout << "            |     |     |     |     |     |" << nl;
cout << "            | " << board_5x5[21] << "  |" << " " << board_5x5[22] << "  |" << " " << board_5x5[23] << "  |" << " " << board_5x5[24] << "  |" << " " << board_5x5[25] << "  |" << nl;
cout << "            |_____|_____|_____|_____|_____|" << nl;
}
/*********************************************************************
 ** Function: Logo
 ** Description: Draws the tic tac toe Logo
 ** Parameters: None.
 ** Pre-Conditions: None.
 ** Post-Conditions: Logo is drawn.
 *********************************************************************/
void Logo()
{
    cout << nl;


    /*              ____________
  \\      /        |            |
   \\    /         |            |
    \\  /          |            |
     +             |            |
     /\\           |            |
    /  \\          |            |
   /    \\         |____________|
  /      \\
                                          | /  __    __       __    __
                              _           |/  |__|  |__|  |  |  |  |  |
                             |_|  \ /  .  |\  |  |  |  \  |  |  |  |  |
                             |_|   |   .  | \ |  |  |   \ |  |  |__|  |


    */


cout << "                                 \\      /            ____________                         " << nl;
cout << "                                  \\    /            |            |                        " << nl;
cout << "                                   \\  /             |            |                        " << nl;
cout << "                                    +               |            |                        " << nl;
cout << "                                    /\\              |            |                        " << nl;
cout << "                                   /  \\             |            |                        " << nl;
cout << "                                  /    \\            |            |                        " << nl;
cout << "                                 /      \\           |____________|                        " << nl;
cout << "                                                                                           " << nl;
cout << "                                                                                           " << nl;
cout << "                                                             | /  __    __       __    __  " << nl;
cout << "                                                 _           |/  |__|  |__|  |  |  |  |  | " << nl;
cout << "                                                |_|  \\ /  .  |\\  |  |  |  \\  |  |  |  |  | " << nl;
cout << "                                                |_|   |   .  | \\ |  |  |   \\ |  |  |__|  | " << nl;

}
/*********************************************************************
 ** Function: Reset_Board
 ** Description: Resets board using the backup board array
 ** Parameters: None.
 ** Pre-Conditions: None.
 ** Post-Conditions: Board is reset back to normal.
 *********************************************************************/
void Reset_Board()
{
    board[0] = reset[0];
    board[1] = reset[1];
    board[2] = reset[2];
    board[3] = reset[3];
    board[4] = reset[4];
    board[5] = reset[5];
    board[6] = reset[6];
    board[7] = reset[7];
    board[8] = reset[8];
    board[9] = reset[9];
}
/*********************************************************************
 ** Function: Reset_5x5
 ** Description: Resets board using the backup board array
 ** Parameters: None.
 ** Pre-Conditions: None.
 ** Post-Conditions: Board is reset back to normal.
 *********************************************************************/
void Reset_5x5()
{
    board_5x5[0]  = reset_5x5[0];
    board_5x5[1]  = reset_5x5[1];
    board_5x5[2]  = reset_5x5[2];
    board_5x5[3]  = reset_5x5[3];
    board_5x5[4]  = reset_5x5[4];
    board_5x5[5]  = reset_5x5[5];
    board_5x5[6]  = reset_5x5[6];
    board_5x5[7]  = reset_5x5[7];
    board_5x5[8]  = reset_5x5[8];
    board_5x5[9]  = reset_5x5[9];
    board_5x5[10] = reset_5x5[10];
    board_5x5[11] = reset_5x5[11];
    board_5x5[12] = reset_5x5[12];
    board_5x5[13] = reset_5x5[13];
    board_5x5[14] = reset_5x5[14];
    board_5x5[15] = reset_5x5[15];
    board_5x5[16] = reset_5x5[16];
    board_5x5[17] = reset_5x5[17];
    board_5x5[18] = reset_5x5[18];
    board_5x5[19] = reset_5x5[19];
    board_5x5[20] = reset_5x5[20];
    board_5x5[21] = reset_5x5[21];
    board_5x5[22] = reset_5x5[22];
    board_5x5[23] = reset_5x5[23];
    board_5x5[24] = reset_5x5[24];
    board_5x5[25] = reset_5x5[25];

}
/*********************************************************************************************
 ** Function: Refresh
 ** Description: A macro for a lot of if conditions to refresh board's old state for AI use
 ** Parameters: int.
 ** Pre-Conditions: Loop counter defined.
 ** Post-Conditions: Board is reset back to pre modifications.
 *********************************************************************************************/
void refresh(int i)
{
        if(i == 1) board[1] = '1';
  else  if(i == 2) board[2] = '2';
  else  if(i == 3) board[3] = '3';
  else  if(i == 4) board[4] = '4';
  else  if(i == 5) board[5] = '5';
  else  if(i == 6) board[6] = '6';
  else  if(i == 7) board[7] = '7';
  else  if(i == 8) board[8] = '8';
  else  if(i == 9) board[9] = '9';

}
/*********************************************************************************
 ** Function: Check_Win
 ** Description: Checks who's the winner and announces it
 ** Parameters: None.
 ** Pre-Conditions: Board should have elements of X & O.
 ** Post-Conditions: Winner is announced, user is prompted to play again or Exit
 *********************************************************************************/
int Check_Win()
{
    /*
    Board illustration [Developer use]
     ______________
    |    |    |    |
    |  1 |  2 |  3 |
    |____|____|____|
    |    |    |    |
    |  4 |  5 |  6 |
    |____|____|____|
    |    |    |    |
    |  7 |  8 |  9 |
    |____|____|____|
    */

    u int x;

    if( (board[1] == 'X' && board[2] == 'X' && board[3] == 'X') || (board[4] == 'X' && board[5] == 'X' && board[6] == 'X') ||
        (board[7] == 'X' && board[8] == 'X' && board[9] == 'X') || (board[1] == 'X' && board[5] == 'X' && board[9] == 'X') ||
        (board[3] == 'X' && board[5] == 'X' && board[7] == 'X') || (board[2] == 'X' && board[5] == 'X' && board[8] == 'X') ||
        (board[1] == 'X' && board[4] == 'X' && board[7] == 'X') || (board[3] == 'X' && board[6] == 'X' && board[9] == 'X') )
        {
            x =  1;
        }

else if( (board[1] == 'O' && board[2] == 'O' && board[3] == 'O') || (board[4] == 'O' && board[5] == 'O' && board[6] == 'O') ||
         (board[7] == 'O' && board[8] == 'O' && board[9] == 'O') || (board[1] == 'O' && board[5] == 'O' && board[9] == 'O') ||
         (board[3] == 'O' && board[5] == 'O' && board[7] == 'O') || (board[2] == 'O' && board[5] == 'O' && board[8] == 'O') ||
         (board[1] == 'O' && board[4] == 'O' && board[7] == 'O') || (board[3] == 'O' && board[6] == 'O' && board[9] == 'O') )
         {
             x =  2;
         }
    else x =  0;

   return x;
}
/*********************************************************************************
 ** Function: win_5x5
 ** Description: Checks who's the winner and announces it
 ** Parameters: None.
 ** Pre-Conditions: Board should have elements of X & O.
 ** Post-Conditions: Winner is announced, user is prompted to play again or Exit
 *********************************************************************************/
int win_5x5() // needs all possible condition implementations, only rows are done, rest are still undone!
{
    /*
    Board illustration [Developer use]

         _____________________________
        |     |     |     |     |     |
        |  1  |  2  |  3  |  4  |  5  |
        |_____|_____|_____|_____|_____|
        |     |     |     |     |     |
        |  6  |  7  |  8  |  9  |  10 |
        |_____|_____|_____|_____|_____|
        |     |     |     |     |     |
        |  11 |  12 |  13 |  14 |  15 |
        |_____|_____|_____|_____|_____|
        |     |     |     |     |     |
        |  16 |  17 |  18 |  19 |  20 |
        |_____|_____|_____|_____|_____|
        |     |     |     |     |     |
        |  21 |  22 |  23 |  24 |  25 |
        |_____|_____|_____|_____|_____|

        */

    //Rows
    for(int rows = 1; rows <= 25; rows++)
    {
        if(rows == 1)
        {
            if(board_5x5[1] == board_5x5[2] && board_5x5[2] == board_5x5[3] &&
               board_5x5[3] == board_5x5[4] && board_5x5[4] == board_5x5[5])

            {
                if(board_5x5[1] == "O")
                    return 2;
           else if(board_5x5[1] == "X")
                    return 1;
            }
        }
        else if(rows == 2)
        {
            if(board_5x5[2] == board_5x5[1] && board_5x5[2] == board_5x5[3] &&
               board_5x5[3] == board_5x5[4] && board_5x5[4] == board_5x5[5])
            {
                if(board_5x5[2] == "O")
                    return 2;
           else if(board_5x5[2] == "X")
                    return 1;
            }

        }
        else if(rows == 3)
        {
            if(board_5x5[3] == board_5x5[2] && board_5x5[2] == board_5x5[1] &&
               board_5x5[3] == board_5x5[4] && board_5x5[4] == board_5x5[5])
            {
                if(board_5x5[3] == "O")
                    return 2;
           else if(board_5x5[3] == "X")
                    return 1;
            }

        }
        else if(rows == 4)
        {
            if(board_5x5[4] == board_5x5[3] && board_5x5[3] == board_5x5[2] &&
               board_5x5[2] == board_5x5[1] && board_5x5[4] == board_5x5[5])
            {
                if(board_5x5[4] == "O")
                    return 2;
           else if(board_5x5[4] == "X")
                    return 1;
            }

        }
        else if(rows == 5)
        {
            if(board_5x5[5] == board_5x5[4] && board_5x5[4] == board_5x5[3] &&
               board_5x5[3] == board_5x5[2] && board_5x5[2] == board_5x5[1])
            {
                if(board_5x5[5] == "O")
                    return 2;
           else if(board_5x5[5] == "X")
                    return 1;
            }

        }
        else if(rows == 6)
        {
            if(board_5x5[6] == board_5x5[7] && board_5x5[7] == board_5x5[8] &&
               board_5x5[8] == board_5x5[9] && board_5x5[9] == board_5x5[10])
            {
                if(board_5x5[6] == "O")
                    return 2;
           else if(board_5x5[6] == "X")
                    return 1;
            }

        }
        else if(rows == 7)
        {
            if(board_5x5[7] == board_5x5[6] && board_5x5[7] == board_5x5[8] &&
               board_5x5[8] == board_5x5[9] && board_5x5[9] == board_5x5[10])
            {
                if(board_5x5[7] == "O")
                    return 2;
           else if(board_5x5[7] == "X")
                    return 1;
            }

        }
        else if(rows == 8)
        {
            if(board_5x5[8] == board_5x5[7] && board_5x5[7] == board_5x5[6] &&
               board_5x5[8] == board_5x5[9] && board_5x5[9] == board_5x5[10])
            {
                if(board_5x5[8] == "O")
                    return 2;
           else if(board_5x5[8] == "X")
                    return 1;
            }

        }
        else if(rows == 9)
        {
            if(board_5x5[9] == board_5x5[8] && board_5x5[8] == board_5x5[7] &&
               board_5x5[7] == board_5x5[6] && board_5x5[9] == board_5x5[10])
            {
                if(board_5x5[9] == "O")
                    return 2;
           else if(board_5x5[9] == "X")
                    return 1;
            }

        }
        else if(rows == 10)
        {
            if(board_5x5[10] == board_5x5[9] && board_5x5[9] == board_5x5[8] &&
               board_5x5[8] == board_5x5[7] && board_5x5[7] == board_5x5[6])
            {
                if(board_5x5[10] == "O")
                    return 2;
           else if(board_5x5[10] == "X")
                    return 1;
            }

        }
        else if(rows == 11)
        {
            if(board_5x5[11] == board_5x5[12] && board_5x5[12] == board_5x5[13] &&
               board_5x5[13] == board_5x5[14] && board_5x5[14] == board_5x5[15])
            {
                if(board_5x5[11] == "O")
                    return 2;
           else if(board_5x5[11] == "X")
                    return 1;
            }

        }
        else if(rows == 12)
        {
            if(board_5x5[12] == board_5x5[11] && board_5x5[12] == board_5x5[13] &&
               board_5x5[13] == board_5x5[14] && board_5x5[14] == board_5x5[15])
            {
                if(board_5x5[12] == "O")
                    return 2;
           else if(board_5x5[12] == "X")
                    return 1;
            }

        }
        else if(rows == 13)
        {
            if(board_5x5[13] == board_5x5[12] && board_5x5[12] == board_5x5[11] &&
               board_5x5[13] == board_5x5[14] && board_5x5[14] == board_5x5[15])
            {
                if(board_5x5[13] == "O")
                    return 2;
           else if(board_5x5[13] == "X")
                    return 1;
            }

        }
        else if(rows == 14)
        {
            if(board_5x5[14] == board_5x5[13] && board_5x5[13] == board_5x5[12] &&
               board_5x5[12] == board_5x5[11] && board_5x5[14] == board_5x5[15])
            {
                if(board_5x5[14] == "O")
                    return 2;
           else if(board_5x5[14] == "X")
                    return 1;
            }

        }
        else if(rows == 15)
        {
            if(board_5x5[15] == board_5x5[14] && board_5x5[14] == board_5x5[13] &&
               board_5x5[13] == board_5x5[12] && board_5x5[12] == board_5x5[11])
            {
                if(board_5x5[15] == "O")
                    return 2;
           else if(board_5x5[15] == "X")
                    return 1;
            }

        }
        else if(rows == 16)
        {
            if(board_5x5[16] == board_5x5[17] && board_5x5[17] == board_5x5[18] &&
               board_5x5[18] == board_5x5[19] && board_5x5[19] == board_5x5[20])
            {
                if(board_5x5[16] == "O")
                    return 2;
           else if(board_5x5[16] == "X")
                    return 1;
            }

        }
        else if(rows == 17)
        {
            if(board_5x5[17] == board_5x5[16] && board_5x5[17] == board_5x5[18] &&
               board_5x5[18] == board_5x5[19] && board_5x5[19] == board_5x5[20])
            {
                if(board_5x5[17] == "O")
                    return 2;
           else if(board_5x5[17] == "X")
                    return 1;
            }

        }
        else if(rows == 18)
        {
            if(board_5x5[18] == board_5x5[17] && board_5x5[17] == board_5x5[16] &&
               board_5x5[18] == board_5x5[19] && board_5x5[19] == board_5x5[20])
            {
                if(board_5x5[18] == "O")
                    return 2;
           else if(board_5x5[18] == "X")
                    return 1;
            }

        }
        else if(rows == 19)
        {
            if(board_5x5[19] == board_5x5[18] && board_5x5[18] == board_5x5[17] &&
               board_5x5[17] == board_5x5[16] && board_5x5[19] == board_5x5[20])
            {
                if(board_5x5[19] == "O")
                    return 2;
           else if(board_5x5[19] == "X")
                    return 1;
            }

        }
        else if(rows == 20)
        {
            if(board_5x5[20] == board_5x5[19] && board_5x5[19] == board_5x5[18] &&
               board_5x5[18] == board_5x5[17] && board_5x5[17] == board_5x5[16])
            {
                if(board_5x5[20] == "O")
                    return 2;
           else if(board_5x5[20] == "X")
                    return 1;
            }

        }
        else if(rows == 21)
        {
            if(board_5x5[21] == board_5x5[22] && board_5x5[22] == board_5x5[23] &&
               board_5x5[23] == board_5x5[24] && board_5x5[24] == board_5x5[25])
            {
                if(board_5x5[21] == "O")
                    return 2;
           else if(board_5x5[21] == "X")
                    return 1;
            }

        }
        else if(rows == 22)
        {
            if(board_5x5[22] == board_5x5[21] && board_5x5[22] == board_5x5[23] &&
               board_5x5[23] == board_5x5[24] && board_5x5[24] == board_5x5[25])
            {
                if(board_5x5[22] == "O")
                    return 2;
           else if(board_5x5[22] == "X")
                    return 1;
            }

        }
        else if(rows == 23)
        {
            if(board_5x5[23] == board_5x5[22] && board_5x5[22] == board_5x5[21] &&
               board_5x5[23] == board_5x5[24] && board_5x5[24] == board_5x5[25])
            {
                if(board_5x5[23] == "O")
                    return 2;
           else if(board_5x5[23] == "X")
                    return 1;
            }

        }
        else if(rows == 24)
        {
            if(board_5x5[24] == board_5x5[23] && board_5x5[23] == board_5x5[22] &&
               board_5x5[22] == board_5x5[21] && board_5x5[24] == board_5x5[25])
            {
                if(board_5x5[24] == "O")
                    return 2;
           else if(board_5x5[24] == "X")
                    return 1;
            }

        }
        else if(rows == 25)
        {
            if(board_5x5[25] == board_5x5[24] && board_5x5[24] == board_5x5[23] &&
               board_5x5[23] == board_5x5[22] && board_5x5[22] == board_5x5[21])
            {
                if(board_5x5[25] == "O")
                    return 2;
           else if(board_5x5[25] == "X")
                    return 1;
            }

        }

    }



    /*
    Board illustration [Developer use]

         _____________________________
        |     |     |     |     |     |
        |  1  |  2  |  3  |  4  |  5  |
        |_____|_____|_____|_____|_____|
        |     |     |     |     |     |
        |  6  |  7  |  8  |  9  |  10 |
        |_____|_____|_____|_____|_____|
        |     |     |     |     |     |
        |  11 |  12 |  13 |  14 |  15 |
        |_____|_____|_____|_____|_____|
        |     |     |     |     |     |
        |  16 |  17 |  18 |  19 |  20 |
        |_____|_____|_____|_____|_____|
        |     |     |     |     |     |
        |  21 |  22 |  23 |  24 |  25 |
        |_____|_____|_____|_____|_____|

        */

    //Columns
    for(int column = 1; column <= 25; column++)
    {
        if(column == 1)
        {
            if(board_5x5[1] == board_5x5[6] && board_5x5[6] == board_5x5[11] &&
               board_5x5[11] == board_5x5[16] && board_5x5[16] == board_5x5[21])

            {
                if(board_5x5[1] == "O")
                    return 2;
           else if(board_5x5[1] == "X")
                    return 1;
            }
        }
        else if(column == 2)
        {
            if(board_5x5[2] == board_5x5[7] && board_5x5[7] == board_5x5[12] &&
               board_5x5[12] == board_5x5[17] && board_5x5[17] == board_5x5[22])
            {
                if(board_5x5[2] == "O")
                    return 2;
           else if(board_5x5[2] == "X")
                    return 1;
            }

        }
        else if(column == 3)
        {
            if(board_5x5[3] == board_5x5[8] && board_5x5[8] == board_5x5[13] &&
               board_5x5[13] == board_5x5[18] && board_5x5[18] == board_5x5[23])
            {
                if(board_5x5[3] == "O")
                    return 2;
           else if(board_5x5[3] == "X")
                    return 1;
            }

        }
        else if(column == 4)
        {
            if(board_5x5[4] == board_5x5[9] && board_5x5[9] == board_5x5[14] &&
               board_5x5[14] == board_5x5[19] && board_5x5[19] == board_5x5[24])
            {
                if(board_5x5[4] == "O")
                    return 2;
           else if(board_5x5[4] == "X")
                    return 1;
            }

        }
        else if(column == 5)
        {
            if(board_5x5[5] == board_5x5[10] && board_5x5[10] == board_5x5[15] &&
               board_5x5[15] == board_5x5[20] && board_5x5[20] == board_5x5[25])
            {
                if(board_5x5[5] == "O")
                    return 2;
           else if(board_5x5[5] == "X")
                    return 1;
            }

        }
        else if(column == 6)
        {
            if(board_5x5[6] == board_5x5[1] && board_5x5[6] == board_5x5[11] &&
               board_5x5[11] == board_5x5[16] && board_5x5[16] == board_5x5[21])
            {
                if(board_5x5[6] == "O")
                    return 2;
           else if(board_5x5[6] == "X")
                    return 1;
            }

        }
        else if(column == 7)
        {
            if(board_5x5[7] == board_5x5[2] && board_5x5[7] == board_5x5[12] &&
               board_5x5[12] == board_5x5[17] && board_5x5[17] == board_5x5[22])
            {
                if(board_5x5[7] == "O")
                    return 2;
           else if(board_5x5[7] == "X")
                    return 1;
            }

        }
        else if(column == 8)
        {
            if(board_5x5[8] == board_5x5[3] && board_5x5[8] == board_5x5[13] &&
               board_5x5[13] == board_5x5[18] && board_5x5[18] == board_5x5[23])
            {
                if(board_5x5[8] == "O")
                    return 2;
           else if(board_5x5[8] == "X")
                    return 1;
            }

        }
        else if(column == 9)
        {
            if(board_5x5[9] == board_5x5[4] && board_5x5[9] == board_5x5[14] &&
               board_5x5[14] == board_5x5[19] && board_5x5[19] == board_5x5[24])
            {
                if(board_5x5[9] == "O")
                    return 2;
           else if(board_5x5[9] == "X")
                    return 1;
            }

        }
        else if(column == 10)
        {
            if(board_5x5[10] == board_5x5[5] && board_5x5[10] == board_5x5[15] &&
               board_5x5[15] == board_5x5[20] && board_5x5[20] == board_5x5[25])
            {
                if(board_5x5[10] == "O")
                    return 2;
           else if(board_5x5[10] == "X")
                    return 1;
            }

        }
        else if(column == 11)
        {
            if(board_5x5[11] == board_5x5[6] && board_5x5[6] == board_5x5[1] &&
               board_5x5[11] == board_5x5[16] && board_5x5[16] == board_5x5[21])
            {
                if(board_5x5[11] == "O")
                    return 2;
           else if(board_5x5[11] == "X")
                    return 1;
            }

        }
        else if(column == 12)
        {
            if(board_5x5[12] == board_5x5[7] && board_5x5[7] == board_5x5[2] &&
               board_5x5[12] == board_5x5[17] && board_5x5[17] == board_5x5[22])
            {
                if(board_5x5[12] == "O")
                    return 2;
           else if(board_5x5[12] == "X")
                    return 1;
            }

        }
        else if(column == 13)
        {
            if(board_5x5[13] == board_5x5[8] && board_5x5[8] == board_5x5[3] &&
               board_5x5[13] == board_5x5[18] && board_5x5[18] == board_5x5[23])
            {
                if(board_5x5[13] == "O")
                    return 2;
           else if(board_5x5[13] == "X")
                    return 1;
            }

        }
        else if(column == 14)
        {
            if(board_5x5[14] == board_5x5[9] && board_5x5[9] == board_5x5[4] &&
               board_5x5[14] == board_5x5[19] && board_5x5[19] == board_5x5[24])
            {
                if(board_5x5[14] == "O")
                    return 2;
           else if(board_5x5[14] == "X")
                    return 1;
            }

        }
        else if(column == 15)
        {
            if(board_5x5[15] == board_5x5[10] && board_5x5[10] == board_5x5[5] &&
               board_5x5[15] == board_5x5[20] && board_5x5[20] == board_5x5[25])
            {
                if(board_5x5[15] == "O")
                    return 2;
           else if(board_5x5[15] == "X")
                    return 1;
            }

        }
        else if(column == 16)
        {
            if(board_5x5[16] == board_5x5[11] && board_5x5[11] == board_5x5[6] &&
               board_5x5[6] == board_5x5[1] && board_5x5[16] == board_5x5[21])
            {
                if(board_5x5[16] == "O")
                    return 2;
           else if(board_5x5[16] == "X")
                    return 1;
            }

        }
        else if(column == 17)
        {
            if(board_5x5[17] == board_5x5[12] && board_5x5[12] == board_5x5[7] &&
               board_5x5[7] == board_5x5[2] && board_5x5[17] == board_5x5[22])
            {
                if(board_5x5[17] == "O")
                    return 2;
           else if(board_5x5[17] == "X")
                    return 1;
            }

        }
        else if(column == 18)
        {
            if(board_5x5[18] == board_5x5[13] && board_5x5[13] == board_5x5[8] &&
               board_5x5[8] == board_5x5[3] && board_5x5[18] == board_5x5[23])
            {
                if(board_5x5[18] == "O")
                    return 2;
           else if(board_5x5[18] == "X")
                    return 1;
            }

        }
        else if(column == 19)
        {
            if(board_5x5[19] == board_5x5[14] && board_5x5[14] == board_5x5[9] &&
               board_5x5[9] == board_5x5[4] && board_5x5[19] == board_5x5[24])
            {
                if(board_5x5[19] == "O")
                    return 2;
           else if(board_5x5[19] == "X")
                    return 1;
            }

        }
        else if(column == 20)
        {
            if(board_5x5[20] == board_5x5[15] && board_5x5[15] == board_5x5[10] &&
               board_5x5[10] == board_5x5[5] && board_5x5[20] == board_5x5[25])
            {
                if(board_5x5[20] == "O")
                    return 2;
           else if(board_5x5[20] == "X")
                    return 1;
            }

        }
        else if(column == 21)
        {
            if(board_5x5[21] == board_5x5[16] && board_5x5[16] == board_5x5[11] &&
               board_5x5[11] == board_5x5[6] && board_5x5[6] == board_5x5[1])
            {
                if(board_5x5[21] == "O")
                    return 2;
           else if(board_5x5[21] == "X")
                    return 1;
            }

        }
        else if(column == 22)
        {
            if(board_5x5[17] == board_5x5[12] && board_5x5[12] == board_5x5[7] &&
               board_5x5[7] == board_5x5[2] && board_5x5[22] == board_5x5[17])
            {
                if(board_5x5[22] == "O")
                    return 2;
           else if(board_5x5[22] == "X")
                    return 1;
            }

        }
        else if(column == 23)
        {
            if(board_5x5[23] == board_5x5[18] && board_5x5[18] == board_5x5[13] &&
               board_5x5[13] == board_5x5[8] && board_5x5[8] == board_5x5[3])
            {
                if(board_5x5[23] == "O")
                    return 2;
           else if(board_5x5[23] == "X")
                    return 1;
            }

        }
        else if(column == 24)
        {
            if(board_5x5[24] == board_5x5[19] && board_5x5[19] == board_5x5[14] &&
               board_5x5[14] == board_5x5[9] && board_5x5[9] == board_5x5[4])
            {
                if(board_5x5[24] == "O")
                    return 2;
           else if(board_5x5[24] == "X")
                    return 1;
            }

        }
        else if(column == 25)
        {
            if(board_5x5[25] == board_5x5[20] && board_5x5[20] == board_5x5[15] &&
               board_5x5[15] == board_5x5[10] && board_5x5[10] == board_5x5[5])
            {
                if(board_5x5[25] == "O")
                    return 2;
           else if(board_5x5[25] == "X")
                    return 1;
            }

        }

    }



    /*
    Board illustration [Developer use]

         _____________________________
        |     |     |     |     |     |
        |  1  |  2  |  3  |  4  |  5  |
        |_____|_____|_____|_____|_____|
        |     |     |     |     |     |
        |  6  |  7  |  8  |  9  |  10 |
        |_____|_____|_____|_____|_____|
        |     |     |     |     |     |
        |  11 |  12 |  13 |  14 |  15 |
        |_____|_____|_____|_____|_____|
        |     |     |     |     |     |
        |  16 |  17 |  18 |  19 |  20 |
        |_____|_____|_____|_____|_____|
        |     |     |     |     |     |
        |  21 |  22 |  23 |  24 |  25 |
        |_____|_____|_____|_____|_____|

        */


    //Diagonals
    for(int diagonal = 1; diagonal <= 25; diagonal++)
    {
        if(diagonal == 1)
        {
            if(board_5x5[1] == board_5x5[7] && board_5x5[7] == board_5x5[13] &&
               board_5x5[13] == board_5x5[19] && board_5x5[19] == board_5x5[25])

            {
                if(board_5x5[1] == "O")
                    return 2;
           else if(board_5x5[1] == "X")
                    return 1;
            }
        }
        else if(diagonal == 5)
        {
            if(board_5x5[5] == board_5x5[9] && board_5x5[9] == board_5x5[13] &&
               board_5x5[13] == board_5x5[17] && board_5x5[17] == board_5x5[21])
            {
                if(board_5x5[5] == "O")
                    return 2;
           else if(board_5x5[5] == "X")
                    return 1;
            }

        }

        else if(diagonal == 7)
        {
            if(board_5x5[7] == board_5x5[1] && board_5x5[7] == board_5x5[13] &&
               board_5x5[13] == board_5x5[19] && board_5x5[19] == board_5x5[25])
            {
                if(board_5x5[7] == "O")
                    return 2;
           else if(board_5x5[7] == "X")
                    return 1;
            }

        }

        else if(diagonal == 9)
        {
            if(board_5x5[9] == board_5x5[5] && board_5x5[9] == board_5x5[13] &&
               board_5x5[13] == board_5x5[17] && board_5x5[17] == board_5x5[21])
            {
                if(board_5x5[9] == "O")
                    return 2;
           else if(board_5x5[9] == "X")
                    return 1;
            }

        }


        else if(diagonal == 13)
        {
            if( (board_5x5[13] == board_5x5[7] && board_5x5[7] == board_5x5[1] && board_5x5[13] == board_5x5[19] && board_5x5[19] == board_5x5[25]) ||
                (board_5x5[13] == board_5x5[9] && board_5x5[9] == board_5x5[5] && board_5x5[13] == board_5x5[17] && board_5x5[17] == board_5x5[21]) )

            {
                if(board_5x5[13] == "O")
                    return 2;
           else if(board_5x5[13] == "X")
                    return 1;
            }

        }
        else if(diagonal == 17)
        {
            if(board_5x5[17] == board_5x5[21] && board_5x5[17] == board_5x5[13] &&
               board_5x5[13] == board_5x5[9] && board_5x5[9] == board_5x5[5])
            {
                if(board_5x5[17] == "O")
                    return 2;
           else if(board_5x5[17] == "X")
                    return 1;
            }

        }
        else if(diagonal == 19)
        {
            if(board_5x5[19] == board_5x5[13] && board_5x5[19] == board_5x5[25] &&
               board_5x5[13] == board_5x5[7] && board_5x5[7] == board_5x5[1])
            {
                if(board_5x5[19] == "O")
                    return 2;
           else if(board_5x5[19] == "X")
                    return 1;
            }

        }
        else if(diagonal == 21)
        {
            if(board_5x5[21] == board_5x5[17] && board_5x5[17] == board_5x5[13] &&
               board_5x5[13] == board_5x5[9] && board_5x5[9] == board_5x5[5])
            {
                if(board_5x5[21] == "O")
                    return 2;
           else if(board_5x5[21] == "X")
                    return 1;
            }

        }
        else if(diagonal == 25)
        {
            if(board_5x5[25] == board_5x5[19] && board_5x5[19] == board_5x5[13] &&
               board_5x5[13] == board_5x5[7] && board_5x5[7] == board_5x5[1])
            {
                if(board_5x5[25] == "O")
                    return 2;
           else if(board_5x5[25] == "X")
                    return 1;
            }

        }

    }


   return 0; //default case
}
/*********************************************************************
 ** Function: movesleft
 ** Description: Checks whether there is a place for next move.
 ** Parameters: None.
 ** Pre-Conditions: None.
 ** Post-Conditions: returns true if there is , false if there isn't.
 *********************************************************************/
bool movesleft()
{
    for(int i = 1; i <= 9; i++)
    {
        if(board[i] != reset[i])
            return true;
    }
    return false;
}
/****************************************************************************
 ** Function: evaluate
 ** Description: Returns a total value for the board current condition
 ** Parameters: None.
 ** Pre-Conditions: None.
 ** Post-Conditions: gives a high value for a board if maximizer‘s turn
 **                  or a low value for the board if minimizer‘s turn.
 ****************************************************************************/
int evaluate() //need to implement checking for all rows,columns and diagonals
{
    /*
    Board illustration [Developer use]
     ______________
    |    |    |    |
    |  1 |  2 |  3 |
    |____|____|____|
    |    |    |    |
    |  4 |  5 |  6 |
    |____|____|____|
    |    |    |    |
    |  7 |  8 |  9 |
    |____|____|____|
    */

    //Rows
    for(int rows = 1; rows <= 9; rows++)
    {
        if(rows == 1)
        {
            if(board[1] == board[2] &&
               board[2] == board[3])
            {
                if(board[1] == 'O')
                    return +10;
           else if(board[1] == 'X')
                    return -10;
            }
        }
        else if(rows == 2)
        {
            if(board[2] == board[1] &&
               board[2] == board[3])
            {
                if(board[2] == 'O')
                    return +10;
           else if(board[2] == 'X')
                    return -10;
            }

        }
        else if(rows == 3)
        {
            if(board[3] == board[2] &&
               board[2] == board[1])
            {
                if(board[3] == 'O')
                    return +10;
           else if(board[3] == 'X')
                    return -10;
            }

        }
        else if(rows == 4)
        {
            if(board[4] == board[5] &&
               board[5] == board[6])
            {
                if(board[4] == 'O')
                    return +10;
           else if(board[4] == 'X')
                    return -10;
            }

        }
        else if(rows == 5)
        {
            if(board[5] == board[4] &&
               board[5] == board[6])
            {
                if(board[5] == 'O')
                    return +10;
           else if(board[5] == 'X')
                    return -10;
            }

        }
        else if(rows == 6)
        {
            if(board[6] == board[5] &&
               board[5] == board[4])
            {
                if(board[6] == 'O')
                    return +10;
           else if(board[6] == 'X')
                    return -10;
            }

        }
        else if(rows == 7)
        {
            if(board[7] == board[8] &&
               board[8] == board[9])
            {
                if(board[7] == 'O')
                    return +10;
           else if(board[7] == 'X')
                    return -10;
            }

        }
        else if(rows == 8)
        {
            if(board[8] == board[7] &&
               board[8] == board[9])
            {
                if(board[8] == 'O')
                    return +10;
           else if(board[8] == 'X')
                    return -10;
            }

        }
        else if(rows == 9)
        {
            if(board[9] == board[8] &&
               board[8] == board[7])
            {
                if(board[9] == 'O')
                    return +10;
           else if(board[9] == 'X')
                    return -10;
            }

        }

    }



    /*
    Board illustration [Developer use]
     ______________
    |    |    |    |
    |  1 |  2 |  3 |
    |____|____|____|
    |    |    |    |
    |  4 |  5 |  6 |
    |____|____|____|
    |    |    |    |
    |  7 |  8 |  9 |
    |____|____|____|
    */

    //Columns
    for(int column = 1; column <= 9; column++)
    {
        if(column == 1)
        {
            if(board[1] == board[4] &&
               board[4] == board[7])
            {
                if(board[1] == 'O')
                    return +10;
           else if(board[1] == 'X')
                    return -10;
            }
        }
        else if(column == 2)
        {
            if(board[2] == board[5] &&
               board[5] == board[8])
            {
                if(board[2] == 'O')
                    return +10;
           else if(board[2] == 'X')
                    return -10;
            }

        }
        else if(column == 3)
        {
            if(board[3] == board[6] &&
               board[6] == board[9])
            {
                if(board[3] == 'O')
                    return +10;
           else if(board[3] == 'X')
                    return -10;
            }

        }
        else if(column == 4)
        {
            if(board[4] == board[1] &&
               board[4] == board[7])
            {
                if(board[4] == 'O')
                    return +10;
           else if(board[4] == 'X')
                    return -10;
            }

        }
        else if(column == 5)
        {
            if(board[5] == board[2] &&
               board[5] == board[8])
            {
                if(board[5] == 'O')
                    return +10;
           else if(board[5] == 'X')
                    return -10;
            }

        }
        else if(column == 6)
        {
            if(board[6] == board[3] &&
               board[6] == board[9])
            {
                if(board[6] == 'O')
                    return +10;
           else if(board[6] == 'X')
                    return -10;
            }

        }
        else if(column == 7)
        {
            if(board[7] == board[4] &&
               board[4] == board[1])
            {
                if(board[7] == 'O')
                    return +10;
           else if(board[7] == 'X')
                    return -10;
            }

        }
        else if(column == 8)
        {
            if(board[8] == board[5] &&
               board[5] == board[2])
            {
                if(board[8] == 'O')
                    return +10;
           else if(board[8] == 'X')
                    return -10;
            }

        }
        else if(column == 9)
        {
            if(board[9] == board[6] &&
               board[6] == board[3])
            {
                if(board[9] == 'O')
                    return +10;
           else if(board[9] == 'X')
                    return -10;
            }

        }

    }

    /*
    Board illustration [Developer use]
     ______________
    |    |    |    |
    |  1 |  2 |  3 |
    |____|____|____|
    |    |    |    |
    |  4 |  5 |  6 |
    |____|____|____|
    |    |    |    |
    |  7 |  8 |  9 |
    |____|____|____|
    */


    //Diagonals
    for(int diagonal = 1; diagonal <= 9; diagonal++)
    {
        if(diagonal == 1)
        {
            if(board[1] == board[5] &&
               board[5] == board[9])
            {
                if(board[1] == 'O')
                    return +10;
           else if(board[1] == 'X')
                    return -10;
            }
        }
        else if(diagonal == 3)
        {
            if(board[3] == board[5] &&
               board[5] == board[7])
            {
                if(board[3] == 'O')
                    return +10;
           else if(board[3] == 'X')
                    return -10;
            }

        }
        else if(diagonal == 5)
        {
            if( (board[5] == board[1] && board[5] == board[9]) ||
                (board[5] == board[3] && board[5] == board[7]) )
            {
                if(board[5] == 'O')
                    return +10;
           else if(board[5] == 'X')
                    return -10;
            }

        }
        else if(diagonal == 7)
        {
            if(board[7] == board[5] &&
               board[5] == board[3])
            {
                if(board[7] == 'O')
                    return +10;
           else if(board[7] == 'X')
                    return -10;
            }

        }
        else if(diagonal == 9)
        {
            if(board[9] == board[5] &&
               board[5] == board[1])
            {
                if(board[9] == 'O')
                    return +10;
           else if(board[9] == 'X')
                    return -10;
            }

        }

    }

    return 0; //if no one wins(default case)
}
/*********************************************************************
 ** Function: minimax
 ** Description: Controls Hard AI algorithm
 ** Parameters: int,bool
 ** Pre-Conditions: None.
 ** Post-Conditions: Best move decided.
 *********************************************************************/
int minimax(int depth, bool isMaximized)
{

    int eve = evaluate();

    //------Base Cases------
    if (eve == 10) return eve;

    if (eve == -10) return eve;

    if (movesleft()==false) return 0;



    if (isMaximized)
    {
        int bestMove = -1000;


        for (int i = 1; i <= 9; i++)
        {

                if (board[i] != 'X' && board[i] != 'O')
                {

                    board[i] = 'O';

                    bestMove = max( bestMove,
                        minimax(depth+1, !isMaximized) );


                    refresh(i);
                }

        }
        return bestMove;
    }


    else
    {
        int bestMove = 1000;


        for (int i = 1; i <= 9; i++)
        {

                if (board[i] != 'X' && board[i] != 'O')
                {

                    board[i] = 'X';

                    bestMove = min( bestMove,
                        minimax(depth+1, !isMaximized) );


                    refresh(i);
                }

        }
        return bestMove;
    }

}
/*********************************************************************
 ** Function: findBestMove
 ** Description: Return the best possible move for the player
 ** Parameters: None.
 ** Pre-Conditions: None.
 ** Post-Conditions: None.
 *********************************************************************/
 int findBestMove()
{
    int bestVal = -1000;
    int bestMove;



    for (int i = 1; i <= 9; i++)
    {

            if (board[i] != 'X' && board[i] != 'O')
            {

                board[i] = 'O';


                int moveVal = minimax(0, false);

                refresh(i);

                if (moveVal > bestVal)
                {
                    bestMove = i;
                    bestVal = moveVal;
                }
            }

    }
    return bestMove;
}
/*********************************************************************
 ** Function: Multi_Mode
 ** Description: Controls multi-player mode movements
 ** Parameters: None.
 ** Pre-Conditions: User selects Multi-player from the menu.
 ** Post-Conditions: None.
 *********************************************************************/
void Multi_Mode()
{

    int turn = 1;
    char h;
    int Move,Nx;

    if(again == 0 || Player2 == "CPU")
    {
    bugged:
    cout << "Player 1 Name: ";
    cin >> Player1;
    cout << "Player 2 Name: ";
    cin >> Player2;
    if(Player1 == Player2) {cout << "Similar Names, Retry:" << nl; goto bugged;}
    }
    else if(again == 1) {goto here;}

    here:

    system("CLS");

    cout << "                              \aWelcome " << Player1 << " & " << Player2 << " Press D to start drawing the board" << nl;
    Logo();



    cin >> h;

    if(h == 'D' || h == 'd') Draw_Board();
    else { cout << "Wrong input" << nl; exit(0);}



    /*cout << nl << nl;
    cout << "                                                         " << Player1 << "'s Score: " << S1 << nl
         << "                                                         " << Player2 << "'s Score: " << S2 << nl;*/


         for(int i = 1; i <= 9; i++)
         {

             if(turn == 1)
             {
                 cout << nl << Player1 << "'s Turn, make your move[1-9]: ";
                 bug:
                 cin >> Move;
                 if(Move >= 1 && Move <= 9)
                 {
                     if(board[Move] != 'X' && board[Move] != 'O')
                     {
                         board[Move] = 'X';
                         Draw_Board();
                         if(Check_Win() == 1)
                         {
                             Draw_Board();
                             cout << Player1 << " Wins!" << nl;
                             S1++;
                             cout << "Do you want to play again?(y/n) : ";
                             cin >> h;
                             if(h == 'y' || h == 'Y')
                             {
                                 again = 1;

                                 cout << nl << "1. Single Player" << nl << "2. Multi-Player 3x3 Board" << nl << "3. Multi-Player 5X5 Board" << nl << "4. Exit" << nl << nl;
                                 cin >> Nx;
                                 Reset_Board();
                                 Prompt(Nx);
                                 break;
                             }
                             else {exit(0);}
                         }

                         turn = 2;
                     }
                     else { cout << "Invalid move, Try again: "; goto bug; }
                 }
                 else { cout << "Invalid move, Try again: "; cin.clear(); cin.ignore(); goto bug; }
             }
             else if(turn == 2)
             {
                 cout << nl << Player2 << "'s Turn, make your move[1-9]: ";
                 bugs:
                 cin >> Move;
                 if(Move >= 1 && Move <= 9)
                 {
                     if(board[Move] != 'X' && board[Move] != 'O')
                     {
                         board[Move] = 'O';
                         Draw_Board();
                         if(Check_Win() == 2)
                         {
                             Draw_Board();
                             cout << Player2 << " Wins!" << nl;
                             S2++;
                             cout << "Do you want to play again?(y/n) : ";
                             cin >> h;
                             if(h == 'y' || h == 'Y')
                             {
                                 again = 1;

                                 cout << nl << "1. Single Player" << nl << "2. Multi-Player 3x3 Board" << nl << "3. Multi-Player 5X5 Board" << nl << "4. Exit" << nl << nl;
                                 cin >> Nx;
                                 Reset_Board();
                                 Prompt(Nx);
                                 break;
                             }
                             else {exit(0);}
                         }

                         turn = 1;
                     }
                     else { cout << "Invalid move, Try again: "; goto bugs; }
                 }
                 else { cout << "Invalid move, Try again: "; cin.clear(); cin.ignore(); goto bugs; }
             }
            if(i == 9)
            {
                if(Check_Win() == 1)
                         {
                             Draw_Board();
                             cout << Player1 << " Wins!" << nl;
                             S1++;
                             cout << "Do you want to play again?(y/n) : ";
                             cin >> h;
                             if(h == 'y' || h == 'Y')
                             {
                                 again = 1;

                                 cout << nl << "1. Single Player" << nl << "2. Multi-Player 3x3 Board" << nl << "3. Multi-Player 5X5 Board" << nl << "4. Exit" << nl << nl;
                                 cin >> Nx;
                                 Reset_Board();
                                 Prompt(Nx);
                                 break;
                             }
                             else {exit(0);}
                         }

            else if(Check_Win() == 2)
                         {
                             Draw_Board();
                             cout << Player2 << " Wins!" << nl;
                             S2++;
                             cout << "Do you want to play again?(y/n) : ";
                             cin >> h;
                             if(h == 'y' || h == 'Y')
                             {
                                 again = 1;

                                 cout << nl << "1. Single Player" << nl << "2. Multi-Player 3x3 Board" << nl << "3. Multi-Player 5X5 Board" << nl << "4. Exit" << nl << nl;
                                 cin >> Nx;
                                 Reset_Board();
                                 Prompt(Nx);
                                 break;
                             }
                             else {exit(0);}
                         }

            else if(Check_Win() == 0)
                         {
                             Draw_Board();
                             cout << "Draw! Better luck next time" << nl;
                             cout << "Do you want to play again?(y/n) : ";
                             cin >> h;
                             if(h == 'y' || h == 'Y')
                             {
                                 again = 1;

                                 cout << nl << "1. Single Player" << nl << "2. Multi-Player 3x3 Board" << nl << "3. Multi-Player 5X5 Board" << nl << "4. Exit" << nl << nl;
                                 cin >> Nx;
                                 Reset_Board();
                                 Prompt(Nx);
                                 break;
                             }
                             else {exit(0);}
                         }


         }
         }
}
/*********************************************************************
 ** Function: Multi_5x5
 ** Description: Controls multi-player mode movements for 5x5 board
 ** Parameters: None.
 ** Pre-Conditions: User selects Multi-player from the menu.
 ** Post-Conditions: None.
 *********************************************************************/
void Multi_5x5()
{

    int turn = 1;
    char h;
    int Move,Nx;

    if(again == 0 || Player2 == "CPU")
    {
    bugged:
    cout << "Player 1 Name: ";
    cin >> Player1;
    cout << "Player 2 Name: ";
    cin >> Player2;
    if(Player1 == Player2) {cout << "Similar Names, Retry:" << nl; goto bugged;}
    }
    else if(again == 1) {goto here;}

    here:

    system("CLS");

    cout << "                              \aWelcome " << Player1 << " & " << Player2 << " Press D to start drawing the board_5x5" << nl;
    Logo();



    cin >> h;

    if(h == 'D' || h == 'd') Draw_5x5();
    else { cout << "Wrong input" << nl; exit(0);}



    /*cout << nl << nl;
    cout << "                                                         " << Player1 << "'s Score: " << S1 << nl
         << "                                                         " << Player2 << "'s Score: " << S2 << nl;*/


         for(int i = 1; i <= 25; i++)
         {

             if(turn == 1)
             {
                 cout << nl << Player1 << "'s Turn, make your move[1-9]: ";
                 bug:
                 cin >> Move;
                 if(Move >= 1 && Move <= 9)
                 {
                     if(board_5x5[Move] != "X" && board_5x5[Move] != "O")
                     {

                         board_5x5[Move] = "X";
                         Draw_5x5();
                         if(win_5x5() == 1)
                         {
                             Draw_5x5();
                             cout << Player1 << " Wins!" << nl;
                             S1++;
                             cout << "Do you want to play again?(y/n) : ";
                             cin >> h;
                             if(h == 'y' || h == 'Y')
                             {
                                 again = 1;

                                 cout << nl << "1. Single Player" << nl << "2. Multi-Player 3x3 board_5x5" << nl << "3. Multi-Player 5X5 board_5x5" << nl << "4. Exit" << nl << nl;
                                 cin >> Nx;
                                 Reset_5x5();
                                 Prompt(Nx);
                                 break;
                             }
                             else {exit(0);}
                         }

                         turn = 2;
                     }
                     else { cout << "Invalid move, Try again: "; goto bug; }
                 }
                else if(Move >= 10 && Move <= 25)
                 {
                     if(board_5x5[Move] != "X" && board_5x5[Move] != "O")
                     {

                         board_5x5[Move] = "X ";
                         Draw_5x5();
                         if(win_5x5() == 1)
                         {
                             Draw_5x5();
                             cout << Player1 << " Wins!" << nl;
                             S1++;
                             cout << "Do you want to play again?(y/n) : ";
                             cin >> h;
                             if(h == 'y' || h == 'Y')
                             {
                                 again = 1;

                                 cout << nl << "1. Single Player" << nl << "2. Multi-Player 3x3 board_5x5" << nl << "3. Multi-Player 5X5 board_5x5" << nl << "4. Exit" << nl << nl;
                                 cin >> Nx;
                                 Reset_5x5();
                                 Prompt(Nx);
                                 break;
                             }
                             else {exit(0);}
                         }

                         turn = 2;
                     }
                     else { cout << "Invalid move, Try again: "; goto bug; }
                 }
                 else { cout << "Invalid move, Try again: "; cin.clear(); cin.ignore(); goto bug; }
             }
             else if(turn == 2)
             {
                 cout << nl << Player2 << "'s Turn, make your move[1-9]: ";
                 bugs:
                 cin >> Move;
                 if(Move >= 1 && Move <= 9)
                 {
                     if(board_5x5[Move] != "X" && board_5x5[Move] != "O")
                     {
                         board_5x5[Move] = "O";
                         Draw_5x5();
                         if(win_5x5() == 2)
                         {
                             Draw_5x5();
                             cout << Player2 << " Wins!" << nl;
                             S2++;
                             cout << "Do you want to play again?(y/n) : ";
                             cin >> h;
                             if(h == 'y' || h == 'Y')
                             {
                                 again = 1;

                                 cout << nl << "1. Single Player" << nl << "2. Multi-Player 3x3 board_5x5" << nl << "3. Multi-Player 5X5 board_5x5" << nl << "4. Exit" << nl << nl;
                                 cin >> Nx;
                                 Reset_5x5();
                                 Prompt(Nx);
                                 break;
                             }
                             else {exit(0);}
                         }

                         turn = 1;
                     }
                     else { cout << "Invalid move, Try again: "; goto bugs; }
                 }
                 else  if(Move >= 10 && Move <= 25)
                 {
                     if(board_5x5[Move] != "X" && board_5x5[Move] != "O")
                     {
                         board_5x5[Move] = "O ";
                         Draw_5x5();
                         if(win_5x5() == 2)
                         {
                             Draw_5x5();
                             cout << Player2 << " Wins!" << nl;
                             S2++;
                             cout << "Do you want to play again?(y/n) : ";
                             cin >> h;
                             if(h == 'y' || h == 'Y')
                             {
                                 again = 1;

                                 cout << nl << "1. Single Player" << nl << "2. Multi-Player 3x3 board_5x5" << nl << "3. Multi-Player 5X5 board_5x5" << nl << "4. Exit" << nl << nl;
                                 cin >> Nx;
                                 Reset_5x5();
                                 Prompt(Nx);
                                 break;
                             }
                             else {exit(0);}
                         }

                         turn = 1;
                     }
                     else { cout << "Invalid move, Try again: "; goto bugs; }
                 }
                 else { cout << "Invalid move, Try again: "; cin.clear(); cin.ignore(); goto bugs; }
             }
            if(i == 25)
            {
                if(win_5x5() == 1)
                         {
                             Draw_5x5();
                             cout << Player1 << " Wins!" << nl;
                             S1++;
                             cout << "Do you want to play again?(y/n) : ";
                             cin >> h;
                             if(h == 'y' || h == 'Y')
                             {
                                 again = 1;

                                 cout << nl << "1. Single Player" << nl << "2. Multi-Player 3x3 board_5x5" << nl << "3. Multi-Player 5X5 board_5x5" << nl << "4. Exit" << nl << nl;
                                 cin >> Nx;
                                 Reset_5x5();
                                 Prompt(Nx);
                                 break;
                             }
                             else {exit(0);}
                         }

            else if(win_5x5() == 2)
                         {
                             Draw_5x5();
                             cout << Player2 << " Wins!" << nl;
                             S2++;
                             cout << "Do you want to play again?(y/n) : ";
                             cin >> h;
                             if(h == 'y' || h == 'Y')
                             {
                                 again = 1;

                                 cout << nl << "1. Single Player" << nl << "2. Multi-Player 3x3 board_5x5" << nl << "3. Multi-Player 5X5 board_5x5" << nl << "4. Exit" << nl << nl;
                                 cin >> Nx;
                                 Reset_5x5();
                                 Prompt(Nx);
                                 break;
                             }
                             else {exit(0);}
                         }

            else if(win_5x5() == 0)
                         {
                             Draw_5x5();
                             cout << "Draw! Better luck next time" << nl;
                             cout << "Do you want to play again?(y/n) : ";
                             cin >> h;
                             if(h == 'y' || h == 'Y')
                             {
                                 again = 1;

                                 cout << nl << "1. Single Player" << nl << "2. Multi-Player 3x3 board_5x5" << nl << "3. Multi-Player 5X5 board_5x5" << nl << "4. Exit" << nl << nl;
                                 cin >> Nx;
                                 Reset_5x5();
                                 Prompt(Nx);
                                 break;
                             }
                             else {exit(0);}
                         }


         }
         }
}

/*********************************************************************
 ** Function: Single_Mode
 ** Description: Controls all single player operations & AI
 ** Parameters: None.
 ** Pre-Conditions: User selects Single-player from the menu.
 ** Post-Conditions: None.
 *********************************************************************/
void Single_Mode()
{

    int turn = 1;
    char h;
    int Move,Nx;


    system("CLS");

    for(;;)
    {
        if     (diff == 0) { label = "Easy mode";   break; }
        else if(diff == 1) { label = "Medium Mode"; break; }
        else if(diff == 2) { label = "Hard Mode";   break; }
    }



    if(again == 0 || Player2 != "CPU")
    {
        S1 = 0;
        S2 = 0;
        again = 0;
    cout << "Enter your name: " << nl;
    cin >> Player1;
    Player2 = "CPU";
    }
    else if(again == 1) {goto there;}

    there:
    cout << "                              \aWelcome " << Player1 << " Press D to start drawing the board" << nl;
    Logo();


    cin >> h;

    if(h == 'D' || h == 'd') Draw_Board();
    else { cout << "Wrong input" << nl; exit(0);}


 for(int i = 1; i <= 9; i++)
         {

             if(turn == 1)
             {
                 cout << nl << label << nl;
                 cout << nl << Player1 << "'s Turn, make your move[1-9]: ";
                 bug:
                 cin >> Move;
                 if(Move >= 1 && Move <= 9)
                 {
                     if(board[Move] != 'X' && board[Move] != 'O')
                     {
                         board[Move] = 'X';
                         Draw_Board();
                         if(Check_Win() == 1)
                         {
                             Draw_Board();
                             cout << Player1 << " Wins!" << nl;
                             //int c = evaluate(); //debug dis shit
                             //cout << "Board value: " << c << nl;
                             S1++;
                             cout << "Do you want to play again?(y/n) : ";
                             cin >> h;
                             if(h == 'y' || h == 'Y')
                             {
                                 again = 1;

                                 cout << nl << "1. Single Player" << nl << "2. Multi-Player 3x3 Board" << nl << "3. Multi-Player 5X5 Board" << nl << "4. Exit" << nl << nl;
                                 cin >> Nx;
                                 Reset_Board();
                                 Prompt(Nx);
                                 break;
                             }
                             else {exit(0);}
                         }

                         turn = 2;
                     }
                     else { cout << "Invalid move, Try again: "; goto bug; }
                 }
                 else { cout << "Invalid move, Try again: "; cin.clear(); cin.ignore(); goto bug; }
             }
             else if(turn == 2)
             {
                          //Draw_Board();
                          //cout << nl << label << nl;
                          if     (diff == 0) board[Easy_AI()] = 'O';
                          else if(diff == 1) board[Med_AI()]  = 'O';
                          else if(diff == 2) board[Hard_AI()] = 'O';
                          Draw_Board();
                          //cout << nl << Hard_AI() << nl; //debugging move
                         if(Check_Win() == 2)
                         {
                             Draw_Board();
                             cout << "CPU Wins!" << nl;
                             //int c = evaluate(); //debugging dis shit
                            // cout << "Board value: " << c << nl;
                             S2++;
                             cout << "Do you want to play again?(y/n) : ";
                             cin >> h;
                             if(h == 'y' || h == 'Y')
                             {
                                 again = 1;

                                 cout << nl << "1. Single Player" << nl << "2. Multi-Player 3x3 Board" << nl << "3. Multi-Player 5X5 Board" << nl << "4. Exit" << nl << nl;
                                 cin >> Nx;
                                 Reset_Board();
                                 Prompt(Nx);
                                 break;
                             }
                             else {exit(0);}
                         }

                             turn = 1;


             }
            if(i == 9)
            {
                if(Check_Win() == 1)
                         {
                             Draw_Board();
                             cout << Player1 << " Wins!" << nl;
                             S1++;
                             cout << "Do you want to play again?(y/n) : ";
                             cin >> h;
                             if(h == 'y' || h == 'Y')
                             {
                                 again = 1;

                                 cout << nl << "1. Single Player" << nl << "2. Multi-Player 3x3 Board" << nl << "3. Multi-Player 5X5 Board" << nl << "4. Exit" << nl << nl;
                                 cin >> Nx;
                                 Reset_Board();
                                 Prompt(Nx);
                                 break;
                             }
                             else {exit(0);}
                         }

            else if(Check_Win() == 2)
                         {
                             Draw_Board();
                             cout << Player2 << " Wins!" << nl;
                             S2++;
                             cout << "Do you want to play again?(y/n) : ";
                             cin >> h;
                             if(h == 'y' || h == 'Y')
                             {
                                 again = 1;

                                 cout << nl << "1. Single Player" << nl << "2. Multi-Player 3x3 Board" << nl << "3. Multi-Player 5X5 Board" << nl << "4. Exit" << nl << nl;
                                 cin >> Nx;
                                 Reset_Board();
                                 Prompt(Nx);
                                 break;
                             }
                             else {exit(0);}
                         }

            else if(Check_Win() == 0)
                         {
                             Draw_Board();
                             cout << "Draw! Better luck next time" << nl;
                             cout << "Do you want to play again?(y/n) : ";
                             cin >> h;
                             if(h == 'y' || h == 'Y')
                             {
                                 again = 1;

                                 cout << nl << "1. Single Player" << nl << "2. Multi-Player 3x3 Board" << nl << "3. Multi-Player 5X5 Board" << nl << "4. Exit" << nl << nl;
                                 cin >> Nx;
                                 Reset_Board();
                                 Prompt(Nx);
                                 break;
                             }
                             else {exit(0);}
                         }


         }
         }


}
/*********************************************************************
 ** Function: Easy_AI
 ** Description: Controls all Easy AI operations
 ** Parameters: None.
 ** Pre-Conditions: Called within Single_Mode()
 ** Post-Conditions: Returns random next move for AI.
 *********************************************************************/
int Easy_AI()
{
    int bestMove;

    srand(time(NULL));


    for(int i = 1; i <= 9; i++)
    {
        int flag = 0;

        if(board[i] != 'X' && board[i] != 'O')
        {

            board[i] = 'O';
            u int temp = Check_Win();
            if(temp == 2)
            {
                bestMove = i;
                flag=1;
                break;
            }

          else
          {
              refresh(i);
          }
        }
        if(flag!=1){

        for(int i = 1; i <= 9; i++)
          {

               bestMove = rand() % 10;
               if(board[bestMove] != 'X' && board[bestMove] != 'O') break;
          }

        }
    }

return bestMove;
}
/************************************************************************************
 ** Function: Med_AI
 ** Description: Controls all Medium AI operations
 ** Parameters: None.
 ** Pre-Conditions: Called within Single_Mode()
 ** Post-Conditions: Returns Semi-Smart next move for AI which tries to block player
 *************************************************************************************/
int Med_AI()
{
    int bestMove = findBestMove();

    return bestMove;
}
/************************************************************************************
 ** Function: Hard_AI
 ** Description: Controls all Hard AI operations
 ** Parameters: None.
 ** Pre-Conditions: Called within Single_Mode()
 ** Post-Conditions: Returns next Smart move
 *************************************************************************************/
int Hard_AI() //to implement conditions controlling all positions of X after temp == 2.[DONE!].
            //MUST FIX NOT PLAYING TURN 2 && APPLYING BOTH CONDITIONS OF BLOCK & WIN!!![NOT DONE]. conds 1 3 6, 1 2 4
{           //requires further  implementation.
    int bestMove;

    //srand(time(NULL));


    for(int i =1 ; i <= 9; i++)
    {


        if(board[i] != 'X' && board[i] != 'O')
        {
            board[i] = 'O';
            u int temp = Check_Win();
            board[i] = 'X';
            u int temp2 = Check_Win();

            if(temp == 2)
            {
                bestMove = i;
                refresh(i);
                return bestMove;
            }
            else if(temp2 == 1)
            {
              bestMove = i;
              refresh(i);
              return bestMove;

            }
            else
            {
              refresh(i);
            }
        }
     }
          while(true)
          {
              srand(time(NULL));
              bestMove = rand() % 10;
              if(board[bestMove] != 'X' && board[bestMove] != 'O' && bestMove!=0) return bestMove;

          }

}
/*******************************************************************
 ** Function: PromptM
 ** Description: Decides which Difficulty the AI will play with
 ** Parameters: int
 ** Pre-Conditions: Selects single player from menu
 ** Post-Conditions: Returns difficulty value
 *******************************************************************/
int PromptM(int x)
{
    system("CLS");
    switch(x)
    {
    case 1:
        return 0;
    case 2:
        return 1;
    case 3:
        return 2;

    }
    return 0;
}
/**********************************************************************************************
 ** Function: Prompt
 ** Description: Decides which mode the user picked and sends it to the corresponding function
 ** Parameters: int
 ** Pre-Conditions: int variable defined in main & passed to function
 ** Post-Conditions: Corresponding function is called.
 **********************************************************************************************/
void Prompt(int x)
{
    system("CLS");
    switch(x)
    {
    case 1:
        int ch;
        cout << "Choose AI difficulty:\nNOTE: Entering any value other than 1,2,3 will default it to Easy mode\n" << nl << "1. Easy" << nl << "2. Medium" << nl << "3. Hard" << nl;
        cin >> ch;
        diff = PromptM(ch);
        Single_Mode();
        break;
    case 2:
        Multi_Mode();
        break;
    case 3:
        Multi_5x5();
        break;
    case 4:
        exit(0);
        break;

    default: cout << "Invalid input" << nl;
    }
}

int main()
{


    char ch;
    int dec;
    //PlaySound(TEXT("bird.wav"), NULL, SND_ASYNC | SND_LOOP);
    cout << "Do you want to play(y/n)? ";
    cin >> ch;


    if(ch == tolower('N')) return 1;


    cout << nl << "1. Single Player" << nl << "2. Multi-Player 3x3 Board" << nl << "3. Multi-Player 5X5 Board" << nl << "4. Exit" << nl << nl;
    cin >> dec;
    Prompt(dec);

    getch();
    return 0;
}
