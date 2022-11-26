#include <stdio.h>

int number = 28;
int X = 1000000000;

int load[28][28] = {
	{0,X,1,1,1,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,1,X}, //정문 
	{X,0,X,X,X,1,X,X,X,X,X,X,X,1,X,X,X,X,X,X,X,X,X,1,X,X,X,X}, //베어드홀 
	{1,X,0,1,1,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,1,X,1,X,X}, //경상관 
	{1,X,1,0,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X}, //문학관 
	{1,X,1,X,0,1,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X}, //안익태기념관 
	{X,1,X,X,1,0,X,X,X,X,X,X,X,1,X,X,X,X,X,X,X,X,X,X,X,X,1,X}, //형남공학관 
	{X,X,X,X,X,X,0,1,X,X,1,X,X,X,X,X,X,X,X,X,X,X,X,1,X,X,X,X}, //교육관 
	{X,X,X,X,X,X,1,0,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,1,X,X}, // 백마관 
	{X,X,X,X,X,X,X,X,0,1,X,X,X,1,X,X,X,X,X,X,X,X,X,X,X,X,X,X}, //한경직기념관 
	{X,X,X,X,X,X,X,X,X,0,X,1,X,1,1,X,X,X,X,X,1,X,X,X,X,X,X,1}, //신양관 
	{X,X,X,X,X,X,1,X,X,X,0,X,1,X,X,X,X,X,X,X,X,X,X,1,X,X,X,X}, //벤처중소기업센터 
	{X,X,X,X,X,X,X,X,X,1,X,0,1,X,X,X,X,X,X,X,X,X,1,1,X,X,X,X}, //진리관 
	{X,X,X,X,X,X,X,X,X,X,1,1,0,X,X,X,X,X,X,X,X,X,1,X,X,X,X,X}, //조만식기념관 
	{X,1,X,X,X,1,X,X,1,X,X,X,X,0,X,X,X,X,X,X,X,X,X,X,X,X,X,X}, //한국기독교박물관 
	{X,X,X,X,X,X,X,X,X,1,X,X,X,X,0,1,X,X,X,X,1,X,1,X,X,X,X,X}, //중앙도서관 
	{X,X,X,X,X,X,X,X,X,X,X,X,X,X,1,0,1,X,X,1,X,X,1,X,X,X,X,X}, //연구관 
	{X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,1,0,1,1,1,X,X,X,X,X,X,X,X}, //창신관 
	{X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,1,0,1,X,X,X,X,X,X,X,X,X}, //생활관 
	{X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,1,1,0,1,X,1,X,X,X,X,X,X}, //학생생활관 
	{X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,1,X,1,0,1,X,X,X,X,X,X,1}, //전산관 
	{X,X,X,X,X,X,X,X,X,1,X,X,X,X,1,X,X,X,X,1,0,X,X,X,X,X,X,1}, //미래관 
	{X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,1,X,X,0,X,X,1,X,X,X}, //정보과학관 
	{X,X,X,X,X,X,X,X,X,X,X,1,1,X,1,1,X,X,X,X,X,X,0,X,X,X,X,X}, //웨스트임스터홀 
	{X,1,1,X,X,X,1,X,X,X,1,1,X,X,X,X,X,X,X,X,X,X,X,0,X,X,X,X}, //학생회관 
	{X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,1,X,X,0,X,X,1}, //창의관 
	{X,X,1,X,X,X,X,1,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,0,X,X}, //대운동장 
	{1,X,X,X,X,1,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,0,1}, //중문1 
	{X,X,X,X,X,X,X,X,X,1,X,X,X,X,X,X,X,X,X,1,1,X,X,X,1,X,1,0}, //중문2 
};

bool v[28];
int d[28];
int r[28];


int getsmall(){
	int min = X;
	int index = 0;
	for(int i=0; i<number; i++){
		if(d[i] < min && !v[i]){
			min = d[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start){
	for(int i=0; i<number; i++){
		d[i] = load[start][i];
	}
	v[start] = true;
	for(int i=0; i<number-2; i++){
		int current = getsmall();
		r[i] = current;
		v[current] = true;
		for(int j=0; j<28; j++){
			if(!v[j]){
				if(d[current] + load[current][j] < d[j]){
					d[j] = d[current] + load[current][j];
				}
			}
		}
	}
}

char list(){
	printf("0:정문 / 1:베어드홀 / 2:숭덕경상관 / 3:문화관 / 4:안익태기념관\n5:형남공학관");
	printf(" 6:교육관 / 7:백마관 / 8:한경직기념관 / 9:신양관\n10:벤처중소기업센터");
	printf(" 11:진리관 / 12:조만식기념관 / 13:한국기독교박물관 / 14:중앙도서관\n15:연구관");
	printf(" 16:창신관 / 17:생활관 / 18:학생생활관 / 19:전산관\n20:미래관");
	printf(" 21:정보과학관 / 22:웨스트임스터홀 / 23:학생회관 / 24:창의관\n25:대운동장");
	printf(" 26:중문1 / 27:중문2\n\n");
}
void rout(int end){

	int c = r[end];
	if(end < 0){
		return;
	}
	
	for(int i=0; i<28; i++){
		if(load[c][i] < 10){
			for(int j=0; j<end; j++){
				if(i == r[j]){
					printf("%d <- ",r[j]);
					rout(j);
				
				}
			}
		}
	}printf("\n");
}


int main(){
	int start;
	int end; 
	list();
	printf("출발지점을 입력하세요 >> ");
	scanf("%d", &start);
	printf("도착지점을 입력하세요 >> ");
	scanf("%d", &end);
	dijkstra(start);
	if(start == end){
		printf("현재위치입니다!");
	}
	else{
		printf("%d부터 %d까지의 최단거리 = %d\n",start, end, d[end]);
	}
	
	for(int i=0; i<28; i++){
		if(r[i] == end){
		    printf("\n");
			rout(i);
	    }
	}
}
