#include<iostream>
#include<fstream>

using namespace std;

int main() {
    ifstream fileIn;
    string s;
    string line;

    fileIn.open("C:\\Users\\tiens\\Desktop\\two.TXT", ios_base::in);
    if(fileIn.fail() == true) {
        cout<<"\nKhong tim thay file";
    }

    int count = 0;
    while (!fileIn.eof()) {
        getline(fileIn, line);
        if(line == "") break;
		s += line;
        count++;
	}

    fileIn.close();
    cout<<"\nCác tỉnh/thành vừa đọc từ file nè : ";
    cout<<s;
    cout<<"\n\nCó "<<count<<" tỉnh/thành trong file";
    return 0;
} 
