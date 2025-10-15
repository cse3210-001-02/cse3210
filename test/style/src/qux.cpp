// LINT: [include의 이름과 순서] clang-format에 따른 include
#include "foo/bar/qux.h" // 구현 파일 헤더

#include <stdio.h>  // C 헤더
#include <iostream> // C++ 헤더
#include <map>
#include <vector> // C++ 헤더

#include "foo/bar/baz.h"  // 사용자 정의 헤더
#include "foo/bar/quux.h" // 사용자 정의 헤더

int global_variable = 1;

// LINT: [상수 이름]
[[maybe_unused]] int const kMaxValue = 100;
[[maybe_unused]] int const MaxValue = 100;

// LINT: [타입 이름] class
class urlTable {};
// LINT: [타입 이름] struct
struct urlTableTester {};
// LINT: [타입 이름] typedef
typedef std::map<void *, std::string> propertiesMap;
// LINT: [타입 이름] enum
enum urlTableErrors {
  // LINT: [열거형 이름]
  UrlTableOk,
  urlTableNotFound,
  kUrlTableCorrupt
};

struct MyStruct {
  [[maybe_unused]] int myVar;
  [[maybe_unused]] int my_var;
  [[maybe_unused]] int my_var_;
};

class MyClass {
public:
  // TODO: 접근 제어
  int public_class_var;

private:
  [[maybe_unused]] int myVar;
  [[maybe_unused]] int my_var;
  [[maybe_unused]] int my_var_;
};

// LINT: [일반 함수]
void MyFunc();
void my_func();

int main() {
  // LINT: [변수 이름] 공통 사항
  [[maybe_unused]] int myVar = 10;
  int my_var = 10;

  // LINT: [형 변환] C 스타일 형 변환 사용
  [[maybe_unused]] float f1 = (float)my_var;
  // LINT: [형 변환] C 스타일 형 변환 사용
  [[maybe_unused]] float f2 = float(my_var);
  // LINT: [형 변환] C++ 스타일 형 변환 사용 권장
  [[maybe_unused]] float f3 = static_cast<float>(my_var);

  // LINT: [수식에 관한 규칙] 단항 연산자
  my_var++;
  // LINT: [수식에 관한 규칙] 이항 연산자
  int i1 = my_var + 1;

  // LINT: [Switch 문에 관한 규칙]
  switch (i1) {
  case 1:
    std::cout << "One\n";
    break;
  case 5:
    std::cout << "Five\n";
    break;
  }

  return 0;
}
