void mySort(int d[], unsigned int n)
{
    int a;
    for (int j = 0; j < n; j++){
        for (int i = 0; i < n; i++){
            if (d[j]<d[i]){
                a = d[j];
                d[j] = d[i];
                d[i] = a;
            }
        }
    }
}

