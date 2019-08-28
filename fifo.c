#include <stdio.h>
#define MAX 100005

int n, ar[MAX], cap, q[MAX], fault, hit;

void fifo(){
	int i, pos=1, flag, cnt=1;
	for(i=1; i<=cap; i++) q[i]=-1;
	while(pos<=n){
		flag=0;
		for(i=1; i<=cap; i++){
			if(q[i]==-1){
				q[i]=ar[pos];
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
			if(ar[pos]==q[i]){
				flag=1;
				break;
			}
		}
		if(cnt>cap) cnt=1;
		if(flag==0){
			q[cnt]=ar[pos];
			pos++;
			cnt++;
			fault++;
		}
		else{
			hit++;
			pos++;
		}
	}
}
int main(void) {
	int i;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &ar[i]);
	}
	scanf("%d", &cap);
	fifo();
	printf("\nNumber of hit: %d\n", hit);
	printf("Page Fault: %d\n", fault);
	return 0;
}
