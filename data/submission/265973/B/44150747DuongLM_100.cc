<<<<<<< Updated upstream
#include<stdio.h>

int check(int x, int y, int x0, int y0, int d){
    int deltaX = x - x0;
    if(deltaX < 0){
        deltaX = -deltaX;
    }
    int deltaY = y - y0;
    if(deltaY < 0){
        deltaY = -deltaY;
    }

    int delta = deltaX > deltaY ? deltaX : deltaY;
    return delta <= d;
}

int main(int argc, char const *argv[]){
    // freopen("./data/B_test.txt", "r", stdin);
    int d, n;
    scanf("%d%d", &d, &n);

    int x[n], y[n], c[n];
    for(int i = 0; i < n; i++){
        scanf("%d%d%d", x + i, y + i, c + i);
    }

    int arr[101][101];
    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 101; j++){
            arr[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        int minX0, maxX0, minY0, maxY0;
        minX0 = x[i] - d;
        minX0 = minX0 > 0 ? minX0 : 1;
        maxX0 = x[i] + d;
        maxX0 = maxX0 <= 100 ? maxX0 : 100;

        minY0 = y[i] - d;
        minY0 = minY0 > 0 ? minY0 : 1;
        maxY0 = y[i] + d;
        maxY0 = maxY0 <= 100 ? maxY0 : 100;

        // printf("%d %d\n", minY0, maxY0);
        for(int x0 = minX0; x0 <= maxX0; x0++){
            for(int y0 = minY0; y0 <= maxY0; y0++){//printf("%d %d\n", x0, y0);
                if(check(x[i], y[i], x0, y0, d)){
                    arr[x0][y0] += c[i];
                }
            }
        }
    }

    int result = arr[1][1];
    int minX = 1, minY = 1;
    for(int i = 1; i < 101; i++){
        for(int j = 1; j < 101; j++){
            if(result < arr[i][j]){
                minX = i;
                minY = j;
                result = arr[i][j];
            }
        }
    }

    // for(int i = 1; i < 7; i++){
    //     for(int j = 1; j < 7; j++){
    //         printf("%d ", arr[i][j]);
    //     }printf("\n");
    // }

    printf("%d %d %d\n", minX, minY, result);
    return 0;
}
=======
#include<stdio.h>

int check(int x, int y, int x0, int y0, int d){
    int deltaX = x - x0;
    if(deltaX < 0){
        deltaX = -deltaX;
    }
    int deltaY = y - y0;
    if(deltaY < 0){
        deltaY = -deltaY;
    }

    int delta = deltaX > deltaY ? deltaX : deltaY;
    return delta <= d;
}

int main(int argc, char const *argv[]){
    // freopen("./data/B_test.txt", "r", stdin);
    int d, n;
    scanf("%d%d", &d, &n);

    int x[n], y[n], c[n];
    for(int i = 0; i < n; i++){
        scanf("%d%d%d", x + i, y + i, c + i);
    }

    int arr[101][101];
    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 101; j++){
            arr[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        int minX0, maxX0, minY0, maxY0;
        minX0 = x[i] - d;
        minX0 = minX0 > 0 ? minX0 : 1;
        maxX0 = x[i] + d;
        maxX0 = maxX0 <= 100 ? maxX0 : 100;

        minY0 = y[i] - d;
        minY0 = minY0 > 0 ? minY0 : 1;
        maxY0 = y[i] + d;
        maxY0 = maxY0 <= 100 ? maxY0 : 100;

        // printf("%d %d\n", minY0, maxY0);
        for(int x0 = minX0; x0 <= maxX0; x0++){
            for(int y0 = minY0; y0 <= maxY0; y0++){//printf("%d %d\n", x0, y0);
                if(check(x[i], y[i], x0, y0, d)){
                    arr[x0][y0] += c[i];
                }
            }
        }
    }

    int result = arr[1][1];
    int minX = 1, minY = 1;
    for(int i = 1; i < 101; i++){
        for(int j = 1; j < 101; j++){
            if(result < arr[i][j]){
                minX = i;
                minY = j;
                result = arr[i][j];
            }
        }
    }

    // for(int i = 1; i < 7; i++){
    //     for(int j = 1; j < 7; j++){
    //         printf("%d ", arr[i][j]);
    //     }printf("\n");
    // }

    printf("%d %d %d\n", minX, minY, result);
    return 0;
}
>>>>>>> Stashed changes
