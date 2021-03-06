// RUN: %clang_cc1 -fsyntax-only -verify -std=c++11 %s

struct S {
  int *j = &nonexistent; // expected-error {{use of undeclared identifier 'nonexistent'}}
  int *m = &n; // ok

  int n = f(); // ok
  int f();
};

int i = sizeof(S::m); // ok
int j = sizeof(S::m + 42); // ok


struct T {
  int n;
  static void f() {
    int a[n]; // expected-error {{invalid use of member 'n' in static member function}}
    int b[sizeof n]; // ok
  }
};
