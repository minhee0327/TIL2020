import 'normalize.css';
import styles from './index.css'

function component (){
    const element = document.createElement('div'); //div tag를 생성
    element.innerText = "Hello Webpack"; //div 태그 내부 글자

    console.log(styles);

    element.classList = styles.helloWebpack //div 태그 내부에 클래스로 helloWebpack의 해시값

    return element;
}

document.body.appendChild(component()) //body태그 자식요소로 component함수로 만든 div태그를 붙임

//따라서 결과: class에 있는 css우선순위가 일반 태그에 적용한 것보다 높기 때문에 파랑색 출력
//console.log(styles); => {helloWebpack: 해시값} 
//