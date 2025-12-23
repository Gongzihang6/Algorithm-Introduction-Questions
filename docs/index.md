---
hide:
  - navigation # 在首页隐藏右侧的本页目录（可选，让首页看起来更像封面）
---

# 算法导论题解 (Algorithm Introduction Questions)

[![GitHub stars](https://img.shields.io/github/stars/Gongzihang6/Algorithm-Introduction-Questions?style=social)](https://github.com/Gongzihang6/Algorithm-Introduction-Questions)
[![ci](https://github.com/Gongzihang6/Algorithm-Introduction-Questions/actions/workflows/ci.yml/badge.svg)](https://github.com/Gongzihang6/Algorithm-Introduction-Questions/actions/workflows/ci.yml)

欢迎来到 **Algorithm Introduction Questions** 项目主页。

本项目旨在记录《算法导论》（Introduction to Algorithms, CLRS）的详细习题解答与代码实现。内容涵盖了从基础的排序算法到高级的图论、动态规划等章节。

---

## ✨ 功能特性与演示

本站点使用 **MkDocs** 配合 **Material for MkDocs** 主题构建，针对算法学习场景进行了以下优化配置：

### 1. 数学公式完美渲染 (LaTeX)

利用 MathJax 支持复杂的数学推导，这对于分析时间复杂度和证明算法正确性至关重要。

**示例：主定理 (Master Theorem)**

设 $a \ge 1$ 和 $b > 1$ 为常数，设 $f(n)$ 为一函数，$T(n)$ 由递归式 $T(n) = aT(n/b) + f(n)$ 定义。那么 $T(n)$ 有如下渐近界：

$$
T(n) = \begin{cases} 
\Theta(n^{\log_b a}) & \text{若 } f(n) = O(n^{\log_b a - \epsilon}), \text{ for some } \epsilon > 0 \\
\Theta(n^{\log_b a} \lg n) & \text{若 } f(n) = \Theta(n^{\log_b a}) \\
\Theta(f(n)) & \text{若 } f(n) = \Omega(n^{\log_b a + \epsilon}), \text{ for some } \epsilon > 0
\end{cases}
$$

**示例：矩阵运算**

$$
\mathbf{H} = \begin{bmatrix} 
h_{11} & h_{12} & h_{13} \\ 
h_{21} & h_{22} & h_{23} \\ 
h_{31} & h_{32} & h_{33} 
\end{bmatrix}
$$

### 2. 代码高亮与交互

支持 C++、Python、Java 等多种语言的高亮显示，并带有**行号**、**一键复制**和**行高亮**功能。

=== "C++ 实现"

    ```cpp
    #include <iostream>
    #include <vector>
    
    // 快速排序 Partition 函数
    int partition(std::vector<int>& arr, int low, int high) {
        int pivot = arr[high]; // 选取最后一个元素作为基准
        int i = (low - 1);
    
        for (int j = low; j <= high - 1; j++) {
            // 如果当前元素小于基准
            if (arr[j] < pivot) {
                i++; 
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        return (i + 1);
    }
    ```

=== "Python 实现"

    ```python
    def partition(arr, low, high):
        pivot = arr[high]
        i = low - 1
        
        for j in range(low, high):
            if arr[j] < pivot:
                i += 1
                arr[i], arr[j] = arr[j], arr[i]
        
        arr[i + 1], arr[high] = arr[high], arr[i + 1]
        return i + 1
    ```

### 3. 提示块 (Admonitions)

使用不同颜色的提示块来标记重点、警告或补充说明。

!!! note "关于解题思路"
    大部分题目不仅包含代码，还会提供详细的**伪代码 (Pseudocode)** 分析和**时间复杂度证明**。

!!! tip "技巧"
    点击代码块右上角的 **复制按钮** 可以快速获取代码。
    点击左侧或顶部的导航栏可以切换章节。

!!! warning "版权声明"
    本仓库代码仅供学习交流使用，请勿直接用于作业抄袭。

---

## 📂 内容导航

请通过左侧侧边栏或下方链接浏览具体章节：

第一部分 算法基础

- [第 1 章: 算法在计算机中的作用](1、算法基础\第一章-算法在计算机中的作用.md) 
- [第 2 章：排序和顺序统计量](chapter2.md)
- [第 3 章：数据结构](chapter3.md)
- [第 4 章：高级设计和分析技术](chapter4.md)

---

<p align="center">
  Built with ❤️ by <a href="https://github.com/Gongzihang6">Gongzihang6</a> 
</p>