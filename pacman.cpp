#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>

#define x first
#define y second
#define pii pair<int, int>
#define mp make_pair

using namespace std;

char naghshe[20][43] = {
	"##########################################",
	"#E     #              #####     ##       #",
	"# ######        #         #####  #       #",
	"#      #######  ########         #####   #",
	"#               #             ####       #",
	"#               #                      # #",
	"#    ## ##     ##     ## ##   #######  # #",
	"#   #     #          #     #        #  # #",
	"#  #       #  ####  #       #      #   # #",
	"#  #       #        #      #      #    # #",
	"#  #########  ####  #######      #     # #",
	"#  #       #        #           #    #   #",
	"#  #       #  ####  #    ####   #    #####",
	"#  #       #        #           #    #   #",
	"#              ##         ##             #",
	"# #####     #################     ########",
	"#       #             #                  #",
	"# ##### #  ####  #    #    #  #########  #",
	"#       #        #    =    #             #",
	"##########################################"};

char p = 77;

int x = 22, y = 18;

bool pac;

void goToXY(int x = 0,int y = 0) {
     HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD c;
     c.X = x;
     c.Y = y;
     SetConsoleCursorPosition(h, c);
}

void _naghshe () {
	for(int i = 0; i < 20; i++) {
		for (int j = 0; j < 43; ++j)
			cout << (naghshe[i][j] == '#'? char(-37) : naghshe[i][j]);
		cout << '\n';
	}
}

void GameOver () {
	while (true) {
		if(kbhit())
			exit(0);
		system("cls");
		Sleep(300);
	    goToXY(20, 13);
		cout << "Game Over";
	    Sleep(300);
	}
}

void harekat(){
  	if (kbhit()) {
    	int p1 = getch();
    	if (p1 == 'q')
    		GameOver();
    	if ((p1 == 77 || p1 == 72
		 ||  p1 == 75 || p1 == 80)) {
		 	p = p1;
		 }
	}
	int nx = x, ny = y;
	switch (p) {
   	case 72://bala
   		ny = (ny - 1);
   		break;
   	case 77://rast
   		nx = (nx + 1);
   		break;
   	case 80://paiin
   		ny = (ny + 1);
   		break;
   	case 75://chap
   		nx = (nx - 1);
   		break;
	}
	if (naghshe[ny][nx] == '#') 
		return;	
	goToXY(x, y);
	cout << " ";
	x = nx, y = ny;
	goToXY(x, y);
	if (pac)
		p == 77 || p == 75? cout << '=' : cout << char(-70);
	else 
		p == 72? cout << 'v' : p == 77? cout << char(60) : p == 80? cout << char(94): cout << char(62);
	pac ^= 1;
}

int main() {
	system("color C");
	_naghshe();
	while (true) {
		harekat();
		Sleep(185);
	}
	return 0;
}

