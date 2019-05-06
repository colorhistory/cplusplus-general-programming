#include <iostream>

template <typename T>
class Person {
  public:
    Person(T idValue, T ageValue);

    T getId() const;
    void setId(const T &value);

    T getAge() const;
    void setAge(const T &value);

  private:
    T id;
    T age;
};

template <typename T>
Person<T>::Person(T idValue, T ageValue) {
    this->id = idValue;
    this->age = ageValue;
}

template <typename T>
T Person<T>::getId() const {
    return id;
}

template <typename T>
void Person<T>::setId(const T &value) {
    id = value;
}

template <typename T>
T Person<T>::getAge() const {
    return age;
}

template <typename T>
void Person<T>::setAge(const T &value) {
    age = value;
}

int main(int argc, char *argv[]) {
    Person<double> person(12.3, 23.4);
    std::cout << person.getId() << std::endl;
    std::cout << person.getAge() << std::endl;
    return 0;
}
