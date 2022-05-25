#include<conio.h>
#include<stdio.h>
int KiemTraNam(int y);//Ki?m tra nam nhu?n hay ko
int KiemTraNgay(int d,int m,int y);//Ki?m tra ngày có có trong tháng hay không
void SoNgayTrongThang(int y,int m,int a);//S? ngày trong t?ng tháng tính theo nam nhu?n hay ko nhu?n
int main(){
    int d,m,y;
    cout<<"Nhap ngay, thang, nam: ";
    cin>>d>>m>>y;
    if(m>0 && m<=12 && y>1){
        if(KiemTraNgay(d,m,y)==1){
            cout<<"Dinh dang ngay dung \n";
        }
        else cout<<"Dinh dang ngay sai";
    }
    else cout<<"so nam hoac so thang ko dung";
    //Ki?m tra thang nam nh?p vào
    getch();
}
int KiemTraNam(int y,int m){
    bool check;
    if(y%400==0 || (y%4==0 && y%100!=0)){
        check=0;//Nam nhu?n
    }
    else check=1;//Nam thu?ng
    return check;
}//Ki?m tra nam nhu?n hay ko nhu?n
void SoNgayTrongThang(int y,int m,int a[13]){
    int i;
    for(i=1;i<=12;i++){
        if(i<=7)
            if(i%2!=0) a[i]=31;//tháng 1,3,5,7 có 31 ngày
            else a[i]=30;//tháng 2,4,6 có 30 ngày
        if(i>=8)
            if(i%2==0) a[i]=31;//tháng 8,10,12 có 30 ngày
            else a[i]=30;//tháng 9,11 có 30 ngày
        if(i==2)
            if(KiemTraNam(y,m)==0) a[i]=29;//Nam nhu?n tháng 2 có 29 ngày
            else a[i]=28;//Nam không nhu?n tháng 2 có 28 ngày
    }
}//Xét 1 tháng có bao nhiêu ngày
int KiemTraNgay(int d,int m,int y){
    bool check;
    int a[13];//Ð?t bi?n luu ngày trong tháng
    SoNgayTrongThang(y,m,a);
    if(d<=a[m] && d>0)
        check=1;//Ðúng
    else check=0;//Sai
    return check;
}
printf("\nNgay thu %d trong nam", y);
    getch();
    return 0;
}
