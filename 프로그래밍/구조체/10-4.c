#define _CRT_SECURE_NO_WARNINGS	//	strcpy 보안 경고로 인한 컴파일 에러 방지
#include<stdio.h>
#include<stdlib.h>
#include<string.h>			//	strcpy 함수가 선언된 헤더 파일

typedef struct {			//	구조체 이름이 없는 익명 구조체
	char name[100];			//	사람의 이름을 저장할 변수
	int age;				//	사람의 나이를 저장할 변수
	char gender[10];		//	사람의 성별을 저장할 변수
}Person;					//	typedef를 사용하여 구조체 별칭을 Person으로 정의

void Person_printf(Person* data1, Person* data2, Person* data3) {				//	Person_printf 함수 정의, 데이터를 출력하는 함수
	printf("%s은 %s이고 %d살이다.\n", data1->name, data1->gender, data1->age);	//	인덱스 1번째의 이름, 성별, 나이 값 출력
	printf("%s은 %s이고 %d살이다.\n", data2->name, data2->gender, data2->age);	//	인덱스 2번째의 이름, 성별, 나이 값 출력
	printf("%s은 %s이고 %d살이다.\n", data3->name, data3->gender, data3->age);	//	인덱스 3번째의 이름, 성별, 나이 값 출력
}

int main(void) {
	Person temp;			//	버블 정렬을 사용하기 위한 공간 선언
	int choice;				//	입력하는 사람이 나이순과 이름순 중 고른 번호를 저장할 변수
	Person data[4] = { 0 };	//	구조체 배열 초기화
	Person* p = data;		//	구조체 별칭으로 포인터 선언
	for (int i = 1; i < 4; i++) {							//	i가 1부터 3까지 1씩 증가하는 동안
		printf("%d번째 사람 : ", i);						//	i번째 사람 : 출력
		scanf("%s %d %s", &p->name, &p->age, &p->gender);	//	인덱스 i번째 사람의 이름, 나이, 성별 정보를 입력
		if (data[i].age < 0 || data[i].age>120) {			//	나이가 0미만 120 초과라면
			printf("입력된 나이 확인\n");					//	입력된 나이 확인 출력
			i--;											//	i값 1 감소
			continue;										//	건너뛰기
		}
		if (strcmp(&p->gender, "m") == 0)					//	strcmp 함수를 이용하여 입력한 성별이 m이라면
			strcpy(&p->gender, "남자");						//	m을 남자로 변경
		else if (strcmp(&p->gender, "f") == 0)				//	strcmp 함수를 이용하여 입력한 성별이 f라면
			strcpy(&p->gender, "여자");						//	f를 여자로 변경
		strcpy(&data[i].name, &p->name);					//	입력받은 이름을 구조체 배열의 i번째에 복사
		strcpy(&data[i].age, &p->age);						//	입력받은 나이를 구조체 배열의 i번째에 복사
		strcpy(&data[i].gender, &p->gender);				//	입력받은 성별을 구조체 배열의 i번째에 복사

	}
	printf("1. 나이순 2. 이름순?");							//	1. 나이순 2. 이름순? 출력
	scanf("%d", &choice);									//	나이순과 이름순 중 하나를 선택해서 입력
	if (choice == 1) {										//	선택한 것이 1번이라면
		for (int i = 1; i < 3; i++) {						//	i가 1부터 2까지 1씩 증가
			if (data[i].age > data[i + 1].age) {			//	data의 i번째 인덱스의 나이가 data의 i+1번째 인덱스의 나이보다 크다면
				temp = data[i];								//	data의 i번째 인덱스를 temp에 저장
				data[i] = data[i + 1];						//	data의 i+1번째 인덱스를 data의 i번째 인덱스에 저장
				data[i + 1] = temp;							//	temp를 data의 i+1번째 인덱스에 저장
			}
		}
	}
	else if (choice == 2) {										//	선택한 것이 2번이라면
		for (int i = 1; i < 3; i++) {							//	i가 1부터 2까지 1씩 증가
			if (strcmp(data[i].name, data[i + 1].name) == 1) {	//	data의 i번째 인덱스의 이름이 data의 i+1번째 인덱스의 이름보다 크다면
				temp = data[i];									//	data의 i번째 인덱스를 temp에 저장
				data[i] = data[i + 1];							//	data의 i+1번째 인덱스를 data의 i번째 인덱스에 저장
				data[i + 1] = temp;								//	temp를 data의 i+1번째 인덱스에 저장
			}
		}

	}
	Person_printf(&data[1], &data[2], &data[3]);				//	Person_printf 함수 호출
	system("pause");
	return 0;
}