#include <iostream>

using namespace std;
 
int current[7] = {0,2,5,4,3,1,6}; //앞 뒤 서 동 위 아래

int a[5] = {0,1,3,6,4}; //가로 
int b[5] = {0,1,5,6,2}; //세로 

int a_current = 1;
int b_current = 1;

int N,M,current_x,current_y,k;

int map[20][20];
int order[1000];
int dice[7];

bool position_check(int d) {
	
	if(d == 1) {
		
		if(current_y + 1 <= M-1)
			return true;
	}
	else if(d == 2) {
		if(current_y - 1 >= 0)
			return true;
	}
	else if(d == 3) {
		if(current_x - 1 >= 0)
			return true;
	}
	else if(d == 4) {
		if(current_x  + 1 <= N - 1)
			return true;
	}
	return false;
}

int return_floor_v(int n) {
	
	switch(n) {
		case 1:
			return 6;
		case 2:
			return 5;
		case 3:
			return 4;
		case 4:
			return 3;
		case 5:
			return 2;
		case 6:
			return 1;
	}
}

void move(int d) {  //동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4로 주어진다.
	
	int dice_floor_v;
	
	if(d == 1) { //arr_1
		current_y++;
		
		int temp = dice[4];
		
		dice[4] = dice[6];
		dice[6] = dice[3];
		dice[3] = dice[1];
		dice[1] = temp;
		
	}
	
	else if(d == 2) { //arr_1
	
		current_y--;
		int temp = dice[4];
		
		dice[4] = dice[1];
		dice[1] = dice[3];
		dice[3] = dice[6];
		dice[6] = temp;
	}
	
	else if(d == 3) { //arr_2
		current_x--;
		int temp = dice[1];
		
		dice[1] = dice[5];
		dice[5] = dice[6];
		dice[6] = dice[2];
		dice[2] = temp;
	}
	
	else { //arr_2
		current_x++;
		int temp = dice[2];
		
		dice[2] = dice[6];
		dice[6] = dice[5];
		dice[5] = dice[1];
		dice[1] = temp;
	}
	
//	cout << "floor : " << dice_floor_v << '\n';
	if(!map[current_x][current_y])
		map[current_x][current_y] = dice[6];
	else {
		
//		printf("change : %d -> %d(%d,%d)\n",dice[dice_floor_v],map[current_x][current_y],current_x,current_y);
		dice[6] = map[current_x][current_y];
		map[current_x][current_y] = 0;
	} 
}

int main() 
{

	cin >> N >> M >> current_x >> current_y >> k;
	
	for(int x = 0 ; x < N ; x++) 
		for(int y = 0 ; y < M ; y++)
			cin >> map[x][y];
	
	for(int x = 0 ; x < k ; x++) 
		 cin >> order[x];
	
	for(int x = 0 ; x < k ; x++) {
		int temp = order[x];
		if(!position_check(temp))
			continue;
		move(temp);
		cout << dice[1] << '\n';

	}

}
