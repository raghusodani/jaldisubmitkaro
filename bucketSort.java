
package Lab;

import java.util.*;

public class bucketSort {
	   static void bucketSort1(float arr[], int n) 
	    { 
	        if(n <= 0) 
	            return; 
	      
	        
	        @SuppressWarnings("unchecked") 
	        ArrayList<Float>[] b = new ArrayList[n];  
	      
	        for(int i = 0; i < n; i++) 
	        { 
	            b[i] = new ArrayList<Float>(); 
	        } 
	          
	        
	        for(int i = 0; i < n; i++) 
	        { 
	            int idx = (int)arr[i]*n; 
	            b[idx].add(arr[i]); 
	        } 
	      
	       
	        for(int i = 0; i < n; i++) 
	        { 
	            Collections.sort(b[i]); 
	        } 
	      
	          
	        int index = 0; 
	        for(int i = 0; i < n; i++) 
	        { 
	            for(int j = 0; j < b[i].size(); j++) 
	            { 
	                arr[index++] = b[i].get(j); 
	            } 
	        } 
	    }  
	   static void callBucket(float[] a){
	    	  
    	   
    	   
    	   long start=System.nanoTime();
    	   bucketSort1(a,a.length);
    	   long end=System.nanoTime();
    	   System.out.println("Time taken is: " +(end-start)/1000);
 
       }
  public static void main(String args[]) {
	  Random rand=new Random();
		Scanner s=new Scanner(System.in);
		System.out.println("ENTER THE LENGTH OF ARRAYS");
		int l=s.nextInt();
		
		
		
		
		
		
		 
		
		
		float a[]=new float[l];
		float[] b=new float[l];
		float c[]=new float[l];
		
		
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
		callBucket(b);
		callBucket(c);
		callBucket(a);
  }
}
