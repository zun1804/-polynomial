#include"tonghieutichthuong.h"


void nhapXuatChuoiDaThuc(char chuoiDaThuc[]){
	printf("nhap vao chuoi da thuc: "); 
	scanf("%[^\n]s", chuoiDaThuc);
	printf("chuoi sau khi nhap: %s\n", chuoiDaThuc);
}

void chuyenChuoiVeDangMacDinh(char chuoiDaThuc[]){
	int length = strlen(chuoiDaThuc);
	int i = 0;
	for(; i < length; i++){
		if(chuoiDaThuc[i] == 'x'){
			chuoiDaThuc[i] -= 32;
		}
	}
} 

void xoaMotKyTu(char chuoiDaThuc[], int vitri){
	int chieuDaiDaThuc = strlen(chuoiDaThuc);
	
	int i = vitri;
	for(; i < (chieuDaiDaThuc - 1); i++){
		chuoiDaThuc[i] = chuoiDaThuc[i + 1];
	}
	//them vao ki tu ket thuc chuoi la '\0'
	chuoiDaThuc[chieuDaiDaThuc - 1] = '\0';
}

void xoaKhoangTrang(char chuoiDaThuc[]){
	int i = 0;
	for(; i < strlen(chuoiDaThuc); i++){
		if(chuoiDaThuc[i] == ' '){
			xoaMotKyTu(chuoiDaThuc, i);
			i--;
		}
	}
}

void themMotKyTu(char chuoiDaThuc[], int viTriThem, char phanTuThem){
	int chieuDaiDaThuc = strlen(chuoiDaThuc);
	
	int i = chieuDaiDaThuc - 1;
	for(; i >= viTriThem; i--){
		chuoiDaThuc[i + 1] = chuoiDaThuc[i];
	}
	chuoiDaThuc[viTriThem] = phanTuThem;
	chuoiDaThuc[chieuDaiDaThuc + 1] = '\0';
} 

int kiemTraDeThemMuKhong(char chuoiDaThuc[], int viTriXet){
	//tu vi tri phan tu dang xet, xet duyet nguoc vao cac phan tu phia truoc.
	int i = viTriXet;
	//dk neu nhu phan tu tai i van la so thi tiep tuc vong lap.
	while(((int)chuoiDaThuc[i] >= 48) && ((int)chuoiDaThuc[i] <= 57)){
		i--;
	}
	if(chuoiDaThuc[i] == '+' || chuoiDaThuc[i] == '-'){
		return 1;
	}
	else{
		return 0; 
	} 
}

void daThucStupid(char chuoiDaThuc[]){
	int chieuDaiDaThuc = strlen(chuoiDaThuc);
	
	int i = 0;
	int chieuDaiDaThucMoi = chieuDaiDaThuc;
	for(; i < chieuDaiDaThucMoi; i++){
		//xet dk da thuc co dang: ...+aX-... || ...+aX || ...-aX+... || ...-aX 
		if((chuoiDaThuc[i] == 'X' && (chuoiDaThuc[i + 1] == '+' || chuoiDaThuc[i + 1] == '-')) || (chuoiDaThuc[i] == 'X' && chuoiDaThuc[i + 1] == '\0')){
			themMotKyTu(chuoiDaThuc, (i + 1), '^');
			themMotKyTu(chuoiDaThuc, (i + 2), '1');
			//vi da them hai ki tu "^1" nen phai cong i them 2 de ko xet nhung phan tu vua them vao
			i += 2; 
			//vi them hai ki tu nen chieu dai chuoi cung tang len hai.
		    chieuDaiDaThucMoi += 2;
		}
	}
	
	//them dau cong vao dau vs dk heso dau tien duong.
	if(chuoiDaThuc[0] != '-'){
		themMotKyTu(chuoiDaThuc, 0, '+');
	    chieuDaiDaThucMoi++;
	}
	
	i = 0;
	for(; i < chieuDaiDaThucMoi; i++){
		if(chuoiDaThuc[i] >= '0' && chuoiDaThuc[i] <= '9' && (chuoiDaThuc[i + 1] == '+' || chuoiDaThuc[i + 1] == '-' || chuoiDaThuc[i + 1] == '\0')){
			//vi tu dong 80 -> 83 chung ta da them dau cong vao dau chuoi, nen chuoi neu chi la so 1,
			// no se tro thanh +1 => du dk de kiem tra dk if phia duoi.
			if(kiemTraDeThemMuKhong(chuoiDaThuc, i)){
				themMotKyTu(chuoiDaThuc, (i + 1), 'X');
				themMotKyTu(chuoiDaThuc, (i + 2), '^');
				themMotKyTu(chuoiDaThuc, (i + 3), '0');
				i += 3; 
			    chieuDaiDaThucMoi += 3;
			}
		}
	}
	
	//vi se co truong hop chuoi co dang +X => hso la 1 nen them vao chuoi cho de dang lay ra heso.
	int j = 0;
	for(; j < chieuDaiDaThucMoi; j++){
		if((chuoiDaThuc[j] == '-' || chuoiDaThuc[j] == '+') && (chuoiDaThuc[j + 1] == 'X')){
			themMotKyTu(chuoiDaThuc, (j + 1), '1');
			j++;
			chieuDaiDaThucMoi++;
		}
	}
}

void chuanHoaChuoi(char chuoiDaThuc[]){
	xoaKhoangTrang(chuoiDaThuc);
	daThucStupid(chuoiDaThuc);
}

//sau khi da co chuoi dang stupid nhat. 
int chuyenChuoiThanhSo(char chuoi[]){
	int soTraVe = 0;
	int length = strlen(chuoi);
	
	int i = 0;
	for(; i < length; i++){
		soTraVe = soTraVe * 10 + ((int)chuoi[i] - 48);
	}
	return soTraVe;
}

void mangTam(char chuoi[], int mangTam[], int *chieuDaiMang){
	char *p, *q;
    p=chuoi;
    
    int temp = 0;
    while(q=strtok(p,"X^+-")){
        p=NULL;
        mangTam[temp++] = chuyenChuoiThanhSo(q);
    }
    (*chieuDaiMang) = temp;
} 

//mang tam bay gio se co tinh chat: phan tu tai chi so chan la he so cua da thuc, tai chi so le la so mu tuong ung vs he so trong da thuc.
int bacLonNhatCuaDaThuc(int mangTam[], int chieuDaiMang){
	int max = 0;
	//xet duyet tat ca cac chi so le de lay ra duoc so mu cao nhat.
	int i = 1;
	for(; i < chieuDaiMang; i+= 2){
		max = max < mangTam[i] ? mangTam[i] : max;
	}
	return max;
}

//da thuc co dang: aX^(heso1)+ bX^*heso2)+... => nhan thay he so nam giua ky tu '^' va '+'
// => tim vi tri dau mu va dau cong de xuat ra duoc so mu chua he so am can tim.
int timDauMu(char chuoi[], int viTriBatDau){
	int length = strlen(chuoi);
	
	int i = (viTriBatDau + 1);
	for(; i < length; i++){
		if(chuoi[i] == '^'){
			//gap ky tu '^' dau tien lap tuc tra ve vi tri do.
			return i;
		}
	}
}

int timDauCongHoacTru(char chuoi[], int viTriBatDau){
	int length = strlen(chuoi);
	
	int i = (viTriBatDau + 1);
	for(; i < length; i++){
		if(chuoi[i] == '+' || chuoi[i] == '-'){
			//gap ky tu '+' hoac '-' dau tien lap tuc tra ve vi tri do.
			return i;
		}
	}
}

void timViTriHeSoChuaDauTru(char chuoi[], int mangViTri[], int *chieuDai) {
	int length = strlen(chuoi);
	
	int duyetmang = 0;
	int i = 0;
	for(; i < length; i++){
		//xet tai phan tu chua ky tu '-'
		if(chuoi[i] == '-'){
			int viTriMu = timDauMu(chuoi, i);
			int viTriCongHoacTru = timDauCongHoacTru(chuoi, i); 
			
			char chuoiTam[MAX] = "";
			int temp = 0;
			//vi he so nam giua ky tu '^' va ky tu '+' hoac '-' nen vi tri ngay sau viTriMu se la noi bat dau va vi tri ngay truoc viTriCongHoacTru 
			//se la vi tri ket thuc.
			int flag = viTriMu + 1;
			for(; flag < viTriCongHoacTru; flag++){
				chuoiTam[temp++] = chuoi[flag];
			}
			chuoiTam[temp] = '\0';//ky tu ket thuc chuoi.
			mangViTri[duyetmang++] = chuyenChuoiThanhSo(chuoiTam);
		}
	}
	(*chieuDai) = duyetmang;
}

//mangViTri chua cac so mu co he so phia truoc am.
int kiemTraHeSoAm(int heso, int mangViTri[], int chieuDai){
	int i = 0;
	for(; i < chieuDai; i++){
		if(heso == mangViTri[i]){
			return 1;
		}
	}
	return 0;
}

void daThucChuan(int mangTam[], int chieuDaiMang, int daThuc[], int *bacDaThuc, int mangViTri[], int chieuDai){
	(*bacDaThuc) = bacLonNhatCuaDaThuc(mangTam, chieuDaiMang);
	int j = 1;
	for(; j < chieuDaiMang; j+= 2){
		if(kiemTraHeSoAm(mangTam[j], mangViTri, chieuDai)){
			daThuc[(*bacDaThuc) - (mangTam[j])] = -mangTam[j - 1];
		}
		else{
			daThuc[(*bacDaThuc) - (mangTam[j])] = mangTam[j - 1];
		}
	}
}

void chuyenChuoiThanhMang(char chuoi[], int daThuc[], int *bac){
	int mangViTri[MAX] = {0};
	int chieuDai;
	timViTriHeSoChuaDauTru(chuoi, mangViTri, &chieuDai);
    
	int mangTam1[MAX] = {0};
	int chieuDaiMang1;
	mangTam(chuoi, mangTam1, &chieuDaiMang1);
	daThucChuan(mangTam1, chieuDaiMang1, daThuc, bac, mangViTri, chieuDai);
}

void nhapChuoiVaChuyenVeDaThuc(char chuoi[], int daThuc[], int *bac){
	nhapXuatChuoiDaThuc(chuoi);
	chuyenChuoiVeDangMacDinh(chuoi);
	chuanHoaChuoi(chuoi);
	chuyenChuoiThanhMang(chuoi, daThuc, bac);
}

//xuat da thuc.
int kiemTraDaThucKhong(int daThuc[], int bacDaThuc){
	int m = 0;
	for(; m <= bacDaThuc; m++){
		if(daThuc[m]){
			return 0;
		}
	}
	return 1;
}

void xuatDaThuc(int daThuc[], int bacDaThuc){
	if(kiemTraDaThucKhong(daThuc, bacDaThuc)){
		printf("0");
	}
	else{
		int m = 0;
		for(; m  <= bacDaThuc; m++){
			//neu he so tai do bang 0 thi bo qua.
			if(!(daThuc[m])){
				continue;
			}
			else{
				//xet he so dau tien
				if((!m)){
					//neu da thuc la 1 hang so
					if(!(bacDaThuc - m)){
						printf("%d", daThuc[m]);
					}
					//neu da thuc co dang aX + b
					else if((bacDaThuc - m) == 1){
						if(daThuc[m] == 1){
							printf("X");
						}
						else if(daThuc[m] == -1){
							printf("-X");
						}
						else{
							printf("%dX", daThuc[m]);
						}
					}
					//neu da thuc co bac lon hon 1.
					else{
					    if(daThuc[m] == 1){
							printf("X^%d", (bacDaThuc - m));
						}
						else if(daThuc[m] == -1){
							printf("-X^%d", (bacDaThuc - m));
						}
						else{
							printf("%dX^%d", daThuc[m], (bacDaThuc - m));
						}
					}
				}
				//xet he so cua x mu 1.
				else if(m == (bacDaThuc - 1)){
					if(daThuc[m] == 1){
						printf("+X");
					}
					else if(daThuc[m] == -1){
						printf("-X");
					}
					else if(daThuc[m] > 0){
						printf("+%dX", daThuc[m]);
					}
					else{
						printf("%dX", daThuc[m]);
					}
				}
				//xet he so cua x mu 0.
				else if(m == bacDaThuc){
					if(daThuc[m] > 0){
						printf("+%d", daThuc[m]);
					}
					else{
						printf("%d", daThuc[m]);
					}
				}
				//xet ca he so con lai.
				else{
					if(daThuc[m] == 1){
						printf("+X^%d", (bacDaThuc - m));
					}
					else if(daThuc[m] == -1){
						printf("-X^%d", (bacDaThuc - m));
					}
					else if(daThuc[m] > 0){
						printf("+%dX^%d", daThuc[m], (bacDaThuc - m));
					}
					else{
						printf("%dX^%d", daThuc[m], (bacDaThuc - m));
					}
				}
			}
		}
	}
}

int timSoLonHon(int a, int b){
	return (a < b) ? b : a;
}

int timSoBeHon(int a, int b){
	return (a < b) ? a : b;
}

void tongDaThuc(int daThuc1[], int bac1, int daThuc2[], int bac2, int daThuc[], int *bac){
	int max = timSoLonHon(bac1, bac2);
	int min = timSoBeHon(bac1, bac2);
	int hieuBacDaThuc = max - min;
	(*bac) = max;
	
	//bac lon hon la bac1
	if(!(max - bac1)){
		int i = 0;
		for(; i <= max; i++){
			if(i < hieuBacDaThuc){
				daThuc[i] = daThuc1[i];
			}
			else{
				daThuc[i] = daThuc1[i] + daThuc2[i - hieuBacDaThuc];
			}
		}
	} 
	//bac lon hon la bac2
	else{
		int i = 0;
		for(; i <= max; i++){
			if(i < hieuBacDaThuc){
				daThuc[i] = daThuc2[i];
			}
			else{
				daThuc[i] = daThuc2[i] + daThuc1[i - hieuBacDaThuc];
			}
		}
	}
}

void hieuDaThuc(int daThuc1[], int bac1, int daThuc2[], int bac2, int daThuc[], int *bac){
	int max = timSoLonHon(bac1, bac2);
	int min = timSoBeHon(bac1, bac2);
	int hieuBacDaThuc = max - min;
	(*bac) = max;
	
	//bac lon hon la bac 1
	if(!(max - bac1)){
		int i = 0;
		for(; i <= max; i++){
			if(i < hieuBacDaThuc){
				daThuc[i] = daThuc1[i];
			}
			else{
				daThuc[i] = daThuc1[i] - daThuc2[i - hieuBacDaThuc];
			}
		}
	} 
	//bac lon hon la bac 2
	else{
		int i = 0;
		for(; i <= max; i++){
			if(i < hieuBacDaThuc){
				daThuc[i] = -daThuc2[i];
			}
			else{
				daThuc[i] = -daThuc2[i] + daThuc1[i - hieuBacDaThuc];
			}
		}
	}
}

void tichDaThuc(int daThuc1[], int bac1, int daThuc2[], int bac2, int daThuc[], int *bac){
	(*bac) = bac1 + bac2;
	int i = 0; 
	for(; i <= (*bac); i++){
		daThuc[i] = 0;
		int j = 0; 
		for(; j <= bac1; j++){
			int k = 0;
			for(; k <= bac2; k++){
				//((bac1 - j) + (bac2 - k)) == ((*bac) - i)  => j + k = i;
				if((j + k) == i){
					daThuc[i] += daThuc1[j] * daThuc2[k];
				}
			}
		}
	}
}

int kiemTraDaThucKhongKieuDouble(double daThuc[], int bacDaThuc){
	int m = 0;
	for(; m <= bacDaThuc; m++){
		if(daThuc[m]){
			return 0;
		}
	}
	return 1;
}

void xuatDaThucKieuDouble(double daThuc[], int bacDaThuc){
	if(kiemTraDaThucKhongKieuDouble(daThuc, bacDaThuc)){
		printf("0");
	}
	else{
		int m = 0;
		for(; m  <= bacDaThuc; m++){
			if(!(daThuc[m])){
				continue;
			}
			else{
				//xet he so dau tien
				if((!m)){
					//neu da thuc la bac 0.
					if(!(bacDaThuc - m)){
						printf("%lf", daThuc[m]);
					}
					else if((bacDaThuc - m) == 1){
						if(daThuc[m] == 1){
							printf("X");
						}
						else if(daThuc[m] == -1){
							printf("-X");
						}
						else{
							printf("%lfX", daThuc[m]);
						}
					}
					//neu da thuc co bac khac 0.
					else{
					    if(daThuc[m] == 1){
							printf("X^%d", (bacDaThuc - m));
						}
						else if(daThuc[m] == -1){
							printf("-X^%d", (bacDaThuc - m));
						}
						else{
							printf("%lfX^%d", daThuc[m], (bacDaThuc - m));
						}
					}
				}
				//xet he so cua x mu 1.
				else if(m == (bacDaThuc - 1)){
					if(daThuc[m] == 1){
						printf("+X");
					}
					else if(daThuc[m] == -1){
						printf("-X");
					}
					else if(daThuc[m] > 0){
						printf("+%lfX", daThuc[m]);
					}
					else{
						printf("%lfX", daThuc[m]);
					}
				}
				//xet he so cua x mu 0.
				else if(m == bacDaThuc){
					if(daThuc[m] > 0){
						printf("+%lf", daThuc[m]);
					}
					else{
						printf("%lf", daThuc[m]);
					}
				}
				//xet ca he so con lai.
				else{
					if(daThuc[m] == 1){
						printf("+X^%d", (bacDaThuc - m));
					}
					else if(daThuc[m] == -1){
						printf("-X^%d", (bacDaThuc - m));
					}
					else if(daThuc[m] > 0){
						printf("+%lfX^%d", daThuc[m], (bacDaThuc - m));
					}
					else{
						printf("%lfX^%d", daThuc[m], (bacDaThuc - m));
					}
				}
			}
		}
	}
}

void haiDaThucBangNhauKhauKieuDuLieu(int daThuc1[], int bac1, double daThuc2[], int *bac2){
	(*bac2) = bac1;
	int i = 0; 
	for(; i <= bac1; i++){
		daThuc2[i] = (double)daThuc1[i];
	}
}

void hieuDaThucKhacKieuDuLieu(double daThuc1[], int bac1, double daThuc2[], int bac2, double daThuc[], int *bac){
	int max = timSoLonHon(bac1, bac2);
	int min = timSoBeHon(bac1, bac2);
	int hieuBacDaThuc = max - min;
	(*bac) = max;
	
	//bac lon hon la bac 1
	if(!(max - bac1)){
		//max = bac1;
		int i = 0;
		for(; i <= max; i++){
			if(i < hieuBacDaThuc){
				daThuc[i] = daThuc1[i];
			}
			else{
				daThuc[i] = daThuc1[i] - daThuc2[i - hieuBacDaThuc];
			}
		}
	} 
	//bac lon hon la bac 2
	else{
		//max = bac2;
		int i = 0;
		for(; i <= max; i++){
			if(i < hieuBacDaThuc){
				daThuc[i] = -daThuc2[i];
			}
			else{
				daThuc[i] = -daThuc2[i] + daThuc1[i - hieuBacDaThuc];
			}
		}
	}
}

void tichDaThucKhacKieuDuLieu(int daThuc1[], int bac1, double daThuc2[], int bac2, double daThuc[], int *bac){
	(*bac) = bac1 + bac2;
	int i = 0; 
	for(; i <= (*bac); i++){
		daThuc[i] = 0;
		int j = 0; 
		for(; j <= bac1; j++){
			int k = 0;
			for(; k <= bac2; k++){
				//((bac1 - j) + (bac2 - k)) == ((*bac) - i)  => j + k = i;
				if((j + k) == i){
					daThuc[i] += daThuc1[j] * daThuc2[k];
				}
			}
		}
	}
}

void thuongDaThuc(int daThuc1[], int bac1, int daThuc2[], int bac2, double daThuc[],
 int *bac, double daThucTam[], int *bacDaThucTam){
	//xem nhu da thuc 1 la da thuc bi chia, va da thuc 2 la da thuc chia.
	if(bac1 < bac2){
		(*bac) = 0;
		daThuc[(*bac)] = 0;
		haiDaThucBangNhauKhauKieuDuLieu(daThuc1, bac1, daThucTam, bacDaThucTam);
	} 
	else{
		(*bac) = bac1 - bac2;	
		//cho daThucTam = daThuc1 tranh viec sau nay dung lai daThuc1 thi ko co!
		haiDaThucBangNhauKhauKieuDuLieu(daThuc1, bac1, daThucTam, bacDaThucTam);
	
		double temp[MAX] = {0};
		int bacTam;	
		int j = 0;//xet da thuc ket qua tu vi tri 0.
		int flag = 0;//xet he so de chia tu vi tri flag.
		int dk = (*bacDaThucTam);
		
		while(dk >= bac2){
			double donThuc[MAX] = {0};
			int bacDonThuc = dk- bac2;
			
			donThuc[0] = daThucTam[flag++]/daThuc2[0];
			daThuc[j++] = donThuc[0];
			
			tichDaThucKhacKieuDuLieu(daThuc2, bac2, donThuc, bacDonThuc, temp, &bacTam);
			hieuDaThucKhacKieuDuLieu(daThucTam, (*bacDaThucTam), temp, bacTam, daThucTam, bacDaThucTam);

			(dk)--;
		}
	}
}
