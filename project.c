#include <stdio.h>
#include<windows.h>
#include <string.h>
#include <ctype.h>


struct people{
    char Username[20],Pass[20],email[20],tel[20],add[20];
}p1,p2;


struct item{
    char name[50];
    int stock,sell,price;
}i[10];


struct revence{
    char dates[20];
    int money;
}revence1[50];

void gotoxy(int x,int y){
		COORD c = { x, y };
		SetConsoleCursorPosition ( GetStdHandle(STD_OUTPUT_HANDLE) , c);
}

top1(){
    gotoxy(31,1);printf("++++++++++++                              +++++++++++++");
    gotoxy(31,2);printf("            *********           *********" );
    gotoxy(31,3);printf("                       Bubblepp");
    gotoxy(31,4);printf("                     Skincare Shop");
    gotoxy(31,5);printf("            *********           *********" );
    gotoxy(31,6);printf("++++++++++++                              +++++++++++++");
}


int first(){
    char select;
    top1();
    gotoxy(15,8);printf("A.Owner\n\n");
    gotoxy(15,11);printf("B.Login/Register\n\n");

    do{gotoxy(15,14);printf("Select A or B :    ");

    gotoxy(31,14);scanf("%s",&select);}
    while(tolower(select)!='a'&&tolower(select)!='b');
    return select;
}

int owner_login(){
    char select;
    system("cls");
    FILE *fp= fopen("Owner.txt","r");
    fscanf(fp,"%s %s", p1.Username,p1.Pass);
    fclose(fp);
    top1();
    gotoxy(31,9);printf("                      ==Owner Login==\n\n");
    gotoxy(31,11);printf("C.Username :");
    gotoxy(31,14);printf("D.Password: ");
    gotoxy(44,11);scanf("%s",&p2.Username);
    gotoxy(43,14);scanf("%s",&p2.Pass);

    while(strcmp(p2.Username,p1.Username)!=0||strcmp(p2.Pass,p1.Pass)!=0){
        gotoxy(31,11);printf("C.Username :                   ");
        gotoxy(31,14);printf("D.Password:                   ");
        gotoxy(49,19);printf("**Please enter again**");
        gotoxy(44,11);scanf("%s",&p2.Username);
        gotoxy(43,14);scanf("%s",&p2.Pass);
    }
}

int owner_select(){
    char select;
    system("cls");
    top1();
    gotoxy(31,9);printf("                      ==Owner  Select==");
    gotoxy(31,11);printf("1.Stock");
    gotoxy(31,13);printf("2.Order list");
    gotoxy(31,15);printf("3.Account");
    gotoxy(31,17);printf("4.Back at home");
    gotoxy(31,19);printf("Select 1,2,3,4:      ");
    gotoxy(50,19);scanf("%s",&select);
    system("cls");
    return select;
}

int log_Regi(){
   char select;
   system("cls");
   top1();
   gotoxy(31,9);printf("                      ==Member==");
   gotoxy(31,13);printf("            A.Login             B.Register");
   gotoxy(16,15);printf("Select A or B: ");scanf("%s",&select);
    return select;
}
//**fc register
int Regi(){
    system("cls");
    top1();
    gotoxy(31,9);printf("                      ==Register==\n\n");
    gotoxy(31,11);printf("Username: ");
    scanf("%40s",p1.Username);
    gotoxy(31,13);printf("Password: ");
    scanf("%40s",p1.Pass);
    gotoxy(31,15);printf("E-mail:   ");
    scanf("%40s",p1.email);
    gotoxy(31,17);printf("Tel:      ");
    scanf("%40s",p1.tel);
    fflush(stdin);
    gotoxy(31,19);printf("Address:  ");
    gets(p1.add);
    FILE *fp= fopen("Member.txt","a");
    fprintf(fp,"%s\n%s \n%s \n%s \n%s\n",p1.Username,p1.Pass,p1.email,p1.tel,p1.add);
    system("cls");
    fclose(fp);
}

void member_login(){
    system("cls");
    top1();
    gotoxy(31,9);printf("                   ==Member Login==");
    gotoxy(31,11);printf("C.Username :");
    gotoxy(31,14);printf("D.Password : ");
    gotoxy(44,11);scanf("%s",&p2.Username);
    gotoxy(44,14);scanf("%s",&p2.Pass);

    FILE *fp= fopen("member.txt","r");
    do{fscanf(fp,"%s",p1.Username);
        fscanf(fp,"%s %s %s",p1.Pass,p1.email,p1.tel);
        fscanf(fp,"%s",p1.add);
        if(feof(fp)){
            gotoxy(31,11);printf("C.Username :                 ");
            gotoxy(31,14);printf("D.Password :                  ");
            gotoxy(49,16);printf("**Please enter again**");
            gotoxy(44,11);scanf("%s",&p2.Username);
            gotoxy(44,14);scanf("%s",&p2.Pass);
            fseek( fp, 0, SEEK_SET );
            }
    }while(strcmp(p2.Username,p1.Username)!=0||strcmp(p2.Pass,p1.Pass)!=0);
    fclose(fp);
}

int member_select(){
   char select;
   system("cls");
   top1();
   gotoxy(31,9);printf("                      ==Member Select==");
   gotoxy(31,11);printf("A.goods");
   gotoxy(31,13);printf("B.Contact");
   gotoxy(31,15);printf("C.Log out");
   gotoxy(31,17);printf("Select A,B,C: ");scanf("%s",&select);
    system("cls");
    return select;
}

char Stock(){
   char select;
   int Brand,Volume;
   system("cls");

   top1();
   gotoxy(31,9);printf("                      ==Stock==\n\n");
   gotoxy(25,10);printf("--------------------------------------------------------------------\n");
   gotoxy(25,11);printf("  Brand                                       Volume          Price\n");
   gotoxy(25,12);printf("--------------------------------------------------------------------\n\n");
   FILE *fp;
   fp= fopen("Stock.txt","r");
    char h[50];
    for(int a=0;a<10;a++){
        fgets(i[a].name,50,fp);
        fscanf(fp,"%d %d %d",&i[a].stock,&i[a].sell,&i[a].price);
        fgets(h,50,fp);
    }fclose(fp);
    do{
    gotoxy(25,13);printf("1.sunkiss(envelope)                          %3d               70",i[0].stock);
    gotoxy(25,14);printf("2.sunkiss(tube)                              %3d              390",i[1].stock);
    gotoxy(25,15);printf("3.Gala Body(small)                           %3d              190",i[2].stock);
    gotoxy(25,16);printf("4.Gala Body(big)                             %3d              390",i[3].stock);
    gotoxy(25,17);printf("5.Serum Vit c                                %3d              450",i[4].stock);
    gotoxy(25,18);printf("6.Muse Muse Skin(s)                          %3d              130",i[5].stock);
    gotoxy(25,19);printf("7.Muse Muse Skin(m)                          %3d              190",i[6].stock);
    gotoxy(25,20);printf("8.Muse Muse Skin(l)                          %3d              390",i[7].stock);
    gotoxy(25,21);printf("9.Sibling Bright And Muist                   %3d              340",i[8].stock);
    gotoxy(25,22);printf("10.Rervitalizing Cream                       %3d              420",i[9].stock);
    do{
    gotoxy(25,23);printf("Add goods enter (A) Delete enter (B) :   ");
    gotoxy(25,24);printf("Brand Member :                              ");
    gotoxy(25,25);printf("Volume :                                          ");
    gotoxy(25,26);printf("Back at home enter (Y/N) :   ");
    gotoxy(64,23);scanf("%s",&select);
    gotoxy(40,24);scanf("%d",&Brand);
    gotoxy(34,25);scanf("%d",&Volume);
    if(tolower(select)=='a'){
            if(Brand==1){
                i[0].stock+=Volume;
            }else if(Brand==2){
                i[1].stock+=Volume;
            }else if(Brand==3){
                i[2].stock+=Volume;
            }else if(Brand==4){
                i[3].stock+=Volume;
            }else if(Brand==5){
                i[4].stock+=Volume;
            }else if(Brand==6){
                i[5].stock+=Volume;
            }else if(Brand==7){
                i[6].stock+=Volume;
            }else if(Brand==8){
                i[7].stock+=Volume;
            }else if(Brand==9){
                i[8].stock+=Volume;
            }else if(Brand==10){
                i[9].stock+=Volume;
            }
       }else if(tolower(select)=='b'){
            if(Brand==1){
                i[0].stock-=Volume;
            }else if(Brand==2){
                i[1].stock-=Volume;
            }else if(Brand==3){
                i[2].stock-=Volume;
            }else if(Brand==4){
                i[3].stock-=Volume;
            }else if(Brand==5){
                i[4].stock-=Volume;
            }else if(Brand==6){
                i[5].stock-=Volume;
            }else if(Brand==7){
                i[6].stock-=Volume;
            }else if(Brand==8){
                i[7].stock-=Volume;
            }else if(Brand==9){
                i[8].stock-=Volume;
            }else if(Brand==10){
                i[9].stock-=Volume;
            }
       }
    }
      while(tolower(select)!='a'&&tolower(select)!='b');
       fp= fopen("Stock.txt","w");
       for(int a=0;a<10;a++){
            fprintf(fp,"%s",i[a].name);
            fprintf(fp,"%d %d %d\n",i[a].stock,i[a].sell,i[a].price);
        }
       fclose(fp);
       do{gotoxy(25,26);printf("Back at home enter (Y/N) :   ");
       gotoxy(52,26);scanf("%s",&select);}
       while(tolower(select)!='y'&&tolower(select)!='n');
   }while(tolower(select)!='y');
}

int order(){
    char ct_n[50];
    char h[50];
    FILE *fp= fopen("Stock.txt","r");
    for(int a=0;a<10;a++){
        fgets(i[a].name,50,fp);
        fscanf(fp,"%d %d %d",&i[a].stock,&i[a].sell,&i[a].price);
        fgets(h,50,fp);
    }
    fclose(fp);
    system("cls");
    top1();
    gotoxy(25,10);printf("--------------------------------------------------------------------\n");
    gotoxy(25,11);printf("  Brand                                       Volume          Price\n");
    gotoxy(25,12);printf("--------------------------------------------------------------------\n\n");
    gotoxy(31,8);printf("                     ==Orderlist==");
    gotoxy(25,13);printf("1.sunkiss(envelope)                           %3d               70",i[0].sell);
    gotoxy(25,14);printf("2.sunkiss(tube)                               %3d              390",i[1].sell);
    gotoxy(25,15);printf("3.Gala Body(small)                            %3d              190",i[2].sell);
    gotoxy(25,16);printf("4.Gala Body(big)                              %3d              390",i[3].sell);
    gotoxy(25,17);printf("5.Serum Vit c                                 %3d              450",i[4].sell);
    gotoxy(25,18);printf("6.Muse Muse Skin(s)                           %3d              130",i[5].sell);
    gotoxy(25,19);printf("7.Muse Muse Skin(m)                           %3d              190",i[6].sell);
    gotoxy(25,20);printf("8.Muse Muse Skin(l)                           %3d              390",i[7].sell);
    gotoxy(25,21);printf("9.Sibling Bright And Muist                    %3d              340",i[8].sell);
    gotoxy(25,22);printf("10.Rervitalizing Cream                        %3d              420",i[9].sell);
    getch();
}

int Account(){
    char dmy[15],dmy_put[8],dmy2[15],y=15;
    system("cls");
    top1();
    gotoxy(25,8);printf("                            ==Account==\n\n");
    gotoxy(10,11);printf("Enter the month and year(12/2000) : ");scanf("%s",&dmy_put);

    int price_in,Total=0;
    int line_income=0;
    char cc[100];
    FILE *fpp= fopen("revence.txt","r");
    while(fgets(cc,100,fpp)!=NULL){
        line_income+=1;
    }fseek( fpp, 0, SEEK_SET );

    for(int a=0;a<line_income;a++){
        fscanf(fpp,"%s        %4d",&dmy,&price_in);
        strcpy(dmy2,dmy+3);
        if(strcmp(dmy2,dmy_put)==0){
            gotoxy(25,12);printf("        ------------------------------------------------");
            gotoxy(25,13);printf("                Date                   revenue          \n");
            gotoxy(25,14);printf("        ------------------------------------------------");
            gotoxy(25,y);printf("              %8s                %4d\n",dmy,price_in);y++;
            Total+=price_in;
        }
    }
    fclose(fpp);
    printf("          Total :   %d   Baht",Total);
    getche();
}


int good_output(int *stock,int *sell,int Vol){
    *stock-=Vol;
    *sell+=Vol;
}

int good(){
    int Brand,Volume,select,item[10],y=13,Total=0,Cash;

    time_t timer;
    struct tm* tm_info;
    char dmy_cp[20];
    time(&timer);
    tm_info = localtime(&timer);
    strftime(dmy_cp, 20, "%d/%m/%Y", tm_info);
    for(int i=0;i<10;i++){
        item[i]=0;
    }
    FILE *fp= fopen("Stock.txt","r");
    char h[50];
    for(int a=0;a<10;a++){
        fgets(i[a].name,50,fp);
        fscanf(fp,"%d %d %d",&i[a].stock,&i[a].sell,&i[a].price);
        fgets(h,50,fp);
    }
    fclose(fp);
    system("cls");
    top1();
    gotoxy(31,8);printf("                      ==Goods==");
    gotoxy(31,10);printf("--------------------------------------------------------------------");
    gotoxy(31,11);printf("  Brand                                                        Price\n");
    gotoxy(31,12);printf("--------------------------------------------------------------------");
    gotoxy(31,14);printf("1.sunkiss(envelope)                                              70");
    gotoxy(31,16);printf("2.sunkiss(tube)                                                 390");
    gotoxy(31,18);printf("3.Gala Body(small)                                              190");
    gotoxy(31,20);printf("4.Gala Body(big)                                                390");
    gotoxy(31,22);printf("5.Serum Vit c                                                   450");
    gotoxy(31,24);printf("6.Muse Muse Skin(s)                                             130");
    gotoxy(31,26);printf("7.Muse Muse Skin(m)                                             190");
    gotoxy(31,28);printf("8.Muse Muse Skin(l)                                             390");
    gotoxy(31,30);printf("9.Sibling Bright And Muist                                      340");
    gotoxy(31,32);printf("10.Rervitalizing Cream                                          420");
    do{gotoxy(31,34);printf("Brand Member :                              ");
        gotoxy(31,36);printf("Volume :                                                   ");
        gotoxy(31,38);printf("Do you want to buy more(x) or enought(y):                                              ");
        gotoxy(46,34);scanf("%d",&Brand);
        gotoxy(40,36);scanf("%d",&Volume);
        item[Brand-1]+=Volume;

        good_output(&i[Brand-1].stock,&i[Brand-1].sell,Volume);
        FILE *fp= fopen("Stock.txt","w");
        for(int a=0;a<10;a++){
            fprintf(fp,"%s",i[a].name);
            fprintf(fp,"%d %d %d\n",i[a].stock,i[a].sell,i[a].price);
        }
        fclose(fp);
       do{gotoxy(31,38);printf("Do you want to buy more(x) or enought(y):  ");
          gotoxy(75,38);scanf("%s",&select);}
       while(tolower(select)!='y'&&tolower(select)!='x');
   }while(tolower(select)!='y');
    system("cls");
    top1();
    gotoxy(31,8);printf("                     ==Payment==");
    gotoxy(31,10);printf("-------------------------------------------------------------------\n");
    gotoxy(31,11);printf("  Brand                             Volume              Price\n");
    gotoxy(31,12);printf("-------------------------------------------------------------------\n\n");
    if(item[0]!=0){
        gotoxy(31,y);printf("sunkiss(envelope)                 %3d                    %4d",item[0],70*item[0]);y++;
    }if(item[1]!=0){
        gotoxy(31,y);printf("sunkiss(tube)                     %3d                    %4d",item[1],390*item[1]);y++;
    }if(item[2]!=0){
        gotoxy(31,y);printf("Gala Body(small)                  %3d                    %4d",item[2],190*item[2]);y++;
    }if(item[3]!=0){
        gotoxy(31,y);printf("Gala Body(big)                    %3d                    %4d",item[3],390*item[3]);y++;
    }if(item[4]!=0){
        gotoxy(31,y);printf("Serum Vit c                       %3d                    %4d",item[4],450*item[4]);y++;
    }if(item[5]!=0){
        gotoxy(31,y);printf("Muse Muse Skin(s)                 %3d                    %4d",item[5],130*item[5]);y++;
    }if(item[6]!=0){
        gotoxy(31,y);printf("Muse Muse Skin(m)                 %3d                    %4d",item[6],190*item[6]);y++;
    }if(item[7]!=0){
        gotoxy(31,y);printf("Muse Muse Skin(l)                 %3d                    %4d",item[7],390*item[7]);y++;
    }if(item[8]!=0){
        gotoxy(31,y);printf("Sibling Bright And Muist          %3d                    %4d",item[8],340*item[8]);y++;
    }if(item[9]!=0){
        gotoxy(31,y);printf("Rervitalizing Cream               %3d                    %4d",item[9],420*item[9]);y++;
    }
    Total=70*item[0]+390*item[1]+190*item[2]+390*item[3]+450*item[4]+130*item[5]+190*item[6]+390*item[7]
         +item[8],340*item[8]+420*item[9];

    int count_line=0;

    char c[50];
    FILE *f1=fopen("revence.txt","r");
    while(fgets(c,500,f1)!=NULL){
        count_line+=1;
    }
    int price_in[count_line],test=0 ;
    char dmy[count_line][20];
    fseek( f1, 0, SEEK_SET );
    for(int i=0;i<count_line;i++){
        fscanf(f1,"%s %d",&dmy[i],&price_in[i]);
        if((strcmp(dmy[i],dmy_cp))==0 ){
            price_in[i]+=Total;
            test=1;
        }
    }
    fclose(f1);

    if(test==1){
        FILE *f2=fopen("revence.txt","w");
        for(int i=0;i<count_line;i++){
            fprintf(f2,"%s %4d\n",dmy[i],price_in[i]);
        }
        fclose(f2);
    }else{
        FILE *f2=fopen("revence.txt","a");
        fprintf(f2,"%s %4d\n",dmy_cp,Total);
        fclose(f2);
    }
    gotoxy(31,y);printf("Total   : %4d",Total);y++;
    gotoxy(31,y);printf("Cash    : ");scanf("%4d",&Cash);y++;
    gotoxy(31,y);printf("Change  : %4d",Cash-Total);y++;
    gotoxy(31,y);printf("               ***********Thank you***********");
    getch();
}

int contact(){
   char ct_n[50],mu[100];
   system("cls");
   top1();
   gotoxy(31,8);printf("                     ==Contact==");
   gotoxy(31,10);printf("Offers and Advice: ");
   gets(mu);
   gets(ct_n);
   FILE *fp= fopen("contact.txt","a");
   fprintf(fp,"%s\n",ct_n);
   fclose(fp);
}

main(){
    char select,select_stock,select_order;
    while(1){

        select=first();
        if(tolower(select)=='a'){
            do{system("cls");
                owner_login();
                do{select=owner_select();
                    if(tolower(select)=='1'){
                        select_stock=Stock();
                    }else if(tolower(select)=='2'){
                        select_order=order();
                    }else if(tolower(select)=='3'){
                        select=Account();
                    }
                }while(select!='4');
            }while(select=='4');
        }else{
            select=log_Regi();
            if(tolower(select)=='a'){
                member_login();
                do{select=member_select();
                    if(tolower(select)=='a'){
                        good();
                    }else if(tolower(select)=='b'){
                        contact();
                    }
                }while(tolower(select)!='c');
            }else{
                Regi();
            }
        }
    }

}











