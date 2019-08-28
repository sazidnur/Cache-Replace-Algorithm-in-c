#include <stdio.h>
#include <limits.h>
#define MAX 100005

int n, ar[MAX], cap, q[MAX], fault, hit, time[MAX];

void lru(){
	int i, pos=1, flag, cnt=1;
	for(i=1; i<=cap; i++) q[i]=-1;
	while(pos<=n){
		flag=0;
		for(i=1; i<=cap; i++){
			if(q[i]==-1){
				q[i]=ar[pos];
				time[i]=pos;
				flag=1;
				break;
			}
		}
		if(flag==1){
			pos++;
			fault++;
			continue;
		}
		for(i=1; i<=cap; i++){
            if(q[i]==ar[pos]){
                flag=1;
                time[i]=pos;
                break;
            }
		}
		if(flag==1){
            hit++;
            pos++;
            continue;
		}
		int mn=INT_MAX, min_pos;
        for(i=1; i<=cap; i++){
            if(time[i]<mn){
                mn=time[i];
                min_pos=i;
            }
        }
        q[min_pos]=ar[pos];
        time[min_pos]=pos;
        fault++;
        pos++;
	}
}
int main(void) {
	int i;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &ar[i]);
	}
	scanf("%d", &cap);
	lru();
	printf("\nNumber of hit: %d\n", hit);
	printf("Page Fault: %d\n", fault);
	return 0;
}
