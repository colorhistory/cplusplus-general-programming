#### Perfect Forwarding

1. **X&&** for a specific type X declares a parameter to be  an rvalue reference. It can only be bound to a movable object(如一个临时对象或者一个以std::move()传递的对象)。参数的值总是可以被修改的，我们可以从中偷值。
2. **T&&** for a template parameter T declares a *forwarding reference*。It can be bound to (可被修改对象，常量对象，或者可被移动对象)

#### Enable_if

std::enable_if<> is a type trait that evaluates a given compile-time expression passed as its (first) template argument and behaves as follows:

1. 如果表达式产生true，则它的类型成员类型产生一种类型。

   * 如果没有第二个参数，则产生空类型void.

   * 如果有第二个参数，则以第二个参数的类型作为类型。

2. 如果表达式产生false，则它成员类型则是未定义的。实例化失败，但是并不是错误。