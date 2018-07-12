#include <stdio.h>
#include "shapes.h"

#define N_INTERVALS 4


int main(int argc, char** argv){

	
	struct Interval intervals [N_INTERVALS];
	int n, m, interval_counter;
	
	intervals[0].begin=0.0; 
	intervals[0].end=1.0; 
	interval_counter=1;

	/* iterating over all the intervals */ 
	do {
		
		/* for each interval, we apply the transformation generating a new sub-interval */
		for(n=interval_counter-1;n>=0 && interval_counter<N_INTERVALS; n--) {
			
		
			m=interval_counter;
			
			/* second sub-interval */ 
			intervals[m].begin = intervals[n].begin+2*(intervals[n].end-intervals[n].begin)/3;
			intervals[m].end = intervals[n].end;
    
    		/* first sub-interval */ 
			//intervals[n].a=intervals[n].a; 
			intervals[n].end = intervals[n].begin+(intervals[n].end-intervals[n].begin)/3;
			interval_counter++;
		}

	}while(interval_counter<N_INTERVALS);


	/* print interval bounds to stdout */ 

	//TODO: write bounds to file

	for(n=0; n<interval_counter; n++){

	printf ("%g\t%g\n", intervals[n].begin, intervals[n].end);
	
	}

	return 0; 
}
