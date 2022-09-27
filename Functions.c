#include<stdio.h>
#include<conio.h>

//Definition
extern int busStopTime[];
extern int Bus8Transit[];
extern int Bus15Transit[];
extern int Bus23Transit[];
//End

/*
Shows the menu for selecting from the 7 options
*/
int menu() {
    
    int chosen;// chosen variable is declaired for alocating memory for the variable

    do {// do while loops for providing the menu in loop
		//printed to the screen as written in the printf() function
        printf("Menu\n");
        printf(" 1. The average travel time for a selected time period\n");
        printf(" 2. Travel times of each bus services at 5:00 pm and after\n");
        printf(" 3. The time taken to reach home by taking a selected bus at a specific time\n");
        printf(" 4. Display the shortest travel time from 1 to 6:30 pm for a selected bus\n");
        printf(" 5. Display the longest time taken to reach home for a selected bus\n");
        printf(" 6. Compute and display the bus which has the longest average travel\n");
        printf(" 0. Exit\n");
        printf("Choose one option: ");
        scanf("%d", &chosen);//Program waits for user input

        if (chosen<0 || chosen>6) {// if the choice given is below 0 or above 6 it is considered as invalid and displayed the invalid message
            printf("\nInvalid choice. Please try again\n\n");            
        }
        printf("\n");
    }
    while(chosen<0 || chosen>6);// if invalid choice is given by user then this loop will execute again to show the menu listng again. This continues until a valid choice is given by user
    return chosen;// the chosen value is returned upon successful selection of choice listed
}

/*
Converts the user given time value to index. The arrays like busStopTime[],Bus8Transit[],Bus15Transit[] and Bus23Transit[] uses this index to find the correct value at right time
*/
int selectTime() { 
    float t=0.0;// floating point value to store user given time

    do {        
        scanf("%f", &t); //user given time is a floating point value which is read using '%f'.        
		//here the user given floating value is converted to integer as index. 
        if (t==1.00f)
            return 0; //return keyword return the function value, here it return 0 int value
        if (t==1.30f)
            return 1;
        if (t==2.00f)
            return 2;
        if (t==2.30f)
            return 3;
        if (t==3.00f)
            return 4;
        if (t==3.30f)
            return 5;
        if (t==4.00f)
            return 6;
        if (t==4.30f)
            return 7;
        if (t==5.00f)
            return 8;
        if (t==5.30f)
            return 9;
        if (t==6.00f)
            return 10;
        if (t==6.30f)
            return 11;
        printf("Invalid time. Please enter again\n");// if none of the if statement is executed then it is invalid time given by user for this program
    }
    while(1);// this do while will execute as long as there is no valid time given. If valid time is given any of the return value is called and breaks the loop
}

//This function lets the user select any of the three buses
int selectBus() {
    int b;// int variable b is declaired to store the selected choice by user

    do {
        printf("Select bus (8, 15 or 23): ");
        scanf("%d", &b); // user is supposed to provide 8 or 15 or 23 as choice, which indicates the bus
        if (b==8 || b==15 || b==23)           // if choice value is desired value, it is returned back to the called function
            return b;

        printf("Invalid bus. Please enter again\n");// wanting message on wrong selection
    }
    while(1);// loops till the user gives a valid data.
}

/*
It shows The average travel time for a selected time period
*/
void item1() {    
//variable declaration part
    int i;//i int variable is declaired for using as index variable in loop
	printf("Select start time from 1.00 to 6.30: ");
    int startTime = selectTime();// start time is selected by user
	printf("Select end time from 1.00 to 6.30: ");
    int endTime = selectTime();// end time is selected by user

    if (startTime <= endTime) {// if the values given are valid, thats is starttime is less than or equalt to end time, then its valid
	//initialises the variables for keeping average each bus times, with zero
        int average8tt = 0;
        int average15tt = 0;
        int average23tt = 0;
        for(i=startTime; i<=endTime; i++) {// iterated through the array starting from start time till end time
            average8tt += (busStopTime[i] + Bus8Transit[i]);// for bus 8 the bustop time is added to bus 8 transit time and added to the previous value in the variable
            average15tt += (busStopTime[i] + Bus15Transit[i]);//for bus 15 the bustop time is added to bus 15 transit time and added to the previous value in the variable
            average23tt += (busStopTime[i] + Bus23Transit[i]);//for bus 23 the bustop time is added to bus 23 transit time and added to the previous value in the variable
        }
        average8tt /= (endTime - startTime + 1);// total sum of the bustop time and bus 8 transit time between the selected start and end time devided with the number of stops to get the average
        average15tt /= (endTime - startTime + 1);// total sum of the bustop time and bus 15 transit time between the selected start and end time devided with the number of stops to get the average
        average23tt /= (endTime - startTime + 1);// total sum of the bustop time and bus 23 transit time between the selected start and end time devided with the number of stops to get the average

        
        printf("\nAverage time: %d\n", (average8tt + average15tt + average23tt) / 3); // summ of avaerage time period values of each bus is added and divided with three to get the total average and its printed
    }
    printf("\n");
}

/*
Prints each bus total time at bus stop time 5:00, 5:30, 6:00 and 6:30
*/
void item2() {
	
    printf("\n");
    printf("Travel time for bus 8 at 5.00: %d\n", (busStopTime[8] + Bus8Transit[8]));
    printf("Travel time for bus 8 at 5.30: %d\n", (busStopTime[9] + Bus8Transit[9]));
    printf("Travel time for bus 8 at 6.00: %d\n", (busStopTime[10] + Bus8Transit[10]));
    printf("Travel time for bus 8 at 6.30: %d\n", (busStopTime[11] + Bus8Transit[11]));

    printf("Travel time for bus 15 at 5.00: %d\n", (busStopTime[8] + Bus15Transit[8]));
    printf("Travel time for bus 15 at 5.30: %d\n", (busStopTime[9] + Bus15Transit[9]));
    printf("Travel time for bus 15 at 6.00: %d\n", (busStopTime[10] + Bus15Transit[10]));
    printf("Travel time for bus 15 at 6.30: %d\n", (busStopTime[11] + Bus15Transit[11]));

    printf("Travel time for bus 23 at 5.00: %d\n", (busStopTime[8] + Bus23Transit[8]));
    printf("Travel time for bus 23 at 5.30: %d\n", (busStopTime[9] + Bus23Transit[9]));
    printf("Travel time for bus 23 at 6.00: %d\n", (busStopTime[10] + Bus23Transit[10]));
    printf("Travel time for bus 23 at 6.30: %d\n", (busStopTime[11] + Bus23Transit[11]));
}

void item3() {
	printf("Select time from 1.00 to 6.30: ");
    int selectedTime = selectTime();//selected a time by user
    int selectedBus = selectBus();// selects a bus by user

    int takenTime = 0;// initialises the time taken
    switch(selectedBus) {
        case 8:
            takenTime = busStopTime[selectedTime] + Bus8Transit[selectedTime]; // calculates the totoal time of transit of bus 8 at the selected time
            break;
        case 15:
            takenTime = busStopTime[selectedTime] + Bus15Transit[selectedTime]; // calculates the totoal time of transit of bus 15 at the selected time
            break;
        case 23:
            takenTime = busStopTime[selectedTime] + Bus23Transit[selectedTime];// calculates the totoal time of transit of bus 23 at the selected time
            break;
    }

    printf("\nTaken time: %d\n", takenTime); // time taken is printed
}

/*
Finds the shortest travel time in the selected bus
*/
void item4() {
    int i; // used for iteration in loop

    int selectedBus = selectBus(); // lets the user select  bus

    int shortestTravelTime = 9999999; // sets a maximum value as initial value for comparing

    for(i=0; i<12; i++) {// iterated through 12 indices of the array
        int travelTime = 0;// initialises the time for particular time
        switch(selectedBus) {
            case 8:
                travelTime = busStopTime[i] + Bus8Transit[i]; // gets the total time for that particular index  for bus 8
                break;
            case 15:
                travelTime = busStopTime[i] + Bus15Transit[i];// gets the total time for that particular index  for bus 15
                break;
            case 23:
                travelTime = busStopTime[i] + Bus23Transit[i];// gets the total time for that particular index  for bus 23
                break;
        }
        if (shortestTravelTime>travelTime || i==0)// first value or after that if current calculated value is less the the shortestTravelTime is swaped with transitTime
            shortestTravelTime = travelTime;
    }

    printf("\nShortest travel time: %d\n", shortestTravelTime);// shortestTravelTime is printed
}
	
/*
Finds the longest time taken for transit time
*/	
void item5() {    
    int i;
    int longestTime = 0;// initialises to 0
    int stopTime = 0;// initialises to 0
    int selectedBus = selectBus();    //  let the user select the bus number

    for(i=0; i<12; i++) { // iterates through 12 indices
        int transitTime = 0;// initialises to 0 for current iteration
        switch(selectedBus) {
            case 8:
                transitTime = Bus8Transit[i]; // current transit time for bus 8 is copied
                break;
            case 15:
                transitTime = Bus15Transit[i];// current transit time for bus 15 is copied
                break;
            case 23:
                transitTime = Bus23Transit[i];// current transit time for bus 23 is copied
                break;
        }
        if (longestTime < transitTime) {// if current value is bigger than previasly biggest value , then swap the values
            longestTime = transitTime;
            stopTime = busStopTime[i];// if longest time is selected it stop tim also selected
        }
    }

    printf("\nLongest time taken to reach home: %d\n", longestTime); // longest time is printed
    printf("Time of travel: %d\n", longestTime + stopTime); // total time taken is printed

}

/*
Finding the longest average time in the three buses
*/
void item6() {
	//initialises variables to 0
    int sumBus8 = 0;
    int sumBus15 = 0;
    int sumBus23 = 0;
    int i;

    for(i=0; i<12; i++) {// iterates through the 12 array values
        sumBus8 += Bus8Transit[i] + busStopTime[i]; // total sum of stop time and bus transit for bus 8 is stored in sumBus8
        sumBus15 += Bus15Transit[i] + busStopTime[i];// total sum of stop time and bus transit for bus 15 is stored in sumBus15
        sumBus23 += Bus23Transit[i] + busStopTime[i];// total sum of stop time and bus transit for bus 23 is stored in sumBus23
    }

    if (sumBus8 > sumBus15 && sumBus8 > sumBus23) {// if total value of bus 8 is lasger its average is printed
        printf("\nBus 8 has longest average travel time: %d\n", (sumBus8 / 12)); //average is found by diving total with 12 and its printed
        return;
    }
    if (sumBus15 > sumBus8 && sumBus15 > sumBus23) {// if total value of bus 15 is lasger its average is printed
        printf("\nBus 15 has longest average travel time: %d\n" , (sumBus15 / 12));//average is found by diving total with 12 and its printed
        return;
    }
    if (sumBus23 > sumBus8 && sumBus23 > sumBus15) {// if total value of bus 23 is lasger its average is printed
        printf("\nBus 23 has longest average travel time: %d\n" , (sumBus23 / 12));//average is found by diving total with 12 and its printed
        return;
    }

    printf("\nSome buses have same longest average travel time\n\n"); // if any of two busses or more have same values this part is executed and printed
}
