#include<stdio.h>
#include<time.h>
#include<string.h>
#define MAX 100

//NHAP DA THUC DANG CHUOI THEO DINH DANG: X^N + a1X^(N-1) + ...
void nhapXuatChuoiDaThuc(char chuoiDaThuc[]);

void chuyenChuoiVeDangMacDinh(char chuoiDaThuc[]);

void xoaMotKyTu(char chuoiDaThuc[], int vitri);

void xoaKhoangTrang(char chuoiDaThuc[]);

void themMotKyTu(char chuoiDaThuc[], int viTrithem, char phanTuThem);

int kiemTraDeThemMuKhong(char chuoiDaThuc[], int viTriXet);

void daThucStupid(char chuoiDaThuc[]);

void chuanHoaChuoi(char chuoiDaThuc[]);

int chuyenChuoiThanhSo(char chuoi[]);

void mangTam(char chuoi[], int daThucTam[], int *chieuDaiMang);

int bacLonNhatCuaDaThuc(int mangTam[], int chieuDaiMang);

int timDauMu(char chuoi[], int viTriBatDau);

int timDauCongHoacTru(char chuoi[], int viTriBatDau);

void timViTriHeSoChuaDauTru(char chuoi[], int mangViTri[], int *chieuDai);

int kiemTraHeSoAm(int heso, int mangViTri[], int chieuDai);

void daThucChuan(int mangTam[], int chieuDaiMang, int daThuc[], int *bacDaThuc, int mangViTri[], int chieuDai);

void chuyenChuoiThanhMang(char chuoi[], int daThuc[], int *bac);

void nhapChuoiVaChuyenVeDaThuc(char chuoi[], int daThuc[], int *bac);

//PHAN THUC HIEN CAC PHEP TINH.
int kiemTraDaThucKhong(int daThuc[], int bacDaThuc);

void xuatDaThuc(int daThuc[], int bacDaThuc);

int timSoLonHon(int a, int b);

int timSoBeHon(int a, int b);

void tongDaThuc(int daThuc1[], int bac1, int daThuc2[], int bac2, int daThuc[], int *bac);

void hieuDaThuc(int daThuc1[], int bac1, int daThuc2[], int bac2, int daThuc[], int *bac);

void tichDaThuc(int daThuc1[], int bac1, int daThuc2[], int bac2, int daThuc[], int *bac);

//PHAN THUC HIEN PHEP CHIA.
int kiemTraDaThucKhongKieuDouble(double daThuc[], int bacDaThuc);

void xuatDaThucKieuDouble(double daThuc[], int bacDaThuc);

void haiDaThucBangNhauKhauKieuDuLieu(int daThuc1[], int bac1, double daThuc2[], int *bac2);

void hieuDaThucKhacKieuDuLieu(double daThuc1[], int bac1, double daThuc2[], int bac2, double daThuc[], int *bac);

void tichDaThucKhacKieuDuLieu(int daThuc1[], int bac1, double daThuc2[], int bac2, double daThuc[], int *bac);

void thuongDaThuc(int daThuc1[], int bac1, int daThuc2[], int bac2, double daThuc[], int *bac, double daThucTam[], int *bacDaThucTam);
