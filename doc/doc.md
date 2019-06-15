#### 模板的两段式编译

1. without instantiation at **definition time**, the template code itself is checked for correctness ignoring the template parameters, This includes:

   * Syntax errors are discovered, such as missing semicolons;

   * Using unknown names that don't depend on template parameters are discovered;

   * Static assertions that don't depend on template parameters are checked.

2. At **instantiation time**, the template code is checked to ensure that all code is valid. That is, now especially, all parts that depend on template parameters are double-check.

#### 模板的编译和链接

模板的两段式编译导致了一个重要的问题：当模板由于被使用而进行实例化时，编译器需要看到该模板的完整定义。

#### 类型推断时的类型转换

Automatic type conversions are limited during type deduction:

* 当参数是被传引用时，任何的类型转换都不会发生。Two arguments declared with the same template parameter T must match exactly.

* 当所有的参数被传值时，只有一些简单的退化会发生。

  1. const 和 volatile 被忽略掉。

  2. 引用转换为引用类型。

  3. 数组和函数被转换为相应的指针。

   For two arguments declared with the same template parameter T the decayed types must match.(退化类型必须一致)

#### 缺省的类型参数

为了支持缺省的类型参数，我们必须为模板类型参数提供一个缺省的类型。

```C++
template<typename T = std::string>
void foo(T = ""){
     ...
}
```

#### 返回类型的处理

1. 引入其它的模板参数作为返回类型，如

   ```C++
   template<typename RT, typename T1, typename T2>
   RT max(T1 a, T2 b){
       ...
   }
   // 调用时指定返回类型
   ::max<double>(1, 2.3);
   ```

2. 推导返回类型

   ```C++
   // C++14的方法
   tempate <typename T1, typename T2>
   auto max(T1 a, T2 b){
      return b < a ? a : b;
   }
   // C++11的方法
   template<typename T1, typename T2>
   auto max(T1 a, T2 b) -> typename decay<decltype(b < a ? a : b)>::type {
      return b < a ? a : b;
   }
   ```

3. 返回一个兼容类型(common type)

   ```C++
   tempalte<typename T1, typename T2>
   std::common_type_t<T1, T2> max(T1 a, T2 b){
       return b < a ? a : b;
   }
   ```

#### 缺省的模板参数2

You can define default values for template parameters. 这些值叫做缺省的模板参数，这些值甚至可以是模板前面的类型参数。

```C++
tempate<typename T1, typename T2, 
        typename RT = std::decay_t<decltype(true ? T1{} : T2{})>>
RT max(T1 a, T2 b){
    return b < a ? a : b;
}
```

对于上面的返回类型，**最好的就是让编译器自己去推导。**

#### 模板函数重载

在所有的因素都相同时，倾向于优先使用非模板函数，然后再进行模板函数。然而如果模板可以进行更好的匹配，则使用模板函数。