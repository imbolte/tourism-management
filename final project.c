#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

#define MAX_USERS 100

int d, m, y;

struct User
{
    char username[30];
    char email[30];
    char password[30];

};

struct User numUser[MAX_USERS];
int userCnt = 0;

struct billinfo
{
    char name[30];
    int age;
    char gender[30];
    int cost;
    char fname[30];
    char cityname[30];
    char hname[30];
    int days;
    char bname[30];

};

struct billinfo newBill;
struct billinfo numBill[MAX_USERS];
int billCnt = 0;

void gotoxy(int x, int y)
{
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}

void arrowHere(int realposition, int arrowposition);

void arrowHere(int realposition , int arrowposition){
    if (realposition == arrowposition)
        printf("\t\t \t------>");
    else
        printf("\t\t \t         ");
}

void read_user_info()
{
    FILE *fr;
    fr = fopen("userinfo.txt", "r");

    if(fr == NULL)
    {
        printf("File not opened\n");
        system("cls");
        return;
    }

    userCnt = 0;

    while(fscanf(fr, "%[^,],%[^,],%[^\n]\n", numUser[userCnt].username, numUser[userCnt].email, numUser[userCnt].password) == 3)
    {
        userCnt++;
    }

    fclose(fr);
}

void read_billinfo()
{
    FILE *fr;
    fr = fopen("billinfo.txt", "r");

    billCnt = 0;

    if(fr == NULL)
    {
        printf("File not opened\n");
        system("cls");
        return;
    }

    while(fscanf(fr, "%[^\n]\n%d\n%[^\n]\n%d\n%[^\n]\n%[^\n]\n%d,%d,%d\n%[^\n]\n", numBill[billCnt].name, &numBill[billCnt].age, numBill[billCnt].gender, &numBill[billCnt].cost, numBill[billCnt].fname, numBill[billCnt].cityname, &d, &m, &y, numBill[billCnt].hname)==10)
    {
        billCnt++;
    }

    fclose(fr);
}

void create_acc()
{
    read_user_info();
    struct User newUser;

    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 NEW ACCOUNT \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

    printf("\n \t \t \tNew Username: ");
    scanf("%s", newUser.username);

    for(int i = 0; i < userCnt; i++)
    {
        if(strcmp(newUser.username, numUser[i].username) == 0)
        {
            system("cls");
            printf("\n\t \t \tUsername already exists. Please choose a different username.");
            Sleep(2000);
            system("cls");
            create_acc();
        }
    }

    printf("\n \t \t \tUsermail: ");
    scanf("%s", newUser.email);

    if(strstr(newUser.email, "gmail.com") != NULL || strstr(newUser.email, "yahoo.com") != NULL)
    {
        printf("\n \t \t \tNew Password: ");
        scanf("%s", newUser.password);

        numUser[userCnt++] = newUser;

        FILE *fa;
        fa = fopen("userinfo.txt", "a+");

        if(fa == NULL)
        {
            printf("File not opened\n");
            return;
        }
        else
        {
            fprintf(fa, "%s,%s,%s\n", newUser.username, newUser.email, newUser.password);
            fclose(fa);

            printf("\n \t \t \tAccount created successfully!\n");
            printf("\n \t \t \tReturning to menu....");
            Sleep(1000);
            system("cls");
            menu();
        }
    }
    else
    {
        printf("\n \t \t \tInvalid email address!!! Please enter a valid email!!!\n");
        Sleep(2000);
        system("cls");
        create_acc();
    }
}

void login()
{
    read_user_info();
    char username[30];
    char userpass[30];
    char ch;
    int i = 0;

    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LOGIN \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

    printf("\n \t \t \tEnter Your Username: ");
    scanf("%s", username);

    printf("\n \t \t \tEnter Your Password: ");

   while((ch = _getch()) != '\r')
    {
        if(ch == '\b' && i > 0)
        {
            printf("\b \b");
            i--;
        }
        else
        {
            userpass[i] = ch;
            printf("*");
            i++;
        }
    }

    userpass[i] = '\0';

    for(int i = 0; i < userCnt; i++)
    {
        if(strcmp(username, numUser[i].username) == 0 && strcmp(userpass, numUser[i].password) == 0)
        {
            system("cls");
            Sleep(100);
            printf("\n\n\t \t \tLogin Successful\n");
            Sleep(1000);
            system("cls");
            bookmenu();
            return;
        }
    }

    printf("\n \t \t \tInvalid username or password.\n");
    Sleep(1000);
    system("cls");
    menu();
}

void d_bus()
{
    system("cls");
    newBill.cost = 0;
    int position = 1, n;
    int keypressed = 0;

    while(keypressed!=13){
            system("cls");

    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 AVAILABLE BUSES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

     arrowHere(1,position);printf("1. Green Line \t Ticket Price : 1,500 TK\n");
     arrowHere(2,position);printf("2. Unique Travels \t Ticket Price : 1,200 TK\n");
     arrowHere(3,position);printf("3. Shyamoli Travels \t Ticket Price : 1,000 TK\n");

     keypressed = getch();

        if(keypressed == 80 && position!=3){
            position++;
        }
        else if (keypressed == 80 && position==3){
            position -=2 ;

        }
        else if (keypressed == 72 && position!=1){
            position--;
        }
        else if  (keypressed == 72 && position==1){
            position+=2;
        }
        else{
            position == position;
        }

    switch(position)
    {
        case 1: newBill.cost+=1500;
        strcpy(newBill.bname,"Green_Line");break;
        case 2: newBill.cost+=1200;
        strcpy(newBill.bname,"Unique_Travels");break;
        case 3: newBill.cost+=1000;
        strcpy(newBill.bname,"Shyamoli_Travels");break;
    }

    }
}
void d_hotel()
{
    system("cls");
    int position = 1;
    int keypressed = 0;

    while(keypressed!=13){
        system("cls");

    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 AVAILABLE HOTELS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");

    arrowHere(1,position);printf("1. Hotel Sheraton\t \tPrice : 17,000 TK PER DAY\n");
    arrowHere(2,position);printf("2. Pan Pacific Sonargaon\tPrice : 15,000 TK PER DAY\n");
    arrowHere(3,position);printf("3. Le Meridien\t \t\tPrice : 12,000 TK PER DAY\n");

    keypressed = getch();

        if(keypressed == 80 && position!=3){
            position++;
        }
        else if (keypressed == 80 && position==3){
            position -=2 ;

        }
        else if (keypressed == 72 && position!=1){
            position--;
        }
        else if  (keypressed == 72 && position==1){
            position+=2;
        }
        else{
            position == position;
        }

    switch(position)
    {
        case 1: strcpy(newBill.hname,"Hotel_Sheraton");break;
        case 2: strcpy(newBill.hname,"Pan_Pacific_Sonargaon");break;
        case 3: strcpy(newBill.hname,"Le_Meridien");break;
    }
    }

    printf("\n \t \t \tEnter No Of Days :\t ");
    scanf("%d", &newBill.days);

    switch(position)
    {
        case 1: newBill.cost += (newBill.days * 17000);break;
        case 2: newBill.cost += (newBill.days * 15000);break;
        case 3: newBill.cost += (newBill.days * 12000);break;
    }

    printf("\n\t \t \tENTER DATE OF CHECK IN : ");
    scanf("%d",&d);
    printf("\n\t \t \tENTER MONTH OF CHECK IN : ");
    scanf("%d",&m);
    printf("\n\t \t \tENTER YEAR OF CHECK IN : ");
	scanf("%d",&y);

}

void c_hotel()
{
    system("cls");
    int position = 1, n;
    int keypressed = 0;

    while(keypressed!=13){
        system("cls");

    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 AVAILABLE HOTELS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");

    arrowHere(1,position);printf("1. Raddison Blu\t \t Price : 18,000 TK PER DAY\n");
    arrowHere(2,position);printf("2. Hotel Peninsula\t Price : 16,000 TK PER DAY\n");
    arrowHere(3,position);printf("3. Hotel Agrabad\t Price : 13,000 TK PER DAY\n");

    keypressed = getch();

        if(keypressed == 80 && position!=3){
            position++;
        }
        else if (keypressed == 80 && position==3){
            position -=2 ;

        }
        else if (keypressed == 72 && position!=1){
            position--;
        }
        else if  (keypressed == 72 && position==1){
            position+=2;
        }
        else{
            position == position;
        }

    switch(position)
    {
        case 1: strcpy(newBill.hname,"Raddison_Blu");break;
        case 2: strcpy(newBill.hname,"Hotel_Peninsula");break;
        case 3: strcpy(newBill.hname,"Hotel_Agrabad");break;
    }
    }

    printf("\n \t \t \tEnter No Of Days :\t ");
    scanf("%d", &newBill.days);

    switch(position)
    {
        case 1: newBill.cost += (newBill.days * 18000);break;
        case 2: newBill.cost += (newBill.days * 16000);break;
        case 3: newBill.cost += (newBill.days * 13000);break;
    }

    printf("\n\t \t \tENTER DATE OF CHECK IN : ");
    scanf("%d",&d);
    printf("\n\t \t \tENTER MONTH OF CHECK IN : ");
    scanf("%d",&m);
    printf("\n\t \t \tENTER YEAR OF CHECK IN : ");
	scanf("%d",&y);
}

void s_hotel()
{
    system("cls");
    int position = 1, n;
    int keypressed = 0;

    while(keypressed!=13){
        system("cls");

    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 AVAILABLE HOTELS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");

    arrowHere(1,position);printf("1. Grand Sylhet Hotel\t Price : 10,000 TK PER DAY\n");
    arrowHere(2,position);printf("2. Rose View Hotel\t Price : 8,000 TK PER DAY\n");
    arrowHere(3,position);printf("3. Hotel Noorjahan Grand\t Price : 6,000 TK PER DAY\n");

    keypressed = getch();

        if(keypressed == 80 && position!=3){
            position++;
        }
        else if (keypressed == 80 && position==3){
            position -=2 ;

        }
        else if (keypressed == 72 && position!=1){
            position--;
        }
        else if  (keypressed == 72 && position==1){
            position+=2;
        }
        else{
            position == position;
        }

    switch(position)
    {
        case 1: strcpy(newBill.hname,"Grand_Sylhet_Hotel");break;
        case 2: strcpy(newBill.hname,"Rose_View_Hotel");break;
        case 3: strcpy(newBill.hname,"Hotel_Noorjahan_Grand");break;
    }
    }
    printf("\n \t \t \tEnter No Of Days :\t ");
    scanf("%d", &newBill.days);

    switch(position)
    {
        case 1: newBill.cost += (newBill.days * 10000);break;
        case 2: newBill.cost += (newBill.days * 8000);break;
        case 3: newBill.cost += (newBill.days * 6000);break;
    }

    printf("\n\t \t \tENTER DATE OF CHECK IN : ");
    scanf("%d",&d);
    printf("\n\t \t \tENTER MONTH OF CHECK IN : ");
    scanf("%d",&m);
    printf("\n\t \t \tENTER YEAR OF CHECK IN : ");
	scanf("%d",&y);
}

void dhk()
{
    int cnt = 1;
    d_input(cnt);
}

void ctg()
{
    int cnt = 2;
    d_input(cnt);
}

void syl()
{
    int cnt = 3;
    d_input(cnt);
}

void int_flight()
{
    int n;
    newBill.cost = 0;
    int position = 1;
    int keypressed = 0;

    while(keypressed!=13){
            system("cls");

    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 AVAILABLE FLIGHTS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");

    arrowHere(1,position);printf("1. Qatar Airways \t Ticket Price : 70,000 TK\n");
    arrowHere(2,position);printf("2. Emirates Airways \t Ticket Price : 60,000 TK\n");
    arrowHere(3,position);printf("3. Belal Airways \t Ticket Price : 420,000 TK\n");

    keypressed = getch();



        if(keypressed == 80 && position!=3){
            position++;
        }
        else if (keypressed == 80 && position==3){
            position -=2 ;

        }
        else if (keypressed == 72 && position!=1){
            position--;
        }
        else if  (keypressed == 72 && position==1){
            position+=2;
        }
        else{
            position == position;
        }


    switch(position)
    {
        case 1: newBill.cost+=70000;
        strcpy(newBill.fname,"Qatar_Airways");break;
        case 2: newBill.cost+=60000;
        strcpy(newBill.fname,"Emirates_Airways");break;
        case 3: newBill.cost+=420000;
        strcpy(newBill.fname,"Belal_Airways");break;
    }
}

}

void int_hotel()
{
    system("cls");
    int n;
    int position = 1;
    int keypressed = 0;

    while(keypressed!=13){
            system("cls");

    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 AVAILABLE HOTELS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");

    arrowHere(1,position);printf("1. Marriott International Price : 20,000 TK PER DAY\n");
    arrowHere(2,position);printf("2. InterContinental\t Price : 15,000 TK PER DAY\n");
    arrowHere(3,position);printf("3. Four Seasons\t Price : 10,000 TK PER DAY\n");

    keypressed = getch();

        if(keypressed == 80 && position!=3){
            position++;
        }
        else if(keypressed == 80 && position==3){
            position -=2 ;

        }
        else if(keypressed == 72 && position!=1){
            position--;
        }
        else if(keypressed == 72 && position==1){
            position+=2;
        }
        else{
            position == position;
        }

    switch(position)
    {
        case 1: strcpy(newBill.hname,"Marriott_International");break;
        case 2: strcpy(newBill.hname,"InterContinental");break;
        case 3: strcpy(newBill.hname,"Four_Seasons");break;
    }

    }
    printf("\n \t \t \tEnter No Of Days :\t ");
    scanf("%d", &newBill.days);

    switch(position)
    {
        case 1: newBill.cost += (newBill.days * 20000);break;
        case 2: newBill.cost += (newBill.days * 15000);break;
        case 3: newBill.cost += (newBill.days * 10000);break;
    }

    printf("\n\t \t \tENTER DATE OF CHECK IN : ");
    scanf("%d",&d);
    printf("\n\t \t \tENTER MONTH OF CHECK IN : ");
    scanf("%d",&m);
    printf("\n\t \t \tENTER YEAR OF CHECK IN : ");
	scanf("%d",&y);
}

void d_input(int cnt)
{
    read_billinfo();
    switch(cnt)
    {
        case 1: strcpy(newBill.cityname, "Dhaka");break;
        case 2: strcpy(newBill.cityname, "Chittagong");break;
        case 3: strcpy(newBill.cityname, "Sylhet");break;
    }

    int flag = 0;
    while(flag == 0)
    {
        printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BOOKING INFO \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

        printf("\n\t \t \tEnter Your Name : ");
        scanf("%s", newBill.name);

        for(int i = 0; i < billCnt; i++)
        {
            if(strcmp(newBill.name, numBill[i].name) == 0)
            {
                system("cls");
                printf("\n\t \t \tName already exists. Please choose a different name.");
                Sleep(2000);
                system("cls");
                bookmenu();
            }
        }

        printf("\n\t \t \tEnter Your Age : ");
        scanf("%d", &newBill.age);
        printf("\n\t \t \tEnter Your Gender(M/F) : ");
        scanf("%s", newBill.gender);
        d_bus();
        switch(cnt)
        {
            case 1: d_hotel();break;
            case 2: c_hotel();break;
            case 3: s_hotel();break;

        }
        ++flag;
    }

    FILE *fa;
    fa = fopen("billinfo.txt","a+");

    if(fa == NULL)
    {
        printf("File not opened.\n");
    }
    else
    {
        fprintf(fa, "%s\n%d\n%s\n%d\n%s\n%s\n", newBill.name, newBill.age, newBill.gender, newBill.cost, newBill.bname, newBill.cityname);
        fprintf(fa, "%d,%d,%d\n%s\n", d, m, y, newBill.hname);
        fclose(fa);
    }

    numBill[billCnt++] = newBill;

    system("cls");

    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BILL OVERVIEW \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

        printf("\n\n\t\tNAME : %s", newBill.name);
        printf("\n\n\t\tAGE : %d", newBill.age);
        printf("\n\n\t\tGENDER : %s", newBill.gender);
        printf("\n\n\t\tTOTAL COST : %d TK ONLY", newBill.cost);
        printf("\n\n\t\tFLIGHT Name : %s", newBill.bname);
        printf("\n\n\t\tDESTINATION : %s", newBill.cityname);
        printf("\n\n\t\tCHECKIN DATE : %d/%d/%d", d, m, y);
        printf("\n\n\t\tHOTEL NAME : %s", newBill.hname);

    printf("\n\n\t\tBOOKING SUCCESSFULL");

    Sleep(3000);

    system("cls");
    bookmenu();
}

void input(int cnt)
{
    read_billinfo();
    switch(cnt)
    {
        case 1: strcpy(newBill.cityname, "New_York");break;
        case 2: strcpy(newBill.cityname, "Moscow");break;
        case 3: strcpy(newBill.cityname, "Los_Angeles");break;
    }

    int flag = 0;
    while(flag == 0)
    {
        printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BOOKING INFO \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

        printf("\n\t \t \tEnter Your Name : ");
        scanf("%s", newBill.name);

        for(int i = 0; i < billCnt; i++)
        {
            if(strcmp(newBill.name, numBill[i].name) == 0)
            {
                system("cls");
                printf("\n\t \t \tName already exists. Please choose a different name.");
                Sleep(2000);
                system("cls");
                bookmenu();
            }
        }

        printf("\n\t \t \tEnter Your Age : ");
        scanf("%d", &newBill.age);
        printf("\n\t \t \tEnter Your Gender(M/F) : ");
        scanf("%s", newBill.gender);
        int_flight();
        int_hotel();
        ++flag;
    }

    FILE *fa;
    fa = fopen("billinfo.txt","a+");

    if(fa == NULL)
    {
        printf("File not opened.\n");
    }
    else
    {
        fprintf(fa, "%s\n%d\n%s\n%d\n%s\n%s\n", newBill.name, newBill.age, newBill.gender, newBill.cost, newBill.fname, newBill.cityname);
        fprintf(fa, "%d,%d,%d\n%s\n", d, m, y, newBill.hname);
        fclose(fa);
    }

    numBill[billCnt++] = newBill;

    system("cls");

    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BILL OVERVIEW \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

        printf("\n\n\t\tNAME : %s", newBill.name);
        printf("\n\n\t\tAGE : %d", newBill.age);
        printf("\n\n\t\tGENDER : %s", newBill.gender);
        printf("\n\n\t\tTOTAL COST : %d TK ONLY", newBill.cost);
        printf("\n\n\t\tFLIGHT Name : %s", newBill.fname);
        printf("\n\n\t\tDESTINATION : %s", newBill.cityname);
        printf("\n\n\t\tCHECKIN DATE : %d/%d/%d", d, m, y);
        printf("\n\n\t\tHOTEL NAME : %s", newBill.hname);

    printf("\n\n\t\tBOOKING SUCCESSFULL");

    Sleep(6000);

    system("cls");
    bookmenu();
}

void NY()
{
    int cnt = 1;
    input(cnt);
}

void moscow()
{
    int cnt = 2;
    input(cnt);
}

void LA()
{
    int cnt = 3;
    input(cnt);
}

void international()
{
    system("cls");
    int position = 1;
    int keypressed = 0;

    while (keypressed != 13) {
        system("cls");

        printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 AVAILABLE CITIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");

        arrowHere(1, position); printf("1. New York\n");
        arrowHere(2, position); printf("2. Moscow\n");
        arrowHere(3, position); printf("3. Los Angeles\n");

        keypressed = getch();

        if (keypressed == 80 && position != 3) {
            position++;
        }
        else if (keypressed == 80 && position == 3) {
            position -= 2;
        }
        else if (keypressed == 72 && position != 1) {
            position--;
        }
        else if (keypressed == 72 && position == 1) {
            position += 2;
        }
        else {
            position = position;
        }
    }

    switch (position) {
        case 1:
            system("cls");
            NY();break;
        case 2:
            system("cls");
            moscow();break;
        case 3:
            system("cls");
            LA();break;
    }
}

void domestic()
{

    system("cls");
    int position = 1;
    int keypressed = 0;

    while (keypressed != 13) {
        system("cls");

        printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 AVAILABLE CITIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");

        arrowHere(1, position); printf("1. Dhaka\n");
        arrowHere(2, position); printf("2. Chittagong\n");
        arrowHere(3, position); printf("3. Sylhet\n");

        keypressed = getch();

        if (keypressed == 80 && position != 3) {
            position++;
        }
        else if (keypressed == 80 && position == 3) {
            position -= 2;
        }
        else if (keypressed == 72 && position != 1) {
            position--;
        }
        else if (keypressed == 72 && position == 1) {
            position += 2;
        }
        else {
            position = position;
        }
    }

    switch(position)
    {
        case 1:system("cls"); dhk();break;
        case 2:system("cls"); ctg();break;
        case 3:system("cls"); syl();break;
    }
}

void Book_Package()
{
    system("cls");
    int position = 1;
    int keypressed = 0;

    while (keypressed != 13) {
        system("cls");

    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 PACKAGES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");

    arrowHere(1, position);printf("1. Internantional Packages\n");
    arrowHere(2, position);printf("2. Domestic Packages\n");

    keypressed = getch();

        if (keypressed == 80 && position != 3) {
            position++;
        }
        else if (keypressed == 80 && position == 3) {
            position -= 2;
        }
        else if (keypressed == 72 && position != 1) {
            position--;
        }
        else if (keypressed == 72 && position == 1) {
            position += 2;
        }
        else {
            position = position;
        }

    }

    switch(position)
    {
        case 1:system("cls");international();break;
        case 2:system("cls");domestic();break;

    }

}

void Generate_Bill()
{
    read_billinfo();

    char tname[30];
    printf("\n\n\t\tEnter booking name : ");
    scanf("%s", tname);

    int flag = 0;

    for(int i = 0; i < billCnt; i++)
    {
        if(strcmp(numBill[i].name, tname) == 0)
        {
            system("cls");
            flag = 1;

            printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 YOUR BILL \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

            printf("\n\n\t\tNAME : %s", numBill[i].name);
            printf("\n\n\t\tAGE : %d", numBill[i].age);
            printf("\n\n\t\tGENDER : %s", numBill[i].gender);
            printf("\n\n\t\tTOTAL COST : %d TK ONLY", numBill[i].cost);
            printf("\n\n\t\tFLIGHT Name : %s", numBill[i].fname);
            printf("\n\n\t\tDESTINATION : %s", numBill[i].cityname);
            printf("\n\n\t\tCHECKIN DATE : %d/%d/%d", d, m, y);
            printf("\n\n\t\tHOTEL NAME : %s", numBill[i].hname);
        }
    }

    if(flag != 1)
        {
             printf("\n\n\t\tBill does not exists!!!\n");
             Sleep(2000);
             system("cls");
             bookmenu();
        }

    usleep(5000000);
    system("cls");
    bookmenu();

}

void Cancel_Booking()
{
    read_billinfo();

    char username[30];
    char password[30];
    int flag = 0;
    int i, j;

    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 CANCEL BOOKING \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

    printf("\n \t \t \tEnter Your Username: ");
    scanf("%s", username);

    for(i = 0; i < billCnt; i++)
    {
        if(strcmp(username, numBill[i].name) == 0)
        {
            flag = 1;
            printf("\n \t \t \tBooking Cancelled Successfully!\n");

            for(j = i; j < billCnt - 1; j++)
            {
                strcpy(numBill[j].name, numBill[j + 1].name);
                numBill[j].age = numBill[j + 1].age;
                strcpy(numBill[j].gender, numBill[j + 1].gender);
                numBill[j].cost = numBill[j + 1].cost;
                strcpy(numBill[j].fname, numBill[j + 1].fname);
                strcpy(numBill[j].cityname, numBill[j + 1].cityname);
                strcpy(numBill[j].hname, numBill[j + 1].hname);
                strcpy(numBill[j].bname, numBill[j + 1].bname);
            }

            billCnt--;

            FILE *fw;
            fw = fopen("billinfo.txt", "w");

            if(fw == NULL)
            {
                printf("File not opened\n");
                return;
            }

            for(int j = 0; j < billCnt; j++)
            {
                fprintf(fw, "%s\n%d\n%s\n%d\n%s\n%s\n", numBill[j].name, numBill[j].age, numBill[j].gender, numBill[j].cost, numBill[j].fname, numBill[j].cityname);
                fprintf(fw, "%d,%d,%d\n%s\n", d, m, y, numBill[j].hname);
            }

            fclose(fw);
            break;
        }
    }

    if(flag != 1)
    {
        printf("\n \t \t \tNo Bill Found.\n");
    }

    Sleep(1000);
    system("cls");
    bookmenu();
}

void Change_Password()
{
    char username[30];
    char userpass[30];
    char newpass[30];
    int pos = -1;
    int f = 0;

    read_user_info();

    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 CHANGE PASSWORD \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

    printf("\n \t \t \tEnter Your Username : ");
    scanf("%s", username);
    printf("\n \t \t \tEnter Your Old Password : ");
    scanf("%s", userpass);

    for(int i = 0; i < userCnt; i++)
    {
        if(strcmp(numUser[i].username, username)==0 && strcmp(numUser[i].password, userpass)==0)
        {
            system("cls");

            printf("\t\t\tEnter Your New Password : ");

            scanf("%s", newpass);
            pos = i;
            strcpy(numUser[pos].password, newpass);

            f = 1;
            break;
        }
    }

    if(f == 1)
    {
        FILE *fw;
        fw = fopen("tempfile.txt", "w");
        if(fw == NULL)
        {
            printf("File not opened\n");
            return;
        }

        for(int i = 0; i < userCnt; i++)
        {
            fprintf(fw, "%s,%s,%s\n", numUser[i].username, numUser[i].email, numUser[i].password);
        }

        fclose(fw);

        remove("userinfo.txt");
        rename("tempfile.txt", "userinfo.txt");

        printf("\n \t \t \tPassword updated successfully!\n");
        Sleep(1000);
        system("cls");
        menu();
    }
    else
    {
        printf("Invalid username or password.\n");
        Sleep(1000);
        system("cls");
        menu();
    }
}

void forgetpass()
{
    char username[30];
    char userpass[30];
    char usermail[30];
    char newpass[30];

    int pos = -1;
    int f = 0;

    read_user_info();

    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 RESET PASSWORD \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

    printf("\n \t \t \tEnter Your Username : ");
    scanf("%s", username);
    printf("\n \t \t \tEnter Your email: ");
    scanf("%s", usermail);

    for(int i = 0; i < userCnt; i++)
    {
        if(strcmp(numUser[i].username, username)==0 && strcmp(numUser[i].email, usermail)==0)
        {
            system("cls");

            printf("\t\t\tEnter Your New Password : ");

            scanf("%s", newpass);
            pos = i;
            strcpy(numUser[pos].password, newpass);

            f = 1;
            break;
        }
    }

    if(f == 1)
    {
        FILE *fw;
        fw = fopen("tempfile.txt", "w");
        if(fw == NULL)
        {
            printf("File not opened\n");
            return;
        }

        for(int i = 0; i < userCnt; i++)
        {
            fprintf(fw, "%s,%s,%s\n", numUser[i].username, numUser[i].email, numUser[i].password);
        }

        fclose(fw);

        remove("userinfo.txt");
        rename("tempfile.txt", "userinfo.txt");

        printf("\n \t \t \tPassword reset successfully!\n");
        Sleep(1000);
        system("cls");
        menu();
    }
    else
    {
        printf("Invalid username or password.\n");
        Sleep(1000);
        system("cls");
        menu();
    }
}

void Logout()
{
    menu();
}

void bookmenu()
{
   system("cls");
   int position = 1;
    int keypressed = 0;

    while(keypressed!=13){
        system("cls");

    printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    arrowHere(1,position);printf("1. Book Package\n");
    arrowHere(2,position);printf("2. Generate Bill\n");
    arrowHere(3,position);printf("3. Cancel Booking \n");
    arrowHere(4,position);printf("4. Change Password\n");
    arrowHere(5,position);printf("5. Logout\n");
    printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    keypressed = getch();

        if(keypressed == 80 && position!=5){
            position++;
        }
        else if (keypressed == 80 && position==5){
            position -=4 ;

        }
        else if (keypressed == 72 && position!=1){
            position--;
        }
        else if  (keypressed == 72 && position==1){
            position+=4;
        }
        else{
            position == position;
        }
    }

    switch(position)
    {
        case 1:system("cls");Book_Package();break;
        case 2:system("cls");Generate_Bill();break;
        case 3:system("cls");Cancel_Booking();break;
        case 4:system("cls");Change_Password();break;
        case 5:system("cls");Logout();break;

    }

}

void Exit()
{
    system("cls");
   int position = 1;
    int keypressed = 0;

    while(keypressed!=13){
        system("cls");

    printf("\n\n\n\t\t\ \t \t \tDo You Want To Exit?\n\n");

    arrowHere(1,position);printf("1. YES\n");
    arrowHere(2,position);printf("2. NO\n");

    keypressed = getch();

        if(keypressed == 80 && position!=2){
            position++;
        }
        else if (keypressed == 80 && position==2){
            position -=1 ;

        }
        else if (keypressed == 72 && position!=1){
            position--;
        }
        else if  (keypressed == 72 && position==1){
            position+=1;
        }
        else{
            position == position;
        }
    }

    switch(position)
    {
        case 1:system("cls");
        printf("\n\t\t\ \t THANK YOU FOR USING OUR PROGRAM!!!\n\n\n\n");
        return ; break;
        case 2:system("cls");menu();break;
    }

}

void menu()
{
    system("cls");
    int position = 1;
    int keypressed = 0;

    while(keypressed!=13){
        system("cls");


    printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME T0 BAHUBALI TOURISM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");

    arrowHere(1,position);printf("1. Create Account\n");
    arrowHere(2,position);printf("2. Login\n");
    arrowHere(3,position);printf("3. Admin login\n");
    arrowHere(4,position);printf("4. Forget password\n");
    arrowHere(5,position);printf("5. Exit\n");

    printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    keypressed = getch();



        if(keypressed == 80 && position!=5){
            position++;
        }
        else if (keypressed == 80 && position==5){
            position -=4 ;

        }
        else if (keypressed == 72 && position!=1){
            position--;
        }
        else if  (keypressed == 72 && position==1){
            position+=4;
        }
        else{
            position == position;
        }


    }

    switch(position)
    {
        case 1:system("cls");create_acc();break;
        case 2:system("cls");login();break;
        case 3:system("cls");admin();break;
        case 4:system("cls");forgetpass();break;
        case 5:system("cls");Exit();break;
    }

}

void createUser()
{
    system("cls");
    read_user_info();
    struct User newUser;
    int i;

    printf("\n \t \t \tEnter the username for the new user:  ");
    scanf("%s", newUser.username);

    for(i = 0; i < userCnt; i++)
    {
        if(strcmp(newUser.username, numUser[i].username) == 0)
        {
            system("cls");
            printf("\n\t \t \tUsername already exists. Please choose a different username.");
            Sleep(2000);
            system("cls");
            create_acc();
        }
    }

    printf("\n \t \t \tEnter the usermail for the new user: : ");
    scanf("%s", newUser.email);

    if(strstr(newUser.email, "gmail.com") != NULL || strstr(newUser.email, "yahoo.com") != NULL)
    {
        printf("\n \t \t \tNew Password: ");
        scanf("%s", newUser.password);

        numUser[userCnt++] = newUser;

        FILE *fa;
        fa = fopen("userinfo.txt", "a+");

        if(fa == NULL)
        {
            printf("File not opened\n");
            return;
        }
        else
        {
            fprintf(fa, "%s,%s,%s\n", newUser.username, newUser.email, newUser.password);
            fclose(fa);

            printf("\n \t \t \tAccount created successfully!\n");
            printf("\n \t \t \tReturning to menu....");
            Sleep(1000);
            system("cls");
            admin_menu();
        }
    }
    else
    {
        printf("\n \t \t \tInvalid email address!!! Please enter a valid email!!!\n");
        Sleep(2000);
        system("cls");
        admin_menu();
    }

}

void deleteUser()
{
    system("cls");
    read_user_info();
    char username[30];
    int i, j;


    printf("\n \t \t \tEnter the username of the user to delete: ");
    scanf("%s", username);


    int flag = 0;
    for(i = 0; i < userCnt; i++)
    {
        if(strcmp(numUser[i].username, username) == 0)
        {
            for(j = i; j < userCnt - 1; j++)
            {
                strcpy(numUser[j].username, numUser[j + 1].username);
                strcpy(numUser[j].email, numUser[j + 1].email);
                strcpy(numUser[j].password, numUser[j + 1].password);
            }
            userCnt--;
            flag = 1;
            break;
        }
    }

    if(flag == 1)
    {
        FILE *fw;
        fw = fopen("tempfile.txt", "w");
        if(fw == NULL)
        {
            printf("File not opened\n");
            return;
        }

        for(int i = 0; i < userCnt; i++)
        {
            fprintf(fw, "%s,%s,%s\n", numUser[i].username, numUser[i].email, numUser[i].password);
        }

        fclose(fw);

        remove("userinfo.txt");
        rename("tempfile.txt", "userinfo.txt");

        printf("\n \t \t \tUser deleted successfuly!!!\n");
        Sleep(1000);
        system("cls");
        admin_menu();
    }
    else
    {
        printf("\n \t \t \t User not found!!!");
        Sleep(1000);
        system("cls");
        admin_menu();
    }
}

void Alluser()
{
    read_user_info();
    system("cls");

    for(int i = 0; i < userCnt; i++)
    {
        printf("\n\n\t\tUSERNAME : %s", numUser[i].username);
        printf("\n\n\t\tUSERMAIL : %s", numUser[i].email);
        printf("\n\n\t\tUSERNAME : %s", numUser[i].password);
        printf("\n\n");
    }

    Sleep(10000);
    system("cls");
    admin_menu();


}


void Allbills()
{
    read_billinfo();
    system("cls");

    for(int i = 0; i < billCnt; i++)
    {
        printf("\n\n\t\tNAME : %s", numBill[i].name);
        printf("\n\n\t\tAGE : %d", numBill[i].age);
        printf("\n\n\t\tGENDER : %s", numBill[i].gender);
        printf("\n\n\t\tTOTAL COST : %d TK ONLY", numBill[i].cost);
        printf("\n\n\t\tFLIGHT Name : %s", numBill[i].fname);
        printf("\n\n\t\tDESTINATION : %s", numBill[i].cityname);
        printf("\n\n\t\tCHECKIN DATE : %d/%d/%d", d, m, y);
        printf("\n\n\t\tHOTEL NAME : %s", numBill[i].hname);
        printf("\n");
    }

    Sleep(10000);
    system("cls");
    admin_menu();
}

void delete_bill()
{
    read_billinfo();

    char username[30];
    int flag = 0;
    int i, j;
    system("cls");
    printf("\n \t \t \tEnter the name of the bill to delete: ");
    scanf("%s", username);

    for(i = 0; i < billCnt; i++)
    {
        if(strcmp(username, numBill[i].name) == 0)
        {
            flag = 1;
            printf("\n \t \t \tBooking Cancelled Successfully!\n");

            for (j = i; j < billCnt - 1; j++)
            {
                strcpy(numBill[j].name, numBill[j + 1].name);
                numBill[j].age = numBill[j + 1].age;
                strcpy(numBill[j].gender, numBill[j + 1].gender);
                numBill[j].cost = numBill[j + 1].cost;
                strcpy(numBill[j].fname, numBill[j + 1].fname);
                strcpy(numBill[j].cityname, numBill[j + 1].cityname);
                strcpy(numBill[j].hname, numBill[j + 1].hname);
                strcpy(numBill[j].bname, numBill[j + 1].bname);
            }

            billCnt--;

            FILE *fw;
            fw = fopen("billinfo.txt", "w");

            if(fw == NULL)
            {
                printf("File not opened\n");
                return;
            }

            for(int j = 0; j < billCnt; j++)
            {
                fprintf(fw, "%s\n%d\n%s\n%d\n%s\n%s\n", numBill[j].name, numBill[j].age, numBill[j].gender, numBill[j].cost, numBill[j].fname, numBill[j].cityname);
                fprintf(fw, "%d,%d,%d\n%s\n", d, m, y, numBill[j].hname);
            }

            fclose(fw);
            break;
        }
    }

    if(flag != 1)
    {
        printf("\n \t \t \tNo Bill Found.\n");
    }

    Sleep(1000);
    system("cls");
    admin_menu();

}

void admin_menu()
{
    system("cls");
   int position = 1;
    int keypressed = 0;

    while(keypressed!=13){
        system("cls");

    arrowHere(1,position);printf("1. Create user\n");
    arrowHere(2,position);printf("2. Delete user\n");
    arrowHere(3,position);printf("3. Show Users\n");
    arrowHere(4,position);printf("4. Show Bills\n");
    arrowHere(5,position);printf("5. Delete Bill\n");
    arrowHere(6,position);printf("6. Logout\n");

    keypressed = getch();

        if(keypressed == 80 && position!=6){
            position++;
        }
        else if (keypressed == 80 && position==5){
            position -=5;

        }
        else if (keypressed == 72 && position!=1){
            position--;
        }
        else if  (keypressed == 72 && position==1){
            position+=5;
        }
        else{
            position == position;
        }

    }

    switch(position)
    {
        case 1:
        createUser();break;
        case 2:
        deleteUser();break;
        case 3:
        Alluser();break;
        case 4:
        Allbills();break;
        case 5:
        delete_bill();break;
        case 6:
        system("cls");menu();break;
    }

}

void admin()
{
    system("cls");
    char adminname[30];
    char adminpass[30];
    char ch;
    int i = 0;

    printf("\n \t \t \tAdmin Username: ");
    scanf("%s", adminname);
    printf("\n \t \t \tAdmin Password: ");

    while((ch = _getch()) != '\r')
    {
        if(ch == '\b' && i > 0)
        {
            printf("\b \b");
            i--;
        }
        else
        {
            adminpass[i] = ch;
            printf("*");
            i++;
        }
    }

    adminpass[i] = '\0';

    if(strcmp(adminname, "admin") == 0 && strcmp(adminpass, "admin123") == 0)
    {
        system("cls");
        admin_menu();
    }
    else
    {
        system("cls");
        printf("\t\t\tENTER CORRECT ID OR PASSWORD!!!\n");
        Sleep(2000);
        admin();
    }

}

int main()
{
    int time=1000;
    system("COLOR 8");
        /// t
       gotoxy(1, 1);
        printf("%c",219);
        usleep(time);
        gotoxy(2, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(3, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(4, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(5, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(6, 1);
         printf("%c",219);
        usleep(time);
         printf("%c",219);
        usleep(time);
        gotoxy(7, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(8, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(9, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(10, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(11, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(6, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(6, 2);
         printf("%c",219);
        usleep(time);
        gotoxy(6, 3);
         printf("%c",219);
        usleep(time);
        gotoxy(6, 4);
         printf("%c",219);
        usleep(time);
        gotoxy(6, 5);
         printf("%c",219);
        usleep(time);
        gotoxy(6, 6);
         printf("%c",219);
        usleep(time);
        gotoxy(6, 7);
         printf("%c",219);
        usleep(time);
        gotoxy(6, 8);
         printf("%c",219);
        usleep(time);
        gotoxy(6, 9);
         printf("%c",219);
        usleep(time);
        gotoxy(6, 10);
         printf("%c",219);
        usleep(time);
        /// t end

        /// o
        gotoxy(13, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(14, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(15, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(16, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(17, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(18, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(19, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(20, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(21, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(13, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(13, 2);
         printf("%c",219);
        usleep(time);
        gotoxy(13, 3);
         printf("%c",219);
        usleep(time);
        gotoxy(13, 4);
         printf("%c",219);
        usleep(time);
        gotoxy(13, 5);
         printf("%c",219);
        usleep(time);
        gotoxy(13, 6);
         printf("%c",219);
        usleep(time);
        gotoxy(13, 7);
         printf("%c",219);
        usleep(time);
        gotoxy(13, 8);
         printf("%c",219);
        usleep(time);
        gotoxy(13, 9);
         printf("%c",219);
        usleep(time);
        gotoxy(13, 10);
         printf("%c",219);
        usleep(time);

        gotoxy(21, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(21, 2);
         printf("%c",219);
        usleep(time);
        gotoxy(21, 3);
         printf("%c",219);
        usleep(time);
        gotoxy(21, 4);
         printf("%c",219);
        usleep(time);
        gotoxy(21, 5);
         printf("%c",219);
        usleep(time);
        gotoxy(21, 6);
         printf("%c",219);
        usleep(time);
        gotoxy(21, 7);
         printf("%c",219);
        usleep(time);
        gotoxy(21, 8);
         printf("%c",219);
        usleep(time);
        gotoxy(21, 9);
         printf("%c",219);
        usleep(time);
        gotoxy(21, 10);
         printf("%c",219);
        usleep(time);

        gotoxy(14, 10);
         printf("%c",219);
        usleep(time);
        gotoxy(15, 10);
         printf("%c",219);
        usleep(time);
        gotoxy(16, 10);
         printf("%c",219);
        usleep(time);
        gotoxy(17, 10);
         printf("%c",219);
        usleep(time);
        gotoxy(18, 10);
         printf("%c",219);
        usleep(time);
        gotoxy(19, 10);
         printf("%c",219);
        usleep(time);
        gotoxy(20, 10);
         printf("%c",219);
        usleep(time);
        /// o end

        ///u

        gotoxy(23, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(23, 2);
         printf("%c",219);
        usleep(time);
        gotoxy(23, 3);
         printf("%c",219);
        usleep(time);
        gotoxy(23, 4);
         printf("%c",219);
        usleep(time);
        gotoxy(23, 5);
         printf("%c",219);
        usleep(time);
        gotoxy(23, 6);
         printf("%c",219);
        usleep(time);
        gotoxy(23, 7);
         printf("%c",219);
        usleep(time);
        gotoxy(23, 8);
         printf("%c",219);
        usleep(time);
        gotoxy(23, 9);
         printf("%c",219);
        usleep(time);

        gotoxy(24, 10);
         printf("%c",219);
        usleep(time);
        gotoxy(25, 10);
         printf("%c",219);
        usleep(time);
        gotoxy(26, 10);
         printf("%c",219);
        usleep(time);
        gotoxy(27, 10);
         printf("%c",219);
        usleep(time);
        gotoxy(28, 10);
         printf("%c",219);
        usleep(time);
        gotoxy(29, 10);
         printf("%c",219);
        usleep(time);
        gotoxy(30, 10);
         printf("%c",219);
        usleep(time);

        gotoxy(31, 9);
         printf("%c",219);
        usleep(time);
        gotoxy(31, 8);
         printf("%c",219);
        usleep(time);
        gotoxy(31, 7);
         printf("%c",219);
        usleep(time);
        gotoxy(31, 6);
         printf("%c",219);
        usleep(time);
        gotoxy(31, 5);
         printf("%c",219);
        usleep(time);
        gotoxy(31, 4);
         printf("%c",219);
        usleep(time);
        gotoxy(31, 3);
         printf("%c",219);
        usleep(time);
        gotoxy(31, 2);
         printf("%c",219);
        usleep(time);
        gotoxy(31, 1);
         printf("%c",219);
        usleep(time);

        ///u

        gotoxy(33, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(33, 2);
         printf("%c",219);
        usleep(time);
        gotoxy(33, 3);
         printf("%c",219);
        usleep(time);
        gotoxy(33, 4);
         printf("%c",219);
        usleep(time);
        gotoxy(33, 5);
         printf("%c",219);
        usleep(time);
        gotoxy(33, 6);
         printf("%c",219);
        usleep(time);
        gotoxy(33, 7);
         printf("%c",219);
        usleep(time);
        gotoxy(33, 8);
         printf("%c",219);
        usleep(time);
        gotoxy(33, 9);
         printf("%c",219);
        usleep(time);
        gotoxy(33, 10);
         printf("%c",219);
        usleep(time);

        gotoxy(34, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(35, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(36, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(37, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(38, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(39, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(40, 2);
         printf("%c",219);
        usleep(time);
        gotoxy(41, 3);
         printf("%c",219);
        usleep(time);
        gotoxy(40, 4);
         printf("%c",219);
        usleep(time);
        gotoxy(39, 5);
         printf("%c",219);
        usleep(time);
        gotoxy(38, 5);
         printf("%c",219);
        usleep(time);
        gotoxy(37, 5);
         printf("%c",219);
        usleep(time);
        gotoxy(36, 5);
         printf("%c",219);
        usleep(time);
        gotoxy(35, 5);
         printf("%c",219);
        usleep(time);
        gotoxy(34, 5);
         printf("%c",219);
        usleep(time);
        gotoxy(35, 6);
         printf("%c",219);
        usleep(time);
        gotoxy(36, 7);
         printf("%c",219);
        usleep(time);
        gotoxy(37, 8);
         printf("%c",219);
        usleep(time);
        gotoxy(38, 9);
         printf("%c",219);
        usleep(time);
        gotoxy(39, 10);
         printf("%c",219);
        usleep(time);
        /// r end;

        ///I

        gotoxy(43, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(44, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(45, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(46, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(47, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(48, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(49, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(50, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(51, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(52, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(53, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(48, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(48, 2);
         printf("%c",219);
        usleep(time);
        gotoxy(48, 3);
         printf("%c",219);
        usleep(time);
        gotoxy(48, 4);
         printf("%c",219);
        usleep(time);
        gotoxy(48, 5);
         printf("%c",219);
        usleep(time);
        gotoxy(48, 6);
         printf("%c",219);
        usleep(time);
        gotoxy(48, 7);
         printf("%c",219);
        usleep(time);
        gotoxy(48, 8);
         printf("%c",219);
        usleep(time);
        gotoxy(48, 9);
         printf("%c",219);
        usleep(time);
        gotoxy(48, 10);
         printf("%c",219);
        usleep(time);
        gotoxy(43, 10);
         printf("%c",219);
        usleep(time);
        gotoxy(44, 10);
         printf("%c",219);
        usleep(time);
        gotoxy(45, 10);
         printf("%c",219);
        usleep(time);
        gotoxy(46, 10);
         printf("%c",219);
        usleep(time);
        gotoxy(47, 10);
         printf("%c",219);
        usleep(time);
        gotoxy(49, 10);
         printf("%c",219);
        usleep(time);
        gotoxy(50, 10);
         printf("%c",219);
        usleep(time);
        gotoxy(51, 10);
         printf("%c",219);
        usleep(time);
        gotoxy(52, 10);
         printf("%c",219);
        usleep(time);
        gotoxy(53, 10);
         printf("%c",219);
        usleep(time);
        ///I end;

        /// s
        gotoxy(64, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(63, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(62, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(61, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(60, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(59, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(58, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(57, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(56, 1);
         printf("%c",219);
        usleep(time);

        gotoxy(56, 2);
         printf("%c",219);
        usleep(time);
        gotoxy(56, 3);
         printf("%c",219);
        usleep(time);
        gotoxy(56, 4);
         printf("%c",219);
        usleep(time);
        gotoxy(56, 5);
         printf("%c",219);
        usleep(time);

        gotoxy(56, 5);
         printf("%c",219);
        usleep(time);
        gotoxy(57, 5);
         printf("%c",219);
        usleep(time);
        gotoxy(58, 5);
         printf("%c",219);
        usleep(time);
        gotoxy(59, 5);
         printf("%c",219);
        usleep(time);
        gotoxy(60, 5);
         printf("%c",219);
        usleep(time);
        gotoxy(61, 5);
         printf("%c",219);
        usleep(time);
        gotoxy(62, 5);
         printf("%c",219);
        usleep(time);
        gotoxy(63, 5);
         printf("%c",219);
        usleep(time);
        gotoxy(64, 5);
         printf("%c",219);
        usleep(time);

        gotoxy(64, 6);
         printf("%c",219);
        usleep(time);
        gotoxy(64, 7);
         printf("%c",219);
        usleep(time);
        gotoxy(64, 8);
         printf("%c",219);
        usleep(time);
        gotoxy(64, 9);
         printf("%c",219);
        usleep(time);
        gotoxy(64, 10);
         printf("%c",219);
        usleep(time);

        gotoxy(63, 10);
         printf("%c",219);
        usleep(time);
        gotoxy(62, 10);
         printf("%c",219);
        usleep(time);
        gotoxy(61, 10);
         printf("%c",219);
        usleep(time);
        gotoxy(60, 10);
         printf("%c",219);
        usleep(time);
        gotoxy(59, 10);
         printf("%c",219);
        usleep(time);
        gotoxy(58, 10);
         printf("%c",219);
        usleep(time);
        gotoxy(57, 10);
         printf("%c",219);
        usleep(time);
        gotoxy(56, 10);
         printf("%c",219);
        usleep(time);
        /// s

        ///m

        gotoxy(68, 10);
         printf("%c",219);
        usleep(time);
        gotoxy(68, 9);
         printf("%c",219);
        usleep(time);
        gotoxy(68, 8);
         printf("%c",219);
        usleep(time);
        gotoxy(68, 7);
         printf("%c",219);
        usleep(time);
        gotoxy(68, 6);
         printf("%c",219);
        usleep(time);
        gotoxy(68, 5);
         printf("%c",219);
        usleep(time);
        gotoxy(68, 4);
         printf("%c",219);
        usleep(time);
        gotoxy(68, 3);
         printf("%c",219);
        usleep(time);
        gotoxy(68, 2);
         printf("%c",219);
        usleep(time);
        gotoxy(68, 1);
         printf("%c",219);
        usleep(time);

        gotoxy(69, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(70, 2);
         printf("%c",219);
        usleep(time);
        gotoxy(71, 3);
         printf("%c",219);
        usleep(time);
        gotoxy(72, 4);
         printf("%c",219);
        usleep(time);
        gotoxy(73, 3);
         printf("%c",219);
        usleep(time);
        gotoxy(74, 2);
         printf("%c",219);
        usleep(time);
        gotoxy(75, 1);
         printf("%c",219);
        usleep(time);

        gotoxy(76, 1);
         printf("%c",219);
        usleep(time);
        gotoxy(76, 2);
         printf("%c",219);
        usleep(time);
        gotoxy(76, 3);
         printf("%c",219);
        usleep(time);
        gotoxy(76, 4);
         printf("%c",219);
        usleep(time);
        gotoxy(76, 5);
         printf("%c",219);
        usleep(time);
        gotoxy(76, 6);
         printf("%c",219);
        usleep(time);
        gotoxy(76, 7);
         printf("%c",219);
        usleep(time);
        gotoxy(76, 8);
         printf("%c",219);
        usleep(time);
        gotoxy(76, 9);
         printf("%c",219);
        usleep(time);
        gotoxy(76, 10);
         printf("%c",219);
        usleep(time);
        ///m

        system("COLOR 6");

        ///m

        gotoxy(5, 25);
         printf("%c",219);
        usleep(time);
        gotoxy(5, 24);
         printf("%c",219);
        usleep(time);
        gotoxy(5, 23);
         printf("%c",219);
        usleep(time);
        gotoxy(5, 22);
         printf("%c",219);
        usleep(time);
        gotoxy(5, 21);
         printf("%c",219);
        usleep(time);
        gotoxy(5, 20);
         printf("%c",219);
        usleep(time);
        gotoxy(5, 19);
         printf("%c",219);
        usleep(time);
        gotoxy(5, 18);
         printf("%c",219);
        usleep(time);
        gotoxy(5, 17);
         printf("%c",219);
        usleep(time);
        gotoxy(5, 16);
         printf("%c",219);
        usleep(time);

        gotoxy(6, 16);
         printf("%c",219);
        usleep(time);
        gotoxy(7, 17);
         printf("%c",219);
        usleep(time);
        gotoxy(8, 18);
         printf("%c",219);
        usleep(time);
        gotoxy(9, 19);
         printf("%c",219);
        usleep(time);
        gotoxy(10, 18);
         printf("%c",219);
        usleep(time);
        gotoxy(11, 17);
         printf("%c",219);
        usleep(time);
        gotoxy(12, 16);
         printf("%c",219);
        usleep(time);

        gotoxy(13, 16);
         printf("%c",219);
        usleep(time);
        gotoxy(13, 17);
         printf("%c",219);
        usleep(time);
        gotoxy(13, 18);
         printf("%c",219);
        usleep(time);
        gotoxy(13, 19);
         printf("%c",219);
        usleep(time);
        gotoxy(13, 20);
         printf("%c",219);
        usleep(time);
        gotoxy(13, 21);
         printf("%c",219);
        usleep(time);
        gotoxy(13, 22);
         printf("%c",219);
        usleep(time);
        gotoxy(13, 23);
         printf("%c",219);
        usleep(time);
        gotoxy(13, 24);
         printf("%c",219);
        usleep(time);
        gotoxy(13, 25);
         printf("%c",219);
        usleep(time);
        ///m

        ///a

        gotoxy(15, 25);
         printf("%c",219);
        usleep(time);
        gotoxy(15, 24);
         printf("%c",219);
        usleep(time);
        gotoxy(16, 23);
         printf("%c",219);
        usleep(time);
        gotoxy(16, 22);
         printf("%c",219);
        usleep(time);
        gotoxy(17, 21);
         printf("%c",219);
        usleep(time);
        gotoxy(17, 20);
         printf("%c",219);
        usleep(time);
        gotoxy(18, 19);
         printf("%c",219);
        usleep(time);
        gotoxy(18, 18);
         printf("%c",219);
        usleep(time);
        gotoxy(19, 17);
         printf("%c",219);
        usleep(time);
        gotoxy(20, 16);
         printf("%c",219);
        usleep(time);

        gotoxy(21, 17);
         printf("%c",219);
        usleep(time);

        gotoxy(22, 18);
         printf("%c",219);
        usleep(time);
        gotoxy(22, 19);
         printf("%c",219);
        usleep(time);
        gotoxy(23, 20);
         printf("%c",219);
        usleep(time);
        gotoxy(23, 21);
         printf("%c",219);
        usleep(time);
        gotoxy(24, 22);
         printf("%c",219);
        usleep(time);
        gotoxy(24, 23);
         printf("%c",219);
        usleep(time);
        gotoxy(25, 24);
         printf("%c",219);
        usleep(time);
        gotoxy(25, 25);
         printf("%c",219);
        usleep(time);

        gotoxy(19, 21);
         printf("%c",219);
        usleep(time);
        gotoxy(20, 21);
         printf("%c",219);
        usleep(time);
        gotoxy(21, 21);
         printf("%c",219);
        usleep(time);
        ///a

        ///n

        gotoxy(27, 25);
         printf("%c",219);
        usleep(time);
        gotoxy(27, 24);
         printf("%c",219);
        usleep(time);
        gotoxy(27, 23);
         printf("%c",219);
        usleep(time);
        gotoxy(27, 22);
         printf("%c",219);
        usleep(time);
        gotoxy(27, 21);
         printf("%c",219);
        usleep(time);
        gotoxy(27, 20);
         printf("%c",219);
        usleep(time);
        gotoxy(27, 19);
         printf("%c",219);
        usleep(time);
        gotoxy(27, 18);
         printf("%c",219);
        usleep(time);
        gotoxy(27, 17);
         printf("%c",219);
        usleep(time);
        gotoxy(27, 16);
        printf("%c",219);
         usleep(time);

        gotoxy(28, 16);
         printf("%c",219);
        usleep(time);
        gotoxy(29, 17);
         printf("%c",219);
        usleep(time);
        gotoxy(30, 18);
         printf("%c",219);
        usleep(time);
        gotoxy(31, 19);
         printf("%c",219);
        usleep(time);
        gotoxy(32, 20);
         printf("%c",219);
        usleep(time);
        gotoxy(33, 21);
         printf("%c",219);
        usleep(time);
        gotoxy(34, 22);
         printf("%c",219);
        usleep(time);
         gotoxy(35, 23);
         printf("%c",219);
        usleep(time);
         gotoxy(36, 24);
         printf("%c",219);
        usleep(time);
        gotoxy(37, 25);
         printf("%c",219);
        usleep(time);

         gotoxy(38, 25);
         printf("%c",219);
        usleep(time);
        gotoxy(38, 24);
         printf("%c",219);
        usleep(time);
        gotoxy(38, 23);
         printf("%c",219);
        usleep(time);
        gotoxy(38, 22);
         printf("%c",219);
        usleep(time);
        gotoxy(38, 21);
         printf("%c",219);
        usleep(time);
        gotoxy(38, 20);
         printf("%c",219);
        usleep(time);
        gotoxy(38, 19);
         printf("%c",219);
        usleep(time);
        gotoxy(38, 18);
         printf("%c",219);
        usleep(time);
        gotoxy(38, 17);
         printf("%c",219);
        usleep(time);
        gotoxy(38, 16);
        printf("%c",219);
         usleep(time);
         ///n

         ///a

         gotoxy(40, 25);
         printf("%c",219);
        usleep(time);
        gotoxy(40, 24);
         printf("%c",219);
        usleep(time);
        gotoxy(41, 23);
         printf("%c",219);
        usleep(time);
        gotoxy(41, 22);
         printf("%c",219);
        usleep(time);
        gotoxy(42, 21);
         printf("%c",219);
        usleep(time);
        gotoxy(42, 20);
         printf("%c",219);
        usleep(time);
        gotoxy(43, 19);
         printf("%c",219);
        usleep(time);
        gotoxy(43, 18);
         printf("%c",219);
        usleep(time);
        gotoxy(44, 17);
         printf("%c",219);
        usleep(time);
        gotoxy(45, 16);
         printf("%c",219);
        usleep(time);

        gotoxy(46, 17);
         printf("%c",219);
        usleep(time);

        gotoxy(47, 18);
         printf("%c",219);
        usleep(time);
        gotoxy(47, 19);
         printf("%c",219);
        usleep(time);
        gotoxy(48, 20);
         printf("%c",219);
        usleep(time);
        gotoxy(48, 21);
         printf("%c",219);
        usleep(time);
        gotoxy(49, 22);
         printf("%c",219);
        usleep(time);
        gotoxy(49, 23);
         printf("%c",219);
        usleep(time);
        gotoxy(50, 24);
         printf("%c",219);
        usleep(time);
        gotoxy(50, 25);
         printf("%c",219);
        usleep(time);

        gotoxy(44, 21);
         printf("%c",219);
        usleep(time);
        gotoxy(45, 21);
         printf("%c",219);
        usleep(time);
        gotoxy(46, 21);
         printf("%c",219);
        usleep(time);
        ///a

         ///g

         gotoxy(63, 16);
        printf("%c",219);
         usleep(time);
         gotoxy(62, 16);
        printf("%c",219);
         usleep(time);
         gotoxy(61, 16);
        printf("%c",219);
         usleep(time);
         gotoxy(60, 16);
        printf("%c",219);
         usleep(time);
         gotoxy(59, 16);
        printf("%c",219);
         usleep(time);
         gotoxy(58, 16);
        printf("%c",219);
         usleep(time);
         gotoxy(57, 16);
        printf("%c",219);
         usleep(time);
         gotoxy(56, 16);
        printf("%c",219);
         usleep(time);
         gotoxy(55, 16);
        printf("%c",219);
         usleep(time);

         gotoxy(54, 17);
        printf("%c",219);
         usleep(time);
         gotoxy(53, 18);
        printf("%c",219);
         usleep(time);
         gotoxy(52, 19);
        printf("%c",219);
         usleep(time);
         gotoxy(52, 20);
        printf("%c",219);
         usleep(time);
         gotoxy(52, 21);
        printf("%c",219);
         usleep(time);
         gotoxy(52, 22);
        printf("%c",219);
         usleep(time);
         gotoxy(53, 23);
        printf("%c",219);
         usleep(time);
         gotoxy(54, 24);
        printf("%c",219);
         usleep(time);
         gotoxy(55, 25);
        printf("%c",219);
         usleep(time);

         gotoxy(56, 25);
        printf("%c",219);
         usleep(time);
         gotoxy(57, 25);
        printf("%c",219);
         usleep(time);
         gotoxy(58, 25);
        printf("%c",219);
         usleep(time);
         gotoxy(59, 25);
        printf("%c",219);
         usleep(time);
         gotoxy(60, 25);
        printf("%c",219);
         usleep(time);
         gotoxy(61, 25);
        printf("%c",219);
         usleep(time);
         gotoxy(62, 25);
        printf("%c",219);
         usleep(time);
         gotoxy(63, 25);
        printf("%c",219);
         usleep(time);

         gotoxy(64, 24);
        printf("%c",219);
         usleep(time);
         gotoxy(65, 23);
        printf("%c",219);
         usleep(time);
         gotoxy(65, 22);
        printf("%c",219);
         usleep(time);
         gotoxy(65, 21);
        printf("%c",219);
         usleep(time);

         gotoxy(64, 21);
        printf("%c",219);
         usleep(time);
         gotoxy(63, 21);
        printf("%c",219);
         usleep(time);
         gotoxy(62, 21);
        printf("%c",219);
         usleep(time);

         ///g

         ///e
         gotoxy(76, 16);
         printf("%c",219);
        usleep(time);
        gotoxy(75, 16);
         printf("%c",219);
        usleep(time);
        gotoxy(74, 16);
         printf("%c",219);
        usleep(time);
        gotoxy(73, 16);
         printf("%c",219);
        usleep(time);
        gotoxy(72, 16);
         printf("%c",219);
        usleep(time);
        gotoxy(71, 16);
         printf("%c",219);
        usleep(time);
        gotoxy(70, 16);
         printf("%c",219);
        usleep(time);
        gotoxy(69, 16);
         printf("%c",219);
        usleep(time);

        gotoxy(69, 16);
         printf("%c",219);
        usleep(time);
        gotoxy(69, 17);
         printf("%c",219);
        usleep(time);
        gotoxy(69, 18);
         printf("%c",219);
        usleep(time);
        gotoxy(69, 19);
         printf("%c",219);
        usleep(time);
        gotoxy(69, 20);
         printf("%c",219);
        usleep(time);
        gotoxy(69, 21);
         printf("%c",219);
        usleep(time);
        gotoxy(69, 22);
         printf("%c",219);
        usleep(time);
        gotoxy(69, 23);
         printf("%c",219);
        usleep(time);
        gotoxy(69, 24);
         printf("%c",219);
        usleep(time);
        gotoxy(69, 25);
         printf("%c",219);
        usleep(time);

        gotoxy(70, 21);
         printf("%c",219);
        usleep(time);
        gotoxy(71, 21);
         printf("%c",219);
        usleep(time);
        gotoxy(72, 21);
         printf("%c",219);
        usleep(time);
        gotoxy(73, 21);
         printf("%c",219);
        usleep(time);
        gotoxy(74, 21);
         printf("%c",219);
        usleep(time);

        gotoxy(76, 25);
         printf("%c",219);
        usleep(time);
        gotoxy(75, 25);
         printf("%c",219);
        usleep(time);
        gotoxy(74, 25);
         printf("%c",219);
        usleep(time);
        gotoxy(73, 25);
         printf("%c",219);
        usleep(time);
        gotoxy(72, 25);
         printf("%c",219);
        usleep(time);
        gotoxy(71, 25);
         printf("%c",219);
        usleep(time);
        gotoxy(70, 25);
         printf("%c",219);
        usleep(time);
        gotoxy(69, 25);
         printf("%c",219);
        usleep(time);

        ///e

         ///m

         gotoxy(78, 25);
         printf("%c",219);
        usleep(time);
        gotoxy(78, 24);
         printf("%c",219);
        usleep(time);
        gotoxy(78, 23);
         printf("%c",219);
        usleep(time);
        gotoxy(78, 22);
         printf("%c",219);
        usleep(time);
        gotoxy(78, 21);
         printf("%c",219);
        usleep(time);
        gotoxy(78, 20);
         printf("%c",219);
        usleep(time);
        gotoxy(78, 19);
         printf("%c",219);
        usleep(time);
        gotoxy(78, 18);
         printf("%c",219);
        usleep(time);
        gotoxy(78, 17);
         printf("%c",219);
        usleep(time);
        gotoxy(78, 16);
         printf("%c",219);
        usleep(time);

        gotoxy(79, 16);
         printf("%c",219);
        usleep(time);
        gotoxy(80, 17);
         printf("%c",219);
        usleep(time);
        gotoxy(81, 18);
         printf("%c",219);
        usleep(time);
        gotoxy(82, 19);
         printf("%c",219);
        usleep(time);
        gotoxy(83, 18);
         printf("%c",219);
        usleep(time);
        gotoxy(84, 17);
         printf("%c",219);
        usleep(time);
        gotoxy(85, 16);
         printf("%c",219);
        usleep(time);

        gotoxy(86, 16);
         printf("%c",219);
        usleep(time);
        gotoxy(86, 17);
         printf("%c",219);
        usleep(time);
        gotoxy(86, 18);
         printf("%c",219);
        usleep(time);
        gotoxy(86, 19);
         printf("%c",219);
        usleep(time);
        gotoxy(86, 20);
         printf("%c",219);
        usleep(time);
        gotoxy(86, 21);
         printf("%c",219);
        usleep(time);
        gotoxy(86, 22);
         printf("%c",219);
        usleep(time);
        gotoxy(86, 23);
         printf("%c",219);
        usleep(time);
        gotoxy(86, 24);
         printf("%c",219);
        usleep(time);
        gotoxy(86, 25);
         printf("%c",219);
        usleep(time);

        /// e

        gotoxy(96, 16);
         printf("%c",219);
        usleep(time);
        gotoxy(95, 16);
         printf("%c",219);
        usleep(time);
        gotoxy(94, 16);
         printf("%c",219);
        usleep(time);
        gotoxy(93, 16);
         printf("%c",219);
        usleep(time);
        gotoxy(92, 16);
         printf("%c",219);
        usleep(time);
        gotoxy(91, 16);
         printf("%c",219);
        usleep(time);
        gotoxy(90, 16);
         printf("%c",219);
        usleep(time);
        gotoxy(89, 16);
         printf("%c",219);
        usleep(time);

        gotoxy(89, 16);
         printf("%c",219);
        usleep(time);
        gotoxy(89, 17);
         printf("%c",219);
        usleep(time);
        gotoxy(89, 18);
         printf("%c",219);
        usleep(time);
        gotoxy(89, 19);
         printf("%c",219);
        usleep(time);
        gotoxy(89, 20);
         printf("%c",219);
        usleep(time);
        gotoxy(89, 21);
         printf("%c",219);
        usleep(time);
        gotoxy(89, 22);
         printf("%c",219);
        usleep(time);
        gotoxy(89, 23);
         printf("%c",219);
        usleep(time);
        gotoxy(89, 24);
         printf("%c",219);
        usleep(time);
        gotoxy(89, 25);
         printf("%c",219);
        usleep(time);

        gotoxy(90, 21);
         printf("%c",219);
        usleep(time);
        gotoxy(91, 21);
         printf("%c",219);
        usleep(time);
        gotoxy(92, 21);
         printf("%c",219);
        usleep(time);
        gotoxy(93, 21);
         printf("%c",219);
        usleep(time);
        gotoxy(94, 21);
         printf("%c",219);
        usleep(time);

        gotoxy(96, 25);
         printf("%c",219);
        usleep(time);
        gotoxy(95, 25);
         printf("%c",219);
        usleep(time);
        gotoxy(94, 25);
         printf("%c",219);
        usleep(time);
        gotoxy(93, 25);
         printf("%c",219);
        usleep(time);
        gotoxy(92, 25);
         printf("%c",219);
        usleep(time);
        gotoxy(91, 25);
         printf("%c",219);
        usleep(time);
        gotoxy(90, 25);
         printf("%c",219);
        usleep(time);
        gotoxy(89, 25);
         printf("%c",219);
        usleep(time);

        ///e

        ///n

        gotoxy(99, 25);
         printf("%c",219);
        usleep(time);
        gotoxy(99, 24);
         printf("%c",219);
        usleep(time);
        gotoxy(99, 23);
         printf("%c",219);
        usleep(time);
        gotoxy(99, 22);
         printf("%c",219);
        usleep(time);
        gotoxy(99, 21);
         printf("%c",219);
        usleep(time);
        gotoxy(99, 20);
         printf("%c",219);
        usleep(time);
        gotoxy(99, 19);
         printf("%c",219);
        usleep(time);
        gotoxy(99, 18);
         printf("%c",219);
        usleep(time);
        gotoxy(99, 17);
         printf("%c",219);
        usleep(time);
        gotoxy(99, 16);
        printf("%c",219);
         usleep(time);

        gotoxy(100, 16);
         printf("%c",219);
        usleep(time);
        gotoxy(101, 17);
         printf("%c",219);
        usleep(time);
        gotoxy(102, 18);
         printf("%c",219);
        usleep(time);
        gotoxy(103, 19);
         printf("%c",219);
        usleep(time);
        gotoxy(104, 20);
         printf("%c",219);
        usleep(time);
        gotoxy(105, 21);
         printf("%c",219);
        usleep(time);
        gotoxy(106, 22);
         printf("%c",219);
        usleep(time);
         gotoxy(107, 23);
         printf("%c",219);
        usleep(time);
         gotoxy(108, 24);
         printf("%c",219);
        usleep(time);
        gotoxy(109, 25);
         printf("%c",219);
        usleep(time);

         gotoxy(110, 25);
         printf("%c",219);
        usleep(time);
        gotoxy(110, 24);
         printf("%c",219);
        usleep(time);
        gotoxy(110, 23);
         printf("%c",219);
        usleep(time);
        gotoxy(110, 22);
         printf("%c",219);
        usleep(time);
        gotoxy(110, 21);
         printf("%c",219);
        usleep(time);
        gotoxy(110, 20);
         printf("%c",219);
        usleep(time);
        gotoxy(110, 19);
         printf("%c",219);
        usleep(time);
        gotoxy(110, 18);
         printf("%c",219);
        usleep(time);
        gotoxy(110, 17);
         printf("%c",219);
        usleep(time);
        gotoxy(110, 16);
        printf("%c",219);
         usleep(time);

         ///n

         ///t
         gotoxy(113, 16);
        printf("%c",219);
        usleep(time);
        gotoxy(114, 16);
         printf("%c",219);
        usleep(time);
        gotoxy(115, 16);
         printf("%c",219);
        usleep(time);
        gotoxy(116, 16);
         printf("%c",219);
        usleep(time);
        gotoxy(117, 16);
         printf("%c",219);
        usleep(time);
        gotoxy(118, 16);
         printf("%c",219);
        usleep(time);
         printf("%c",219);
        usleep(time);
        gotoxy(119, 16);
         printf("%c",219);
        usleep(time);
        gotoxy(120, 16);
         printf("%c",219);
        usleep(time);
        gotoxy(121, 16);
         printf("%c",219);
        usleep(time);
        gotoxy(122, 16);
         printf("%c",219);
        usleep(time);
        gotoxy(123, 16);
         printf("%c",219);
        usleep(time);
        gotoxy(118, 16);
         printf("%c",219);
        usleep(time);
        gotoxy(118, 17);
         printf("%c",219);
        usleep(time);
        gotoxy(118, 18);
         printf("%c",219);
        usleep(time);
        gotoxy(118, 19);
         printf("%c",219);
        usleep(time);
        gotoxy(118, 20);
         printf("%c",219);
        usleep(time);
        gotoxy(118, 21);
         printf("%c",219);
        usleep(time);
        gotoxy(118, 22);
         printf("%c",219);
        usleep(time);
        gotoxy(118, 23);
         printf("%c",219);
        usleep(time);
        gotoxy(118, 24);
         printf("%c",219);
        usleep(time);
        gotoxy(118, 25);
         printf("%c",219);
        usleep(time);

        Sleep(1000);
        getch();
        system("cls");

    system("COLOR 3");
    menu();
    return 0;
}

