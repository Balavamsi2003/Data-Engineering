#include<stdio.h>
#include<stdlib.h>
int main(){
	int n,b;
	printf("\n Enter the no.of elements");
	scanf("%d",&n);
	printf("\n Enter the bin length");
	scanf("%d",&b);
	int k=n/b;
	int l[k][b];
	float mean[b];
	for(int j=0;j<k;j++){
		for(int i=0;i<b;i++){
			scanf("%d",&l[j][i]);
		}
	}
	for(int j=0;j<k;j++){
		int sum=0;
		for(int i=0;i<b;i++){
			sum+=l[j][i];
		}
		mean[j]=float(sum)/b;
	}
for(int j=0;j<k;j++){
		for(int i=0;i<b;i++){
			printf("%.2f ",mean[j]);
		}
		printf("\n");
	}
}
