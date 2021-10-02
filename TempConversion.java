//Anuj Pillai
//201952205
//2-D

import java.util.*;
import java.io.*;

public class TempConversion {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter temperature in farenheit : ");
        float f = sc.nextFloat();
        double c=(f-32)/1.8;
        System.out.printf("Temperatue in celsius will be : %.2f",c);

    }
}