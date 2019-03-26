#include <unistd.h>
#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]){
	
	
	int my_rank,size;
	int sum;
	
	MPI_Init(&argc, &argv);
	//MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	// qdd code for barrier
	
	
	MPI_Barrier(MPI_COMM_WORLD);
	 
	
	printf("I received %d from %d \n",sum, my_rank);
	
	MPI_Finalize();

}
