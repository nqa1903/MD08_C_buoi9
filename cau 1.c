#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int numbers[100];
	int size;
	int sum , max , min , findNumber , count ;
	int addIndex , addValue , currentIndex;
	do{
		printf("*************** MENU *************** \n");
		printf("1. Nhap so phan tu va cac phan tu \n");
		printf("2. In gia tri cac phan tu dang quang ly \n");
		printf("3. In cac phan tu chan va tinh tong \n");
		printf("4. In gia tri nho nhat va lon nhat trong mang \n");
		printf("5. In ra cac phan tu la so nguyen to va tinh tong \n");
		printf("6. Nhap vao 1 so va thong ke cac phan tu theo gia tri \n");
		printf("7. Them 1 phan tu vao cho chi dinh \n");
		printf("8. exit \n");
		printf("Lua chon cua ban : ");
		int choice;
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Nhap vao so phan tu cua mang : ");
				scanf("%d",&size);
				for(int i = 0 ; i < size ; i++){
					printf("numbers[%d] = ",currentIndex);
					scanf("%d",&numbers[currentIndex]);
					currentIndex++;
				}
				break;
			case 2:
				printf("Gia tri cac phan tu trong mang : \n");
				for(int i = 0 ; i < currentIndex ; i++){
					printf("%d \t",numbers[i]);
				}
				printf("\n");
				break;
			case 3:
				sum = 0;
				for(int i = 0 ; i < currentIndex ; i++){
					if(numbers[i] % 2 == 0){
						printf("%d \t", numbers[i]);
						sum += numbers[i] ;
					}
				}
				printf("Tong so chan : %d \n",sum);
				break;
			case 4:
				min = numbers[0];
				max = numbers[0];
				for(int i = 0 ; i < currentIndex ; i++){
					if(min > numbers[i]){
						min = numbers[i];
					}
					if(max < numbers[i]){
						max = numbers[i];
					}
				}
				printf("Gia tri lon nhat %d - Gia tri nho nhat %d \n", max , min);
				break;
			case 5:
				sum = 0;
				for(int i = 0 ; i < currentIndex ; i++){
					int isPrime = 0;
					if(numbers[i] >= 2){
						for(int j = 2 ; j <= sqrt(numbers[i]) ; j++){
							if(numbers[i] % j == 0){
								isPrime = 1;
								break;
							}
						}
					}else{
						isPrime = 1;
					}
					if(isPrime == 0){
						printf("%d \t",numbers[i]);
						sum += numbers[i];
					}
				}
				printf("Tong cac so nguyen to : %d \n",sum);
				break;
			case 6:
				count = 0;
				printf("Nhap vao 1 so : ");
				scanf("%d",&findNumber);
				for(int i = 0 ; i < currentIndex ; i++){
					if(numbers[i] == findNumber){
						count++;
					}
				}
				printf("So phan tu co gia tri %d trong mang la %d \n",findNumber , count);
				break;
			case 7:
				printf("Nhap gia tri can them : ");
				scanf("%d",&addValue);
				printf("Nhap vao chi so can them : ");
				scanf("%d",&addIndex);
				if(addIndex < 0 || addIndex >= 99){
					printf("khong the chen");
				}else{
					if(addIndex == currentIndex){
						numbers[currentIndex] = addValue;
						currentIndex++;
					}else if(addIndex > currentIndex){
						for(int i = currentIndex ; i < addIndex ; i++){
							numbers[i] = 0;
						}
						numbers[addIndex] = addValue;
						currentIndex = addIndex + 1;
					}else{
						for(int i = currentIndex ; i > addIndex ; i--){
							numbers[i] = numbers[i - 1];
						}
						currentIndex++;
						numbers[addIndex] = addValue;
					}
				}
				break;
			case 8:
				exit(0);
			default:
				printf("Chon lai");
		}
	}while(1 == 1);
}
