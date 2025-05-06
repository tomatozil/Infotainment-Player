[//]: # (Windsurf 프로젝트)
![Made with Windsurf](https://img.shields.io/badge/Made%20with-Windsurf-blueviolet)


## Infotainment Player

Raspberry Pi OS 기반의 인포테인먼트 플레이어입니다. GStreamer를 사용한 오디오 스트리밍 기능을 제공하며, QML을 통한 터치 UI로 제어가 가능합니다.

### 요구사항

- CMake 3.10 이상
- Qt 6.x
- GStreamer 1.0 이상
- Raspberry Pi OS

### 설치 및 빌드

1. 필요한 패키지 설치
```bash
# CMake 설치
brew install cmake

# Qt6 설치
brew install qt6

# GStreamer 설치
brew install gstreamer

```

2. 프로젝트 빌드
```bash
# 빌드 디렉토리 생성 및 이동
cd /path/to/infotainment-player
mkdir -p build
cd build

# CMake 실행 및 빌드
cmake ..
make
```

### 실행 방법

1. Qt 화면 테스트
```bash
# 빌드된 실행 파일 실행
./InfotainmentPlayer

# Qt 화면 테스트를 위한 환경 변수 설정
export QT_QPA_PLATFORM=eglfs  # Raspberry Pi 환경에서 사용
export QT_QPA_EGLFS_PHYSICAL_WIDTH=800  # 화면 너비 (mm)
export QT_QPA_EGLFS_PHYSICAL_HEIGHT=480  # 화면 높이 (mm)
export QT_QPA_EGLFS_WIDTH=800  # 화면 해상도
export QT_QPA_EGLFS_HEIGHT=480  # 화면 해상도
./InfotainmentPlayer
```

2. Qt 화면 테스트 방법
   - 모드 선택: 오디오/비디오 모드를 라디오 버튼으로 선택
   - URL 입력: 스트리밍 URL을 텍스트 필드에 입력
   - 재생/일시정지/정지: 버튼을 통해 제어
   - 볼륨 조절: 슬라이더를 통해 조절
   - 상태 표시: 현재 재생 상태 표시

### 지원되는 기능

- 오디오 스트리밍 (GStreamer)
  - 실시간 오디오 스트리밍 재생
  - 볼륨 조절
  - 재생/일시정지/정지

- 터치 UI
  - 직관적인 터치 조작 인터페이스
  - 모드 전환 (오디오/비디오)
  - 상태 표시 (재생 중/일시정지)

### 오류 해결

1. 화면이 표시되지 않는 경우
```bash
export QT_QPA_PLATFORM=eglfs
export QT_QPA_EGLFS_KMS_CONFIG=/path/to/kms_config.json
```

2. 오디오 출력 문제
```bash
export GST_DEBUG=*:3
```


## GStreamer Pipeline

playbin

 └── uridecodebin → decodebin → audioconvert/videoconvert → sink

### 학습 포인트

- 빌드 시스템 설계   
CMake를 통해 모듈·라이브러리 탐색 및 링크

- 미디어 스트리밍 구조   
GStreamer 파이프라인 생성·제어

- 리소스 생명주기 관리   
초기화→사용→정리(cleanup)까지 안전한 객체 관리

- UI와 비즈니스 로직 분리   
Qt/QML 뷰와 C++ 스트리머 클래스 간에 시그널/슬롯으로 역할을 분리하는 아키텍처

- 임베디드 플랫폼 고려사항   
Raspberry Pi 환경에서의 런타임 설정

### 앞으로 할 것

- 하드웨어 가속 및 경량화 전략  
  Raspberry Pi에서 성능 최적화를 위한 구체적 방안 연구