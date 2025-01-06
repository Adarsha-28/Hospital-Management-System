//HOSPITAL MANAGEMENT SYSTEM
/*TEAM MEMBERS
1.ADARSHA U CSE006
2.BOOMIKA L CSE037
3.DHANUSHRI D CSE050*/

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

// Structure to store patient details
struct Patient {
    int id;
    char name[50];
    int age;
    char gender[10];
    char contact[20];
};
// Structure to store doctors details
struct Doctor {
    int did;
    char dname[50];
    int dage;
    char dgender[10];
    char dcontact[20];
};

// Function to add a new patient
void addPatient(struct Patient patients[], int *patientCount) {
    struct Patient newPatient;
    newPatient.id = (*patientCount) + 1;
    
    printf("\nEnter patient name: ");
    scanf("%s", newPatient.name);
    getchar();
    
    printf("Enter patient age: ");
    scanf("%d", &newPatient.age);
    
    printf("Enter patient gender: ");
    scanf("%s", newPatient.gender);
    getchar();
    
    printf("Enter patient contact: ");
    scanf("%s", newPatient.contact);
    
    patients[*patientCount] = newPatient;
    (*patientCount)++;
    printf("\nPatient added successfully!\n---------------------------\n\n");
}

// Function to display all patients
void displayPatients(struct Patient patients[], int patientCount)
{
	int i;
    printf("\nPATIENT DETAILS:\n\n");
    printf("%-5s %-20s %-10s %-10s %-5s\n","ID","NAME","AGE","GENDER","CONTACT");
    printf("---------------------------------------------------------------------\n");
    for ( i = 0; i < patientCount; i++)
    {
        printf("%-5d %-20s %-10d %-10s %-5s\n\n",patients[i].id,patients[i].name,patients[i].age,patients[i].gender,patients[i].contact);
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
    int found=0,i;//searchId,
    char search_patient[50];
    printf("\nEnter the Patient name: ");
    scanf("%s",search_patient);
    getchar();
    for( i=0;i<patientCount;i++)
    {
        if(!(strcmp(patients[i].name,search_patient)))
        {
            found=1;
            printf("%-5s %-20s %-10s %-10s %-5s\n","ID","NAME","AGE","GENDER","CONTACT");
            printf("-------------------------------------------------------------\n");
            printf("%-5d %-20s %-10d %-10s %-5s\n\n",patients[i].id,patients[i].name,patients[i].age,patients[i].gender,patients[i].contact);
            printf("PATIENT FOUND...!!!\n\n");
        }
    }
    if(!found)
        printf("PATIENT NOT FOUND...!!!\n\n");
}

// Function to add a new Doctor
void addDoctor(struct Doctor doctors[], int *doctorCount) {
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
    printf("\nDOCTOR DETAILS:\n\n");
    printf("%-5s %-20s %-10s %-10s %-5s\n","ID","NAME","AGE","GENDER","CONTACT");
    printf("------------------------------------------------------------------\n");
    for ( i = 0; i < doctorCount; i++)
    {
        printf("%-5d %-20s %-10d %-10s %-5s\n\n",doctors[i].did,doctors[i].dname,doctors[i].dage,doctors[i].dgender,doctors[i].dcontact);
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
    int found=0,i;
    printf("\nEnter the Doctor name: ");
    char search_doctor[50];
    printf("\nEnter the Doctor name: ");
    scanf("%s",search_doctor);
    getchar();
    for( i=0;i<doctorCount;i++)
    {
        if(!strcmp(doctors[i].dname,search_doctor))
        {
            found=1;
            printf("%-5s %-20s %-10s %-10s %-5s\n","ID","NAME","AGE","GENDER","CONTACT");
            printf("--------------------------------------------------------------\n");
            printf("%-5d %-20s %-10d %-10s %-5s\n\n",doctors[i].did,doctors[i].dname,doctors[i].dage,doctors[i].dgender,doctors[i].dcontact);
            printf("Doctor found...!!!\n\n");
        }
    }
    if(!found)
        printf("DOCTOR NOT FOUND...!!!\n\n");
}

int main() {
    struct Patient patients[MAX_SIZE];
    struct Doctor doctors[MAX_SIZE];
    int patientCount = 0,doctorCount=0;
    int choice,option;
    int id,did;

    do {
        printf("\t\t\t\tHOSPITAL MANAGEMENT SYSTEM\n\n");
        printf("Choose any one to fill details:\n");
        printf("1. Patient Details\n");
        printf("2. Doctor Details\n");
        printf("3. Exit\n\n");
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
            printf("Exiting...\n\n");
        }
    } while(choice != 3);
}
