#include "mySort.h"
void myMerge(int array[], unsigned int first, unsigned int mid,
             unsigned int last) {

  int size1 = (mid + 1) - first; // first half of array
  int size2 = last - mid;        // second half of array


  int left[size1], right[size2]; // declares first and second half temp arrays

  for (int i = 0; i < size1; i++) {
    myCopy(&array[i + first], &left[i]);
    // left[i] = array[first + i];
  } // copies first half of array elements

  for (int i = 0; i < size2; i++) {
    myCopy(&array[i + 1 + mid], &right[i]);
    // right[i] = array[mid + i + 1];
  } // copies second half of array elements

  int i1 = 0, i2 = 0, a = first;
  while (i2 < size2 && i1 < size1) {
    if (myCompare(right[i2], left[i1]) <= 0) { // left[i1] <= right[i2]
      myCopy(&right[i2], &array[a]);
      // array[a] = right[i2];
      i2++;

    } else {
      myCopy(&left[i1], &array[a]);
      // array[a] = left[i1];
      i1++;
    }
    a++;
  }
  while (i1 < size1 || i2 < size2) {
    if (i1 < size1) {
      myCopy(&left[i1], &array[a]);
      // array[a] = left[i1];
      i1++;
      a++;
    }
    if (i2 < size2) {
      myCopy(&right[i2], &array[a]);
      // array[a] = right[i2];
      i2++;
      a++;
    }
  }
}

void mySort(int array[], unsigned int first, unsigned int last) {
  // continually cuts array in half and then merges them all together

  if (first < last) {
    int mid = (first + (last - 1)) / 2;

    mySort(array, first, mid);
    mySort(array, mid + 1, last);
    myMerge(array, first, mid, last);
  }
}