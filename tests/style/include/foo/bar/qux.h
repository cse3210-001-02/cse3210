// LINT: [#define 가드] Header Guard 밖에 코드가 있는 경우
int BeforeHeaderGuard();

#ifndef FOO_BAR_QUX_H_
#define FOO_BAR_QUX_H_

#endif

int AfterHeaderGuard();
