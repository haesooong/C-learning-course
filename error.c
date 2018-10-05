#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*전역변수
=============================================*/

char id[100], pass[100];
int money = 0;

/*회원가입&로그인
=============================================*/

void init(void); //회원가입과 로그인을 처리합니다.
void verfy_human(void); //인간증명 단계입니다.
void signup(void); //회원가입을 처리합니다.
void signin(void); //로그인을 처리합니다.

/*입출금, 잔액확인
=============================================*/

void money_engine(void); //돈을 관리해 줍니다.
void add_money(void); //입금을 처리합니다.
void get_money(void); //출금을 처리합니다.
void find_money(void); //잔액확인 기능입니다.

/*메인함수
============================================*/

int main(void){
	printf("=================================================\n");
	printf("=                                               =\n");
	printf("=                    OBank 은행                 =\n");
	printf("=                                               =\n");
	printf("=================================================\n");
	init();
	money_engine();
}


/*회원가입&로그인
=============================================*/

void init(void){
	printf("=                                               =\n");
	printf("=     시작하려면 먼저 가입을 하시기 바랍니다.   =\n");
	printf("=                                               =\n");
	printf("=================================================\n");
	printf("=                                               =\n");
	printf("=         가입 절차를 안내해 드리겠습니다.      =\n");
	printf("=                                               =\n");
	printf("=         1. 인간 증명 절차                     =\n");
	printf("=         2. 회원 가입                          =\n");
	printf("=         3. 로그인                             =\n");
	printf("=                                               =\n");
	printf("=================================================\n");
	verfy_human();
	signup();
	signin();
}

void verfy_human(void){
	srand( (unsigned)time(NULL) );
	int verfy_number = 1000+(rand() % 4000), verfy_number_real;
	printf("=                                               =\n");
	printf("=            인간 증명을 하겠습니다.            =\n");
	printf("=                                               =\n");
	printf("=       아래 보이는 숫자를 따라 적으세요 :      =\n");
	printf("=                                               =\n");
	printf("=                     %d                      =\n", verfy_number);
	printf("=                                               =\n");
	printf("=================================================\n");
	printf("                      ");
	scanf("%d", &verfy_number_real);
	if(verfy_number_real == verfy_number){
		printf("=================================================\n");
		printf("=                                               =\n");
		printf("=             인증이 완료되었습니다.            =\n");
		printf("=                                               =\n");
		printf("=         이제 회원가입을 시작하겠습니다.       =\n");
		printf("=                                               =\n");
		printf("=================================================\n");
	}else{
		printf("=================================================\n");
		printf("=                                               =\n");
		printf("=              잘못된 숫자였습니다.             =\n");
		printf("=                                               =\n");
		printf("=             프로그렘은 종료됩니다.            =\n");
		printf("=                                               =\n");
		printf("=================================================\n");
		exit(0);
	}
}


void signup(void){
	printf("=                                               =\n");
	printf("=            회원 가입을 하겠습니다.            =\n");
	printf("=                                               =\n");
	printf("=     먼저 원하는 ID 를 적고 암호를 적으세요.   =\n");
	printf("=                                               =\n");
	printf("=================================================\n");
	printf("           ID : ");
	scanf("%s", id);
	printf("         PASS : ");
	scanf("%s", pass);
}


void signin(void){
	printf("=================================================\n");
	printf("=                                               =\n");
	printf("=              로그인을 하겠습니다.             =\n");
	printf("=                                               =\n");
	printf("=      가입할 때 적은 ID 와 암호를 적으세요.    =\n");
	printf("=                                               =\n");
	printf("=================================================\n");
	for(int i = 0; ; i++){
		char false_id[100], false_pass[100];
		printf("           ID : ");
		scanf("%s", false_id);
		printf("         PASS : ");
		scanf("%s", false_pass);
		if((strcmp(false_id, id) == 0) && (strcmp(false_pass, pass) == 0)){
			printf("=================================================\n");
			printf("=                                               =\n");
			printf("=       로그인이 성공적으로 진행되었습니다.     =\n");
			printf("=                                               =\n");
			printf("=          이제 입출금을 할 수 있습니다.        =\n");
			printf("=                                               =\n");
			printf("=================================================\n");
			break;
		}else if(i >= 5){
			printf("=================================================\n");
			printf("=                                               =\n");
			printf("=          로그인 횟수를 초과하였습니다.        =\n");
			printf("=                                               =\n");
			printf("=             프로그렘은 종료됩니다.            =\n");
			printf("=                                               =\n");
			printf("=================================================\n");
			exit(0);
		}else{
			printf("\n=================================================\n");
			printf("=                                               =\n");
			printf("=             잘못된 비밀번호였습니다.          =\n");
			printf("=                                               =\n");
			printf("=================================================\n\n");
		}
	}
}


/*입출금, 잔액확인
=============================================*/

void money_engine(void){
	int number;
	while(1){
		printf("=                                               =\n");
		printf("=          어떻게 도와드릴까요? 고르세요.       =\n");
		printf("=                                               =\n");
		printf("=================================================\n");
		printf("=                                               =\n");
		printf("=         1. 입금                               =\n");
		printf("=         2. 출금                               =\n");
		printf("=         3. 잔액확인                           =\n");
		printf("=                                               =\n");
		printf("=================================================\n");
		printf("            번호를 선택해 주세요 : ");
		scanf("%d", &number);
		switch(number){
			case 1:
				add_money();
			case 2:
				get_money();
			case 3:
				find_money();
			default: //작동이 않 되요... 😭 왜???
				printf("\n=================================================\n");
				printf("=                                               =\n");
				printf("=             잘못된 번호였습니다.              =\n");
				printf("=                                               =\n");
				printf("=================================================\n");
		}
	}
	
	
}


void add_money(void){
	
}


void get_money(void){
	
}

void find_money(void){
	
}
