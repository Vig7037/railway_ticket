#include<stdio.h>
#include<string.h>
#define max 20
int seat[25];
int queue[max], f=-1, r=-1;
char s_name[20][20];
struct details
{
	char name[20];
	int seat_no;
};
//insertion
void enter(struct details dea)
{
	if(r==max)
	{
		printf("All the seats are booked.\n");
	}
	else{
	if(r==-1&&f==-1)
	{
		r=0;
		f=0;
	}
	queue[r]=dea.seat_no;
	strcpy(s_name[r],dea.name);
	r++;
	printf("Your seat has booked.\n");
	}
}
//deletion
int del(int no)
{
	int i;
	if((r==-1&&f==-1)||(f==r+1))
	{
		printf("Till now no seat has booked.\n");
	}
	else{
		i=0;
		while(queue[i]!=no)
		{
			i++;
		}
		while(i!=r-1)
		{
			queue[i]=queue[i+1];
			strcpy(s_name[i],s_name[i]);
			i++;
		}
		r--;
		printf("Your seat has cancled.\n");
	}
}
//seat avabality
int seat_avl()
{
	int i=0,nreserve=0;
		while(i!=max)
		{
			if(seat[i]!=0)
			{
			nreserve++;
			}	
			i++;
		}
	return nreserve;
}
//display seats arrangement
void dis_seats()
{
	int i;
	printf("\nSeats arrangement:\n");
    for(i=0;i<20;i++)
{
	printf("%d\t\t\t",seat[i++]);
	printf("%d\n",seat[i]);
}
}
//give 0 to the queue
void s_no(int so)
{
	int i=0;
	while(i!=max)
	{
		if(seat[i]==so)
		{
			seat[i]=0;
			break;
		}
		i++;
	}
}
//for del the reserved seat 
void del_s_no(int no)
{
	seat[no-1]=no;
}
int main()
{
	int  no, j, val, i;
	struct details dea;
	FILE *fp=fopen("C:\\Users\\ASUS\\Documents\\OneNote Notebooks\\seats_arrangement.txt","r");
    FILE *fi=fopen("C:\\Users\\ASUS\\Documents\\OneNote Notebooks\\railway_details.txt","w+");
    //to give the seat no to the queue
	if(fp!=NULL)
    {i=0;
    	while(!feof(fp))
    	{
    		fscanf(fp,"%d ",&val);
    		seat[i]=val;
    		i++;
		}
	}
	printf("\t\t\t\tWelcome to Bharat Railway ticket desk\n");
	while(1)
	{
	printf("\n\n");
	printf("Press 0 if you want to Exit progrme.\n");
	printf("Press 1 if you want to know how many seats are available.\n");
	printf("Press 2 if you want to book the seat.\n");
	printf("Press 3 if you want to cancel the seat.\n");
    printf("Enter the number->");
    fflush(stdin);
    scanf("%d",&no);
	//for exit the  program
	if(no==0)
	{
		printf("\033[H\033[2J");
    	printf("\033[0m");
		printf("\033[92mThanks to come in the Bharat Railway....\n ");
		printf("\033[0m");
		for(i=0;i<max;i++)
		{
			fprintf(fp,"%d  ",seat[i]);
		}
		for(i=0;i!=r+1;i++)
		{
		fprintf(fi,"%s %d\n",s_name[i],queue[i]);
		}
		fclose(fi);
		fclose(fp);
		break;
	}
	else if(no==1)
	{
		printf("\033[H\033[2J");
	    printf("\033[0m");
		i=seat_avl();
		if(i!=0){
		printf("\nWe have %d seats available in this block.",i);}
		else{
			printf("\nWe have no more seats available.");}
	}
	//for seat booking
	else if(no==2)
	{
	printf("\033[H\033[2J");
	printf("\033[0m");
	printf("\033[96m");
	dis_seats();
	printf("\033[0m");
	printf("Enter the following details:\n");
	printf("Enter the name(no space):");
	scanf("%s",dea.name);
	printf("Enter the seat no which do you want(0 number seat means reserved):");
	scanf("%d",&dea.seat_no);
	printf("\033[H\033[2J");
	printf("\033[0m");
	enter(dea);
	//fprintf(fi,"%s  %d \n",dea.name,dea.seat_no);
	s_no(dea.seat_no);
	}
	//for delete the seat
	else if(no==3){
	printf("\033[96m");
	printf("Enter the seat no which do you want to delete:");
	scanf("%d",&val);
	printf("\033[H\033[2J");
	printf("\033[0m");
	del(val);
	del_s_no(val);
	}
	else{
		printf("\033[H\033[2J");
		printf("\033[0m");
		printf("You enter the wrong key.\nPlease try again.\n");
	}
	
}
	return 0;	
}
