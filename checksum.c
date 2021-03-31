/********************************/
/* Program Name: Checksum Ver. C*/
/* Author: Adrian Gonzalez III  */
/* Date: 2-12-21                */
/********************************/

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

#define max_int (255)
#define byte unsigned char

int main(int argc, char* argv[], char** envp) {

    int quotient, remainder;

    int count = 10;
    int sum = 0;
    int checksumID = 6;
    int temp;
    byte checksum; //byte
    byte complement;
    byte header[10];
    int reval = 0;

    /* the following is the prototype for the read system call */
    reval = read(STDIN_FILENO, &header, 10);

    // start of copy pasta
    for (int i = 0; i < count; i++) {
        //scanf("%d", &temp);
        //header[i] = (byte) temp;
        //fprintf(stdout, "header[%d]: %d \n", i, header[i]);    TESTING IN THE SERVER WORKED WOOOOOOOO
        if (i == checksumID - 1) {
            checksum = header[i];
            header[i] = 0;
        }

        //if (nums[i] > max_int) {
        //    printf("ERROR : NUMBER INPUT TOO LARGE!\n");
        //    exit(1);
        //}

        sum += header[i];

        quotient = sum / (max_int + 1);
        remainder = sum % (max_int + 1);
        sum = quotient + remainder;
        //fprintf(stdout, "Sum at %d: %d \n", i, sum);


    }

    complement = max_int - sum;
    // end of copy pasta

    fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);
    if (checksum != complement) {
        fprintf(stderr, "Error Detected!\n");
        return 1;
    }
    return 0;
}