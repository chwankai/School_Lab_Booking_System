// 1211207735 See Chwan Kai
// 1211209629 Alvin Seng Chan Jun
// 1211209544 Ong Wen Jun Owen
// 1211208339 Nur Izzati Adlina Binti Izzaq Harahap

// Title >> FIST: Lab Booking

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototype
void add_record();
void display_record();
void search_record();
void delete_record();
void edit_record();
void lab_location();
void registration_page();
void login_page();
char *assign_day();
char *assign_lab();

// structure for reservation details
struct booking
{

    char room_name[50];
    char time[50];
    char days[50];
    int day, n_student, time_slot, count;
};

// structure for booking account
struct account
{

    char first_name[50];
    char last_name[50];
    char username[50];
    char password[50];
};

int main()
{

    // declare
    int choice, answer;

    // display menu
    printf("\n---------------------------------------------\n");
    printf("\tWELCOME TO LAB BOOKING SYSTEM\n");
    printf("---------------------------------------------\n");
    printf("1. Register\n");
    printf("2. Login\n\n");

    // ask for user's action
    printf("Select your action [1 or 2] : ");
    scanf("%d", &answer);

    // if user enter other value
    while (answer > 2 || answer < 1)
    {

        printf("Wrong code input, please try again [1-2]: ");
        scanf("%d", &answer);

    } // end of while loop

    switch (answer)
    {

    case 1:

        // This is for register account
        registration_page();
        break;

    case 2:

        // This is for login
        login_page();
        break;

    } // end of switch case

    // keep looping until user exit
    while (choice != 7)
    {

        // display main menu
        printf("\n---------------------------------------------\n");
        printf("\t\t    MAIN MENU\n");
        printf("---------------------------------------------\n");
        printf("1. Book Lab\n");
        printf("2. Display Reservation\n");
        printf("3. Search Reservation For Specific Day\n");
        printf("4. Cancel Lab Reservation\n");
        printf("5. Edit Number of Students\n");
        printf("6. Display the Lab Location\n");
        printf("7. Exit\n\n");

        // ask for choice
        printf("Enter your choice : ");
        scanf("%d", &choice);

        // done action based on choice
        switch (choice)
        {

        case 1:

            // This is for add record
            add_record();
            break;

        case 2:

            // This is for display record
            display_record();
            fflush(stdin);
            printf("Press any key to return main menu..... \n");
            getchar();
            break;

        case 3:

            // This is for search record (based on day)
            search_record();
            fflush(stdin);
            printf("Press any key to return main menu..... \n");
            getchar();
            break;

        case 4:

            // This is for delete record
            delete_record();
            break;

        case 5:

            // This is to edit number of student in reservation
            edit_record();
            fflush(stdin);
            printf("Press any key to return main menu..... \n");
            getchar();
            break;

        case 6:

            // This is for indicate lab's location
            lab_location();
            fflush(stdin);
            printf("Press any key to return main menu..... \n");
            getchar();
            break;

        case 7:

            // This is to terminate the program
            printf("Thank you for using the service, have a nice day.\n\n");
            exit(0);
            break;

        default:

            // Ask the user to re-enter the code again
            printf("Please enter a valid number.\n\n");
            fflush(stdin);
            printf("Press any key to continue.......");
            getchar();
            break;

        } // end of switch case

    } // end of while loop

} // end of main function

void registration_page()
{

    // declare
    char confirm_password[50];
    struct account id;
    FILE *login;

    // open file
    login = fopen("login_account.txt", "a");

    // if file cannot open
    if (login == NULL)
    {
        fprintf(stderr, "Cannot open file\n");
        exit(0);
    } // end of if

    // display title
    printf("\n-----------------------------\n");
    printf("|        REGISTRATION       |\n");
    printf("-----------------------------\n");

    // ask for first name
    fflush(stdin);
    printf("\nEnter your first name  : ");
    gets(id.first_name);

    // ask for last name
    fflush(stdin);
    printf("Enter your last name   : ");
    gets(id.last_name);

    // ask for MMU ID name
    fflush(stdin);
    printf("Enter your MMU ID      : ");
    gets(id.username);

    do
    {

        // ask for password
        fflush(stdin);
        printf("\nCreate a password      : ");
        gets(id.password);

        // confirm password
        fflush(stdin);
        printf("Confirm your password  : ");
        gets(confirm_password);

        // check if both passwords match
        if (strcmp(id.password, confirm_password) != 0)
        {

            printf("Password unmatch, please check and try again.\n");

        } // end of if

    } while (strcmp(id.password, confirm_password) != 0);

    // save the record into file
    fwrite(&id, sizeof(struct account), 1, login);
    // close the file
    fclose(login);

    // display successful message
    printf("\nThank you %s, your account has created successfully.\n", id.first_name);

    fflush(stdin);
    printf("Press any key to proceed to login...");
    getchar();

    // jump to login page
    login_page();

} // end of registration_page function

void login_page()
{

    // declare
    FILE *login;
    struct account id;
    int found = 0;
    char username[50], password[50];

    // open file
    login = fopen("login_account.txt", "r");

    // if file cannot open
    if (login == NULL)
    {
        fprintf(stderr, "Can't open file. If you never register before, you may first proceed to registration\n");
        exit(0);
    } // end of if

    // display title
    printf("\n------------------------------\n");
    printf("|\t     LOGIN           |\n");
    printf("------------------------------\n");

    do
    {

        // return to the beginning of the file
        rewind(login);

        // ask data from user
        fflush(stdin);
        printf("Enter your MMU ID: ");
        gets(username);
        fflush(stdin);
        printf("Enter your password: ");
        gets(password);

        while (fread(&id, sizeof(struct account), 1, login) > 0)
        {

            // check if we have record in the file & did it match
            if (strcmp(id.username, username) == 0 && strcmp(id.password, password) == 0)
            {

                found = 1;

                // display message
                printf("\n\n>>> Welcome back %s", id.first_name);

            } // end of if

        } // end of while

        // if did not find the result
        if (found == 0)
        {
            printf("\nWrong account or password, please try again.\n");
        } // end of if

    } while (found == 0);

    // close the file
    fclose(login);

} // end of login_page function

void add_record()
{

    // declare
    char answer;
    int building, room, count = 0;
    int *c;
    struct booking info;
    FILE *fp;

    // point C to the address of count
    c = &count;

    do
    {

        // open file
        fp = fopen("information.txt", "a");

        // display menu
        printf("\n------------------------------------\n");
        printf("| RESERVATION: SELECT THE BUILDING |\n");
        printf("------------------------------------\n");
        printf("1. CDP Building (Block B)\n");
        printf("2. FIST Building\n");

        // ask for data
        printf("\nEnter your choice : ");
        scanf("%d", &building);

        // if user enter other value
        while (building > 2 || building < 1)
        {

            printf("Wrong code input, please try again [1-2]: ");
            scanf("%d", &building);

        } // end of while loop

        switch (building)
        {

        case 1:

            // display CDP menu
            printf("\n---------------------------------------------\n");
            printf("|\tCDP BUILDING : SELECT THE LAB\t    |\n");
            printf("---------------------------------------------\n");
            printf("1. MBMR 2021\n");
            printf("2. MBMR 2022\n");

            // ask for choice
            printf("\nEnter your choice: ");
            scanf("%d", &room);

            // if user enter other data
            while (room > 2 || room < 1)
            {

                printf("Wrong code input, please try again [1-2]: ");
                scanf("%d", &room);

            } // end of while loop

            // assign value to info_room_name
            if (room == 1)
            {

                strcpy(info.room_name, "MBMR 2021");

            } // end of if
            else if (room == 2)
            {

                strcpy(info.room_name, "MBMR 2022");

            } // end of else if

            break;

        case 2:

            // display FIST Building menu
            printf("\n----------------------------------------------\n");
            printf("|\tFIST BUILDING : SELECT THE LAB\t     |\n");
            printf("----------------------------------------------\n");
            printf("1. MNBR 2005 APPLICATION LAB\n");
            printf("2. MNBR 2006 DATABASE LAB\n");
            printf("3. MNBR 2007 SOFTWARE ENGINEERING LAB\n");
            printf("4. MNBR 3007 MOLECULAR LAB\n");

            // ask for data
            printf("\nEnter your choice: ");
            scanf("%d", &room);

            // if user enter other value
            while (room > 4 || room < 1)
            {

                printf("Wrong code input, please try again [1-4] : ");
                scanf("%d", &room);

            } // end of while loop

            // assign value to info_room_name
            if (room == 1)
            {

                strcpy(info.room_name, "MNBR 2005 APPLICATION LAB");

            } // end of if
            else if (room == 2)
            {

                strcpy(info.room_name, "MNBR 2006 DATABASE LAB");

            } // end of else if
            else if (room == 3)
            {

                strcpy(info.room_name, "MNBR 2007 SOFTWARE ENGINEERING LAB");

            } // end of else if
            else if (room == 4)
            {

                strcpy(info.room_name, "MNBR 3007 MOLECULAR LAB");

            } // end of else if

            break;

        } // end of switch case

        // ask for day
        printf("\nSelect day [1 for Monday, 2 for Tuesday etc] : ");
        scanf("%d", &info.day);

        // if user enter wrong day
        while (info.day > 7 || info.day < 1)
        {

            printf("Wrong day input, please try again [1-7] : ");
            scanf("%d", &info.day);

        } // end of while loop

        // assign value to info.day
        if (info.day == 1)
        {

            strcpy(info.days, "Monday");

        } // end of if
        else if (info.day == 2)
        {

            strcpy(info.days, "Tuesday");

        } // end of else if
        else if (info.day == 3)
        {

            strcpy(info.days, "Wednesday");

        } // end of else if
        else if (info.day == 4)
        {

            strcpy(info.days, "Thursday");

        } // end of else if
        else if (info.day == 5)
        {

            strcpy(info.days, "Friday");

        } // end of else if
        else if (info.day == 6)
        {

            strcpy(info.days, "Saturday");

        } // end of else if
        else if (info.day == 7)
        {

            strcpy(info.days, "Sunday");

        } // end of else if

        // ask for time slot
        printf("\n1. 08:00 AM - 10:00 AM\n2. 10:00 AM - 12:00 PM\n3. 12:00 PM - 02:00 PM\n4. 02:00 PM - 04:00 PM\n5. 04:00 PM - 06:00 PM\n");
        printf("Select Time Slot : ");
        scanf("%d", &info.time_slot);

        // if user enter wrong code
        while (info.time_slot > 5 || info.time_slot < 1)
        {

            printf("Wrong code input, please try again [1-5] : ");
            scanf("%d", &info.time_slot);

        } // end of while loop

        // assign value to info.time_slot
        if (info.time_slot == 1)
        {

            strcpy(info.time, "08:00AM - 10:00AM");

        } // end of if
        else if (info.time_slot == 2)
        {

            strcpy(info.time, "10:00AM - 12:00PM");

        } // end of else if
        else if (info.time_slot == 3)
        {

            strcpy(info.time, "12:00PM - 02:00PM");

        } // end of else if
        else if (info.time_slot == 4)
        {

            strcpy(info.time, "02:00PM - 04:00PM");

        } // end of else if
        else if (info.time_slot == 5)
        {

            strcpy(info.time, "04:00PM - 06:00PM");

        } // end of else if

        // ask for the number of student
        printf("\nEnter number of student: ");
        scanf("%d", &info.n_student);

        // check if the file cannot open
        if (fp == NULL)
        {
            fprintf(stderr, "can't open file");
        } // end of if
        else
        {
            printf("\nReserved successfully.\n");
        } // end of else

        // save the record into file
        fwrite(&info, sizeof(struct booking), 1, fp);
        // close the file
        fclose(fp);

        // calculate total of lab booked
        count += 1;

        // ask if user want to continue
        printf("Press [Y] to made another reservation : ");
        scanf("%s", &answer);

    } while (answer == 'Y' || answer == 'y'); // end of do while loop, check if user want to continue

    // display result
    printf("\nTotal lab booked : %d\n", *c);
    fflush(stdin);
    printf("Press any key to back to main menu...\n");
    getchar();

} // end of add_record function

void display_record()
{

    // declare
    FILE *fp;
    struct booking info;
    fp = fopen("information.txt", "r");

    // check if file cannot open
    if (fp == NULL)
    {
        fprintf(stderr, "Can't open file. If no reservation has been made before, you should make a reservation first.\n");
        exit(0);
    } // end of if

    // display title
    printf("\n---------------------------------\n");
    printf("|\tPREVIOUS BOOKED LAB\t|\n");
    printf("-----------------------------------------------\n");

    // read the file and display all info
    while (fread(&info, sizeof(struct booking), 1, fp))
    {
        printf("Lab                      : %s\n", info.room_name);
        printf("Booked Day               : %s\n", info.days);
        printf("Time Slot                : %s\n", info.time);
        printf("Number of student        : %d\n", info.n_student);
        printf("-----------------------------------------------\n");

    } // end of while loop

    // close the file
    fclose(fp);

} // end of display_record function

void search_record()
{

    // declare
    FILE *fp;
    struct booking info;
    int day, found = 0;
    char days[50], answer;

    // open file
    fp = fopen("information.txt", "r");

    // if file cannot open
    if (fp == NULL)
    {
        fprintf(stderr, "can't open file\n");
        exit(0);
    } // end of if

    // display title
    printf("\n---------------------------------\n");
    printf("|\tSEARCH RESERVED LAB\t|\n");
    printf("---------------------------------\n");

    // assign value from assign_day function to days
    strcpy(days, assign_day(day));

    printf("-----------------------------------------------\n");

    // read content in file
    while (fread(&info, sizeof(struct booking), 1, fp) > 0)
    {

        // check if we have reservation on this day
        if (strcmp(info.days, days) == 0)
        {

            found = 1;
            // display info
            printf("Lab                      : %s\n", info.room_name);
            printf("Booked Day               : %s\n", info.days);
            printf("Time Slot                : %s\n", info.time);
            printf("Number of student        : %d\n", info.n_student);
            printf("-----------------------------------------------\n");

        } // end of if

    } // end of while

    // if did not find the result on this day
    if (found == 0)
    {
        printf("Did not found any reservation on this day.\n");
    } // end of if

    // close the file
    fclose(fp);

} // end of search_record function

void delete_record()
{

    // declare
    FILE *fp, *fp1;
    struct booking info;
    int day, time_slot, building, room, found = 0;
    char days[50], time[50], room_name[50], answer;

    // open file
    fp = fopen("information.txt", "r");
    fp1 = fopen("temp.txt", "w"); // open a temp file to moved all data except the line that wants to delete

    // if file cannot open
    if (fp == NULL || fp1 == NULL)
    {
        fprintf(stderr, "can't open file\n");
        exit(0);
    } // end of if

    do
    {

        // display title
        printf("\n---------------------------------\n");
        printf("|\tCANCEL RESERVATION\t|\n");
        printf("---------------------------------\n");

        // assigned value from assign_lab to room_name
        strcpy(room_name, assign_lab());

        // assigned value from assign_day function to days
        strcpy(days, assign_day());

        // ask for time
        printf("\n1. 08:00 AM - 10:00 AM\n2. 10:00 AM - 12:00 PM\n3. 12:00 PM - 02:00 PM\n4. 02:00 PM - 04:00 PM\n5. 04:00 PM - 06:00 PM\n");
        printf("Select Time Slot : ");
        scanf("%d", &time_slot);

        // if user enter wrong code
        while (time_slot > 5 || time_slot < 1)
        {

            printf("Wrong code input, please try again: ");
            scanf("%d", &time_slot);

        } // end of while loop

        // assign value to time
        if (time_slot == 1)
        {

            strcpy(time, "08:00AM - 10:00AM");

        } // end of if
        else if (time_slot == 2)
        {

            strcpy(time, "10:00AM - 12:00PM");

        } // end of else if
        else if (time_slot == 3)
        {

            strcpy(time, "12:00PM - 02:00PM");

        } // end of else if
        else if (time_slot == 4)
        {

            strcpy(time, "02:00PM - 04:00PM");

        } // end of else if
        else if (time_slot == 5)
        {

            strcpy(time, "04:00PM - 06:00PM");

        } // end of else if

        // read the file to check if requested record was found
        while (fread(&info, sizeof(struct booking), 1, fp))
        {

            if (strcmp(room_name, info.room_name) == 0 && strcmp(days, info.days) == 0 && strcmp(time, info.time) == 0)
            {
                found = 1;
            } // end of if
            else
            {
                fwrite(&info, sizeof(struct booking), 1, fp1); // if the record was not the one requested, move to temp file
            }                                                  // end of else

        } // end of while loop

        // close the file
        fclose(fp);
        fclose(fp1);

        // if did not found the record
        if (!found)
        {

            printf("\nRecord not found.\n");

        } // end of if

        // if found the record
        if (found)
        {

            // delete old file
            remove("information.txt");

            // replace temp file name with old name
            rename("temp.txt", "information.txt");

            // display success message
            printf("\nRecord deleted succesfully.\n");

        } // end of if

        fflush(stdin);
        printf("Press [Y] to delete another record: ");
        scanf("%c", &answer);

    } while (answer == 'Y' || answer == 'y'); // end of do while loop

} // end of delete_record function

void edit_record()
{

    // declare
    FILE *fp, *fp2;
    struct booking info;
    int day, time_slot, building, room, found = 0;
    char days[50], time[50], room_name[50], answer;

    // open file
    fp = fopen("information.txt", "r");
    fp2 = fopen("tempp.txt", "w"); // temporarily file

    // check if file cannot open
    if (fp == NULL || fp2 == NULL)
    {
        fprintf(stderr, "can't open file\n");
        exit(0);
    } // end of if

    // display title
    printf("\n---------------------------------\n");
    printf("|\tEDIT RESERVATION\t|\n");
    printf("---------------------------------\n");

    // assigned value from assign_lab to room_name
    strcpy(room_name, assign_lab());

    // assigned value from assign_day function to days
    strcpy(days, assign_day());

    // ask for time
    printf("\n1. 08:00 AM - 10:00 AM\n2. 10:00 AM - 12:00 PM\n3. 12:00 PM - 02:00 PM\n4. 02:00 PM - 04:00 PM\n5. 04:00 PM - 06:00 PM\n");
    printf("Select Time Slot : ");
    scanf("%d", &time_slot);

    // if user enter wrong code
    while (time_slot > 5 || time_slot < 1)
    {

        printf("Wrong code input, please try again: ");
        scanf("%d", &time_slot);

    } // end of while loop

    // assigned value to time
    if (time_slot == 1)
    {

        strcpy(time, "08:00AM - 10:00AM");

    } // end of if
    else if (time_slot == 2)
    {

        strcpy(time, "10:00AM - 12:00PM");

    } // end of else if
    else if (time_slot == 3)
    {

        strcpy(time, "12:00PM - 02:00PM");

    } // end of else if
    else if (time_slot == 4)
    {

        strcpy(time, "02:00PM - 04:00PM");

    } // end of else if
    else if (time_slot == 5)
    {

        strcpy(time, "04:00PM - 06:00PM");

    } // end of else if

    // read the file and check if requested record was found
    while (fread(&info, sizeof(struct booking), 1, fp))
    {

        if (strcmp(room_name, info.room_name) == 0 && strcmp(days, info.days) == 0 && strcmp(time, info.time) == 0)
        {
            found = 1;

            // ask for new number of student
            printf("\nRecord found! Original number of student: %d\nEnter new number of student : ", info.n_student);
            scanf("%d", &info.n_student);

            // write into the file after info amended
            fwrite(&info, sizeof(struct booking), 1, fp2);

        } // end of if
        else
        {

            // not the requested record, print directly into the file
            fwrite(&info, sizeof(struct booking), 1, fp2);

        } // end of else

    } // end of while loop

    // close the file
    fclose(fp);
    fclose(fp2);

    // if did not found the record
    if (!found)
    {

        printf("\nRecord not found.\n");

    } // end of if

    // if found the record
    if (found)
    {

        // delete old file
        remove("information.txt");

        // replace temporarily file's name with old name
        rename("tempp.txt", "information.txt");

        // display success message
        printf("\nRecord edited succesfully, the total of student will now be %d.\n", info.n_student);

    } // end of if

} // end of edit_record function

void lab_location()
{

    // declare
    int building, room;
    char room_name[50], location[100];

    // display title
    printf("\n-------------------------\n");
    printf("|\tLAB LOCATION\t|\n");
    printf("-------------------------\n");
    printf("---------------------------------\n");
    printf("|\tSELECT THE BUILDING\t|\n");
    printf("---------------------------------\n");
    printf("1. CDP Building (Block B)\n");
    printf("2. FIST Building\n");

    // ask for data
    printf("Enter your choice : ");
    scanf("%d", &building);

    // if user enter wrong code
    while (building > 2 || building < 1)
    {

        printf("Wrong code input, please try again[1-2]: ");
        scanf("%d", &building);

    } // end of while loop

    switch (building)
    {

    case 1:

        // display CDP title
        printf("\n---------------------------------------------\n");
        printf("|\tCDP BUILDING : SELECT THE LAB\t    |\n");
        printf("---------------------------------------------\n");
        printf("1. MBMR 2021\n");
        printf("2. MBMR 2022\n");

        // ask for data
        printf("Enter your choice: ");
        scanf("%d", &room);

        // if user enter wrong code
        while (room > 2 || room < 1)
        {

            printf("Wrong code input, please try again[1-2]: ");
            scanf("%d", &room);

        } // end of while loop

        // assign value to room_name and location
        if (room == 1)
        {

            strcpy(room_name, "MBMR 2021");
            strcpy(location, "CDP Building (Block B) @ Floor 2");

        } // end of if
        else if (room == 2)
        {

            strcpy(room_name, "MBMR 2022");
            strcpy(location, "CDP Building (Block B) @ Floor 2");

        } // end of else if

        break;

    case 2:

        // display FIST title
        printf("\n----------------------------------------------\n");
        printf("|\tFIST BUILDING : SELECT THE LAB\t     |\n");
        printf("----------------------------------------------\n");
        printf("1. MNBR 2005 APPLICATION LAB\n");
        printf("2. MNBR 2006 DATABASE LAB\n");
        printf("3. MNBR 2007 SOFTWARE ENGINEERING LAB\n");
        printf("4. MNBR 3007 MOLECULAR LAB\n");

        // ask for data
        printf("Enter your choice: ");
        scanf("%d", &room);

        // when user enter wrong code
        while (room > 4 || room < 1)
        {

            printf("Wrong code input, please try again[1-4]: ");
            scanf("%d", &room);

        } // end of while loop

        // assign value to room_name and location
        if (room == 1)
        {

            strcpy(room_name, "MNBR 2005 APPLICATION LAB");
            strcpy(location, "FIST Building @ Floor 2");

        } // end of if
        else if (room == 2)
        {

            strcpy(room_name, "MNBR 2006 DATABASE LAB");
            strcpy(location, "FIST Building @ Floor 2");

        } // end of else if
        else if (room == 3)
        {

            strcpy(room_name, "MNBR 2007 SOFTWARE ENGINEERING LAB");
            strcpy(location, "FIST Building @ Floor 2");

        } // end of else if
        else if (room == 4)
        {

            strcpy(room_name, "MNBR 3007 MOLECULAR LAB");
            strcpy(location, "FIST Building @ Floor 3");

        } // end of else if

        break;

    } // end of switch case

    // display result
    printf("\nThe location of %s is at %s.\n\n", room_name, location);

} // end of lab_location function

char *assign_day()
{

    // declare
    static char days[50];
    int day;

    // Ask for day
    printf("\nSelect day [1 for Monday, 2 for Tuesday etc] : ");
    scanf("%d", &day);

    // give value to days
    if (day == 1)
    {

        strcpy(days, "Monday");

    } // end of if
    else if (day == 2)
    {

        strcpy(days, "Tuesday");

    } // end of else if
    else if (day == 3)
    {

        strcpy(days, "Wednesday");

    } // end of else if
    else if (day == 4)
    {

        strcpy(days, "Thursday");

    } // end of else if
    else if (day == 5)
    {

        strcpy(days, "Friday");

    } // end of else if
    else if (day == 6)
    {

        strcpy(days, "Saturday");

    } // end of else if
    else if (day == 7)
    {

        strcpy(days, "Sunday");

    } // end of else if

    return days;

} // end of assign_day function

char *assign_lab()
{

    // declare
    int building, room;
    static char room_name[50];

    // display title
    printf("---------------------------------\n");
    printf("|\tSELECT THE BUILDING\t|\n");
    printf("---------------------------------\n");
    printf("1. CDP Building (Block B)\n");
    printf("2. FIST Building\n");

    // ask for data
    printf("\nEnter your choice : ");
    scanf("%d", &building);

    // if user enter other value
    while (building > 2 || building < 1)
    {

        printf("Wrong code input, please try again[1-2]: ");
        scanf("%d", &building);

    } // end of while loop

    switch (building)
    {

    case 1:

        // display CDP title
        printf("\n---------------------------------------------\n");
        printf("|\tCDP BUILDING : SELECT THE LAB\t    |\n");
        printf("---------------------------------------------\n");
        printf("1. MBMR 2021\n");
        printf("2. MBMR 2022\n");

        // ask for room choice
        printf("\nEnter your choice: ");
        scanf("%d", &room);

        // if user enter other value
        while (room > 2 || room < 1)
        {

            printf("Wrong code input, please try again[1-2]: ");
            scanf("%d", &room);

        } // end of while loop

        // assigned value to room_name
        if (room == 1)
        {

            strcpy(room_name, "MBMR 2021");

        } // end of if
        else if (room == 2)
        {

            strcpy(room_name, "MBMR 2022");

        } // end of else if

        break;

    case 2:

        // display FIST title
        printf("\n----------------------------------------------\n");
        printf("|\tFIST BUILDING : SELECT THE LAB\t     |\n");
        printf("----------------------------------------------\n");
        printf("1. MNBR 2005 APPLICATION LAB\n");
        printf("2. MNBR 2006 DATABASE LAB\n");
        printf("3. MNBR 2007 SOFTWARE ENGINEERING LAB\n");
        printf("4. MNBR 3007 MOLECULAR LAB\n");

        // ask for room choice
        printf("Enter your choice: ");
        scanf("%d", &room);

        // if user enter other value
        while (room > 4 || room < 1)
        {

            printf("Wrong code input, please try again[1-4]: ");
            scanf("%d", &room);

        } // end of while loop

        // assigned value to room_name
        if (room == 1)
        {

            strcpy(room_name, "MNBR 2005 APPLICATION LAB");

        } // end of if
        else if (room == 2)
        {

            strcpy(room_name, "MNBR 2006 DATABASE LAB");

        } // end of else if
        else if (room == 3)
        {

            strcpy(room_name, "MNBR 2007 SOFTWARE ENGINEERING LAB");

        } // end of else if
        else if (room == 4)
        {

            strcpy(room_name, "MNBR 3007 MOLECULAR LAB");

        } // end of else if

        break;

    } // end of switch case

    return room_name;

} // end of assign_lab function
