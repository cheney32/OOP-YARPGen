## OOP-YARPGen

基于随机程序生成器 YARPGen进行扩展，提供以下特性

- 结构体
- 面向对象
- 指针、动态内存分配
- 赋值关键词 (const, static等)
- 函数注入



### 一、安装与部署

安装 `yaml-cpp` 库
```
sudo apt-get install libyaml-cpp-dev
```

在项目根目录执行如下指令：

创建 `build` 文件夹

```
mkdir build
cd build
```

编译

```
cmake ..
make
```

执行成功后，产生名为 `yarpgen` 的文件，即可执行文件

```
./yarpgen
```

 生成的 `test.cpp` 即测试程序



### 二、测试脚本

测试脚本位于 `/runner` 路径下

#### 1、默认测试

通过执行如下命令，进行默认测试

```
python3 __main__.py
```

脚本会生成大量测试用例，并进行编译和运行。

在项目根目录的 `/Testing` 路径下，会产生一个名为测试时间的文件夹，其中：

- `/backup` 存放着可能存在bug的测试用例
- `/cases` 存放所有测试用例
- `/log` 存放所有测试日志信息



#### 2、自定义测试

通过 `/runner/default.yaml` 可以自定义测试规模

- `language`：一般无需改动
- `generator_path`：指 OOP-YARPGen 的可执行文件路径
- `testing_path`：测试文件夹路径，用于存放测试用例和日志
- `timeout`：编译的超时时间（以秒为单位）
- `run_count`：每次脚本生成的测试用例数量



#### 3、函数注入设置

- `func_zip_path`：用户提供的函数 zip 包的路径
- `func_total`：函数 zip 包中函数的总数



在 `/runner` 路径中，自带的函数 zip 库如下：

- `functions.zip` ：稳定的函数注入库（默认）
- `functions_all.zip`  ：包含指针参数的全量函数注入库



#### 4、编译器设置

- compiler：用户指定的编译器列表
- optimization：用户指定的优化选项列表
- extra_option：用户指定的额外编译选项列表
- march：用户指定的架构列表



### 三、函数注入功能

#### 1、原理

在运行时，OOP-YARPGen 会自动从函数 zip 库中随机挑选一个函数，注入到测试用例中。

函数 zip 库中全部是 yaml 文件，每个 yaml 对应一个函数：

```
# 示例函数
function_name: func_1
parameter_types:
- int
return_type: int
function: |-
  int func_1(int a) {
    return a;
  }
input:
- '1'
output: '1'
misc:
- const int VALUE = 0;
```

**必须包含以下内容：**

- **`function_name`**：名称
- **`parameter_types`**：参数类型列表
- **`return_type`**：返回类型
- **`function`**：函数体代码（ `|-` 表示的多行字符串）
- **`input`**：输入参数值（字符串列表）
- **`output`**：返回结果值（字符串）
- **`misc`**：其他辅助信息，例如宏定义、常量等。



#### 2、自定义函数库

若需要注入自定义函数库，则通过 `/runner/default.yaml` 设定其 zip 的路径和函数数量

**你需要提供一个 zip 压缩包，必须包含了 k 个 yaml 文件，名称必须为：**

```
func_n.yaml		# n 从 0 到 k
```



### 四、消融支持

#### 1、不生成函数

在  `/runner/__main__.py` 中，将参数 `func_zip_path` 指定为空即可，测试脚本无法找到函数库，则不执行注入。



#### 2、不生成指针

在 git branch 中切换至 no-ptr 分支，进行编译安装



#### 3、不生成对象

在 git branch 中切换至 no-object 分支，进行编译安装