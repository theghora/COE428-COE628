#include "mySort.h"

void mySort(int array[], unsigned int first, unsigned int last)
    {

      for (int j = 1+first; j<=last; j++){   //used professors slides
        int key;
        myCopy(&array[j],&key);
        
        int i =j-1;
        
        while (i>=0  && myCompare(array[i],key)>0){   //put mycompare and copy in
          myCopy(&array[i],&array[i+1]);
          i--;
        }
        myCopy(&key,&array[i+1]);
      }                           
    }
