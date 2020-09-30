#include<iostream>
#include<string>>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n= numberMonth("December");
    cout<<n;
	return 0;
}
	int numberMonth(string m){
        string monthArray[12] = {"January","February","March","April","May",
                        "June","July","August","September","October","November","December"};
        for(int i=0;i<12;i++){
            if(m == monthArray[i]){
                return (i+1);
            }
        }
    }
