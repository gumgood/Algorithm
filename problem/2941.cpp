#include<stdio.h>
#include<string.h>

char in[102];
char cro1[3] = {'d','z','='};
char cro2[7][2] = {'c', '=',	'c', '-', 'd', '-', 'l', 'j',	'n', 'j', 's', '=',	'z', '='};

int solve(){
	int cnt = 0;
	for(int i=0; i<strlen(in); i++, cnt++){
		if(cro1[0]==in[i] && cro1[1]==in[i+1] && cro1[2]==in[i+2])
			i+=2; // +3
		for(int j=0; j<7; ++j)
			if(cro2[j][0]==in[i] && cro2[j][1]==in[i+1])
				i++; // +2
	}
	return cnt;
}

int main(){
	scanf("%s", in);
	printf("%d", solve());
	return 0;
}
