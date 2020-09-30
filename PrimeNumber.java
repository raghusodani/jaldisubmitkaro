//Anuj Pillai
//201952205
//2-D
import java.util.*;
import java.io.*;
public class PrimeNumber {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number :");
        int n = sc.nextInt();
        boolean ans = isPrime(n);
        if(ans==true){
        System.out.println("It is non prime.");
        }
        else{
            System.out.println("It is prime.");
        }
    }
    public static boolean isPrime(int n){
        int count=0;
        for(int i=2;i<=n/2;i++){
            if(n%i==0){
                count++;
            }
        }
        if(count>0){
            return true;
        }
        else{
            return false;
        }
    }
}
