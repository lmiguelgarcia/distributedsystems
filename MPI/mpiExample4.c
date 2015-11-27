#include <stdio.h>
#include "mpi.h"

int main(int argc,char *argv[]){
	int i, sum, sTotal, upToVal;
	int start, end, size, rank;
	long int pTotal;

	upToVal = 1000;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	start = rank*(upToVal/size) + 1;
    	if(rank==(size-1)){
    	  
    	  end = upToVal;
    	  
    	}else{
    	
    		end = start + (upToVal/size)-1;
    		
    	}
    	
    	sum = 0;
    	sTotal=0;
	    pTotal=0;
	    
    	for(i=start; i<= end; i++){
    		sum = sum +i;
    	}
    	
	MPI_Reduce(&sum, &sumTotal, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	MPI_Reduce(&sum, &prodTotal, 1, MPI_LONG, MPI_PROD, size-1, MPI_COMM_WORLD);
  printf("\nRank: %d, sum: %d, sumTotal: %d, prodTotal: %ld, start: %d, end: %d\n", rank, sum, sTotal, pTotal, start, end);

	MPI_Finalize();

	return 0;
}
