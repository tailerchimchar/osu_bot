using namespace std;
#include<windows.graphics.h>
#include<Windows.h>
#include<iostream>
#include<time.h>

void wait(long milliseconds) {
	register long endwait;
	endwait = clock() + milliseconds * CLOCKS_PER_SEC * 0.001;
	while (clock() < endwait) { Sleep(100); } 
	/* //500ms may be quite inaccurate,	but if 
	//it is too inaccurate you can also use sleep(100) 
	or sleep(50).*/
}

int main() {
	

	//initWindow(screenWidth, screenHeight, "", -3, -3);

	POINT cursorPosition;
	
	for (int i = 0; i < 10; i++) {
		DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
		DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
		
		GetCursorPos(&cursorPosition);
		cout << "X: " << cursorPosition.x << " ";
		cout << "Y: " << cursorPosition.y << endl;
		wait(500);
	}
	

	//getch();
	//closegraph();


	return 0;
}