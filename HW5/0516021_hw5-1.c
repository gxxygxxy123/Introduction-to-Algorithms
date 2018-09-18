#include <stdio.h>
#include <stdlib.h>
typedef	struct {
		int num;
		char suit;
		int value;
}Card;
int max(int a, int b){
	return a >= b ? a : b;
}
int main(void){

	int test_case, t, i, j;
	scanf("%d", &test_case);
	for(t = 0;t < test_case;t++){
		int n;
		scanf("%d", &n);
		Card *c = malloc(n * sizeof(Card));
		for(i = 0;i < n;i++)
			c[i].value = 1;
		for(i = 0;i < n;i++){//input
			char tmp[3];
			scanf("%s", tmp);
			if(tmp[0] == '1'){
				switch(tmp[1]){
					case '0':
						c[i].num = 10;
						c[i].suit = tmp[2];
						break;
					case '1':
						c[i].num = 11;
						c[i].suit = tmp[2];
						break;
					case '2':
						c[i].num = 12;
						c[i].suit = tmp[2];
						break;
					case '3':
						c[i].num = 13;
						c[i].suit = tmp[2];
						break;
					default://Ace
						c[i].num = 1;
						c[i].suit = tmp[1];
						break;
				}
			}
			else{
				c[i].num = tmp[0]-'0';
				c[i].suit = tmp[1];
			}
		}
		int ans = 1;
		for(i = 0;i < n;i++){
			int q = 1;
			for(j = 0;j < i;j++){
				if(c[i].num == 8 || c[j].num == 8){
					q = max(q, c[j].value + 1);
				}
				if(c[i].num == c[j].num){
					q = max(q, c[j].value + 1);
				}
				else if(c[i].suit == c[j].suit){
					q = max(q, c[j].value + 1);
				}
			}
			c[i].value = q;
			ans = max(ans, q);
		}
		int i;
		printf("%d\n", ans);
		free(c);
	}
	return 0;
} 
