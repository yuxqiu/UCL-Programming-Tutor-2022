class Base {
public:
  virtual ~Base() = default;

  // what's the meaning of =0?
  virtual void f() = 0;
};

class Derived final : public Base {
public:
  // final keyword
  ~Derived() final = default;

  // override keyword
  void f() override;
};

int main(void) {
  Derived d;

  //   Base class pointer to d
  Base *p = &d;
  //   Base class reference to d
  Base &r = d;

  //   NRW since C++17
  //   suppress the warning of unused variables
  (void)(p);
  (void)(r);

  //   given a base class pointer
  //   we probably need to cast it back to the original type
  //   we could use dynamic casting
  Derived *dptr = dynamic_cast<Derived *>(p);
  (void)(dptr);

  //   We could also use dynamic cast
  Derived *dptr_static = static_cast<Derived *>(p);
  (void)(dptr_static);

  //   And there are two other castings: const_cast, reinterpret_cast
  //   There are some differences between them.

  return 0;
}