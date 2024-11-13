#ifndef ITER_HPP
#define ITER_HPP

template<typename T> void iter(T* array, unsigned long len, void (*fct)(T& elem));
template<typename T> void iter(T* array, unsigned long len, void (*fct)(const T& elem));

#endif // !ITER_HPP
