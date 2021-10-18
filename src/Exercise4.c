/*
4. Write a function to check whether a given array is sorted or not.
Return 1 if sorted increasing, -1: decreasing, 0: not sorted
Ex:
______________________________________
| Input: 8 7 9 2 1 5 2               |
| Output: 0                          |
|____________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Ex4(int arr[], int n){
	//Your codes here
	int increase = 1, decrease = 1, i = 0;
	while((increase == 1 || decrease == 1) && (i < n-1)) {
		if(arr[i] < arr[i+1]) {
			decrease = 0;
		}
		else if(arr[i] > arr[i+1]) {
			increase = 0;
		}
		++i;
	}
	if(increase == 1) {
		return 1;
	}
	else if(decrease == 1) {
		return -1;
	}
	else {
		return 0;
	}
}

int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	argc--;
	int testcase[argc],i;
	for(i=0; i<argc;i++){
		testcase[i] = atoi(argv[i+1]);
	}
	
	printf("%d", Ex4(testcase, argc));

	return 0;
}