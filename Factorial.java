//Anuj Pillai
//201952205
//2-D

import java.util.*;
import java.io.*;

public class Factorial {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number :");
        int n = sc.nextInt();
        int ans = FactorialCalc(n);
        System.out.println("It's factorial will be : "+ans);
    }
    public static int FactorialCalc(int no){
       int fact=1;
       for(int i=1;i<=no;i++){
           fact=fact*i;
       }
       return fact;
    }
}