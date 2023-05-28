#include<iostream>
#include<fstream>

using namespace std;

int main() {
    int a[100][100];
    int n, m;
    ifstream fileIn;
    fileIn.open("C:\\Users\\tiens\\Desktop\\one.TXT", ios_base::in);
    if(fileIn.fail() == true) {
		cout<<"\nKhong tim thay file";
        return -1;
    }
    fileIn>>n;
    fileIn>>m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            fileIn>>a[i][j];
        }
    }

    cout<<"\nMảng sau khi đọc từ file"<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    fileIn.close();
    return 0;
}