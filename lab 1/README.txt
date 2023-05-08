ERROR:sortMain2.c dosnt read the last item from argv, otherwise no other errors

1. Suppose you were given an object module (with no access to source code) that sorted an
array of integers very efficiently. However, the sort function in the object module must
be invoked with the following signature:
betterSort(int data[], first, last);
where the array to sort is data and the parameters first and last give the indices of the
portion of the array that is to be sorted.
How could you write a mySort() function with the signature used in this lab that could
exploit the better sorting function in the supplied object module? 

ANSWER:
    If I am understand the question correctly, it is asking if we were to copy the bettersort algorithm into our sort function,
    how would we take advantage of it but with the same signature as our current sort function?

    The variable "nDataItems" in the main function is used to let the sort function know how large the array is. If we assume that
    the "first" value is the beginning of the array, we can set it as the data[0] and the last can be data[nDataItems].