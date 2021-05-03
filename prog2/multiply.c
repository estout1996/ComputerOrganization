/* Elizabeth Stout
 * CPSC 2310 Project 2
 * Due July 21, 2020 
 * 
 * This program multiplies two 8-bit numbers and emulates a hardware multiplication 
 */

#include <stdio.h>
#include "multiply.h"

/*
prints character passed in to itsbinary equivalent
 value - the character to convert and print
*/
void printBinary(unsigned char value) {

    int i;

    for (i = 7; i >= 0; i--)
    {
        printf("%u", (value >> i) & 1);
    }
}

void printSeperation(){
    printf("---------------------------------------------------\n");
}

void printEqualsLine(){
    printf("          ----------\n");
}

int main() {
    Registers regs;
    int mpd;
    int mpq;

    printf("multiplicand: ");
    scanf("%32d", &mpd); // Limit input to 32 characters

    //check for invalid input
    if (mpd > 255 || mpd < 0) 
    { 
        fprintf(stderr, "Invalid number, must be in range [0, 255]\n");
        return(-1);
    }
    regs.mdr = (unsigned char) mpd; // Cast to unsigned char

    printf("multiplier: ");
    scanf("%32d", &mpq);

    //check for invalid input
    if (mpq > 255 || mpq < 0) 
    { 
        fprintf(stderr, "Invalid number, must be in range [0, 255]\n");
        return(-1);
    }
    regs.mq = (unsigned char) mpq;

    regs.c = 0;
    regs.acc = 0;
    printf("\nc and acc set to 0\n");
    printf("%-24s=%4u decimal and ", "mq set to multiplier", regs.mq);
    printBinary(regs.mq);
    printf(" binary\n");
    printf("%-24s=%4u decimal and ", "mdr set to multiplicand", regs.mdr);
    printBinary(regs.mdr);
    printf(" binary\n");

    int i;
    unsigned char msb;

    // Loop through the 8 steps
    for (i = 1; i <= 8; i++) 
    { 
        printSeperation();
        printf("step %d:   %u ", i, regs.c);
        printBinary(regs.acc);
        printf(" ");
        printBinary(regs.mq);
        printf("\n");
        printf("        +   ");

         // If the lsb=1, add mdr and acc
        if (regs.mq % 2 == 1) 
        {
            printBinary(regs.mdr);
            printf("        ^ add based on lsb=1\n");

            //take care of overflow
            if ((int) regs.mdr + (int) regs.acc > 255) 
            { 
                regs.c = !regs.c; // If there is an overflow
            }

            regs.acc = (unsigned char)((int)regs.mdr + (int)regs.acc); // Cast to int, then back to unsigned char to truncate any overflow
        } 

        // don't add because lsb=0
        else 
        { 
            printf("00000000        ^ no add based on lsb=0\n");
        }

        printEqualsLine();
        printf("%11u ", regs.c);
        printBinary(regs.acc);
        printf(" ");
        printBinary(regs.mq);
        printf("\n");
        printf("       >>                     shift right\n");
        
        regs.c = (regs.c << 7); // shift to be added to accumulator
        msb = regs.acc % 2; // Get lsb of accumulator
        msb = (msb << 7); // shift to be added to mq 
        regs.acc = (regs.acc >> 1);
        regs.acc += regs.c;
        regs.c = 0; // Reset carry
        regs.mq = (regs.mq >> 1);
        regs.mq += msb;
        
        printf("%11u ", regs.c);
        printBinary(regs.acc);
        printf(" ");
        printBinary(regs.mq);
        printf("\n");
    }

    printSeperation();
    printf("check:                 binary   decimal\n");
    printf("                     ");
    printBinary((unsigned char) mpd);
    printf("%10d\n", mpd);
    printf("           x         ");
    printBinary((unsigned char) mpq);
    printf("  x    ");
    printf("%3d\n", mpq);
    printf("             ----------------    ------\n");
    printf("             %u", regs.c);
    printBinary(regs.acc);
    printBinary(regs.mq);
    printf("     %5d\n", mpd * mpq);
}