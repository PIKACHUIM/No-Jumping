#include <iostream>
#include <windows.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	HWND WINS_TIDP;
	WINS_TIDP=FindWindow("ConsoleWindowClass",NULL);	//���������ڵ���������
	ShowWindow(WINS_TIDP,SW_HIDE);				        //����ָ�����ڵ���ʾ״̬
	system("CD BINS&&JUMP.EXE");
	system("pause");
	return 0;
}
