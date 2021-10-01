package Lab;

import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class heapsort { 
    public void sort(int arr[]) 
    { 
        int n = arr.length; 
  
        // Build heap (rearrange array) 
        for (int i = n / 2 - 1; i >= 0; i--) 
            heapify(arr, n, i); 
  
        // One by one extract an element from heap 
        for (int i=n-1; i>=0; i--) 
        { 
            // Move current root to end 
            int temp = arr[0]; 
            arr[0] = arr[i]; 
            arr[i] = temp; 
  
            // call max heapify on the reduced heap 
            heapify(arr, i, 0); 
        } 
    } 
  
    // To heapify a subtree rooted with node i which is 
    // an index in arr[]. n is size of heap 
    void heapify(int arr[], int n, int i) 
    { 
        int largest = i;  // Initialize largest as root 
        int l = 2*i + 1;  // left = 2*i + 1 
        int r = 2*i + 2;  // right = 2*i + 2 
  
        // If left child is larger than root 
        if (l < n && arr[l] > arr[largest]) 
            largest = l; 
  
        // If right child is larger than largest so far 
        if (r < n && arr[r] > arr[largest]) 
            largest = r; 
  
        // If largest is not root 
        if (largest != i) 
        { 
            int swap = arr[i]; 
            arr[i] = arr[largest]; 
            arr[largest] = swap; 
  
            // Recursively heapify the affected sub-tree 
            heapify(arr, n, largest); 
        } 
    } 
    void call(int[] a) {
    	heapsort ob=new heapsort();
    	int T[]=new int[a.length];
    	for(int i=0;i<a.length;i++)
    		T[i]=a[i];
    	
    	long start=System.nanoTime();
    	ob.sort(T);
    	long end=System.nanoTime();
    	System.out.println(end-start);
    }
  
    /* A utility function to print array of size n */
    static void printArray(int arr[]) 
    { 
        int n = arr.length; 
        for (int i=0; i<n; ++i) 
            System.out.print(arr[i]+" "); 
        System.out.println(); 
    } 
  
    // Driver program 
    public static void main(String args[]) 
    { 
    	Random rand=new Random();
		Scanner s=new Scanner(System.in);
		heapsort ob=new heapsort();
		System.out.println("ENTER THE LENGTH OF ARRAYS");
		
		int l=s.nextInt();
		
		
		
		int a[]=new int[l];
		int b[]=new int[l];
		int c[]=new int[l];
		
		
		//random array c
		for(int i=0;i<a.length;i++) {
			c[i]=rand.nextInt();
		}
		for(int i=0;i<c.length;i++) {
			c[i]=a[i];
		}
		
		
		
		//sorted array a
		Arrays.sort(a);
		
		//reverse sorted array b
		for(int i=0;i<a.length;i++) {
			b[i]=a[a.length-i-1];
		}
		System.out.println("time takem by reverse sorted array B");
		ob.call(b);
		System.out.println("time takem by random arrar array C");
		ob.call(c);
		System.out.println("time takem by sorted array A");
		ob.call(a);
    } 
} 