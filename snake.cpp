#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>

using namespace std;

#define x first
#define y second
#define pii pair<int, int>
#define mp make_pair

queue <int> jahat;

char p = 77;

int x = 6, y = 0, Tx = 0, Ty = 0, o, xghaza, yghaza, speedy;

bool a[41][21];

bool ghaza_hast;

char* Color(int color=7, char* Message = ""){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    return Message;
}

void goToXY(int x = 0,int y = 0) {
     HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD c;
     c.X = x;
     c.Y = y;
     SetConsoleCursorPosition(h, c);
}


void GameOver () {
	while (true) {
		if(kbhit()) 
			exit(0);
		system("cls");
		Sleep(300);
	    goToXY(20, 13);
	    Color((rand() % 15) + 1);
		cout << "Game Over";
	    Sleep(300);
	}
}

void _speedy () {
	system("cls");
	int maci = 1;
	char mac;
	goToXY(3, 1);
	cout << "1 . Hard";
	goToXY(1, 2);
	cout << char(-2) << " 2 . Normal";
	goToXY(3, 3);
	cout << "3 . Easy";
	while(true) {
		if (kbhit()) {
			mac = getch();
			switch(mac) {
				case 13:
					maci == 0? speedy = 50 :
					maci == 1? speedy = 100 :
					speedy = 150;
					return;
				case 80:
					goToXY(1, maci + 1);
					cout << ' ';
					maci = (maci + 1) % 3;
					goToXY(1, maci + 1);
					cout << char(-2);
					break;
				case 72:
					goToXY(1, maci + 1);
					cout << ' ';
					maci = (maci + 2) % 3;
					goToXY(1, maci + 1);
					cout << char(-2);
					break;
			}
		}
	}
}

void starting() {
	int maci = 1;
	char mac = 72;
	goToXY(1, 1);
	cout << char(-2) << " 1 . start";
	goToXY(3, 2);
	cout << "2 . exit";
	while(true) {
		if (kbhit()) {
			mac = getch();
			switch(mac) {
				case 13:
					if(maci == 1) {
						_speedy();
						return;
					}
					else
						exit(0);
					break;
				case 80:
					goToXY(1, 2);
					cout << char(-2);
					goToXY(1, 1);
					cout << ' ';
					maci = 2;
					break;
				case 72:
					goToXY(1, 1);
					cout << char(-2);
					goToXY(1, 2);
					cout << ' ';
					maci = 1;
					break;
			}
		}
	}
}

void kadr() {
	for (int i = 1; i < 41; ++i) {
   		goToXY(i, 0);
    	cout << char(205);
  	}
  	for (int i = 1; i < 21; ++i) {
    	goToXY(0, i) ;
    	cout << char(186);
  	}
  	for (int i = 1; i < 41; ++i) {
    	goToXY(i, 21);
    	cout << char(205);
  	}
  	for (int i = 1; i < 21; ++i) {
    	goToXY(41, i);
    	cout << char(186);
  	}
  	goToXY(41, 21);
  	cout << char(188);
  	goToXY(0, 21);
  	cout << char(200);
  	goToXY(41, 0);
  	cout << char(187);
  	goToXY(0, 0);
  	cout << char(201);
}

void harekat(){
	int forghaza;
  	if (kbhit()) {
    	int p1 = getch();
    	if (p1 == 'q')
    		GameOver();
    	if (!(p == 77 && p1 == 75)
		 && !(p == 75 && p1 == 77)
		 && !(p == 80 && p1 == 72)
		 && !(p == 72 && p1 == 80)
		 && (p1 == 77 || p1 == 72
		 ||  p1 == 75 || p1 == 80)) {
		 	p = p1;
		 }
    }
	switch (p) {
   	case 72://bala
   		y = (y + 19) % 20;
		forghaza = 1;
   		jahat.push(1);
   		break;
   	case 77://rast
   		x = (x + 1) % 40;
   		x = (x + 1) % 40;
		forghaza = 2;
   		jahat.push(2);
   		break;
   	case 80://paiin
   		y = (y + 1) % 20;
		forghaza = 3;
   		jahat.push(3);
   		break;
   	case 75://chap
   		x = (x + 39) % 40;
   		x = (x + 39) % 40;
		forghaza = 4;
   		jahat.push(4);
   		break;
	}
	if (a[x + 1][y + 1]) {
		GameOver();
	}
	a[x + 1][y + 1] = true;
	goToXY(x + 1, y + 1);
	Color((rand() % 15) + 1);
	cout << char(-2);
	goToXY(Tx + 1, Ty + 1);
	cout << " ";
	if (x + 1 == xghaza && y + 1 == yghaza) {
		ghaza_hast = false;
	}
	else {
		a[Tx + 1][Ty + 1] = false;
		switch (jahat.front()) {
			case 1:
				Ty = (Ty + 19) % 20;
				break;
			case 2:
				Tx = (Tx + 1) % 40;
				Tx = (Tx + 1) % 40;
				break;
			case 3:
				Ty = (Ty + 1) % 20;
				break;
			case 4:
				Tx = (Tx + 39) % 40;
				Tx = (Tx + 39) % 40;
				break;
		}
		jahat.pop();
	}
	if (kbhit()) {
    	int p1 = getch();
    	if (p1 == 'q')
    		GameOver();
    	if (!(p == 77 && p1 == 75)
		 && !(p == 75 && p1 == 77)
		 && !(p == 80 && p1 == 72)
		 && !(p == 72 && p1 == 80)
		 && (p1 == 77 || p1 == 72
		 ||  p1 == 75 || p1 == 80)) {
		 	p = p1;
		 }
    }
}

void ghaza() {
	int adadghaza;	
	do {
		xghaza = 1 + (rand() % 20);
		xghaza = (xghaza * 2) - 1;
    	yghaza = 1 + (rand() % 20);
	} while (a[xghaza][yghaza]);
   	adadghaza = 1 + (rand() % 9);
   	goToXY(xghaza, yghaza);
   	Color((rand() % 15) + 1);
   	cout << adadghaza;
	ghaza_hast = true;
}

int main() {
	menu :
	starting();
	system("cls");
	Color(3);
	srand(time(0));
	jahat.push(2);a[1][1] = true;
	jahat.push(2);a[2][1] = true;
	jahat.push(2);a[3][1] = true;
	a[4][1] = true;
	goToXY(1, 1);
	cout << char(-2) << ' ' << char(-2) << ' ' << char(-2) << ' ' << char(-2);
    kadr();
	while (++o) {
		if (!ghaza_hast)
			ghaza();
		harekat();
		Sleep(speedy);
	}
    return 0;
}
