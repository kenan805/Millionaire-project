#include<iostream>
#include<windows.h>
#include<ctime>
#include<conio.h>
#include<mmsystem.h>

using namespace std;

int choiceNum;
char yes_or_no;
char answer;
char stop_continue;
char correct_answer;
char choice_L_or_A;
char name[20];
char friendName[20];
int gain;
int lifeline;
int i = 1;
int count1 = 0, count2 = 0, count3 = 0;
int correctPer, incorrectPer1, incorrectPer2, incorrectPer3;


void choiseMenu();

void mySetColor(int fg, int bg) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, fg | (bg << 4));
}

void introduction() {
	system("cls");
	mySetColor(2, 0);
	cout << "\t\t\t\t$     $\n";
	cout << "\t\t\t\t$$   $$  $  $       $       $   $$$$   $    $    $$    $  $$$$$   $$$$$$\n";
	cout << "\t\t\t\t$ $ $ $     $       $          $    $  $$   $   $  $      $    $  $\n";
	cout << "\t\t\t\t$  $  $  $  $       $       $  $    $  $ $  $  $    $  $  $    $  $$$$$\n";
	cout << "\t\t\t\t$     $  $  $       $       $  $    $  $  $ $  $$$$$$  $  $$$$$   $\n";
	cout << "\t\t\t\t$     $  $  $       $       $  $    $  $   $$  $    $  $  $   $   $\n";
	cout << "\t\t\t\t$     $  $  $$$$$$  $$$$$$  $   $$$$   $    $  $    $  $  $    $  $$$$$$\n\n";
	mySetColor(14, 0);
	cout << "\t\t\t\t\t     > > > > Welcome to the Millionaire game < < < <     \n";
	mySetColor(3, 0);
	cout << "\n\n\t\t\t\t\t\t1 Start\t\t2 Rules\t\t3 Quit\n\n";
	mySetColor(6, 0);
	PlaySound(TEXT("mil.wav"), NULL, SND_SYNC);
	cout << "\t\t\t\tMake your choice: ";
	cin >> choiceNum;
	choiseMenu();
	mySetColor(7, 0);
}

void rules() {
	system("cls");
	mySetColor(8, 0);
	cout << "\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	cout << "\n\n\t\t\t* There will be a total of 12 questions in the game.\n\n\t\t\t* You will have 3 chances.";
	cout << "These are the friendly call, 50/50 and the audience's answers.\n\n";
	cout << "\t\t\t* The value of the question:\t1 --> 500 AZN\t\t5 --> 10000 AZN\t\t9  --> 150000 AZN\n";
	cout << "\t\t\t\t\t\t\t2 --> 1000 AZN\t\t6 --> 20000 AZN\t\t10 --> 250000 AZN\n";
	cout << "\t\t\t\t\t\t\t3 --> 2000 AZN\t\t7 --> 50000 AZN\t\t11 --> 500000 AZN\n";
	cout << "\t\t\t\t\t\t\t4 --> 5000 AZN\t\t8 --> 75000 AZN\t\t12 --> 1000000 AZN\n";
	cout << "\n\t\t\t* If a question is answered incorrectly, the game will end. Good luck ...\n\n";
	cout << "\n\t\t\tvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvVVvvvvvvvvvvvvvvvvvvvvvvv\n";
	mySetColor(3, 0);
	cout << "\n\n\t\t\t\t\t\t0 Main menu\t1 Start\t\t2 Rules\t\t3 Quit\n\n";
	mySetColor(6, 0);
	PlaySound(TEXT("rules.wav"), NULL, SND_SYNC);
	cout << "\t\t\tMake your choice: ";
	cin >> choiceNum;
	if (choiceNum == 0 || choiceNum == 1 || choiceNum == 2 || choiceNum == 3)
		choiseMenu();
	else {
		mySetColor(4, 0);
		cout << "\n\t\t\tThe choice is wrong.Try again...\n";
		Sleep(1000);
		system("cls");
		rules();
	}
	mySetColor(7, 0);
}

void quit() {
	system("cls");
	mySetColor(8, 0);
	cout << "\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n";
	cout << "\t\t\t\tAre you sure you want to exit the game ?\n\n\t\t\t\tMake your choice Y(yes) or N(no): ";
	cin >> yes_or_no;

	if (yes_or_no == 'Y' || yes_or_no == 'y') {
		system("cls");
		mySetColor(14, 0);
		cout << "\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n";
		cout << "\n\n\n\t\t\t\t\t\tSee you in the next game.Bye...\n\n\n";
		cout << "\n\n\t\t\t\tvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n";
		PlaySound(TEXT("closing.wav"), NULL, SND_SYNC);
		mySetColor(7, 0);
		exit(0);

	}
	else if (yes_or_no == 'N' || yes_or_no == 'n') introduction();
	else {
		mySetColor(4, 0);
		cout << "\n\t\t\t\tThe choice is wrong.Try again...\n";
		Sleep(800);
		system("cls");
		quit();
	}
}

void retryGame() {
	mySetColor(8, 0);
	cout << "\nReturn to the main menu to play again, get help and exit the game. ( Select 0 )";
	cin >> choiceNum;
	if (choiceNum == 0) introduction();
	else
	{
		cout << "\nThe choice is wrong.Try again...\n";
		system("cls");
		retryGame();
	}
}

void checkAnswer() {
	mySetColor(14, 0);
	cout << "\n\nChoose your answer: ";
	cin >> answer;
	PlaySound(TEXT("milanswer.wav"), NULL, SND_SYNC);
}

void answer_correctA() {
	count1 = 1;
	incorrectPer1 = rand() % 20;
	incorrectPer2 = rand() % 20;
	incorrectPer3 = rand() % 20;
	correctPer = 100 - (incorrectPer1 + incorrectPer2 + incorrectPer3);
	cout << "\nA --> " << correctPer << " %" << endl;
	cout << "B --> " << incorrectPer1 << " %" << endl;
	cout << "C --> " << incorrectPer2 << " %" << endl;
	cout << "D --> " << incorrectPer3 << " %" << endl;
}

void answer_correctB() {
	count1 = 1;
	incorrectPer1 = rand() % 20;
	incorrectPer2 = rand() % 20;
	incorrectPer3 = rand() % 20;
	correctPer = 100 - (incorrectPer1 + incorrectPer2 + incorrectPer3);
	cout << "\nA --> " << incorrectPer1 << " %" << endl;
	cout << "B --> " << correctPer << " %" << endl;
	cout << "C --> " << incorrectPer2 << " %" << endl;
	cout << "D --> " << incorrectPer3 << " %" << endl;
}

void answer_correctC() {
	count1 = 1;
	incorrectPer1 = rand() % 20;
	incorrectPer2 = rand() % 20;
	incorrectPer3 = rand() % 20;
	correctPer = 100 - (incorrectPer1 + incorrectPer2 + incorrectPer3);
	cout << "\nA --> " << incorrectPer1 << " %" << endl;
	cout << "B --> " << incorrectPer2 << " %" << endl;
	cout << "C --> " << correctPer << " %" << endl;
	cout << "D --> " << incorrectPer3 << " %" << endl;
}

void answer_correctD() {
	count1 = 1;
	incorrectPer1 = rand() % 20;
	incorrectPer2 = rand() % 20;
	incorrectPer3 = rand() % 20;
	correctPer = 100 - (incorrectPer1 + incorrectPer2 + incorrectPer3);
	cout << "\nA --> " << incorrectPer1 << " %" << endl;
	cout << "B --> " << incorrectPer2 << " %" << endl;
	cout << "C --> " << incorrectPer3 << " %" << endl;
	cout << "D --> " << correctPer << " %" << endl;
}

void friendRandomAnswers() {
	char random_answers = 65 + rand() % 4;
	switch (correct_answer)
	{
	case 'A': if (random_answers != correct_answer) cout << random_answers;
			else friendRandomAnswers();
		break;
	case 'B': if (random_answers != correct_answer) cout << random_answers;
			else friendRandomAnswers();
		break;
	case 'C': if (random_answers != correct_answer) cout << random_answers;
			else friendRandomAnswers();
		break;
	case 'D': if (random_answers != correct_answer) cout << random_answers;
			else friendRandomAnswers();
		break;
	}
}

void friendTrue() {
	count3 = 1;
	cout << "\nEnter your friend's name: ";
	cin >> friendName;
	cout << "\nCALLING ...";
	cout << endl;
	cout << endl;
	PlaySound(TEXT("call.wav"), NULL, SND_SYNC);
	PlaySound(TEXT("pickup.wav"), NULL, SND_SYNC);
	cout << friendName << ": Hello?  " << name << " need Help?" << endl << endl;
	Sleep(1000);
	cout << name << ": Yes friend. " << "Can you help me with question " << i << " ?" << endl << endl;
	Sleep(1000);
	cout << friendName << ": I think it's " << correct_answer << endl << endl;
	Sleep(1000);
	cout << name << ": How sure are you?" << endl << endl;
	Sleep(1000);
	cout << friendName << ": I'm 100% sure about this." << endl << endl;
	Sleep(1000);
	cout << name << ": Okay thanks!" << endl << endl;
	Sleep(200);
	PlaySound(TEXT("callend.wav"), NULL, SND_SYNC);
}

void friendFalse() {
	count3 = 1;
	cout << "\nEnter your friend's name: ";
	cin >> friendName;
	cout << "\nCALLING ";
	Sleep(200);
	cout << ".";
	Sleep(200);
	cout << ".";
	Sleep(200);
	cout << ".";
	cout << endl;
	cout << endl;
	PlaySound(TEXT("call.wav"), NULL, SND_SYNC);
	PlaySound(TEXT("pickup.wav"), NULL, SND_SYNC);
	cout << friendName << ": Hello?  " << name << " need Help?" << endl << endl;
	Sleep(1000);
	cout << name << ": Yes friend. " << "Can you help me with question " << i << " ?" << endl << endl;
	Sleep(1000);
	cout << friendName << ": I think it's  ";
	friendRandomAnswers();
	Sleep(1000);
	cout << endl << endl;
	cout << name << ": How sure are you?" << endl << endl;
	Sleep(1000);
	cout << friendName << ": I'm not sure" << endl << endl;
	Sleep(1000);
	cout << name << ": Okay thanks!" << endl << endl;
	PlaySound(TEXT("callend.wav"), NULL, SND_SYNC);
}

void lifeHacks() {
	mySetColor(2, 0);
	cout << "\nLifeline 1: Ask the Audience - You will ask the opinion of the audience.\n" << endl;
	cout << "Lifeline 2: 50:50 - The two right answers will remain.\n" << endl;
	cout << "Lifeline 3: Call a Friend - You may call a friend to help you.\n" << endl;
	mySetColor(14, 0);
	lifeline = 0;
	cout << "What lifeline do you want to use ? ";
	cin >> lifeline;
	mySetColor(2, 0);
	if (lifeline == 1)
	{
		if (count1 == 1) {
			mySetColor(4, 0);
			cout << "\nX ~ You have already used this lifeline\n";
			lifeHacks();
		}
		else {
			PlaySound(TEXT("ask.wav"), NULL, SND_SYNC);
			switch (correct_answer)
			{
			case 'A':
				answer_correctA();
				checkAnswer();
				break;
			case 'B':
				answer_correctB();
				checkAnswer();
				break;
			case 'C':
				answer_correctC();
				checkAnswer();
				break;
			case 'D':
				answer_correctD();
				checkAnswer();
				break;

			}

		}
	}
	else if (lifeline == 2) {
		if (count2 == 1) {
			mySetColor(4, 0);
			cout << "\nX ~ You have already used this lifeline\n";
			lifeHacks();
		}
		else {
			mySetColor(9, 0);
			switch (i)
			{
			case 1:
				count2 = 1;
				cout << "\nA) 4 bayt\t\tB)       \n\nC)       \t\tD) 2 bayt" << endl;
				PlaySound(TEXT("50-50.wav"), NULL, SND_SYNC);
				checkAnswer();
				break;
			case 2:
				count2 = 1;
				cout << "\nA)       \t\tB)       \n\nC) 1 bayt\t\tD) 2 bayt" << endl;
				PlaySound(TEXT("50-50.wav"), NULL, SND_SYNC);
				checkAnswer();
				break;
			case 3:
				count2 = 1;
				cout << "\nA) 4 bayt\t\tB)       \n\nC)       \t\tD) 2 bayt" << endl;
				PlaySound(TEXT("50-50.wav"), NULL, SND_SYNC);
				checkAnswer();
				break;
			case 4:
				count2 = 1;
				cout << "\nA) 4 bayt\t\tB) 8 bayt\n\nC)       \t\tD)       " << endl;
				PlaySound(TEXT("50-50.wav"), NULL, SND_SYNC);
				checkAnswer();
				break;
			case 5:
				count2 = 1;
				cout << "\nA)       \t\tB) ||,&&,!\n\nC)       \t\tD) <,<=,==,!=" << endl;
				PlaySound(TEXT("50-50.wav"), NULL, SND_SYNC);
				checkAnswer();
				break;
			case 6:
				count2 = 1;
				cout << "\nA) \\n\t\tB)    \n\nC) \\t\t\tD)    " << endl;
				PlaySound(TEXT("50-50.wav"), NULL, SND_SYNC);
				checkAnswer();
				break;
			case 7:
				count2 = 1;
				cout << "\nA)       \t\tB) z > k\n\nC)       \t\tD) i--" << endl;
				PlaySound(TEXT("50-50.wav"), NULL, SND_SYNC);
				checkAnswer();
				break;
			case 8:
				count2 = 1;
				cout << "\nA) * \t\tB)   \n\nC) &\t\tD)   " << endl;
				PlaySound(TEXT("50-50.wav"), NULL, SND_SYNC);
				checkAnswer();
				break;
			case 9:
				count2 = 1;
				cout << "\nA) 4 byte \t\tB)       \n\nC)       \t\tD) 1 byte " << endl;
				PlaySound(TEXT("50-50.wav"), NULL, SND_SYNC);
				checkAnswer();
				break;
			case 10:
				count2 = 1;
				cout << "\nA)       \t\tB) C++\n\nC) Phyton\t\tD)       " << endl;
				PlaySound(TEXT("50-50.wav"), NULL, SND_SYNC);
				checkAnswer();
				break;
			case 11:
				count2 = 1;
				cout << "\nA) References \t\tB)        \n\nC)        \t\tD) Private " << endl;
				PlaySound(TEXT("50-50.wav"), NULL, SND_SYNC);
				checkAnswer();
				break;
			case 12:
				count2 = 1;
				cout << "\nA)                  \t\tB) 1983, Guido van Rossum\n\nC)                  \t\tD) 1985, Bjarne Stroustrup " << endl;
				PlaySound(TEXT("50-50.wav"), NULL, SND_SYNC);
				checkAnswer();
				break;
			}
		}
	}
	else if (lifeline == 3) {
		if (count3 == 1) {
			mySetColor(4, 0);
			cout << "\nX ~ You have already used this lifeline\n";
			lifeHacks();
		}
		if (correct_answer == 'A')
		{
			(rand() % 4) ? friendTrue() : friendFalse();
			checkAnswer();
		}
		else if (correct_answer == 'B')
		{
			(rand() % 4) ? friendTrue() : friendFalse();
			checkAnswer();
		}
		else if (correct_answer == 'C')
		{
			(rand() % 4) ? friendTrue() : friendFalse();
			checkAnswer();
		}
		else if (correct_answer == 'D')
		{
			(rand() % 4) ? friendTrue() : friendFalse();
			checkAnswer();
		}
	}
	else {
		mySetColor(4, 0);
		cout << "\nThe choice is wrong.Try again...\n";
		Sleep(1500);
		lifeHacks();
	}
}

void lifelineOrAnswer() {
	mySetColor(14, 0);
	if (!(count1 == 1 && count2 == 1 && count3 == 1)) {
		cout << "\n\nSelect H to use the lifelines, A to answer: ";
		cin >> choice_L_or_A;
		if (choice_L_or_A == 'H' || choice_L_or_A == 'h') lifeHacks();
		else if (choice_L_or_A == 'A' || choice_L_or_A == 'a') checkAnswer();
		else {
			mySetColor(4, 0);
			cout << "\nThe choice is wrong.Try again...\n";
			Sleep(1000);
			lifelineOrAnswer();
		}
	}
	else checkAnswer();
}

void exitGame() {
	mySetColor(2, 0);
	i = 1;
	cout << "\n\nYour earnings are " << gain << " AZN\n\n";
	retryGame();
	mySetColor(7, 0);
}

void endGame() {
	mySetColor(4, 0);
	if (gain >= 1000 && gain <= 50000) {
		cout << "\n\nThe answer is wrong.Game over ! ! !\n\nYour earnings are " << 1000 << " AZN\n\n";
		PlaySound(TEXT("lose.wav"), NULL, SND_SYNC);
		i = 1;
	}
	else if (gain >= 50000) {
		cout << "\n\nThe answer is wrong.Game over ! ! !\n\nYour earnings are " << 50000 << " AZN\n\n";
		PlaySound(TEXT("lose.wav"), NULL, SND_SYNC);
		i = 1;
	}
	else {
		cout << "\n\nThe answer is wrong.Game over ! ! !\n\nYour earnings are " << 0 << " AZN\n\n";
		PlaySound(TEXT("lose.wav"), NULL, SND_SYNC);
		i = 1;
	}

	retryGame();
	mySetColor(7, 0);
}

void _continue() {
	mySetColor(8, 0);
	cout << "\nDo you want to continue the game?\n\nMake your choice Y(yes) or N(no): ";
	cin >> yes_or_no;
	if (yes_or_no == 'N' || yes_or_no == 'n') {
		exitGame();
	}
	else if (yes_or_no == 'Y' || yes_or_no == 'y') {
		i++;
	}
	else {
		mySetColor(4, 0);
		cout << "\nThe choice is wrong.Try again...\n";
		Sleep(1500);
		system("cls");
		_continue();
	}
}

void millionaire() {
	mySetColor(2, 0);
	cout << "\n ##    ##  #######  ##     ##\n";
	cout << "  ##  ##  ##     ## ##     ##\n";
	cout << "   ####   ##     ## ##     ##\n";
	cout << "    ##    ##     ## ##     ##\n";
	cout << "    ##    ##     ## ##     ##\n";
	cout << "    ##    ##     ## ##     ##\n";
	cout << "    ##     #######   #######\n\n";
	cout << "             ###    ########  ########\n";
	cout << "            ## ##   ##     ## ##      \n";
	cout << "           ##   ##  ##     ## ##      \n";
	cout << "          ##     ## ########  ######  \n";
	cout << "          ######### ##   ##   ##      \n";
	cout << "          ##     ## ##    ##  ##      \n";
	cout << "          ##     ## ##     ## ########\n\n";
	cout << "                      ###         ##     ## #### ##       ##       ####  #######  ##    ##    ###    #### ########  ########\n";
	cout << "                     ## ##        ###   ###  ##  ##       ##        ##  ##     ## ###   ##   ## ##    ##  ##     ## ##      \n";
	cout << "                    ##   ##       #### ####  ##  ##       ##        ##  ##     ## ####  ##  ##   ##   ##  ##     ## ##      \n";
	cout << "                   ##     ##      ## ### ##  ##  ##       ##        ##  ##     ## ## ## ## ##     ##  ##  ########  ######  \n";
	cout << "                   #########      ##     ##  ##  ##       ##        ##  ##     ## ##  #### #########  ##  ##   ##   ##      \n";
	cout << "                   ##     ##      ##     ##  ##  ##       ##        ##  ##     ## ##   ### ##     ##  ##  ##    ##  ##      \n";
	cout << "                   ##     ##      ##     ## #### ######## ######## ####  #######  ##    ## ##     ## #### ##     ## ########\n";
	PlaySound(TEXT("milwin.wav"), NULL, SND_SYNC);

	retryGame();
}

void questions() {
	system("cls");
	while (i <= 12) {
		{
			switch (i)
			{
			case 1:
				mySetColor(10, 0);
				cout << "Okay " << name << " the game  has started";
				mySetColor(9, 0);
				cout << "\n\nQuestion " << i << ": What is the size of the int data type ?\n\n";
				cout << "A) 4 bayt\t\tB) 8 bayt\n\nC) 1 bayt\t\tD) 2 bayt";
				correct_answer = 'A';
				lifelineOrAnswer();
				mySetColor(2, 0);
				if (answer == 'a' || answer == 'A') {
					gain = 500;
					cout << "\n\nCongratulations. The answer is correct. \n\n> > > The amount you earn is " << gain << " AZN < < < \n";
					PlaySound(TEXT("win.wav"), NULL, SND_SYNC);
					_continue();
				}
				else if (answer == 'b' || answer == 'B' || answer == 'c' || answer == 'C' || answer == 'd' || answer == 'D') {
					endGame();
				}
				else {
					mySetColor(4, 0);
					cout << "\n\nThe choice is wrong.Try again...\n";
					Sleep(500);
					questions();
				}
			case 2:
				system("cls");
				mySetColor(9, 0);
				cout << "Question " << i << ": What is the size of the bool data type ?\n\n";
				cout << "A) 4 bayt\t\tB) 8 bayt\n\nC) 1 bayt\t\tD) 2 bayt";
				correct_answer = 'C';
				lifelineOrAnswer();
				mySetColor(2, 0);
				if (answer == 'c' || answer == 'C') {
					gain = 1000;
					cout << "\n\nCongratulations. The answer is correct. \n\n> > > The amount you earn is " << gain << " AZN < < < \n";
					PlaySound(TEXT("win.wav"), NULL, SND_SYNC);
					_continue();
				}
				else if (answer == 'b' || answer == 'B' || answer == 'a' || answer == 'A' || answer == 'd' || answer == 'D') {
					endGame();
				}
				else {
					mySetColor(4, 0);
					cout << "\n\nThe choice is wrong.Try again...\n";
					Sleep(500);
					system("cls");
					questions();
				}
			case 3:
				system("cls");
				mySetColor(9, 0);
				cout << "Question " << i << ": What is the size of the short data type ?\n\n";
				cout << "A) 4 bayt\t\tB) 8 bayt\n\nC) 1 bayt\t\tD) 2 bayt";
				correct_answer = 'D';
				lifelineOrAnswer();
				mySetColor(2, 0);
				if (answer == 'd' || answer == 'D') {
					gain = 2000;
					cout << "\n\nCongratulations. The answer is correct. \n\n> > > The amount you earn is " << gain << " AZN < < < \n";
					PlaySound(TEXT("win.wav"), NULL, SND_SYNC);
					_continue();
				}
				else if (answer == 'b' || answer == 'B' || answer == 'c' || answer == 'C' || answer == 'a' || answer == 'A') {
					endGame();
				}
				else {
					mySetColor(4, 0);
					cout << "The choice is wrong.Try again...\n";
					Sleep(500);
					system("cls");
					questions();
				}
			case 4:
				system("cls");
				mySetColor(9, 0);
				cout << "Question " << i << ": What is the size of the double data type ?\n\n";
				cout << "A) 4 bayt\t\tB) 8 bayt\n\nC) 1 bayt\t\tD) 2 bayt";
				correct_answer = 'B';
				lifelineOrAnswer();
				mySetColor(2, 0);
				if (answer == 'b' || answer == 'B') {
					gain = 5000;
					cout << "\n\nCongratulations. The answer is correct. \n\n> > > The amount you earn is " << gain << " AZN < < < \n";
					PlaySound(TEXT("win.wav"), NULL, SND_SYNC);
					_continue();
				}
				else if (answer == 'a' || answer == 'A' || answer == 'c' || answer == 'C' || answer == 'd' || answer == 'D') {
					endGame();
				}
				else {
					mySetColor(4, 0);
					cout << "The choice is wrong.Try again...\n";
					Sleep(500);
					system("cls");
					questions();
				}
			case 5:
				system("cls");
				mySetColor(9, 0);
				cout << "Question " << i << ": Which are logical operators ?\n\n";
				cout << "A) +,-,*,/\t\tB) ||,&&,!\n\nC) =,+=,-=,*=\t\tD) <,<=,==,!=";
				correct_answer = 'B';
				lifelineOrAnswer();
				mySetColor(2, 0);
				if (answer == 'b' || answer == 'B') {
					gain = 10000;
					cout << "\n\nCongratulations. The answer is correct. \n\n> > > The amount you earn is " << gain << " AZN < < < \n";
					PlaySound(TEXT("win.wav"), NULL, SND_SYNC);
					_continue();
				}
				else if (answer == 'a' || answer == 'A' || answer == 'c' || answer == 'C' || answer == 'd' || answer == 'D') {
					endGame();
				}
				else {
					mySetColor(4, 0);
					cout << "The choice is wrong.Try again...\n";
					Sleep(500);
					system("cls");
					questions();
				}
			case 6:
				system("cls");
				mySetColor(9, 0);
				cout << "Question " << i << ": Which new line is the escape sequence ?\n\n";
				cout << "A) \\n\t\tB) \\b\n\nC) \\t\t\tD) \\a";
				correct_answer = 'A';
				lifelineOrAnswer();
				mySetColor(2, 0);
				if (answer == 'a' || answer == 'A') {
					gain = 20000;
					cout << "\n\nCongratulations. The answer is correct. \n\n> > > The amount you earn is " << gain << " AZN < < < \n";
					PlaySound(TEXT("win.wav"), NULL, SND_SYNC);
					_continue();
				}
				else if (answer == 'b' || answer == 'B' || answer == 'c' || answer == 'C' || answer == 'd' || answer == 'D') {
					endGame();
				}
				else {
					mySetColor(4, 0);
					cout << "The choice is wrong.Try again...\n";
					Sleep(500);
					system("cls");
					questions();
				}
			case 7:
				system("cls");
				mySetColor(9, 0);
				cout << "Question " << i << ": Which answer used the unary operator ?\n\n";
				cout << "A) m % 4 \t\tB) z > k\n\nC) a + b\t\tD) i--";
				correct_answer = 'D';
				lifelineOrAnswer();
				mySetColor(2, 0);
				if (answer == 'd' || answer == 'D') {
					gain = 50000;
					cout << "\n\nCongratulations. The answer is correct. \n\n> > > The amount you earn is " << gain << " AZN < < < \n";
					PlaySound(TEXT("win.wav"), NULL, SND_SYNC);
					_continue();
				}
				else if (answer == 'b' || answer == 'B' || answer == 'c' || answer == 'C' || answer == 'a' || answer == 'A') {
					endGame();
				}
				else {
					mySetColor(4, 0);
					cout << "The choice is wrong.Try again...\n";
					Sleep(500);
					system("cls");
					questions();
				}
			case 8:
				system("cls");
				mySetColor(9, 0);
				cout << "Question " << i << ": Which symbol is used to learn the address of a variable in C++ ?\n\n";
				cout << "A) * \t\tB) ->\n\nC) &\t\tD) $ ";
				correct_answer = 'C';
				lifelineOrAnswer();
				mySetColor(2, 0);
				if (answer == 'c' || answer == 'C') {
					gain = 75000;
					cout << "\n\nCongratulations. The answer is correct. \n\n> > > The amount you earn is " << gain << " AZN < < < \n";
					PlaySound(TEXT("win.wav"), NULL, SND_SYNC);
					_continue();
				}
				else if (answer == 'b' || answer == 'B' || answer == 'a' || answer == 'A' || answer == 'd' || answer == 'D') {
					endGame();
				}
				else {
					mySetColor(4, 0);
					cout << "The choice is wrong.Try again...\n";
					Sleep(500);
					system("cls");
					questions();
				}
			case 9:
				system("cls");
				mySetColor(9, 0);
				cout << "Question " << i << ": How many bytes is the size of the void ?\n\n";
				cout << "A) 4 byte \t\tB) 2 byte\n\nC) 16 byte\t\tD) 1 byte ";
				correct_answer = 'D';
				lifelineOrAnswer();
				mySetColor(2, 0);
				if (answer == 'd' || answer == 'D') {
					gain = 150000;
					cout << "\n\nCongratulations. The answer is correct. \n\n> > > The amount you earn is " << gain << " AZN < < < \n";
					PlaySound(TEXT("win.wav"), NULL, SND_SYNC);
					_continue();
				}
				else if (answer == 'b' || answer == 'B' || answer == 'c' || answer == 'C' || answer == 'a' || answer == 'A') {
					endGame();
				}
				else {
					mySetColor(4, 0);
					cout << "The choice is wrong.Try again...\n";
					Sleep(500);
					system("cls");
					questions();
				}
			case 10:
				system("cls");
				mySetColor(9, 0);
				cout << "Question " << i << ": Which programming language is closer to machine language ?\n\n";
				cout << "A) Java \t\tB) C++\n\nC) Phyton\t\tD) C# ";
				correct_answer = 'B';
				lifelineOrAnswer();
				mySetColor(2, 0);
				if (answer == 'b' || answer == 'B') {
					gain = 250000;
					cout << "\n\nCongratulations. The answer is correct. \n\n> > > The amount you earn is " << gain << " AZN < < < \n";
					PlaySound(TEXT("win.wav"), NULL, SND_SYNC);
					_continue();
				}
				else if (answer == 'a' || answer == 'A' || answer == 'c' || answer == 'C' || answer == 'd' || answer == 'D') {
					endGame();
				}
				else {
					mySetColor(4, 0);
					cout << "The choice is wrong.Try again...\n";
					Sleep(500);
					system("cls");
					questions();
				}
			case 11:
				system("cls");
				mySetColor(9, 0);
				cout << "Question " << i << ": Which are not access modifiers ?\n\n";
				cout << "A) References \t\tB) Private\n\nC) Protected\t\tD) Private ";
				correct_answer = 'A';
				lifelineOrAnswer();
				mySetColor(2, 0);
				if (answer == 'a' || answer == 'A') {
					gain = 500000;
					cout << "\n\nCongratulations. The answer is correct. \n\n> > > The amount you earn is " << gain << " AZN < < < \n";
					PlaySound(TEXT("win.wav"), NULL, SND_SYNC);
					_continue();
				}
				else if (answer == 'b' || answer == 'B' || answer == 'c' || answer == 'C' || answer == 'd' || answer == 'D') {
					endGame();
				}
				else {
					mySetColor(4, 0);
					cout << "The choice is wrong.Try again...\n";
					Sleep(500);
					system("cls");
					questions();
				}
			case 12:
				system("cls");
				mySetColor(9, 0);
				cout << "This is the last and million manat question.\n\nQuestion " << i << ": In what year and by whom was C ++ created ?\n\n";
				cout << "A) 1995, James Gosling \t\tB) 1983, Guido van Rossum\n\nC) 1999, Dennis Ritchie\t\tD) 1985, Bjarne Stroustrup ";
				correct_answer = 'D';
				lifelineOrAnswer();
				mySetColor(2, 0);
				if (answer == 'd' || answer == 'D') {
					gain = 1000000;
					cout << "\n\nCongratulations. The answer is correct. \n\n> > > The amount you earn is " << gain << " AZN < < < \n";
					millionaire();
					mySetColor(7, 0);
					exit(0);
				}
				else if (answer == 'b' || answer == 'B' || answer == 'c' || answer == 'C' || answer == 'a' || answer == 'A') {
					endGame();
				}
				else {
					mySetColor(4, 0);
					cout << "\nThe choice is wrong.Try again...\n";
					Sleep(500);
					system("cls");
					questions();
				}
			}

		}
	}
}

void choiseMenu() {
	mySetColor(6, 0);
	if (choiceNum == 0) {
		introduction();
	}
	else if (choiceNum == 1) {
		cout << "\n\t\t\t\tEnter your name: ";
		cin >> name;
		questions();

	}
	else if (choiceNum == 2) {
		rules();
	}
	else if (choiceNum == 3) {
		quit();
	}
	else {
		mySetColor(4, 0);
		cout << "\n\t\t\t\tThe choice is wrong.Try again...\n";
		Sleep(1000);
		system("cls");
		introduction();
		choiseMenu();
	}
}


int main() {
	srand(time(NULL));
	introduction();
	choiseMenu();
	return 0;
}