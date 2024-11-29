#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    // Dosyayi hem yazma (out) hem de okuma (in) modunda ac
    fstream myFile("userinput.txt", ios::out | ios::in);
    string output;

    // Dosyanin acilip acilmadigini anlamak icin kontrol
    if (myFile.is_open()) {
        string text;
        
        //Kullaniciden metni al
        cout << "Enter the text you want to write to the file:\n";
        getline(cin, text);

        // metni dosyaya yaz
        myFile << text;
        cout << "The text has been written to the file.\n";

        //okuma islemi icin imleci dosyanin basina al
        myFile.clear();               // Dosya durum bayragini temizler
        myFile.seekg(0, ios::beg);    // Dosya imlecini dosya basina alir

        // Dosyadan satir satir okuyup ekrana yazdir
        while (getline(myFile, output)) {
            cout << output << endl;
        }

        // Dosyayi kapatmayi unutma
        myFile.close();
    }
    else {
        // Dosya acilamazsa hata mesaji ver
        cout << "File could not be opened!";
    }

    return 0;
}
