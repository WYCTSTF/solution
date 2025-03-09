clangd 发送代码给 clang ，实时分析返回的结果，提供语义分析/语法补全/代码高亮，

编辑器 -> clangd -> clang -> (Apple SDK) -> IR -> lld -> arm asm -> executable file

内建类型找不到 宏找不到，sdk，这一问题发生在 clang为前端的部分。考虑解决clang配置，提供给它一个参数

-isysroot .../sdk

-I/Users/syh/llvm18.1.8/include

env clang -v