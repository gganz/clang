// RUN: %clang -ccc-host-triple x86_64-apple-darwin10 -S -o %t.s -mkernel -Xclang -verify %s

// rdar://problem/9143356

int foo();
void test() {
  static int y = 0;
  static int x = foo(); // expected-error {{this initialization requires a guard variable, which the kernel does not support}}
}
