#include <stdio.h>
#include <string.h> 
#include <ctype.h>

struct student;
void hienthiDSSV(struct student*, int);
void hienThiTenCot();

struct age{
    int day;
    int month;
    int year;
    int age;
};
struct DiemGPA{
    float gpa;
    char aca_rating[10];
};
struct student{
    char ID[8];
    char name [40];
    struct age dob;
    char gender[10]; 
    char faculty[50]; 
    struct DiemGPA GPA;
};
void NhapGPA(struct DiemGPA *diemgpa){
    printf("Nhap diem GPA: ");
    scanf("%f",&diemgpa->gpa);
    if ((diemgpa->gpa)>= 5 && (diemgpa->gpa)<6.5)
        strcpy(diemgpa->aca_rating,"TB");
    if ((diemgpa->gpa) >= 6.5 && (diemgpa->gpa) <7.5) 
        strcpy(diemgpa->aca_rating,"Kha");
    if ((diemgpa->gpa) >= 7.5 && (diemgpa->gpa) <8.5)
        strcpy(diemgpa->aca_rating,"Gioi");
    if ((diemgpa->gpa) >= 8.5 && (diemgpa->gpa) <=10)
        strcpy(diemgpa->aca_rating,"Xuat sac");
}
// Nhap ngay, thang, nam sinh tinh tuoi
// Check nam nhuan
int CheckNamNhuan( int year){
    return ((year % 4 ==0) && (year % 100 ==0)||(year % 400 !=0))?1:0 ;
}
int DayofMonth(int month, int year){
    int CheckMonth;
    int Day_Month;
    switch(month){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        Day_Month =31;
        break;
    case 4: case 6: case 9: case 11:
        Day_Month =30; 
        break;
    case 2: CheckMonth = CheckNamNhuan(year);
            if (CheckMonth == 1){
                Day_Month =29;
            }else
                Day_Month =28;
        break;
    }
    return Day_Month;
}
void age(struct age* tuoi){   
    int Day =22;        
    int Month=3;    
    int Year=2021;
    printf("Input year of birth: ");
    scanf("%d",&tuoi->year);
    do{
    printf("Input month of birth: ");
    scanf("%d",&tuoi->month);
    if (tuoi->month >12 || tuoi->month < 1)
    printf("Please input month again\n");
    } while (tuoi->month >12 || tuoi->month < 1);
    do{
    printf("Input day of birth: ");
    scanf("%d",&tuoi->day);
    if (tuoi->day < 1 || tuoi->day > DayofMonth(tuoi->month,tuoi->year))
    printf("Please input day again\n");
    } while (tuoi->day < 1 || tuoi->day > DayofMonth(tuoi->month,tuoi->year));
    tuoi->age = Year - tuoi->year;
    if (tuoi->month < Month) 
    tuoi->age = Year - tuoi->year ;
    else if (tuoi->day < Day && tuoi->month>= Month)
    tuoi->age = Year - tuoi->year ;
    else if (tuoi->day > Day && tuoi->month >= Month )
    tuoi->age = Year - tuoi->year;
}
// Nhap thong tin sinh vien
// In hoa chu ten 
void Format_Name(char *s){
    while (s[0] == ' ')
    strcpy(&s[0], &s[1]);   
    do {
        s[strlen(s)] = '\0';
    } while(s[strlen(s)] == ' ');
    for (int i =0; i < strlen(s); i++){
        if ((s[i]== ' ') && (s[i+1]==' ')){
            strcpy(&s[i],&s[i+1]);
            i--;
        }
    }
    strlwr(s); 
    s[0]= toupper(s[0]); 
    for (int i=0; i < strlen(s); i++){
        if (s[i]==' ')
        s[i+1]= toupper(s[i+1]);  
    }
}
struct student nhapTTSV(){
    struct student sv; 
    printf("Input ID: ");
    scanf(" %[^\n]s",sv.ID);
    strupr(sv.ID);
    printf("Input name of student: ");
    scanf(" %[^\n]s",sv.name);
    Format_Name(sv.name);
    printf("Input male or female or other: ");
    scanf("%s",sv.gender);
    Format_Name(sv.gender);
    printf("Input major(SE,AI,..): ");
    scanf("%s",sv.faculty);
    strupr(sv.faculty);
    age(&sv.dob);
    NhapGPA(&sv.GPA);
    return sv;
}
// Hien thi thong tin sinh vien
void hienthiTTSV(struct student sv){
    printf("%-15s %-25s %-16s %-15d %-10s %-14.2f %-15s\n",sv.ID,sv.name,sv.gender,sv.dob.age,sv.faculty,sv.GPA.gpa,sv.GPA.aca_rating);
}
// Sap xep theo ten
void sapXepTheoTen(struct student* ds, int slsv) {
    for(int i = 0; i < slsv - 1; i++) {
        for(int j = slsv - 1; j > i; j --) {
            if(strcmp(ds[j].name, ds[j-1].name) < 0) {
                struct student sv = ds[j];
                ds[j] = ds[j - 1];
                ds[j - 1] = sv;
            }
        }
    }
}
// Sap xep theo diem
void sapxeptheodiemtangdan(struct student *ds, int slsv){
    for (int i=0; i<slsv-1; i++){
        for (int j=slsv-1; j>i;j--){
            if (ds[j].GPA.gpa> ds[j-1].GPA.gpa){
                struct student sv=ds[j];
                ds[j]= ds[j-1];
                ds[j-1]=sv;
            }
        }
    }
}
void sapxeptheodiemgiamdan(struct student *ds,int slsv){
    for (int i=0; i< slsv-1; i++){
        for (int j=slsv-1; j>i; j--){
            if (ds[j].GPA.gpa <ds[j-1].GPA.gpa){
                struct student sv=ds[j];
                ds[j]=ds[j-1];
                ds[j-1]=sv;
            }
        }
    }
}
int findStudentByID( struct student *ds,int slsv,char mssv[]){
    int i=0;
    for (i=0; i< slsv; i++){
        if(strcmp(ds[i].ID,mssv) == 0 ){
            return i;
        }
    }
    return -1;
}
// Tim kiem sinh vien
void timkiemsinhvien(struct student *ds,int slsv,char mssv[]){
    hienThiTenCot();
    int timSV=0;
    for (int i=0; i < slsv; i++){
        if (strcmp(ds[i].ID,mssv)==0){
            hienthiTTSV(ds[i]);
            timSV=1;
        }
    }
    if (timSV==0){
        printf("Cannot find the student %s\n",mssv);
    }
}
// Xoa sinh vien 
void xoasinhvien(struct student *ds,int *slsv,char mssv[],int pos){
    for (int i=pos; i < (*slsv)-1; i++){
        struct student sv=ds[i];
        strcpy(ds[i].ID,ds[i+1].ID);
        strcpy(ds[i].name,ds[i+1].name);
        strcpy(ds[i].gender,ds[i+1].gender);
        strcpy(ds[i].faculty,ds[i+1].faculty);
        ds[i].GPA.gpa=ds[i+1].GPA.gpa;
        strcpy(ds[i].GPA.aca_rating,ds[i+1].GPA.aca_rating);
        ds[i].dob=ds[i+1].dob;
    }
    (*slsv)--;
    hienThiTenCot();
    for (int i=0; i< *slsv; i++){
        hienthiTTSV(ds[i]);
    }
}
 typedef
// Luu file 
void luuFile(struct student *ds, int slsv) {
    char fName[26];
    printf("Input the name of file: ");
    gets(fName);
    FILE* fOut = fopen(fName, "a");
    int i;
    for(i = 0; i < slsv; i++) {
        struct student sv = ds[i];
        fprintf(fOut,"%-15s %-25s %-16s %-15d %-10s %-14.2f %-15s\n",
        sv.ID,sv.name,sv.gender,sv.dob.age,sv.faculty,sv.GPA.gpa,sv.GPA.aca_rating);
    }
    fclose(fOut);
}
void hienThiTenCot(){
    printf("                                                 STUDENT LIST                                               \n");
    printf("---------------------------------------------------------------------------------------------------------------------\n");
    printf("%-15s %-25s %-15s %-10s %-15s %-15s %-15s\n", "MSSV", "Ten SV", "Gioi tinh", "Tuoi", "Chuyen Nganh", "Diem GPA", "Hoc luc");
}
void hienThiDSSV(struct student* ds, int slsv){
    if (slsv==0){
        printf("This student list dont have student\n");
    }
    hienThiTenCot();
    int i;
    for(i = 0; i < slsv; i++){
        hienthiTTSV(ds[i]);
    }
    printf("---------------------------------------------------------------------------------------------------------------------\n");
}
 
// Load file 
void loadfile(struct student* ds, int* slsv){
    FILE* fOut = fopen("Danh_sach_SV.txt", "r");
    int i = 0;
    if(fOut){
        for(;;){
            struct student sv;
            fscanf(fOut," %15s %25[^\n] %16s %15d %10s %14f  %15[^\n]\n",
            sv.ID,sv.name,sv.gender,&sv.dob.age,sv.faculty,&sv.GPA.gpa,sv.GPA.aca_rating);
            ds[i++] = sv;
            if(feof(fOut)){
                break;
            }
        }
    }
    fclose(fOut);
    *slsv = i;
}
int main(){
    struct student dssv[1000];
    struct student sv;
    int slsv = 0;
    int luachon;
    char buffer;
    loadfile(dssv, &slsv);
    printf("Now student list:\n");
    hienThiDSSV(dssv, slsv);    
    int choice_diem;    
    int pos;
    do{
        printf("\n|--------------------------------MENU--------------------------------|");
        printf("\n| 1.Add new student                | 6.Delete Student by ID          |");
        printf("\n| 2.Show Student list              | 7.Save Student from file        |");
        printf("\n| 3.Sort Student List by name      | 8.Update Student from file      |");
        printf("\n| 4.Sort Student List by point     | 0.Quit                          |");
        printf("\n| 5.Find Student by ID             |                                 |");
        printf("\n|                                  |                                 |");
        printf("\n|___________________Welcome to student list of NhaThy________________|");
        printf("\n|--------------------------------------------------------------------|");
        do{
        printf("\n**          Input your choice:");
            scanf("%d", &luachon);
            scanf("%c", &buffer);
            fflush(stdin);
            if(buffer != 10){
                printf("\nFalse input!!!");
            }
        }while(buffer != 10);
        switch (luachon){
            case 0:
                printf("Good Bye\n");
                break;
            case 1:{
                sv = nhapTTSV();
                dssv[slsv++] = sv;
                break;
            }
            case 2:{
                hienThiDSSV(dssv,slsv);
                break;
            }
            case 3:{
                sapXepTheoTen(dssv,slsv);
                printf("\nStudent list after sort by name A-Z:\n");
                hienThiDSSV(dssv, slsv);
                break;
            }   
            case 4:{
                printf("Student list after sort by point:\n");
                printf("1: Decrease\n");
                printf("2: Increase\n");
                printf("Your choice: ");
                scanf("%d",&choice_diem);
                switch (choice_diem){
                    case 1:     
                    sapxeptheodiemgiamdan(dssv,slsv);
                    printf("\nStudent list after sort by point decrease:\n");
                    hienThiDSSV(dssv, slsv);
                    break;
                    case 2:
                    sapxeptheodiemtangdan(dssv,slsv);
                    printf("\nStudent list after sort by point increase:\n");
                    hienThiDSSV(dssv, slsv);
                    break;
                }
                break;
            }
            case 5:{
                char mssv[8];
                printf("Input ID of student you want to find: ");
                gets(mssv);
                pos =findStudentByID(dssv,slsv,mssv);
                if(pos == -1){
                    printf("This list dont have student you want to find\n");
                }else {
                timkiemsinhvien(dssv,slsv,mssv);
                }
                break;
            }
            case 6:{
                char mssv[8];
                printf("Input ID od student you want to delete: ");
                gets(mssv);
                pos =findStudentByID(dssv,slsv,mssv);
                if(pos == -1){
                    printf("This list dont have student you want to delete\n");
                }else {
                xoasinhvien(dssv,&slsv,mssv,pos);
                printf("Complete to delete!!\n");
                }
                break;
            }
            case 7:{
                luuFile(dssv,slsv);
                break;
                }
            case 8:{
                loadfile(dssv, &slsv);
                printf("Now student list:\n");
                hienThiDSSV(dssv, slsv);
                break;
            }
            default:
                printf("Do you know number from 1 to 8???\n");
                break;
        }
    } while (luachon);
}