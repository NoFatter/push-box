#include <stdio.h>
int map[21][41]={0};
int step = 0;
int main()
{
	void picture();
	void prime();
	int i,j;
	char temp;
	int x,y;
	int level;
	int count;
	int N;
	printf("��������Ϸ�Ѷ�(1-9)��");
	scanf("%d",&level);
	prime(level);
	picture();
	while(1){
		count=0;
		temp = getch();
		if(temp==77){
			for(i=0;i<21;i++){
				for(j=0;j<41;j++){
					if(map[i][j]==9){
						y=i;
						x=j;
					}
				}
			}
			if(x+1>39){
				continue;
			}
			if(map[y][x+1]==8){
				if(x+2>39){
					continue;
				}
				if(map[y][x+2]==6||map[y][x+2]==8){
					continue;
				}
				map[y][x+2]=8;
			}
			if(map[y][x+1]==6){
				continue;
			}
			if(map[y][x+1]==7){
				continue;
			}
			map[y][x]=0;
			map[y][x+1]=9;
			step++;
			picture();
		}//���� 
		if(temp==80){
			for(i=0;i<21;i++){
				for(j=0;j<41;j++){
					if(map[i][j]==9){
						y=i;
						x=j;
					}
				}
			}
			if(y+1>19){
				continue;
			}
			if(map[y+1][x]==8){
				if(y+2>19){
					continue;
				}
				if(map[y+2][x]==6||map[y+2][x]==8){
					continue;
				}
				map[y+2][x]=8;
			}
			if(map[y+1][x]==6){
				continue;
			}
			if(map[y+1][x]==7){
				continue;
			}
			map[y][x]=0;
			map[y+1][x]=9;
			step++;
			picture();
		}//����
		if(temp==72){
			for(i=0;i<21;i++){
				for(j=0;j<41;j++){
					if(map[i][j]==9){
						y=i;
						x=j;
					}
				}
			}
			if(y-1<0){
				continue;
			}
			if(map[y-1][x]==8){
				if(y-2<0){
					continue;
				}
				if(map[y-2][x]==6||map[y-2][x]==8){
					continue;
				}
				map[y-2][x]=8;
			}
			if(map[y-1][x]==6){
				continue;
			}
			if(map[y-1][x]==7){
				continue;
			}
			map[y][x]=0;
			map[y-1][x]=9;
			step++;
			picture();
		}//����
		if(temp==75){
			for(i=0;i<21;i++){
				for(j=0;j<41;j++){
					if(map[i][j]==9){
						y=i;
						x=j;
					}
				}
			}
			if(x-1<0){
				continue;
			}
			if(map[y][x-1]==8){
				if(x-2<0){
					continue;
				}
				if(map[y][x-2]==6||map[y][x-2]==6){
					continue;
				}
				map[y][x-2]=8;
			}
			if(map[y][x-1]==6){
				continue;
			}
			if(map[y][x-1]==7){
				continue;
			}
			map[y][x]=0;
			map[y][x-1]=9;
			step++;
			picture();
		} //���� 
		if(temp==0x1b){
			system("cls");
			break;
		}
		for(i=0;i<21;i++){
			for(j=0;j<51;j++){
				if(map[i][j]==7){
					count++;
				}
			}
		}
		if(count==0){
			for(i=0;i<21;i++){
				for(j=0;j<41;j++){
					map[i][j]=0;	
				}
			}
			printf("\n\n������!\n");
			printf("�����������\n");
			getchar(); 
			level++;
			if(level==10){
				system("cls");
				printf("ͨ����!\n������Ǹ���ţ�\n ��л������棡\n");
				printf("�����ˣ������\n");
				break;
			}
			prime(level);
			picture();
		}
	}
	system("pause");
	return 0;	
} 


void picture(){
	int i,j;
	system("cls");
	for(i=0;i<21;i++){
		for(j=0;j<41;j++){
			if(map[i][j]==0){
				printf(" ");
			}
			else if(map[i][j]==1){
				printf("|");
			}
			else if(map[i][j]==2){
				printf("-");
			}
			else if(map[i][j]==9){
				printf("&"); 
			}
			else if(map[i][j]==8){
				printf("#");
			}
			else if(map[i][j]==7){
				printf("$");
			}
			else if(map[i][j]==6){
				printf("+");
			}
		}
		printf("\n");
	}
	printf("\n\n");
	printf("��ʹ�÷��������С�������ӣ�\n");
	printf("��ǰ������%d\n",step);
	printf("&��С�ˣ�#�����ӣ�$��Ŀ�ĵأ�\n");
	printf("��esc���˳�"); 
}

void prime(int level){
	int i;
	step = 0;
	for(i=0;i<21;i++){
		map[i][40]=1;//1Ϊ| 
	}
	for(i=0;i<41;i++){
		map[20][i]=2;//2Ϊ- 
	}
	if(level==1){
		map[1][1]=9;//9Ϊ��
		map[2][2]=8;//8Ϊ����
		map[15][30]=7;//7ΪĿ�ĵ� 
	} 
	else if(level==2){
		map[1][1]=9;
		map[2][2]=8;
		map[15][30]=7;
		for(i=0;i<20;i++){
			if(i==13||i==14){
				continue;
			}
			map[i][20]=6;//6Ϊ�ϰ� 
		}
	}
	else if(level==3){
		map[1][1]=9;
		map[17][19]=8;
		map[15][3]=7;
		for(i=0;i<20;i++){
			if(i==15||i==16){
				continue;
			}
			map[i][20]=6; 
		}		
	}
	else if(level==4){
		map[1][1]=9;
		map[17][19]=8;
		map[15][3]=7;
		for(i=0;i<20;i++){
			if(i==15||i==16){
				continue;
			}
			map[i][20]=6; 
		}
		map[14][4]=6;
		map[14][3]=6;
		map[14][2]=6;
		map[15][4]=6;
		map[16][4]=6;
		map[16][3]=6;
		map[16][2]=6;
	}
	else if(level==5){
		map[1][1]=9;
		map[17][19]=8;
		map[17][30]=8;
		map[15][3]=7;
		map[2][30]=7;
		for(i=0;i<20;i++){
			if(i==15||i==16){
				continue;
			}
			map[i][20]=6; 
		}
		map[14][4]=6;
		map[14][3]=6;
		map[14][2]=6;
		map[15][4]=6;
		map[16][4]=6;
		map[16][3]=6;
		map[16][2]=6;
		
		map[1][30]=6;
		map[1][29]=6;
		map[2][29]=6;
		map[1][31]=6;
		map[2][31]=6;
		map[3][31]=6;
		map[3][29]=6;
	}
	else if(level==6){
		map[7][20]=9;
		map[7][17]=8;
		map[9][29]=7;
		for(i=5;i<11;i++){
			map[i][15]=6;
		}
		for(i=5;i<11;i++){
			map[i][30]=6;
		}
		for(i=16;i<30;i++){
			map[5][i]=6;
		}
		for(i=16;i<30;i++){
			map[10][i]=6;
		}
	}
	else if(level==7){
		map[7][20]=9;
		map[7][17]=8;
		map[8][17]=8;
		map[9][29]=7;
		map[6][29]=7;
		for(i=5;i<11;i++){
			map[i][15]=6;
		}
		for(i=5;i<11;i++){
			map[i][30]=6;
		}
		for(i=16;i<30;i++){
			map[5][i]=6;
		}
		for(i=16;i<30;i++){
			map[10][i]=6;
		}
		for(i=5;i<11;i++){
			if(i==7||i==8){
				continue;
			}
			map[i][28]=6;
		}
	}
	else if(level==8){
		map[7][20]=9;
		map[7][17]=8;
		map[8][17]=8;
		map[8][19]=8;
		map[9][29]=7;
		map[6][29]=7;
		map[6][21]=7;
		for(i=5;i<11;i++){
			map[i][15]=6;
		}
		for(i=5;i<11;i++){
			map[i][30]=6;
		}
		for(i=16;i<30;i++){
			map[5][i]=6;
		}
		for(i=16;i<30;i++){
			map[10][i]=6;
		}
		for(i=5;i<11;i++){
			if(i==7||i==8){
				continue;
			}
			map[i][28]=6;
		}
		for(i=5;i<11;i++){
			if(i==7||i==8){
				continue;
			}
			map[i][20]=6;
		}
	}
	else if(level==9){
		map[7][20]=9;
		map[7][17]=8;
		map[8][17]=8;
		map[8][19]=8;
		map[8][24]=8;
		map[9][29]=7;
		map[6][29]=7;
		map[6][21]=7;
		map[9][21]=7;
		for(i=5;i<11;i++){
			map[i][15]=6;
		}
		for(i=5;i<11;i++){
			map[i][30]=6;
		}
		for(i=16;i<30;i++){
			map[5][i]=6;
		}
		for(i=16;i<30;i++){
			map[10][i]=6;
		}
		for(i=5;i<11;i++){
			if(i==7||i==8){
				continue;
			}
			map[i][28]=6;
		}
		for(i=5;i<11;i++){
			if(i==7||i==8){
				continue;
			}
			map[i][20]=6;
		}
	}
}
	

