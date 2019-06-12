#include <iostream>
#include <windows.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	HWND WINS_TIDP;
	WINS_TIDP=FindWindow("ConsoleWindowClass",NULL);	//处理顶级窗口的类名窗口
	ShowWindow(WINS_TIDP,SW_HIDE);				        //设置指定窗口的显示状态
	system("CD BINS&&JUMP.EXE");
	system("pause");
	return 0;
}
