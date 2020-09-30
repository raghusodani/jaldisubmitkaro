//Anuj Pillai
//201952205
//2-D

import java.util.*;
import java.io.*;

public class CountPrime {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter two numbers a and b (b>a) :");
        int a = sc.nextInt();
        int b = sc.nextInt();
        System.out.println("Prime numbers between these two numbers are : ");
        for(int i=a+1;i<b;i++){
            int count=0;
            for(int j=2;j<=i/2;j++){
                if(i%j==0){
                    count++;
                }
            }
            if(count==0){
                System.out.println(i+" ");
            }
        }   
    }    
}