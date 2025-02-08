# Engine2D

---
(제작 도중이므로, 많은 변경이 있을 수 있습니다.)
---
## 개요
Engine2D는 2D 게임 개발을 위한 간단한 게임 엔진입니다. 이 프로젝트는 씬 관리, 스프라이트 처리, 입력 시스템 등을 포함한 다양한 기능을 제공합니다.

## 프로젝트 링크
GitHub 저장소: [Engine2D](https://github.com/REDKJW/Engine2D)

## 구조
이 엔진은 여러 개의 핵심 파일로 구성되어 있으며, 주요 역할은 다음과 같습니다:

### 핵심 파일
- **main.cpp** : 프로그램의 진입점 (WinMain 함수 포함)
- **body.cpp** : 메시지 루프가 구동되는 `body` 구조체 및 초기화 구현
- **elements_initializer.cpp** : 개별 씬에 대한 그래픽 스프라이트 배치 및 구동 함수 초기화(사용자가 직접 편집하여 사용)
- **scene_management.cpp** : 개별 씬(scene) 및 씬들을 총괄하는 씬 관리자(scene manager) 구현
- **sprite.cpp** : 단순 스프라이트 및 버튼 구현. 알파값 등 추가 예정
- **input_core.cpp** : 입력 시스템 구현

## 주요 기능
- **엔진 초기화**: `Engine2D`의 기본 환경을 설정하고 초기화하는 기능 포함
- **씬(Scene) 관리**: 여러 개의 씬을 로드하고 전환할 수 있음
- **스프라이트(Sprite) 처리**: 2D 그래픽 요소를 다룰 수 있는 기능 제공
- **입력(Input) 처리**: 키보드 및 마우스 입력을 감지하고 처리

## 빌드 방법
1. 프로젝트를 클론합니다.
   ```sh
   git clone https://github.com/REDKJW/Engine2D.git
   cd Engine2D
   ```
2. CMake 또는 직접 Makefile을 사용하여 빌드합니다.
   ```sh
   mkdir build
   cd build
   cmake ..
   make
   ```
3. 실행 파일을 실행합니다.
   ```sh
   ./Engine2D
   ```

## 더 자세한 구조는
첨부된 `Engine2D 청사진.drawio` 파일을 확인하세요.(수정 예정)

## 사용 방법
1. `elements_initializer.cpp`를 수정하여 각각의 씬을 작성할 수 있습니다.(예제 추가 예정)
3. `input_core.cpp`를 수정하여 원하는 입력 이벤트를 처리할 수 있습니다.(CONFIG를 수정하는 방식으로 변경 예정)

## 기여 방법
1. 이 저장소를 포크합니다.
2. 새로운 브랜치를 생성합니다.
   ```sh
   git checkout -b feature-branch
   ```
3. 변경 사항을 커밋합니다.
   ```sh
   git commit -m "새로운 기능 추가"
   ```
4. 원격 저장소에 푸시합니다.
   ```sh
   git push origin feature-branch
   ```
5. Pull Request를 생성합니다.

## 라이선스
이 프로젝트는 자유롭게 수정 및 배포할 수 있습니다.

## 문의
질문이나 피드백은 Issue를 생성하거나 직접 연락주세요.
