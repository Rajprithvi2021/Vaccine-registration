#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
int i;
int n;
int back;
char name;
char type;
struct details {
	int id;
	int age;
	char firstName[10];
	char lastName[10];
	int year;
	int month;
	int day;
	char mv[15];
	int ward;
	char street[10];
	int number;
	int renumber;
	int sRam;
	int ran;
};

void getData();

void noofRec();

int main()
{
	printf("\n\n\n\n");
	printf("\t\t\tWelcome to Vaccine Registration");
	printf("\n\t_____________________________________________________________________");
	printf("\n\n\t     Note: You should be at least 18 years for vaccine registration ");
	printf("\n\t_____________________________________________________________________");

	label1:	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t 1) Vaccine Registration \n");
	printf("\t\t\t 2) Search \n");
	printf("\t\t\t 3) No of Records\n");
	printf("\t\t\t 4) Exit \n");

	int choice;
	printf("\n\t......................................................................");
	printf("\n\n\t\t\tEnter your choice: ");
	scanf("%d",&choice);
	printf("\n");
	system ("cls");

	switch(choice) 
	{
		case 1:
		{
		label2:
			printf("\n");
			printf("\n\n\n");	
			printf("\t\t\t\tIdentity verification: \n");
			printf("\n\t_____________________________________________________________________\n");

			printf("\n\t\t\t 1) Citizenship Card \n");
			printf("  \t\t\t 2) Student Card \n");
			printf("  \t\t\t 3) Others \n");
			printf("  \t\t\t 4) Back to main menu\n");
			printf("  \t\t\t 5) Exit\n");
			printf("\n\t......................................................................");

			int choose;
			printf("\n \n\t\t\t Enter your choice: ");
			scanf("%d",&choose);
			printf("\n");
			system ("cls");

			switch(choose)
			{
				case 1:
				{
					FILE *fp ;
					int another;
					struct details vac[10];
					fp=fopen("RegisteredName.txt", "a+");
					if(fp == NULL)
					{
						puts ("Cannot open file");
						return 0;
					}
					printf("\n\n\n\n");
					printf("\t\t\t\tCitizenship Card");
					printf("\n\n\t\t\t>Press 1 if you want to go back: ");
					scanf("%d",&back);
					if(back==1) {
						goto label2;
					}
					printf("\n\t_____________________________________________________________________");
					printf("\n\n\t\t\t> Number of data you want to enter: ");
					scanf("%d",&n);

					for(i=0;i<n;i++) {

						printf("\t\t\t> Enter Citizenship Number : ");

						getData();		
					}

					fflush(stdin);
					fclose(fp);
					break;
				}
				case 2:
				{
					printf("\n\n\n\n");
					printf("\t\t\t\tStudent Card");
					printf("\n\t_____________________________________________________________________");

					FILE *fp ;
					int another;
					char name[20];
					struct details vac ;
					fp=fopen("RegisteredName.txt", "a+");
					if(fp == NULL)
					{
						puts ("Cannot open file");
						return 0;
					}
					printf("\n\n\t\t\tPress 1 if you want to go back: ");
					scanf("%d",&back);
					if(back==1) {
						goto label2;
					}
					printf("\t\t\t> Number of data you want to enter: ");
					scanf("%d",&n);
					for(i=0;i<n;i++) {

						printf("\t\t\t> Enter Student id: ");

						getData();	
					}
					fflush(stdin);
					fclose(fp);
					break;
				}

				case 4: {
					goto label1;
				}

				case 5: {
					exit(0);
				}
				default:
				{
					printf("\n\t......................................................................");
					printf("\n\n\t\t\t Enter correct choice!!! \n");
					goto label2;
				}
			}

			goto label2;
		}

		case 2:
		{
			printf("\n\n\n\n");
			printf("\t \t\t\t Search ");	
			printf("\n\t_____________________________________________________________________");

			FILE *fp ;
			struct details vac;
			fp=fopen("RegisteredName.txt", "r");
			if(fp == NULL){
				puts ("Cannot open file");
				return 0;
			}

			int serial,found=0;
			printf("\n\n\t\t\tPress 1 if you want to go back: ");
			scanf("%d",&back);
			if(back==1) {
				goto label1;
			}
			printf("\n\n\t\t\t> Enter Your serial number: ");
			scanf("%d",&serial);
			while(fread(&vac,sizeof(details),1,fp)) {
				if(vac.ran==serial) {
					found=1;
					printf("\n\t\t\t> Your Id Number: %d\n",vac.id);
					printf("\t\t\t> Name: %s %s\n",vac.firstName,vac.lastName);
					printf("\t\t\t> Date of birth: %d/%d/%d\n",vac.year,vac.month,vac.day);
					printf("\t\t\t> Address: Bagamati, Chitwan, %s, %d, %s\n",vac.mv,vac.ward,vac.street);
				}
			}
			if(!found){
       			printf("\n\n\t\t\tRecord not found\n");
    		}
    		goto label1;
		}

		case 3: {
			printf("Press 1 if you want to go back: ");
			scanf("%d",&back);
			if(back==1) {
				goto label2;
			}
			noofRec();
			goto label1;
		}

		case 4: {
			exit(0);
		}
		goto label1;

		default:
		{

			printf("\n\n\t\t\t Enter correct choice!!! ");
			goto label1;
		}
	}
	return 0;
	getch();
}

void getData(){
	FILE *fp ;
	struct details vac[10];
	fp=fopen("RegisteredName.txt", "a+" );
	if(fp==NULL)
	{
		puts("Cannot open file");
	}
	scanf("%d",&vac[i].id);

	printf("\t\t\t> Enter your first and last name: ");
	scanf("%s %s", vac[i].firstName, vac[i].lastName);

	date: printf("\t\t\t> Enter Your Date of birth (YYYY MM DD): ");
	scanf(" %d %d %d",&vac[i].year,&vac[i].month,&vac[i].day);

	if(vac[i].year<1930 || vac[i].month > 12 || vac[i].day>31) {
		printf("\t\t\tPlease enter a valid date!!\n");
		goto date;
	}

	vac[i].age = 2022- vac[i].year;

	if(vac[i].age<18) {
		printf("\t\t\tGrow up shorty!!!");
	}

	printf("\t\t\t> Enter Your Address: \n");

	printf("\n\t\t\t\t> Municipality/VDC: ");
	scanf("%s",vac[i].mv);

	printf("\t\t\t\t> Ward no: ");
	scanf("%d",&vac[i].ward);

	printf("\t\t\t\t> Street: ");
	scanf("%s",vac[i].street);

	while(1) {
		printf("\n\t\t\t> Enter Your Phone Number: ");
		scanf("%d",&vac[i].number);
		printf("\t\t\t> Re-Enter Your Phone Number: ");
		scanf("%d",&vac[i].renumber);
		if(vac[i].number==vac[i].renumber) {
			break;
		}
		else {
			printf("\t\t\t> Enter Your Phone Number Correctly.\n");
		}
	}

	int random;
	srand(time(NULL));
	random = rand();
	printf("\t\t\t\t|-------------|\n");
    printf("\t\t\t\t|   OTP is:   |\n");
    printf("\t\t\t\t|             |\n");
    printf("\t\t\t\t|    %d    |\n",random);
    printf("\t\t\t\t|             |\n");
    printf("\t\t\t\t|             |\n");
    printf("\t\t\t\t|-------------|\n");
    printf("\t\t\t\t|__1___2___3__|\n");
    printf("\t\t\t\t|__4___5___6__|\n");
    printf("\t\t\t\t|__7___8___9__|\n");
    printf("\t\t\t\t|__*___0___#__|\n");
    printf("\t\t\t\t|.............|\n");
	while(1) {
		label3: printf("\t\t\t> Enter Your OTP: ");
		scanf("%d",&vac[i].sRam);
        if(random==vac[i].sRam){
            break;
        }
        else {
        	printf("\n\n\t\t\tYou have entered the wrong OTP, please try again!\n\n");
        	goto label3;
		}
	}

	srand(time(NULL));
	random=rand();
	vac[i].ran=random;
	printf("\t\t\t> Your Serial Number is: %d\n",random);
	printf("\n =========================================================================");
	printf("\n\n\t ---> Keep your Serial Number '%d' safely... \n",random);
    printf("\n =========================================================================");
    printf("\n\n");

	fwrite(&vac,sizeof(details),1,fp);
}

void noofRec(){
	struct details vac;
	FILE *fp;
	fp = fopen("RegisteredName.txt","r");
	fseek(fp,0,SEEK_END);
	int no;
	no = ftell(fp)/sizeof(details);
	printf("\n\n\n\n\n\t =========================================================================");
	printf("\n\n\t\t ---> No of records: %d\n",no);

	fclose(fp);
	printf("\n\t =========================================================================");
}