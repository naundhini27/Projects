#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include <stdbool.h>

int i,j;
int mainexit;
void menu();
void close();
struct date{
    int m,y,d;
    };
struct info
{
    char name[50];
   char address1[20];
   char address2[20];
   char city[20];
   char acctype[10];
   int accno,age;
   double phno;
   float amt;
   struct date deposit;
   struct date withdraw;

}add,check,update,del, transaction;

float interest(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);

}
void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

void create_acc()
{
    FILE *fptr;
    fptr=fopen("bank.dat","a+");
    if(fptr==NULL)
      printf("Error");
    printf("-------ENTER THE DETAILS-------\n");
    printf("Enter your account number: ");
    scanf("%d",&check.accno);
    while(fscanf(fptr,"%d %s %d %s %s %s %lf %s %f %d/%d/%d",&add.accno,add.name,&add.age,add.address1,add.address2,add.city,&add.phno,add.acctype,&add.amt,&add.deposit.d,&add.deposit.m,&add.deposit.y)!=EOF)
   {
      if (check.accno==add.accno)
         {
            printf("This account number is already used");
            fordelay(10000000);
            return ;
         }
   }
   add.accno=check.accno;
   printf("\nEnter today's date(dd/mm/yyyy):");
   scanf("%d/%d/%d",&add.deposit.d,&add.deposit.m,&add.deposit.y);
   printf("Enter your name: ");
   scanf("%s",add.name);
   printf("Enter your age: ");
   scanf("%d",&add.age);
   printf("Enter address line 1:");
   scanf("%s",add.address1);
   printf("Enter address line 2:");
   scanf("%s",add.address2);
   printf("Enter address city:");
   scanf("%s",add.city);
   printf("Enter your phone number: ");
   scanf("%lf",&add.phno);
   printf("Enter the amount to deposit: ");
   scanf("%f",&add.amt);
   printf("Type of account (Savings S or Current C) :");
   scanf("%s",add.acctype);
   fprintf(fptr,"%d %s %d %s %s %s %lf %s %f %d/%d/%d\n",add.accno,add.name,add.age,add.address1,add.address2,add.city,add.phno,add.acctype,add.amt,add.deposit.d,add.deposit.m,add.deposit.y);
   printf("\nAccount created sucessfully");
   fclose(fptr);
   printf("\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d", &mainexit);
    if (mainexit==1)
        menu();
    else if(mainexit==0)
        close();
}
void disp_acc()
{
   FILE *fptr;
   fptr=fopen("bank.dat","r");
   printf("\nACCOUNT NO.\t\t NAME\t\t\tAGE\t\t\tCITY\t\tPHONE NO.\n");
   printf("----------------------------------------------------------------------------------------------------------");
   while(fscanf(fptr,"%d %s %d %s %s %s %lf %s %f %d/%d/%d",&add.accno,add.name,&add.age,add.address1,add.address2,add.city,&add.phno,add.acctype,&add.amt,&add.deposit.d,&add.deposit.m,&add.deposit.y)!=EOF)
   {
      printf("\n%7d\t\t\t%8s\t\t%2d\t\t%15s\t\t%.f",add.accno,add.name,add.age,add.city,add.phno);
   }
   fclose(fptr);
   printf("\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d", &mainexit);
    if (mainexit==1)
        menu();
    else if(mainexit==0)
        close();
}
void update_acc()
{
   int c,flag=0;
   FILE *ptr1,*ptr2;
   ptr1=fopen("bank.dat","r");
   ptr2=fopen("new.dat","w");
   printf("Enter your account number : ");
   scanf("%d",&update.accno);
   while(fscanf(ptr1,"%d %s %d %s %s %s %lf %s %f %d/%d/%d",&add.accno,add.name,&add.age,add.address1,add.address2,add.city,&add.phno,add.acctype,&add.amt,&add.deposit.d,&add.deposit.m,&add.deposit.y)!=EOF)
   {
      if(add.accno==update.accno)
      {
         flag=1;
         printf("What do you want to change: \n1.Address\n2.Phone numeber\n");
         scanf("%d",&c);
         if(c==1)
         {
            printf("Enter address line 1: ");
            scanf("%s",update.address1);
            printf("Enter address line 2: ");
            scanf("%s",update.address2);
            printf("Enter the city: ");
            scanf("%s",update.city);
            fprintf(ptr2,"%d %s %d %s %s %s %lf %s %f %d/%d/%d\n",add.accno,add.name,add.age,update.address1,update.address2,update.city,add.phno,add.acctype,add.amt,add.deposit.d,add.deposit.m,add.deposit.y);
            printf("Address sucessfully updated");
         }
         else
         {
            printf("Enter the phone number: ");
            scanf("%lf",&update.phno);
            fprintf(ptr2,"%d %s %d %s %s %s %lf %s %f %d/%d/%d\n",add.accno,add.name,add.age,add.address1,add.address2,add.city,update.phno,add.acctype,add.amt,add.deposit.d,add.deposit.m,add.deposit.y);
            printf("Phone number sucessfully updated");
         }
      }
      else
      {
         fprintf(ptr2,"%d %s %d %s %s %s %lf %s %f %d/%d/%d\n",add.accno,add.name,add.age,add.address1,add.address2,add.city,add.phno,add.acctype,add.amt,add.deposit.d,add.deposit.m,add.deposit.y);
      }
   }
   if(flag==0)
      printf("This account does not exist");
   fclose(ptr1);
   fclose(ptr2);
   remove("bank.dat");
   rename("new.dat","bank.dat");
   printf("\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d", &mainexit);
    if (mainexit==1)
        menu();
    else if(mainexit==0)
        close();
}
void transact(void)
{   int choice,test=0;
    FILE *ptr1,*ptr2;
    ptr1=fopen("bank.dat","r");
    ptr2=fopen("new.dat","w");

        printf("Enter the account no. of the customer:");
    scanf("%d",&transaction.accno);
   while(fscanf(ptr1,"%d %s %d %s %s %s %lf %s %f %d/%d/%d",&add.accno,add.name,&add.age,add.address1,add.address2,add.city,&add.phno,add.acctype,&add.amt,&add.deposit.d,&add.deposit.m,&add.deposit.y)!=EOF)
   {

            if(add.accno==transaction.accno)
            {   test=1;
                if(strcmpi(add.acctype,"fixed1")==0||strcmpi(add.acctype,"fixed2")==0||strcmpi(add.acctype,"fixed3")==0)
                {
                    printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                    fordelay(1000000000);
                    system("cls");
                    menu();
                }
                printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("Enter the amount you want to deposit:Rs. ");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;
                    fprintf(ptr2,"%d %s %d %s %s %s %lf %s %f %d/%d/%d\n",add.accno,add.name,add.age,add.address1,add.address2,add.city,add.phno,add.acctype,add.amt,add.deposit.d,add.deposit.m,add.deposit.y);
                    printf("\n\nDeposited successfully!");
                }
                else
                {
                    printf("Enter the amount you want to withdraw:Rs. ");
                    scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;
                    fprintf(ptr2,"%d %s %d %s %s %s %lf %s %f %d/%d/%d\n",add.accno,add.name,add.age,add.address1,add.address2,add.city,add.phno,add.acctype,add.amt,add.deposit.d,add.deposit.m,add.deposit.y);
                    printf("\n\nWithdrawn successfully!");
                }

            }
            else
            {
                    fprintf(ptr2,"%d %s %d %s %s %s %lf %s %f %d/%d/%d\n",add.accno,add.name,add.age,add.address1,add.address2,add.city,add.phno,add.acctype,add.amt,add.deposit.d,add.deposit.m,add.deposit.y);
            }
   }
   fclose(ptr1);
   fclose(ptr2);
   remove("bank.dat");
   rename("new.dat","bank.dat");
   if(test!=1)
   {
       printf("\n\nRecord not found!!");
       transact_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&mainexit);
      system("cls");
      if (mainexit==0)
        transact();
    else if (mainexit==1)
        menu();
    else if (mainexit==2)
        close();
    else
    {
        printf("\nInvalid!");
        goto transact_invalid;
    }

   }
   else
   {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&mainexit);
        system("cls");
        if (mainexit==1)
            menu();
        else
            close();
   }
}

void del_acc()
{
   FILE *ptr1,*ptr2;
   int flag=0;
   ptr1=fopen("bank.dat","r");
   ptr2=fopen("new.dat","w");
   printf("Enter the account number: ");
   scanf("%d",&del.accno);
   while(fscanf(ptr1,"%d %s %d %s %s %s %lf %s %f %d/%d/%d",&add.accno,add.name,&add.age,add.address1,add.address2,add.city,&add.phno,add.acctype,&add.amt,&add.deposit.d,&add.deposit.m,&add.deposit.y)!=EOF)
   {
      if(add.accno==del.accno)
      {
         flag++;
      }
      if(add.accno!=del.accno)
      {
         fprintf(ptr2,"%d %s %d %s %s %s %lf %s %f %d/%d/%d\n",add.accno,add.name,add.age,add.address1,add.address2,add.city,add.phno,add.acctype,add.amt,add.deposit.d,add.deposit.m,add.deposit.y);
      }
   }
   if(flag==0)
      printf("This account does not exist");
   else
      printf("Record Deleted");
   fclose(ptr1);
   fclose(ptr2);
   remove("bank.dat");
   rename("new.dat","bank.dat");
    if(flag!=1)
   {
       printf("\n\nRecord not found!!");
       transact_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&mainexit);
      system("cls");
      if (mainexit==0)
        transact();
    else if (mainexit==1)
        menu();
    else if (mainexit==2)
        close();
    else
    {
        printf("\nInvalid!");
        goto transact_invalid;
    }

   }
   else
   {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&mainexit);
        system("cls");
        if (mainexit==1)
            menu();
        else
            close();
   }

}

void close()
{
	printf("Thank You");
}
void menu(void)
{   int choice;
    system("cls");
    printf("\n\n\t\t\t       BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t xxxxxxx WELCOME TO THE MAIN MENU xxxxxxx ");
    printf("\n\n\t\t1.Create a new account\n\t\t2.Update information of existing account\n\t\t3.Transactions\n\t\t4.Deleting account\n\t\t5.View customer's list\n\t\t6.Exit\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);
    system("cls");
    switch(choice)
    {
        case 1:create_acc();
        break;
        case 2:update_acc();
        break;
        case 3:transact();
        break;
        case 4:del_acc();
        break;
        case 5:disp_acc();
        break;
        case 6:close();
        break;
    }

}
int main()
{
	char user[10],username[10]="Bank";
    char pass[10],password[10]="1234";
    int i=0;
    printf("\n\n\n\t\t\t\t xxxxxxxxComputer Programming Projectxxxxxxxxx\n\t\t\t\t\t User Login ");
    printf("\n\n\n\n\n\t\t\t\tEnter the Username to login:");
    scanf("%s",user);
    printf("\n\n\n\n\n\t\t\t\tEnter the password to login:");
    scanf("%s",pass);

    if (strcmp(pass,password)==0 && strcmp(user,username)==0 )
        {printf("\n\nUsername and Password Match!\nLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(". ");
        }
        printf("\n");
                system("pause");
				system("cls");

            menu();
        }
    else
        {   printf("\n\nWrong Username or password!!\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&mainexit);
            if (mainexit==1)
                    {

                        system("cls");
                        main();
                    }

            else if (mainexit==0)
                    {
                    system("cls");
                    close();}
            else
                    {printf("\nInvalid!");
                    fordelay(1000000000);
                    system("cls");
                    goto login_try;}

        }
        return 0;
}
