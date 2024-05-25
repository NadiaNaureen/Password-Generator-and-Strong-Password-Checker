#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 100
int size =-1;
int l;
char arr[40400][40400];
int i=0;
int j=0;
void print_combinations(char *str, int start, int end) {
  if (start == end) {
    
    for(int k=i;k<=i;k++){
        for(int g=0;g<l;g++){
            arr[k][g]=str[g];
        }
    }
    i=i+1;
    j=j+1;
    return;
  }
  for (int i = start; i < end; i++) {
    // Swap the characters at positions start and i.
    char temp = str[start];
    str[start] = str[i];
    str[i] = temp;

    // Print all combinations of the string starting from position start + 1.
    print_combinations(str, start + 1, end);

    // Swap the characters back to their original positions.
    temp = str[start];
    str[start] = str[i];
    str[i] = temp;
  }
  
}
void randomPass(){
    int num=rand() % i + 1;
    for(int p=0;p<l;p++){
        printf("%c",arr[num][p]);
    }
    
}
void PasswdGeneration(){ //function for password generation

  int n,m,p,q,i;
  char password[N];
  char small[]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  char caps[]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K','L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  int num[]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  char spl[]={'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '+', '-', '.', '~', '|', '<', '>', '=', '-', '_', '/', ':', ';', '?', '[', ']', '{', '}', '~'};
  printf("enter the size of the password");
  scanf("%d",&l);
  printf("enter the no of upper case letters");
  scanf("%d",&n);
  printf("enter the no of lower case letters");
  scanf("%d",&m);
  printf("enter the no of no");
  scanf("%d",&p);
  printf("enter the no of spl charcters");
  scanf("%d",&q);
  if(n+m+p+q==l)
  {
  for(i=0;i<n;i++){
      int random_index = rand()%26;
      password[++size] = small[random_index]; //generation of random capital alphabets

  }
  for(i=0;i<m;i++){
      int random_index = rand()%26;
      password[++size] = caps[random_index];  //generation of random small alphabets

  }
  for(i=0;i<p;i++){
      int random_index = rand()%10;
      password[++size] = num[random_index]; //generation of random numbers
      
  }
   for(i=0;i<q;i++){
      int random_index = rand()%29;
      password[++size] = spl[random_index]; //generation of random spl characters
      
  }
  //for(i=0;i<=size;i++){
  //    printf("%c",password[i]); //printing the final password
  //}
  }
  else{
      printf("Size of characters exceede the length of tha password");
  }
  /*for(i=0;i<size;i++){
      
  }*/
   print_combinations(password, 0, l);
   randomPass();

}

void Strength(){  //function to check the strength of the entered password
    bool isSubstring(char *string, char *username, char *dob, char *name) {  //function to check if the personal details matches with the password
    if (strstr(string, username) != NULL || strstr(string, dob) != NULL || strstr(string, name) != NULL)  
        return true;
    else
        return false;
}
    char string[100];
    char username[100];
    char dob[20];
    char name[20];
    int length, has_uppercase, has_lowercase, has_digit, has_special;
    //getting personal infomation from the user
    printf("Enter a password: "); 
    scanf("%s", string);
    printf("Enter a username: ");
    scanf("%s", username);
    printf("Enter dob: ");
    scanf("%s", dob);
    printf("Enter name: ");
    scanf("%s", name);
   
    has_uppercase = has_lowercase = has_digit = has_special = 0;
    length = strlen(string);
     //checking if the password has all kinds of characters 
     //using for loop to iterate through the string
    for (int i = 0; i < length; ++i) {
        if (isupper(string[i]))
            has_uppercase = 1;
        else if (islower(string[i]))
            has_lowercase = 1;
        else if (isdigit(string[i]))
            has_digit = 1;
        else
            has_special = 1;
    }
    //checking if it meets the certain conditions to be a strong password
    //if not prints the prompt message 
    if (isSubstring(string, username, dob, name) || length < 8 || !has_uppercase || !has_lowercase || !has_digit || !has_special) {
        printf("Your password is Weak\n");
        if (length < 8) {
            printf("The length of your password is less than 8 characters.\n");
        }
        if (!has_uppercase) {
            printf("Include uppercase in your password.\n");
        }
        if (!has_lowercase) {
            printf("Include lowercase in your password.\n");
        }
        if (!has_digit) {
            printf("Include numbers in your password.\n");
        }
        if (!has_special) {
            printf("Include special characters in your password.\n");
        }
        if (isSubstring(string, username, dob, name)) {
            printf("Your password should not include your personal info.\n");
        }
    } else {
        printf("Your password is Strong\n");
    }
}
void timetocrack()
{
    int tim=0;
    char string[100];
    int length, has_uppercase, has_lowercase, has_digit, has_special;
    //getting personal infomation from the user
    printf("Enter a password: "); 
    scanf("%s", string);
    has_uppercase = has_lowercase = has_digit = has_special = 0;
    length = strlen(string);
    // Function to calculate combinations of a password
long long calculateCombinations(char string[], int length) {
    long long combinations = 1;
    // Assuming each character in the password is distinct
    // So, the number of combinations is simply length
    for (int i = 1; i <= length; i++) {
        combinations *= i;
    }
return combinations;
}

// Function to calculate time taken to crack a password
double timeToCrack(long long combinations, int length) {
    // Assuming one combination takes 1 millisecond to try
    // You can adjust this according to your system's capabilities
    double tim = (double)combinations / length;

    return tim;
}
//checking if the password has all kinds of characters 
     //using for loop to iterate through the string
    for (int i = 0; i < length; ++i) {
        if (isupper(string[i]))
            has_uppercase = 1;
        else if (islower(string[i]))
            has_lowercase = 1;
        else if (isdigit(string[i]))
            has_digit = 1;
        else
            has_special = 1;
    }

    //checking if it meets the certain conditions to be a strong password
    //if not prints the prompt message 
    if (length < 8 || !has_uppercase || !has_lowercase || !has_digit || !has_special) {
        tim=tim+1;
        if (length > 8) {
            tim=tim+8;
        }
        if (has_uppercase) {
            tim=tim+10;
        }
        if (has_lowercase) {
            tim=tim+10;
        }
        if (has_digit) {
            tim=tim+10;
        }
        if (has_special) {
            tim=tim+15;
        }
        
    } 
    printf("The time taken to crack your password is :%d seconds!",tim);
    
}
int main()
{
    int choice;
    printf("********************************");
    printf("PASSWORD GENERATION AND CHECKER");
    printf("********************************");
    while(1){
    printf("\n\n\tMENU\t");
    printf("\n1.Password generation\n2.Password checker\n3.Time taken to crack your password\n");
    printf("Choose operation to be performed: ");  
    scanf("%d", &choice);
    //using switch case to perform various functions 
    switch(choice){
        case 1:
        PasswdGeneration();
        break;
        case 2:
        Strength();
        break;
        case 3:
        timetocrack();
        break;
        case 4:
        exit(0);
        default:
        printf("invalid choice");
    }
    }
}

