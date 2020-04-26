/**
 * Created by HeYanLe on 2020/4/18 0018.
 * https://github.com/heyanLE
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sys/timeb.h>
#include "../inc/qgsort.h"
#include "../inc/smallarray.h"

long long small_getTimeStamp(){
    timeb t{};
    ftime(&t);
    return t.time * 1000 + t.millitm;
}

long long testInsertSort(int *a ){
    long long  time_11 = small_getTimeStamp();
    for(int i = 0 ; i < 100000 ; i ++){
        InsertSort(a+(i*100) ,100);
    }
    long long  time_12 = small_getTimeStamp();
    return time_12 -time_11;

};

long long testMergeSort(int *a ){
    long long  time_11 = small_getTimeStamp();
    int *temp = new int[100];
    for(int i = 0 ; i < 100000 ; i ++){
        MergeSort(a,i*100 ,i*100+100 ,temp);
    }
    long long  time_12 = small_getTimeStamp();
    delete[](temp);
    return time_12 -time_11;
};

long long testQuickSort_Recursion(int *a ){
    long long  time_11 = small_getTimeStamp();
    for(int i = 0 ; i < 100000 ; i ++){
        QuickSort_Recursion(a,i*100 ,i*100+100);
    }
    long long  time_12 = small_getTimeStamp();
    return time_12 -time_11;
};

long long testQuickSort(int *a ){
    long long  time_11 = small_getTimeStamp();
    for(int i = 0 ; i < 100000 ; i ++){
        QuickSort(a+(i*100) ,100);
    }
    long long  time_12 = small_getTimeStamp();
    return time_12 -time_11;
};

long long  testCountSort(int *a ){
    long long  time_11 = small_getTimeStamp();
    for(int i = 0 ; i < 100000 ; i ++){

        int max = 0;
        for(int j = (i*100) ; j < (i*100) +100 ; j ++){
            if(a[j] >= max){
                max = a[j];
            }
        }
        CountSort(a+(i*100) ,100 ,max);
    }
    long long  time_12 = small_getTimeStamp();
    return time_12 -time_11;
};

long long  testRadixCountSort(int *a ){
    long long  time_11 = small_getTimeStamp();
    for(int i = 0 ; i < 100000 ; i ++){
        RadixCountSort(a+(i*100) ,100 );
    }
    long long  time_12 = small_getTimeStamp();
    return time_12 -time_11;
};

void testSmallArray(){

    std:: cout << "Sorting ..." << std::endl;
    int m_time = small_getTimeStamp();
    std::srand(m_time);
    int *a = new int[10000000] ;
    for(int i = 0 ; i < 10000000 ; i ++){
        a[i] = rand();
    }


    int *a1 = new int[10000000] ;
    memcpy(a1,a,10000000*sizeof(int));

    int *a2= new int[10000000] ;
    memcpy(a2,a,10000000*sizeof(int));

    int *a3= new int[10000000] ;
    memcpy(a3,a,10000000*sizeof(int));

    int *a4= new int[10000000] ;
    memcpy(a4,a,10000000*sizeof(int));

    int *a5= new int[10000000];
    memcpy(a5,a,10000000*sizeof(int));

    int *a6= new int[10000000];
    memcpy(a6,a,10000000*sizeof(int));

    long long  insert1 = testInsertSort(a1);
    long long  merge1 = testMergeSort(a2 );
    long long  quickR1 = testQuickSort_Recursion(a3 );
    long long  quick1 = testQuickSort(a4 );
    long long  count1 = testCountSort(a5 );
    long long  countR1 = testRadixCountSort(a6 );

    system("cls");
    std:: cout << std::endl << "========= Result =========" << std::endl
                << ">>>>> 100000 * size of 100 <<<<<<<" << std::endl
               << "Insert Sort :" << insert1  << "ms" << std::endl
               << "Merge Sort :" << merge1  << "ms" << std::endl
               << "Quick Sort Recursion :" << quickR1 << "ms" << std::endl
               << "Quick Sort :" << quick1  << "ms" << std::endl
               << "Count Sort :" << count1  << "ms" << std::endl
               << "Radix Count Sort :" << countR1  << "ms" << std::endl;

    delete[](a);
    delete[](a1);
    delete[](a2);
    delete[](a3);
    delete[](a4);
    delete[](a5);
    delete[](a6);
    system("pause");

};

