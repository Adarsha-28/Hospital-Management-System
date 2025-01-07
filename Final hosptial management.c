//HOSPITAL MANAGEMENT SYSTEM
/*TEAM MEMBERS
1.ADARSHA U 24CS006
2.BOOMIKA L 24CS037
3.DHANUSHRI D 24CS050*/

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_APPOINTMENT 50

// Structure to store patient details
struct Patient {
    int id;
    char name[50];
    int age;
    char gender[10];
    char contact[20];
    int roomCharges;
    int consultationFees;
    int medicationCost;
    int serviceCharges;
};

// Structure to store doctors details
struct Doctor {
    int did;
    char dname[50];
    int dage;
    char dgender[10];
    char dcontact[20];
};

//Structure to store appointment details
struct Appointment{
	int app_id;
	int P_id;
	int D_id;
	char date[10];
};

// Function to add a new patient
void addPatient(struct Patient patients[], int *patientCount) {
	if(*patientCount == MAX_SIZE)
    {
        printf("\nSTORAGE IS FULL...!!!");
    }
   
    patients[*patientCount].id = (*patientCount) + 1;

    printf("\nEnter patient name: ");
    scanf("%s", patients[*patientCount].name);
    getchar();

    printf("Enter patient age: ");
    scanf("%d",patients[*patientCount].age);

    printf("Enter patient gender: ");
    scanf("%s", patients[*patientCount].gender);
    getchar();

    printf("Enter patient contact: ");
    scanf("%s", patients[*patientCount].contact);
    (*patientCount)++;
    printf("\nPATIENT ADDED SUCCESSFULLY!\n---------------------------\n\n");
}

// Function to display all patients
void displayPatients(struct Patient patients[], int patientCount)
{
	int i;
	if(patientCount==0)
    {
        printf("\nPATIENTS DETAILS NOT FOUND...!!!\nNEED TO ADD...!!!\n\n");
    }
    else
	{
		printf("\nPATIENT DETAILS:\n\n");
    	printf("%-5s %-20s %-10s %-10s %-5s\n","ID","NAME","AGE","GENDER","CONTACT");
    	printf("---------------------------------------------------------------------\n");
    	for ( i = 0; i < patientCount; i++)
    	{
        	printf("%-5d %-20s %-10d %-10s %-5s\n\n",patients[i].id,patients[i].name,patients[i].age,patients[i].gender,patients[i].contact);
    	}
	}	
}

// Function to delete a patient by ID
void deletePatient(struct Patient patients[], int *patientCount, int id) {
    int found = 0,i,j;
    for ( i = 0; i < *patientCount; i++) //To search id in whole loop
    {
        if (patients[i].id == id)
        {
            found = 1;
            for ( j = i; j < (*patientCount) - 1; j++)
            {
                patients[j] = patients[j + 1];
            }
            (*patientCount)--;
            printf("\nPatient with ID %d deleted successfully!\n---------------------------\n\n", id);
            break;
        }
    }
    if (!found) {
        printf("\nPatient with ID %d not found.\n\n", id);
    }
}

// Function to update a patient by ID
void updatePatient(struct Patient patients[], int patientCount, int id) {
    int found = 0,i;
    for ( i = 0; i < patientCount; i++)
    {
        if (patients[i].id == id)
        {
            found = 1;
            printf("Enter new name (current:%s): ",patients[i].name);
            scanf("%s", patients[i].name);
            printf("Enter new age (current:%d): ",patients[i].age);
            scanf("%d", &patients[i].age);
            printf("Enter new gender (current:%s): ",patients[i].gender);
            scanf("%s", patients[i].gender);
            printf("Enter new contact (current:%s): ",patients[i].contact);
            scanf("%s", patients[i].contact);
            printf("Patient with ID %d updated successfully!\n---------------------------\n\n", id);
            break;
        }
    }
    if (!found) {
        printf("\nPatient with ID %d not found.\n", id);
    }
}

//Function to search a Patient
void searchPatient(struct Patient patients[], int patientCount)
{
    int found=0,i,num,pid;//searchId
    char search_patient[50];//By name
    printf("How You want to Search? By ID or Name\n1.ID\n2.Name\n\nChoose your option: ");
    scanf("%d",&num);
    if(num==1)
    {
        printf("\nEnter the Patient ID: ");
        scanf("%d",&pid);
        for( i=0;i<patientCount;i++)
        {
            if(pid==patients[i].id)
            {
                found=1;
                printf("%-5s %-20s %-10s %-10s %-5s\n","ID","NAME","AGE","GENDER","CONTACT");
                printf("------------------------------------------------------------------\n");
                printf("%-5d %-20s %-10d %-10s %-5s\n\n",patients[i].id,patients[i].name,patients[i].age,patients[i].gender,patients[i].contact);
            }
        }
    }
    else if(num==2)
    {
        printf("\nEnter the Patient name: ");
        scanf("%s",search_patient);
        getchar();
        for( i=0;i<patientCount;i++)
        {
            if(!(strcasecmp(patients[i].name,search_patient)))
            {
                found=1;
                printf("%-5s %-20s %-10s %-10s %-5s\n","ID","NAME","AGE","GENDER","CONTACT");
                printf("-------------------------------------------------------------\n");
                printf("%-5d %-20s %-10d %-10s %-5s\n\n",patients[i].id,patients[i].name,patients[i].age,patients[i].gender,patients[i].contact);
                printf("PATIENT FOUND...!!!\n\n");
            }
        }
    }
    if(!found)
        printf("PATIENT NOT FOUND...!!!\n\n");
}

// Function to add a new Doctor
void addDoctor(struct Doctor doctors[], int *doctorCount) {
	if(*doctorCount == MAX_SIZE)
    {
        printf("\nSTORAGE IS FULL...!!!");
    }
    struct Doctor newDoctor;
    newDoctor.did = (*doctorCount) + 1;

    printf("\nEnter Doctor name: ");
    scanf("%s", newDoctor.dname);

    printf("Enter Doctor age: ");
    scanf("%d", &newDoctor.dage);

    printf("Enter Doctor gender: ");
    scanf("%s", newDoctor.dgender);

    printf("Enter Doctor contact: ");
    scanf("%s", newDoctor.dcontact);

    doctors[*doctorCount] = newDoctor;
    (*doctorCount)++;

    printf("\nDoctor added successfully!\n-----------------------\n\n");
}

// Function to display all Doctors
void displayDoctors(struct Doctor doctors[], int doctorCount)
{
	int i;
	if(doctorCount==0)
    {
        printf("\nDOCTORS DETAILS NOT FOUND...!!!\nNEED TO ADD...!!!\n\n");
    }
    else
    {
    	printf("\nDOCTOR DETAILS:\n\n");
    	printf("%-5s %-20s %-10s %-10s %-5s\n","ID","NAME","AGE","GENDER","CONTACT");
    	printf("------------------------------------------------------------------\n");
    	for ( i = 0; i < doctorCount; i++)
    	{
        	printf("%-5d %-20s %-10d %-10s %-5s\n\n",doctors[i].did,doctors[i].dname,doctors[i].dage,doctors[i].dgender,doctors[i].dcontact);
    	}
	}
}

// Function to delete a Doctor by ID
void deleteDoctor(struct Doctor doctors[], int *doctorCount, int did) {
    int found = 0,i,j;
    for ( i = 0; i < *doctorCount; i++) //To search did in whole loop
    {
        if (doctors[i].did == did)
        {
            found = 1;
            for (j = i; j < (*doctorCount) - 1; j++)
            {
                doctors[j] = doctors[j + 1];
            }
            (*doctorCount)--;
            printf("\nDoctor with ID %d deleted successfully!\n-----------------------\n\n", did);
            break;
        }
    }
    if (!found) {
        printf("\nDoctor with ID %d not found.\n\n", did);
    }
}

// Function to update a Doctor by ID
void updateDoctor(struct Doctor doctors[], int doctorCount, int did) {
    int found = 0,i;
    for (i = 0; i < doctorCount; i++)
    {
        if (doctors[i].did == did)
        {
            found = 1;
            printf("\nEnter new name (current:%s): ",doctors[i].dname);
            scanf("%s", doctors[i].dname);
            printf("Enter new age (current:%d): ",doctors[i].dage);
            scanf("%d", &doctors[i].dage);
            printf("Enter new gender (current:%s): ",doctors[i].dgender);
            scanf("%s", doctors[i].dgender);
            printf("Enter new contact (current:%s): ",doctors[i].dcontact);
            scanf("%s", doctors[i].dcontact);
            printf("Doctor with ID %d updated successfully!\n-----------------------\n\n", did);
            break;
        }
    }
    if (!found) {
        printf("\nDoctor with ID %d not found.\n", did);
    }
}

//Function to search a Doctor
void searchDoctor(struct Doctor doctors[], int doctorCount)
{
    int found=0,i,doc_id,num;
    char search_doctor[50];
    printf("How You want to Search? By ID or Name\n1.ID\n2.Name\n\nChoose your option: ");
    scanf("%d",&num);
    if(num==1)
    {
        printf("\nEnter the Doctor ID: ");
        scanf("%d",doc_id);
        for( i=0;i<doctorCount;i++)
        {
            if(doc_id==doctors[i].did)
            {
                found=1;
                printf("%-5s %-20s %-10s %-10s %-5s\n","ID","NAME","AGE","GENDER","CONTACT");
                printf("------------------------------------------------------------------\n");
                printf("%-5d %-20s %-10d %-10s %-5s\n\n",doctors[i].did,doctors[i].dname,doctors[i].dage,doctors[i].dgender,doctors[i].dcontact);
            }
        }
    }
    else if(num==2)
    {
        printf("\nEnter the Doctor name: ");
        scanf("%s",search_doctor);
        getchar();
        for( i=0;i<doctorCount;i++)
        {
            if(!strcasecmp(doctors[i].dname,search_doctor))
            {
                found=1;
                printf("%-5s %-20s %-10s %-10s %-5s\n","ID","NAME","AGE","GENDER","CONTACT");
                printf("--------------------------------------------------------------\n");
                printf("%-5d %-20s %-10d %-10s %-5s\n\n",doctors[i].did,doctors[i].dname,doctors[i].dage,doctors[i].dgender,doctors[i].dcontact);
                printf("Doctor found...!!!\n\n");
            }
        }
    }
    if(!found)
        printf("DOCTOR NOT FOUND...!!!\n\n");
}

//appointment scheduling
void scheduleAppointment(struct Appointment appointments[],int *appointmentCount)
{
	if(*appointmentCount == MAX_APPOINTMENT)
    {
        printf("\nAPPOINTMENT NOT AVAILABLE...!!!\n");
    }
	appointments[*appointmentCount].app_id= (*appointmentCount)+1;
	printf("\nEnter Patient's ID : ");
	scanf("%d",&appointments[*appointmentCount].P_id);
    printf("Enter Doctor ID: ");
    scanf("%d", &appointments[*appointmentCount].D_id);
    printf("Enter Date (DD/MM/YYYY): ");
    scanf("%s", appointments[*appointmentCount].date);
    getchar();
    (*appointmentCount)++;  
    printf("\nAPPOINTMENT SCHEDULED SUCCESSFULLY...!!!\n\n");
}

//view appointment
void viewAppointment(struct Appointment appointments[],int appointmentCount)
{
	int i;
	if(appointmentCount==0)
    {
        printf("\nAPPOINTMENT DETAILS NOT FOUND...!!!\nNEED TO ADD...!!!\n\n");
    }
    else
    {
    	printf("\nAPPOINTMENTS:\n\n");
    	printf("%-18s %-15s %-15s %-15s\n","APPOINTMENT_ID","PATIENT's ID","DOCTOR's ID","DATE");
    	printf("-------------------------------------------------------------\n");
    
    	for(i=0;i<appointmentCount;i++)
    		printf("%-18d %-15d %-15d %-15s\n\n",appointments[i].app_id,appointments[i].P_id,appointments[i].D_id,appointments[i].date);
	}
}

//cancel appointment
void cancelAppointment(struct Appointment appointments[],int *appointmentCount)
{
	int cancel_id,i,j,found;
	printf("\nEnter Appointment id : ");
	scanf("%d",&cancel_id);
	for(i=0 ; i < *appointmentCount ;i++)
    {
        if(cancel_id==appointments[i].app_id)
        {
            found=1;
            for(j=i ; j<*appointmentCount ; j++)
            {
                appointments[j].app_id=appointments[j+1].app_id;
            }
        }
    }
    (*appointmentCount)--;
    
    if(found == 1)
        printf("\nAPPOINTMENT CANCELED SUCCESSFULLY...!!!\n\n");
    else
        printf("\nAPPOINTMENT NOT FOUND...!!!\n\n");
}

//Function to Create Bill summary
void bill(struct Patient patients[], int patientCount, int id)
{
    int found = 0,i;
    for ( i = 0; i < patientCount; i++)
    {
        if (patients[i].id == id)
        {
            found = 1;
            printf("Enter Room Charges: ");
            scanf("%d", &patients[i].roomCharges);
            printf("Enter Consultation Fees: ");
            scanf("%d", &patients[i].consultationFees);
            printf("Enter Medication Cost: ");
            scanf("%d", &patients[i].medicationCost);
            printf("Enter Service Charges: ");
            scanf("%d", &patients[i].serviceCharges);
            printf("\t\t\t\tBILL SUMMARY\n\n");
            printf("------------------------------------------------------------------\n");
            printf("%-5s %-20s %-10s %-10s %-5s\n","ID","NAME","AGE","GENDER","CONTACT");
            printf("------------------------------------------------------------------\n");
            printf("%-5d %-20s %-10d %-10s %-5s\n\n",patients[i].id,patients[i].name,patients[i].age,patients[i].gender,patients[i].contact);
            printf("------------------------------------------------------------------\n\n");
            printf("Room Charges            %d\n",patients[i].roomCharges);
            printf("Consultation Fees       %d\n",patients[i].consultationFees);
            printf("Medication Cost         %d\n",patients[i].medicationCost);
            printf("Service Charges         %d\n",patients[i].serviceCharges);
            printf("------------------------------------------------------------------\n\n");
            printf("Total                   %d\n",patients[i].roomCharges+patients[i].consultationFees+patients[i].medicationCost+patients[i].serviceCharges);
            printf("------------------------------------------------------------------\n\n");
        }
    }
    if(!found)
    printf("\nPATIENT ID NOT FOUND...!!!\n\n");
}

int main() {
    struct Patient patients[MAX_SIZE];
    struct Doctor doctors[MAX_SIZE];
    struct Appointment appointments[MAX_APPOINTMENT];
    int patientCount = 0,doctorCount=0,appointmentCount=0;
    int choice,option;
    int id,did;

    do {
        printf("\t\t\t\tHOSPITAL MANAGEMENT SYSTEM\n\n");
        printf("Choose any one to fill details:\n");
        printf("1. Patient Details\n");
        printf("2. Doctor Details\n");
        printf("3. Appointment Details\n");
        printf("4. Patient Bill Receipt\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice==1)
        {
            printf("\n1. Add Patient Details\n");
            printf("2. Display Patients\n");
            printf("3. Delete Patient Details\n");
            printf("4. Update Patient Details\n");
            printf("5. Search Patient Details\n\n");
            printf("Choose any option:");
            scanf("%d",&option);
            switch (option) {
            case 1:
                addPatient(patients, &patientCount);
                break;
            case 2:
                displayPatients(patients, patientCount);
                break;
            case 3:
                printf("Enter patient ID to delete: ");
                scanf("%d", &id);
                deletePatient(patients, &patientCount, id);
                break;
            case 4:
                printf("Enter patient ID to update: ");
                scanf("%d", &id);
                updatePatient(patients, patientCount, id);
                break;
            case 5:
                searchPatient(patients, patientCount);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
            }
        }
        else if(choice==2)
        {
            printf("\n1. Add Doctor Details\n");
            printf("2. Display Doctors\n");
            printf("3. Delete Doctor Details\n");
            printf("4. Update Doctor Details\n");
            printf("5. Search Doctor Details\n\n");
            printf("Choose any option:");
            scanf("%d",&option);
            switch (option) {
            case 1:
                addDoctor(doctors, &doctorCount);
                break;
            case 2:
                displayDoctors(doctors, doctorCount);
                break;
            case 3:
                printf("Enter Doctor ID to delete: ");
                scanf("%d", &did);
                deleteDoctor(doctors, &doctorCount, did);
                break;
            case 4:
                printf("Enter Doctor ID to update: ");
                scanf("%d", &did);
                updateDoctor(doctors, doctorCount, did);
                break;
            case 5:
                searchDoctor(doctors, doctorCount);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
            }
        }
        else if(choice==3)
        {
        	printf("\n1.Schedule Appointment\n");
        	printf("2.View Appointment\n");
        	printf("3.Cancel Appointment\n\n");
        	printf("Choose any option : ");
        	scanf("%d",&option);
        	switch(option)
        	{
        		case 1:
        			scheduleAppointment(appointments,&appointmentCount);
        			break;
        		case 2:
        			viewAppointment(appointments,appointmentCount);
        			break;
        		case 3:
        			cancelAppointment(appointments,&appointmentCount);
        			break;
        		default:
					printf("\nInvalid choice...\n");	
					break;
			}
		}
        else if(choice==4)
        {
            printf("\nEnter patient ID to Create Bill: ");
            scanf("%d", &id);
            bill(patients, patientCount, id);
        }
        else if(choice==5)
        {
            printf("Exiting...\n\n");
        }
    } while(choice != 5);
    return 0;
}
