#include <unistd.h>
#include <stdio.h>
#include <mpi.h>

#define SIZE 9

#define UP    0
#define DOWN  1
#define LEFT  2
#define RIGHT 3

void create_cartesian_grid(int nb_tasks, MPI_Comm cartesian_comm, int my_rank, int  coords[], int dims[],int periods[], int reorder, int neighbors[]     ){
	
}

int main(int argc, char *argv[]){
	
	
	int my_rank,nb_tasks;
	
	int dims[2] = {3,3}; // nb of processes in each dimension of the grid
	int periods[2] = {0,0};
	int reorder = 0;
	int coords[2];
	int neighbors[4];
	int remains[2];
	
	MPI_Comm rows_comm;
	MPI_Comm cols_comm; 
	remains[0]= 0;
	remains[1]= 1;
	
	MPI_Comm cartesian_comm; //communicator with new cartesian topology (handle) 
	
	
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &nb_tasks);
	
	//create_cartesian_grid(nb_tasks, cartesian_comm, my_rank, coords, dims, periods, reorder, neighbors);
	if( nb_tasks == SIZE ){
	
		MPI_Cart_create(MPI_COMM_WORLD,2,dims,periods,reorder,&cartesian_comm);
		MPI_Comm_rank(cartesian_comm, &my_rank);
		MPI_Cart_coords(cartesian_comm, my_rank, 2, coords); // in the vect coords we'll get the coordinates of the specified process
		
		MPI_Cart_shift(cartesian_comm, 0, 1, &neighbors[UP], &neighbors[DOWN]);
		MPI_Cart_shift(cartesian_comm, 1, 1, &neighbors[LEFT], &neighbors[RIGHT]);
		
		printf("rank= %d coords= %d %d  neighbors(u,d,l,r)= %d %d %d %d\n",
             my_rank,coords[0],coords[1],neighbors[UP],neighbors[DOWN],neighbors[LEFT],neighbors[RIGHT]);
	}
	// communicator per row
	MPI_Cart_sub(cartesian_comm, remains, &rows_comm );
	int new_rank;
	
	MPI_Comm_rank(rows_comm, &new_rank);
	//printf("partition per row \n");
	printf("old rank = %d and new rank row= %d \n",my_rank, new_rank);
	
	// communicator per column
	remains[0]= 1;
	remains[1]= 0;
	MPI_Cart_sub(cartesian_comm, remains, &cols_comm );
	//int new_rank;
	
	MPI_Comm_rank(cols_comm, &new_rank);
	//printf("partition per column \n");
	printf("old rank = %d and new rank col= %d \n",my_rank, new_rank);
	
	MPI_Finalize();

}
