#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

struct monHoc
{
    string tmh;
    float diem;
};

struct sinhVien
{
    string hoten;
    vector<monHoc> ds_mh; // mảng 1 chiều các môn học của 1 sinh viên
};


void doc_sv(ifstream &fileIn, sinhVien &sv) {
    fileIn.ignore();
    getline(fileIn, sv.hoten);
}

void doc_mh(ifstream &fileIn, monHoc &mh) {
    fileIn.ignore();
    getline(fileIn, mh.tmh,'-');
    fileIn>>mh.diem;
}

void docFile(ifstream &fileIn, vector<sinhVien> &ds_sv) {
    int m;
    fileIn>>m; // đọc số lượng môn học
    while(!fileIn.eof()) {
        sinhVien sv; // khai báo sinh viên nhận dữ liệu từ file về
        doc_sv(fileIn, sv);
        for(int i = 0; i < m; i++) {
            monHoc mh; // khai báo môn học nhận dữ liệu từ file về
            doc_mh(fileIn, mh);
            sv.ds_mh.push_back(mh);
        }
        ds_sv.push_back(sv);
    }
}

void xuat_SV(sinhVien sv) {
    cout<<"\nHọ tên : "<<sv.hoten<<endl;
}

void xuat_MH(monHoc mh) {
    cout<<"\nTên môn học : "<<mh.tmh;
    cout<<"\nĐiểm : "<<mh.diem;
}

void xuat_TT(vector<sinhVien> ds) {
    for(int i = 0; i < ds.size(); i++) {
        cout<<"\t\tSinh viên thứ "<<i+1<<endl;
        xuat_SV(ds[i]);
        cout<<"\tDANH SÁCH MÔN HỌC TƯƠNG ỨNG";
        for(int j = 0; j < ds[i].ds_mh.size(); j++) {
            xuat_MH(ds[i].ds_mh[j]);
        }
        cout<<"\n";
    }
}

// hàm đếm số lượng môn học có điểm dưới 5.5
void dem(vector<sinhVien> &ds) {
    for(int i = 0; i < ds.size(); i++) {
        int count = 0;
        for(int j = 0; j < ds[i].ds_mh.size(); j++) {
            if(ds[i].ds_mh[j].diem < 5.5) {
                count++;
            }
        }
        cout<<"Số môn học có điểm dưới 5.5 của sinh viên "<<ds[i].hoten<<" là : "<<count<<endl;
    }
}

void doc_Sl(ofstream &fileOut, vector<sinhVien> ds) {
    for(int i = 0; i < ds.size(); i++) {
        fileOut<<ds[i].ds_mh.size()<<endl;
        break;
    }
}
void ghi_TT_SV(ofstream &fileOut, sinhVien sv) {
    fileOut<<sv.hoten<<endl;
}

void ghi_TT_MH(ofstream &fileOut, monHoc mh) {
    fileOut<<mh.tmh<<"-"<<mh.diem;
}

void ghiFile(ofstream &fileOut, vector<sinhVien> ds) {
    for(int i = 0; i < ds.size(); i++) {
       ghi_TT_SV(fileOut, ds[i]);
        for(int j = 0; j < ds[i].ds_mh.size(); j++) {
            ghi_TT_MH(fileOut, ds[i].ds_mh[j]);
            fileOut<<"\n";
        }
    }
}

void ghi_SLMH(ofstream &fileOut, vector<sinhVien> ds) {
    for(int i = 0; i < ds.size(); i++) {
        int count = 0;
        for(int j = 0; j < ds[i].ds_mh.size(); j++) {
            if(ds[i].ds_mh[j].diem < 5.5) {
                count++;
            }
        }
        fileOut<<"Số môn học có điểm dưới 5.5 của sinh viên "<<ds[i].hoten<<" là : "<<count<<endl;
    }
}

int main() {
    ifstream fileIn;
    vector<sinhVien> ds_sinhvien;
    monHoc mh;
    fileIn.open("C:\\Users\\tiens\\Desktop\\input2.TXT", ios_base::in);
    if(fileIn.fail() == true) {
        cout<<"\nFile khong ton tai";
    }
    docFile(fileIn, ds_sinhvien);
    xuat_TT(ds_sinhvien);
    dem(ds_sinhvien);
    fileIn.close();
    ofstream fileOut;
    fileOut.open("C:\\Users\\tiens\\Desktop\\output2.TXT", ios_base::out);
    doc_Sl(fileOut, ds_sinhvien);
    ghiFile(fileOut, ds_sinhvien);
    ghi_SLMH(fileOut, ds_sinhvien);
    fileOut.close();
    return 0;
}
