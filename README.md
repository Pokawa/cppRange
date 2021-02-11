# cppRange

python style range class to be used in range based for loops

```cpp
for (auto a : Range(0, 7, 3)) {
    std::cout << a << " ";
}
```
OUTPUT: 0 3 6

```cpp
for (auto a : Range(-0.5, 1.5, 0.45)) {
    std::cout << a << " ";
}
```
OUTPUT: -0.5 -0.05 0.4 0.85 1.3

```cpp
std::vector<int> l = {1,2,3,4,5,6,7,8,9};
for (auto a : Range(l.begin(), l.end(), 3)) {
    std::cout << *a << " ";
}
```
OUTPUT: 1 4 7
