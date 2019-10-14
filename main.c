#include <stdlib.h>
#include <sys/time.h>
#include "yael/vector.h"
#include "yael/nn.h"

double elapsed (){
    struct timeval tv;
    gettimeofday (&tv, NULL);
    return  tv.tv_sec + tv.tv_usec * 1e-6;
}

float * pq_load_vec(char* dataset_dir, int d, int n){
	float* vector = (float*) malloc(sizeof(float)*d*n);

	fvecs_read (dataset_dir, d, n, vector);

	return vector;
}

int main(int argv,char **argc) {

  double t0 = elapsed();

  int nb = 10000;
  int nq = 100;
  int k= 100;
  int d = 128;

  float *database;
  float *queries;
  int *ids = (int*) malloc(nq * k * sizeof(int));
  float *dis = (float*) malloc(nq * k * sizeof(float));

  printf ("[%.3f s] Lendo vetores\n", elapsed() - t0);

  database = pq_load_vec("/home/andre/Downloads/siftsmall/siftsmall_base.fvecs", d, nb);
  queries = pq_load_vec("/home/andre/Downloads/siftsmall/siftsmall_query.fvecs", d, nq);

  printf ("[%.3f s] Iniciou knn\n", elapsed() - t0);

  knn_full (2, nq, nb, d, k, database, queries, NULL, ids, dis);

  printf ("[%.3f s] terminou knn\n", elapsed() - t0);

  // for(int i = 0; i < nq; i++){
  //   printf("\nQUERY %d\n", i);
  //   for(int j = 0; j < k; j++){
  //     printf("ids %d, dis %.4f\n", ids[i*k+j], dis[i*k+j]);
  //   }
  // }

  free(ids);
  free(dis);
  free(database);
  free(queries);

  return 0; 
}
