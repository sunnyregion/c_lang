#include "stdio.h"
#define MAX_INT ((unsigned)(-1) >> 1)
#define MIN_INT (MAX_INT + 1)
void week7_2(){
	int n,iCount,i,j,iTmp,iRow,iCol;
	scanf("%d",&n);
	int matrix[n][n],record[n][3];
	int bFlag=1;
	while(iCount<n){
		for(i=0;i<n;i++){
			scanf("%d", &iTmp);
			matrix[iCount][i]=iTmp;
		}
		iCount++;
	}

	for(i=0;i<n;i++){
		iTmp=MIN_INT;
		iRow=0;
		iCol=0;
		for(j=0;j<n;j++){
			if (iTmp<matrix[i][j]){
				iTmp=matrix[i][j];
				iRow=i;
				iCol=j;
			}

		}
		record[i][0]=i;
		record[i][1]=iCol;
		record[i][2]=iTmp;
		
	}
	for (j = 0; j < n; j++){
		iTmp=MAX_INT;
		iRow=0;
		iCol=0;
		for (i = 0; i < n; ++i)
		{
			if (iTmp>matrix[i][j]){
				iTmp=matrix[i][j];
				iRow=i;
				iCol=j;
			}
		}
		if(record[iRow][0]==iRow && record[iRow][1]==iCol){
			bFlag=0;
			printf("%d %d",iRow,iCol );
			break;
		}
	}

	if(bFlag==1){
		printf("NO");
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	week7_2();
	return 0;
}