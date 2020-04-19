/**
 * Created by HeYanLe on 2020/4/18 0018.
 * https://github.com/heyanLE
 */

#include "../inc/qgsort.h"
#include <stack>
#include <queue>
#include <iostream>
#include <cstdlib>

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序
 *  @param       : 数组指针 a, 数组长度 n
 */
void InsertSort(int *a,int n){
    for(int i = 0 ; i < n ; i ++){
        for(int j = i ; j > 0 ; j --){
            if(a[j-1] > a[j]){
                int c = a[j-1];
                a[j-1] = a[j];
                a[j] = c;
            }else{
                break;
            }
        }
    }
};

/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp){

    int i = begin;  // 左组指针
    int j = mid +1; // 右组指针
    int k = 0;      // 临时组指针

    while(i <= mid && j <= end){ // 左右组都没到结尾
        if(a[i] <= a[j] ){
            temp[k++] = a[i++];
        }else{
            temp[k++] = a[j++];
        }
    }
    while(i <= mid){ //左组剩余全部加入
        temp[k++] = a[i++];
    }
    while(j <= end){
        temp[k++] = a[j++];
    }
    k = 0; // 将临时组 加入原来数组
    while(begin <= end){
        a[begin++] = temp[k++];
    }

};


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a,int begin,int end,int *temp){
    int mid = (end + begin)/2;
    if(begin < end){
        // 左半排序
        MergeSort(a, begin, mid, temp);
        // 右半排序
        MergeSort(a, mid+1, end, temp);
        // 左右合并
        MergeArray(a ,begin ,mid ,end ,temp);
    }
};

/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int *a, int begin, int end){
    return begin;
};

/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int *a, int begin, int end){

    int i = begin;      // 头指针
    int j = end;        // 尾指针
    int k = a[Partition(a,begin,end)];   // 枢纽

    if(begin >= end){
        return; //出口条件
    }

    while(i != j){ //指针不相遇

        while(j > i && a[j] >= k){ // 尾指针往左找比枢纽小的
            j --;
        }
        if(j > i){ // 如果指针没相遇 将尾指针的数值赋值给头指针
            a[i] = a[j];
        }

        while(j > i && a[i] <= k){ //头指针往右找比枢纽大的
            i++;
        }
        if(j > i){  // 如果指针没相遇 将头指针的数赋值给尾指针
            a[j] = a[i];
        }
    }

    if(i == j){ //指针相遇 将枢纽赋值
        a[i] = k;
    }

    QuickSort_Recursion(a ,begin ,i); // 快排枢纽左边
    QuickSort_Recursion(a ,i+1 ,end); //快排枢纽右边

};

/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int *a,int size){

    std::stack<int> stack ; //   使用栈来实现快速排序尾递归转迭代
    stack.push(size-1);
    stack.push(0);

    while(!stack.empty()){

        /**
         * 获取这次排序迭代的 start 和 end
         */
        int begin = stack.top();
        stack.pop();
        int end = stack.top();
        stack.pop();


        int i = begin;      // 头指针
        int j = end;        // 尾指针
        int k = a[Partition(a,begin,end)];   // 枢纽

        if(i >= j){
            continue;
        }

        while(i != j){ //指针不相遇

            while(j > i && a[j] >= k){ // 尾指针往左找比枢纽小的
                j --;
            }
            if(j > i){ // 如果指针没相遇 将尾指针的数值赋值给头指针
                a[i] = a[j];
            }

            while(j > i && a[i] <= k){ //头指针往右找比枢纽大的
                i++;
            }
            if(j > i){  // 如果指针没相遇 将头指针的数赋值给尾指针
                a[j] = a[i];
            }
        }

        if(i == j){ //指针相遇 将枢纽赋值
            a[i] = k;
        }

        stack.push(i);
        stack.push(begin); // 快排左边


        stack.push(end);
        stack.push(i +1); // 快排右边

    }

};

/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, int size , int max){

    if(max < 0){
        return;
    }
    int *temp = new int[max+1]();
    for(int i = 0 ; i < size ; i ++){
        temp[a[i]] ++;
    }
    for(int i = 0 ; i <= max ; i ++){
        for(int j = 0 ; j < temp[i] ; j ++){
            *a = i;
            a ++;
        }
    }
    delete[](temp);

};

/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size){
    int p0 = 0;
    int p1 = size -1;
    int p = 0;
    int temp = 0 ;
    while(p <= p1){

        switch (a[p]){
            case 0:
                temp = a[p];
                a[p] = a[p0];
                a[p0] = temp;
                p0 ++;
                p ++;
                break;
            case 2:
                temp = a[p];
                a[p] = a[p1];
                a[p1] = temp;
                p1 --;
                break;
            default:
                p ++;
        }

    }
};

/**
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */
int NumberK(int *a ,int size ,int kk){

    if(kk <= 0 || kk > size){
        return -1;
    }

    std::stack<int> stack ; //   使用栈来实现快速排序尾递归转迭代
    stack.push(size-1);
    stack.push(0);

    while(!stack.empty()){

        /**
         * 获取这次排序迭代的 start 和 end
         */
        int begin = stack.top();
        stack.pop();
        int end = stack.top();
        stack.pop();


        int i = begin;      // 头指针
        int j = end;        // 尾指针
        int k = a[i];   // 枢纽

        if(i >= j){
            continue;
        }

        while(i != j){ //指针不相遇

            while(j > i && a[j] >= k){ // 尾指针往左找比枢纽小的
                j --;
            }
            if(j > i){ // 如果指针没相遇 将尾指针的数值赋值给头指针
                a[i] = a[j];
            }

            while(j > i && a[i] <= k){ //头指针往右找比枢纽大的
                i++;
            }
            if(j > i){  // 如果指针没相遇 将头指针的数赋值给尾指针
                a[j] = a[i];
            }
        }

        if(i == j){ //指针相遇 将枢纽赋值
            a[i] = k;
        }

        if(i == kk){
            return a[i];
        }else if(i < kk){
            stack.push(i);
            stack.push(begin); // 快排左边
        }else if(i > kk){
            stack.push(end);
            stack.push(i +1); // 快排右边
        }
    }
    return a[kk-1];
};

/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int *a,int size){

    std::queue<int> queues[10];

    int radix = 10;
    int isWhile = 1;

    while(isWhile){
        isWhile = 0;

        for(int i = 0 ; i < size ; i ++){
            int w = (a[i]%radix - a[i]%(radix/10))/(radix/10);
            queues[w].push(a[i]);
            if(a[i] >= radix){
                isWhile = 1;
            }
        }
        radix *= 10;
        int *p = a;
        for(int i = 0 ; i < 10 ; i ++){
            while(!queues[i].empty()){
                *p = queues[i].front();
                queues[i].pop();
                p ++;
            }
        }

    }


};