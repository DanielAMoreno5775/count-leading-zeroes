/**Primary Author: Daniel Moreno
 * 
 * Contains functions main, displayMenu, getUserChoice, evaluateUserChoice, getUnsignedInt
 * Will print out the menu of options, get the user's choice, get the user's input, and pass that input to each operation
*/


#include "major1.h"
#define infinite for(;;)

int main(){
    //variable definitions and initializations
    char userChoice;
    uint32_t a, b;
    int result;

    //loop until the user enters 5 to exit
    do {
        a = 1;
        b = 1;
        result = 1;
        //get user's choice
        userChoice = evaluateUserChoice();
        //select option based on user's choice
        //Choice: Count Leading Zeroes
        if (userChoice == '1') {
            a = getUnsignedInt("Enter a 32-bit number (>= 1 and <= 4294967295, inclusively): ", 1, UINT_MAX);
            result = countLeadingZeroes(a);
            printf("The number of leading zeroes in %u is %d\n", a, result);
        }
        //Choice: Endian Swap
        else if (userChoice == '2') {
            printf("Endian swap operation by other group member\n");
        }
        //Choice: Rotate-right
        else if (userChoice == '3') {
            printf("Rotate right operation by other group member\n");
        }
        //Choice: Parity
        else if (userChoice == '4') {
            printf("Parity operation by other group member\n");
        }
    } while (userChoice != '5');
    
    printf("Program terminating. Goodbye...\n");

    return 0;
}



//functions below this point
//print menu
void displayMenu() {
    printf("Enter the menu option for the operation to perform:\n");
    printf("   (1) Count Leading Zeroes\n");
    printf("   (2) Endian Swap\n");
    printf("   (3) Rotate-right\n");
    printf("   (4) Parity\n");
    printf("   (5) EXIT\n");
}

//read in the user's input
//output only 1 character
char getUserChoice() {
    //variable definitions and initializations
    char buffer[(sizeof(int)*3 + 3)*2];

    //print menu to console
    displayMenu();

    //prompt user
    printf("--> ");
    //store input in buffer while preventing array overflows
    if (fgets(buffer, sizeof buffer, stdin) == NULL) {
        return 'a';
    }

    //flushes the input buffer so that extra characters aren't automatically inputted in next loop
    fflush(stdin);   
    //fixes strange edge-case where getUnsignedInt will be called twice if the menu input is too long
    if(!strchr(buffer, '\n'))        //will trigger the loop if a newline character does not exist
        while(fgetc(stdin)!='\n');   //discard input until newline

    //return inputted character
    return buffer[0];
}

//determine whether user's input is a valid option
//if it is valid, return it
//if it isn't valid, loop and ask for new input
char evaluateUserChoice() {
    //variable definitions and initializations
    char userInput = 'a';

    //get initial user choice
    userInput = getUserChoice();
    //loop until valid choice
    while (userInput != '1' && userInput != '2' && userInput != '3' && userInput != '4' && userInput != '5') {
        //print error message
        printf("\nError: Invalid option. Please try again.\n");
        //call function again to get new input before looping to check new input
        userInput = getUserChoice();
    }

    return userInput;
}

//get an unsigned 32-bit integer from the user in the range of [min,max] with bounds checking
//uses special uint32_t data type to prevent issues due to different OSes assigning different amounts of bits to ints
uint32_t getUnsignedInt(char *prompt, unsigned long min, unsigned long max) {
    //variable definitions and initializations
    uint32_t destinationValue = 0;

    //infinite loop until the function returns using a defined macro constant
    infinite {
        //create massive input buffer to prevent issues
        //resets with each loop iteration
        char buf[(sizeof(int)*3 + 3)*2];

        //prompt user
        printf("%s", prompt);
        //store input in buffer while preventing array overflows
        if (fgets(buf, sizeof buf, stdin) == NULL) {
            return min;
        }
        //append a null terminator to prevent issues
        char ch = '\0';
        strncat(buf, &ch, 1);
        //determine memory address of buffer's end
        char *endptr;
        //set up error checker
        errno = 0;
        //convert buffer into unsigned long long
        //data type is excessive to prevent issues before bounds checking has occurred
        unsigned long long tempLong = strtoll(buf, &endptr, 10);
        //ensure conversion occurred and that there isn't any strange stuff at the end
        if (buf == endptr || *endptr != '\n') {
            continue;
        }
        //check whether error occurred and perform bounds checking
        if (!errno && tempLong >= min  && tempLong <= max) {
            //cast long to unsigned int
            destinationValue = (uint32_t) tempLong;
	        //flushes the input buffer so that extra characters aren't automatically inputted in next loop
    	    fflush(stdin);   
            if(!strchr(buf, '\n'))           //will trigger the loop if a newline character does not exist
                while(fgetc(stdin)!='\n');   //discard input until newline
            //return value and exit function
            return destinationValue;
        }
    }
} 