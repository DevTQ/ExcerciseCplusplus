#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct SV
{
    string hoten;
    float diem[60];
};

void docFIle(ifstream &fileIn, SV sv[], int n) {
    while(!fileIn.eof())  {
        for(int i = 0; i < n; i++) {
            fileIn.ignore();
            getline(fileIn, sv[i].hoten);
            for(int j = 0; j < n; j++) {
                fileIn>>sv[i].diem[j];
            }
        }
    }
}

void nhap(SV &sv) {
    cin.ignore();
    cout<<"\nNhập họ tên : ";
    getline(cin,sv.hoten);
}

void Nhap_DS(SV sv[], int n, int m) {
    for(int i = 0; i < n; i++) {
        nhap(sv[i]);
        for(int j = 0; j < m; j++) {
            cout<<"\nđiểm : ";
            cin>>sv[i].diem[j];
        }
    }
}

void ghiFile(ofstream &fileOut, SV sv[], int n, int m) {
    for(int i = 0; i < n; i++) {
        fileOut<<sv[i].hoten<<endl;
        for(int j = 0; j < m; j++) {
            fileOut<<sv[i].diem[j]<<" ";
        }
        fileOut<<endl;
    }
}

int main() {
    SV sv[100];
    ifstream fileIn;
    fileIn.open("C:\\Users\\tiens\\Desktop\\four.TXT", ios_base::in);
    if(fileIn.fail() == true) {
        cout<<"\nKhong tim thay file!";
    }
    int n;
    cout<<"\nNhập số lượng sinh viên : ";
    cin>>n; 
    int m;
    fileIn>>m;
    Nhap_DS(sv, n, m);
    fileIn.close();
    ofstream fileOut;
    fileOut.open("C:\\Users\\tiens\\Desktop\\four.TXT", ios_base::app);
    fileOut<<m<<endl;
    ghiFile(fileOut, sv, n, m);
    cout<<"\nGhi file thành công";
    return 0;
}
