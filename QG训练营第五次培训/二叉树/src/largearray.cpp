/**
 * Created by HeYanLe on 2020/4/18 0018.
 * https://github.com/heyanLE
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sys/timeb.h>
#include "../inc/qgsort.h"
#include "../inc/largearray.h"

long long getTimeStamp(){
    timeb t{};
    ftime(&t);
    return t.time * 1000 + t.millitm;
}

long long testInsertSort(int *a ,int length){
    long long  time_11 = getTimeStamp();
    InsertSort(a ,length);
    long long  time_12 = getTimeStamp();
    return time_12 -time_11;
}

long long testMergeSort(int *a ,int length){
    int *temp = new int[length];
    long long  time_11 = getTimeStamp();
    MergeSort(a ,0 ,length-1 ,temp);
    long long  time_12 = getTimeStamp();
    delete[](temp);
    return time_12 -time_11;
}

long long testQuickSort_Recursion(int *a ,int length){
    long long  time_11 = getTimeStamp();
    QuickSort_Recursion(a ,0 ,length-1);
    long long  time_12 = getTimeStamp();
    return time_12 -time_11;
}

long long testQuickSort(int *a ,int length){
    long long  time_11 = getTimeStamp();
    QuickSort(a ,length);
    long long  time_12 = getTimeStamp();
    return time_12 -time_11;
}

long long  testCountSort(int *a ,int length){
    long long  time_11 = getTimeStamp();
    int max = 0;
    for(int i = 0 ; i < length ; i ++){
        if(a[i] >= max){
            max = a[i];
        }
    }
    CountSort(a ,length ,max);
    long long  time_12 = getTimeStamp();
    return time_12 -time_11;
}

long long  testRadixCountSort(int *a ,int length){
    long long  time_11 = getTimeStamp();
    RadixCountSort(a ,length);
    long long  time_12 = getTimeStamp();
    return time_12 -time_11;
}

void testLargeArray(){
    std:: cout << "Sorting ..." << std::endl;
    int m_time = getTimeStamp();
    std::srand(m_time);
    int *a = new int[200000] ;
    for(int i = 0 ; i < 200000 ; i ++){
        a[i] = rand();
        //std:: cout << a[i] << std::endl;
    }


    int *a1 = new int[200000] ;
    memcpy(a1,a,20000*sizeof(int));

    int *a2= new int[200000] ;
    memcpy(a2,a,20000*sizeof(int));

    int *a3= new int[200000] ;
    memcpy(a3,a,20000*sizeof(int));

    int *a4= new int[200000] ;
    memcpy(a4,a,20000*sizeof(int));

    int *a5= new int[200000];
    memcpy(a5,a,20000*sizeof(int));

    int *a6= new int[200000];
    memcpy(a6,a,20000*sizeof(int));

    // 1w
    long long  insert1 = testInsertSort(a1 ,10000);
    long long  merge1 = testMergeSort(a2 ,1000);
    long long  quickR1 = testQuickSort_Recursion(a3 ,1000);
    long long  quick1 = testQuickSort(a4 ,1000);
    long long  count1 = testCountSort(a5 ,10000);
    long long  countR1 = testRadixCountSort(a6 ,10000);

    // 5w
    long long  insert2 = testInsertSort(a1 ,50000);
    long long  merge2 = testMergeSort(a2 ,5000);
    long long  quickR2 = testQuickSort_Recursion(a3 ,5000);
    long long  quick2 = testQuickSort(a4 ,5000);
    long long  count2 = testCountSort(a5 ,50000);
    long long  countR2 = testRadixCountSort(a6 ,50000);

    // 20w
    long long  insert3 = testInsertSort(a1 ,200000);
    long long  merge3 = testMergeSort(a2 ,20000);
    long long  quickR3 = testQuickSort_Recursion(a3 ,20000);
    long long  quick3 = testQuickSort(a4 ,20000);
    long long  count3 = testCountSort(a5 ,200000);
    long long  countR3 = testRadixCountSort(a6 ,200000);

    system("cls");
    std:: cout << std::endl << "========= Result =========" << std::endl
        << ">>>>> size of 10000 <<<<<<<" << std::endl
        << "Insert Sort :" << insert1  << "ms" << std::endl
        << "Merge Sort :" << merge1  << "ms" << std::endl
        << "Quick Sort Recursion :" << quickR1 << "ms" << std::endl
        << "Quick Sort :" << quick1  << "ms" << std::endl
        << "Count Sort :" << count1  << "ms" << std::endl
        << "Radix Count Sort :" << countR1  << "ms" << std::endl;

    std:: cout << std::endl << ">>>>> size of 50000 <<<<<<<" << std::endl
               << "Insert Sort :" << insert2  << "ms" << std::endl
               << "Merge Sort :" << merge2  << "ms" << std::endl
               << "Quick Sort Recursion :" << quickR2 << "ms" << std::endl
               << "Quick Sort :" << quick2  << "ms" << std::endl
               << "Count Sort :" << count2  << "ms" << std::endl
               << "Radix Count Sort :" << countR2  << "ms" << std::endl;

    std:: cout<< std::endl << ">>>>> size of 200000 <<<<<<<" << std::endl
               << "Insert Sort :" << insert3  << "ms" << std::endl
               << "Merge Sort :" << merge3  << "ms" << std::endl
               << "Quick Sort Recursion :" << quickR3 << "ms" << std::endl
               << "Quick Sort :" << quick3  << "ms" << std::endl
               << "Count Sort :" << count3  << "ms" << std::endl
               << "Radix Count Sort :" << countR3  << "ms" << std::endl;

    delete[](a);
    delete[](a1);
    delete[](a2);
    delete[](a3);
    delete[](a4);
    delete[](a5);
    delete[](a6);
    system("pause");

}

