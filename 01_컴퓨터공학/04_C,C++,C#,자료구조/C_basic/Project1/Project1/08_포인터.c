/*
- 포인터 변수는 메모리 주소 저장 (어떤 자료형인지, 위치값(메모리 주소값))
- 예시1:
- int a = 5; (주소값: 0 X AFB03954)
- int *b = &a; (0 X AFB03954를 가리킴, b의 주소는 0 XCA29839F )
- 포인터 변수, b를 통해서도 5라는 값을 가져올 수 있음.

- https://bit.ly/38wT4Du
- int a; &a : 주소 연산자: 변수 앞에 붙어서 사용하는 변수가 할당된 메모리 시작 주소값을 구한다.
- int *pi: 포인터: 시작 주소값을 저장하는 변수에 가리키는 자료형을 표시하여 선언
- *pi = 10 : 간접참조 연산자: 포인터에 사용하여 포인터가 가리키는 변수 사용

- 실제로 변수를 할당하면 메모리 주소상에는 4byte를 차지하므로, 
- 메모리 주소를 1byte식 표현할 때, 4 칸을 차지하게됨. 
- (예시2: compile하면, 메모리주소값이 4byte씩 떨어져있는걸 확인할 수 있다.)

* 포인터의 강력한 기능
	- 컴퓨터 시스템의 특정한 메모리에 바로 접근이 가능하다.
	- 따라서 기존에 존재하던 중요한 메모리 영역에 접근하지 않도록 주의해야한다.
	- 아래 코드는 위험한 코드 예시
		- int *a = 0 X33484735;
		- *a = 0;
	- a에 사용됬던 주소값이 어떻게 쓰이는지 모르는데, 0으로 덮으면 안됨
	- 또한, 포인터는 다중으로 사용이 가능하다. (포인터의 포인터 변수)
	- 예시3:
		- int **c = &b;

	- 예시4:
		- 배열과 포인터는 동일.
		- 배열을 선언한 이후에는 그 이름자체가 포인터 변수와 동일하다. 
*/

/*
#include <stdio.h>
//예시1: 기본 포인터 사용 
int main(void) {
	int a = 5;
	int* b = &a; //포인터 연산자
	
	printf("%d\n", *b); //간접 참조 연산자
	system("pause");
	return 0;
}
*/

/*
#include <stdio.h>

//예시2: 배열 주소값 확인해보기
int main(void) {
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	int i;

	for (i = 0; i < 10; i++) {
		printf("%d %d\n", a[i], &a[i]); //배열의 값, 주소값
	}
	system("pause");
	return 0;
}
*/

/*
#include <stdio.h>

//예시3: 다중 포인터 사용
int main(void) {
	int a = 5;
	int* b = &a;
	int** c = &b;
	printf("%d\n", **c);

	system("pause");
	return 0;
}
*/

/*
#include <stdio.h>

//예시4: 배열은 선언과 동시에 그 이름이 포인터 변수
int main(void) {
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	int* b = a;
	printf("%d\n", b[2]);
	system("pause");
	return 0;
}
*/