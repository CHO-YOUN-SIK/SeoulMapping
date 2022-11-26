#include <stdio.h>

int number = 28;
int X = 1000000000;

int load[28][28] = {
	{0,X,1,1,1,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,1,X}, //���� 
	{X,0,X,X,X,1,X,X,X,X,X,X,X,1,X,X,X,X,X,X,X,X,X,1,X,X,X,X}, //�����Ȧ 
	{1,X,0,1,1,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,1,X,1,X,X}, //���� 
	{1,X,1,0,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X}, //���а� 
	{1,X,1,X,0,1,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X}, //�����±��� 
	{X,1,X,X,1,0,X,X,X,X,X,X,X,1,X,X,X,X,X,X,X,X,X,X,X,X,1,X}, //�������а� 
	{X,X,X,X,X,X,0,1,X,X,1,X,X,X,X,X,X,X,X,X,X,X,X,1,X,X,X,X}, //������ 
	{X,X,X,X,X,X,1,0,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,1,X,X}, // �鸶�� 
	{X,X,X,X,X,X,X,X,0,1,X,X,X,1,X,X,X,X,X,X,X,X,X,X,X,X,X,X}, //�Ѱ������� 
	{X,X,X,X,X,X,X,X,X,0,X,1,X,1,1,X,X,X,X,X,1,X,X,X,X,X,X,1}, //�ž�� 
	{X,X,X,X,X,X,1,X,X,X,0,X,1,X,X,X,X,X,X,X,X,X,X,1,X,X,X,X}, //��ó�߼ұ������ 
	{X,X,X,X,X,X,X,X,X,1,X,0,1,X,X,X,X,X,X,X,X,X,1,1,X,X,X,X}, //������ 
	{X,X,X,X,X,X,X,X,X,X,1,1,0,X,X,X,X,X,X,X,X,X,1,X,X,X,X,X}, //�����ı��� 
	{X,1,X,X,X,1,X,X,1,X,X,X,X,0,X,X,X,X,X,X,X,X,X,X,X,X,X,X}, //�ѱ��⵶���ڹ��� 
	{X,X,X,X,X,X,X,X,X,1,X,X,X,X,0,1,X,X,X,X,1,X,1,X,X,X,X,X}, //�߾ӵ����� 
	{X,X,X,X,X,X,X,X,X,X,X,X,X,X,1,0,1,X,X,1,X,X,1,X,X,X,X,X}, //������ 
	{X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,1,0,1,1,1,X,X,X,X,X,X,X,X}, //â�Ű� 
	{X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,1,0,1,X,X,X,X,X,X,X,X,X}, //��Ȱ�� 
	{X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,1,1,0,1,X,1,X,X,X,X,X,X}, //�л���Ȱ�� 
	{X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,1,X,1,0,1,X,X,X,X,X,X,1}, //����� 
	{X,X,X,X,X,X,X,X,X,1,X,X,X,X,1,X,X,X,X,1,0,X,X,X,X,X,X,1}, //�̷��� 
	{X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,1,X,X,0,X,X,1,X,X,X}, //�������а� 
	{X,X,X,X,X,X,X,X,X,X,X,1,1,X,1,1,X,X,X,X,X,X,0,X,X,X,X,X}, //����Ʈ�ӽ���Ȧ 
	{X,1,1,X,X,X,1,X,X,X,1,1,X,X,X,X,X,X,X,X,X,X,X,0,X,X,X,X}, //�л�ȸ�� 
	{X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,1,X,X,0,X,X,1}, //â�ǰ� 
	{X,X,1,X,X,X,X,1,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,0,X,X}, //���� 
	{1,X,X,X,X,1,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,0,1}, //�߹�1 
	{X,X,X,X,X,X,X,X,X,1,X,X,X,X,X,X,X,X,X,1,1,X,X,X,1,X,1,0}, //�߹�2 
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
	printf("0:���� / 1:�����Ȧ / 2:�������� / 3:��ȭ�� / 4:�����±���\n5:�������а�");
	printf(" 6:������ / 7:�鸶�� / 8:�Ѱ������� / 9:�ž��\n10:��ó�߼ұ������");
	printf(" 11:������ / 12:�����ı��� / 13:�ѱ��⵶���ڹ��� / 14:�߾ӵ�����\n15:������");
	printf(" 16:â�Ű� / 17:��Ȱ�� / 18:�л���Ȱ�� / 19:�����\n20:�̷���");
	printf(" 21:�������а� / 22:����Ʈ�ӽ���Ȧ / 23:�л�ȸ�� / 24:â�ǰ�\n25:����");
	printf(" 26:�߹�1 / 27:�߹�2\n\n");
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
	printf("��������� �Է��ϼ��� >> ");
	scanf("%d", &start);
	printf("���������� �Է��ϼ��� >> ");
	scanf("%d", &end);
	dijkstra(start);
	if(start == end){
		printf("������ġ�Դϴ�!");
	}
	else{
		printf("%d���� %d������ �ִܰŸ� = %d\n",start, end, d[end]);
	}
	
	for(int i=0; i<28; i++){
		if(r[i] == end){
		    printf("\n");
			rout(i);
	    }
	}
}
