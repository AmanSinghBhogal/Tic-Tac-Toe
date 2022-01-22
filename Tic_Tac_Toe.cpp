#include<iostream>
#include<conio.h>
using namespace std;

class tic_tac_toe
{
	char square[10] = {'a','1','2','3','4','5','6','7','8','9'};
	public:
	void display();
	int checkwin();
	void board();
	void run();
};

void tic_tac_toe::display()
{
    system("cls");
    cout<<"\t\t\tTic Tac Toe Using Min Max Algorithm."<<endl;
    cout<<"\t\t\t     Code By: Aman Singh Bhogal"<<endl;
	cout << "\t\t\t\t    Tic Tac Toe"<<endl;
    for(int i=0; i<80; i++)
        cout<<"_";
    cout<<endl;
}

int tic_tac_toe::checkwin()
{
	if (square[1] == square[2] && square[2] == square[3])
		return 1;
	else if (square[4] == square[5] && square[5] == square[6])
		return 1;
	else if (square[7] == square[8] && square[8] == square[9])
		return 1;
	else if (square[1] == square[4] && square[4] == square[7])
		return 1;
	else if (square[2] == square[5] && square[5] == square[8])
		return 1;
	else if (square[3] == square[6] && square[6] == square[9])
		return 1;
	else if (square[1] == square[5] && square[5] == square[9])
		return 1;
	else if (square[3] == square[5] && square[5] == square[7])
		return 1;
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
		 square[4] != '4' && square[5] != '5' && square[6] != '6' &&
	    square[7] != '7' && square[8] != '8' && square[9] != '9')
		return 0;
	else
		return -1;
}

int main()
{
    tic_tac_toe t;
    t.display();
    return 0;
}