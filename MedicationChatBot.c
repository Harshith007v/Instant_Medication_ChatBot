#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>   //FOR TIME
void intro(); //DECLARATION OF INTRO FUNCTION
void review(); //DECLARATION OF REVIEW FUNCTION
int n,i,a=0,sum=0,g,num=0,option_intro,operation,option_while,age_med,option_med,scale;
char name[100],complain[500];
struct hospital
{
    char name[30],Doctor[20];
    char disease[30];
    double phone;
    int room,age;
} x[100];
void add(){
    SYSTEMTIME s;
    GetLocalTime(&s);
    FILE *fp=fopen("database_info.txt","a");
    if(fp==NULL)
    {
        printf("FILE DOES NOT EXIT\n");
        exit(1);
    }
    system("cls");
    printf("\n\n");
    printf("\t\tThe number of database entered is=%d\n",num);
    printf("\n\t\tHow many additional Entries is required:");
    scanf("%d",&n);
    sum=n+num;
    for(i=num; i<sum; i++)
    {
        printf("\n");
        fprintf(fp,"\nNEW ENTRY :\n");
        printf("\t\tEnter patient's Name = ");
        scanf("%s",x[i].name);
        fprintf(fp,"PATIENT_NAME: %s\n",x[i].name);

        printf("\t\tEnter The name of the Doctor = ");
        scanf("%s",x[i].Doctor);
        fprintf(fp,"DOCTOR_NAME: %s\n",x[i].Doctor);

        printf("\t\tEnter disease = ");
        scanf("%s",x[i].disease);
        fprintf(fp,"DISEASE: %s\n",x[i].disease);

        printf("\t\tEnter the age = ");
        scanf("%d",&x[i].age);
        fprintf(fp,"AGE: %d\n",x[i].age);

        printf("\t\tEnter room no = ");
        scanf("%d",&x[i].room);
        fprintf(fp,"ROOM_NO: %d\n",x[i].room);

        printf("\t\tEnter phone number = ");
        scanf("%lf",&x[i].phone);
        fprintf(fp,"PHONE_NO: %lf\n",x[i].phone);
        printf("\n");

        num++;
    }
    printf("\t\t\t\t\t\t\t\t\t\tDATE : %d/%d/%d\n",s.wDay,s.wMonth,s.wYear);
    printf("\t\t\t\t\t\t\t\t\t\tTIME : %d:%d:%d\n",s.wHour,s.wMinute,s.wSecond);
    fclose(fp);
}
void view(){
    for(i=0;i<num;i++){
        printf("\n");
        printf("\t\tSerial Number:%d\n",i);
        printf("\t\tPatient's Name:%s\n",x[i].name);
        printf("\t\tDoctor's Name:%s\n",x[i].Doctor);
        printf("\t\tDisease:%s\n",x[i].disease);
        printf("\t\tAge:%d\n",x[i].age);
        printf("\t\tRoom no:%d\n",x[i].room);
        printf("\t\tPhone Number:%lf\n",x[i].phone);
        printf("\n\n");
    }
}
void edit(){
    SYSTEMTIME s;
    GetLocalTime(&s);
    int q,p;
    printf("\n\n");
    printf("\t\tWhat do you want to edit ?\n");
    printf("\t\tEnter your option\n");
    printf("\t\t1.Patient Name\n\t\t2.Doctor's Name\n\t\t3.Disease\n\t\t4.Age\n\t\t5.Room no\n\t\t6.Phone no.\n");
    printf("\n\t\tOption=");
    scanf("%d",&q);//option
    if(q<=6)
    {
        printf("\n\t\tEnter the serial no of that patient= (0 - %d)=",num-1);
        scanf("%d",&p);//serial number
        if(p<num)
        {
            switch(q){
            case 1:
                printf("\n\t\tEnter the new name=");
                scanf("%s",x[p].name);
                printf("\n\t\tUPDATED AT: %d:%d:%d\n",s.wHour,s.wMinute,s.wSecond);
                break;
            case 2:
                printf("\n\t\tEnter the new Doctor's Name=");
                scanf("%s",x[p].Doctor);
                printf("\n\t\tUPDATED AT: %d:%d:%d\n",s.wHour,s.wMinute,s.wSecond);
                break;
            case 3:
                printf("\n\t\tEnter the new Disease=");
                scanf("%s",x[p].disease);
                printf("\n\t\tUPDATED AT: %d:%d:%d\n",s.wHour,s.wMinute,s.wSecond);
                break;
            case 4:
                printf("\n\t\tEnter the new Age=");
                scanf("%d",&x[p].age);
                printf("\n\t\tUPDATED AT: %d:%d:%d\n",s.wHour,s.wMinute,s.wSecond);
                break;
            case 5:
                printf("\n\t\tEnter the new Room no=");
                scanf("%d",&x[p].room);
                printf("\n\t\tUPDATED AT: %d:%d:%d\n",s.wHour,s.wMinute,s.wSecond);
                break;
            case 6:
                printf("\n\t\tEnter the new Phone no =");
                scanf("%lf",x[p].phone);
                printf("\n\t\tUPDATED AT: %d:%d:%d\n",s.wHour,s.wMinute,s.wSecond);
                break;
            default:
                printf("\n\n\t\tINVALID INPUT\n\n");
            }
        }
        else
        {
            printf("\n\n\t\tInvalid Serial \n\t\tTry Again !!\n\n");
        }
    }
    else
    {
        printf("\n\n\t\tInvalid option\n\t\tTry Again!!\n\n");
    }
}
void search()
{
    int s,h,f;
    char u[100];
    printf("\n\n");
    printf("\t\tBy what do you want to search ?\n");
    printf("\t\t1.Serial no.\n\t\t2.Name\n\t\t3.Doctor's_Name\n\t\t4.Disease\n\t\t5.Age.\n\t\t6.Room No.\n\t\t7.Phone no.\n\n\t\tOption = ");
    scanf("%d",&h);
    if(h==1)
    {
        printf("\n\t\tEnter Serial number of the patient=");
        scanf("%d",&s);
        if(s<num)
        {
            printf("\n");
            printf("\t\tSerial Number=%d\n",s);
            printf("\t\tName = %s\n",x[s].name);
            printf("\t\tDoctor's Name = %s\n",x[s].Doctor);
            printf("\t\tDisease = %s\n",x[s].disease);
            printf("\t\tAge = %d\n",x[s].age);
            printf("\t\tRoom No = %d\n",x[s].room);
            printf("\t\tPhone No = %lf\n",x[s].phone);
            printf("\n\n");
        }
        else
            printf("\n\n\t\tNot Found\n\n");
    }
    else if(h==2)
    {
        int f=1;
        printf("\n\t\tEnter your name=");
        scanf("%s",u);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,x[g].name)==0)
            {
                printf("\n");
                printf("\t\tSerial Number=%d\n",g);
                printf("\t\tName = %s\n",x[g].name);
                printf("\t\tDoctor's Name = %s\n",x[g].Doctor);
                printf("\t\tDisease = %s\n",x[g].disease);
                printf("\t\tAge = %d\n",x[g].age);
                printf("\t\tRoom No = %d\n",x[g].room);
                printf("\t\tPhone No = %lf\n",x[g].phone);
                printf("\n\n");
                f=0;

            }
        }
        if(f==1)
            printf("\n\t\tNot Found\n");



    }
    else if(h==3)
    {
        int f=1;
        printf("\n\t\tEnter Disease = ");
        scanf("%s",u);
        //fflush(stdin);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,x[g].Doctor)==0)
            {
                printf("\n");
                printf("\t\tSerial Number=%d\n",g);
                printf("\t\tName = %s\n",x[g].name);
                printf("\t\tDoctor's Name = %s\n",x[g].Doctor);
                printf("\t\tDisease = %s\n",x[g].disease);
                printf("\t\tAge = %d\n",x[g].age);
                printf("\t\tRoom No = %d\n",x[g].room);
                printf("\t\tPhone No = %lf\n",x[g].phone);
                printf("\n\n");
                f=0;
            }


        }
        if(f==1)
            printf("\n\t\tNot Found\n");


    }
    else if(h==4)
    {
        int f=1;
        printf("\n\t\tEnter Disease = ");
        scanf("%s",u);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,x[g].disease)==0)
            {
                 printf("\n");
                printf("\t\tSerial Number=%d\n",g);
                printf("\t\tName = %s\n",x[g].name);
                printf("\t\tDoctor's Name = %s\n",x[g].Doctor);
                printf("\t\tDisease =%s\n",x[g].disease);
                printf("\t\tAge = %d\n",x[g].age);
                printf("\t\tRoom No = %d\n",x[g].room);
                printf("\t\tPhone No = %lf\n",x[g].phone);
                printf("\n\n");
                f=0;
            }

        }
        if(f==1)
            printf("\t\tNot Found\n\n");

    }
    else if(h==6)
    {
        int f=1;
        printf("\n\t\tEnter Room number = ");
        scanf("%d",&f);
        for(g=0; g<num; g++)
        {
            if(f==x[g].room)
            {
                printf("\n");
                printf("\t\tSerial Number=%d\n",g);
                printf("\t\tName = %s\n",x[g].name);
                printf("\t\tDoctor's Name = %s\n",x[g].Doctor);
                printf("\t\tDisease = %s\n",x[g].disease);
                printf("\t\tAge = %d\n",x[g].age);
                printf("\t\tRoom No = %d\n",x[g].room);
                printf("\t\tPhone No = %lf\n",x[g].phone);
                printf("\n\n");
                f=0;
            }

        }
        if(f==1)
            printf("\n\t\tNot Found");
    }
    else if(h==5)
    {
        int f=1;
        printf("\n\t\tEnter Age = ");
        scanf("%d",&f);
        for(g=0; g<num; g++)
        {
            if(f==x[g].age)
            {
                printf("\n");
                printf("\t\tSerial Number=%d\n",g);
                printf("\t\tName = %s\n",x[g].name);
                printf("\t\tDoctor's Name = %s\n",x[g].Doctor);
                printf("\t\tDisease = %s\n",x[g].disease);
                printf("\t\tAge = %d\n",x[g].age);
                printf("\t\tRoom No = %d\n",x[g].room);
                printf("\t\tPhone No = %lf\n",x[g].phone);
                printf("\n\n");
                f=0;
            }

        }
        if(f==1)
            printf("\t\tNot Found\n\n");

    }
    else if(h==7){
        double f=1;
        printf("\n\t\tEnter your Phone number =");
        scanf("%lf",&f);
        for(g=0; g<num; g++)
        {
            if(f==x[g].phone)
            {
                printf("\n");
                printf("\t\tSerial Number=%d\n",g);
                printf("\t\tName = %s\n",x[g].name);
                printf("\t\tDoctor's Name = %s\n",x[g].Doctor);
                printf("\t\tDisease = %s\n",x[g].disease);
                printf("\t\tAge = %d\n",x[g].age);
                printf("\t\tRoom No = %d\n",x[g].room);
                printf("\t\tPhone No = %lf\n",x[g].phone);
                printf("\n\n");
                f=0;

            }
        }
        if(f==1)
            printf("\n\t\tNot Found\n");

    }
    else{
        printf("\n\n\t\tInvalid input\n\n");
    }
}
void del(){
    SYSTEMTIME s;
    GetLocalTime(&s);
    int f,h;
    printf("\n\n");
    printf("\t\tEnter the serial number of the patient that you want to delete=");
    scanf("%d",&f);
    if(f<num)
    {
        printf("\n\t\tWhat do you want ?\n");
        printf("\t\t1.Remove the whole record\n\t\t2.Remove Name\n\t\t3.Remove DOctor's Name\n\t\t4.Remove Disease\n\t\t5.Remove Age\n\t\t6.Remove room number\n\t\t7.Remove phone Number\n\n\t\tOption = ");
        scanf("%d",&h);
        if(h==1)
        {
            while(f<num)
            {
                strcpy(x[f].name,x[f+1].name);
                strcpy(x[f].disease,x[f+1].disease);
                strcpy(x[f].Doctor,x[f+1].Doctor);
                x[f].age=x[f+1].age;
                x[f].room=x[f+1].room;
                x[f].phone=x[f+1].phone;
                f++;
            }
            num--;
            printf("\n\t\tDELETED AT: %d:%d:%d\n",s.wHour,s.wMinute,s.wSecond);
        }
        else if(h==2)
        {
            strcpy(x[f].name,"Cleared");
            printf("\n\t\tDELETED AT: %d:%d:%d\n",s.wHour,s.wMinute,s.wSecond);

        }
        else if(h==3)
        {
            strcpy(x[f].Doctor,"Cleared");
            printf("\n\t\tDELETED AT: %d:%d:%d\n",s.wHour,s.wMinute,s.wSecond);
        }
        else if(h==4)
        {
            strcpy(x[f].disease,"Cleared");
            printf("\n\t\tDELETED AT: %d:%d:%d\n",s.wHour,s.wMinute,s.wSecond);
        }
        else if(h==5)
        {
            x[f].age=0;
            printf("\n\t\tDELETED AT: %d:%d:%d\n",s.wHour,s.wMinute,s.wSecond);
        }
        else if(h==6)
        {
            x[f].room=0;
            printf("\n\t\tDELETED AT: %d:%d:%d\n",s.wHour,s.wMinute,s.wSecond);
        }
        else if(h==7)
        {
            x[f].phone=0;
            printf("\n\t\tDELETED AT: %d:%d:%d\n",s.wHour,s.wMinute,s.wSecond);
        }
        else{
            printf("\n\n\t\tInvalid Input\n\n");
        }

    }
    else
        printf("\n\n\t\tInvalid Serial number\n");

}
void medicine()
{
    FILE *fp=fopen("database_medicine.txt","a");
    if (fp==NULL)
    {
        printf("FILE DOES NOT EXIT\n");
        exit(1);
    }
    printf("\n\n");
    printf("\t\t\t****************************************************************************");
    printf("\n\n\n");
    printf("\t\t\t\t\t Welcome to INSTANT MEDICATION CHATBOX!!!\n");
    printf("\n\n");
    printf("\t\t\t****************************************************************************");
    printf("\n\n\n");
    printf("\t\t\t\t\t\tEnter your name:");
    fflush(stdin);
    gets(name);
    fprintf(fp,"\nNEW ENTRY:\n");
    fprintf(fp,"NAME:%s\n",name);
    printf("\t\t\t\t\t\tEnter your age:");
    scanf("%d",&age_med);
    fprintf(fp,"AGE:%d\n",age_med);
    fclose(fp);
    while(option_med!=11)
    {
    system("cls");
    printf("\n\n\n");
    backmed:printf("\n"); //goto label -->backmed
    printf("\t\tWHICH SYMPTOM ARE YOU SUFFERING FROM?\n");
    printf("\t\tPress 1 for 'FEVER'\n");
    printf("\t\tPress 2 for 'COLD'\n");
    printf("\t\tPress 3 for 'ALLERGY'\n");
    printf("\t\tPress 4 for 'COUGH'\n");
    printf("\t\tPress 5 for 'PAINKILLER'\n");
    printf("\t\tPress 6 for 'ANTIBOITICS'\n");
    printf("\t\tPress 7 for 'MOTION CLEAR SYRUP'\n");
    printf("\t\tPress 8 for 'SKINFUNGAL INFECTION'\n");
    printf("\t\tPress 9 for 'ACIDITY'\n");
    printf("\t\tPress 10 for 'HEADACHE'\n");
    printf("\t\tPress 11 TO EXIT!!!\n");
    printf("\n");
    printf("\t\tFOR WHICH SYMPTOM DO YOU MEDICATION?:");
    scanf("%d",&option_med);
    switch(option_med)
    {
    case 1:printf("\n\t\tFor FEVER,use:\n");
            printf("\t\tPARACETAMOL TABLETS IP 500MG\n");
            printf("\t\tPARACETAMOL TABLETS IP 650MG\n");
            break;
    case 2:printf("\n\t\tFor COLD,use:\n");
            printf("\t\tCETRIZINE DIHYDROCHLORIDE IP 5MG\n");
            printf("\t\tPHENYLEPHRINE HYDROCHOLORIDE 10MG\n");
            break;
    case 3:printf("\n\t\tFor ALLERGY,use:\n");
            printf("\t\tLEVOCETRIZINE DIHYDROCHLORIDE IP 5MG\n");
            printf("\t\tMONTELUKAST 10 MG TABLET\n");
            break;
    case 4:printf("\n\t\tFor COUGH,use:\n");
            printf("\t\tLEVOSALBUTAMOL SUPLHATE 1MG\n");
            printf("\t\tAMBROXOL HYDROCHLORIDE 30MG\n");
            break;
    case 5:printf("\n\t\tFor PAINKILLER's,use:\n");
            printf("\t\tACECLOFENAC 100MG\n");
            printf("\t\tPARACETAMOL 325MG\n");
            break;
    case 6:printf("\n\t\tFor ANTIBIOTIC's,use:\n");
            printf("\t\tAMOXYCILLIN 500MG\n");
            printf("\t\tCEFIXIME 200 MG TABLET\n");
            break;
    case 7:printf("\n\t\tFor MOTION CLEARANCE,use:\n");
            printf("\t\tLIQUID PARAFFIN 1.25ML SYRUP\n");
            printf("\t\tLACTULOSE 10GM/15ML SYRUP\n");
            break;
    case 8:printf("\n\t\tFor SKIN FUNGAL INFECTION's,use:\n");
            printf("\t\tITRACONAZOLE 200MG CAPSULES\n");
            printf("\t\tTERBINAFINE 250 MG TABLETS\n");
            break;
    case 9:printf("\n\t\tFor ACIDITY,use:\n");
            printf("\t\tRABEPRAZOLE 20MG + DOMPERIDONE 30 MG CAPSULE\n");
            printf("\t\tMAGNESIUM HYDROXIDE 250 MG and  ACTIVATED DIMETHICONE 50 MG SUSPENSION\n");
            break;
    case 10:printf("\n\t\tFor HEADACHE,use:\n");
            printf("\t\tADVIL\n");
            printf("\t\tMOTRIN\n");
            break;
    case 11:system("cls");
            review();
            exit(1);
    default:system("cls");
            printf("\n\n\t\t\t   Invalid Input\n");
            printf("\n\t\tPLEASE SELECT THE AVAILABLE OPTIONS\n");
            goto backmed;
}
printf("\n");
printf("\n");
printf("\t\tUSE ANY OF THE TWO GIVEN MEDICINE/TABLETS.\n\t\tFOR 3-DAYS,MORNING AND EVENING AFTER FOOD.\n");
printf("\n\n\t\t\t\t\t  PRESS ANY KEY TO CONTINUE");
printf("\n\n\t\t\t\t * * * * * WEAR MASK AND STAY SAFE * * * * *\n");
getch();
    }
}
void review()
{
    printf("\n\n\n");
    printf("\t\t\tHOW WOULD YOU RATE OUR SERVICE:\n\n\t\t\t5:EXCELLENT\n\t\t\t4:GOOD\n\t\t\t3:SATISFACTORY\n\t\t\t2:POOR\n\t\t\t1:REALLY BAD\n\n\t\t\t RATING:");
  scanf("%d",&scale);
  fflush(stdin);
  switch(scale)
  {
    case 5:
      printf("\n\t\t\t\t\t\tTHANKYOU FOR THE REVIEW\n\t\t\t\t\t\tIT WAS GREAT HELPING YOU!!\n\n");
      break;
    case 4:
      printf("\n\t\t\t\t\t\tTHANKYOU FOR THE REVIEW\n\t\t\t\t\t\tIT WAS GREAT HELPING YOU!!\n\n");
      break;
    case 3:
      printf("\n\n\tYOUR COMPLAINTS:");
      scanf("%s",complain);
      printf("\n\t\t\t\t\t\t THANKYOU FOR THE REVIEW\n\t\t\t\t\tWE WILL FIX THE ISSUES AS EARLY AS POSSIBLE\n\n");
      break;
       case 2:
       printf("\n\n\tYOUR COMPLAINTS:");
      scanf("%s",complain);
      printf("\n\t\t\t\t\t\t THANKYOU FOR THE REVIEW\n\t\t\t\t\tWE WILL FIX THE ISSUES AS EARLY AS POSSIBLE\n\n");
      break;
      case 1:
      printf("\n\n\tYOUR COMPLAINTS:");
      scanf("%s",complain);
      printf("\n\t\t\t\t\t\tTHANKYOU FOR THE REVIEW\n\t\t\t\t\tWE WILL FIX THE ISSUES AS EARLY AS POSSIBLE\n\n");
      break;
    default:
      printf("\n\t\t\tTHANKYOU FOR SELECTING OUR MEDICATION CHATBOT.... WE WERE PLEASED TO HELP YOU\n\n");
  }
    printf("\n\t\t\t****************************************************************************");
    printf("\n\n");
    printf("\t\t\t\t\t\tTHANK YOU FOR USING ME!!!");
    printf("\n\n");
    printf("\t\t\t****************************************************************************");
    getch();
}
int main()
{
    system("cls");
    intro();
    system("cls");
    printf("\n\n\n");
    backoption:printf("\n"); //goto label --> backoption
    printf("\t\t\t========================================\n");
    printf("\t\t\t      CHOOSE AN OPTION TO CONTINUE \n");
    printf("\t\t\t========================================\n");
    printf("\n\t\t 1. NEED SOME MEDICINES TO STABILIZE YOUR HEALTH\n");
    printf("\n\t\t 2. WANT TO ADD SOME INFORMATION IN THE RECORDS \n");
    printf("\n\t\t 3. EXIT \n");
    printf(" \n\n \t\t\t\tOPTION:");
    scanf("%d",&option_intro);  //option_intro variable-->to choose the option
    if(option_intro==1)
    {
        system("cls");
        medicine();

    }
    else if(option_intro==2)
    {
        system("cls");
        while(operation!=6)
        {
            printf("\n\n\n");
            backwhile: //goto label --> backwhile
            printf("\t\t WHAT OPERATION DO YOU WANT TO PERFORM\n");
            printf("\t\t -------------------------------------\n");
            printf("\n\t\t 1.ENTER NEW DATA TO THE RECORD\n");
            printf("\n\t\t 2.VIEW ALL AVAILABLE DATA\n");
            printf("\n\t\t 3.EDIT AVAILABLE DATA\n");
            printf("\n\t\t 4.SEARCH AVAILABLE DATA\n");
            printf("\n\t\t 5.DELETE AVAILABLE DATA\n");
            printf("\n\t\t 6.EXIT\n");
            printf("\n\t\t    OPTION: ");
            scanf("%d",&option_while);
            switch (option_while)
            {
            case 1: system("cls");
                    printf("\n\n");
                    add();
                    break;
            case 2: system("cls");
                    view();
                    break;
            case 3: system("cls");
                    edit();
                    break;
            case 4: system("cls");
                    search();
                    break;
            case 5: system("cls");
                    del();
                    break;

            case 6: system("cls");
                    review();
                    exit(1);

            default: system("cls");
                    printf("\n");
                    printf("\t\t\t   INVALID INPUT\n");
                    printf("\n\t\t   PLEASE SELECT THE AVAILABLE OPTIONS\n");
                    printf("\n ");
                   goto backwhile; // backwhile--> inside while loop of information
            }
            printf("\n\n\t\t\t\t PRESS ANY KEY TO CONITNUE\n");
            getch();
            system("cls");
        }

    }
    else if(option_intro==3)
    {
        system("cls");
        review();
        exit(1);
    }
    else
    {
        system("cls");
        printf("\n\n\n");
        printf("\t\t\t\t      INVALID INPUT\n");
        printf("\n\t\t\t        PLEASE PRESS EITHER 1 OR 2\n");
        goto backoption; //backoption--> for intro page
    }

    return 0;
}
void intro()
{
    printf("\n\n\n");
    printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t*                                                                       *\n");
    printf("\t\t*                            WELCOME TO                                 *\n");
    printf("\t\t*                     INSTANT MEDICATION CHAT BOT                       *\n");
    printf("\t\t*                                                                       *\n");
    printf("\t\t*        - - - - - - - - - - - - - - - - - - - - - - - - - -            *\n");
    printf("\t\t*                                                                       *\n");
    printf("\t\t*                  GET YOUR MEDICINIES INSTANTLY                        *\n");
    printf("\t\t*                                                                       *\n");
    printf("\t\t*                                                                       *\n");
    printf("\t\t*           WE SEE THIS IS YOUR FIRST TIME CHATTING WITH US             *\n");
    printf("\t\t*    EXPLORE OUR MOST POPULAR TOPICS AND FEEL FREE TO CONTACT US IF     *\n");
    printf("\t\t*                  THERE'S ANY OTHER QUERIES                            *\n");
    printf("\t\t*                                                                       *\n");
    printf("\t\t*                WE KNOW THE WORLD IS FULL OF CHOICES                   *\n");
    printf("\t\t*                                                                       *\n");
    printf("\t\t*                     THANKYOU FOR CHOOSING US                          *\n");
    printf("\t\t*                                                                       *\n");
    printf("\t\t*                                                                       *\n");
    printf("\t\t*                                                                       *\n");
    printf("\t\t*                                                                       *\n");
    printf("\t\t*                                                                       *\n");
    printf("\t\t*                     PRESS ANY KEY TO CONTINUE                         *\n");
    printf("\t\t*                                                                       *\n");
    printf("\t\t*                                                                       *\n");
    printf("\t\t*                                                                       *\n");
    printf("\t\t*                                                                       *\n");
    printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    getch();
    system("cls");
}
