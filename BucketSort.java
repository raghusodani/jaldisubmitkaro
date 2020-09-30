package com.anujpillai;

import java.util.*;

public class BucketSort {
//    public static void main(String[] args) {
//        int[] intArr = {47, 85, 10, 45, 16, 34, 67, 80, 34, 4, 0, 99};
//        System.out.println("Original array- " + Arrays.toString(intArr));
//        bucketSort(intArr, 10);
//        System.out.println("Sorted array after bucket sort- " + Arrays.toString(intArr));
//    }
    static void bucketSort(int[] intArr, int noOfBuckets){
        List<Integer>[] buckets = new List[noOfBuckets];
        for(int i = 0; i < noOfBuckets; i++){
            buckets[i] = new LinkedList<>();
        }
        for(int num : intArr){
            buckets[hash(num)].add(num);
        }
        for(List<Integer> bucket : buckets){
            Collections.sort(bucket);
        }
        int i = 0;
        for(List<Integer> bucket : buckets){
            for(int num : bucket){
                intArr[i++] = num;
            }
        }
    }
    static int hash(int num){
        return num/10;
    }

}
