import java.util.*;
import java.lang.*;
import java.io.*;

public class RotateArray {
    public static int[] leftrotatebyone(int ar[]){
        int temp = ar[0];
        for(int i=0;i<ar.length-1;i++){
            ar[i]=ar[i+1];
            ar[i+1] = temp;
            temp=ar[i+1];
        }
        return ar;
    }
    public static void main(String[] args){
       Scanner sc = new Scanner(System.in);
       int  t = sc.nextInt();
       while(t-->0){
           int n = sc.nextInt();
           int d = sc.nextInt();
           int[] ar = new int[n];
           for(int i=0;i<n;i++){
               ar[i] = sc.nextInt();
           }
           int[] a = new int[d];
           int[] a1 = new int[n-d];
           int[] a2 = new int[n];
           for(int i=0;i<d;i++){
               a[i] = ar[i];
           }
           for( int i=d;i<n;i++){
               a1[i-d] = ar[i];
           }
           System.arraycopy(a1, 0, a2, 0, a1.length);
           System.arraycopy(a, 0, a2, a1.length, a.length);
           System.out.println(Arrays.toString(a2));
       }
    }
}
