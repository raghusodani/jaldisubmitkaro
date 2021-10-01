import java.util.*;
import java.lang.*;
public class fizzBuzz {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] a = new String[n];
        for(int i=1;i<=n;i++){
            if(i%3==0){
                if(i%5==0){
                    a[i-1]="FizzBuzz";
                }
                else{
                    a[i-1]="Fizz";
                }
            }
            else if(i%5==0){
                a[i-1]="Buzz";
            }
            else{
                a[i-1]=Integer.toString(i);
            }
        }
        for(int i=0;i<n;i++){
            System.out.println(a[i]);
        }
    }
}