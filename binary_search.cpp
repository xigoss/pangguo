#include<stdio.h>
#include <iostream>
using namespace std;                            


int binary_search(int array[],int n,int value)
{
    //write your code here
    int begin, mid, end;
    begin = 0;
    end = n-1;
    while(begin <= end){
        mid = (begin + end)/2;
        if(array[mid] == value){
            break;
        }else{
            if(array[mid] > value){
                end = mid-1;
            }else{
                begin = mid+1;
            }
        }
    }
    while(mid > 0){
        if(array[mid] == array[mid-1]){
            mid--;
        }else{
            break;
        }
    }
    return mid;
}


//start ��ʾ���Զ��ľ���ʼΨһ��ʶ������ɾ�������ӡ�
int main()
{    
    //write your code here
    int array[10] = {1,2,5,5,6,7,7,10,12,15};
    int n = binary_search(array, 10, 5);
    cout<<"5�������е��±�Ϊ"<<n<<endl;
    return 0;
}