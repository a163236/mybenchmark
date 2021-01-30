#include "dataset1.h"

extern int _pallc(int tid, int func); 
extern int _publk(int tid); 
extern int _pblk(int tid); 
extern int _pdall(int tid);
extern void _thread0();
extern void _thread1();

int success_publk;
int success_pblk;
int success_pdall;
int j;  // loop index
int D,E,F;
void thread0(){
  for (j = 0; j < DATA_SIZE/2; j++)
  {
    //results[j] = input_data[j];
    D = input_data[j-1];
    E = input_data[j];
    F = input_data[j+1];

    if ( D < E ) {
      if ( E < F )
        results[j] = E;
      else if ( F < D )
        results[j] = D;
      else
        results[j] = F;
    }

    else {
      if ( D < F )
        results[j] = D;
      else if ( F < E )
        results[j] = E;
      else
        results[j] = F;
    }
  }
}

int i;
int A,B,C;
void thread1(){
  for (i = DATA_SIZE/2; i < DATA_SIZE; i++)
  {
    //results[i] = input_data[i];
    A = input_data[i-1];
    B = input_data[i];
    C = input_data[i+1];

    if ( A < B ) {
      if ( B < C )
        results[i] = B;
      else if ( C < A )
        results[i] = A;
      else
        results[i] = C;
    }

    else {
      if ( A < C )
        results[i] = A;
      else if ( C < B )
        results[i] = B;
      else
        results[i] = C;
    }
  }
  
  // スレッド0の再開
  int success_publk = 0;
  while (!success_publk)
  {
    success_publk = _publk(0);
  }
  // スレッド1の終了
  success_pdall = 0;
  while (!success_pdall)
  {
    success_pdall = _pdall(1);
  }
} 

// check関数
static int verify()
{
  int i;
  // Unrolled for faster verification
  for (i = 0; i < DATA_SIZE/2*2; i+=2)
  {
    int t0 = results[i], t1 = results[i+1];
    int v0 = verify_data[i], v1 = verify_data[i+1];
    if (t0 != v0) return 8000+i;
    if (t1 != v1) return 8000+i+1;
  }
  if (DATA_SIZE % 2 != 0 && results[DATA_SIZE-1] != verify_data[DATA_SIZE-1])
    return 888;
  return 777;
}

int main(void){
  _pallc(1, thread1);

  _publk(1);

  thread0();

  _pblk(0);

  //verify();
  //int a = 76000+input_data[25];
  
  //int b = 77000+verify_data[25];
  return 99000+results[25];
}