#include <iostream>
#include <stdio.h>

using namespace std;

int a[10000001],b[10000001];
int index;

void Merge(int a[], int l, int mid , int r){
	int i = l, j = mid + 1,k = l;
	while(i <= mid && j <= r){
		if(a[i] <= a[j]){
			b[k] = a[i];
            k ++;
            i ++;
        }
		else{
			index += j - k;
            if (index > 10000007) index -= 10000007;
			b[k] = a[j];
            k ++;
            j ++;
		}
	}
	while(i <= mid){
		b[k] = a[i];
        k ++;
        i ++;
    }
	while(j <= r){
		b[k] = a[j];
        k ++;
        j ++;
    }
	for(int i = l; i <= r; i++)
		a[i] = b[i];

}

void Search(int a[], int l, int r)
{
	if(l < r){
		int mid = l + (r-l)/2;
		Search(a,l,mid);
		Search(a,mid+1,r);
		Merge(a,l,mid,r);
	}
}

int main(){
	int n;
	scanf("%d",&n);
    index = 0;
    for(int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    Search(a,0,n-1);
    printf("%d",index);
	return 0;
}