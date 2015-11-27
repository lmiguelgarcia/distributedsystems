#include <stdio.h>
#include <mpi.h>

//Modifique el código del archivo mpiExample7.c de modo que se envie a todos los nodos en el comunicador
//MPI_COMM_WORLD la suma calculada en el nodo raiz de este comunicador

int main(int argc, char *argv[]){
    int i,rank,size;
    int root,count;
    int buffer[5];
    MPI_Status status;
    MPI_Request request;

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    root=0;
    count=5;
    if(rank== root){
      for(i=0;i<count;i++){
        buffer[i]=i;
      }
    }


    MPI_Bcast(buffer, count, MPI_INT, root, MPI_COMM_WORLD);
    printf("Rank is: %d, Value at buffer[%d] is: %d\n \n ",rank, count-1, buffer[count-1]);

    MPI_Finalize();
    return 0;
}