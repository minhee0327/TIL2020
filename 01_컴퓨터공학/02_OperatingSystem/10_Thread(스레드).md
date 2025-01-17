# 10 Thread(스레드)
- Thread(스레드)
    - Light Weight Process 라고도 함
    - 프로세스
        - 프로세스간에는 각 프로세스의 데이터 접근이 불가
        - 프로세스간 커뮤니케이션 위해서는 IPC 기법 필요
    - 스레드
        - 하나의 프로세스에 여러개의 스레드 생성가능
        - 스레드들은 동시 실행 가능
        - 프로세스 안에 있으므로, 프로세스의 데이터들을 모두 접근 가능
        - IPC 사용할 필요 없음
    - 멀티 스레드
        - 소프트웨어 병행 작업 처리를 위해 멀티 스레드를 사용
        - 각 스레드의 CODE, DATA, HEAP영역을 서로 공유하고, thread Stack영역만 별도로 각 스레드가 가지고있다.

> 멀티 태스킹 / 멀티 프로세싱 / 멀티 스레드  
> 1. 멀티 태스킹: 단일 CPU에서 여려 프로세스를 실행시켜 동시에 실행되는 것 처럼 보임  
> 2. 멀티 프로세싱: 여러 CPU를 사용하여, 하나 이상의 프로세스를 빠르게 실행하여 속도를 높임   
> 3. 멀티 스레드: 하나의 프로세스를 여러개의 스레드를 사용  
> 따라서 최근 CPU는 멀티코어를 가지므로, 여러스레드를 만들어서 멀티 코어의 활용도를 높이고 있다.

- 스레드 장단점
    - 장점
        1. 사용자에 대한 응답성 향상
        2. 자원 (공유) 효율
            - IPC기법과 같이 프로세스간 자원공유를 위해 번거로운 작업 필요 X
            - 프로세스 안에 있으므로, 프로세스 데이터를 모두 접근가능
        3. 작업이 분리되어 코드가 간결
            - 이건 작성하기 나름이기는 함.
        4. CPU 활용도 높이고 성능을 개선할 수 있다.
    - 단점
        1. 스레드 중 하나의 스레드만 문제가 생기더라도 전체 프로세스가 영향을 받음
        2. 스레드 많이 생성시, Context Switching이 많이 일어나 성능 저하 일어날 수 있다.
            - 예: 리눅스 OS는 스레드를 프로세스와 같이 다룬다.
            - 따라서 스레드를 많이 생성할수록 모든 스레드에 대해 스케쥴링하면서 컨택스트 스위칭이 빈번할수밖에 없다.
    
- Process VS Thread 
    |Process|Thread|
    |:------:|:-------:|
    |프로세스는 독립적|스레드는 프로세스의 서브셋(종속되어있음)|
    |각각 독립적인 자원을 가짐|**프로세스의 자원 공유**|
    |자신만의 주소영역 가짐|주소영역 공유|
    |프로세스간 IPC기법 통신|IPC 기법 필요 없음|


- 스레드 동기화문제
    - 동기화(Synchronization)
        - 스레드의 실행순서는 정해진게 아니라, 스케쥴러에 따라 그때마다 다름
        - 그런데 한 프로세스 내부의 스레드들은 같은 데이터를 공유하고 있음
        - 그래서 순서가 꼬이면, 비정상 동작을 할 수 있음. 
        - 이 비정상 동작을 스레드 동기화라고 하기때문에 관리가 필요하다.
        - 정리:
            - 동기화: 작업들 사이에 *실행시기* 를 맞추는 것.
            - 여러스레드가 동일한 자원(데이터) 접근시 동기화 이슈발생
                - 동일한 자원을 여러 스레드가 동시 수정시 각 스레드 결과에 영향(비정상 동작)을 준다.
        - 해결방법
            - **mutual exclusion(상호배제)**
            - 스레드는 프로세스 모든 데이터를 접근할 수 있으므로,
                - 여러스레드가 변경하는 공유변수에 대해 exclusive access필요
                - 어느 한 스레드가 공유변수를 갱신하는 동안 다른 스레드가 동시 접근하지 못하도록 막기
            
            - example02참조
                - 한번에 한 스레드만 공유자원에 엑세스하도록 만들어주면 해결(lock)
                    ```python
                    lock.acquire()
                    for i in range(100000):
                        g_count +=1  #임계자원
                    lock.release()
                    ```
                - 임계영역(critical section): 동시 실행하면 안되는 영역
                - 임계자원(critical resource): 동시 수정하면 안되는 자원(g_count)

- Mutex와 세마포어(Semaphore)
    - Critical Section(임계 영역) 에 대한 접근을 막기 위해 Locking 매커니즘이 필요
        - Mutex(binary semaphore)
            - 임계 구역에 하나의 스레드만 들어갈 수 있음
            - 한 쓰레드, 프로세스에 의해 소유될 수 있는 Key를 기반으로 한 상호배제기법
        - Semaphore
            - 임계구역에 여러 스레드가 들어갈 수 있음
            - counter를 두어 동시에 리소스에 접근할 수 있는 허용가능한 스레드 수 제어
            - 현재 공유자원에 접근할 수 있는 쓰레드, 프로세스의 수를 나타내는 (제한)값을 두어 상호배제를 달성하는 기법
            - 구현(수도코드)
                - P: 검사(임계영역에 들어갈 때) = lock.aquire()
                    - S값이 1 이상이면, 임예영역 진입후 S값 1차감(S값이 0이면 대기)
                - V: 증가(임예영역에서 나올때) = lock.release()
                    - S값을 1 더하고, 임계영역을 나옴
                - S: 세마포어값( 초기 값만큼 여러 프로세스가 동시 임계영역 접근가능)
                    ```C++
                    P(S): wait(S){
                        while S<=0; //대기(loop, CPU실행, 성능 ↓)
                        S--;        // 다른 프로세스 접근 제한
                    }
                    V(S): signal(S){
                        S++;   // 다른 프로세스 접근 허용
                    }
                    ```
                - wait()은 S가 0이면 임계영역에 들어가기위해 반복문 수행
                    - 바쁜 대기, busy waiting.(위 예제)
                    - 운영체제 기술로 보완: 대기큐(아래 예제)
                        - S가 음수일 경우 바쁜 대기 대신, 대기큐에 넣는다.
                        - loop를 돌리지 않고, 대기큐에 넣어둔 후 block.
                        - wakeup()함수를 통해 대기큐에 있는 프로세스 재실행.
                        - 이렇게 하면 CPU부하를 줄이면서도 semaphore를 처리할수있다.
                    ```C++
                    wait(S){
                        S->count--;
                        if(S->count<0){
                            add this process to S->queue;
                            block(); 
                        }
                    }
                    signal(S){
                        S->count++;
                        if (s->count>1){
                            remove a process P from S->queue;
                            wakeup(P)
                        }
                    }
                    ```
        - [참고자료](https://worthpreading.tistory.com/90)
        - 참고: 주요세마포어함수(POSIX세마포어)
            - sem_open(): 세마포어 생성
            - sem_wait(): 임계영역 접근전, 세마포어를 잠그고, 세마포어가 잠겨있다면 풀릴때까지 대기
            - sem_post(): 공유자원에 대한 접근이 끝났을 때 세마포어 잠금을 해제한다.

- 교착상태(Deadlock)와 기아상태(Starvation)
    - 교착상태(deadlock)이란?
        - 무한대기상태: 두개 이상의 작업이 서로 상대방의 작업이 끝나기만을 기다리기 때문에(waiting), 다음 단계로 진행 못하는 상태
        - 여러 프로스세스가 동일자원 점유를 요청할때 발생
        > 배치 처리 시스템에서는 일어나지 않는 문제
        > 프로세스 , 스레드 둘다 이와같은 상태 일어날 수 있음
        - 참고: 아래 4개지 조건 모두 성립하면 교착상태 발생 가능성있음
            - 상호배제: 프로세스들이 필요로하는 자원에 대해 배타적 통제권요구
            - 점유대기: 프로세스가 할당된 자원을 가진 상태에서 다른 자원을 기다림
            - 비선점: 프로세스가 어떤 자원의 사용이 끝날때까지 그 자원을 뺏을 수 없음
            - 순환대기: 각 프로세스는 순환적으로 다음 프로세스가 요구하는 자원을 가지고있음
            - 위 4가지 조건중 한가지가 성립안되도록 빼면, 교착상태를 방지할 수 있음.
    - 기아상태(starvation)
        - 특정 프로세스의 우선순위가 낮아서 원하는 자원을 계속 할당받지 못하는 상태
        - 여러프로세스가 부족한 자원을 점유하기 위해 경쟁할때, 특정 프로세스는 영원히 자원이 할당 안되는 경우를 주로 의미.
        - 해결방안
            - 우선순위변경
                - 프로세스 우선순위를 수시로 변경해서, 각 프로세스가 높은 우선순위를 가질기회 주기
                - 오래기다린 프로세스의 우선순위 높여주기
                - 우선순위가 아닌, 요청 순서대로 처리하는 FIFO기반 요청큐 사용.