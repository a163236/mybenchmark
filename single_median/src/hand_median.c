// See LICENSE for license details.
// riscv-tests/benchmark/median
//**************************************************************************
// Median filter bencmark
//--------------------------------------------------------------------------
//
// This benchmark performs a 1D three element median filter. The
// input data (and reference data) should be generated using the
// median_gendata.pl perl script and dumped to a file named
// dataset1.h.


//--------------------------------------------------------------------------
// Input/Reference Data

#include "dataset1.h"


int i;
int A,B,C;
void thread1(){
  for (i = 0; i < DATA_SIZE; i++)
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
}
//--------------------------------------------------------------------------
// Main

int main()
{
  
  // Do the filter
  thread1();
  

  // Check the results
  return 99000+results[100];
  //return verify( DATA_SIZE, results_data, verify_data );
}
