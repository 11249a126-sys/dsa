#include <stdio.h>

int main() {
    int n, capacity;
    scanf("%d", &n);

    int weight[n];
    for(int i=0;i<n;i++) scanf("%d",&weight[i]);

    scanf("%d", &capacity);

    int bin[n], bins = 0;

    for(int i=0;i<n;i++) {
        int best = -1;
        for(int j=0;j<bins;j++) {
            if(bin[j] + weight[i] <= capacity) {
                if(best==-1 || (capacity-bin[j]) > (capacity-bin[best]))
                    best = j;
            }
        }
        if(best==-1)
            bin[bins++] = weight[i];
        else
            bin[best] += weight[i];
    }

    printf("Bins used: %d", bins);
}
