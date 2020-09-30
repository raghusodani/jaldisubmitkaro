import java.util.*;

class Radix
{
    void radixSort(int A[], int n)
    {
        int r = A[0];
        for(int i = 1; i < n; ++i)
        {
            if(A[i] > r)
            {
                r = A[i];
            }
        }
        for(int base = 1; r / base > 0; base *= 10)
        {
            countingSort(A, n, base);
        }
    }

    void countingSort(int[] A, int n, int base)
    {
        int B[] = new int[n];
        int C[] = new int[]{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        
        for(int i = 0; i < n; ++i)
        {
            C[(A[i] / base) % 10] += 1;
        }
        for(int i = 1; i < 10; ++i)
        {
            C[i] += C[i - 1]; 
        }
        for(int i = n - 1; i >= 0; --i)
        {
            B[C[(A[i] / base) % 10] - 1] = A[i];
            C[(A[i] / base) % 10] -= 1;
        }
        for(int i = 0; i < n; ++i)
        {
            A[i] = B[i];
        }
    }
}

class RadixSort
{
    public static void main(String[] args)
    {
        //851.968 1769.472 2752.512 3670.016 4,456.448
        Radix obj = new Radix();
        Random rand = new Random();
        int n = 10000;
        int A[] = new int[n];
        for(int i = 0; i < n; ++i)
        {
            A[i] = rand.nextInt(100);
        }
        obj.radixSort(A, n);
        for(int i = 0; i < n; ++i)
        {
            System.out.printf("%d ", A[i]);
        }
        System.out.println();
    }
}