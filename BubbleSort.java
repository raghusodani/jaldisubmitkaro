import java.util.*;

public class BubbleSort{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the array : ");
        int n = sc.nextInt();
        int ar[] = new int[n];
        System.out.println("Enter the array : ");
        for(int i=0;i<ar.length;i++){
            ar[i]=sc.nextInt();
        }
        int temp;
        for(int i=0;i<ar.length;i++){
            for(int j=1;j<ar.length-i;j++){
                if(ar[j-1] > ar[j]){   
                    temp = ar[j-1];  
                    ar[j-1] = ar[j];  
                    ar[j] = temp;  
                    }
            }
        }

        for(int i=0;i<ar.length;i++){
            System.out.printf(ar[i]+" ");
        }
        
    }
}