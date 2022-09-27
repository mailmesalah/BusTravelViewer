#include<conio.h>
#include<stdio.h>
/*
This is the starting point of the program
*/
int main(void) {

    int stop = 0;//stop int variable is initialised to 0 so that the loop following stays in loop as long as stop variable is 0
    
    while(!stop) {//Executes the loop till stop is 1
        switch(menu()) {//menu() function is called to let the user select any of the 7 options given by the function , upon selection it is returned to the switch statement
            case 1:
                item1();// When user selects '1' the average travel time for a selected time period is shown                
                break;//ignores other case statements
            case 2:
                item2();// When user selects number 2, Travel times of each bus services at 5:00 pm and after is calculated and shown
                break;//ignores other case statements
            case 3:
                item3();// up on selecting 3 as option, The time taken to reach home by taking a selected bus at a specific time is shown
                break;//ignores other case statements
            case 4:
                item4(); // On 4 , the shortest travel time from 1 to 6:30 pm for a selected bus is displayed
                break;//ignores other case statements
            case 5:
                item5();// select 5 to show the longest time taken to reach home for a selected bus            
                break;//ignores other case statements
            case 6:  
                item6(); // 6 for Compute and display the bus which has the longest average travel
                break;//ignores other case statements
            case 0:
                stop = 1; //when 0 is selected , it for exiting the loop to stop the program, stop variable is set to 0 which in turn causes to faile the while loop condition to exit the loop
                break;//ignores other case statements
        }
        printf("\n");// next line chareacter is printed to skip a line on console(standard output, ie:-screen)
    }

    return 0; //Zero is return to state the program run successfully, non zero numbers indicate error in program
}
