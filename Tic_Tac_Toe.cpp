// Tic Tac Toe Game C++.
// Made By: Aman Singh Bhogal
// Algorithm used for Computer Opponent is Mini Max Algorithm.

#include<iostream>  // For Input Output.
#include<conio.h>   // For using getch() function.
using namespace std;

class tic_tac_toe
{
    // Initializing the Squares:
	char square[10] = {'0','1','2','3','4','5','6','7','8','9'};

	public:
	void display();     // Formatted Output Screen.
	int checkwin();     // Constantly Check for winner.
	void board();       // Logic for Board.
    int make_move(int n,int player);    // Used to make Move on Board
	void run();         // Handles entire Execution
    int minimax_AI(int depth,int isAI);     // Mini Max Algorithm for Computer Opponent.
    int Find_The_Best_Move();       // Finds best move for AI at any given Instance.
};

int tic_tac_toe::make_move(int n, int player)
{
    char mark=(player == 1) ? 'X' : 'O';
    int choice =n;
    for(int i=1;i<=9;i++)
    {
        char c = 48 + i;
        if(choice == i && square[i] == c)
        {
            square[i] = mark;
            return 0;
        }
    }
    cout<<"Invalid Move! Please try again";
    getch();
    return -1;
}

void tic_tac_toe::display()
{
    // For Windows use: system("cls");
    system("cls");
    // For Linux use: system("clear");
    // system("clear");
    cout<<"\t\t\tTic Tac Toe Using Min Max Algorithm."<<endl;
    cout<<"\t\t\t     Code By: Aman Singh Bhogal"<<endl;
	cout << "\t\t\t\t    Tic Tac Toe"<<endl;
    for(int i=0; i<80; i++)
        cout<<"_";
    cout<<endl;
}

// Logic to check if any player is winning.
int tic_tac_toe::checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return ((square[1] == 'X')? 10:-10);
    
	else if (square[4] == square[5] && square[5] == square[6])
	    return ((square[4] == 'X')? 10:-10);
    
	else if (square[7] == square[8] && square[8] == square[9])
        return ((square[7] == 'X')? 10:-10);

	else if (square[1] == square[4] && square[4] == square[7])
		return ((square[7] == 'X')? 10:-10);

	else if (square[2] == square[5] && square[5] == square[8])
		return ((square[2] == 'X')? 10:-10);

	else if (square[3] == square[6] && square[6] == square[9])
		return ((square[3] == 'X')? 10:-10);

	else if (square[1] == square[5] && square[5] == square[9])
		return ((square[1] == 'X')? 10:-10);

	else if (square[3] == square[5] && square[5] == square[7])
		return ((square[3] == 'X')? 10:-10);

	else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
		return 2;

    return 0;
}

// Board of the Game
void tic_tac_toe::board()
{
	display();
	cout<<endl << "\t\t\t   AI (X)  -  Player 2 (O)" << endl << endl;
    cout << "\t\t\t      _________________" << endl;
	cout << "\t\t\t     |     |     |     |" << endl;
	cout << "\t\t\t     |  " << square[1] << "  |  " << square[2] << "  |  " << square[3] <<"  |"<< endl;
	cout << "\t\t\t     |_____|_____|_____|" << endl;
	cout << "\t\t\t     |     |     |     |" << endl;
	cout << "\t\t\t     |  " << square[4] << "  |  " << square[5] << "  |  " << square[6] <<"  |"<< endl;
	cout << "\t\t\t     |_____|_____|_____|" << endl;
	cout << "\t\t\t     |     |     |     |" << endl;
	cout << "\t\t\t     |  " << square[7] << "  |  " << square[8] << "  |  " << square[9] <<"  |" << endl;
	cout << "\t\t\t     |_____|_____|_____|" << endl << endl;
    cout<<endl<<"To Exit Enter Q/q."<<endl;
}

// minimax_AI() is a recursive function that tries to find the best possible move for the Computer player.
int tic_tac_toe::minimax_AI(int depth,int isAI)
{
    int cost = checkwin();

    if(cost == 10 || cost == -10)
        return cost;

    if(cost == 2)
        return 0;

    if(isAI)
    {
        int best = -1000;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                int p = i*3 + j +1;
                char c = 48 + p;
                if(square[p] == c)
                {
                    square[p] = 'X';
                    best = max(best, minimax_AI(depth + 1, 0));
                    square[p] = c;
                }
            }
        }
        return best;
    }
    else
    {
        int best = 1000;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                int p = i*3 + j +1;
                char c = 48 + p;
                if(square[p] == c)
                {
                    square[p] = 'O';
                    best = min(best, minimax_AI(depth + 1, 1));
                    square[p] = c;
                }
            }
        }
        return best;
    }
}

// Finc_The_Best_Move() makes use of the minimax_AI() function to make the move for computer player.
int tic_tac_toe::Find_The_Best_Move()
{
    int bestscore = -1000;
    int bestmove = -1;

    for(int i=0; i< 3; i++) 
    {
        for(int j=0; j<3; j++)
        {
            int p = (i*3) + j +1;
            char c = 48 + p;
            if(square[p] == c)
            {
                square[p] = 'X';
                int moveScore = minimax_AI(0,0);
                square[p] = c;
                if(moveScore > bestscore)
                {
                    bestmove = p;
                    bestscore = moveScore;
                }
            }
        }
    }
    return bestmove;
}

// run() function handles the entire execution of the program.
void tic_tac_toe::run()
{
    board();
    int player=1,win=0;
    string n;
    while(!win)
    {
        player = (player%2)? 1:2; 
        if(player == 2)
        {
            int k;
            cout<<endl<<"Human's Turn, Enter your Choice: ";
            cin>>n;
            if(n == "Q" || n == "q")
                exit(0);
            else
                k = stoi(n);
            int i = make_move(k,player);
            if(i==-1)
                continue;
            player++;
        }
        else
        {
            int move = Find_The_Best_Move();
            make_move(move,player);
            board();
            cout<<"\t\t\t\tAI's Move."<<endl<<endl;
            cout<<"Please Press any key to continue.......";
            getch();
            player++;
        }
        board();
        win = checkwin();
    }
    if(win==10 || win==-10)
		cout<<"\t\t\t\tPlayer "<<((--player==1)?"AI":"Human")<<" Wins!"<<endl<<endl;
	else
		cout<<"\t\t\t\t  Game Draw!"<<endl<<endl;
}

// This is the main function of the Program.
int main()
{
    tic_tac_toe t;
    t.run();
    return 0;
}