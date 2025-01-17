1. React

   - javaScript로 DOM을 직접 건드리면서 작업을 하다보면, 코드가 난잡해지기 쉬움
   - 처리할 이벤트도 다양하고, 관리해야할 상태값도 다양하고 DOM도 다양하면,  
     이에 따라 업데이트 하는 규칙이 많이 복잡해짐.
   - 그래서 프레임워크가 나왔음: Ember, Backbone, AngularJS 등  
      자바스크립트의 특정 값이 바뀌면,  
      특정 DOM의 속성이 바뀌도록 연결하여 업데이트 작업을 간소화함
   - 리엑트는 DOM을 업데이트할 규칙을 정하는게 아니고, 아예 다 날린 후,  
     처음부터 모든걸 새로 만들어서 보여주면 어떨까? 라는 발상에서 시작됨.
   - 하지만 모두 날리고 다 새로 만들면 속도가 느릴것.
   - 이를 개선하기 위해 Virtual Dom을 사용.
   - 실제 보여지는 DOM이 아닌, 메모리에 가상으로 존재하는 DOM.
   - 상태가 업데이트 되면, 업데이트가 필요한 곳의 UI를 가상 돔에 먼저 랜더링하고, 실제 브라우저에 보여지고 있는 DOM과 비교후, 차이가 있는 곳을 감지해서, 실제 DOM에 패치시키는것.
   - 이로써 업데이트를 어떻게할지 고민하지 않으면서, 빠른 성능을 지킬 수 있게됨.

2. 환경설정

   - jsx: javaScript확장버전(리엑트 컴포넌트에서 XML형식의 값을 반환)
     - 리액트에서 생김새 정의
     - XML 형태로 코드 작성하면 babel이 JSX를 javaScript로 변환.
   - webpack: 여러가지 파일을 한 개로 결합하기 위해
   - babel:
     - jsx를 비롯한 새로운 자바스크립트 문법을 사용하기위해.
     - javaScript 문법 확장
     - 최신문법이나 편의상 사용하거나 실험적인 자바스크립트 문법을 정식 자바스크립트 형태로 변환
     - 구형 브라우저 환경에서도 실행
   - node.js: node --version으로 확인 (babel, webpack 이 런타임인 node.js 기반으로 만들어져있음.)
   - yarn(npm 개선버전) : yarn --version으로 확인 (없을 경우 설치)
   - code editor: vsCode로 진행
   - git bash: terminal환경설정 함.
   - 프로젝트 생성: npx create-react-app [프로젝트명]
   - .gitignore 작성
   - 프로젝트 생성후, 해당 경로에서 yarn start(혹은 npm start)

3. My first react Component

   - index.js 의 ReactDom.render의 역할: 브라우저에 있는 실제 DOM내부에 리액트 컴포넌트를 렌더링하겠다.
   - 항상 닫히는 태그로(self closing tag)사용
   - 항상 하나의 태그로 감싸진 상태로 리턴.
   - 단순히 감싸기위한 용도로 `<div>` 쓰지 않고, Fragment(`<></>`)사용하면된다.
   - Fragment는 브라우저 상에서 따로 별도 엘리먼트로 나타나지 않음
   - 변수를 보여줘야할 때는 {}로 감싸서 보여주기

4. 이번 강의에서 배우고 싶은 것

   1. 최적화
   2. 비동기
   3. 다른 파트는 왠만하면 이해하고, 바로 생각해서 쓸수있게 복습

5. 프로젝트 폴더 설명
   1. begin-react: react 입문
      - Hook + 함수형 컴포넌트
        - useState, use Reducer로 상태관리
        - useRef로 DOM 선택(외부 라이브러리 등 처리)
        - 배열 CRUD
        - useEffect (마운트, 언마운트, 업데이트)
        - 최적화(useMemo, useCallback, React.memo)
        - 커스텀 Hooks, ContextAPI 전역값관리, Immer라이브러리로 불변성 유지
      - Class 형 컴포넌트
        - LifeCycleMethod
   2. error-catch: 클래스형 컴포넌트 (생명주기 메서드 중, componentDidcatchup으로 예외처리)
   3. useful-tools:
      - 리엑트 개발에 편리한 추가 도구들.
        - Prettier
          - 코드 스타일을 커스터마이징 할 수 있음.
          - edittor와 연동해서 사용.
        - ESLint
          - 라이브러리(실습)
            - eslint-config-airbnb 로 진행해봄
        - Snippet
