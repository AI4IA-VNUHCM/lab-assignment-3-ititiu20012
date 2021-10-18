/*
3.	Input an array of n integers. Find the largest sorted sub array
(sorted array increasing/decreasing and has the largest number of elements)
Ex:
 _____________________________________________
| Input: 2 5 3 4 8 9 7 6 10                   |
| Output: Increasing 3 4 8 9 Decreasing 9 7 6 |
|_____________________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Ex3(int in_arr[], int n){
	//Your codes here
	int max_increase = 1, count_increase = 1, increase_index = 0;
	int max_decrease = 1, count_decrease = 1, decrease_index = 0;
	for(int i = 1; i < n; i++) {
		if(in_arr[i] > in_arr[i-1]) {
			count_increase++;
		} 
		else {
			if(max_increase < count_increase) {
				max_increase = count_increase;
				increase_index = i - max_increase;
			}
			count_increase = 1;
		}
	}
	if(max_increase < count_increase) {
		max_increase = count_increase;
		increase_index = n - max_increase;
	}
	for(int j = 1; j < n; j++) {
		if(in_arr[j] < in_arr[j-1]) {
			count_decrease++;
		}
		else {
			if(max_decrease < count_decrease) {
				max_decrease = count_decrease;
				decrease_index = j - max_decrease;
			}
			count_decrease = 1;
		}
	}
	if(max_decrease < count_decrease) {
		max_decrease = count_decrease;
		decrease_index = n - max_decrease;
	}
	printf("Increasing ");
	for(int i = increase_index; i < max_increase + increase_index; i++) {
		printf("%d ", in_arr[i]);
	}
	printf("Decreasing ");
	for(int j = decrease_index; j < max_decrease + decrease_index; j++) {
		printf("%d ", in_arr[j]);
	}
}

int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	argc--;
	int testcase[argc],i;
	for(i=0; i<argc;i++){
		testcase[i] = atoi(argv[i+1]);
	}
	
	Ex3(testcase, argc);
	
	return 0;
}