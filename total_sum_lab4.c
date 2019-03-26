#include <unistd.h>
#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]){
	
	
	int my_rank,size;
	int sum;
	
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	
	//first_version
	
	//MPI_Reduce(&my_rank, &sum,1, MPI_INT, MPI_SUM,	0, MPI_COMM_WORLD);
	
	//MPI_Bcast(&sum, 1, MPI_INT, 0, MPI_COMM_WORLD);
	
	//printf("I received %d from %d \n",sum, my_rank);
	
	//second version
	
	MPI_Allreduce(&my_rank, &sum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
	
	printf("I received %d from %d \n",sum, my_rank);
	
	MPI_Finalize();

}
