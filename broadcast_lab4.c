#include <unistd.h>
#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]){
	
	
	int my_rank,size;
	int a[10];
	
	MPI_Init(&argc, &argv);
	
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	if(my_rank == 0){
		for(int i = 0 ; i < 10 ; i++){
			a[i] = i;
			}
		}
	
	MPI_Bcast(&a, 10, MPI_INT, 0, MPI_COMM_WORLD);
	
	printf("I received %d from %d \n",a[1], my_rank);
	
	MPI_Finalize();

}
