#include<stdio.h>
#include<math.h>
int main(){
	int t=0,n,g,a,b,i,j,min=1000,ii=1;
	scanf("%d%d%d",&n,&a,&b);//������̥���� 
	int lun[n][2];
	for(i=0;i<n;i++){        // ѭ������ÿһ����̥���� 
		scanf("%d%d",&lun[n][0],&lun[n][1]);
		if(min>lun[n][0]){
			g=i;
			t=lun[n][0];
		}	
	}
	for(i=1;i<a;i++){		//һ���ܵ�Ȧ�� 
		if(b<=lun[g][0]*pow(lun[g][1],ii-1)){// �ж�Ҫ��Ҫ����̥ 
			t+=b;
			ii=1;
			for(j=0;j<n;j++){
				if(min>lun[j][0]){
					g=j;
				}	
			}
		}
		t+=lun[g][0]*pow(lun[g][1],ii-1);
		ii++;
	}
	printf("%d",t);
	return 0;
} 
