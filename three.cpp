#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct SV
{
    string hoten;
    float diem[60];
};

void docFIle(ifstream &fileIn, SV sv[], int m) {
    while(!fileIn.eof())  {
        for(int i = 0; i < m; i++) {
            fileIn.ignore();
            getline(fileIn, sv[i].hoten);
            for(int j = 0; j < m; j++) {
                fileIn>>sv[i].diem[j];
            }
        }
    }
}

void dem(SV sv[], int m) {
    for(int i = 0; i < m; i++) {
        int count = 0;
        for(int j = 0; j < m; j++) {
            if(sv[i].diem[j] < 5.5) {
                count++;
            }
        }
        cout<<"\nSố môn học có điểm dưới 5.5 của sinh viên "<<sv[i].hoten<<" là : "<<count;
    }
}
void xuat(SV &sv) {
    cout<<sv.hoten<<endl;
}
void xuat_DS(SV ds[], int m) {
    for(int i = 0; i < m; i++) {
        xuat(ds[i]);
        for(int j = 0; j < m; j++) {
            cout<<ds[i].diem[j]<<" ";
        }
        cout<<"\n";
    }
}

void ghiFile(ofstream &fileOut, SV sv[], int m) {
    for(int i = 0; i < m; i++) {
        fileOut<<sv[i].hoten<<endl;
        for(int j = 0; j < m; j++) {
            fileOut<<sv[i].diem[j]<<" ";
        }
        fileOut<<endl;
    }
}

void dem1(ofstream &fileOut, SV sv[], int m) {
    
    for(int i = 0; i < m; i++) {
        int count = 0;
        for(int j = 0; j < m; j++) {
            if(sv[i].diem[j] < 5.5) {
                count++;
            }
        }
        fileOut<<"\nSố môn học có điểm dưới 5.5 của sinh viên "<<sv[i].hoten<<" là : "<<count;
    }
}

int main() {
    SV ds_sv[100];
    ifstream fileIn;
    fileIn.open("C:\\Users\\tiens\\Desktop\\input.TXT", ios_base::in);
    if(fileIn.fail() == true) {
        cout<<"\nKhong tim thay file!";
    }
    int m;
    fileIn>>m;
    docFIle(fileIn, ds_sv, m);
    cout<<"\nDoc file thành công";
    xuat_DS(ds_sv, m);
    dem(ds_sv, m);
    fileIn.close();
    ofstream fileOut;
    fileOut.open("C:\\Users\\tiens\\Desktop\\output.TXT", ios_base::out);
    ghiFile(fileOut, ds_sv, m);
    dem1(fileOut, ds_sv, m);
    cout<<"\nGhi file thành công";
}