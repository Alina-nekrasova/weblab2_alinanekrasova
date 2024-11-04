#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void ReadFromFile() {
    ifstream file("file.txt");
    if (!file.is_open()) {
        cerr << "Failed to open file for reading!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        cout << "Data read from file: " << line << endl;
    }

    file.close();
}

int main()
{
    HANDLE hMutex = OpenMutex(SYNCHRONIZE, FALSE, L"Text by Mutex");
    if (hMutex == NULL)
    {
        cerr << "Failed! Error: " << GetLastError() << endl;
        return 1;
    }

    cout << "Successfull!" << endl;
    ReadFromFile();
    CloseHandle(hMutex);
	return 0;
}