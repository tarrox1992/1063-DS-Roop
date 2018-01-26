___1)___
```cpp
   int a[] = {25, -3, 6, 0, -3, 6};
   
   int n = a[1];
```

```cpp
n = -3
```

___2)___
```cpp
  int n = 0;
  for (int i=0; i<6; i++) {
    if (a[i] < 0) {
      n++;
    }
  }
```

```cpp
n = 2
```

___3)___
```cpp
  int n;
  for (int i=0; i<6; i++) {
    a[i] = a[i]+1;
  }
  n = a[2];
```

```cpp
n = 7
```

___4)___
```cpp
  int n = 0;
  for (int i=0; i<5; i++) {
    for (int j=i+1; j<6; j++) {
      if (a[i] == a[j]) {
         n++;
      }
    }
  }
````

```cpp
n = 2
```

___5)___
```cpp
n = a[3]+1;
```

```cpp
n = 1
```

___6)___
```cpp
n = a[3+1];
```

```cpp
n = -3
```

___7)___
```cpp
n = a[3+1]+1;
```

```cpp
n = -2
```


___8)___
```cpp
n = a[3+1]+a[1];
```

```cpp
n = -6
```

___9)___
```cpp
What does the array look like after the following:

a[3+1] = a[3]+1;
```

```cpp
a = 25, -3, 6, 0, 1, 6
```

___10)___
```cpp
a[3] = a[3]+a[1+3]*2;
```

```cpp
a = -6
```   
