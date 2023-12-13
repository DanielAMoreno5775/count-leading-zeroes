/**Primary Author: Daniel Moreno
 * 
 * Contains function countLeadingZeroes
 * Will determine leading zeroes in binary form of passed integer
*/

#include "major1.h"

/**Takes one input then uses bitwise operations
 * to return the number of leading zeroes in the binary form of that input
 * @param uint32 num: the number to be evaluated; a 32-bit, unsigned integer
 * @return int: the number of leading zeroes; an int from 0 to 31
*/
int countLeadingZeroes (uint32_t num) {
    //variable definitions and initializations
    int binaryNum[32] = {0};
    int index = 0;
    int counter = 0;

    //obtain binary version of the unsigned, 32-bit integer
    //assume initial value of 31 as integer as 32 bits
    for (int i = 31; i >= 0; i--) {
        //initialize temporary variable as result of right-shifting the int by the value of i
        int temp = num >> i;

        //store result of bitwise AND operator and increment the index
        binaryNum[index] = (temp & 1);
        index++;
    }

    //increment through the array storing the new binary number
    for (int i = 0; i < 32; i++) {
        //temporarily store current character
        char current = binaryNum[i];
        //if the character is a 1, stop counting leading zeroes and return the current count
        if (current == 1) {
            return counter;
        }
        //otherwise, keep counting
        else {
            counter++;
        }
    }

    //if the program is functioning properly, this return statement will never be reached
    //if it is reached, it will return a -1 to indicate an error with the if statement within the for loop
    return -1; 
}