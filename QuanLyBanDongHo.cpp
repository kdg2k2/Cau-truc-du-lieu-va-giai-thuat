/*
Thiết lập dslk đơn quản lý việc bán đồng hồ của một đơn vị bán hàng
Với chức năng 
    -tìm kiếm
    -sắp xếp
    -thêm sp (trường hợp nhập thiếu)
    -xóa sp(trong trường hợp nhập thừa hoặc nhầm lẫn)
    - ...
Gồm các thông tin:  
    - Mã sản phẩm
    - hãng sản xuất
    - chất liệu(nhựa silicon-thép datao gỉ....)
    - Phong cách(học sinh sv-thể thao-văn phòng....)
    - giới tính(đồng hồ cho nam-nữ-trung tính...)
    - trọng lượng đồng hồ
    - ngày sản xuất
    - thời gian bảo hành
    - giá bán 

#####################################################################
#                                _`				                    #
#                             _ooOoo_				                #
#                            o8888888o				                #
#                            88" . "88				                #
#                            (| -_- |)				                #
#                            O\  =  /O				                #
#                         ____/`---'\____			        	    #
#                       .'  \\|     |//  `.			                #
#                      /  \\|||  :  |||//  \		        	    #
#                     /  _||||| -:- |||||_  \		        	    #
#                     |   | \\\  -  /'| |   |		        	    #
#                     | \_|  `\`---'//  |_/ |		        	    #
#                     \  .-\__ `-. -'__/-.  /		        	    #
#                   ___`. .'  /--.--\  `. .'___		        	    #
#                ."" '<  `.___\_<|>_/___.' _> \"".	    		    #
#               | | :  `- \`. ;`. _/; .'/ /  .' ; |	                #
#               \  \ `-.   \_\_`. _.'_/_/  -' _.' /	        	    #
#=================`-.`___`-.__\ \___  /__.-'_.'_.-'=================#
#                              `=--=-'
#           _.-/`)
#          // / / )
#       .=// / / / )
#      //`/ / / / /
#     // /     ` /
#    ||         /
#     \\       /
#      ))    .'
#     //    /
#          /
*/

#include<iostream>
#include<string>
using namespace std;

typedef struct DongHo
{
    string  hsp, clieu, pcach, gt;
    int tgbh, msp;
    float tl, tien;
    DongHo *next;
}DH;
typedef DH *List;

void KhoiTao(List &L);
void ThemDau(List &L, int msp, string hsp, string clieu, string pcach, string gt, int tgbh, float tl, float tien);
void ThemCuoi(List &L, int msp, string hsp, string clieu, string pcach, string gt, int tgbh, float tl, float tien);
void Them_Vtbk(List &L, int msp, string hsp, string clieu, string pcach, string gt, int tgbh, float tl, float tien);
void TaoDauDS(List &L);
void xoadau (List &L);
void xoacuoi(List &L);
void Xuat(List L);

int Empty (List L);
void TaoBatKi(List &L);
void Search_Msp(List L);
void Search_HangSp(List L);
void Search_GtSp(List L);
void Sort_TrongLuong(List &L);
void Sort_msp(List &L);
void LocHangTonKho (List &L, List &Y, List &X);
void NoiDsSauKhiLoc (List &Y, List &X, List &C);
float GiaTB(List L);
void Gia2tr(List L);
void Xoabatki(List &L);
void Sort_gia(List &L);

int main()
{
    List L,Y,X,C;
    KhoiTao(L);
    TaoDauDS(L);
    int luachon;
    do
    {
        cout << endl;
        system("pause");
        system("cls");
        cout << "\n ===========Menu============ \n";
        cout << "\n 1. Ktra DS rong hay ko";
        cout << "\n 2. Xuat ds";
        cout << "\n 3. Tim sp bang msp";
        cout << "\n 4. Tim sp theo hang";
        cout << "\n 5. Tim sp theo gioi tinh";
        cout << "\n 6. Loc hang ton kho";
        cout << "\n 7. Noi ds sau khi loc xong";  
        cout << "\n 8. Them 1 ptu vao vtbk";    
        cout << "\n 9. Sort_gia";
        cout << "\n 10. Sort_TrongLuong";
        cout << "\n 11. Sort_msp";
        cout << "\n 12. Cac Sp gia chi tu 2tr vnd";
        cout << "\n 13. Gia tien tb cua 1 chiec dong ho";
        cout << "\n 14. Xoa ptu bat ki";
        cout << endl;
        cout << "\n 15. Thoat";
        cout << endl;
        cout << "\n Lua chon: "; cin >> luachon;
        switch (luachon)
        {
            case 1:
                if(Empty(L))
                    cout << "\n DS rong!";  
                else    
                    cout << "\n Ds ko rong!";
                break;
            case 2:Xuat(L);break;
            case 3:Search_Msp(L);break;   
            case 4:Search_HangSp(L);break;
            case 5:Search_GtSp(L);break;   
            case 6:LocHangTonKho(L,Y,X);break;
            case 7:NoiDsSauKhiLoc(Y,X,C);break;
            case 8:TaoBatKi(L);break;
            case 9:Sort_gia(L);break;
            case 10:Sort_TrongLuong(L);break;  
            case 11:Sort_msp(L);break;
            case 12:Gia2tr(L);break;
            case 13:cout << "\n Gia trung binh cua 1 chiec dong ho: "<<GiaTB(L)<<"trieu vnd";break;
            case 14:Xoabatki(L);break;
            default:;break;
        }
    }while(luachon!=15);
    return 0;
}

void KhoiTao(List &L)
{
    L=NULL;
}

void ThemDau(List &L, int ma, string hang, string cl, string pc, string gtinh, int baohanh, float tlg, float gia)
{
    List Q = new DH;
    Q->msp = ma;
    Q->hsp=hang;
    Q->clieu=cl;
    Q->pcach=pc;
    Q->gt=gtinh;
    Q->tgbh = baohanh;
    Q->tl = tlg;
    Q->tien = gia;

    Q->next = L;
    L=Q;
}

void ThemCuoi(List &L, int ma, string hang, string cl, string pc, string gtinh, int baohanh, float tlg, float gia)
{
    List P=L;
	List Q = new DH;
	Q->msp = ma;
    Q->hsp=hang;
    Q->clieu=cl;
    Q->pcach=pc;
    Q->gt=gtinh;
    Q->tgbh = baohanh;
    Q->tl = tlg;
    Q->tien = gia;
	Q->next=NULL;
	
	if(L!=NULL)
	{
		while (P->next!=NULL)
		{
			P=P->next;
		}
		P->next=Q;
	}
	else
	{
		L=Q;
	}
}

void TaoDauDS(List &L)
{
    string  hsp, clieu, pcach, gt;
    int tgbh, msp;
    float tl, tien;

    int n;  cout << "\n Nhap so luong sp: "; cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cout << "\n Nhap sp thu "<< i+1 << ": ";
        
        cout << "\n Ma sp: ";		cin >> msp;
        fflush(stdin);
		cout << "\n Hang sp: "; 	getline(cin,hsp);
        fflush(stdin);
        cout << "\n Chat lieu: ";    getline(cin,clieu);
        fflush(stdin);
        cout << "\n Phong cach: ";      getline(cin,pcach);
        fflush(stdin);
		cout << "\n Gioi tinh: ";		getline(cin,gt);
		cout << "\n Thoi luong bao hanh (thang): "; 	cin >> tgbh;
		cout << "\n Trong luong (gam): "; 	cin >> tl;
		cout << "\n Gia tien (Trieu vnd): "; 	cin >> tien;
        cout << "\n";
        ThemDau(L, msp, hsp,clieu, pcach, gt, tgbh, tl, tien);
    }  
}

void Them_Vtbk(List &L, int ma, string hang, string cl, string pc, string gtinh, int baohanh, float tlg, float gia)
{
    List count=L;
    int dem=0;
    while (count != NULL)
    {
        dem++;
        count=count->next;
    }
    
    string  hsp, clieu, pcach, gt;
    int tgbh, msp,k;
    float tl, tien;

    List Q = new DH;
    Q->msp = ma;
    Q->hsp=hang;
    Q->clieu=cl;
    Q->pcach=pc;
    Q->gt=gtinh;
    Q->tgbh = baohanh;
    Q->tl = tlg;
    Q->tien = gia; 
 
    do{
        cout << "\n Chen vao vtri thu: ";
        cin>>k;
        if(k<1||k>dem+1)
        {
            cout << "\n Nhap vtri trong khoang [1,"<<dem+1<<"]: ";
            system("pause");
        }        
    }while(k<1||k>dem+1);

    if(k==1)
        ThemDau(L, ma, hang , cl, pc, gtinh, baohanh, tlg, gia);
    else if(k==dem+1)
        ThemCuoi(L, ma, hang , cl, pc, gtinh, baohanh, tlg, gia);
    else
    {
        int dem=0;
        List N=L, M;
        while (N!=NULL)
        {
            dem++;
            if(dem==k)
            {
                Q->next=N;
                M->next=Q;
                break;
            }
            M=N;
            N=N->next;
        }
    }
}

void TaoBatKi(List &L)
{
    string  hsp, clieu, pcach, gt;
    int tgbh, msp;
    float tl, tien;

    cout << "\n Ma sp: ";		cin >> msp;
    fflush(stdin);
	cout << "\n Hang sp: "; 	getline(cin,hsp);
    fflush(stdin);
    cout << "\n Chat lieu: ";    getline(cin,clieu);
    fflush(stdin);
    cout << "\n Phong cach: ";      getline(cin,pcach);
    fflush(stdin);
	cout << "\n Gioi tinh: ";		getline(cin,gt);
	cout << "\n Thoi luong bao hanh (thang): "; 	cin >> tgbh;
	cout << "\n Trong luong (gam): "; 	cin >> tl;
	cout << "\n Gia tien (Trieu vnd): "; 	cin >> tien;
    cout << "\n";

    Them_Vtbk(L, msp, hsp, clieu, pcach, gt, tgbh, tl, tien);
    Xuat(L);
}

void Xuat(List L)
{
	List P=L;
	while (P!=NULL)
	{
		cout << "\n Msp: "<< P->msp;
		cout << "\n Hang: "<< P->hsp;
        cout << "\n Chat lieu: "<< P->clieu;
        cout << "\n Phong cach: "<< P->pcach;
		cout << "\n Gioi tinh: "<< P->gt;
		cout << "\n Bao hanh: "<< P->tgbh <<" thang";
		cout << "\n Trong luong: "<< P->tl <<" gam";
        cout << "\n Gia: "<< P->tien <<" Trieu vnd";
		cout << "\n ********";
		P=P->next;
	}
	
}

int Empty (List L)
{
    return (L==NULL);
}

void Search_Msp(List L)
{
    int x;
    List T=L;
    cout << "\n Nhap msp can tim: ";
    cin>>x;

    while (T!=NULL && x != T->msp)
    {
        T=T->next;
    }
    if(T==NULL) cout << "\n Khong tim thay";
    else
    {
        cout << "\n Msp: "<< T->msp;
        cout << "\n Hang: "<< T->hsp;
        cout << "\n Chat lieu: "<< T->clieu;
        cout << "\n Phong cach: "<< T->pcach;
        cout << "\n Gioi tinh: "<< T->gt;
        cout << "\n Bao hanh: "<< T->tgbh <<" thang";
        cout << "\n Trong luong: "<< T->tl <<" gam";
        cout << "\n Gia: "<< T->tien <<" Trieu vnd";
        cout << "\n ";
    } 
}

void Search_HangSp(List L)
{
    string x;
    List T=L;
    cout << "\n Hang sp can tim la: ";
    fflush(stdin);      getline(cin,x);

    while (T!=NULL && x!=T->hsp)
    {
        T=T->next;
    }
    if(T==NULL) cout << "\n Khong tim thay";
    else
    {
        cout << "\n Msp: "<< T->msp;
        cout << "\n Hang: "<< T->hsp;
        cout << "\n Chat lieu: "<< T->clieu;
        cout << "\n Phong cach: "<< T->pcach;
        cout << "\n Gioi tinh: "<< T->gt;
        cout << "\n Bao hanh: "<< T->tgbh <<" thang";
        cout << "\n Trong luong: "<< T->tl <<" gam";
        cout << "\n Gia: "<< T->tien <<" Trieu vnd";
        cout << "\n ";
    }     
}

void Search_GtSp(List L)
{
    string x;
    List T=L;
    cout << "\n Gioi tinh sp can tim la: ";
    fflush(stdin);      getline(cin,x);

    while (T!=NULL && x!=T->gt)
    {
        T=T->next;
    }
    if(T==NULL) cout << "\n Khong tim thay";
    else
    {
        cout << "\n Msp: "<< T->msp;
        cout << "\n Hang: "<< T->hsp;
        cout << "\n Chat lieu: "<< T->clieu;
        cout << "\n Phong cach: "<< T->pcach;
        cout << "\n Gioi tinh: "<< T->gt;
        cout << "\n Bao hanh: "<< T->tgbh <<" thang";
        cout << "\n Trong luong: "<< T->tl <<" gam";
        cout << "\n Gia: "<< T->tien <<" Trieu vnd";
        cout << "\n ";
    }     
}

void Sort_TrongLuong(List &L)
{
    List H = L;
    int count = 0;
    while(H!=NULL)
    {
        count++;
        H = H->next;
    }
    List Q,P,Z;
    for(int i = 0 ; i < count-1 ; i++)
    {
        P = L;
        for(int j = count-1 ; j > i ; j-- )
        {
            if(P->tl > P->next->tl)
            {
                Z = P->next;
                P->next = P->next->next;
                Z->next = P;
                if(P == L)
                    L = P = Z;
                else
                {
                    Q->next = Z;
                    P = Z;
                }
            }
            Q = P;
            P = P->next;
        }
    }
    cout << "\n Ds sp sau sx theo Trong Luong: ";Xuat(L);
}

void Sort_msp(List &L)
{
    List H = L;
    int count = 0;
    while(H!=NULL)
    {
        count++;
        H = H->next;
    }
    List Q,P,Z;
    for(int i = 0 ; i < count-1 ; i++)
    {
        P = L;
        for(int j = count-1 ; j > i ; j-- )
        {
            if(P->msp > P->next->msp)
            {
                Z = P->next;
                P->next = P->next->next;
                Z->next = P;
                if(P == L)
                    L = P = Z;
                else
                {
                    Q->next = Z;
                    P = Z;
                }
            }
            Q = P;
            P = P->next;
        }
    }
    cout << "\n Ds sau Sort msp: ";
    Xuat(L);
}

void LocHangTonKho (List &L, List &Y, List &X)
{
	KhoiTao(Y);
	KhoiTao(X);
    string  hang, cl, pc, gtinh;
    int bh, ma;
    float trongluong, gia;
	List Q, P=L;	
	while(P!=NULL)
    {
        ma = P->msp;
        hang = P->hsp;
        cl = P->clieu;
        pc = P->pcach;
        gtinh = P->gt;
        trongluong = P->tl;
        bh = P->tgbh;
        gia = P->tien;
		if(P->tgbh < 12)
        {
            ThemDau(Y,ma,hang,cl,pc,gtinh,bh,trongluong,gia);
        }
        else
        {
            ThemDau(X,ma,hang,cl,pc,gtinh,bh,trongluong,gia);
        } 	
		P=P->next;
	}
    cout<<"\nDanh sach san pham ton kho:"<<endl;
    Xuat(Y);
    cout<<"\nDanh sach san pham new:"<<endl;
    Xuat(X);
}

void NoiDsSauKhiLoc (List &Y, List &X, List &C)
{
    KhoiTao(C);
    List P=Y, Q=X;
    string  hang, cl, pc, gtinh;
    int bh, ma;
    float trongluong, gia;
    while (P!=NULL)
    {
        ma = P->msp;
        hang = P->hsp;
        cl = P->clieu;
        pc = P->pcach;
        gtinh = P->gt;
        trongluong = P->tl;
        bh = P->tgbh;
        gia = P->tien;
        ThemDau(C,ma,hang,cl,pc,gtinh,bh,trongluong,gia);
        P=P->next;
    }
    while (Q!=NULL)
    {
        ma = Q->msp;
        hang = Q->hsp;
        cl = Q->clieu;
        pc = Q->pcach;
        gtinh = Q->gt;
        trongluong = Q->tl;
        bh = Q->tgbh;
        gia = Q->tien;
        ThemDau(C,ma,hang,cl,pc,gtinh,bh,trongluong,gia);
        Q=Q->next;
    }
    cout << "\n Ds sau khi noi lai: ";
    Xuat(C);
}

float GiaTB(List L)
{
    List Q=L;
    float tb=0;
    while (Q!=NULL)
    {
        tb=tb+Q->tien;
        Q=Q->next;
    }
    List count=L;
    int dem=0;
    while (count!=NULL)
    {
        dem++;
        count=count->next;
    }
    
    return tb/dem;
}

void Gia2tr(List L)
{
    List T=L;
    float count=0;
    while (T!=NULL)
    {
        if (T->tien <= 2)
        {
            cout << "\n Msp: "<< T->msp;
            cout << "\n Hang: "<< T->hsp;
            cout << "\n Chat lieu: "<< T->clieu;
            cout << "\n Phong cach: "<< T->pcach;
            cout << "\n Gioi tinh: "<< T->gt;
            cout << "\n Bao hanh: "<< T->tgbh <<" thang";
            cout << "\n Trong luong: "<< T->tl <<" gam";
            cout << "\n Gia: "<< T->tien <<" Trieu vnd";
            cout << "\n ";  count++;
        }
        T=T->next;
    }
    if(count != 0)
        cout << "\n Co "<<count<<" sp gia chi tu 2tr vnd";
    else
        cout << "\n Khong tim thay!";
}

void Xoabatki(List &L)
{
	int id;
	cout <<"Xoa ptu thu: ";	
    cin >> id;
    List count=L;
    int dem=0;
    while (count!=NULL)
    {
        dem++;
        count=count->next;
    }

    if(id==1)
        xoadau(L);
    else if (id==dem)
    {
        xoacuoi(L);
    }
    
    else
    {
        List P = L; 
        List Q;
        int dem=0;
        while(P!=NULL)
        {
            dem++;
            if (dem == id)
            {
                Q->next = P->next;
                delete P;   break;
            }
            Q = P;
            P = P->next;
        }
    }
    Xuat(L);
}

void xoadau (List &L)
{
    string  hang, cl, pc, gtinh;
    int bh, ma;
    float trongluong, gia;
	List Q;
	Q=L;
	L=L->next;

	ma = Q->msp;
    hang = Q->hsp;
    cl = Q->clieu;
    pc = Q->pcach;
    gtinh = Q->gt;
    trongluong = Q->tl;
    bh = Q->tgbh;
    gia = Q->tien;

	delete Q;
}

void xoacuoi (List &L)
{
    string  hang, cl, pc, gtinh;
    int bh, ma;
    float trongluong, gia;
	List Q, P;
	if (L->next!=NULL)
	{
		P=L;
		while ((P->next->next)!=NULL)
		{
			P=P->next;
		}
		Q=P->next;

		ma = Q->msp;
        hang = Q->hsp;
        cl = Q->clieu;
        pc = Q->pcach;
        gtinh = Q->gt;
        trongluong = Q->tl;
        bh = Q->tgbh;
        gia = Q->tien;

		delete Q;
		P->next=NULL;
	}
	else
	{
		ma = L->msp;
        hang = L->hsp;
        cl = L->clieu;
        pc = L->pcach;
        gtinh = L->gt;
        trongluong = L->tl;
        bh = L->tgbh;
        gia = L->tien;
		delete L;
		L=NULL;
	}
}

void Sort_gia(List &L)
{
    List H = L;
    int count = 0;
    while(H!=NULL)
    {
        count++;
        H = H->next;
    }
    List Q,P,Z;
    for(int i = 0 ; i < count-1 ; i++)
    {
        P = L;
        for(int j = count-1 ; j > i ; j-- )
        {
            if(P->tien > P->next->tien)
            {
                Z = P->next;
                P->next = P->next->next;
                Z->next = P;
                if(P == L)
                    L = P = Z;
                else
                    Q->next = Z;
                P = Z;
            }
            Q = P;
            P = P->next;
        }
    }
    cout << "\n Ds sau Sort tien: ";
    Xuat(L);
}