1. C
    1. C에서 기본 문법은 클라우드 환경에서 진행
        - https://ideone.com/
        - https://ide.goorm.io/
        - 잘 기억안나는 부분만 긁어와서 저장해두기
    2. IDE(통합 개발환경)
        - 코딩, 디버깅, 컴파일, 배포 모든 과정 통합관리 software
        - Visual Studio 2019사용중
        - [필요한 부분만 IDE에서 진행]
    3. 프로젝트 생성 및 파일생성, 빌드
        1. 프로젝트 생성방법
            - 파일(F)=> 새로만들기(N) => 프로젝트(P)
            - '빈프로젝트'생성하기
            - 프로젝트 경로 설정하기
        2. 소스코드 생성방법
            - 소스파일 -> 추가(D) -> 새항목(W)
            - C파일(.c)생성하기
        3. C파일 이름 규칙
            - _ 사용X
            - 특수문자 사용X
        4. 소스코드 실행방법
            - 디버그 -> 디버깅시작(S)
            - F5 눌러 간단히 실행가능
            - system("pause")함수로 콘솔 창 닫힘 방지
        5. 프로젝트 빌드방법
            - 빌드(B) -> 솔루션 빌드(B)
        6. 프로젝트 빌드 결과확인
            - 솔루션 탐색기 -> 파일탐색기에서 폴더열기(X)
            - Debug 폴더 내부 실행파일 확인

    4. 기본 C파일 분석
        - `#include <stdio>`: standard I/O 라이브러리 (printf,...)
        - main() 함수로부터시작
        - return 0 (기본적으로 반환)
        - 하나의 명령어가 끝나면 `;`
        - `system("pause")`: 시스템함수 불러오는 순간 잠시 대기(키보드 입력시 실행중지)
        