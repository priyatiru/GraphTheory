/*
-------------------------------------------------------------------------------
@author: Akshay Jain
Problem: Fractional Knapsack Problem
-------------------------------------------------------------------------------
*/

# include<stdio.h>
void merge(float arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(float arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void knapsack(int n, float w[], float v[], float W) {
      int curWeight = 0;
      double finalvalue = 0.0;


      for (int i = 0; i < n; i++)
      {
          if (curWeight + w[i] <= W)
          {
              printf("%f\t",w[i]);
              printf("%f\n",v[i]);
              curWeight += w[i];
              finalvalue += v[i];
          }

          else
          {
              int remain = W - curWeight;
              printf("%f\t",w[i]);
              printf("%f\n",v[i]);
              finalvalue += v[i] * ((double) remain / w[i]);
              break;
          }
      }

   printf("\nMaximum profit is:- %lf\n", finalvalue);

}

int main() {
   float weight[20], profit[20], capacity;
   int num, i, j;
   float ratio[20], temp;

   printf("\nEnter the no. of objects:- ");
   scanf("%d", &num);

   printf("\nEnter the wts and profits of each object:- ");
   for (i = 0; i < num; i++) {
      scanf("%f %f", &w[i], &profit[i]);
   }

   printf("\nEnter the capacityacity of knapsack:- ");
   scanf("%f", &capacity);

   for (i = 0; i < num; i++) {
      ratio[i] = profit[i] / weight[i];
   }

   mergeSort(ratio, 0, num - 1);
   mergeSort(weight, 0, num - 1);
   mergeSort(profit, 0, num - 1);

   knapsack(num, weight, profit, capacity);
   return(0);
}
