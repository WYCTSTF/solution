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
3. 周长为24的直角三角形
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
addThree x y z = x + y + z