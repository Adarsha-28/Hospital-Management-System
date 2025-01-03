//hospital mangement
#include<stdio.h>
#include<ctype.h>
struct hospital{
	char h_name[50];
	char h_place[50];
    char contact[10];
};
// Function to print hospital data 
void printHospital(struct hospital h) 
{ 
	printf("Hospital Name: %s\n", h.h_name); 
	printf("Place: %s\n", h.h_place); 
	printf("Contact: %s\n",h.contact);  
	printf("\n"); 
} 

int main()
{
	struct hospital hosp[3]={
		{"ROYAL CARE SUPER SPECIALTY HOSPITAL","L&T TOLL GATE,NEELAMBUR, COIMBATORE","9143491434"},
		{"KOVAI MEDICAL CENTER AND HOSPITAL","AVINASHI POAD,COIMBATORE","4226803838"},
		{"SRI RAMAKRISHNA HOSPITAL","SAROJINI NAIDU POAD,SIDDHAPUDUR,COIMBATORE","4223500000"}
	};
	int n=3,i;
	int choice;
	do{
		printf("----------WELCOME----------\n");
		printf("1.View hospital details\n2.Exit\nEnter your choice : ");
		scanf("%d",&choice);
		switch (choice) { 
			case 1: 
			printf("\nPrinting Hospital Data:\n\n"); 
			for (i = 0; i < n; i++) { 
				printHospital(hosp[i]); 
			} 
			break;
			case 2:
				printf("Existing the program...!");
				break;
			default:
				printf("Enter valid choice");
    	}
	}while(choice!=2);
	return 0;
}
