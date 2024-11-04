#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void WriteToFile(const string& data) {
    ofstream file("file.txt", ios::app);
    if (!file.is_open()) {
        cerr << "Failed to open file for writing!" << endl;
        return;
    }

    file << data << endl;
    cout << "Data written to file: " << data << endl;

    file.close();
}

int main()
{
    HANDLE hMutex = CreateMutex(NULL, FALSE, L"Text by Mutex");
    if (hMutex == NULL)
    {
        cerr << "Failed! Error: " << GetLastError() << endl;
        return 1;
    }

    cout << "Successfull!" << endl;
    WriteToFile("Hello!");
    CloseHandle(hMutex);

	return 0;
}