#include<stdio.h>

int main(int argc, char const *argv[]){
    // freopen("./data/B_test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", a + i);
    }

    int hillStart = 0;
    int hillRecord = 0;
    int curHillLeft = 0;
    int curHillRight = 0;

    int valeyStart = 0;
    int valeyRecord = 0;
    int curValeyLeft = 0;
    int curValeyRight = 0;

    for(int i = 1; i < n; i++){
        if(a[i - 1] < a[i]){
            if(curHillRight > 0){
                int tmp = curHillLeft < curHillRight ? curHillLeft : curHillRight;
                hillRecord = hillRecord > tmp ? hillRecord : tmp;
                curHillRight = 0;
                curHillLeft = 0;
            }
            curHillLeft++;
            hillStart = 1;
        }
        if(a[i - 1] > a[i]){
            if(hillStart || curHillLeft){
                curHillRight++;
            }
            hillStart = 0;
        }
        if(a[i] == a[i - 1]){
            hillStart = 0;
            curHillRight = 0;
            curHillLeft = 0;
        }
    
        if(a[i - 1] > a[i]){
            if(curValeyRight > 0){
                int tmp = curValeyLeft < curValeyRight ? curValeyLeft : curValeyRight;
                valeyRecord = valeyRecord > tmp ? valeyRecord : tmp;
                curValeyLeft = 0;
                curValeyRight = 0;
            }
            curValeyLeft++;
            valeyStart = 1;
        }
        if(a[i - 1] < a[i]){
            if(valeyStart || curValeyLeft){
                curValeyRight++;
            }
            valeyStart = 0;
        }
    }

    if(curHillRight > 0){
        int tmp = curHillLeft < curHillRight ? curHillLeft : curHillRight;
        hillRecord = hillRecord > tmp ? hillRecord : tmp;
        curHillRight = 0;
        curHillLeft = 0;
    }

    if(curValeyRight > 0){
        int tmp = curValeyLeft < curValeyRight ? curValeyLeft : curValeyRight;
        valeyRecord = valeyRecord > tmp ? valeyRecord : tmp;
        curValeyLeft = 0;
        curValeyRight = 0;
    }

    printf("%d %d\n", hillRecord, valeyRecord);
    return 0;
}
