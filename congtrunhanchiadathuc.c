#include"tonghieutichthuong.h"

int main(){
	char chuoiDaThuc1[MAX] = "";
	int daThuc1[MAX] = {0};
	int bac1;
	nhapChuoiVaChuyenVeDaThuc(chuoiDaThuc1, daThuc1, &bac1);
	printf("da thuc 1 la: ");
	xuatDaThuc(daThuc1, bac1);
	printf("\n");
	
	fflush(stdin); 
	char chuoiDaThuc2[MAX] = "";
	int daThuc2[MAX] = {0};
	int bac2;
	nhapChuoiVaChuyenVeDaThuc(chuoiDaThuc2, daThuc2, &bac2);
	printf("da thuc 2 la: ");
	xuatDaThuc(daThuc2, bac2);
	printf("\n");
	
	//phan thuc hien cac phep tinh.
	int bac;
	int daThuc[MAX] = {0};
	
	int bacDu;
	double daThucDu[MAX] = {0};
	
	int bacDouble;
	double daThucDouble[MAX] = {0};
	
	printf("\ntong da thuc 1 va 2 vua nhap vao la: ");
	tongDaThuc(daThuc1, bac1, daThuc2, bac2, daThuc, &bac);
	xuatDaThuc(daThuc, bac);
	
	printf("\nhieu da thuc 1 cho 2 vua nhap vao la: ");
	hieuDaThuc(daThuc1, bac1, daThuc2, bac2, daThuc, &bac);
	xuatDaThuc(daThuc, bac);
	
	printf("\ntich hai da thuc vua nhap vao la: ");
	tichDaThuc(daThuc1, bac1, daThuc2, bac2, daThuc, &bac);
	xuatDaThuc(daThuc, bac);
	
	if(kiemTraDaThucKhong(daThuc2, bac2)){
		printf("\nkhong the chia hai da thuc vi da thuc 2 bang 0.");
	}
	else{
		thuongDaThuc(daThuc1, bac1, daThuc2, bac2, daThucDouble, &bacDouble, daThucDu, &bacDu);
		printf("\nthuong cua da thuc 1 cho da thuc 2 vua nhap vao la: ");
		xuatDaThucKieuDouble(daThucDouble, bacDouble);
		printf("\ndu cua da thuc 1 cho da thuc 2 vua nhap vao la: ");
		xuatDaThucKieuDouble(daThucDu, bacDu);
	}

	return 0;
}
