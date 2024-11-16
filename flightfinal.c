#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void red () {
  printf("\033[1;31m");
}

void yellow() {
  printf("\033[1;33m");
}

void green(){
    printf("\033[32m");
}

void blue(){
    printf("\033[0;34m");
}

void purple(){
    printf("\033[0;35m");
}

void cyan(){
    printf("\033[0;36m");
}

void reset () {
  printf("\033[0m");
}
// this changes color to white

// struct for storing data of each flight
struct flight
{
  char airline[30];
  char date[12];
  char from[10];
  char to[10];
  char dep_time[8];
  char duration[10];
  char price[12];
  char code[6];
};

struct string {
  char str[20];
};

// Global array of struct string to store city names
struct string cities[] = {
    {"Mumbai"},
    {"Delhi"},
    {"Bangalore"},
    {"Chennai"},
    {"Cochin"},
    {"Kolkata"},
    {"Hyderabad"},
    {"Pune"},
    {"Jaipur"},
    {"Panaji"},
    {"Patna"},
    {"Lucknow"}

};

// Struct to store food details
struct food
{
    char name[50];
    char details[100];
    float price;
};

// Array of food options
struct food food_menu[] = {
    {"Tea/Coffee", "Your choice of hot beverage.", 50.0},
    {"Soft Drinks", "Variety of soft drinks available.", 60.0},
    {"Orange Juice", "Freshly squeezed orange juice.", 70.0},
    {"Mineral Water", "Bottled mineral water.", 30.0},
    {"Chicken Biryani", "Delicious rice dish with tender chicken pieces and aromatic spices.", 250.0},
    {"Fish Curry", "Spicy and tangy fish curry cooked with fresh fish pieces.", 220.0},
    {"Paneer Tikka", "Grilled cottage cheese marinated in spices and served with mint chutney.", 200.0},
    {"Poha", "Flattened rice cooked with onions, peanuts, and spices.", 150.0},
    {"Sandwich", "Classic sandwich with layers of vegetables and mayonnaise.", 180.0},
    {"Veg Noodles", "Stir-fried noodles with crunchy vegetables and soy sauce.", 170.0},
    {"North Indian Meal", "Includes Roti, Paneer Butter Masala, Dal Makhani, and Rice.", 280.0},
    {"South Indian Meal", "Includes Idli, Dosa, Sambar, and Coconut Chutney.", 260.0},
    {"Rajma Chawal", "Red kidney beans curry served with steamed rice.", 210.0},
    {"Veg Biryani", "Spiced rice cooked with mixed vegetables.", 200.0}
};

int quantities[14]={0};
bool orederedfood=false;

// array of all flight data
struct flight arr[18241];
struct flight preferable[300];
int preferable_idx=0;
bool flightavailable=false;

//datatype for return flights
struct flight returnpreferable[300];
int returnpreferable_idx=0;
bool returnflightavailable=false;

char name[50];
char age[3];
char email[50];
char mob[11];
struct flight choosed;
struct flight rchoosed;
int trip_type;
int tempidx;
int tempreturnidx;

int tickets=0;
int return_tickets=0;
// Variables to store user input

// Variable to store total amount
float total = 0; 

// To store origin of the flight
char origin[150];

// To store destination of the flight
char destination[150];

// To store date of the flight
char datestr[20];

// To store return date of the flight
char return_date[20];

void Welcome();

bool citycheck(char cityname[150]);

void read_data();

void cus_data();

// flushes the before stored values in origin,destination,datestr
void flushInputBuffer();

int check_data();

void displayavailablecities();

void inputFlight();

// Function prototype declaration for city name correction.
void correctCityName(char cityName[]);

// Function prototype declaration for inputing date.
char *input_date();
char *input_return_date();

// Function prototype declaration for valid date checking.
bool is_valid_date(int day, int month, int year);

void checkFlightAvailability();

void checkReturnFlightAvailability();

void display_available_flights();

void display_return_available_flights();

void selectFlight();

void selectreturnFlight();

void displayflight(struct flight given );

void displayreturnflight(struct flight given );

void enterNoOfTickets();

void enterNoOfReturnTickets();

void printSummary();

void printReturnSummary();

void confirmBooking();

void display_menu();

void select_food();

void order_food();

void payment();

void printSystemThankYouMessage();


int main()
{
   Welcome();
  // this will read all the data from file and puts in the arr array
  read_data();

  int total_flights = 18241;

  yellow();
  printf("\t----PLEASE ENTER YOUR INFORMATION----\n");
  reset();
  printf("\n");
  cus_data();
  displayavailablecities();

  // Calling inputFlight function to start inputing flight details
  inputFlight();

  //checks if a flight is available or not
  checkFlightAvailability();
  if(trip_type==2)
  checkReturnFlightAvailability();
  
  if(trip_type==1 || returnflightavailable)
  {
  if(flightavailable){
    display_available_flights();
    selectFlight();
    enterNoOfTickets();
    printSummary();
    display_menu();
    select_food();
    order_food(); 
    }
  }
  

  if(returnflightavailable){
    display_return_available_flights();
    selectreturnFlight();
    enterNoOfReturnTickets();
    printReturnSummary();
    display_menu();
    select_food();
    total=0;
    order_food();
    }
    
    if(flightavailable)
    {
      payment();
    }
  
    printSystemThankYouMessage();

  reset();
  return 0;

}


void Welcome() {
    // Clear the screen for a fresh start
    system("cls");
    
    green();
    printf("\n");
    printf("***********************************************************************************\n");
    printf("*                                                                                 *\n");
    printf("*                 WELCOME TO THE AIRLINE RESERVATION SYSTEM                       *\n");
    printf("*                                                                                 *\n");
    printf("*      Where Your Journey Begins! Experience the Convenience of Booking Flights   *\n");
    printf("*          Effortlessly and Enjoy a Seamless Travel Experience with Us.           *\n");
    printf("*                                                                                 *\n");
    printf("*       We Offer a Wide Range of Destinations, Competitive Prices, and Flexible   *\n");
    printf("*                 Booking Options to Suit Your Travel Needs.                      *\n");
    printf("*                                                                                 *\n");
    printf("*                    Your Adventure Awaits. Start Booking Now!                    *\n");
    printf("*                                                                                 *\n");
    printf("***********************************************************************************\n");

    // Pause for user interaction
    printf("\n");
    printf("Press any key to continue...");
    getchar();  // Wait for user input
    getchar();  // Wait for another key press to continue
    reset();    // Reset text color
}


bool citycheck(char cityname[150]){
  for(int i=0;i<12;i++){
    if(!strcmp(cityname,cities[i].str)){
      return true;
    }
  }
  return false;
}


void read_data()
{
  // Open the file in binary mode.
  FILE *fp = fopen("flight_dataset.csv", "rb");

  //  Number of lines in .csv file
  char line[18241];
  int idx = 0;

  while (fgets(line, sizeof(line), fp))
  {
    // Split each line into fields using the comma delimiter.
    char *fields[10];
    int num_fields = 0;
    char *field = strtok(line, ",");
    while (field)
    {
      fields[num_fields++] = field;
      field = strtok(NULL, ",");
    }

    struct flight temp;

    // Copying each field to the appropriate data type.
    strncpy(temp.airline, fields[1], sizeof(temp.airline) - 1);
    temp.airline[sizeof(temp.airline) - 1] = '\0';

    strncpy(temp.date, fields[2], sizeof(temp.date) - 1);
    temp.date[sizeof(temp.date) - 1] = '\0';

    strncpy(temp.from, fields[3], sizeof(temp.from) - 1);
    temp.from[sizeof(temp.from) - 1] = '\0';

    strncpy(temp.to, fields[4], sizeof(temp.to) - 1);
    temp.to[sizeof(temp.to) - 1] = '\0';

    strncpy(temp.dep_time, fields[5], sizeof(temp.dep_time) - 1);
    temp.dep_time[sizeof(temp.dep_time) - 1] = '\0';

    strncpy(temp.duration, fields[6], sizeof(temp.duration) - 1);
    temp.duration[sizeof(temp.duration) - 1] = '\0';

    strncpy(temp.price, fields[7], sizeof(temp.price) - 1);
    temp.price[sizeof(temp.price) - 1] = '\0';

    strncpy(temp.code, fields[8], sizeof(temp.code) - 1);
    temp.code[sizeof(temp.code) - 1] = '\0';

    arr[idx++] = temp;
  }

  // Close the file.
  fclose(fp);
  return;
}


void cus_data(){
   
    purple();
    printf("Name: ");
    green();
    scanf("%s",&name);
    
    flushInputBuffer();

    purple();
    printf("Age: ");
    green();
    scanf("%s",&age);

    flushInputBuffer();

    purple();
    printf("Email: ");
    green();
    scanf("%s",&email);
    

    flushInputBuffer();

    purple();
    printf("Mobile Number: ");
    green();
    scanf("%s",&mob);

    flushInputBuffer();

    printf("\n");
    reset();
    
    if(check_data()){

    }
    else{
      cus_data();
    }
}


void flushInputBuffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}


int check_data(){
  bool check=true;

  // Cheching for age
  for(int i=0;age[i]!='\0';i++){
    if (!isdigit(age[i])) {
            red();
            printf("Enter Valid Age!!! \n");
            reset();
            check=false;
            break;
        }
  }
  if(check){
    if(atoi(age)>120){
      red();
      printf("Enter Valid Age!!! ");
      reset();
      check=false;
    }
  }

  //Cheching for mob
  if(strlen(mob)==10){
    for(int i=0;mob[i]!='\0';i++){
    if (!isdigit(mob[i])) {
          red();
          printf("Enter Valid Mobile Number!!! \n");
          reset();
          check=false;
          break;
        }
  }
  }
  else{
    red();
    printf("Enter Valid Mobile Number!!! \n");
    reset();
    check=false;
  }
  
  // Checking for email 
  if(strlen(email)>10){
    int len= strlen(email);
    if(email[len-10]=='@' && (email[len-9]=='e' || email[len-9]=='g') && email[len-8]=='m' && email[len-7]=='a' && email[len-6]=='i' && email[len-5]=='l'
    &&email[len-4]=='.'  && email[len-3]=='c' && email[len-2]=='o' && email[len-1]=='m'){
      
    }
    else{
      red();
      printf("Enter Valid Email address!!! \n");
      reset();
      check=false;
    }
  }
  else{
    red();
    printf("Enter Valid Email address!!! \n");
    reset();
    check=false;
  }
   
    if(check){
    return 1;
    }
    else{
      printf("\n");
      return 0;
    }
}


// this function is to display the number of citites which have our flight system
void displayavailablecities(){ 

  reset();
  printf("\n");

  yellow();
  printf("We have flights availabile in following cities:\n\n");

  cyan();
  for(int i=0;i<12;i++){
    printf("%s\n\n",cities[i].str);
  }

  reset();
}


void inputFlight()
{

  // Prompting user to enter origin
  purple();
  printf("Enter origin: ");
  cyan();
  scanf("%149s", origin);

  printf("\n");
  // Remove newline character from the end
  correctCityName(origin);
  // Correcting the capitalization of the origin city
  // Prompting user to enter destination
  purple();
  printf("Enter destination: ");
  cyan();
  scanf("%149s", destination);

  printf("\n");
  // Remove newline character from the end
  correctCityName(destination);

  // Correcting the capitalization of the destination city
  flushInputBuffer();

   if(citycheck(origin) && citycheck(destination)){
  }
  else{
    red();
    printf("Enter the name of cities from above listed cities\n");
    reset();
    inputFlight();
    return;

  }
  // Prompt user to select trip type
  purple();
  printf("Select trip type:\n");
  printf("1. One-way\n");
  printf("2. Round trip\n");
  cyan();
  printf("Enter your choice: ");
  scanf("%d",&trip_type);

  printf("\n");

  // Copying date string from input date function.
  strcpy(datestr, input_date());

  if(trip_type==2){
    strcpy(return_date, input_return_date());
  }

 
  // Displaying search criteria
  printf("\n");
  yellow();
  printf("Searching for flights from %s to %s on %s ...\n\n", origin, destination, datestr);
  reset();

  // Displaying search criteria
  if(trip_type==2)
  {
  printf("\n");
  yellow();
  printf("Searching for flights from %s to %s on %s ...\n\n", destination, origin, return_date);
  reset();
  }
}


// Function to correct the city name entered by the user
void correctCityName(char cityName[])
{
  int i;
  int capitalizeNext = 1;
  // Flag to indicate whether the next character should be capitalized

  // Loop through each character in the city name
  for (i = 0; cityName[i] != '\0'; i++)
  {
    // If the character should be capitalized
    if (capitalizeNext)
    {
      // Capitalize the current character
      cityName[i] = toupper(cityName[i]);
      capitalizeNext = 0;
      // Reset the flag
    }
    // If the character is a space set flag to capitalize next character
    else if (cityName[i] == ' ')
    {
      capitalizeNext = 1;
    }
    // Otherwise, convert the character to lowercase
    else
    {
      cityName[i] = tolower(cityName[i]);
    }
  }
}


// Function to input and return the entered date string.
char *input_date()
{
  // String to store date.
  char date[20];
  
  // Loop to ensure user enters correct date.
  while (true)
  {
    // Prompting user to enter date.
    purple();
    printf("Enter date in DD/MM/YYYY format : ");
    cyan();
    scanf("%19s", date);
    // Reading the entered date.
    char *datestr = malloc(strlen(date) + 1);
  // Dynamic memory allocation for datestr.

    bool redflag = false;
    printf("\n");
    // Red flag to ensure date string is continuous.

    // Loop to check date string is continuous.
    for (int i = 0; i < 10; i++)
    {
      if (date[i] == '\0')
      {
        redflag = true;
      }
    }

    // Telling user invalid format if date string is not continuous.
    if (redflag)
    {
      red();
      printf("Invalid format.\n\n");
      reset();
      printf("Please enter in DD/MM/YYYY format.\n");
      continue;
    }

    // Ensuring correct format for date.
    if (date[2] != '/' || date[5] != '/')
    {
      printf("Invalid format.\nPlease enter in DD/MM/YYYY format.\n");
      continue;
    }

    // Parsing day,month and year as integers from characters using atoi() function.
    int day = atoi(date);
    int month = atoi(date + 3);
    int year = atoi(date + 6);

    // Checking if the date is valid or not.
    if (is_valid_date(day, month, year))
    {
     
      // Copying date into datestr.
      strcpy(datestr, date);
      break;
      // Breaking out of the loop if date is valid.
    }
    else if (year >= 2025)
    {
      printf("flights are only available for year 2024 for now..\nWant to see flights for 2024\n");
      continue;
    }
    else
    {
      printf("Invalid Date.\nPlease enter a valid date.\n");
      continue;
      // Continuing the loop if date is invalid.
    }
    return datestr;
    // Returning datestr.
  }
}


char *input_return_date(){

  // String to store date.
  char rdate[20];
  
  // Loop to ensure user enters correct date.
  while (true)
  {
    // Prompting user to enter date.
    purple();
    printf("Enter return date in DD/MM/YYYY format : ");
    cyan();
    scanf("%19s", rdate);
    // Reading the entered date.
    char *return_date = malloc(strlen(rdate) + 1);
  // Dynamic memory allocation for datestr.

    bool redflag = false;
    printf("\n");
    // Red flag to ensure date string is continuous.

    // Loop to check date string is continuous.
    for (int i = 0; i < 10; i++)
    {
      if (rdate[i] == '\0')
      {
        redflag = true;
      }
    }

    // Telling user invalid format if date string is not continuous.
    if (redflag)
    {
      red();
      printf("Invalid format.\n\n");
      reset();
      printf("Please enter in DD/MM/YYYY format.\n");
      continue;
    }

    // Ensuring correct format for date.
    if (rdate[2] != '/' || rdate[5] != '/')
    {
      printf("Invalid format.\nPlease enter in DD/MM/YYYY format.\n");
      continue;
    }

    // Parsing day,month and year as integers from characters using atoi() function.
    int day = atoi(rdate);
    int month = atoi(rdate + 3);
    int year = atoi(rdate + 6);

    // Checking if the date is valid or not.
    if (is_valid_date(day, month, year))
    {
     
      // Copying date into datestr.
      strcpy(return_date, rdate);
      break;
      // Breaking out of the loop if date is valid.
    }
    else if (year >= 2025)
    {
      printf("flights are only available for year 2024 for now..\nWant to see flights for 2024\n");
      continue;
    }
    else
    {
      printf("Invalid Date.\nPlease enter a valid date.\n");
      continue;
      // Continuing the loop if date is invalid.
    }
    return return_date;
    // Returning return_date.
  }
}


// Function to check if date is valid or not.
bool is_valid_date(int day, int month, int year)
{
  // Invalid day,month,year checking.
  if (month < 1 || month > 12 || day < 1 || year != 2024)
  {
    return false;
    // Returning false if invalid day,month,year found.
  }

  // Initialising max days to keep track of maximum no.of days in a month.
  int maxDays;

  // Equalling maxdays according to the month entered.
  switch (month)
  {
  // 31 day months.
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    maxDays = 31;
    break;
  // 30 day months.
  case 4:
  case 6:
  case 9:
  case 11:
    maxDays = 30;
    break;
  // February month.
  case 2:
    maxDays = 29;
    break;
  }

  // Ensuring entered day is not greater than maxdays in the respective month.
  return (day <= maxDays);
}


void checkFlightAvailability()
{
    bool found = false;
    int recheck = 0;
    flightavailable=false;

    // Iterate through all flights
    for (int i = 0; i < 18241; i++)
    {
        // Check if the flight matches the user's input
        if (strcmp(arr[i].from, origin) == 0 && strcmp(arr[i].to, destination) == 0 && strcmp(arr[i].date, datestr) == 0)
        { 
            found = true;
            flightavailable=true;
            if (trip_type==1){
            preferable[preferable_idx++]=arr[i];
          }
        }
    }
    
    if (!found) {
        while (true)
        {
            red();
            printf("Flight not available on that date.\n\n");
            green();
            printf("Do you want to try a different date? (0/1): ");
            reset();
            if (scanf("%d", &recheck) != 1)
            {
                // Invalid input, clear input buffer
                printf("Invalid input. Please enter 0 or 1.\n");
                continue;
            }
            printf("\n");
            if (recheck == 1)
            {
                // Clear input buffer
                while (getchar() != '\n');
                // Call inputFlight to get a new date
                inputFlight();
                // Check flight availability again with the new date
                checkFlightAvailability();
                return; // Exit the function after rechecking
            }
            else if (recheck == 0)
            {   
              yellow();
              printf("Thank You for Visiting.\nSee You Soon!");
              reset();
                return; // Exit the loop
            }
            else
            {
                printf("Invalid input. Please enter 0 or 1.\n");
            }
        }
    }
}


void checkReturnFlightAvailability()
{
    bool found = false;
    int recheck = 0;
    returnflightavailable=false;
    // Iterate through all flights
    for (int i = 0; i < 18241; i++)
    {
        // Check if the flight matches the user's input
        if (strcmp(arr[i].from, destination) == 0 && strcmp(arr[i].to, origin) == 0 && strcmp(arr[i].date, return_date) == 0)
        { 
            found = true;
            returnflightavailable=true;
            returnpreferable[returnpreferable_idx++]=arr[i];
        }
    }

    for (int i = 0; i < 18241; i++)
    {
    if (strcmp(arr[i].from, origin) == 0 && strcmp(arr[i].to, destination) == 0 && strcmp(arr[i].date, datestr) == 0 && returnflightavailable==true)
        { 
            preferable[preferable_idx++]=arr[i];
        }
    }    
    
    if (!found) {
        while (true)
        {
            flightavailable=false;
            red();
            printf("Flight not available on that date.\n\n");
            green();
            printf("Do you want to try a different date? (0/1): ");
            reset();
            if (scanf("%d", &recheck) != 1)
            {
                // Invalid input, clear input buffer
                printf("Invalid input. Please enter 0 or 1.\n");
                continue;
            }
            printf("\n");
            if (recheck == 1)
            {
                // Clear input buffer
                while (getchar() != '\n');
                // Call inputFlight to get a new date
                inputFlight();
                // Check flight availability again with the new date
                checkFlightAvailability();
                if (trip_type==2)
                checkReturnFlightAvailability();
                return; // Exit the function after rechecking
            }
            else if (recheck == 0)
            {   
              yellow();
              printf("Thank You for Visiting.\nSee You Soon!");
              reset();
                return; // Exit the loop
            }
            else
            {
                printf("Invalid input. Please enter 0 or 1.\n");
            }
        }
    }
}


void display_available_flights(){
  green();
  printf("flights from %s to %s on %s are available\n\n", origin, destination, datestr);
  cyan();
  printf("Below are options for flights from %s to %s on %s are available :\n\n", origin, destination, datestr);
  reset();

  for(int i=0;i<preferable_idx;i++){
    red();
    printf("Index:%d ->  ",i);
    
    reset();
    printf("%s ",preferable[i].airline);
    
    printf("%s\n\n",preferable[i].code);
    cyan();
    printf("   %s ",preferable[i].from);
    reset();
    printf("To ");
    cyan();
    printf("%s\n\n",preferable[i].to);

    purple();
    printf("Departure : ");
    yellow();
    printf("%s   ",preferable[i].dep_time);
    purple();
    printf("Duration : ");
    yellow();
    printf("%s\n\n",preferable[i].duration);

    purple();
    printf("   Price: ");
    green();
    printf("%s/-\n\n",preferable[i].price);
    reset();

    printf("  -------------------------------------------------------------------------------------\n\n");
  }

  

}


void display_return_available_flights(){
  green();
  printf("flights from %s to %s on %s are available\n\n", destination, origin, return_date);
  cyan();
  printf("Below are options for flights from %s to %s on %s are available :\n\n", destination, origin, return_date);
  reset();

  for(int i=0;i<returnpreferable_idx;i++){
    red();
    printf("Index:%d ->  ",i);
    
    reset();
    printf("%s ",returnpreferable[i].airline);
    
    printf("%s\n\n",returnpreferable[i].code);
    cyan();
    printf("   %s ",returnpreferable[i].from);
    reset();
    printf("To ");
    cyan();
    printf("%s\n\n",returnpreferable[i].to);

    purple();
    printf("Departure : ");
    yellow();
    printf("%s   ",returnpreferable[i].dep_time);
    purple();
    printf("Duration : ");
    yellow();
    printf("%s\n\n",returnpreferable[i].duration);

    purple();
    printf("   Price: ");
    green();
    printf("%s/-\n\n",returnpreferable[i].price);
    reset();

    printf("  -------------------------------------------------------------------------------------\n\n");
  }

}


void selectFlight(){
    green();
  printf("Enter the index of the flight that you like to Book : ");
 

  yellow();
  scanf("%d",&tempidx);
  printf("\n");
  reset();
  if(tempidx>=preferable_idx || tempidx<0){
  cyan();
  printf("Invalid index!!\n");
  printf("Select the index for the above mentioned Flights\n");
  reset();
  selectFlight();
  }
  else
  {
  choosed=preferable[tempidx];

  cyan();

  printf("You have Selected flight of index %d\n\n",tempidx);
  reset();

  displayflight(choosed);
  }
}


void selectreturnFlight(){
    green();
  printf("Enter the index of the flight that you like to Book : ");
  

  yellow();
  scanf("%d",&tempreturnidx);
  printf("\n");
  reset();
  if(tempreturnidx>=returnpreferable_idx || tempreturnidx<0){
  cyan();
  printf("Invalid index!!\n");
  printf("Select the index for the above mentioned Flights\n");
  reset();
  selectreturnFlight();
  }
  else
  {

  rchoosed=returnpreferable[tempreturnidx];

  cyan();

  printf("You have Selected flight of index %d\n\n",tempreturnidx);
  reset();

  displayreturnflight(rchoosed);
  }
}


void displayflight(struct flight given ){
   
    
    red();
    printf("%s ",given.airline);
    
    printf("%s\n\n",given.code);
    cyan();
    printf("   %s ",given.from);
    reset();
    printf("To ");
    cyan();
    printf("%s\n\n",given.to);

    purple();
    printf("Departure : ");
    yellow();
    printf("%s   ",given.dep_time);
    purple();
    printf("Duration : ");
    yellow();
    printf("%s\n\n",given.duration);

    purple();
    printf("   Price: ");
    green();
    printf("%s/-\n\n",given.price);
    reset();

}


void displayreturnflight(struct flight given ){
   
    
    red();
    printf("%s ",given.airline);
    
    printf("%s\n\n",given.code);
    cyan();
    printf("   %s ",given.from);
    reset();
    printf("To ");
    cyan();
    printf("%s\n\n",given.to);

    purple();
    printf("Departure : ");
    yellow();
    printf("%s   ",given.dep_time);
    purple();
    printf("Duration : ");
    yellow();
    printf("%s\n\n",given.duration);

    purple();
    printf("   Price: ");
    green();
    printf("%s/-\n\n",given.price);
    reset();

}


void enterNoOfTickets(){
  reset();
  printf("Enter the Number of Ticket You want to Book : ");
  yellow();
  scanf("%d",&tickets);
  reset();
  printf("\n");
}


void enterNoOfReturnTickets(){
  reset();
  printf("Enter the Number of Return Ticket You want to Book : ");
  yellow();
  scanf("%d",&return_tickets);
  reset();
  printf("\n");
}

void printSummary(){
    cyan();
    printf("******************************************************************************\n");
    printf("*                                                                            \n");
    printf("*                          TICKET SUMMARY                                    \n");
    printf("*                                                                            \n");
    printf("* Flight Code:       %s\n", choosed.code);
    printf("* Departure:         %s\n", origin);
    printf("* Destination:       %s\n", destination);
    printf("* Date:              %s\n", datestr);
    printf("* Time:              %s\n", choosed.duration);
    printf("* Price:             %s\n", choosed.price);
    printf("* Number of Tickets: %d\n", tickets);
    printf("                                                                            \n");
    printf("******************************************************************************\n");

    printf("\n\n\n");  // Add some additional newlines for spacing

    printf("Press any key to continue...");
    getchar();  // Wait for user input
    getchar();  // Wait for another key press to continue
    reset();
    confirmBooking();
}


void printReturnSummary(){
  if(flightavailable && returnflightavailable){
    cyan();
    printf("******************************************************************************\n");
    printf("*                                                                            \n");
    printf("*                    RETURN TICKET SUMMARY                                  \n");
    printf("*                                                                            \n");
    printf("* Flight Code:       %s\n", rchoosed.code);
    printf("* Departure:         %s\n", destination);
    printf("* Destination:       %s\n", origin);
    printf("* Date:              %s\n", return_date);
    printf("* Time:              %s\n", rchoosed.duration);
    printf("* Price:             %s\n", rchoosed.price);
    printf("* Number of Tickets: %d\n", return_tickets);
    printf("                                                                            \n");
    printf("******************************************************************************\n");

    printf("\n\n\n");  // Add some additional newlines for spacing

    printf("Press any key to continue...");
    getchar();  // Wait for user input
    getchar();  // Wait for another key press to continue
    reset();
    confirmBooking();
  }
}
void confirmBooking() {
    int choice;

    printf("\n");
    purple();
    printf("Do you confirm the booking of the above ticket? (1: Yes / 0: No): ");
    yellow();
    scanf("%d", &choice);

    if (choice == 0) {
            exit(0);  // Exit the program
    }
    if(choice==1) {
      printf("\n");
    }
    else {
        red();
        printf("Invalid choice! Please enter 1 for Yes or 0 for No.\n");
        reset();
        confirmBooking();  // Ask for confirmation again
    }
}

// Function to display the main food menu
void display_menu() {
    printf("\n");          
    // Newline for formatting
    purple();                
    // Set text color to cyan
     printf("\n");
    printf("=========================================\n");
    printf("       Welcome to Flight Food Menu!\n");
    printf("=========================================\n\n");  
    // Display welcome message
    reset();               
    // Reset text color
    for (int i = 0; i < 14; i++) {  
        // Loop through the food menu
        printf("%d. ", i + 1);         
        // Display item number
        green();                      
         // Set text color to yellow
        if(i<9){
        printf("%-30s", food_menu[i].name); 
        }
        else{
          printf("%-29s", food_menu[i].name);
        }
        // Display food name with formatting
        reset();                        
        // Reset text color
        printf("(INR ");                
        // Display currency
        yellow();                        
        // Set text color to green
        printf("%.2f", food_menu[i].price); 
        // Display food price
        reset();                        
        // Reset text color
        printf(") - ");                 
        // Separator
        blue();                         
        // Set text color to blue
        printf("%s", food_menu[i].details);
         // Display food details
        reset();                       
         // Reset text color
        printf("\n");                  
        // Newline
    }
    printf("\n");         
     // Newline for formatting
}


// Function to let the user select food items and quantities
void select_food() {
    char input[100];       
    // Array to store user input
    purple();              
    // Set text color to purple
    printf("Please enter the item codes separated by commas (e.g., 1,3,5)(enter 0 for no order):\n");  
    // Prompt user to enter item codes
    reset();               
    // Reset text color

    while (true) { // Loop until valid input is provided
        cyan();                
        // Set text color to cyan
        scanf("%s", input);   
        printf("\n"); 
        // Read user input
        char *token = strtok(input, ",");  
        // Tokenize input string
        bool validInput = true;

        while (token != NULL) {  
            // Loop through tokens
            int index = atoi(token) - 1;  
            // Convert token to integer and adjust index
            if (index >= 0 && index < 14) {  
                // Check if index is valid
                yellow();          
                // Set text color to yellow
                printf("Quantity for %s (%d): ", food_menu[index].name, index + 1);  
                // Prompt user for quantity
                reset();           
                // Reset text color
                cyan();            
                // Set text color to cyan
                scanf("%d", &quantities[index]); 
                orederedfood=true; 
                // Read quantity for the selected item
            }
            else if (index==-1) {
              break;
            }
            else {
                printf("Invalid input. Please enter a valid item code.\n");
                // Print invalid input message
                validInput = false;
                break;
            }
            token = strtok(NULL, ",");  
            // Get next token
        }

        if (validInput) {
            break; // Exit the loop if valid input is provided
        }
    }
}


// Function to display the order summary
void order_food() {
  if(orederedfood){
    printf("\nYour Order:\n\n");  

    // Display order header
    for (int i = 0; i < 14; i++) {  
        // Loop through food items
        if (quantities[i] > 0) {  
            // Check if quantity is greater than 0
            yellow();         
            // Set text color to yellow
            printf("%s x %d (INR ", food_menu[i].name, quantities[i]);  
            // Display food name and quantity
            green();          
            // Set text color to green
            printf("%.2f", food_menu[i].price * quantities[i]);  
            // Calculate and display total price for the item
            reset();          
            // Reset text color
            printf(")\n");    
            // Newline
            total += food_menu[i].price * quantities[i];  
            // Add item price to total
        }
        }
    
    printf("\n");         
     // Newline for formatting
    purple();              
    // Set text color to purple
    printf("Total Amount: INR "); 
     // Display total amount header
    green();              
     // Set text color to green
    printf("%.2f\n", total);
      // Display total amount
    yellow();             
      // Reset text color
    printf("\nThank you for ordering from our Exquisite Menu!"); 
    printf("\nHave a nice and safe journey!\n\n");
     // Display thank you message
     reset();
  }
  else{
    yellow();
    printf("\nThank you for considering our Flight Food Menu.\n");
    printf("Should you wish to savor our offerings later, we're here to enhance your journey.\n");
    printf("Have a pleasant flight!\n");
    reset();
  }
}


void payment(){
int ch;
purple();
printf("Press 1 to pay through UPI || Press 0 to use Net Banking\n");
reset();
yellow();
scanf("%d",&ch);
reset();
printf("\n");

if(ch==1){
cyan();
printf("Please pay on the given upi id: 123@sbi\n");
printf("\n");
reset();
green();
printf("Amount to be paid: %f\n",(atoi(preferable[tempidx].price)*tickets+total+atoi(returnpreferable[tempreturnidx].price)*return_tickets));
printf("\n");
reset();
yellow();
printf("After confirmation the flight ticket will be sent to your registered email\n");
printf("Your registered E-Mail adress is: %s\n",email);
reset();
printf("If you wish to change your email then press 1 else press any other number\n");

int op;
scanf("%d",&op);

if(op==1){
  printf("Enter your new E-mail\n");
  scanf("%s",&email);
  yellow();
  printf("New E-Mail: %s\n",email);
  reset();
}

printf("\n");
reset();
}
else if(ch==0){
cyan();
printf("Please pay to the given bank account:\n");
printf("Recepient Name:[ ]\n");
printf("Account Number:[ ]\n");
printf("Routing Number:[ ]\n");
printf("\n");
reset();
green();
printf("Amount to be paid: %f\n",atoi(preferable[tempidx].price)*tickets+total+atoi(returnpreferable[tempreturnidx].price)*return_tickets);
reset();
printf("\n");
yellow();
printf("After confirmation the flight ticket will be sent to your registered email\n");
printf("Your registered E-Mail adress is: %s\n",email);
reset();
printf("If you wish to change your email then press 1 else press any other number\n");
int op;
scanf("%d",&op);

if(op==1)
{
  printf("Enter your new E-mail\n");
  scanf("%s",&email);
  yellow();
  printf("Your New Email Id is : ");
  yellow();
  printf("%s",email);
}

printf("\n");
reset();
}
else{
  printf("INVALID CHOICE\n");
  payment();
}
}
void printSystemThankYouMessage() {
    green();
    printf("\n");
    printf("*******************************************************\n");
    printf("**                                                   **\n");
    printf("**               Thank You for Choosing              **\n");
    printf("**             Our Luxury Flight Service!            **\n");
    printf("**                                                   **\n");
    printf("**  Your trust is the wind beneath our wings.        **\n");
    printf("**  Your journey is our mission.                     **\n");
    printf("**                                                   **\n");
    printf("**  We are delighted to be a part of your adventure. **\n");
    printf("**  Here's to many more shared destinations!         **\n");
    printf("**                                                   **\n");
    printf("**              With heartfelt gratitude,            **\n");
    printf("**              The Flight Booking System            **\n");
    printf("**                                                   **\n");
    printf("*******************************************************\n");
    printf("\n");
    reset();
}