-- 单行注释

{--
  多行注释
--}

doubleMe x = x + x

doubleUs x y = doubleMe x + doubleMe y

doubleSmallNumber x =
  if x > 100
    then x
    else x * 2

{-- Haskell中的if else是固定格式

  即你必须给出一个函数明确的定义

  而非可以忽略的过程

--}

doubleSmallNumber' x = (if x > 100 then x else x * 2) + 1

-- 这里如果去掉() 那么+1只会对else生效

-- 函数名首字母不允许大写，通常我们用'在结尾以区分两个差别不大的函数

conanO'Briden = "It's a-me, Conan O'Briden!"

-- 没有参数的函数通常被称作“定义”，一旦定义，就直接等价，且不可修改

------------------------------

-- List是一种常用数据结构，其中元素类型必须相同

{--

合并List使用 `++` 运算子，但是使用 `++` 会遍历整个List（操作符左边那个）

所以可以用`：`运算子在List前端插入元素

用 `!!`按索引拿到List中的元素，下标从 0 开始

List可以装List，List的List，在我看来就是一个n维的向量，即把矩阵作为元素

List可以按字典序比较大小

head返回一个List的头部，首个元素，tail返回尾部，即去头剩下的子List

last返回一个List的最后一个元素，init返回去掉最后一个元素的子List

length返回一个List的长度

null检查一个List是否为空

reverse反转一个List

take x [] 返回一个List前x个元素，如果x超过 List大小，则会整个截取
如果是0，则得到空List

drop x [] 用法一样，返回一个删除前x个元素的List

minimum [] \ maximum [] 返回最小值 \ 最大值

sum [] \ product [] 返回一个List的和 \ 积

elem 判断一个元素是否包含于一个List，通常以中缀函数的形式调用它

4 `elem` [3,4,5,6]
--}

-- Range中的浮点数是不精确的
a = take 20 [0.1, 0.3 ..]

-- 字符串就是字符构成的List
chara = take 12 (cycle ['L', 'O', 'L', ' '])

chara' = take 12 (cycle "LOL ")

-- repeat 接受一个值作参数，并返回一个仅包含该值的无限 List
-- 这与用 cycle 处理单元素 List 差不多，当然这个值可以是一个列表
chara'' = take 12 (repeat 5) -- 等价于replicate 12 5

chara''' = replicate 12 [1, 2, 3]

{------------------------------------------

---------- List Comprehension  ------------

------------------------------------------}

-- 高一数学的必修就教过 Set Comprehension 可以从现有的集合按照规则产生一个新集合
-- 同样适用于List这一结构

listComprehensionExample = [x * 2 | x <- [1 .. 10]]

-- 限制条件 predicate 由逗号分隔

lce0 = [x * 2 | x <- [1 .. 10], x * 2 >= 12]

lce1 = [x | x <- [50, 51 .. 100], x `mod` 7 == 3]

-- 从一个 List 中筛选出符合特定predicate的操作称为filtering 过滤

-- 假如我们想要一个 comprehension，它能够使 List 中所有大于 10 的奇数变为 "BANG"
-- 小于 10 的奇数变为 "BOOM"，其他则统统扔掉

-- odd 函数判断是否为奇数从而返回 True 或 False
boomBangs xs = [if x < 10 then "BOOM!" else "BANG!" | x <- xs, odd x]

-- 多个限制条件 \ Haskell中不等于的符号是 /=
-- 自制一个函数 参数为一个 integer 列表，返回所有 mod 3 不为 0 的数
clear3 xx = [x | x <- xx, x `mod` 3 /= 0]

-- 在不过滤的前提 下
-- 取自两个长度为 4 的集合的 comprehension 会产生一个长度为 16 的 List。
-- 以 Integer 为例
comb = [x * y | x <- [2, 5, 10], y <- [8, 10, 11], x * y > 50]

-- ghci> let nouns = ["hobo","frog","pope"]
-- ghci> let adjectives = ["lazy","grouchy","scheming"]
-- ghci> [adjective ++ " " ++ noun | adjective <- adjectives, noun <- nouns]

-- ["lazy hobo","lazy frog","lazy pope","grouchy hobo","grouchy frog",
-- "grouchy pope","scheming hobo","scheming frog","scheming pope"]

mylength xs = sum [1 | _ <- xs]

-- 对字符同样适用

getUpper xs = [c | c <- xs, c `elem` ['A' .. 'Z']]

-- 使用嵌套的 List Comprehension 完成一些 miraculously work.

-- ghci> let xxs = [[1,3,5,2,2,4],[1,2,3,4,5],[1,2,3,4,512]]
-- ghci> [[x | x <- xs, even x] | xs <- xxs]

ans n m = sum [if gcd x y == 1 then 1 else 0 | x <- [1 .. n - 1], y <- [1 .. m - 1]] + 2

-- \sum \sum_{j=1}^{i=1}

-- Haskell 没有循环
-- 下例: 我自己想的怎么算 (1 + (1 + 2) + (1 + 2 + 3) + ... + (1 + .. + n))
-- 如果C/C++的话 for (int i = 1; i <= n; i++) 不用看都已经写好了
ans' n = sum [x * (n + 1 - x) | x <- [1 .. n]]

{------------------------------------------

-----------------  Tuple  -----------------

------------------------------------------}

-- 元祖长度和每列的类型必须固定

-- fst 返回二元祖 (序对) 的首项，snd 返回尾项

-- 使用 zip 组合两个列表产生元祖，元祖个数取决于短的那个列表长度

pair1 = zip [5, 3, 2, 6, 2, 7, 2, 5, 4, 6, 6] ["im", "a", "turtle"]

{-- 简单习题 找直角三角形
1. 三边长为整数
2. 三边长度都小于等于10
3. 周长为24的直角三角形ƒ
--}

rightTriangles = [(x,y,z) | z <- [1..10], y <- [1..z], x <- [1..y], x^2 + y^2 == z^2, x+y+z == 24]

{-----------------------

        Type - 类型

-----------------------}

-- :t 命令可以检查类型

removeNonUppercase :: [Char] -> [Char]
-- 从它的参数和返回值可以看出是一个字符串映射成另一个字符串
removeNonUppercase st = [c | c <- st, c `elem` ['A' .. 'Z']]

-- 分隔参数也是 ->
addThree :: Int -> Int -> Int -> Int
addThree x y z=x+y+z

-- factorial :: Int -> Int 如果启用这个声明，就会溢出成傻逼，因为这个范围是-2147483648 ~ 2147483647
factorial :: Integer -> Integer -- 而 Integer 无上限，不过效率要低
factorial n = product [1..n]

circumference :: Float -> Float -- 双精度
circumference r = 2 * pi * r

circumference' :: Double -> Double -- 双精度
circumference' r = 2 * pi * r

{-------------------------------
-------  Type Variables  -------
-------------------------------}

-- head 的类型为 :: [a] -> a
-- 其中 a 是一个类型变量，并不指示任何具体类型
-- 有点像 c++ 里的泛型？

-- ghci> :t (==)
-- (==) :: (Eq a) => a -> a -> Bool

-- 判断 == 是一个中缀函数，还有一些运算符号也是如此
-- 如果要检查他的类型 就要用（）括起来令他作为另一个函数

{-------------------------------
---------  Type class ----------
-------------------------------}

-- => 符号左边的部分叫做 型别约束 Typeclass
-- 可以看做 java 中的 interface 或者 C++ 中的 template class?
-- 后者是个人理解，事实上我对C++的模版是一点也不了解

-- 理解成实例为类型的 interface 还是可以的

-- Eq 这一 Typeclass 提供了判断相等性的接口，凡是可以比较相等性的型别必属于 Eq class
-- elem 函数的型别为 (Eq a) => a -> [a] -> Bool
-- 因为检测是否存在于 List 的过程中用到了 ==

-- 几个基本的 Typeclass

-- Eq class
-- 提供了 == 和 /= 所以只要有一个函数有 Eq 的型别限制，那么一定在定义里用到了 == 和 /=
-- 除函数以外的所有型别都属于 Eq，因此都可以判断相等性

-- Ord class
-- 包含 `<,>,<=,>=` 之类用于比较大小的函数
-- `compare` 函数取两个 Ord 类中的相同型别的值作参数返回一个 Ordering 类型的值
-- Ordering 类型有 GT EQ LT 三种值 分别表示 大于 等于 小于

-- 型别如果属于 Ord 显然必先属于 Eq

-- 感觉模版这东西和 List Comprehension + predicate 没差多少
-- 纯纯的一个集合 + 集合操作

-- Show class
-- 目前为止，除函数以外的所有类型都是 Show class 的实例
-- 操作 Show 类型类的实例的函数中，最常用的是 show
-- show :: (Show a) => a -> String
-- 没错，show 甚至可以把 String 类型转换成 String 类型

-- Read class
-- 可以看做与 Show 相反的 Typeclass
-- read 函数
-- read :: (Read a) => String -> a
-- 但是一个 read "4" 是ambiguous的 从 constraints 中也可见一斑，a 是一个Type variable，必须直接指定实例的具体类型、型别或者通过后接的操作间接的推导类型
-- 对于直接指示类型，我们使用 类型注解
-- ghci> read "5" :: Int
-- ghci> read "(3, 'a')" :: (Int, Char)

-- Enum class
-- Enum 的实例类型都是有连续顺序的，它们的值都是可以枚举的
-- 每个值都有相应的后继(successer)和前趋(predecesor) 可以用 succ 和 pred 函数得到

-- Bounded class
-- 实例都有一个上限和下限，分别用 maxBound 和 minBound 函数得到
-- ghci> minBound :: Int
-- -2147483648
-- ghci> maxBound :: Char
-- '\1114111'
-- ghci> minBound :: Bool
-- False
-- 这两个函数的类型都是 (Bounded a) => a 可以说这两个函数都是多态常量
-- 如果元组中项的类型都属于 Bounded 类型类的实例，那么这个元组也属于 Bounded 的实例了

-- Num class
-- 它的实例类型都有数的特征
-- ghci> :t 20
-- 20 :: (Num t) => t
-- ghci> :t (*)
-- (*) :: (Num a) => a -> a -> a
-- 可以看到乘号两边的类型必须相同，故这里的 Type 应当属于 Show 和 Eq

-- Floating class
-- 仅包含 Float 和 Double 两种浮点类型
-- 某些函数 如 sin \ cos \ sqrt

-- Integeral class
-- 实例类型有 Int 和 Integer
-- 有个函数十分实用 fromIntegeral
-- fromIntegeral :: (Integeral a, Num b) => a -> b
-- 注意到用了多个类型约束，这是合法的，用逗号隔开即可
-- 通过签名可以看出 fromIntegeral函数取一个整数作为参数并返回一个更加通用的数值
-- 例如对于 length :: [a] -> Int ，取了一个列表长度之后给他加上一个浮点数，就会寄掉
-- ghci> fromIntegeral (length [1,2,3,4]) + 3.2
-- 7.2

-- 有时，属于一个 Typeclass 会是属于另一个 Typeclass 的先决条件 prerequisite


{-----------------------------------------------
------------------------------------------------

--------------  第三章 函数的语法  ----------------

------------------------------------------------
-----------------------------------------------}

------------------   模式匹配   -----------------

-- 模式匹配用来避免大块的if else链

lucky :: Int -> String
lucky 7 = "Lucky Number Seven"
lucky x = "Sorry, you're out of luck, pal!"

-- 模式匹配将会按照从上到下的顺序检查

-- 利用模式匹配写出第一个 Haskell 的递归函数
factorial' :: Integer -> Integer
factorial' 0 = 1
factorial' n = n * factorial' (n-1)

-- 模式匹配可能会失败
charName :: Char -> String
charName 'a' = "Albert"
charName 'b' = "Broseph"
charName 'c' = "Cecil"
-- Non-exhaustive patterns in function.

-- 元组的模式匹配
-- 计算二维空间中的向量(以序对的形式表示)的和
addVectors :: (Double, Double) -> (Double, Double) -> (Double, Double)
-- addVectors a b = (fst a + fst b, snd a + snd b)
-- 如果用模式匹配
addVectors (x1, y1) (x2, y2) = (x1 + x2, y1 + y2)
-- 主要是突出一点：模式匹配检查特定的结构


first' :: (a, b, c) -> a
first' (x, _, _) = x
-- 泛变量 generic variable _
-- 这个貌似可以重复，换成别的就不行
-- 可能特指那些不受重视的元素
second' :: (a, b, c) -> b;
second' (_, y, _) = y;
third :: (a, b, c) -> c;
third (_, _, z) = z

------   哨卫   ----------
-- 一个哨卫就是一个布尔表达式

bmiTell :: Double -> String
bmiTell bmi
  | bmi <= 18.5 = "You' re underweight, you emo, you!"
  | bmi <= 25.0 = "You' re supposeedly normal. Pffft, I bet you're ugly!"
  | bmi <= 30.0 = "You' re fat! Lose some weight, fatty!"
-- | otherwise = "FF" 如果去掉之后，下一行的模式匹配就是 redundant 的
bmiTell _ = "Fuck you" -- 如果所有哨卫都不匹配并且不具备 otherwise

max' :: (Ord a) => a -> a -> a
max' a b
  | a < b = b
  | otherwise = a

myCompare :: (Ord a) => a -> a -> Ordering
a `myCompare` b
  | a == b = EQ
  | a <= b = LT
  | otherwise = GT


-- 观察如下例子
-- bmiTell' :: Double -> Double -> String
-- bmiTell' weight height
--   | weight / height ^ 2 <= 18.5 = "you' re underweight."
--   | weight / height ^ 2 <= 25.0 = "you' re normal."
--   | weight / height ^ 2 <= 30.0 = "you' re fat."
--   | otherwise = "you' re a whale"
-- 显然这个例子里面，weight / height ^ 2 是个很让人恼火的玩意儿
-- 因此我们可以使用 where
-- 直接上一个激进的修改
bmiTell' :: Double -> Double -> String
bmiTell' weight height
  | bmi <= skinny = "you' re underweight"
  | bmi <= normal = "you' re normal"
  | bmi <= fat    = "you' re fat"
  | otherwise     = "you' re a whale."
  where bmi = weight / height ^ 2
        -- skinny = 18.5
        -- normal = 25.0
        -- fat = 30.0
        -- where 中可以使用模式匹配
        (skinny, normal, fat) = (18.5, 25.0, 30.0)
        -- where 绑定中的模式匹配，从某方面来讲我觉得有些过于人性化、数学化了

-- 注意其中的变量定义必须对其在同一列 这样 Haskell 才能明确其所在的代码块

-- where 部分定义的名字只对本函数可见
-- 因此如果想要重复使用 则应当放在全局中

-- 来看一个失败的案例

-- greet :: String -> String
-- greet "Juan" = niceGreeting ++ " Juan!"
-- greet "Fernando" = niceGreeting ++ " Fernando!"
-- greet name = badGreeting ++ " " ++ name
--       where niceGreeting = "Hello! So vrey nice to see you,"
--             badGreeting = "Oh! Pfft. It's you."

-- 可以交换两行 where 的顺序 发现 " Juan" \ "Fernando" \ name 会分别报错
-- 因为 where 定义的名字只有最后一个模式可用

-- 因此在这里我们需要全局定义
badGreeting :: String
badGreeting = "balabala"

niceGreeting :: String
niceGreeting = "balala"

-- 一个简单函数 告诉我们姓名的首字母 运用 where 中的模式匹配
initials :: String -> String -> String
initials firstname lastname = [f] ++ ". "++[l] ++ "."
  where (f:_) = firstname
        (l:_) = lastname

------------------------------------
------ 在 where 块中定义函数  --------
------------------------------------

calcBmis :: [(Double, Double)] -> [Double]
calcBmis xs = [bmi w h | (w, h) <- xs]
  where bmi weight height = weight / height ^ 2
  -- 可以看到这里 where 中的 bmi 是一个函数

-- 到这里为止 我们尝试使用不变形的方法计算 (1 + (1 + 2) + .. + (1 + .. + n))
-- 我决定使用递归去做
calc1 :: Integer -> Integer
calc1 1 = 1
calc1 n = sum [1 .. n] + calc1 (n-1)

-- 除此以外，是否能用 where 完成这件事情

calc2 :: Int -> Int
calc2 n = sum [sum xs | xs <- [[1 .. i] | i <- [1 .. n]]]

-- 到现在算是理解 List Comprehension 了...
cylinder :: Double -> Double -> Double
cylinder r h =
    let sideArea = 2 * pi * r * h
        topArea = pi * r ^ 2
    in sideArea + topArea

-------------------------------------------
-----------------  3.4 let  ---------------
-------------------------------------------

-- let <bindings> in <expressions>
-- let 中绑定的名字仅对 in 中的表达式可见
-- ghci> 4 * (let a = 9 in a + 1) +2
-- 42
-- let 表达式类似于 where 绑定
-- where 可以在函数底部绑定 变量 或者 函数，支持模式匹配 对整个函数包括哨卫在内的内容可见
-- let 则是一个表达式 允许在任何位置定义局部变量 并且不对别的哨卫可见

-- ghci> [let square x = x * x in (square 5, square 3, square 2)]
-- [25, 9, 4]

-- 需要在一行中绑定多个名字时，可以用分号隔开
-- ghci> (let a = 100; b = 200; c = 300 in a * b * c, let foo = "Hey "; bar = "there!" in foo ++ bar)
-- (6000000, "Hey there!")

-- ghci> (let (a,b,c) == (1,,2,3) in a+b+c) * 100
-- 600

-- calcBmis xs = [bmi wh | (w,h) <- xs]
--  where bmi weight height = weight / height ^ 2
-- 可以改写成

-- 列表推导式中的 let
-- calcBmis xs = [bmi | (w, h) <- xs, let bmi = w / h ^ 2]
-- Haskell是说话的艺术，不在乎底层怎么实现，而是数据的表述方式
-- List comprehension 中的 (w, h) <- xs 被称为生成器(generator)
-- 生成器中不能饮用 bmi 变量，因为他在 let 绑定之前定义 ｜ 是句废话

------------------------------------------------------
--------------------  3.5 case 表达式 -----------------
------------------------------------------------------

-- 两段等价代码
-- head' :: [a] -> a
-- head' [] = error "No head for empty lists!"
-- head' (x:_) = x
-- 还记得这里的括号不表示元组，而是将绑定多个变量的一种格式，不产生语义歧义
head' :: [a] -> a
head' xs = case xs of []    -> error "No head for empty lists"
                      (x:_) -> x

-- case 的语法
-- case expression of pattern -> result
--                    pattern -> result
--                    ...


-- 一直到最后没有匹配的模式就会产生一个运行时错误

-- 函数参数的模式匹配只能在定义函数的时候使用，但是 case 表达式的模式匹配可以在任何地方使用
-- 简单讲，参数的模式匹配 对象 限定参数 而 case 的 对象 是任何你想要操作的东西

describeList :: [a] -> String
describeList ls = "The list is " ++ case ls of []    -> "empty"
                                               [x]   -> "a singleton list."
                                               (x:_) -> "a longer list"
                                    -- 或者写成 xs -> "a longer list."
                                    -- 事实上这个 xs 匹配了所有的东西

-- 函数定义中的模式匹配也就是 case 的语法糖
describelist' :: [a] -> String
describelist' ls = "The list is " ++ what ls
  where what []  = "..."
        what [x] = "a singleton list"
        what xs  = "a longer list"

-- 这里可以看到 where 中定义的 what 函数又是由参数模式匹配写出来的
-- 自然 what 也可以用 case 表示

  -- where what ls = case ls of []    -> "empty"
  --                            [x]   -> "a singleton list"
  --                            (x:_) -> "a longger list"


{-----------------------------------------------
------------------------------------------------

-----------------  第四章 递归  ------------------

------------------------------------------------
-----------------------------------------------}

maximum' :: (Ord a) => [a] -> a
maximum' [] = error "maximum of empty list"
maximum' [x] = x
maximum' (x:xs) = max x (maximum' xs)

-- 尝试写出自己的replicate
replicate' :: Int -> a -> [a]
-- 发现如果用模式匹配会不是很好写
-- 对于 case 或者 let 也是
-- 因为这里考察的不是一个表达式 或者 匹配，而是判断一个边界，需要哨卫判断条件

-- 到这里我才算理解参数要检查的就两种，一个是参数结构，一个是参数性质，即内容
replicate' n x
  | n <= 0 = []
  | otherwise = x : replicate' (n-1) x


-- Take 函数有两个边界条件
-- 1. n <= 0 返回空列表
-- 2. 取空列表 返回 空列表
take' :: (Num i, Ord i) => i -> [a] -> [a]
take' n _
  | n <= 0 = [] -- 在之前演示过，如果一个哨卫不使用otherwise 那么在 n > 0 的时候就会进入下一个模式
take' _ [] = []
take' n (x:xs) = x : take' (n-1) xs

reverse' :: [a] -> [a]
reverse' [] = []
reverse' (x:xs) = reverse' xs ++ [x]

-- 这一个函数直接给我干懵了 别的过程式语言绝不可能写的如此狂野
repeat' :: a -> [a]
repeat' x = x : repeat' x

zip' :: [a] -> [b] -> [(a,b)]
zip' _ [] = []
zip' [] _ = []
zip' (x:xs) (y:ys) = (x,y) : zip' xs ys -- 如此的自然！

elem' :: (Eq a) => a -> [a] -> Bool
elem' a [] = False
elem' a (x:xs)
  | a == x = True
  | otherwise = a `elem'` xs

-- 最终递归：快排
quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (x:xs) =
  let smallerOrEqual = [a | a <- xs, a <= x]
      larger = [a | a <- xs, a > x]
  in quicksort smallerOrEqual ++ [x] ++ quicksort larger
-- 太离谱了 \ 不过如此

{-----------------------------------------------
------------------------------------------------

---------------  第五章 高阶函数  ----------------

------------------------------------------------
-----------------------------------------------}

-- 5.1 柯里函数

-- 所有的多参数函数都是柯里函数，柯里函数不会一次性取完所有参数，而是在每次调用时取一个参数，并返回一个一元函数来取下一个参数，以此类推
-- ghci> :t max
-- max :: (Ord a) => a -> a -> a
-- 上面的声明也可以写成 max :: (Ord a) => a -> (a -> a)
-- 也就是取一个类型为 a 的值作为参数，返回一个函数，这个函数取类型为 a 的值作为参数，返回类型为 a 的值
-- 这样的好处是，我们传入部分参数，就可以得到一个部分应用的函数 (partial application)
-- 部分应用使得构造新函数简便快捷，随时可以传递给其他函数去构造新函数

multiThree :: Int -> (Int -> (Int -> Int))
multiThree x y z = x * y * z

-- 一个例子，以少数参数调用函数来创建新函数
-- ghci> let multTwoWithNine = multiThree 9
-- ghci> mulTwoWithNine 2 3
-- 54

compareWithHundred :: Int -> Ordering
-- compareWithHundred n = n `compare` 100 这是之前的写法
compareWithHundred = compare 100

-- 发现想要 100 放在前去比较 直接写 compareWithHundred = 100 `comare` 是不行的
-- 原因是中缀函数需要 截断 (section) 才能进行部分应用 这步加上一个()就可以实现
-- compareHundredWith = (100 `compare`)
-- 加减乘除等二元运算也是如此 当然 为了区分 负数，如果需要减法，应当使用 subtract 函数

