# My Frequently Forgotten Facts (FFFs)
------
## 1. Object
> 在Java中，只有基本类型（primitive types）不是对象，如 int, char, boolean。

``` java
Object obj;
obj = new String(); //ok
obj = new int[10]; //ok
```

## 2. 访问权限

### 各修饰符访问权限如下表：
|Modifier|Class|Package|Out Subclass|Other|Total|
|:--:|:--:|:--:|:--:|:--:|:--:|
|`private`|Y|N|N|N|1|
|`default`|Y|Y|N|N|2|
|`protected`|Y|Y|Y|N|3|
|`public`|Y|Y|Y|Y|4|

[See doc here.](https://docs.oracle.com/javase/tutorial/java/javaOO/accesscontrol.html)

## 3. Type[] 和 ArrayList<Type>
``` java
Type[] array = new Type[size]; //size大小
ArrayList<Type> = new ArrayList<>(); //动态增长
// In ArrayList<Type>, 'Type' can't be primitive types
```
将 `Type[]` 替换成 `ArrayList<Type>` 要注意的变化：
* 不必指出数组的大小
* 使用 `add` 将任意多的元素添加到数组中
* 使用 `size()` 替代 `length` 计算元素的数目
* 使用 `a.get(i)` 替代 `a[i]` 访问元素

## 4. 包装器类（wrappers）
包装器类（`Integer, Long, Float, Double, Short, Byte, Character, Boolean`）的对象是不可变的，一旦被构建，包装器里的值就不能被改变。
``` java
//this method won't work
public void triple (Integer i) {
    Integer j = i;
    System.out.println(i == j); //true
    i = 3 * i; //i -> a new wrapper
    System.out.println(i == j); //false
}
```

## 5. 参数数量可变的方法
``` java
public static double max(double... values) {
    double largest = Double.NEGATIVE_INFINITY;
    for (double v : values) {
        if (v > largest) {
            largest = v;
        }
    }
    return largest;
}
```
